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
    sf::FloatRect getBoundingRect() const { 
        sf::FloatRect rect = mSprite.getGlobalBounds();
        rect.top -= 10.f;
        rect.width -= 80.f;
        rect.left += 40.f;
        return getWorldTransform().transformRect(rect); 
    }
    bool isCollide(const sf::FloatRect& rect) const ;
};

#endif