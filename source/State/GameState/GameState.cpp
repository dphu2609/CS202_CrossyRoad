#include <State/GameState/GameState.hpp>

GameState::GameState(StateStack &stack, sf::RenderWindow &window)
    : State(stack, window), mWorld(window) {
}

void GameState::draw() {
    mWorld.draw();
    // mGUIContainer.draw();
}

void GameState::update(sf::Time dt) {
    mWorld.update(dt);
    // mGUIContainer.update(dt);
}

void GameState::handleEvent(sf::Event &event) {
    mWorld.handleEvent(event);
    // mGUIContainer.handleEvent(event);
}




