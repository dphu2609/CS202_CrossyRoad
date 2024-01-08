#include <GUI/Button.hpp>

GUI::Button::Button() {}

GUI::Button::Button(
    const std::vector<sf::Texture> &textures, const sf::Vector2f &size, 
    const sf::Vector2f &position, std::function<void()> callback
) {}

GUI::Button::Button(
    std::function<void()> callback,
    const std::vector<sf::Texture> &textures, const sf::Vector2f &size, 
    const sf::Vector2f &position, const sf::Font &fonts, 
    const std::string &text, const std::vector<sf::Color> &textColor
) {}

GUI::Button::Button(
    std::function<void()> callback,
    const sf::Vector2f &size, const sf::Vector2f &position, 
    const sf::Font &fonts, const std::string &text,
    const std::vector<sf::Color> &textColor,
    const std::vector<sf::Color> &shapeColor,
    const std::vector<sf::Color> &shapeOutlineColor
) {
    mType = 2;
    mShape.setSize(size);
    mShape.setPosition(0, 0);
    mShape.setFillColor(shapeColor[0]);
    mShape.setOutlineThickness(2);
    mShape.setOutlineColor(shapeOutlineColor[0]);

    mText.setFont(fonts);
    mText.setString(text);
    mText.setCharacterSize(mShape.getSize().y / 2);
    mText.setFillColor(textColor[0]);
    mText.setPosition(
        size.x / 2 - mText.getGlobalBounds().width / 2, 
        size.y / 2 - mText.getGlobalBounds().height / 2
    );

    this->setPosition(position);

    mCallback = callback;
    mIsToggle = false;

    mTextColor = textColor;
    mShapeColor = shapeColor;
    mShapeOutlineColor = shapeOutlineColor;
}

void GUI::Button::handleEvent(sf::RenderWindow &window, sf::Event &event) {
    if (checkHover(window, event)) {
        if (!mIsHover) {
            mIsHover = true;
            if (mType == 1) {
                mText.setFillColor(mTextColor[1]);
            } else if (mType == 2) {
                mShape.setFillColor(mShapeColor[1]);
                mShape.setOutlineColor(mShapeOutlineColor[1]);
                mText.setFillColor(mTextColor[1]);
            
            }
        }
    }
    else if (mIsHover) {
        mIsHover = false;
        if (mType == 1) {
            mText.setFillColor(mTextColor[0]);
        } else if (mType == 2) {
            mShape.setFillColor(mShapeColor[0]);
            mShape.setOutlineColor(mShapeOutlineColor[0]);
            mText.setFillColor(mTextColor[0]);
        }
    }

    if (checkLeftClick(window, event)) {
        mCallback();
    }
}

bool GUI::Button::checkHover(sf::RenderWindow &window, sf::Event &event) {
    sf::Vector2f localPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    sf::FloatRect dataBounds;
    if (mType == 0 || mType == 1) {
        dataBounds = this->getTransform().transformRect(mSprite[0].getGlobalBounds());
    } else {
        dataBounds = this->getTransform().transformRect(mShape.getGlobalBounds());
    }
    sf::Vector2f startPoint(dataBounds.left, dataBounds.top);
    sf::Vector2f endPoint(dataBounds.left + dataBounds.width, dataBounds.top + dataBounds.height);
    return (localPosition.x >= startPoint.x && localPosition.x <= endPoint.x && localPosition.y >= startPoint.y && localPosition.y <= endPoint.y);
}

bool GUI::Button::checkLeftClick(sf::RenderWindow &window, sf::Event &event) {
    return (checkHover(window, event) && sf::Mouse::isButtonPressed(sf::Mouse::Left) && event.type == sf::Event::MouseButtonPressed);
}

void GUI::Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    if (mType == 0) {
        if (mIsHover) target.draw(mSprite[1], states);
        else target.draw(mSprite[0], states);
    } else if (mType == 1) {
        if (mIsHover) {
            target.draw(mSprite[1], states);
        } else {
            target.draw(mSprite[0], states);
        }
        target.draw(mText, states);
    } else {
        target.draw(mShape, states);
        target.draw(mText, states);
    }
}