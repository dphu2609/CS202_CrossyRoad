#include <Menu/Instruction.hpp>
#include <iostream>
using namespace std;
Instruction::Instruction()
{
    colorBound=sf::Color::Transparent;
    sizeBound=sf::Vector2f(100.f,100.f);
    // sizeTheme=sf::Vector2f(1920.f,1080.f);
    sizeCharacter=100;
    sf::FloatRect size;

    // mTime=sf::Time::Zero;
    // timePerFrame=sf::seconds(60.f/60.f);

    // lightScreen=true;

    // backgroundLight.loadFromFile("media/images/menu/background_glacial_mountains_lightened.png");
    // backgroundLightSprite.setTexture(backgroundLight);
    // sf::FloatRect sizeThemeOrigin=backgroundLightSprite.getGlobalBounds();
    // backgroundLightSprite.setScale(sf::Vector2f(sizeTheme.x/sizeThemeOrigin.width,sizeTheme.y/sizeThemeOrigin.height));

    // backgroundLight2.loadFromFile("media/images/menu/background_glacial_mountains_lightened.png");
    // backgroundLight2Sprite.setTexture(backgroundLight2);
    // sizeThemeOrigin=backgroundLight2Sprite.getGlobalBounds();
    // backgroundLight2Sprite.setScale(sf::Vector2f(sizeTheme.x/sizeThemeOrigin.width,sizeTheme.y/sizeThemeOrigin.height));
    // backgroundLight2Sprite.setPosition(1920.f,0.f);

    _font.loadFromFile("media/font/Alinore.otf");
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

    returnImage.loadFromFile("media/images/menu/Back1.png");
    returnImageSprite.setTexture(returnImage);
    size=returnImageSprite.getGlobalBounds();
    returnImageSprite.setOrigin(size.width/2,size.height/2);
    returnImageSprite.setPosition(sf::Vector2f(100.f,100.f));
    returnImageSprite.setScale(300.f/size.width,300.f/size.height);

    returnImageDark.loadFromFile("media/images/menu/Back2.png");
    returnImageDarkSprite.setTexture(returnImageDark);
    size=returnImageDarkSprite.getGlobalBounds();
    returnImageDarkSprite.setOrigin(size.width/2,size.height/2);
    returnImageDarkSprite.setPosition(sf::Vector2f(100.f,100.f));
    returnImageDarkSprite.setScale(300.f/size.width,300.f/size.height);

    isReturnOn=false;

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

    // left.setPosition(860.f,915.f);
    // right.setPosition(1070.f,915.f);
    // right.rotate(180.f);

    triangle.loadFromFile("media/images/menu/Backward1.png");
    triangleDark.loadFromFile("media/images/menu/Backward2.png");

    oneIncreaseBound.setSize(sf::Vector2f(70.f,70.f));
    oneIncreaseBound.setFillColor(sf::Color::Transparent);
    size=oneIncreaseBound.getLocalBounds();
    oneIncreaseBound.setOrigin(size.width/2,size.height/2); 
    oneIncreaseBound.setPosition(1070.f,915.f); //
    oneIncreaseTriangle.setTexture(triangle);
    size=oneIncreaseTriangle.getGlobalBounds();
    oneIncreaseTriangle.setOrigin(size.width/2,size.height/2);
    oneIncreaseTriangle.setScale(220.f/size.width,220.f/size.height);
    oneIncreaseTriangle.setPosition(1070.f,915.f);
    oneIncreaseTriangle.rotate(180.f); //
    oneIncreaseTriangleDark.setTexture(triangleDark);
    size=oneIncreaseTriangleDark.getGlobalBounds();
    oneIncreaseTriangleDark.setOrigin(size.width/2,size.height/2);
    oneIncreaseTriangleDark.setScale(220.f/size.width,220.f/size.height);
    oneIncreaseTriangleDark.setPosition(1070.f,915.f);
    oneIncreaseTriangleDark.rotate(180.f); //

    oneDecreaseBound.setSize(sf::Vector2f(70.f,70.f));
    oneDecreaseBound.setFillColor(sf::Color::Transparent);
    size=oneDecreaseBound.getLocalBounds();
    oneDecreaseBound.setOrigin(size.width/2,size.height/2); 
    oneDecreaseBound.setPosition(860.f,915.f); //
    oneDecreaseTriangle.setTexture(triangle);
    size=oneDecreaseTriangle.getGlobalBounds();
    oneDecreaseTriangle.setOrigin(size.width/2,size.height/2);
    oneDecreaseTriangle.setScale(220.f/size.width,220.f/size.height);
    oneDecreaseTriangle.setPosition(860.f,915.f); //
    oneDecreaseTriangleDark.setTexture(triangleDark);
    size=oneDecreaseTriangleDark.getGlobalBounds();
    oneDecreaseTriangleDark.setOrigin(size.width/2,size.height/2);
    oneDecreaseTriangleDark.setScale(220.f/size.width,220.f/size.height);
    oneDecreaseTriangleDark.setPosition(860.f,915.f);

    isOneIncreaseOn=false;
    isOneDecreaseOn=false;
}

