#include <Menu/Instruction.hpp>
#include <iostream>
using namespace std;
Instruction::Instruction()
{
    colorBound=sf::Color::Transparent;
    sizeBound=sf::Vector2f(100.f,100.f);
    // sizeTheme=sf::Vector2f(1920.f,1080.f);
    sizeCharacter=100;
    sizeCharacterDirection=90;
    sf::FloatRect size;

    numImages=16;
    currentImage=0;
    layout=1;

    cTime=sf::Time::Zero;
    timePerCharacter=sf::seconds(40.f/60.f);

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

    firstIns.setString("Use keyboards to move");
    firstIns.setFont(_font);
    firstIns.setCharacterSize(50);
    firstIns.setFillColor(colorCharacter);
    size=firstIns.getGlobalBounds();
    firstIns.setOrigin(size.width/2,size.height/2);
    firstIns.setPosition(960.f,280.f);

    leftImageDark.loadFromFile("media/images/menu/leftIns.png");
    leftImageDarkSprite.setTexture(leftImageDark);
    size=leftImageDarkSprite.getGlobalBounds();
    leftImageDarkSprite.setOrigin(size.width/2,size.height/2);
    leftImageDarkSprite.setPosition(sf::Vector2f(740.f,770.f));
    leftImageDarkSprite.setScale(500.f/size.width,500.f/size.height);

    rightImageDark.loadFromFile("media/images/menu/leftIns.png");
    rightImageDarkSprite.setTexture(rightImageDark);
    size=rightImageDarkSprite.getGlobalBounds();
    rightImageDarkSprite.setOrigin(size.width/2,size.height/2);
    rightImageDarkSprite.setPosition(sf::Vector2f(1180.f,760.f));
    rightImageDarkSprite.setScale(500.f/size.width,500.f/size.height);
    rightImageDarkSprite.rotate(180);

    upImageDark.loadFromFile("media/images/menu/upIns.png");
    upImageDarkSprite.setTexture(upImageDark);
    size=upImageDarkSprite.getGlobalBounds();
    upImageDarkSprite.setOrigin(size.width/2,size.height/2);
    upImageDarkSprite.setPosition(sf::Vector2f(960.f,520.f));
    upImageDarkSprite.setScale(500.f/size.width,500.f/size.height);

    up.loadFromFile("media/images/menu/up.png");
    upSprite.setTexture(up);
    size=upSprite.getGlobalBounds();
    upSprite.setOrigin(size.width/2,size.height/2);
    upSprite.setScale(200.f/size.width,200.f/size.height);
    upSprite.setPosition(sf::Vector2f(600.f,300.f));

    down.loadFromFile("media/images/menu/down.png");
    downSprite.setTexture(down);
    size=downSprite.getGlobalBounds();
    downSprite.setOrigin(size.width/2,size.height/2);
    downSprite.setScale(200.f/size.width,200.f/size.height);
    downSprite.setPosition(sf::Vector2f(600.f,410.f));

    right.loadFromFile("media/images/menu/right.png");
    rightSprite.setTexture(right);
    size=rightSprite.getGlobalBounds();
    rightSprite.setOrigin(size.width/2,size.height/2);
    rightSprite.setScale(200.f/size.width,200.f/size.height);
    rightSprite.setPosition(sf::Vector2f(710.f,410.f));

    left.loadFromFile("media/images/menu/left.png");
    leftSprite.setTexture(left);
    size=leftSprite.getGlobalBounds();
    leftSprite.setOrigin(size.width/2,size.height/2);
    leftSprite.setScale(200.f/size.width,200.f/size.height);
    leftSprite.setPosition(sf::Vector2f(490.f,410.f));

    w.loadFromFile("media/images/menu/letterControl.png");
    wSprite.setTexture(w);
    size=wSprite.getGlobalBounds();
    wSprite.setOrigin(size.width/2,size.height/2);
    wSprite.setScale(200.f/size.width,200.f/size.height);
    wSprite.setPosition(sf::Vector2f(1320.f,300.f));

    // wBound.setSize(sf::Vector2f(sizeBound.x,sizeBound.y));
    // wBound.setFillColor(colorBound);
    // wBound.setPosition(1270.f,250.f);

    s.loadFromFile("media/images/menu/letterControl.png");
    sSprite.setTexture(s);
    size=sSprite.getGlobalBounds();
    sSprite.setOrigin(size.width/2,size.height/2);
    sSprite.setScale(200.f/size.width,200.f/size.height);
    sSprite.setPosition(sf::Vector2f(1320.f,410.f));

    // sBound.setSize(sf::Vector2f(sizeBound.x,sizeBound.y));
    // sBound.setFillColor(colorBound);
    // sBound.setPosition(1270.f,360.f);

    a.loadFromFile("media/images/menu/letterControl.png");
    aSprite.setTexture(a);
    size=aSprite.getGlobalBounds();
    aSprite.setOrigin(size.width/2,size.height/2);
    aSprite.setScale(200.f/size.width,200.f/size.height);
    aSprite.setPosition(sf::Vector2f(1210.f,410.f));

    // aBound.setSize(sf::Vector2f(sizeBound.x,sizeBound.y));
    // aBound.setFillColor(colorBound);
    // aBound.setPosition(1160.f,360.f);

    d.loadFromFile("media/images/menu/letterControl.png");
    dSprite.setTexture(d);
    size=dSprite.getGlobalBounds();
    dSprite.setOrigin(size.width/2,size.height/2);
    dSprite.setScale(200.f/size.width,200.f/size.height);
    dSprite.setPosition(sf::Vector2f(1430.f,410.f));

    // dBound.setSize(sf::Vector2f(sizeBound.x,sizeBound.y));
    // dBound.setFillColor(colorBound);
    // dBound.setPosition(1380.f,360.f);

    wText.setString("W");
    wText.setFont(_font);
    wText.setCharacterSize(sizeCharacterDirection);
    wText.setFillColor(colorCharacter);
    size=wText.getGlobalBounds();
    wText.setOrigin(size.width/2,size.height/2);
    wText.setPosition(sf::Vector2f(1318.f,265.f));
    //wText.setScale(1.75,0.8);

    sText.setString("S");
    sText.setFont(_font);
    sText.setCharacterSize(sizeCharacterDirection);
    sText.setFillColor(colorCharacter);
    size=sText.getGlobalBounds();
    sText.setOrigin(size.width/2,size.height/2);
    sText.setPosition(sf::Vector2f(1318.f,375.f));
    //wText.setScale(1.75,0.8);

    aText.setString("A");
    aText.setFont(_font);
    aText.setCharacterSize(sizeCharacterDirection);
    aText.setFillColor(colorCharacter);
    size=aText.getGlobalBounds();
    aText.setOrigin(size.width/2,size.height/2);
    aText.setPosition(sf::Vector2f(1208.f,375.f));

    dText.setString("D");
    dText.setFont(_font);
    dText.setCharacterSize(sizeCharacterDirection);
    dText.setFillColor(colorCharacter);
    size=dText.getGlobalBounds();
    dText.setOrigin(size.width/2,size.height/2);
    dText.setPosition(sf::Vector2f(1428.f,375.f));
    //wText.setScale(1.75,0.8);

    setFirstPlayerTexture();
    //firstPlayer.loadFromFile("media/images/characters/1.png");
    for (int i = 0; i < numImages; i++)
    {
        firstPlayerSprites[i].setTexture(firstPlayers[i]);
        size = firstPlayerSprites[i].getGlobalBounds();
        firstPlayerSprites[i].setOrigin(size.width / 2, size.height / 2);
        firstPlayerSprites[i].setPosition(sf::Vector2f(960, 680.f));
        firstPlayerSprites[i].setScale(0.6, 0.6);
    }

    setSecondPlayerTexture();
    //secondPlayer.loadFromFile("media/images/characters/1.png");
    for (int i = 0; i < numImages; i++)
    {
        secondPlayerSprites[i].setTexture(secondPlayers[i]);
        size = secondPlayerSprites[i].getGlobalBounds();
        secondPlayerSprites[i].setOrigin(size.width / 2, size.height / 2);
        secondPlayerSprites[i].setPosition(sf::Vector2f(1062.5, 550.f));
        secondPlayerSprites[i].setScale(0.6, 0.6);
    }
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
    if(current>1) {--current;layout=current;}
    tmp=to_string(current)+tmp;
    part.setString(tmp);
}

