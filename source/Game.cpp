#include <Game.hpp>

Game::Game() : mWindow(sf::VideoMode(640, 480), "SFML Application")
, mStateStack(mWindow) {
}

void Game::loadTextures() {
    Resources::textures.load(Textures::CharacterSkin1BackwardState1, "media/images/characters/1.png");
    Resources::textures.load(Textures::CharacterSkin1BackwardState2, "media/images/characters/2.png");
    Resources::textures.load(Textures::CharacterSkin1BackwardState3, "media/images/characters/3.png");
    Resources::textures.load(Textures::CharacterSkin1BackwardState4, "media/images/characters/4.png");
    Resources::textures.load(Textures::CharacterSkin1ForwardState1, "media/images/characters/5.png");
    Resources::textures.load(Textures::CharacterSkin1ForwardState2, "media/images/characters/6.png");
    Resources::textures.load(Textures::CharacterSkin1ForwardState3, "media/images/characters/7.png");
    Resources::textures.load(Textures::CharacterSkin1ForwardState4, "media/images/characters/8.png");
    Resources::textures.load(Textures::CharacterSkin1LeftState1, "media/images/characters/9.png");
    Resources::textures.load(Textures::CharacterSkin1LeftState2, "media/images/characters/10.png");
    Resources::textures.load(Textures::CharacterSkin1LeftState3, "media/images/characters/11.png");
    Resources::textures.load(Textures::CharacterSkin1LeftState4, "media/images/characters/12.png");
    Resources::textures.load(Textures::CharacterSkin1RightState1, "media/images/characters/13.png");
    Resources::textures.load(Textures::CharacterSkin1RightState2, "media/images/characters/14.png");
    Resources::textures.load(Textures::CharacterSkin1RightState3, "media/images/characters/15.png");
    Resources::textures.load(Textures::CharacterSkin1RightState4, "media/images/characters/16.png");
}

void Game::run() {
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