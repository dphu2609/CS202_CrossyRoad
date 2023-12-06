#ifndef SCENEGRAPH_SPRITENODE_HPP
#define SCENEGRAPH_SPRITENODE_HPP

#include <SceneGraph/SceneNode.hpp>

#include <SFML/Graphics/Sprite.hpp>


class SpriteNode : public SceneNode
{
	public:
		explicit SpriteNode(const sf::Texture& texture);
		SpriteNode(const sf::Texture& texture, const sf::IntRect& textureRect);


	private:
		virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;


	private:
		sf::Sprite mSprite;
};

#endif // BOOK_SPRITENODE_HPP