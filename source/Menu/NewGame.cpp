#include <Menu/NewGame.hpp>

NewGame::NewGame()
{
    colorBound=sf::Color::Transparent;
    sizeBound=sf::Vector2f(100.f,100.f);
    // sizeTheme=sf::Vector2f(1920.f,1080.f);
    sizeCharacter=100;
    modePos=sf::Vector2f(1500.f,300.f);
    sf::FloatRect size;

    numImages=16;
    currentImage=0;

    // mTime=sf::Time::Zero;
    // timePerFrame=sf::seconds(60.f/60.f);
    cTime=sf::Time::Zero;
    timePerCharacter=sf::seconds(40.f/60.f);

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
    title.setScale(1.75,1.f);
    title.setPosition(sf::Vector2f(200.f,0.f));

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

    onepBound.setSize(sizeBound);
    onepBound.setFillColor(colorBound);
    onepBound.setPosition(1670.f,50.f);

    onep.setString("1P");
    onep.setFont(_font);
    onep.setCharacterSize(sizeCharacter);
    onep.setFillColor(colorCharacter);
    onep.setPosition(1670.f,50.f);

    twopBound.setSize(sizeBound);
    twopBound.setFillColor(colorBound);
    twopBound.setPosition(1770.f,50.f);

    twop.setString("2P");
    twop.setFont(_font);
    twop.setCharacterSize(sizeCharacter);
    twop.setFillColor(colorCharacter);
    twop.setPosition(1770.f,50.f);

    numPlayer=1;

    firstpBound.setSize(sf::Vector2f(sizeBound.x*5.75,sizeBound.y));
    firstpBound.setFillColor(colorBound);
    firstpBound.setPosition(150.f,700.f);

    firstp.setString("First Player");
    firstp.setFont(_font);
    firstp.setCharacterSize(sizeCharacter);
    firstp.setFillColor(colorCharacter);
    size=firstp.getGlobalBounds();
    firstp.setOrigin(size.width/2,size.height/2);
    firstp.setPosition(437.5,700.f);

    secondpBound.setSize(sf::Vector2f(sizeBound.x*5.75,sizeBound.y));
    secondpBound.setFillColor(colorBound);
    secondpBound.setPosition(775.f,700.f);

    secondp.setString("Second Player");
    secondp.setFont(_font);
    secondp.setCharacterSize(sizeCharacter);
    secondp.setFillColor(colorCharacter);
    size=secondp.getGlobalBounds();
    secondp.setOrigin(size.width/2,size.height/2);
    secondp.setPosition(1062.5,700.f);

    setFirstPlayerTexture();
    //firstPlayer.loadFromFile("media/images/characters/1.png");
    for (int i = 0; i < numImages; i++)
    {
        firstPlayerSprites[i].setTexture(firstPlayers[i]);
        size = firstPlayerSprites[i].getGlobalBounds();
        firstPlayerSprites[i].setOrigin(size.width / 2, size.height / 2);
        firstPlayerSprites[i].setPosition(sf::Vector2f(437.5, 550.f));
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

    changeToOnePlayer();

    easy.setString("Easy");
    easy.setFont(_font);
    easy.setCharacterSize(sizeCharacter);
    easy.setFillColor(colorCharacter);
    easy.setPosition(modePos);

    medium.setString("Medium");
    medium.setFont(_font);
    medium.setCharacterSize(sizeCharacter);
    medium.setFillColor(colorCharacter);
    medium.setPosition(sf::Vector2f(modePos.x,modePos.y+100));

    hard.setString("Hard");
    hard.setFont(_font);
    hard.setCharacterSize(sizeCharacter);
    hard.setFillColor(colorCharacter);
    hard.setPosition(sf::Vector2f(modePos.x,modePos.y+200));
    
    extreme.setString("Extreme");
    extreme.setFont(_font);
    extreme.setCharacterSize(sizeCharacter);
    extreme.setFillColor(colorCharacter);
    extreme.setPosition(sf::Vector2f(modePos.x,modePos.y+300));

    modePos.y=320.f;
    // circles.resize(4);
    // for(int i=0;i<4;i++)
    // {
    //     circles[i].setPosition(modePos.x+300,modePos.y+i*100+50.f);
    // }
    // circles[0].changeToDark();

    modeSwitch=0;
    isFirstCircleOn=true;
    isSecondCircleOn=false;
    isThirdCircleOn=false;
    isFourthCircleOn=false;

    circleImage.loadFromFile("media/images/menu/Circle1.png");
    circleImageDark.loadFromFile("media/images/menu/Circle2.png");

    firstCircleBound.setRadius(20.f);
    firstCircleBound.setFillColor(sf::Color::Green);
    size=firstCircleBound.getGlobalBounds();
    firstCircleBound.setOrigin(size.width/2,size.height/2); 
    firstCircleBound.setPosition(modePos.x+300,modePos.y+0*100+50.f); //
    firstCircle.setTexture(circleImage); 
    size=firstCircle.getGlobalBounds();
    firstCircle.setOrigin(size.width/2,size.height/2);
    firstCircle.setScale(120.f/size.width,120.f/size.height);
    firstCircle.setPosition(modePos.x+300,modePos.y+0*100+50.f); //
    firstCircleDark.setTexture(circleImageDark);
    size=firstCircleDark.getGlobalBounds();
    firstCircleDark.setOrigin(size.width/2,size.height/2);
    firstCircleDark.setScale(120.f/size.width,120.f/size.height);
    firstCircleDark.setPosition(modePos.x+300,modePos.y+0*100+50.f); //

    secondCircleBound.setRadius(20.f);
    secondCircleBound.setFillColor(sf::Color::Green);
    size=secondCircleBound.getGlobalBounds();
    secondCircleBound.setOrigin(size.width/2,size.height/2); 
    secondCircleBound.setPosition(modePos.x+300,modePos.y+1*100+50.f); //
    secondCircle.setTexture(circleImage); 
    size=secondCircle.getGlobalBounds();
    secondCircle.setOrigin(size.width/2,size.height/2);
    secondCircle.setScale(120.f/size.width,120.f/size.height);
    secondCircle.setPosition(modePos.x+300,modePos.y+1*100+50.f); //
    secondCircleDark.setTexture(circleImageDark);
    size=secondCircleDark.getGlobalBounds();
    secondCircleDark.setOrigin(size.width/2,size.height/2);
    secondCircleDark.setScale(120.f/size.width,120.f/size.height);
    secondCircleDark.setPosition(modePos.x+300,modePos.y+1*100+50.f); //

    thirdCircleBound.setRadius(20.f);
    thirdCircleBound.setFillColor(sf::Color::Green);
    size=thirdCircleBound.getGlobalBounds();
    thirdCircleBound.setOrigin(size.width/2,size.height/2); 
    thirdCircleBound.setPosition(modePos.x+300,modePos.y+2*100+50.f); //
    thirdCircle.setTexture(circleImage); 
    size=thirdCircle.getGlobalBounds();
    thirdCircle.setOrigin(size.width/2,size.height/2);
    thirdCircle.setScale(120.f/size.width,120.f/size.height);
    thirdCircle.setPosition(modePos.x+300,modePos.y+2*100+50.f); //
    thirdCircleDark.setTexture(circleImageDark);
    size=thirdCircleDark.getGlobalBounds();
    thirdCircleDark.setOrigin(size.width/2,size.height/2);
    thirdCircleDark.setScale(120.f/size.width,120.f/size.height);
    thirdCircleDark.setPosition(modePos.x+300,modePos.y+2*100+50.f); //

    fourthCircleBound.setRadius(20.f);
    fourthCircleBound.setFillColor(sf::Color::Green);
    size=fourthCircleBound.getGlobalBounds();
    fourthCircleBound.setOrigin(size.width/2,size.height/2); 
    fourthCircleBound.setPosition(modePos.x+300,modePos.y+3*100+50.f); //
    fourthCircle.setTexture(circleImage); 
    size=fourthCircle.getGlobalBounds();
    fourthCircle.setOrigin(size.width/2,size.height/2);
    fourthCircle.setScale(120.f/size.width,120.f/size.height);
    fourthCircle.setPosition(modePos.x+300,modePos.y+3*100+50.f); //
    fourthCircleDark.setTexture(circleImageDark);
    size=fourthCircleDark.getGlobalBounds();
    fourthCircleDark.setOrigin(size.width/2,size.height/2);
    fourthCircleDark.setScale(120.f/size.width,120.f/size.height);
    fourthCircleDark.setPosition(modePos.x+300,modePos.y+3*100+50.f); //

    playBound.setSize(sf::Vector2f(sizeBound.x*2,sizeBound.y));
    playBound.setFillColor(colorBound);
    playBound.setPosition(1500.f,800.f);

    play.setString("Play");
    play.setFont(_font);
    play.setCharacterSize(sizeCharacter);
    play.setFillColor(colorCharacter);
    play.setPosition(1500.f,800.f);

    // packs.push_back(Pack(onepBound,onep));
    // packs.push_back(Pack(twopBound,twop));
    //packs.push_back(Pack(playBound,play));
}

// sf::Vector2f NewGame::posBackGroundLight()
// {
//     return backgroundLightSprite.getPosition();
// }

// sf::Vector2f NewGame::posBackGroundLight2()
// {
//     return backgroundLight2Sprite.getPosition();
// }

// void NewGame::setPosBackgroundLight(sf::Vector2f pos)
// {
//     backgroundLightSprite.setPosition(pos);
// }

// void NewGame::setPosBackgroundLight2(sf::Vector2f pos)
// {
//     backgroundLight2Sprite.setPosition(pos);
// } 

// bool NewGame::stateBackgroundLight()
// {
//     return lightScreen;
// }  

// void NewGame::setBackground(bool isBackgoundLight)
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

void NewGame::setFirstPlayerTexture()
{
    sf::FloatRect size;
    for(int i=1;i<=numImages;i++)
    {
        firstPlayer.loadFromFile(Link(i).getLink());
        firstPlayers.push_back(firstPlayer);
    }
}

void NewGame::setSecondPlayerTexture()
{
    sf::FloatRect size;
    for(int i=1;i<=numImages;i++)
    {
        secondPlayer.loadFromFile(Link(i).getLink());
        secondPlayers.push_back(secondPlayer);
    }
}  

void NewGame::changeToOnePlayer()
{
    numPlayer=1;
    firstpBound.setPosition(462.5,700.f);
    firstp.setPosition(750.f,700.f);
    for(int i=0;i<numImages;i++)
    {
        firstPlayerSprites[i].setPosition(sf::Vector2f(750.f,550.f));
    }
    onep.setFillColor(sf::Color::Magenta);
    twop.setFillColor(sf::Color::White);
}

void NewGame::changeToTwoPlayer()
{
    numPlayer=2;
    firstpBound.setPosition(150.f,700.f);
    firstp.setPosition(437.5,700.f);
    for(int i=0;i<numImages;i++)
    {
        firstPlayerSprites[i].setPosition(sf::Vector2f(437.5,550.f));
    }
    onep.setFillColor(sf::Color::White);
    twop.setFillColor(sf::Color::Magenta);
}

void NewGame::setMode()
{
    Statistic::SCREEN_SPEED_DEFAULT=50+modeSwitch*20;
}

int NewGame::processEvent(sf::Event& event,sf::RenderWindow& mWindow)
{
    sf::Vector2f mousePosition=mWindow.mapPixelToCoords(sf::Mouse::getPosition(mWindow));
    sf::FloatRect recBound = onepBound.getGlobalBounds();
    bool isMouseOn = recBound.contains(mousePosition);
    if (isMouseOn)
    {
        onep.setFillColor(sf::Color::Magenta);
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            numPlayer = 1;
            changeToOnePlayer();
        }
        return 1;
    }
    else
    {
        if (1 != numPlayer)
        {
            onep.setFillColor(sf::Color::White);
        }
    }

    recBound = twopBound.getGlobalBounds();
    isMouseOn = recBound.contains(mousePosition);
    if (isMouseOn)
    {
        twop.setFillColor(sf::Color::Magenta);
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            numPlayer = 2;
            changeToTwoPlayer();
        }
        return 1;
    }
    else
    {
        if (2 != numPlayer)
        {
            twop.setFillColor(sf::Color::White);
        }
    }

    recBound = returnBound.getGlobalBounds();
    isMouseOn = recBound.contains(mousePosition);
    if (isMouseOn)
    {
        isReturnOn = true;
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            isReturnOn = false;
            return 0;
        }
        return 1;
    }
    else
    {
        isReturnOn = false;
    }

    recBound = firstCircleBound.getGlobalBounds();
    isMouseOn = recBound.contains(mousePosition);
    if (isMouseOn)
    {
        isFirstCircleOn = true;
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            modeSwitch = 0;
            setMode();
            isSecondCircleOn=false;
            isThirdCircleOn=false;
            isFourthCircleOn=false;
        }
        return 1;
    }
    else
    {
        if (0 != modeSwitch)
        {
            isFirstCircleOn = false;
        }
    }

    recBound = secondCircleBound.getGlobalBounds();
    isMouseOn = recBound.contains(mousePosition);
    if (isMouseOn)
    {
        isSecondCircleOn = true;
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            modeSwitch = 1;
            setMode();
            isFirstCircleOn=false;
            isThirdCircleOn=false;
            isFourthCircleOn=false;
        }
        return 1;
    }
    else
    {
        if (1 != modeSwitch)
        {
            isSecondCircleOn = false;
        }
    }

    recBound = thirdCircleBound.getGlobalBounds();
    isMouseOn = recBound.contains(mousePosition);
    if (isMouseOn)
    {
        isThirdCircleOn = true;
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            modeSwitch = 2;
            setMode();
            isFirstCircleOn=false;
            isSecondCircleOn=false;
            isFourthCircleOn=false;
        }
        return 1;
    }
    else
    {
        if (2 != modeSwitch)
        {
            isThirdCircleOn = false;
        }
    }

    recBound = fourthCircleBound.getGlobalBounds();
    isMouseOn = recBound.contains(mousePosition);
    if (isMouseOn)
    {
        isFourthCircleOn = true;
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            modeSwitch = 3;
            setMode();
            isFirstCircleOn=false;
            isSecondCircleOn=false;
            isThirdCircleOn=false;
        }
        return 1;
    }
    else
    {
        if (3 != modeSwitch)
        {
            isFourthCircleOn = false;
        }
    }

    recBound = playBound.getGlobalBounds();
    isMouseOn = recBound.contains(mousePosition);
    if (isMouseOn)
    {
        play.setScale(1.2,1.2);
        play.setFillColor(sf::Color::Blue);
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            play.setScale(1,1);
            play.setFillColor(sf::Color::White);
            Statistic::IS_GAME_OVER=false;
            return 5;
        }
        return 1;
    }
    else
    {
        play.setScale(1,1);
        play.setFillColor(sf::Color::White);
    }

    return 1;
}

