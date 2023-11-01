#include <SceneGraph/Character.hpp>

Character::Character() {
    this->setSkin(Statistic::PLAYER_SKIN_TYPE);
    for (int i = 0; i < mBackwardState.size(); i++) {
        mBackwardState[i].setOrigin(mBackwardState[i].getGlobalBounds().width / 2, mBackwardState[i].getGlobalBounds().height / 2);
        mBackwardState[i].setScale(Statistic::CHARACTER_SIZE.x / mBackwardState[i].getGlobalBounds().width, Statistic::CHARACTER_SIZE.y / mBackwardState[i].getGlobalBounds().height);
        mBackwardState[i].setPosition(Statistic::CHARACTER_SPAWN_POSITION);
        
        mForwardState[i].setOrigin(mForwardState[i].getGlobalBounds().width / 2, mForwardState[i].getGlobalBounds().height / 2);
        mForwardState[i].setScale(Statistic::CHARACTER_SIZE.x / mForwardState[i].getGlobalBounds().width, Statistic::CHARACTER_SIZE.y / mForwardState[i].getGlobalBounds().height);
        mForwardState[i].setPosition(Statistic::CHARACTER_SPAWN_POSITION);
        
        mLeftState[i].setOrigin(mLeftState[i].getGlobalBounds().width / 2, mLeftState[i].getGlobalBounds().height / 2);
        mLeftState[i].setScale(Statistic::CHARACTER_SIZE.x / mLeftState[i].getGlobalBounds().width, Statistic::CHARACTER_SIZE.y / mLeftState[i].getGlobalBounds().height);
        mLeftState[i].setPosition(Statistic::CHARACTER_SPAWN_POSITION);
        
        mRightState[i].setOrigin(mRightState[i].getGlobalBounds().width / 2, mRightState[i].getGlobalBounds().height / 2);
        mRightState[i].setScale(Statistic::CHARACTER_SIZE.x / mRightState[i].getGlobalBounds().width, Statistic::CHARACTER_SIZE.y / mRightState[i].getGlobalBounds().height);
        mRightState[i].setPosition(Statistic::CHARACTER_SPAWN_POSITION);
    }
}

void Character::setSkin(int skin) {
    if (skin == Skin1) {
        mBackwardState.push_back(sf::Sprite(Resources::characterTextures[CharacterTextures::CharacterSkin1BackwardState1]));
        mBackwardState.push_back(sf::Sprite(Resources::characterTextures[CharacterTextures::CharacterSkin1BackwardState2]));
        mBackwardState.push_back(sf::Sprite(Resources::characterTextures[CharacterTextures::CharacterSkin1BackwardState3]));
        mBackwardState.push_back(sf::Sprite(Resources::characterTextures[CharacterTextures::CharacterSkin1BackwardState4]));
        
        mForwardState.push_back(sf::Sprite(Resources::characterTextures[CharacterTextures::CharacterSkin1ForwardState1]));
        mForwardState.push_back(sf::Sprite(Resources::characterTextures[CharacterTextures::CharacterSkin1ForwardState2]));
        mForwardState.push_back(sf::Sprite(Resources::characterTextures[CharacterTextures::CharacterSkin1ForwardState3]));
        mForwardState.push_back(sf::Sprite(Resources::characterTextures[CharacterTextures::CharacterSkin1ForwardState4]));
        
        mLeftState.push_back(sf::Sprite(Resources::characterTextures[CharacterTextures::CharacterSkin1LeftState1]));
        mLeftState.push_back(sf::Sprite(Resources::characterTextures[CharacterTextures::CharacterSkin1LeftState2]));
        mLeftState.push_back(sf::Sprite(Resources::characterTextures[CharacterTextures::CharacterSkin1LeftState3]));
        mLeftState.push_back(sf::Sprite(Resources::characterTextures[CharacterTextures::CharacterSkin1LeftState4]));
        
        mRightState.push_back(sf::Sprite(Resources::characterTextures[CharacterTextures::CharacterSkin1RightState1]));
        mRightState.push_back(sf::Sprite(Resources::characterTextures[CharacterTextures::CharacterSkin1RightState2]));
        mRightState.push_back(sf::Sprite(Resources::characterTextures[CharacterTextures::CharacterSkin1RightState3]));
        mRightState.push_back(sf::Sprite(Resources::characterTextures[CharacterTextures::CharacterSkin1RightState4]));
    }
}

