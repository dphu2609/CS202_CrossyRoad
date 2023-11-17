#ifndef SETTING_HPP
#define SETTING_HPP

#include <SFML/Graphics.hpp>
#include <Menu/Element.hpp>
#include <vector>

using namespace std;

class Setting
{
public:
    Setting();
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
    sf::Text reset;
    sf::RectangleShape resetBound;
    sf::Text save;
    sf::RectangleShape saveBound;
    sf::Text onep;
    sf::Text twop;
    sf::Text music;
    sf::RectangleShape musicBound;
    sf::RectangleShape musicBar;
    sf::Text sound;
    sf::RectangleShape soundBound;
    sf::RectangleShape soundBar;
    sf::Texture backgroundLight; 
    sf::Sprite backgroundLightSprite;
    sf::Texture backgroundLight2; 
    sf::Sprite backgroundLight2Sprite;

    vector<Pack> packs;
    bool lightScreen;
    sf::Time mTime;
    sf::Time timePerFrame;
};

#endif //SETTING_HPP