void Instruction::next()
{
    string tmp=part.getString();
    int current=tmp[0]-'0';
    tmp.erase(tmp.begin());
    if(current<4) {++current;layout=current;}
    tmp=to_string(current)+tmp;
    part.setString(tmp);
}   

void Instruction::setFirstPlayerTexture()
{
    sf::FloatRect size;
    for(int i=1;i<=numImages;i++)
    {
        firstPlayer.loadFromFile(Link(i).getLink());
        firstPlayers.push_back(firstPlayer);
    }
}

void Instruction::setSecondPlayerTexture()
{
    sf::FloatRect size;
    for(int i=1;i<=numImages;i++)
    {
        secondPlayer.loadFromFile(Link(i).getLink());
        secondPlayers.push_back(secondPlayer);
    }
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

    cTime+=dt;
    if(cTime>timePerCharacter)
    {
        ++currentImage;
        if(currentImage==numImages) currentImage=0;
        cTime=sf::Time::Zero;
    }
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

    if (layout == 1)
    {
        mWindow.draw(firstIns);
        mWindow.draw(upSprite);
        mWindow.draw(downSprite);
        mWindow.draw(rightSprite);
        mWindow.draw(leftSprite);
        mWindow.draw(wSprite);
        mWindow.draw(sSprite);
        mWindow.draw(aSprite);
        mWindow.draw(dSprite);
        mWindow.draw(wText);
        mWindow.draw(sText);
        mWindow.draw(aText);
        mWindow.draw(dText);
        mWindow.draw(leftImageDarkSprite);
        mWindow.draw(rightImageDarkSprite);
        mWindow.draw(upImageDarkSprite);
        mWindow.draw(firstPlayerSprites[currentImage]);
    }

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