void Character::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {
    if (mDirection == 0) {
        target.draw(mForwardState[mCurrentState], states);
    } else if (mDirection == 1) {
        target.draw(mBackwardState[mCurrentState], states);
    } else if (mDirection == 2) {
        target.draw(mLeftState[mCurrentState], states);
    } else if (mDirection == 3) {
        target.draw(mRightState[mCurrentState], states);
    }
}

void Character::handleCurrentEvent(sf::RenderWindow &window, sf::Event &event) {
    handleMoveEvent(window, event);
}

void Character::updateCurrent(sf::Time dt, CommandQueue &commandQueue) {
    if (mStateTime > mThreshHold) {
        mCurrentState++;
        if (mCurrentState == mBackwardState.size()) {
            mCurrentState = 0;
        }
        mStateTime = 0.f;
        mClock.restart();
    }
    mStateTime += mClock.restart().asSeconds();

    updateMove(dt);
}

void Character::handleMoveEvent(sf::RenderWindow &window, sf::Event &event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == Controller::MOVE_UP) {
            mKeyInput.push(Controller::MOVE_UP);
        } else if (event.key.code == Controller::MOVE_DOWN) {
            mKeyInput.push(Controller::MOVE_DOWN);
        } else if (event.key.code == Controller::MOVE_LEFT) {
            mKeyInput.push(Controller::MOVE_LEFT);
        } else if (event.key.code == Controller::MOVE_RIGHT) {
            mKeyInput.push(Controller::MOVE_RIGHT);
        }
    }
}

void Character::updateMove(sf::Time dt) {
    if (!mKeyInput.empty()) {
        sf::Keyboard::Key key = mKeyInput.front();
        int direction = -1;
        if (key == Controller::MOVE_UP) {
            direction = 0;
        } else if (key == Controller::MOVE_DOWN) {
            direction = 1;
        } else if (key == Controller::MOVE_LEFT) {
            direction = 2;
        } else if (key == Controller::MOVE_RIGHT) {
            direction = 3;
        }
        if (!move(dt, direction)) {
            mKeyInput.pop();
            mCurrentStep = 0.f;
        }
    }
}

unsigned int Character::getCategory() const {
    return Category::Player;
}

void Character::setPosition(sf::Vector2f position) {
    for (auto &backwardState : mBackwardState) {
        backwardState.setPosition(position);
    }
    for (auto &forwardState : mForwardState) {
        forwardState.setPosition(position);
    }
    for (auto &leftState : mLeftState) {
        leftState.setPosition(position);
    }
    for (auto &rightState : mRightState) {
        rightState.setPosition(position);
    }
}

sf::Vector2f Character::getNextRightPosition(float x) {
    return sf::Vector2f(
        x, -(- (2 / Statistic::CHARACTER_JUMP_DISTANCE) * x * (x - Statistic::CHARACTER_JUMP_DISTANCE))
    );
}

sf::Vector2f Character::getNextLeftPosition(float x) {
    return sf::Vector2f(
        -x, -(- (2 / Statistic::CHARACTER_JUMP_DISTANCE) * x * (x - Statistic::CHARACTER_JUMP_DISTANCE))
    );
}

sf::Vector2f Character::getNextUpPosition(float x) {
    return sf::Vector2f(
        0, -x
    );
}

sf::Vector2f Character::getNextDownPosition(float x) {
    return sf::Vector2f(
        0, x
    );
}

bool Character::move(sf::Time dt, int direction) {
    if (mCurrentStep == 0.f) {
        mInitialPosition = mBackwardState[0].getPosition();
        mDirection = direction;
        mCurrentStep += mSpeed;
        return true;
    }
    else if (mCurrentStep < Statistic::CHARACTER_JUMP_DISTANCE) {
        mCurrentStep += mSpeed;
        sf::Vector2f nextPosition;
        if (direction == 0) {
            nextPosition = getNextUpPosition(mCurrentStep);
        } else if (direction == 1) {
            nextPosition = getNextDownPosition(mCurrentStep);
        } else if (direction == 2) {
            nextPosition = getNextLeftPosition(mCurrentStep);
        } else if (direction == 3) {
            nextPosition = getNextRightPosition(mCurrentStep);
        }
        sf::Vector2f newPosition = mInitialPosition + nextPosition;
        setPosition(newPosition);
        return true;
    }
    return false;
}