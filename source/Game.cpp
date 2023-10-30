#include <Game.hpp>

Game::Game() : mWindow(sf::VideoMode(640, 480), "SFML Application")
, mStateStack(mWindow) {
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

void Game::processEvents()
{
    
}
void Game::update(sf::Time dt)
{
    
}
void Game::render()
{
    
}