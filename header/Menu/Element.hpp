#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <SFML/Graphics.hpp>

class Pack
{
public:
    Pack();
    Pack(sf::RectangleShape& bound,sf::Text& text);
    sf::FloatRect getGlobalBounds();
private:
    sf::RectangleShape bound;
    sf::Text text;
};

#endif //ELEMENT_HPP