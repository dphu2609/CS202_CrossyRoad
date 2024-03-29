#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <bits/stdc++.h>
#include <State/StateStack.hpp>
#include <Configs.hpp>
#include <Menu/Menu.hpp>


class Game {
public:
    Game();
    ~Game();    
    void run();
private:
    void processEvents();
    void update(sf::Time dt);
    void render();
private:
    void loadTextures();
    void loadGifs();
    void loadFonts();
    void loadSounds();
    void registerStates();
private:
    sf::RenderWindow mWindow;
    StateStack mStateStack;
private:
    sf::Sound mBackgroundMusic;
    float mCurrentVolume = 100.f;
};

#endif