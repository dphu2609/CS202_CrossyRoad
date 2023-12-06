#ifndef CAR_ROAD_HPP
#define CAR_ROAD_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <SceneGraph/Road/Vehicle.hpp>
#include <SceneGraph/Road/Road.hpp>
#include <SceneGraph/SpriteNode.hpp>

class VehicleLane : public Road {
public:
    VehicleLane();
    virtual bool isHitDangerousObjects(const sf::FloatRect &bounds) const;
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void updateCurrent(sf::Time dt, CommandQueue &commandQueue);
    std::vector<std::vector<float>> getData();
    void readData(std::ifstream &file);
    void writeData(std::ofstream &file);
    virtual RoadType::ID getRoadType() const {return RoadType::VehicleLane;}
private:
    void vehicleControl(sf::Time dt);
    void trafficLightControl(sf::Time dt);
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
    enum Layer {
        RoadLayer,
        VehicleLayer,
        TrafficLightLayer,
        CountLayer
    };
private:
    std::array<SceneNode*, CountLayer> mSceneLayers;
    std::vector<Vehicle*> mVehicles;
    sf::Sprite mRoadSprite;
    int mDirection; // -1: left, 1: right
    int mType;
    float mSmallCarDistance = 600;
    float mBigCarDistance = 450;
    float mTruckDistance = 550;
    float mTrainDistance = 10000;
private:
    std::vector<std::shared_ptr<SpriteNode>> mTrafficLights; // 0: red, 1: yellow, 2: green
    int mTrafficLightState;

};

#endif