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
    virtual bool isOutOfScreen(const sf::View &view) const {return false;}
    // virtual std::vector<std::shared_ptr<Block>> randomBlock() {return std::vector<std::shared_ptr<Block>>();}
};

#endif