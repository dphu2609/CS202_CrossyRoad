#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <SFML/Graphics.hpp>
#include <SceneGraph/SceneNode.hpp>
#include <Resources/ResourceHolder.hpp>
#include <Configs.hpp>

typedef ResourceHolder<sf::Texture, RoadTextures::ID> RoadTextureHolder;

class Block : public SceneNode
{
public:
enum Type
{
    None,
    Rock,
    // Bush,
    Tree,
    Count
};
public:
    Block(Type type, const RoadTextureHolder& textures); 
    bool isCollide(const sf::FloatRect &rect) const;
    // sf::FloatRect getGlobalBounds();
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::FloatRect getSpriteBounds() const { return mSprite.getGlobalBounds(); }
    sf::FloatRect getBoundingRect() const { 
        return getWorldTransform().transformRect(mSprite.getGlobalBounds()); 
    }
    Type getType() const { return mType; }
private:    
    Type mType;
    sf::Sprite mSprite;
};

#endif
