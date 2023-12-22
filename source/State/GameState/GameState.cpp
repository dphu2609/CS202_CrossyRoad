#include <State/GameState/GameState.hpp>

GameState::GameState(StateStack &stack, sf::RenderWindow &window)
    : State(stack, window), mWorld(window) {
}

void GameState::draw() {
    mWorld.draw();
}

void GameState::update(sf::Time dt) {
    mWorld.update(dt);
    if (Statistic::IS_GAME_OVER) {
        requestStackPush(States::Pause);
    }
    if (mEnvVolume != Statistic::ENVIROMENT_SOUND_VOLUME) {
        mEnvVolume = Statistic::ENVIROMENT_SOUND_VOLUME;
        mWorld.setEnvSoundVolume(mEnvVolume);
    }
    if (mWorld.isEndGame()) {
        requestStateClear();
        requestStackPush(States::End);
        mWorld.stopEnvSound();
    }
    if (!Statistic::IS_GAME_PAUSE && !mIsGamePause) {
        mIsGamePause = true;
        mWorld.setEnvSoundVolume(Statistic::ENVIROMENT_SOUND_VOLUME);
    }
}

void GameState::handleEvent(sf::Event &event) {
    mWorld.handleEvent(event);
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        std::ofstream file;
        file.open(Statistic::LOAD_FILE_NAME);
        mWorld.writeData(file);
        file.close();
        Statistic::IS_GAME_PAUSE = true;
        mWorld.setEnvSoundVolume(0);
        requestStackPush(States::Pause);
    }
}




