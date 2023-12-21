#include <SceneGraph/Character.hpp>

Character::Character(sf::View &view, int currentRoadIndex) : mView(view), mCurrentRoadIndex(currentRoadIndex) {
    this->setSkin(Statistic::PLAYER_SKIN_TYPE);
    this->setOrigin(mBackwardState.getGlobalBounds().width / 2, mBackwardState.getGlobalBounds().height / 2);

    mJumpPositions.push_back(mStartPosition);
    for (int i = 0; i < 19; i++) {
        mJumpPositions.push_back(mJumpPositions.back() + Statistic::CHARACTER_JUMP_DISTANCE_HORIZONTAL);
    }

    mJumpSound.setBuffer(Resources::sounds[Sounds::JumpSound]);
    mHitSound.setBuffer(Resources::sounds[Sounds::HitSound]);
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
    if (!mIsDeathAnimationExecuting)
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
    updateIfOutOfScreen(dt);
    deathController(dt);
    updateMove(dt);
    updateWorldView(dt);
} 

void Character::handleMoveEvent(sf::RenderWindow &window, sf::Event &event) {
    if (event.type == sf::Event::TextEntered && !mIsMoving) {
        // cout<<event.text.unicode<<endl;
        // cout<<static_cast<char>(Controller::MOVE_UP_SET_1)<<endl;
        // cout<<static_cast<char>(Controller::MOVE_DOWN_SET_1)<<endl;
        // cout<<static_cast<char>(Controller::MOVE_LEFT_SET_1)<<endl;
        // cout<<static_cast<char>(Controller::MOVE_RIGHT_SET_1)<<endl;

        if (event.text.unicode == Controller::MOVE_UP_SET_1) {
            if(canMoveUp)
                mKeyInput.push(Controller::MOVE_UP_SET_1);
            else 
                mDirection = 0;
        } else if (event.text.unicode == Controller::MOVE_DOWN_SET_1) {
            if(canMoveDown)
                mKeyInput.push(Controller::MOVE_DOWN_SET_1);
            else
                mDirection = 1;
        } else if (event.text.unicode == Controller::MOVE_LEFT_SET_1) {
            if(canMoveLeft)
                mKeyInput.push(Controller::MOVE_LEFT_SET_1);
            else
                mDirection = 2;
        } else if (event.text.unicode == Controller::MOVE_RIGHT_SET_1) {
            if(canMoveRight)
                mKeyInput.push(Controller::MOVE_RIGHT_SET_1);
            else
                mDirection = 3;
        }
    }
    else if (event.type == sf::Event::KeyPressed && !mIsMoving) {
        if (event.key.code == sf::Keyboard::Up) {
            if(canMoveUp)
                mKeyInput.push(Controller::MOVE_UP_SET_1);
            else    
                mDirection = 0;
        } else if (event.key.code == sf::Keyboard::Down) {
            if(canMoveDown)
                mKeyInput.push(Controller::MOVE_DOWN_SET_1);
            else
                mDirection = 1;
        } else if (event.key.code == sf::Keyboard::Left) {
            if(canMoveLeft)
                mKeyInput.push(Controller::MOVE_LEFT_SET_1);
            else 
                mDirection = 2;
        } else if (event.key.code == sf::Keyboard::Right) {
            if(canMoveRight)
                mKeyInput.push(Controller::MOVE_RIGHT_SET_1);
            else    
                mDirection = 3;
        }
    }
    else if (event.type == sf::Event::KeyReleased && !mIsMoving) {
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
        char key = mKeyInput.front();
        int direction = -1;
        if (key == Controller::MOVE_UP_SET_1 || key == Controller::MOVE_UP_SET_2) {
            direction = 0;
        } else if (key == Controller::MOVE_DOWN_SET_1 || key == Controller::MOVE_DOWN_SET_2) {
            direction = 1;
        } else if (key == Controller::MOVE_LEFT_SET_1 || key == Controller::MOVE_LEFT_SET_2) {
            direction = 2;
        } else if (key == Controller::MOVE_RIGHT_SET_1 || key == Controller::MOVE_RIGHT_SET_2) {
            direction = 3;
        }
        if (!moveCharacter(dt, direction)) {
            mKeyInput.pop();
            mCurrentStep = 0.f;
        }
    }
}

