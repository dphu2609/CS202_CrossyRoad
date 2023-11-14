#ifndef SMALLCAR_ROAD_HPP
#define SMALLCAR_ROAD_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <SceneGraph/Road/Road.hpp>

class SmallCarRoad : public Road {
// public:
//     SmallCarRoad();
//     SmallCarRoad(std::vector<std::string> &oldData);
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