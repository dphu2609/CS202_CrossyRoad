#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <SceneGraph/SceneNode.hpp>
#include <GlobalVar.hpp>
#include <Resources/Gif.hpp>    

class Character : public SceneNode {
public:
    Character(sf::View &view, int currentRoadIndex);
    sf::FloatRect getSpriteBounding();
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
    bool move(sf::Time dt, int direction); 
    
    sf::Vector2f getNextRightPosition(float x);
    sf::Vector2f getNextLeftPosition(float x);
    sf::Vector2f getNextUpPosition(float x);
    sf::Vector2f getNextDownPosition(float x);

    float mCurrentStep = 0.f;
    sf::Vector2f mInitialPosition;
    bool mIsMoving = false;
    virtual void resetCurrentView();
private:
    std::queue<sf::Keyboard::Key> mKeyInput;
};

#endif