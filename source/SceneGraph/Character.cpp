#include <SceneGraph/Character.hpp>

Character::Character(sf::View &view) : mView(view) {
    this->setSkin(Statistic::PLAYER_SKIN_TYPE);
    this->setOrigin(mBackwardState.getGlobalBounds().width / 2, mBackwardState.getGlobalBounds().height / 2);
}

void Character::setSkin(int skin) {
    if (skin == Skin1) {
        mBackwardState.set(Resources::gifsHolder[GIFs::CharacterSkin1Backward]);
        mForwardState.set(Resources::gifsHolder[GIFs::CharacterSkin1Forward]);
        mLeftState.set(Resources::gifsHolder[GIFs::CharacterSkin1Left]);
        mRightState.set(Resources::gifsHolder[GIFs::CharacterSkin1Right]);
    }
}

void Character::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {
    if (mDirection == 0) {
        target.draw(mForwardState, states);
    } else if (mDirection == 1) {
        target.draw(mBackwardState, states);
    } else if (mDirection == 2) {
        target.draw(mLeftState, states);
    } else if (mDirection == 3) {
        target.draw(mRightState, states);
    }
}

void Character::handleCurrentEvent(sf::RenderWindow &window, sf::Event &event) {
    handleMoveEvent(window, event);
}

void Character::updateCurrent(sf::Time dt, CommandQueue &commandQueue) {
    if (mDirection == 0) {
        mForwardState.update(dt);
    } else if (mDirection == 1) {
        mBackwardState.update(dt);
    } else if (mDirection == 2) {
        mLeftState.update(dt);
    } else if (mDirection == 3) {
        mRightState.update(dt);
    }
    updateMove(dt);
    updateWorldView(dt);
}

void Character::resetCurrentView() {
    sf::Vector2f newPosition = this->getPosition() + sf::Vector2f(0, Statistic::RESET_VIEW_POSITION.y);
    this->setPosition(newPosition);
    if (mIsMoving) {
        mInitialPosition.y += Statistic::RESET_VIEW_POSITION.y;
    }
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
    else if (event.type == sf::Event::KeyReleased) {
        if (!mKeyInput.empty()) mKeyInput.push(mKeyInput.front());
        while (mKeyInput.size() > 1) {
            mKeyInput.pop();
        }
    }
}

sf::FloatRect Character::getBoundingRect() const {
    return this->getWorldTransform().transformRect(mBackwardState.getGlobalBounds());
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

void Character::updateWorldView(sf::Time dt) {
    sf::Vector2f centerPosition = mView.getCenter();
    if (this->getPosition().y < centerPosition.y) {
        Statistic::SCREEN_SPEED = Statistic::SCREEN_SPEED_INCREASE;
    }
    else {
        Statistic::SCREEN_SPEED = Statistic::SCREEN_SPEED_DEFAULT;
    }
}

unsigned int Character::getCategory() const {
    return Category::Player;
}

sf::Vector2f Character::getNextRightPosition(float x) {
    return sf::Vector2f(
        x, -(- (2 / Statistic::CHARACTER_JUMP_DISTANCE_HORIZONTAL) * x * (x - Statistic::CHARACTER_JUMP_DISTANCE_HORIZONTAL))
    );
}

sf::Vector2f Character::getNextLeftPosition(float x) {
    return sf::Vector2f(
        -x, -(- (2 / Statistic::CHARACTER_JUMP_DISTANCE_HORIZONTAL) * x * (x - Statistic::CHARACTER_JUMP_DISTANCE_HORIZONTAL))
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
    float mSpeed = (direction < 2 ? Statistic::CHARACTER_JUMP_DISTANCE_VERTICAL / 5 : Statistic::CHARACTER_JUMP_DISTANCE_HORIZONTAL / 5);
    if (mCurrentStep == 0.f) {
        mInitialPosition = this->getPosition();
        mDirection = direction;
        mCurrentStep += mSpeed;
        return mIsMoving = true;
    }
    else if (mCurrentStep < (direction < 2 ? Statistic::CHARACTER_JUMP_DISTANCE_VERTICAL : Statistic::CHARACTER_JUMP_DISTANCE_HORIZONTAL)) {
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
        return mIsMoving = true;
    }
    return mIsMoving = false;
}

sf::FloatRect Character::getSpriteBounding()
{
    return mForwardState.getGlobalBounds();
}
