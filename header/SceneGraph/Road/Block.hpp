#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <SFML/Graphics.hpp>
#include <SceneGraph/SceneNode.hpp>
#include <Resources/ResourceHolder.hpp>
#include <GlobalVar.hpp>

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
    sf::FloatRect getGlobalBounds();
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
private:    
    Type mType;
    sf::Sprite mSprite;
};

#endif
