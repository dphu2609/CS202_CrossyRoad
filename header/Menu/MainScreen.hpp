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
    sf::Vector2f posBackGroundLight();
    sf::Vector2f posBackGroundLight2();
    void setPosBackgroundLight(sf::Vector2f pos);
    void setPosBackgroundLight2(sf::Vector2f pos);      
    bool stateBackgroundLight();  
    void setBackground(bool isBackgoundLight);  
    int processEvent(sf::Event& event,sf::RenderWindow& mWindow);
    void update(sf::Time dt);
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
    sf::Texture backgroundLight; 
    sf::Sprite backgroundLightSprite;
    sf::Texture backgroundLight2; 
    sf::Sprite backgroundLight2Sprite;

    vector<Pack> packs;
    bool lightScreen;
    sf::Time mTime;
    sf::Time timePerFrame;
};

#endif //MAINSCREEN_HPP