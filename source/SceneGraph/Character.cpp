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
        target.draw(mBackwardState[mCurrentState], states);
    } else if (mDirection == 1) {
        target.draw(mForwardState[mCurrentState], states);
    } else if (mDirection == 2) {
        target.draw(mLeftState[mCurrentState], states);
    } else if (mDirection == 3) {
        target.draw(mRightState[mCurrentState], states);
    }
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
}

unsigned int Character::getCategory() const {
    return Category::Player;
}