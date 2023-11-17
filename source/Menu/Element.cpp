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

void Pack::setCharacterSize(int size)
{
    text.setCharacterSize(size);
}

Link::Link(int x)
{
    s="D:/GitHub/CS202_CrossyRoad/media/images/characters/"+to_string(x)+".png";
}

string Link::getLink()
{
    return s;
}