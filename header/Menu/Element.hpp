#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <SFML/Graphics.hpp>
#include <string>

using namespace std;

class Pack
{
public:
    Pack();
    Pack(sf::RectangleShape& bound,sf::Text& text);
    sf::FloatRect getGlobalBounds();
    void setCharacterSize(int size);
private:
    sf::RectangleShape bound;
    sf::Text text;
};

class Link
{
public:
    Link(int x);
    string getLink();
private:
    string s;
};

#endif //ELEMENT_HPP