#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <State/StateStack.hpp>
#include <State/GameState/World.hpp>
#include <State/GameState/Player.hpp>
#include <GUI/Container.hpp>

class GameState : public State {
public:
    GameState(StateStack &stack, sf::RenderWindow &window);
    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event &event);
private:
    World mWorld;
    Player &mPlayer;
    GUI::Container mGUIContainer;
};

#endif
