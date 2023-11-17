#ifndef ROAD_SEQUENCE_HPP
#define ROAD_SEQUENCE_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <SceneGraph/Road/Road.hpp>
#include <SceneGraph/Road/Grass.hpp>
#include <SceneGraph/Road/VehicleLane.hpp>

class RoadSequence : public Road {
private:
    std::vector<std::shared_ptr<Road>> mRoads;
    int mRoadIndex;
    sf::View &mView;
public:
    RoadSequence(sf::View &view);
    virtual void updateCurrent(sf::Time dt, CommandQueue &commands);
    virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
private:
    void updateRoads(sf::Time dt);
    virtual void resetCurrentView();
    void pushBackRandomRoad();
    void popFrontRoad();
};

#endif