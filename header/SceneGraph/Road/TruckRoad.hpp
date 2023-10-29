#ifndef TRUCK_ROAD_HPP
#define TRUCK_ROAD_HPP

#include <bits/stdc++.h>
#include <SceneGraph/Road/Road.hpp>

class TruckRoad : public Road {
// public:
//     TruckRoad();
//     TruckRoad(std::vector<std::string> &oldData); // need optimize
//     virtual bool isCollide(const sf::FloatRect &rect) const;
//     virtual std::vector<std::string> getData() const;
// private:
//     virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
//     virtual void updateCurrent(sf::Time dt);
private:
    std::vector<sf::Sprite> mCar;
    sf::Sprite mRoad;
    sf::Clock mClock;
private:
    const float mCarSpeed = 100.f;
};

#endif