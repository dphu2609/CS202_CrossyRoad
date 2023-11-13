#ifndef MAINSCREEN_HPP
#define MAINSCREEN_HPP

#include <SFML/Graphics.hpp>

class MainScreen
{
public:
    MainScreen();
    void processEvent(sf::Event& event);
    void draw(sf::RenderWindow& mWindow);
private:
    sf::Vector2f pos;
    sf::Vector2f sizeBound;
    sf::Font _font;

    sf::Text title;
    sf::Text newgame;
    sf::RectangleShape newgameBound;
    sf::Text highscore;
    sf::RectangleShape highscoreBound;
    sf::Text setting;
    sf::RectangleShape settingBound;
    sf::Text instruction;
    sf::RectangleShape instructionBound;
    sf::Texture background; 
    sf::Sprite backgroundSprite;

};

#endif //MAINSCREEN_HPP