#include <GUI/Button.hpp>

GUI::Button::Button() {}

GUI::Button::Button(
    const std::vector<sf::Texture> &textures, const sf::Vector2f &size, 
    const sf::Vector2f &position, std::function<void()> callback
) {}

GUI::Button::Button(
    const std::vector<sf::Texture> &textures, const sf::Vector2f &size, 
    const sf::Vector2f &position, const sf::Font &fonts, 
    const std::string &text, const std::vector<sf::Color> &textColor, 
    std::function<void()> callback
) {}

GUI::Button::Button(
    const sf::Vector2f &size, const sf::Vector2f &position, 
    const sf::Font &fonts, const std::string &text,
    std::function<void()> callback
) {}

void GUI::Button::handleEvent(sf::Event &event) {}

void GUI::Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {}