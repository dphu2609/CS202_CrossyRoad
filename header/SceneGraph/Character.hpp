#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <bits/stdc++.h>
#include <SceneGraph/SceneNode.hpp>
#include <GlobalVar.hpp>   

class Character : public SceneNode {
public:
    Character(sf::View &view, int currentRoadIndex);
    Character(sf::View &view, std::ifstream &file);
    sf::FloatRect getSpriteBounding();
    bool canMoveLeft = true;
    bool canMoveRight = true;
    bool canMoveUp = true;
    bool canMoveDown = true;
private:
    virtual void updateCurrent(sf::Time dt, CommandQueue &commandQueue);
    virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
    virtual void handleCurrentEvent(sf::RenderWindow &window, sf::Event &event);
    virtual unsigned int getCategory() const;
private:
    int mCurrentRoadIndex;
public:
    int getCurrentRoadIndex();
    void setCurrentRoadIndex(int currentRoadIndex);
    void increaseCurrentRoadIndex();
    virtual sf::FloatRect getBoundingRect() const;
public:
    void readData(std::ifstream &file);
    void writeData(std::ofstream &file);
private:
    sf::View &mView;
    Gif mBackwardState;
    Gif mForwardState;
    Gif mLeftState;
    Gif mRightState;
    int mDirection = 1; // 0: forward, 1: backward, 2: left, 3: right
private:
    enum SkinType {
        Skin1,
        Skin2,
        Skin3
    };
    void setSkin(int skinType);
private:
    void handleMoveEvent(sf::RenderWindow &window, sf::Event &event);
    void updateMove(sf::Time dt);
    void updateWorldView(sf::Time dt);
    bool moveCharacter(sf::Time dt, int direction); 
    void updateIfOutOfScreen(sf::Time dt);
    
    sf::Vector2f getNextRightPosition(float x);
    sf::Vector2f getNextLeftPosition(float x);
    sf::Vector2f getNextUpPosition(float x);
    sf::Vector2f getNextDownPosition(float x);

    float mCurrentStep = 0.f;
    sf::Vector2f mInitialPosition;
    bool mIsMoving = false;
    virtual void resetCurrentView();
public:
    int getLanePassed() const;
private:
    int mLanePassed = 0;
private:
    std::queue<char> mKeyInput;
private:
    sf::Sound mJumpSound;
private:
    virtual void setCurrentEnvSoundVolume(float volume);
private:
    bool mIsOutOfRiver = false;
    std::vector<float> mJumpPositions;
    float mStartPosition = -878.f;
public:
    void setPositionAfterJumpOutRiver();
private:
    bool mIsDead = false;   
    bool mIsDeathAnimationExecuting = false;
    float mCurrentAngle = 0.f;
    sf::Vector2f mCurrentSize = Statistic::CHARACTER_SIZE;
    bool mIsDeadByLeftVehicle = false;
    bool mIsDeadByRightVehicle = false;
    bool mIsDeadByRiver = false;
    bool mIsDeadByTrain = false;
    void setDeadByLeftVehicleAnimation(sf::Time dt);
    void setDeadByRightVehicleAnimation(sf::Time dt);
    void setDeadByRiverAnimation(sf::Time dt);
    void deathController(sf::Time dt);
public:
    bool isDead() const;
    void setDeadByLeftVehicle();
    void setDeadByRightVehicle();
    void setDeadByRiver();
};

#endif