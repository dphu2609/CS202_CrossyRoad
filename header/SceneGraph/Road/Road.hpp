#ifndef ROAD_HPP
#define ROAD_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <SceneGraph/SceneNode.hpp>
#include <SceneGraph/Character.hpp>
#include <SceneGraph/Road/Block.hpp>

namespace RoadType {
    enum ID {
        SmallCar,
        BigCar,
        Truck,
        RailWay,
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
};

#endif