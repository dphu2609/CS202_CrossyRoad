#ifndef HIGHSCORE_HPP
#define HIGHSCORE_HPP

#include <SFML/Graphics.hpp>

class HighScore
{
public:
    HighScore();
    void processEvent(sf::Event& event);
    void draw(sf::RenderWindow& mWindow);
private:
    sf::Color colorBound;
    sf::Vector2f sizeBound;
    sf::Vector2f sizeTheme;
    sf::Font _font;
    sf::Color colorCharacter;
    unsigned int sizeCharacter;

    sf::Text title;
    sf::RectangleShape returnBound;
    sf::Texture returnImage;
    sf::Sprite returnImageSprite;
    sf::Text onep;
    sf::Text twop;
    sf::RectangleShape firstBound;
    sf::RectangleShape secondBound;
    sf::Texture background; 
    sf::Sprite backgroundSprite;
};

#endif //HIGHSCORE_HPP