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
#include <SceneGraph/Road/VehicleLane.hpp>
#include <SceneGraph/Road/RoadSequence.hpp>
#include <SceneGraph/TextNode.hpp>
#include <GUI/Container.hpp>
#include <GUI/Button.hpp>


class World : private sf::NonCopyable {
public:
    explicit World(sf::RenderWindow &window);
    void writeData(std::ofstream &file);
    void update(sf::Time dt);
    void updateWorldView(sf::Time dt);
    void draw();
    void handleEvent(sf::Event &event);
    CommandQueue &getCommandQueue();
private:
    void buildScene();
    void buildSceneFromFile(std::ifstream &file);   
private:
    enum Layer {
        RoadLayer,
        CharacterLayer,
        GrassLayer,
        ScoreLayer,
        LayerCount
    };
private:
    sf::RenderWindow &mWindow;
    sf::View mWorldView;
    SceneNode mSceneGraph;
    std::array<SceneNode*, LayerCount> mSceneLayers;
    CommandQueue mCommandQueue;
    std::shared_ptr<RoadSequence> mRoadSequence;
    std::shared_ptr<TextNode> mScoreText;
private:
    sf::FloatRect mWorldBounds;
private:
    int mPlayerScore = 0;
    void scoreControl();
private:
    void loadGame();
    void saveGame();
public:
    void setEnvSoundVolume(float volume);
};

#endif
