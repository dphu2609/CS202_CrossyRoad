#include <SceneGraph/SceneNode.hpp>

SceneNode::SceneNode() {
    this->mParent = nullptr;
}

void SceneNode::attachChild(Ptr child) {
    child->mParent = this;
    mChildren.emplace_back(child);
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode& node) {
    auto found = std::find_if(mChildren.begin(), mChildren.end(), [&](Ptr& p) -> bool {return p.get() == &node;});
    assert(found != mChildren.end());
    Ptr result = std::move(*found);
    result->mParent = nullptr;
    mChildren.erase(found);
    return result;
}


void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    drawCurrent(target, states);
    for (const auto& child : mChildren) {
        if (child) 
            child->draw(target, states);
    }
    // drawBoundingRect(target, states);
}

void SceneNode::update(sf::Time dt, CommandQueue& commandQueue)
{
    updateCurrent(dt, commandQueue);
    for (const auto& child : mChildren) child->update(dt, commandQueue);
}

void SceneNode::handleEvent(sf::RenderWindow &window, sf::Event &event) {
    handleCurrentEvent(window, event);
    for (const auto& child : mChildren) child->handleEvent(window, event);
}

void SceneNode::onCommand(const Command &command, sf::Time dt) {
    if (command.category & getCategory()) command.action(*this, dt);
    for (const auto& child : mChildren) child->onCommand(command, dt);
}

sf::Vector2f SceneNode::getWorldPosition() const
{
	return getWorldTransform() * sf::Vector2f();
}

sf::Transform SceneNode::getWorldTransform() const
{
	sf::Transform transform = sf::Transform::Identity;

	for (const SceneNode* node = this; node != nullptr; node = node->mParent)
		transform = node->getTransform() * transform;

	return transform;
}

void SceneNode::drawBoundingRect(sf::RenderTarget& target, sf::RenderStates) const
{
	sf::FloatRect rect = getBoundingRect();

	sf::RectangleShape shape;
	shape.setPosition(sf::Vector2f(rect.left, rect.top));
	shape.setSize(sf::Vector2f(rect.width, rect.height));
	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineColor(sf::Color::Green);
	shape.setOutlineThickness(1.f);

	target.draw(shape);
}

sf::FloatRect SceneNode::getBoundingRect() const
{
	return sf::FloatRect();
}