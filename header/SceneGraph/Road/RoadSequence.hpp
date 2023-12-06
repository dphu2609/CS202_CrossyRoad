#ifndef ROAD_SEQUENCE_HPP
#define ROAD_SEQUENCE_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <SceneGraph/Road/Road.hpp>
#include <SceneGraph/Road/Grass.hpp>
#include <SceneGraph/Road/VehicleLane.hpp>
#include <SceneGraph/Road/River.hpp>
#include <SceneGraph/Character.hpp>

class RoadSequence : public SceneNode {
private:
    std::vector<std::shared_ptr<Road>> mRoads;
    std::shared_ptr<Character> mCharacter;
    int mCurrentRoadIndex;
    sf::View &mView;
public:
    RoadSequence(sf::View &view);
    virtual void updateCurrent(sf::Time dt, CommandQueue &commands);
    virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
    void gameControl(sf::Time dt);
    void roadIndexControl();
private:
    int mPlayerScore = 0;
public:
    int getPlayerScore();
private:
    void updateRoads(sf::Time dt);
    virtual void resetCurrentView();
    void pushBackRandomRoad();
    void popFrontRoad();
};

#endif