void Character::updateIfOutOfScreen(sf::Time dt) {
    if (this->getPosition().x < - Statistic::SCREEN_WIDTH / 2 + 100) {
        while (!mKeyInput.empty()) {
            if (mKeyInput.front() == Controller::MOVE_LEFT_SET_1 || mKeyInput.front() == Controller::MOVE_LEFT_SET_2) {
                mKeyInput.pop();
            } 
            else break;
        }   
    }
    if (this->getPosition().x > Statistic::SCREEN_WIDTH / 2 - 100) {
        while (!mKeyInput.empty()) {
            if (mKeyInput.front() == Controller::MOVE_RIGHT_SET_1 || mKeyInput.front() == Controller::MOVE_RIGHT_SET_2) {
                mKeyInput.pop();
            }
            else break;
        }
    }


    sf::Vector2f globalPosition = this->getWorldTransform().transformPoint(this->getPosition());

    if (globalPosition.y - mView.getCenter().y > 550) {
        mHitSound.play();
        mIsDead = true;
    }
}

int Character::getCurrentRoadIndex() {
    return mCurrentRoadIndex;
}

void Character::setCurrentRoadIndex(int currentRoadIndex) {
    mCurrentRoadIndex = currentRoadIndex;
}

void Character::increaseCurrentRoadIndex() {
    mCurrentRoadIndex++;
}

void Character::resetCurrentView() {
    if (mIsMoving) {
        mInitialPosition.y += Statistic::RESET_VIEW_POSITION.y;
    }
}   

