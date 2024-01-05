#ifndef RIVER_HPP
#define RIVER_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <SceneGraph/Road/Road.hpp>
#include <GlobalVar.hpp>
#include <Resources/ResourceHolder.hpp>
#include <SceneGraph/Road/RiverArea.hpp>

typedef ResourceHolder<sf::Texture, RoadTextures::ID> RoadTextureHolder;

RoadTextures::ID toTextureID(RiverArea::Type type);
float toRiverLength(RiverArea::Type type);
class River : public Road {
private:
    enum Layer
    {
        AreaLayer,
        WoodLayer,
        Count
    };
    std::array<SceneNode*, Count> mSceneLayers;
    std::vector<RiverArea*> areas;
    std::vector<Wood*> woods;
    int currentArea;
    int direction;
    int speed;
    sf::Time spawnTime;
    sf::Clock spawnClock;
private:
    virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
    virtual void updateCurrent(sf::Time dt,CommandQueue& commands);
    virtual bool isHitDangerousObjects(const sf::FloatRect &bounds) const;
    void spawnWood();
    void removeWood();
public:
    River();
    River(std::ifstream &file);
    virtual RoadType::ID getRoadType() const {return RoadType::River;}
    virtual sf::Vector2f getVelocity() const;
    virtual void readData(std::ifstream &file);
    virtual void writeData(std::ofstream &file);

    virtual DeathCause::ID getDeathCause() const {return DeathCause::River;}
};






#endif