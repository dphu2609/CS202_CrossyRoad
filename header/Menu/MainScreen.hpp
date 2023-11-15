#ifndef MAINSCREEN_HPP
#define MAINSCREEN_HPP

#include <SFML/Graphics.hpp>
#include <Menu/Element.hpp>
#include <vector>
using namespace std;

class MainScreen
{
public:
    MainScreen();
    int processEvent(sf::Event& event,sf::RenderWindow& mWindow);
    void draw(sf::RenderWindow& mWindow);
private:
    sf::Vector2f pos;
    sf::Vector2f sizeBound;
    sf::Color colorBound;
    sf::Vector2f sizeTheme;
    sf::Font _font;
    unsigned int sizeCharacter;
    sf::Color colorCharacter;

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

    vector<Pack> packs;
};

#endif //MAINSCREEN_HPP