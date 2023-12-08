#include <State/GameState/GameState.hpp>

GameState::GameState(StateStack &stack, sf::RenderWindow &window)
    : State(stack, window), mWorld(window) {
}

void GameState::draw() {
    mWorld.draw();
}

void GameState::update(sf::Time dt) {
    mWorld.update(dt);
}

void GameState::handleEvent(sf::Event &event) {
    mWorld.handleEvent(event);
    if (Statistic::IS_GAME_OVER) {
        requestStackPush(States::Pause);
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        requestStackPush(States::Pause);
    }
}




