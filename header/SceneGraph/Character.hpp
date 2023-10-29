#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <SceneGraph/SceneNode.hpp>
#include <GlobalVar.hpp>

class Character : public SceneNode {
public:
    Character();
private:
    virtual void updateCurrent(sf::Time dt, CommandQueue &commandQueue);
    virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
    // virtual void handleCurrentEvent(sf::RenderWindow &window, sf::Event &event);
    virtual unsigned int getCategory() const;
private:
    std::vector<sf::Sprite> mBackwardState;
    std::vector<sf::Sprite> mForwardState; 
    std::vector<sf::Sprite> mLeftState;
    std::vector<sf::Sprite> mRightState; 
    sf::Clock mClock; // use to change state of character
    float mStateTime = 0.f; // use to change state of character
    float mThreshHold = 0.4f; // use to change state of character
    int mDirection = 0; // 0: backward, 1: forward, 2: left, 3: right
    int mCurrentState = 0; // current state of character
private:
    enum SkinType {
        Skin1,
        Skin2,
        Skin3
    };
    void setSkin(int skinType);
private:
    virtual void moveUp() {}
    virtual void moveDown() {}
    virtual void moveLeft() {}
    virtual void moveRight() {}
private:
    bool mIsJumping = false;
    std::vector<sf::Keyboard::Key> mKeyInput;
};

#endif