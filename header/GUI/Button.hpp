#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <GUI/Component.hpp>

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
        const std::vector<sf::Texture> &textures, const sf::Vector2f &size, 
        const sf::Vector2f &position, const sf::Font &fonts, 
        const std::string &text, const std::vector<sf::Color> &textColor, std::function<void()> callback
    ); // use when background of button is image and have text
    Button(
        const sf::Vector2f &size, const sf::Vector2f &position, 
        const sf::Font &fonts, const std::string &text,
        std::function<void()> callback
    ); // use when background of button is a rectangle shape in SFML (not image) and have text
private:
    virtual void handleEvent(sf::Event &event);
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
private:
    bool mIsImageButton = false; // use when button is image button (which only has image)
private:
    Callback mCallback;
    sf::RectangleShape mShape; // use when button is not image button (which has image and text)
    sf::Sprite mSprite;
    sf::Text mText;
    std::vector<sf::Color> mTextColor;
    std::vector<sf::Color> mShapeColor;
    bool mIsToggle;
};

#endif // BUTTON_HPP