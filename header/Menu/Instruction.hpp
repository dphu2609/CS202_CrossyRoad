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
    void setFirstPlayerTexture();
    void setSecondPlayerTexture();

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
    int layout;

    sf::Text firstIns;

    sf::Texture leftImageDark;
    sf::Sprite leftImageDarkSprite;
    sf::Texture rightImageDark;
    sf::Sprite rightImageDarkSprite;
    sf::Texture upImageDark;
    sf::Sprite upImageDarkSprite;

    sf::Texture up;
    sf::Sprite upSprite;
    sf::Texture down;
    sf::Sprite downSprite;
    sf::Texture left;
    sf::Sprite leftSprite;
    sf::Texture right;
    sf::Sprite rightSprite;

    sf::Text wText;
    sf::Texture w;
    sf::Sprite wSprite;
    // sf::RectangleShape wBound;
    sf::Text sText;
    sf::Texture s;
    sf::Sprite sSprite;
    // sf::RectangleShape sBound;
    sf::Text aText;
    sf::Texture a;
    sf::Sprite aSprite;
    // sf::RectangleShape aBound;
    sf::Text dText;
    sf::Texture d;
    sf::Sprite dSprite;
    // sf::RectangleShape dBound;

    int numImages;
    int currentImage;
    sf::Texture firstPlayer;
    vector<sf::Texture> firstPlayers;
    // sf::Sprite firstPlayerSprite;
    vector<sf::Sprite> firstPlayerSprites{16};
    sf::Texture secondPlayer;
    vector<sf::Texture> secondPlayers;
    // sf::Sprite secondPlayerSprite;
    vector<sf::Sprite> secondPlayerSprites{16};
    
    // sf::Texture backgroundLight; 
    // sf::Sprite backgroundLightSprite;
    // sf::Texture backgroundLight2; 
    // sf::Sprite backgroundLight2Sprite;

    // bool lightScreen;
    // sf::Time mTime;
    // sf::Time timePerFrame;
    sf::Time cTime; // character time
    sf::Time timePerCharacter;
};

#endif //INSTRUCTION_HPP