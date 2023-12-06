#ifndef PAUSE_STATE_HPP
#define PAUSE_STATE_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <State/StateStack.hpp>
#include <SceneGraph/SceneNode.hpp>
#include <GUI/Container.hpp>
#include <GUI/Button.hpp>
#include <GlobalVar.hpp>

class PauseState : public State {
public:
    PauseState(StateStack &stack, sf::RenderWindow &window);
    virtual void draw();
    virtual void update(sf::Time dt);
    virtual void handleEvent(sf::Event &event);
    virtual void buildScene();
private:
    CommandQueue mCommandQueue;
private:
    sf::RenderWindow &mWindow;
    GUI::Container mGUIContainer;
    std::function<void()> mContinueAction;
};

#endif