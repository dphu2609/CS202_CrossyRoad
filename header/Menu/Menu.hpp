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
    void update(sf::Time dt);
    void processEvent(sf::Event& event);
    void draw(int state, sf::RenderWindow& mWindow);
private:
    int state;
    MainScreen mainscreen;
    NewGame newgame;
    HighScore highscore;
    Setting setting;
    Instruction instruction;
};

#endif //MENU_HPP