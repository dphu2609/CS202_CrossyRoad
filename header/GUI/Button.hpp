#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <GUI/Component.hpp>

namespace GUI {
    class Button;
};

class GUI::Button : public GUI::Component {
public:
    typedef std::shared_ptr<Button> Ptr;
    typedef std::function<void()> Callback;
public:
    Button();
    Button(
        const std::vector<sf::Texture> &textures, const sf::Vector2f &size, 
        const sf::Vector2f &position, std::function<void()> callback
    ); // use when background of button is image and have no text
    Button(
        std::function<void()> callback,
        const std::vector<sf::Texture> &textures, const sf::Vector2f &size, 
        const sf::Vector2f &position, const sf::Font &fonts, 
        const std::string &text, const std::vector<sf::Color> &textColor
    ); // use when background of button is image and have text
    Button(
        std::function<void()> callback,
        const sf::Vector2f &size, const sf::Vector2f &position, 
        const sf::Font &fonts, const std::string &text,
        const std::vector<sf::Color> &textColor,
        const std::vector<sf::Color> &shapeColor,
        const std::vector<sf::Color> &shapeOutlineColor
    ); // use when background of button is a rectangle shape in SFML (not image) and have text
private:
    virtual void handleEvent(sf::RenderWindow &window, sf::Event &event);
    virtual void update(sf::Time dt) {}
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
private:
    bool mIsHover = false;
    bool checkHover(sf::RenderWindow &window, sf::Event &event);
    bool checkLeftClick(sf::RenderWindow &window, sf::Event &event);
private:
    int mType; // 0: image button, 1: image button with text, 2: button with text
    Callback mCallback; 
    sf::RectangleShape mShape; // use when button is not image button (which has image and text)
    std::vector<sf::Sprite> mSprite;
    sf::Text mText;
    std::vector<sf::Color> mTextColor;
    std::vector<sf::Color> mShapeColor;
    std::vector<sf::Color> mShapeOutlineColor;
    bool mIsToggle;
};

#endif // BUTTON_HPP