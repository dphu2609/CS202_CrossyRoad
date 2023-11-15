#ifndef NEWGAME_HPP
#define NEWGAME_HPP

#include <SFML/Graphics.hpp>
#include <menu/Element.hpp>
#include <SceneGraph/Character.hpp>
#include <vector>

using namespace std;

class NewGame
{
public:
    NewGame();
    int processEvent(sf::Event& event,sf::RenderWindow& mWindow);
    void draw(sf::RenderWindow& mWindow);
private:
    sf::Color colorBound;
    sf::Vector2f sizeBound;
    sf::Vector2f sizeTheme;
    sf::Font _font;
    sf::Color colorCharacter;
    unsigned int sizeCharacter;
    sf::Vector2f modePos;

    sf::Text title;
    sf::RectangleShape returnBound;
    sf::Texture returnImage;
    sf::Sprite returnImageSprite;
    sf::RectangleShape onepBound;
    sf::Text onep;
    sf::RectangleShape twopBound;
    sf::Text twop;
    sf::RectangleShape firstpBound;
    sf::Text firstp;
    sf::RectangleShape secondpBound;
    sf::Text secondp;
    sf::RectangleShape firstpLeftBound;
    sf::Texture firstpLeft;
    sf::RectangleShape firstpRightBound;
    sf::Texture firstpRight;
    sf::RectangleShape secondpLeftBound;
    sf::Texture secondpLeft;
    sf::RectangleShape secondpRightBound;
    sf::Texture secondpRight;
    sf::Texture firstPlayer;
    sf::Sprite firstPlayerSprite;
    sf::Texture secondPlayer;
    sf::Sprite secondPlayerSprite;
    sf::Text easy;
    sf::Text medium;
    sf::Text hard;
    sf::Text extreme;
    sf::Texture easyCircle;
    sf::Texture mediumCircle;
    sf::Texture hardCircle;
    sf::Texture extremeCircle;
    sf::RectangleShape playBound;
    sf::Text play;
    sf::Texture background; 
    sf::Sprite backgroundSprite;

    vector<Pack> packs;
    //Character first;
    //Character second;
};

#endif //NEWGAME_HPP