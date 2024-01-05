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
    bool isInRiver = false;
    float oldPos = 0.f;
public:
    RoadSequence(sf::View &view);
    ~RoadSequence();
    virtual void updateCurrent(sf::Time dt, CommandQueue &commands);
    virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
    void gameControl(sf::Time dt);
    void roadIndexControl();
private:
    int mPlayerScore = 0;
public:
    int getPlayerScore();
public:
    void readData(std::ifstream &file);
    void writeData(std::ofstream &file);
private:
    void updateRoads(sf::Time dt);
    void soundController();
    virtual void resetCurrentView();
    void pushBackRandomRoad();
    void popFrontRoad();
private:
    sf::Sound mTrafficSound;
private:
    virtual void setCurrentEnvSoundVolume(float volume);
    virtual void stopEnvSound();
public:
    bool isEndGame() const;
};

#endif