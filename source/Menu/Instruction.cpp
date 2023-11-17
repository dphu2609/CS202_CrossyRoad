#include <Menu/Instruction.hpp>

Instruction::Instruction()
{
    colorBound=sf::Color::Transparent;
    sizeBound=sf::Vector2f(100.f,100.f);
    sizeTheme=sf::Vector2f(1920.f,1080.f);
    sizeCharacter=100;
    sf::FloatRect size;

    background.loadFromFile("D:/GitHub/CS202_CrossyRoad/media/images/menu/background_glacial_mountains.png");
    backgroundSprite.setTexture(background);
    sf::FloatRect sizeThemeOrigin=backgroundSprite.getGlobalBounds();
    backgroundSprite.setScale(sf::Vector2f(sizeTheme.x/sizeThemeOrigin.width,sizeTheme.y/sizeThemeOrigin.height));

    _font.loadFromFile("D:/GitHub/CS202_CrossyRoad/media/font/Alinore.otf");
    colorCharacter=sf::Color::White;

    title.setString("Crossy Road");
    title.setFont(_font);
    title.setCharacterSize(200);
    title.setFillColor(sf::Color::Green);
    size=title.getGlobalBounds();
    title.setOrigin(size.width/2,size.height/2);
    title.setPosition(sf::Vector2f(960.f,50.f));
    title.setScale(1.75,0.8);

    returnBound.setSize(sizeBound);
    returnBound.setFillColor(colorBound);
    returnBound.setPosition(50.f,50.f);

    returnImage.loadFromFile("D:/GitHub/CS202_CrossyRoad/media/images/menu/Back1.png");
    returnImageSprite.setTexture(returnImage);
    size=returnImageSprite.getGlobalBounds();
    returnImageSprite.setOrigin(size.width/2,size.height/2);
    returnImageSprite.setPosition(sf::Vector2f(100.f,100.f));
    returnImageSprite.setScale(300.f/size.width,300.f/size.height);

    bound.setSize(sf::Vector2f(1780.f,780.f));
    bound.setFillColor(colorBound);
    bound.setOutlineThickness(5.0);
    bound.setOutlineColor(sf::Color::Green);
    bound.setPosition(70.f,200.f);

    part.setString("1/4");
    part.setFont(_font);
    part.setCharacterSize(sizeCharacter);
    part.setFillColor(colorCharacter);
    size=part.getGlobalBounds();
    part.setOrigin(size.width/2,size.height/2);
    part.setPosition(960.f,880.f);
}

int Instruction::processEvent(sf::Event& event,sf::RenderWindow& mWindow)
{
    sf::Vector2i mousePosition=sf::Mouse::getPosition(mWindow);
    sf::FloatRect recBound=returnBound.getGlobalBounds();
    bool isMouseOn=recBound.contains(static_cast<float>(mousePosition.x),static_cast<float>(mousePosition.y));
    if(isMouseOn)
    {
        returnImage.loadFromFile("D:/GitHub/CS202_CrossyRoad/media/images/menu/Back2.png");
        returnImageSprite.setTexture(returnImage);
        if(event.type==sf::Event::MouseButtonPressed&&event.mouseButton.button==sf::Mouse::Left)
        {
            return 0;
        }
    }
    else
    {
        returnImage.loadFromFile("D:/GitHub/CS202_CrossyRoad/media/images/menu/Back1.png");
        returnImageSprite.setTexture(returnImage);
    }
    return 4;
}

void Instruction::draw(sf::RenderWindow& mWindow)
{
    mWindow.draw(backgroundSprite);
    mWindow.draw(title);
    mWindow.draw(bound);
    mWindow.draw(part);
    mWindow.draw(returnBound);
    mWindow.draw(returnImageSprite);
}