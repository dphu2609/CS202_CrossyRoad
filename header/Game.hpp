#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <State/StateStack.hpp>
#include <GlobalVar.hpp>
#include <Menu/Menu.hpp>

class Game {
public:
    Game();
    void run();
private:
    void processEvents();
    void update(sf::Time dt);
    void render();
private:
    void loadTextures();
    void loadFonts() {}
    void loadMusics() {}
    void registerStates();
private:
    sf::RenderWindow mWindow;
    //StateStack mStateStack;
    Menu mMenu;
};

#endif