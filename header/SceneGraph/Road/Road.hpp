#ifndef ROAD_HPP
#define ROAD_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <SceneGraph/SceneNode.hpp>
#include <SceneGraph/Character.hpp>
#include <SceneGraph/Road/Block.hpp>

namespace RoadType {
    enum ID {
        VehicleLane,
        River,
        Grass,
    };
};

class Road : public SceneNode {
public:
    virtual bool isCollide(const sf::FloatRect &bounds) const {return false;}
    virtual bool isHitDangerousObjects(const sf::FloatRect &bounds) const {return false;}
    virtual bool isOutOfScreen(const sf::View &view) const {return false;}
    virtual void readData(std::ifstream &file) {}
    virtual void writeData(std::ofstream &file) {}
    virtual RoadType::ID getRoadType() const = 0;
    virtual sf::Vector2f getVelocity() const {return sf::Vector2f(0.f, 0.f);}
};

#endif