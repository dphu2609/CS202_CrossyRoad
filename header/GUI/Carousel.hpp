#ifndef CAROUSEL_HPP
#define CAROUSEL_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <GUI/Component.hpp>
#include <GUI/Button.hpp>

class GUI::Carousel : public GUI::Component {
public:
    typedef std::shared_ptr<Carousel> Ptr;
public:
    Carousel(
        const std::vector<sf::Texture> &textures, const sf::Vector2f &size, const sf::Vector2f &position,
        const sf::Texture &fowardButtonTexture, const sf::Texture &backwardButtonTexture
    );
    Carousel(
        const std::vector<sf::Texture> &textures, const sf::Vector2f &size, 
        const sf::Vector2f &position, const sf::Font &font, 
        const std::vector<std::string>> &text, const std::vector<sf::Color> &textColor,
        const sf::Texture &fowardButtonTexture, const sf::Texture &backwardButtonTexture
    );
    Carousel(
        const sf::Vector2f &size, const sf::Vector2f &position, 
        const std::vector<sf::Color> &shapeColor,const sf::Font &font, 
        const std::vector<std::string>> &text, const std::vector<sf::Color> &textColor,
        const sf::Texture &fowardButtonTexture, const sf::Texture &backwardButtonTexture
    );
private:
    virtual void handleEvent(sf::Event &event);
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
private:
    bool mIsImageCarousel = false;
    std::vector<sf::RectangleShape> mShape;
    std::vector<sf::Sprite> mSprite;
    sf::Text mText;
    std::vector<sf::Color> mTextColor;
    std::vector<sf::Color> mShapeColor;
    GUI::Button mFowardButton;
    GUI::Button mBackwardButton;
    int mIndex;
};
