#ifndef MENU_STATE_HPP
#define MENU_STATE_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <State/StateStack.hpp>
#include <SceneGraph/SceneNode.hpp>
#include <GUI/Container.hpp>
#include <GUI/Button.hpp>
#include <Configs.hpp>

class MenuState : public State {
public:
    MenuState(StateStack &stack, sf::RenderWindow &window);
    virtual void draw();
    virtual void update(sf::Time dt);
    virtual void handleEvent(sf::Event &event);
    virtual void buildScene();
private:
    CommandQueue mCommandQueue;
private:
    sf::RenderWindow &mWindow;
    GUI::Container mGUIContainer;
    std::function<void()> mNewGameAction;
    std::function<void()> mLoadGameAction;
};

#endif
