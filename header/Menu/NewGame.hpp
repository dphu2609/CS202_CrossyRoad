#ifndef NEWGAME_HPP
#define NEWGAME_HPP

#include <SFML/Graphics.hpp>
#include <menu/Element.hpp>
#include <Configs.hpp>
#include <SceneGraph/Character.hpp>
#include <vector>

using namespace std;

class NewGame
{
public:
    NewGame();
    
    // sf::Vector2f posBackGroundLight();
    // sf::Vector2f posBackGroundLight2();
    // void setPosBackgroundLight(sf::Vector2f pos);
    // void setPosBackgroundLight2(sf::Vector2f pos); 
    // bool stateBackgroundLight();  
    // void setBackground(bool isBackgoundLight);
    void setFirstPlayerTexture();
    void setSecondPlayerTexture();
    void changeToOnePlayer();
    void changeToTwoPlayer();  
    void setMode();

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
    sf::Vector2f modePos;

    sf::Text title;

    bool isReturnOn;
    sf::RectangleShape returnBound;
    sf::Texture returnImage;
    sf::Sprite returnImageSprite;
    sf::Texture returnImageDark;
    sf::Sprite returnImageDarkSprite;

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

    int numPlayer;
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
    
    sf::Text easy;
    sf::Text medium;
    sf::Text hard;
    sf::Text extreme;
    
    vector<Circle> circles;

    int modeSwitch;
    bool isFirstCircleOn;
    bool isSecondCircleOn;
    bool isThirdCircleOn;
    bool isFourthCircleOn;
    sf::Texture circleImage;
    sf::Texture circleImageDark;
    sf::CircleShape firstCircleBound;
    sf::Sprite firstCircle;
    sf::Sprite firstCircleDark;
    sf::CircleShape secondCircleBound;
    sf::Sprite secondCircle;
    sf::Sprite secondCircleDark;
    sf::CircleShape thirdCircleBound;
    sf::Sprite thirdCircle;
    sf::Sprite thirdCircleDark;
    sf::CircleShape fourthCircleBound;
    sf::Sprite fourthCircle;
    sf::Sprite fourthCircleDark;

    sf::RectangleShape playBound;
    sf::Text play;
    // sf::Texture backgroundLight; 
    // sf::Sprite backgroundLightSprite;
    // sf::Texture backgroundLight2; 
    // sf::Sprite backgroundLight2Sprite;

    // vector<Pack> packs;
    // bool lightScreen;
    // sf::Time mTime; // background time
    // sf::Time timePerFrame;
    sf::Time cTime; // character time
    sf::Time timePerCharacter;
};

#endif //NEWGAME_HPP