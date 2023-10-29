#ifndef RAILWAY_HPP
#define RAILWAY_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <SceneGraph/Road/Road.hpp>

class RailWay : public Road {
// public:
//     RailWay();
//     RailWay(std::vector<std::string>> &oldData);
//     virtual bool isCollide(const sf::FloatRect &rect) const;
//     virtual std::vector<std::string> getData() const;
// private:
//     virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
//     virtual void updateCurrent(sf::Time dt);
private:
    sf::Sprite mRail;
    sf::Sprite mTrain;
    std::vector<sf::Sprite> mTrafficLight;
    sf::Clock mClock;
private:
    const float mTrainSpeed = 1000.f;
};