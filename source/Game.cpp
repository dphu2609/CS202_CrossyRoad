#include <Game.hpp>

Game::Game() : mWindow(sf::VideoMode(Statistic::SCREEN_WIDTH, Statistic::SCREEN_HEIGHT), "Crossy Road")
, mStateStack(mWindow) {
    loadTextures();
    loadGifs();
    registerStates();
}

void Game::loadTextures() {
    Resources::characterTextures.load(CharacterTextures::CharacterSkin1BackwardState1, "media/images/characters/1.png");
    Resources::characterTextures.load(CharacterTextures::CharacterSkin1BackwardState2, "media/images/characters/2.png");
    Resources::characterTextures.load(CharacterTextures::CharacterSkin1BackwardState3, "media/images/characters/3.png");
    Resources::characterTextures.load(CharacterTextures::CharacterSkin1BackwardState4, "media/images/characters/4.png");
    Resources::characterTextures.load(CharacterTextures::CharacterSkin1ForwardState1, "media/images/characters/5.png");
    Resources::characterTextures.load(CharacterTextures::CharacterSkin1ForwardState2, "media/images/characters/6.png");
    Resources::characterTextures.load(CharacterTextures::CharacterSkin1ForwardState3, "media/images/characters/7.png");
    Resources::characterTextures.load(CharacterTextures::CharacterSkin1ForwardState4, "media/images/characters/8.png");
    Resources::characterTextures.load(CharacterTextures::CharacterSkin1LeftState1, "media/images/characters/9.png");
    Resources::characterTextures.load(CharacterTextures::CharacterSkin1LeftState2, "media/images/characters/10.png");
    Resources::characterTextures.load(CharacterTextures::CharacterSkin1LeftState3, "media/images/characters/11.png");
    Resources::characterTextures.load(CharacterTextures::CharacterSkin1LeftState4, "media/images/characters/12.png");
    Resources::characterTextures.load(CharacterTextures::CharacterSkin1RightState1, "media/images/characters/13.png");
    Resources::characterTextures.load(CharacterTextures::CharacterSkin1RightState2, "media/images/characters/14.png");
    Resources::characterTextures.load(CharacterTextures::CharacterSkin1RightState3, "media/images/characters/15.png");
    Resources::characterTextures.load(CharacterTextures::CharacterSkin1RightState4, "media/images/characters/16.png");
    
    Resources::roadTextures.load(RoadTextures::Grass, "media/images/road/grass3.png");
    Resources::roadTextures.load(RoadTextures::Tree, "media/images/road/tree2.png");
    Resources::roadTextures.load(RoadTextures::Rock, "media/images/road/rock3.png");
    Resources::roadTextures.load(RoadTextures::Bush, "media/images/road/bush1.png");
    Resources::roadTextures.load(RoadTextures::None, "media/images/road/none1.png");
    Resources::roadTextures.load(RoadTextures::Road, "media/images/road/Road1.png");
    Resources::roadTextures.load(RoadTextures::Rail, "media/images/road/Rail70x70_1.png");
    Resources::roadTextures.load(RoadTextures::UniformWater, "media/images/road/uniform.png");
    Resources::roadTextures.load(RoadTextures::AccelerateWater, "media/images/road/accelerate.png");
    Resources::roadTextures.load(RoadTextures::Wood, "media/images/road/wood.jpg");

    Resources::roadTextures.load(RoadTextures::SmallCarLeft, "media/images/road/SmallCarLeft1.png");
    Resources::roadTextures.load(RoadTextures::SmallCarRight, "media/images/road/SmallCarRight1.png");
    Resources::roadTextures.load(RoadTextures::BigCarLeft, "media/images/road/BigCarLeft1.png");
    Resources::roadTextures.load(RoadTextures::BigCarRight, "media/images/road/BigCarRight1.png");
    Resources::roadTextures.load(RoadTextures::TruckLeft, "media/images/road/TruckLeft1.png");
    Resources::roadTextures.load(RoadTextures::TruckRight, "media/images/road/TruckRight1.png");
    Resources::roadTextures.load(RoadTextures::TrainLeft, "media/images/road/FullTrainLeft4Cabin1.png");
    Resources::roadTextures.load(RoadTextures::TrainRight, "media/images/road/FullTrainRight4Cabin1.png");
}
void Game::loadGifs() {
    std::vector<sf::Sprite> characterSkin1Backward;
    characterSkin1Backward.push_back(sf::Sprite(Resources::characterTextures[CharacterTextures::CharacterSkin1BackwardState1]));
    characterSkin1Backward.push_back(sf::Sprite(Resources::characterTextures[CharacterTextures::CharacterSkin1BackwardState2]));
    characterSkin1Backward.push_back(sf::Sprite(Resources::characterTextures[CharacterTextures::CharacterSkin1BackwardState3]));
    characterSkin1Backward.push_back(sf::Sprite(Resources::characterTextures[CharacterTextures::CharacterSkin1BackwardState4]));
    Resources::gifsHolder.load(GIFs::CharacterSkin1Backward, characterSkin1Backward, sf::seconds(0.4f));

    std::vector<sf::Sprite> characterSkin1Forward;
    characterSkin1Forward.push_back(sf::Sprite(Resources::characterTextures[CharacterTextures::CharacterSkin1ForwardState1]));
    characterSkin1Forward.push_back(sf::Sprite(Resources::characterTextures[CharacterTextures::CharacterSkin1ForwardState2]));
    characterSkin1Forward.push_back(sf::Sprite(Resources::characterTextures[CharacterTextures::CharacterSkin1ForwardState3]));
    characterSkin1Forward.push_back(sf::Sprite(Resources::characterTextures[CharacterTextures::CharacterSkin1ForwardState4]));
    Resources::gifsHolder.load(GIFs::CharacterSkin1Forward, characterSkin1Forward, sf::seconds(0.4f));

    std::vector<sf::Sprite> characterSkin1Left;
    characterSkin1Left.push_back(sf::Sprite(Resources::characterTextures[CharacterTextures::CharacterSkin1LeftState1]));
    characterSkin1Left.push_back(sf::Sprite(Resources::characterTextures[CharacterTextures::CharacterSkin1LeftState2]));
    characterSkin1Left.push_back(sf::Sprite(Resources::characterTextures[CharacterTextures::CharacterSkin1LeftState3]));
    characterSkin1Left.push_back(sf::Sprite(Resources::characterTextures[CharacterTextures::CharacterSkin1LeftState4]));
    Resources::gifsHolder.load(GIFs::CharacterSkin1Left, characterSkin1Left, sf::seconds(0.4f));

    std::vector<sf::Sprite> characterSkin1Right;
    characterSkin1Right.push_back(sf::Sprite(Resources::characterTextures[CharacterTextures::CharacterSkin1RightState1]));
    characterSkin1Right.push_back(sf::Sprite(Resources::characterTextures[CharacterTextures::CharacterSkin1RightState2]));
    characterSkin1Right.push_back(sf::Sprite(Resources::characterTextures[CharacterTextures::CharacterSkin1RightState3]));
    characterSkin1Right.push_back(sf::Sprite(Resources::characterTextures[CharacterTextures::CharacterSkin1RightState4]));
    Resources::gifsHolder.load(GIFs::CharacterSkin1Right, characterSkin1Right, sf::seconds(0.4f));
}

void Game::registerStates() {
    mStateStack.registerState<GameState>(States::Game);
}

void Game::run() {
    mStateStack.pushState(States::Game);
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
    while (mWindow.isOpen()) {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        mStateStack.handleEvent(event);
        if (event.type == sf::Event::Closed) {
            mWindow.close();
        }
    }
}

void Game::update(sf::Time dt) {
    mStateStack.update(dt);
}

void Game::render() {
    mWindow.clear();
    mStateStack.draw();
    mWindow.display();
}