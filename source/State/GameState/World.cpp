#include <State/GameState/World.hpp>

World::World(sf::RenderWindow &window) : 
    mWindow(window), mWorldView(window.getDefaultView()), 
    mWorldBounds(0.f, 0.f, mWorldView.getSize().x, Statistic::SCREEN_HEIGHT * 2)
{
    buildScene();
    mWorldView.setCenter(Statistic::INITIAL_VIEW_POSITION - sf::Vector2f(0, 20));
}

void World::buildScene() {
    for (int i = 0; i < LayerCount; i++) {
        SceneNode::Ptr layer = std::make_shared<SceneNode>();
        mSceneLayers[i] = layer.get();
        mSceneGraph.attachChild(layer);
    }

    std::shared_ptr<Character> character = std::make_shared<Character>(mWorldView);
    character->setPosition(Statistic::SCREEN_WIDTH / 2, Statistic::SCREEN_HEIGHT - 60);
    character->setScale(Statistic::CHARACTER_SIZE.x / character->getSpriteBounding().width, Statistic::CHARACTER_SIZE.y / character->getSpriteBounding().height);
    mSceneLayers[CharacterLayer]->attachChild(std::move(character));
    
    std::shared_ptr<RoadSequence> roadSequence = std::make_shared<RoadSequence>(mWorldView);
    roadSequence->setPosition(Statistic::ROAD_WIDTH / 2 - 40, Statistic::CHARACTER_SPAWN_POSITION.y + Statistic::ROAD_HEIGHT * 4);
    mSceneLayers[RoadLayer]->attachChild(std::move(roadSequence));
}

void World::update(sf::Time dt) {
    while (!mCommandQueue.isEmpty()) {
        mSceneGraph.onCommand(mCommandQueue.pop(), dt);
    }
    mSceneGraph.update(dt, mCommandQueue);
    updateWorldView(dt);
}

void World::updateWorldView(sf::Time dt) {
    sf::Vector2f position = mWorldView.getCenter();
    float speed = Statistic::SCREEN_SPEED;
    sf::Vector2f newPosition = sf::Vector2f(position.x, position.y - speed * dt.asSeconds());
    if (newPosition.y <= 0) {
        newPosition = Statistic::RESET_VIEW_POSITION;
        mSceneGraph.resetView();
    }
    mWorldView.setCenter(newPosition);
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

