#ifndef RIVERAREA_HPP
#define RIVERAREA_HPP

#include <SceneGraph/SceneNode.hpp>
#include <SceneGraph/Road/Wood.hpp>
#include <Resources/ResourceHolder.hpp>
#include <Configs.hpp>

typedef ResourceHolder<sf::Texture, RoadTextures::ID> RoadTextureHolder;

class RiverArea : public SceneNode
{
    public:
    enum Type
    {
        Uniform,
        Accelerate
    };
    private:
    sf::Sprite mSprite;
    Type mType;
    sf::Vector2f waterSpeed;
    int direction;
    public:
    RiverArea(Type type, const RoadTextureHolder& textures); 
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const; 
    void accelerate(Wood*& wood, sf::Time dt);
    sf::FloatRect getSpriteBounds() const { return mSprite.getGlobalBounds(); }
    sf::FloatRect getBoundingRect() const { return getWorldTransform().transformRect(mSprite.getGlobalBounds());}
    void setDirection(int dir) { direction = dir; }
    void setSpeed(sf::Vector2f speed) { waterSpeed = speed; }
    sf::Vector2f getVelocity() const { return (float)direction * waterSpeed; }
};

RoadTextures::ID toTextureID(RiverArea::Type type);
float toRiverLength(RiverArea::Type type);


#endif // RIVERAREA_HPP