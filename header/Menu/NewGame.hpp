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
    
    sf::Vector2f posBackGroundLight();
    sf::Vector2f posBackGroundLight2();
    void setPosBackgroundLight(sf::Vector2f pos);
    void setPosBackgroundLight2(sf::Vector2f pos); 
    bool stateBackgroundLight();  
    void setBackground(bool isBackgoundLight);
    void setFirstPlayerTexture();
    void setSecondPlayerTexture();  

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

    int numImages;
    int currentImage;
    sf::Texture firstPlayer;
    vector<sf::Texture> firstPlayers;
    sf::Sprite firstPlayerSprite;
    sf::Texture secondPlayer;
    vector<sf::Texture> secondPlayers;
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
    sf::Texture backgroundLight; 
    sf::Sprite backgroundLightSprite;
    sf::Texture backgroundLight2; 
    sf::Sprite backgroundLight2Sprite;

    vector<Pack> packs;
    bool lightScreen;
    sf::Time mTime; // background time
    sf::Time timePerFrame;
    sf::Time cTime; // character time
    sf::Time timePerCharacter;
};

#endif //NEWGAME_HPP