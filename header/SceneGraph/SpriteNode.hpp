#ifndef SCENEGRAPH_SPRITENODE_HPP
#define SCENEGRAPH_SPRITENODE_HPP

#include <SceneGraph/SceneNode.hpp>

#include <SFML/Graphics/Sprite.hpp>


class SpriteNode : public SceneNode
{
	public:
		explicit SpriteNode(const sf::Texture& texture);
		SpriteNode(const sf::Texture& texture, const sf::IntRect& textureRect);
		void setTextureRect(const sf::IntRect& rect);
		void setOrigin(float x, float y);
		void setOrigin(const sf::Vector2f& origin);
		void setScale(float x, float y);
		void setScale(const sf::Vector2f& scale);
		sf::FloatRect getGlobalBounds() const;

	private:
		virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;


	private:
		sf::Sprite mSprite;
};

#endif // BOOK_SPRITENODE_HPP