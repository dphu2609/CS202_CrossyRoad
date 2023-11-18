#ifndef WOOD_HPP
#define WOOD_HPP

#include <SceneGraph/SceneNode.hpp>
#include <Resources/ResourceHolder.hpp>
#include <GlobalVar.hpp>

typedef ResourceHolder<sf::Texture, RoadTextures::ID> RoadTextureHolder;


class Wood : public SceneNode
{
    private:
    sf::Sprite mSprite;
    float length;
    private:
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    public:
    Wood(const RoadTextureHolder& textures, float maxLength);
    sf::FloatRect getSpriteBounds() const { return mSprite.getGlobalBounds(); }
    sf::FloatRect getBoundingRect() const { return getWorldTransform().transformRect(mSprite.getGlobalBounds()); }
    bool isCollide(const sf::FloatRect& rect) const ;
};

#endif