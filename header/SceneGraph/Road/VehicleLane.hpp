#ifndef CAR_ROAD_HPP
#define CAR_ROAD_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <SceneGraph/Road/Vehicle.hpp>
#include <SceneGraph/Road/Road.hpp>

class VehicleLane : public Road {
public:
    VehicleLane();
    virtual bool isCollide(const sf::FloatRect &rect) const {return false;}
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void updateCurrent(sf::Time dt, CommandQueue &commandQueue);
private:
    void vehicleControl(sf::Time dt);
public:
    enum Type
    {
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
private:
    std::vector<Vehicle*> mVehicles;
    sf::Sprite mRoadSprite;
    sf::Sprite mTrafficLight;
    sf::Clock mSpawnTimer; 
    int mDirection; // -1: left, 1: right
    int mType;
    float mSmallCarSpawnTime = 2;
    float mBigCarSpawnTime = 2;
    float mTruckSpawnTime = 2.5;
    float mTrainSpawnTime = 5.f;
};

#endif