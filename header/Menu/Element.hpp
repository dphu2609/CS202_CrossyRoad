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
private:
    sf::RectangleShape bound;
    sf::Text text;
};

class Circle
{
public:
    Circle();

    sf::FloatRect getGlobalBounds();
    // void setOrigin(float x,float y);
    void setPosition(float x,float y);
    // void setScale(float x,float y);
    void changeToDark();
    void changeToLight();

    void draw(sf::RenderWindow& mWindow);
private:
    sf::Texture circleImage;
    sf::Sprite circleImageSprite;
    sf::CircleShape circle;
    bool isCircleLight;
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