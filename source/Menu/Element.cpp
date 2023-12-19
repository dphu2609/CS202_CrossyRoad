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
    circleImage.loadFromFile("media/images/menu/Circle1.png");
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
    circleImage.loadFromFile("media/images/menu/Circle2.png");
    isCircleLight=false;
}

void Circle::changeToLight()
{
    circleImage.loadFromFile("media/images/menu/Circle1.png");
    isCircleLight=true;
}

void Circle::draw(sf::RenderWindow& mWindow)
{
    mWindow.draw(circle);
    mWindow.draw(circleImageSprite);
}

Triangle::Triangle()
{
    triangle.loadFromFile("media/images/menu/Backward1.png");
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
    triangle.loadFromFile("media/images/menu/Backward2.png");
}
void Triangle::changeToLight()
{
    triangle.loadFromFile("media/images/menu/Backward1.png");
}

void Triangle::draw(sf::RenderWindow& mWindow)
{
    mWindow.draw(bound);
    mWindow.draw(triangleSprite);
}

HalfCircle::HalfCircle()
{
    halfcircle.loadFromFile("media/images/menu/Increase2.png");
    halfcircleSprite.setTexture(halfcircle);
    sf::FloatRect size=halfcircleSprite.getGlobalBounds();
    halfcircleSprite.setOrigin(size.width/2,size.height/2);
    halfcircleSprite.setScale(220.f/size.width,220.f/size.height);

    bound.setSize(sf::Vector2f(70.f,70.f));
    bound.setFillColor(sf::Color::Transparent);
    size=bound.getLocalBounds();
    bound.setOrigin(size.width/2,size.height/2);
}

void HalfCircle::setPosition(float x,float y)
{
    bound.setPosition(x,y);
    halfcircleSprite.setPosition(x,y);
}

void HalfCircle::rotate(float x)
{
    halfcircleSprite.rotate(x);
}

sf::FloatRect HalfCircle::getGlobalBounds()
{
    return bound.getGlobalBounds();
}

void HalfCircle::changeToDark()
{
    halfcircle.loadFromFile("media/images/menu/Increase2.png");
}
void HalfCircle::changeToLight()
{
    halfcircle.loadFromFile("media/images/menu/Increase1.png");
}

void HalfCircle::draw(sf::RenderWindow& mWindow)
{
    mWindow.draw(bound);
    mWindow.draw(halfcircleSprite);
}

BarArray::BarArray()
{
    size=12;
    barArray.resize(size);
    for(int i=0;i<6;i++)
    {
        barArray[i].setSize(sf::Vector2f(45.f,70.f));
        barArray[i].setFillColor(sf::Color::Magenta);
    }
    for(int i=6;i<12;i++)
    {
        barArray[i].setSize(sf::Vector2f(45.f,70.f));
        barArray[i].setFillColor(sf::Color::Magenta);
    }
    current=6;
    oldcurrent=6;
}

void BarArray::setPosition(float x,float y)
{
    for(int i=0;i<size;i++)
    {
        barArray[i].setPosition(x+i*50,y);
    }
}

void BarArray::decreaseByOne()
{
    if(current>0)
    --current;
}

void BarArray::increaseByOne()
{
    if(current<12)
    ++current;
}

void BarArray::reset()
{
    current=6;
    Statistic::MUSIC_SOUND_VOLUME=50.f;
    Statistic::ENVIROMENT_SOUND_VOLUME=50.f;
}

void BarArray::setOldCurrent()
{
    oldcurrent=current;
}

void BarArray::setCurrent()
{
    current=oldcurrent;
    
}

void BarArray::setMusic()
{
    Statistic::MUSIC_SOUND_VOLUME=Statistic::MUSIC_SOUND_VOLUME*current/12;
}

void BarArray::setSound()
{
    Statistic::ENVIROMENT_SOUND_VOLUME=Statistic::ENVIROMENT_SOUND_VOLUME*current/12;
}

void BarArray::draw(sf::RenderWindow& mWindow)
{
    for(int i=0;i<current;i++)
    {
        mWindow.draw(barArray[i]);
    }
}

Link::Link(int x)
{
    s="media/images/characters/"+to_string(x)+".png";
}

string Link::getLink()
{
    return s;
}