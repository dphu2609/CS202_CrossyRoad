#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <SFML/Graphics.hpp>
#include <SceneGraph/SceneNode.hpp>
#include <Resources/ResourceHolder.hpp>
#include <GlobalVar.hpp>

typedef ResourceHolder<sf::Texture, RoadTextures::ID> RoadTextureHolder;

class Vehicle : public SceneNode {
public:
    enum Type
    {
        None,
        SmallCar,
        BigCar,
        Truck,
        Train,
        Count
    };
public:
    Vehicle(Type type, const RoadTextureHolder& textures, int direction = 1); 
    bool isCollide(const sf::FloatRect &rect) const;
    sf::FloatRect getGlobalBounds();
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void updateCurrent(sf::Time dt, CommandQueue &commandQueue);
private:
    void move(sf::Time dt);
private:    
    Type mType;
    sf::Sprite mSprite;
private:
    int mDirection; // -1: left, 1: right
};

#endif
