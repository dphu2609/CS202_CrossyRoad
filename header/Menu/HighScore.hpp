#ifndef HIGHSCORE_HPP
#define HIGHSCORE_HPP

#include <SFML/Graphics.hpp>

class HighScore
{
public:
    HighScore();
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
    sf::Texture backgroundLight; 
    sf::Sprite backgroundLightSprite;
    sf::Texture backgroundLight2; 
    sf::Sprite backgroundLight2Sprite;

    bool lightScreen;
    sf::Time mTime;
    sf::Time timePerFrame;
};

#endif //HIGHSCORE_HPP