// sf::Vector2f Instruction::posBackGroundLight()
// {
//     return backgroundLightSprite.getPosition();
// }

// sf::Vector2f Instruction::posBackGroundLight2()
// {
//     return backgroundLight2Sprite.getPosition();
// }

// void Instruction::setPosBackgroundLight(sf::Vector2f pos)
// {
//     backgroundLightSprite.setPosition(pos);
// }

// void Instruction::setPosBackgroundLight2(sf::Vector2f pos)
// {
//     backgroundLight2Sprite.setPosition(pos);
// } 

// bool Instruction::stateBackgroundLight()
// {
//     return lightScreen;
// }  

// void Instruction::setBackground(bool isBackgoundLight)
// {
//     if (isBackgoundLight)
//     {
//         backgroundLight.loadFromFile("media/images/menu/background_glacial_mountains_lightened.png");
//         backgroundLight2.loadFromFile("media/images/menu/background_glacial_mountains_lightened.png");
//     }
//     else
//     {
//         backgroundLight.loadFromFile("media/images/menu/background_glacial_mountains.png");
//         backgroundLight2.loadFromFile("media/images/menu/background_glacial_mountains.png");
//     }
// } 

void Instruction::previous()
{
    string tmp=part.getString();
    int current=tmp[0]-'0';
    tmp.erase(tmp.begin());
    if(current>1) --current;
    tmp=to_string(current)+tmp;
    part.setString(tmp);
}

void Instruction::next()
{
    string tmp=part.getString();
    int current=tmp[0]-'0';
    tmp.erase(tmp.begin());
    if(current<4) ++current;
    tmp=to_string(current)+tmp;
    part.setString(tmp);
}   

int Instruction::processEvent(sf::Event& event,sf::RenderWindow& mWindow)
{
    sf::Vector2f mousePosition = mWindow.mapPixelToCoords(sf::Mouse::getPosition(mWindow));
    sf::FloatRect recBound = returnBound.getGlobalBounds();
    bool isMouseOn = recBound.contains(mousePosition);
    if (isMouseOn)
    {
        isReturnOn = true;
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            isReturnOn = false;
            return 0;
        }
        return 4;
    }
    else
    {
        isReturnOn = false;
    }

    recBound=oneDecreaseBound.getGlobalBounds();
    isMouseOn=recBound.contains(mousePosition);
    if(isMouseOn)
    {
        isOneDecreaseOn=true;
        if(event.type==sf::Event::MouseButtonPressed&&event.mouseButton.button==sf::Mouse::Left)
        {
            previous();
        }
        return 4;
    }
    else
    {
        isOneDecreaseOn=false;
    }

    recBound=oneIncreaseBound.getGlobalBounds();
    isMouseOn=recBound.contains(static_cast<float>(mousePosition.x),static_cast<float>(mousePosition.y));
    if(isMouseOn)
    {
        isOneIncreaseOn=true;
        if(event.type==sf::Event::MouseButtonPressed&&event.mouseButton.button==sf::Mouse::Left)
        {
            next();
        }
        return 4;
    }
    else
    {
        isOneIncreaseOn=false;
    }

    return 4;
}

void Instruction::update(sf::Time dt)
{
    // mTime+=dt;
    // if(mTime>timePerFrame){
    //     if (lightScreen)
    //     {
    //         backgroundLight.loadFromFile("media/images/menu/background_glacial_mountains.png");
    //         backgroundLight2.loadFromFile("media/images/menu/background_glacial_mountains.png");
    //     }
    //     else
    //     {
    //         backgroundLight.loadFromFile("media/images/menu/background_glacial_mountains_lightened.png");
    //         backgroundLight2.loadFromFile("media/images/menu/background_glacial_mountains_lightened.png");
    //     }
    //     lightScreen = !lightScreen;
    //     mTime=sf::Time::Zero;
    // }
    // backgroundLightSprite.setPosition(backgroundLightSprite.getPosition().x-0.5,0.f);
    // backgroundLight2Sprite.setPosition(backgroundLight2Sprite.getPosition().x-0.5,0.f);
    // if(backgroundLight2Sprite.getPosition().x==0.f)
    // {
    //     backgroundLightSprite.setPosition(0.f,0.f);
    //     backgroundLight2Sprite.setPosition(1920.f,0.f);
    // }
}

void Instruction::draw(sf::RenderWindow& mWindow)
{
    // mWindow.draw(backgroundLightSprite);
    // mWindow.draw(backgroundLight2Sprite);
    mWindow.draw(title);
    mWindow.draw(bound);
    mWindow.draw(part);
    
    mWindow.draw(oneIncreaseBound);
    if(isOneIncreaseOn)
    {
        mWindow.draw(oneIncreaseTriangleDark);
    }
    else mWindow.draw(oneIncreaseTriangle);
    mWindow.draw(oneDecreaseBound);
    if(isOneDecreaseOn)
    {
        mWindow.draw(oneDecreaseTriangleDark);
    }
    else mWindow.draw(oneDecreaseTriangle);

    mWindow.draw(returnBound);
    if(isReturnOn)
    {
        mWindow.draw(returnImageDarkSprite);
    }
    else
    {
        mWindow.draw(returnImageSprite);
    }
}