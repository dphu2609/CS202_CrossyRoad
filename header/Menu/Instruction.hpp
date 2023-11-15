#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include <SFML/Graphics.hpp>

class Instruction
{
public:
    Instruction();
    int processEvent(sf::Event& event,sf::RenderWindow& mWindow);
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
    sf::RectangleShape bound;
    sf::Text part;
    sf::Texture left;
    sf::Sprite leftSprite;
    sf::Texture right;
    sf::Sprite rightSprite;
    sf::Texture background; 
    sf::Sprite backgroundSprite;
};

#endif //INSTRUCTION_HPP