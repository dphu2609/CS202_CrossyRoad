#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <SFML/Graphics.hpp>
#include <Configs.hpp>
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

class Triangle
{
public:
    Triangle();

    void setPosition(float x,float y);
    void rotate(float x);
    sf::FloatRect getGlobalBounds();
    void changeToDark();
    void changeToLight();

    void draw(sf::RenderWindow& mWindow);
private:
    sf::RectangleShape bound;
    sf::Texture triangle;
    sf::Sprite triangleSprite;
};

class HalfCircle
{
public:
    HalfCircle();

    void setPosition(float x,float y);
    void rotate(float x);
    sf::FloatRect getGlobalBounds();
    void changeToDark();
    void changeToLight();

    void draw(sf::RenderWindow& mWindow);
private:
    sf::RectangleShape bound;
    sf::Texture halfcircle;
    sf::Sprite halfcircleSprite;
};

class BarArray
{
public:
    BarArray();

    void setPosition(float x,float y);
    void decreaseByOne();
    void increaseByOne();
    void reset();
    void setOldCurrent();
    void setCurrent();
    void setMusic();
    void setSound();

    void draw(sf::RenderWindow& mWindow);
private:
    int size;
    vector<sf::RectangleShape> barArray;
    int oldcurrent;
    int current;
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