#include <State/GameState/GameState.hpp>

GameState::GameState(StateStack &stack, sf::RenderWindow &window)
    : State(stack, window), mWorld(window) {
    // mWorld.setEnvSoundVolume(70);
}

void GameState::draw() {
    mWorld.draw();
}

void GameState::update(sf::Time dt) {
    mWorld.update(dt);
    if (Statistic::IS_GAME_OVER) {
        requestStackPush(States::Pause);
    }
}

void GameState::handleEvent(sf::Event &event) {
    mWorld.handleEvent(event);
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        std::ofstream file;
        file.open(Statistic::LOAD_FILE_NAME);
        mWorld.writeData(file);
        requestStackPush(States::Pause);
    }

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E) {
        requestStackPush(States::End);
    }
}




