#ifndef SETTING_HPP
#define SETTING_HPP

#include <SFML/Graphics.hpp>

class Setting
{
public:
    Setting();
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
    sf::Text reset;
    sf::RectangleShape resetBound;
    sf::Text save;
    sf::RectangleShape saveBound;
    sf::Text onep;
    sf::Text twop;
    sf::Text music;
    sf::RectangleShape musicBound;
    sf::RectangleShape musicBar;
    sf::Text sound;
    sf::RectangleShape soundBound;
    sf::RectangleShape soundBar;
    sf::Texture background; 
    sf::Sprite backgroundSprite;
};

#endif //SETTING_HPP