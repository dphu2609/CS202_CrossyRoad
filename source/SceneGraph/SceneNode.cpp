#include <SceneGraph/SceneNode.hpp>

SceneNode::SceneNode() {
    this->mParent = nullptr;
}

void SceneNode::attachChild(Ptr child) {
    child->mParent = this;
    mChildren.emplace_back(child);
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    drawCurrent(target, states);
    for (const auto& child : mChildren) {
        if (child) 
            child->draw(target, states);
    }
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