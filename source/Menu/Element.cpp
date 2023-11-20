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
    circleImageSprite.setScale(120.f/size.width,120.f/size.height);

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
    circleImageSprite.setPosition(x,y);
    circle.setPosition(x,y);
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

Triangle::Triangle()
{
    triangle.loadFromFile("D:/GitHub/CS202_CrossyRoad/media/images/menu/Backward1.png");
    triangleSprite.setTexture(triangle);
    sf::FloatRect size=triangleSprite.getGlobalBounds();
    triangleSprite.setOrigin(size.width/2,size.height/2);
    triangleSprite.setScale(220.f/size.width,220.f/size.height);

    bound.setSize(sf::Vector2f(70.f,70.f));
    bound.setFillColor(sf::Color::Transparent);
    size=bound.getLocalBounds();
    bound.setOrigin(size.width/2,size.height/2);
}

void Triangle::setPosition(float x,float y)
{
    bound.setPosition(x,y);
    triangleSprite.setPosition(x,y);
}

void Triangle::rotate(float x)
{
    triangleSprite.rotate(x);
}

sf::FloatRect Triangle::getGlobalBounds()
{
    return bound.getGlobalBounds();
}

void Triangle::changeToDark()
{
    triangle.loadFromFile("D:/GitHub/CS202_CrossyRoad/media/images/menu/Backward2.png");
}
void Triangle::changeToLight()
{
    triangle.loadFromFile("D:/GitHub/CS202_CrossyRoad/media/images/menu/Backward1.png");
}

void Triangle::draw(sf::RenderWindow& mWindow)
{
    mWindow.draw(bound);
    mWindow.draw(triangleSprite);
}

Link::Link(int x)
{
    s="D:/GitHub/CS202_CrossyRoad/media/images/characters/"+to_string(x)+".png";
}

string Link::getLink()
{
    return s;
}