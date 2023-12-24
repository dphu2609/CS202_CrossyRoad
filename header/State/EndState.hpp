#ifndef END_STATE_HPP
#define END_STATE_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <State/StateStack.hpp>
#include <SceneGraph/SceneNode.hpp>
#include <GUI/Container.hpp>
#include <GUI/Button.hpp>
#include <Configs.hpp>

class EndState : public State {
public:
    EndState(StateStack &stack, sf::RenderWindow &window);
    ~EndState();
    virtual void draw();
    virtual void update(sf::Time dt);
    virtual void handleEvent(sf::Event &event);
    virtual void buildScene();
private:
    CommandQueue mCommandQueue;
    void saveHighScore(const std::string &name);

private:
    sf::RenderWindow &mWindow;
    GUI::Container mGUIContainer;
    std::function<void()> mContinueAction;
    std::function<void()> mBackToMenuAction;
    std::function<void()> mRestartAction;
    std::function<void()> mExitAction;
    std::vector<sf::Sprite> CharacterSprites;
    int cur = 0;
    sf::Time mChangeTime;
    sf::Text mEndText;
    sf::Sprite mBackground;
    sf::Text HighScore;
};

#endif
