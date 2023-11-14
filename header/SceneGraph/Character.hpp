#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <SceneGraph/SceneNode.hpp>
#include <GlobalVar.hpp>

class Character : public SceneNode {
public:
    Character();
    sf::FloatRect getSpriteBounding();
private:
    virtual void updateCurrent(sf::Time dt, CommandQueue &commandQueue);
    virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
    virtual void handleCurrentEvent(sf::RenderWindow &window, sf::Event &event);
    virtual unsigned int getCategory() const;
    virtual sf::FloatRect getBoundingRect() const;
private:
    std::vector<sf::Sprite> mBackwardState;
    std::vector<sf::Sprite> mForwardState; 
    std::vector<sf::Sprite> mLeftState;
    std::vector<sf::Sprite> mRightState; 
    sf::Clock mClock; // use to change state of character
    float mStateTime = 0.f; // use to change state of character
    float mThreshHold = 0.4f; // use to change state of character
    int mDirection = 1; // 0: forward, 1: backward, 2: left, 3: right
    int mCurrentState = 0; // current state of character
private:
    enum SkinType {
        Skin1,
        Skin2,
        Skin3
    };
    void setSkin(int skinType);

private:
    // void setPosition(sf::Vector2f position);
private:
    void handleMoveEvent(sf::RenderWindow &window, sf::Event &event);
    void updateMove(sf::Time dt);
    bool move(sf::Time dt, int direction); 
    
    sf::Vector2f getNextRightPosition(float x);
    sf::Vector2f getNextLeftPosition(float x);
    sf::Vector2f getNextUpPosition(float x);
    sf::Vector2f getNextDownPosition(float x);

    float mCurrentStep = 0.f;
    float mSpeed = Statistic::CHARACTER_JUMP_DISTANCE_HORIZONTAL / 5;
    sf::Vector2f mInitialPosition;
private:
    std::queue<sf::Keyboard::Key> mKeyInput;
};

#endif