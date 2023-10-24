#ifndef HIGHSCORE_STATE_HPP
#define HIGHSCORE_STATE_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <State/StateStack.hpp>
#include <SceneGraph/SceneNode.hpp>
#include <GUI/Container.hpp>

class HighscoreState : public State {
public:
    HighscoreState(StateStack &stack, sf::RenderWindow &window);
    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event &event);
    virtual void buildScene();
private:
    sf::Sprite mBackgroundSprite;
    GUI::Container mGUIContainer;
};

#endif
