#ifndef RIVER_HPP
#define RIVER_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <SceneGraph/SceneNode.hpp>
#include <GlobalVar.hpp>
#include <Resources/ResourceHolder.hpp>
#include <SceneGraph/Road/RiverArea.hpp>

typedef ResourceHolder<sf::Texture, RoadTextures::ID> RoadTextureHolder;

RoadTextures::ID toTextureID(RiverArea::Type type);
float toRiverLength(RiverArea::Type type);
class River : public SceneNode {
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
    sf::Time spawnTime;
private:
    virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
    virtual void updateCurrent(sf::Time dt);
public:
    River();
};





#endif