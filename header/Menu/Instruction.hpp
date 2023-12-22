#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include <SFML/Graphics.hpp>
#include <Menu/Element.hpp>

class Instruction
{
public:
    Instruction();

    // sf::Vector2f posBackGroundLight();
    // sf::Vector2f posBackGroundLight2();
    // void setPosBackgroundLight(sf::Vector2f pos);
    // void setPosBackgroundLight2(sf::Vector2f pos);
    // bool stateBackgroundLight();  
    // void setBackground(bool isBackgoundLight);
    void previous();
    void next();  

    int processEvent(sf::Event& event,sf::RenderWindow& mWindow);
    void update(sf::Time dt);
    void draw(sf::RenderWindow& mWindow);
private:
    sf::Color colorBound;
    sf::Vector2f sizeBound;
    // sf::Vector2f sizeTheme;
    sf::Font _font;
    sf::Color colorCharacter;
    unsigned int sizeCharacter;

    sf::Text title;

    bool isReturnOn;
    sf::RectangleShape returnBound;
    sf::Texture returnImage;
    sf::Sprite returnImageSprite;
    sf::Texture returnImageDark;
    sf::Sprite returnImageDarkSprite;

    bool isOneIncreaseOn;
    bool isOneDecreaseOn;
    sf::Texture triangle;
    sf::Texture triangleDark;
    sf::RectangleShape oneIncreaseBound;
    sf::Sprite oneIncreaseTriangle;
    sf::Sprite oneIncreaseTriangleDark;
    sf::RectangleShape oneDecreaseBound;
    sf::Sprite oneDecreaseTriangle;
    sf::Sprite oneDecreaseTriangleDark;
    sf::RectangleShape bound;
    sf::Text part;
    
    // sf::Texture backgroundLight; 
    // sf::Sprite backgroundLightSprite;
    // sf::Texture backgroundLight2; 
    // sf::Sprite backgroundLight2Sprite;

    // bool lightScreen;
    // sf::Time mTime;
    // sf::Time timePerFrame;
};

#endif //INSTRUCTION_HPP