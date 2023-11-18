#include <Menu/Element.hpp>

Pack::Pack()
{

}

Pack::Pack(sf::RectangleShape& bound,sf::Text& text)
{
    this->bound=bound;
    this->text=text;
}

sf::FloatRect Pack::getGlobalBounds()
{
    return bound.getGlobalBounds();
}

Circle::Circle()
{
    isCircleLight=true;
    circleImage.loadFromFile("D:/GitHub/CS202_CrossyRoad/media/images/menu/Circle1.png");
    circleImageSprite.setTexture(circleImage);
    sf::FloatRect size=circleImageSprite.getGlobalBounds();
    circleImageSprite.setOrigin(size.width/2,size.height/2);
    circleImageSprite.setScale(0.3,0.3);

    circle.setRadius(20.f);
    circle.setFillColor(sf::Color::Green);
    size=circle.getGlobalBounds();
    circle.setOrigin(size.width/2,size.height/2);
}

sf::FloatRect Circle::getGlobalBounds()
{
    return circle.getGlobalBounds();
}

void Circle::setPosition(float x,float y)
{
    circleImageSprite.setPosition(x,y+50);
    circle.setPosition(x,y+50);
}

void Circle::changeToDark()
{
    circleImage.loadFromFile("D:/GitHub/CS202_CrossyRoad/media/images/menu/Circle2.png");
    isCircleLight=false;
}

void Circle::changeToLight()
{
    circleImage.loadFromFile("D:/GitHub/CS202_CrossyRoad/media/images/menu/Circle1.png");
    isCircleLight=true;
}

void Circle::draw(sf::RenderWindow& mWindow)
{
    mWindow.draw(circle);
    mWindow.draw(circleImageSprite);
}

Link::Link(int x)
{
    s="D:/GitHub/CS202_CrossyRoad/media/images/characters/"+to_string(x)+".png";
}

string Link::getLink()
{
    return s;
}