#ifndef WORLD_HPP
#define WORLD_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <SceneGraph/SceneNode.hpp>
#include <CommandQueue.hpp>
#include <SceneGraph/Character.hpp>
#include <SceneGraph/Road/Road.hpp>
#include <SceneGraph/Road/Grass.hpp>
#include <SceneGraph/Road/River.hpp>

class World : private sf::NonCopyable {
public:
    explicit World(sf::RenderWindow &window);
    void update(sf::Time dt);
    void draw();
    void handleEvent(sf::Event &event);
    CommandQueue &getCommandQueue();
private:
    void buildScene();
private:
    enum Layer {
        RoadSequence,
        CharacterLayer,
        GrassLayer,
        LayerCount
    };
private:
    sf::RenderWindow &mWindow;
    sf::View mWorldView;
    SceneNode mSceneGraph;
    std::array<SceneNode*, LayerCount> mSceneLayers;
    CommandQueue mCommandQueue;
private:
    sf::FloatRect mWorldBounds;
private:
    int mPlayerIndex;
    std::vector<std::shared_ptr<Road>> mRoadSequence;
private:
    void initRoadSequence();
    void initCharacter(); // use these 2 functions in buildScene()

    void addRoad(); // use when player move to next road
    void removeRoad(); // use when road is out of screen

private:
    void loadGame();
    void saveGame();
};

#endif
