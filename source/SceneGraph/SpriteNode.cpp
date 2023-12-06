#include <SceneGraph/SpriteNode.hpp>

#include <SFML/Graphics/RenderTarget.hpp>


SpriteNode::SpriteNode(const sf::Texture& texture)
: mSprite(texture)
{
}	

SpriteNode::SpriteNode(const sf::Texture& texture, const sf::IntRect& textureRect)
: mSprite(texture, textureRect)
{
}

void SpriteNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}

void SpriteNode::setTextureRect(const sf::IntRect& rect) {
	mSprite.setTextureRect(rect);
}

void SpriteNode::setOrigin(float x, float y) {
	mSprite.setOrigin(x, y);
}

void SpriteNode::setOrigin(const sf::Vector2f& origin) {
	mSprite.setOrigin(origin);
}

void SpriteNode::setScale(float x, float y) {
	mSprite.setScale(x, y);
}

void SpriteNode::setScale(const sf::Vector2f& scale) {
	mSprite.setScale(scale);
}

sf::FloatRect SpriteNode::getGlobalBounds() const {
	return mSprite.getGlobalBounds();
}