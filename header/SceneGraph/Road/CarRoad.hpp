// #ifndef CAR_ROAD_HPP
// #define CAR_ROAD_HPP

// #include <SFML/Graphics.hpp>
// #include <bits/stdc++.h>
// #include <SceneGraph/Road/Vehicle.hpp>
// #include <SceneGraph/Road/Road.hpp>

// class CarRoad : public Road {
// public:
//     CarRoad();
//     virtual bool isCollide(const sf::FloatRect &rect) const;
//     virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
//     virtual void updateCurrent(sf::Time dt, CommandQueue &commandQueue);
// private:
//     void vehicleGenerator();
//     void vehicleController();
// public:
//     enum Type
//     {
//         None,
//         SmallCar,
//         BigCar,
//         Truck,
//         Count
//     };
// private:
//     std::vector<Vehicle*> mVehicles;
//     sf::Sprite mRoadSprite;
//     int mDirection; // -1: left, 1: right
//     int mType;
// };

// #endif