void Character::updateWorldView(sf::Time dt) {
    sf::Vector2f centerPosition = mView.getCenter();
    if (this->getPosition().y + Statistic::CHARACTER_SPAWN_POSITION.y + Statistic::ROAD_HEIGHT * 5 < centerPosition.y) {
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

bool Character::moveCharacter(sf::Time dt, int direction) {
    float mSpeed = (direction < 2 ? Statistic::CHARACTER_JUMP_DISTANCE_VERTICAL / 5 : Statistic::CHARACTER_JUMP_DISTANCE_HORIZONTAL / 5);
    if (mCurrentStep == 0.f) {
        if (mIsOutOfRiver) {
            float delta = std::abs(this->getPosition().x - mJumpPositions.front());
            float temp = delta + 1;
            int index = 0;
            while (delta < temp) {
                temp = delta;
                delta = std::abs(this->getPosition().x - mJumpPositions[++index]);
            }
            if (index != 0) index--;
            this->setPosition(mJumpPositions[index], this->getPosition().y);
            mIsOutOfRiver = false;
        }
        mInitialPosition = this->getPosition();
        mDirection = direction;
        mCurrentStep += mSpeed;
        mCurrentRoadIndex += (direction < 2 ? (direction == 0 ? -1 : 1) : 0);
        mJumpSound.play();
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
    else {
        if (mDirection == 0) mLanePassed++;
        else if (mDirection == 1) mLanePassed--;
    }
    return mIsMoving = false;
}

void Character::setPositionAfterJumpOutRiver() {
    mIsOutOfRiver = true;
}

sf::FloatRect Character::getSpriteBounding()
{
    return mForwardState.getGlobalBounds();
}

int Character::getLanePassed() const {
    return mLanePassed;
}

void Character::writeData(std::ofstream &file) {
    file << mDirection << std::endl;
    file << mCurrentRoadIndex << std::endl;
    file << mLanePassed << std::endl;
    file << getPosition().x << " " << getPosition().y << std::endl;
}
    
void Character::readData(std::ifstream &file) {
    file >> mDirection;
    file >> mCurrentRoadIndex;
    file >> mLanePassed;
    float x, y;
    file >> x >> y;
    setPosition(x, y);
}

Character::Character(sf::View &view, std::ifstream &file) : mView(view) {
    this->setSkin(Statistic::PLAYER_SKIN_TYPE);
    this->setOrigin(mBackwardState.getGlobalBounds().width / 2, mBackwardState.getGlobalBounds().height / 2);
    this->setScale(Statistic::CHARACTER_SIZE.x / this->getSpriteBounding().width, Statistic::CHARACTER_SIZE.y / this->getSpriteBounding().height);
    mJumpPositions.push_back(mStartPosition);
    for (int i = 0; i < 19; i++) {
        mJumpPositions.push_back(mJumpPositions.back() + Statistic::CHARACTER_JUMP_DISTANCE_HORIZONTAL);
    }
    mJumpSound.setBuffer(Resources::sounds[Sounds::JumpSound]);
    mHitSound.setBuffer(Resources::sounds[Sounds::HitSound]);
    readData(file);
}  

void Character::setCurrentEnvSoundVolume(float volume) {
    mJumpSound.setVolume(volume);
}

void Character::setDeadByLeftVehicle() {
    mHitSound.play();
    mIsDeathAnimationExecuting = true;
    mIsDeadByLeftVehicle = true;
}

void Character::setDeadByRightVehicle() {
    mHitSound.play();
    mIsDeathAnimationExecuting = true;
    mIsDeadByRightVehicle = true;
}


void Character::setDeadByRiver() {
    mHitSound.play();
    mIsDeathAnimationExecuting = true;
    mIsDeadByRiver = true;
}

void Character::setDeadByLeftVehicleAnimation(sf::Time dt) {
    if (mCurrentAngle == 0) {
        while (!mKeyInput.empty()) {
            mKeyInput.pop();
        }
        mKeyInput.push(Controller::MOVE_LEFT_SET_1);
    }
    mBackwardState.setRotation(mCurrentAngle);
    mForwardState.setRotation(mCurrentAngle);
    mLeftState.setRotation(mCurrentAngle);
    mRightState.setRotation(mCurrentAngle);
    mCurrentAngle -= 90 / 5;
    if (mCurrentAngle < -90) {
        mIsDead = true;
    }   
}

void Character::setDeadByRightVehicleAnimation(sf::Time dt) {
    if (mCurrentAngle == 0) {
        while (!mKeyInput.empty()) {
            mKeyInput.pop();
        }
        mKeyInput.push(Controller::MOVE_RIGHT_SET_1);
    }
    mBackwardState.setRotation(mCurrentAngle);
    mForwardState.setRotation(mCurrentAngle);
    mLeftState.setRotation(mCurrentAngle);
    mRightState.setRotation(mCurrentAngle);
    mCurrentAngle += 90 / 5;
    if (mCurrentAngle > 90) {
        mIsDead = true;
    }   
}

void Character::setDeadByRiverAnimation(sf::Time dt) {
    mBackwardState.setOpacity(mCurrentOpacity);
    mForwardState.setOpacity(mCurrentOpacity);
    mLeftState.setOpacity(mCurrentOpacity);
    mRightState.setOpacity(mCurrentOpacity);
    mCurrentOpacity -= 0.1;
    if (mCurrentOpacity <= 0) {
        mIsDead = true;
    }
}

void Character::deathController(sf::Time dt) {
    if (mIsDead) return;
    if (mIsDeadByLeftVehicle) {
        setDeadByLeftVehicleAnimation(dt);
    } else if (mIsDeadByRightVehicle) {
        setDeadByRightVehicleAnimation(dt);
    } else if (mIsDeadByRiver) {
        setDeadByRiverAnimation(dt);
    }
}

bool Character::isDead() const {
    return mIsDead;
}
