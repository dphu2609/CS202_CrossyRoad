#ifndef SETTING_HPP
#define SETTING_HPP

#include <SFML/Graphics.hpp>
#include <Menu/Element.hpp>
#include <vector>
#include <iostream>
using namespace std;

class Setting
{
public:
    Setting();

    // sf::Vector2f posBackGroundLight();
    // sf::Vector2f posBackGroundLight2();
    // void setPosBackgroundLight(sf::Vector2f pos);
    // void setPosBackgroundLight2(sf::Vector2f pos);
    // bool stateBackgroundLight();  
    // void setBackground(bool isBackgoundLight);   
    void setCurrent();
    void setOldCurrent();
    void setReset();

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
    unsigned int sizeCharacterDirection;

    sf::Text title;

    bool isReturnOn;
    sf::RectangleShape returnBound;
    sf::Texture returnImage;
    sf::Sprite returnImageSprite;
    sf::Texture returnImageDark;
    sf::Sprite returnImageDarkSprite;

    sf::Text reset;
    sf::RectangleShape resetBound;
    sf::Text save;
    sf::RectangleShape saveBound;

    sf::Text onep;
    sf::Text twop;

    sf::Texture up;
    sf::Sprite upSprite;
    sf::Texture down;
    sf::Sprite downSprite;
    sf::Texture left;
    sf::Sprite leftSprite;
    sf::Texture right;
    sf::Sprite rightSprite;

    bool isFirstCircleOn;
    bool isSecondCircleOn;
    sf::Texture circleImage;
    sf::Texture circleImageDark;
    sf::CircleShape firstCircleBound;
    sf::Sprite firstCircle;
    sf::Sprite firstCircleDark;
    sf::CircleShape secondCircleBound;
    sf::Sprite secondCircle;
    sf::Sprite secondCircleDark;

    sf::Text wText;
    sf::Texture w;
    sf::Sprite wSprite;
    sf::RectangleShape wBound;
    sf::Text sText;
    sf::Texture s;
    sf::Sprite sSprite;
    sf::RectangleShape sBound;
    sf::Text aText;
    sf::Texture a;
    sf::Sprite aSprite;
    sf::RectangleShape aBound;
    sf::Text dText;
    sf::Texture d;
    sf::Sprite dSprite;
    sf::RectangleShape dBound;
    
    int isChosen;
    int controlType;
    int oldControlType;
    char arrayDirection[4];
    char oldArrayDirection[4];

    sf::Text music;
    sf::RectangleShape musicBound;
    sf::RectangleShape musicBar;
    sf::Text sound;
    sf::RectangleShape soundBound;
    sf::RectangleShape soundBar;
    BarArray musicBarArray;
    BarArray soundBarArray;
    // Triangle musicIncrease;
    // Triangle musicDecrease;
    // Triangle soundIncrease;
    // Triangle soundDecrease;

    bool isMusicIncreaseOn;
    bool isMusicDecreaseOn;
    bool isSoundIncreaseOn;
    bool isSoundDecreaseOn;
    sf::Texture triangle;
    sf::Texture triangleDark;
    sf::RectangleShape musicIncreaseBound;
    sf::Sprite musicIncreaseTriangle;
    sf::Sprite musicIncreaseTriangleDark;
    sf::RectangleShape musicDecreaseBound;
    sf::Sprite musicDecreaseTriangle;
    sf::Sprite musicDecreaseTriangleDark;
    sf::RectangleShape soundIncreaseBound;
    sf::Sprite soundIncreaseTriangle;
    sf::Sprite soundIncreaseTriangleDark;
    sf::RectangleShape soundDecreaseBound;
    sf::Sprite soundDecreaseTriangle;
    sf::Sprite soundDecreaseTriangleDark;

    // sf::Texture backgroundLight; 
    // sf::Sprite backgroundLightSprite;
    // sf::Texture backgroundLight2; 
    // sf::Sprite backgroundLight2Sprite;

    // vector<Pack> packs;
    // bool lightScreen;
    // sf::Time mTime;
    // sf::Time timePerFrame;
};

#endif //SETTING_HPP