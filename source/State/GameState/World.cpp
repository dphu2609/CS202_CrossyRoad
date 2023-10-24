#include <State/GameState/World.hpp>

World::World(sf::RenderWindow &window) : 
    mWindow(window), mWorldView(window.getDefaultView()), 
    mWorldBounds(0.f, 0.f, mWorldView.getSize().x, 2000.f), 
    mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize().y / 2.f) 
{
    buildScene();
    mWorldView.setCenter(mSpawnPosition);
}

void World::buildScene() {}

void World::update(sf::Time dt) {
    while (!mCommandQueue.isEmpty()) {
        mSceneGraph.onCommand(mCommandQueue.pop(), dt);
    }
    mSceneGraph.update(dt, mCommandQueue);
}

void World::draw() {
    mWindow.setView(mWorldView);
    mWindow.draw(mSceneGraph);
}

CommandQueue &World::getCommandQueue() {
    return mCommandQueue;
}