void NewGame::update(sf::Time dt)
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

void NewGame::draw(sf::RenderWindow& mWindow)
{
    // mWindow.draw(backgroundLightSprite);
    // mWindow.draw(backgroundLight2Sprite);
    mWindow.draw(title);
    mWindow.draw(returnBound);
    if(isReturnOn)
    {
        mWindow.draw(returnImageDarkSprite);
    }
    else
    {
        mWindow.draw(returnImageSprite);
    }
    mWindow.draw(onepBound);
    mWindow.draw(onep);
    mWindow.draw(twopBound);
    mWindow.draw(twop);
    mWindow.draw(firstpBound);
    mWindow.draw(firstp);
    if(numPlayer==2)
    {
        mWindow.draw(secondpBound);
        mWindow.draw(secondp);
    }
    mWindow.draw(firstPlayerSprites[currentImage]);
    //first.draw(mWindow);
    if(numPlayer==2)
    {
        mWindow.draw(secondPlayerSprites[currentImage]);
    }
    mWindow.draw(easy);
    mWindow.draw(medium);
    mWindow.draw(hard);
    mWindow.draw(extreme);
    mWindow.draw(firstCircleBound);
    if(isFirstCircleOn)
    {
        mWindow.draw(firstCircleDark);
    }
    else mWindow.draw(firstCircle);
    mWindow.draw(secondCircleBound);
    if(isSecondCircleOn)
    {
        mWindow.draw(secondCircleDark);
    }
    else mWindow.draw(secondCircle);
    mWindow.draw(thirdCircleBound);
    if(isThirdCircleOn)
    {
        mWindow.draw(thirdCircleDark);
    }
    else mWindow.draw(thirdCircle);
    mWindow.draw(fourthCircleBound);
    if(isFourthCircleOn)
    {
        mWindow.draw(fourthCircleDark);
    }
    else mWindow.draw(fourthCircle);
    mWindow.draw(playBound);
    mWindow.draw(play);
}