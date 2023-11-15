#include <State/GameState/World.hpp>

World::World(sf::RenderWindow &window) : 
    mWindow(window), mWorldView(window.getDefaultView()), 
    mWorldBounds(0.f, 0.f, mWorldView.getSize().x, Statistic::SCREEN_HEIGHT * 2)
{
    buildScene();
    mWorldView.setCenter(Statistic::CHARACTER_SPAWN_POSITION);
}

void World::buildScene() {
    for (int i = 0; i < LayerCount; i++) {
        SceneNode::Ptr layer = std::make_shared<SceneNode>();
        mSceneLayers[i] = layer.get();
        mSceneGraph.attachChild(layer);
    }

    std::shared_ptr<Character> character = std::make_shared<Character>();
    character->setPosition(Statistic::SCREEN_WIDTH / 2, Statistic::SCREEN_HEIGHT - 100);
    character->setScale(Statistic::CHARACTER_SIZE.x / character->getSpriteBounding().width, Statistic::CHARACTER_SIZE.y / character->getSpriteBounding().height);
    mSceneLayers[CharacterLayer]->attachChild(std::move(character));

    std::shared_ptr<Grass> grassRoad(std::make_shared<Grass>());
    grassRoad->setPosition(Statistic::ROAD_WIDTH / 2 - 40, Statistic::SCREEN_HEIGHT - 60);
    grassRoad.get()->randomBlock();
    
    mRoadSequence.push_back(std::move(grassRoad));
    mSceneLayers[RoadSequence]->attachChild(std::move(mRoadSequence.back()));

    std::shared_ptr<CarRoad> carRoad1 = std::make_shared<CarRoad>();
    carRoad1->setPosition(Statistic::ROAD_WIDTH / 2 - 40, Statistic::SCREEN_HEIGHT - 60 + Statistic::BLOCK_SIZE);
    mSceneLayers[RoadSequence]->attachChild(std::move(carRoad1));

    std::shared_ptr<CarRoad> carRoad2 = std::make_shared<CarRoad>();
    carRoad2->setPosition(Statistic::ROAD_WIDTH / 2 - 40, Statistic::SCREEN_HEIGHT - 60 + Statistic::BLOCK_SIZE * 2);
    mSceneLayers[RoadSequence]->attachChild(std::move(carRoad2));
}

void World::update(sf::Time dt) {
    while (!mCommandQueue.isEmpty()) {
        mSceneGraph.onCommand(mCommandQueue.pop(), dt);
    }
    mSceneGraph.update(dt, mCommandQueue);
}

void World::handleEvent(sf::Event &event) {
    mSceneGraph.handleEvent(mWindow, event);
}

void World::draw() {
    mWindow.setView(mWorldView);
    mWindow.draw(mSceneGraph);
}

CommandQueue &World::getCommandQueue() {
    return mCommandQueue;
}

