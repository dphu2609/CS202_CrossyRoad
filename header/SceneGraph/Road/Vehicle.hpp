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
        SmallCarLeft,
        SmallCarRight,
        BigCarLeft,
        BigCarRight,
        TruckLeft,
        TruckRight,
        TrainLeft,
        TrainRight,
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
    float mSmallCarSpeed = 300.f;
    float mBigCarSpeed = 250.f;
    float mTruckSpeed = 200.f;
    float mTrainSpeed = 2000.f;
public:
    bool isOutOfBound();
};

#endif
