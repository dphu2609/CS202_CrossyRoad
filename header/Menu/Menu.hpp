#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <Menu/MainScreen.hpp>
#include <Menu/NewGame.hpp>
#include <Menu/HighScore.hpp>
#include <Menu/Setting.hpp>
#include <Menu/Instruction.hpp>

class Menu
{
public:
    Menu(); 
    bool playState();
    void returnFromEscapeKey();
    void update(sf::Time dt);
    void processEvent(sf::Event& event,sf::RenderWindow& mWindow);
    void draw(sf::RenderWindow& mWindow);
private:
    int state;
    MainScreen mainscreen;
    NewGame newgame;
    HighScore highscore;
    Setting setting;
    Instruction instruction;
    sf::Vector2f posBackgroundLight;
    sf::Vector2f posBackgroundLight2;
    bool isBackgroundLight;
    bool isPlay;
};



#endif //MENU_HPP