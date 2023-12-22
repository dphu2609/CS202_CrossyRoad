#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <Menu/MainScreen.hpp>
#include <Menu/NewGame.hpp>
#include <Menu/HighScore.hpp>
#include <Menu/Setting.hpp>
#include <Menu/Instruction.hpp>
#include <State/StateStack.hpp>

class Menu : public State // Phu have changed here
{
public:
    Menu(StateStack &stack, sf::RenderWindow &window); // Phu have changed here
    bool playState();
    void returnFromEscapeKey();
    virtual void buildScene(); // Phu have changed here
    virtual void draw(); // Phu have changed here
    virtual void update(sf::Time dt); // Phu have changed here
    virtual void handleEvent(sf::Event &event); // Phu have changed here
private:
    sf::RenderWindow &mWindow; // Phu have changed here
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

    sf::Vector2f sizeTheme;
    sf::Texture backgroundLight; 
    sf::Sprite backgroundLightSprite;
    sf::Texture backgroundLight2; 
    sf::Sprite backgroundLight2Sprite;

    bool lightScreen;
    sf::Time mTime;
    sf::Time timePerFrame;

    bool mIsGameOver = true; // Phu have changed here
};



#endif //MENU_HPP