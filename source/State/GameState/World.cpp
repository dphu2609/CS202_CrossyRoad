#include <State/GameState/World.hpp>

World::World(sf::RenderWindow &window) : 
    mWindow(window), mWorldView(window.getDefaultView()), 
    mWorldBounds(0.f, 0.f, mWorldView.getSize().x, Statistic::SCREEN_HEIGHT * 2)
{
    if (Statistic::IS_LOAD_FROM_FILE) {
        std::ifstream file;
        file.open(Statistic::LOAD_FILE_NAME);
        buildSceneFromFile(file);
        Statistic::IS_LOAD_FROM_FILE = false;
    } else {
        buildScene();
    }
}

void World::buildScene() {
    for (int i = 0; i < LayerCount; i++) {
        SceneNode::Ptr layer = std::make_shared<SceneNode>();
        mSceneLayers[i] = layer.get();
        mSceneGraph.attachChild(layer);
    }
    
    std::shared_ptr<RoadSequence> roadSequence = std::make_shared<RoadSequence>(mWorldView);
    mRoadSequence = roadSequence;
    roadSequence->setPosition(Statistic::ROAD_WIDTH / 2 - 40, Statistic::CHARACTER_SPAWN_POSITION.y + Statistic::ROAD_HEIGHT * 5);
    mSceneLayers[RoadLayer]->attachChild(std::move(roadSequence));

    std::shared_ptr<TextNode> scoreText = std::make_shared<TextNode>(Resources::fonts[Fonts::JoystixMonospaceRegular], std::to_string(Statistic::PLAYER_SCORE));
    mScoreText = scoreText;
    scoreText->setPosition(20, mWorldView.getCenter().y - 500);
    mSceneLayers[ScoreLayer]->attachChild(std::move(scoreText));

    mWorldView.setCenter(Statistic::INITIAL_VIEW_POSITION - sf::Vector2f(0, 20));
}

void World::buildSceneFromFile(std::ifstream &file) {
    float x, y;
    file >> x >> y;
    mWorldView.setCenter(x, y);
    file >> mPlayerScore;

    for (int i = 0; i < LayerCount; i++) {
        SceneNode::Ptr layer = std::make_shared<SceneNode>();
        mSceneLayers[i] = layer.get();
        mSceneGraph.attachChild(layer);
    }
    
    std::shared_ptr<RoadSequence> roadSequence = std::make_shared<RoadSequence>(mWorldView);
    mRoadSequence = roadSequence;
    roadSequence->readData(file);
    mSceneLayers[RoadLayer]->attachChild(std::move(roadSequence));

    std::shared_ptr<TextNode> scoreText = std::make_shared<TextNode>(Resources::fonts[Fonts::JoystixMonospaceRegular], std::to_string(mPlayerScore));
    mScoreText = scoreText;
    scoreText->setPosition(20, mWorldView.getCenter().y - 500);
    mSceneLayers[ScoreLayer]->attachChild(std::move(scoreText));
}

void World::update(sf::Time dt) {
    while (!mCommandQueue.isEmpty()) {
        mSceneGraph.onCommand(mCommandQueue.pop(), dt);
    }
    mSceneGraph.update(dt, mCommandQueue);
    updateWorldView(dt);
    scoreControl();
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
    mScoreText->setPosition(20, mWorldView.getCenter().y - 500);
}

void World::handleEvent(sf::Event &event) {
    mSceneGraph.handleEvent(mWindow, event);
}

void World::draw() {
    mWindow.setView(mWorldView);
    mWindow.draw(mSceneGraph);
}

void World::scoreControl() {
    if (mRoadSequence->getPlayerScore() != mPlayerScore) {
        mPlayerScore = mRoadSequence->getPlayerScore();
        mScoreText->setString(std::to_string(mPlayerScore));
    }
}
CommandQueue &World::getCommandQueue() {
    return mCommandQueue;
}

void World::writeData(std::ofstream &file) {
    file << mWorldView.getCenter().x << " " << mWorldView.getCenter().y << std::endl;
    file << mPlayerScore << std::endl;
    mRoadSequence->writeData(file);
}

void World::setEnvSoundVolume(float volume) {
    mSceneGraph.setEnvSoundVolume(volume);
}
