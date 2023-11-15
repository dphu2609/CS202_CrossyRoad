#include <Menu/Element.hpp>

Pack::Pack(sf::RectangleShape& bound,sf::Text& text)
{
    this->bound=bound;
    this->text=text;
}

sf::FloatRect Pack::getGlobalBounds()
{
    return bound.getGlobalBounds();
}