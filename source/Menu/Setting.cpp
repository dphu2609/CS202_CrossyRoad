#include <Menu/Setting.hpp>

Setting::Setting()
{
    colorBound=sf::Color::Transparent;
    sizeBound=sf::Vector2f(100.f,100.f);
    sizeTheme=sf::Vector2f(1920.f,1080.f);
    sizeCharacter=100;
    sizeCharacterDirection=90;
    sf::FloatRect size;

    mTime=sf::Time::Zero;
    timePerFrame=sf::seconds(60.f/60.f);

    lightScreen=true;

    backgroundLight.loadFromFile("media/images/menu/background_glacial_mountains_lightened.png");
    backgroundLightSprite.setTexture(backgroundLight);
    sf::FloatRect sizeThemeOrigin=backgroundLightSprite.getGlobalBounds();
    backgroundLightSprite.setScale(sf::Vector2f(sizeTheme.x/sizeThemeOrigin.width,sizeTheme.y/sizeThemeOrigin.height));

    backgroundLight2.loadFromFile("media/images/menu/background_glacial_mountains_lightened.png");
    backgroundLight2Sprite.setTexture(backgroundLight2);
    sizeThemeOrigin=backgroundLight2Sprite.getGlobalBounds();
    backgroundLight2Sprite.setScale(sf::Vector2f(sizeTheme.x/sizeThemeOrigin.width,sizeTheme.y/sizeThemeOrigin.height));
    backgroundLight2Sprite.setPosition(1920.f,0.f);

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
    
    resetBound.setSize(sf::Vector2f(sizeBound.x*2,sizeBound.y));
    resetBound.setFillColor(colorBound);
    resetBound.setPosition(50.f,930.f);

    reset.setString("Reset");
    reset.setFont(_font);
    reset.setCharacterSize(sizeCharacter);
    reset.setFillColor(colorCharacter);
    size=reset.getGlobalBounds();
    reset.setOrigin(size.width/2,size.height/2);
    reset.setPosition(150.f,930.f);

    saveBound.setSize(sf::Vector2f(sizeBound.x*2,sizeBound.y));
    saveBound.setFillColor(colorBound);
    saveBound.setPosition(1670.f,930.f);

    save.setString("Save");
    save.setFont(_font);
    save.setCharacterSize(sizeCharacter);
    save.setFillColor(colorCharacter);
    size=save.getGlobalBounds();
    save.setOrigin(size.width/2,size.height/2);
    save.setPosition(1770.f,930.f);

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

    directionCircle.setPosition(600.f,500);
    controlType=0;
    directionCircle.changeToDark();

    w.loadFromFile("media/images/menu/letterControl.png");
    wSprite.setTexture(w);
    size=wSprite.getGlobalBounds();
    wSprite.setOrigin(size.width/2,size.height/2);
    wSprite.setScale(200.f/size.width,200.f/size.height);
    wSprite.setPosition(sf::Vector2f(1320.f,300.f));

    wBound.setSize(sf::Vector2f(sizeBound.x,sizeBound.y));
    wBound.setFillColor(colorBound);
    wBound.setPosition(1270.f,250.f);

    s.loadFromFile("media/images/menu/letterControl.png");
    sSprite.setTexture(s);
    size=sSprite.getGlobalBounds();
    sSprite.setOrigin(size.width/2,size.height/2);
    sSprite.setScale(200.f/size.width,200.f/size.height);
    sSprite.setPosition(sf::Vector2f(1320.f,410.f));

    sBound.setSize(sf::Vector2f(sizeBound.x,sizeBound.y));
    sBound.setFillColor(colorBound);
    sBound.setPosition(1270.f,360.f);

    a.loadFromFile("media/images/menu/letterControl.png");
    aSprite.setTexture(a);
    size=aSprite.getGlobalBounds();
    aSprite.setOrigin(size.width/2,size.height/2);
    aSprite.setScale(200.f/size.width,200.f/size.height);
    aSprite.setPosition(sf::Vector2f(1210.f,410.f));

    aBound.setSize(sf::Vector2f(sizeBound.x,sizeBound.y));
    aBound.setFillColor(colorBound);
    aBound.setPosition(1160.f,360.f);

    d.loadFromFile("media/images/menu/letterControl.png");
    dSprite.setTexture(d);
    size=dSprite.getGlobalBounds();
    dSprite.setOrigin(size.width/2,size.height/2);
    dSprite.setScale(200.f/size.width,200.f/size.height);
    dSprite.setPosition(sf::Vector2f(1430.f,410.f));

    dBound.setSize(sf::Vector2f(sizeBound.x,sizeBound.y));
    dBound.setFillColor(colorBound);
    dBound.setPosition(1380.f,360.f);

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

    letterCircle.setPosition(1320.f,500.f);
    isChosen=0;

    arrayDirection[0]='w';
    arrayDirection[1]='s';
    arrayDirection[2]='a';
    arrayDirection[3]='d';
    oldControlType=0;
    oldArrayDirection[0]='w';
    oldArrayDirection[1]='s';
    oldArrayDirection[2]='a';
    oldArrayDirection[3]='d';

    musicBound.setSize(sf::Vector2f(sizeBound.x*4.7,sizeBound.y));
    musicBound.setFillColor(colorBound);
    musicBound.setPosition(300.f,630.f);

    music.setString("Music");
    music.setFont(_font);
    music.setCharacterSize(sizeCharacter);
    music.setFillColor(colorCharacter);
    size=music.getGlobalBounds();
    music.setOrigin(size.width/2,size.height/2);
    music.setPosition(535.f,630.f);

    musicBar.setSize(sf::Vector2f(sizeBound.x*6,sizeBound.y*0.7));
    musicBar.setFillColor(colorBound);
    musicBar.setOutlineThickness(5.f);
    musicBar.setOutlineColor(sf::Color::Green);
    musicBar.setPosition(920.f,630.f);

    musicIncrease.setPosition(1584.f,665.f);
    musicDecrease.setPosition(854.f,665.f);
    musicIncrease.rotate(180.f);

    soundBound.setSize(sf::Vector2f(sizeBound.x*4.7,sizeBound.y));
    soundBound.setFillColor(colorBound);
    soundBound.setPosition(300.f,780.f);

    sound.setString("Sound");
    sound.setFont(_font);
    sound.setCharacterSize(sizeCharacter);
    sound.setFillColor(colorCharacter);
    size=sound.getGlobalBounds();
    sound.setOrigin(size.width/2,size.height/2);
    sound.setPosition(535.f,780.f);

    soundBar.setSize(sf::Vector2f(sizeBound.x*6,sizeBound.y*0.7));
    soundBar.setFillColor(colorBound);
    soundBar.setOutlineThickness(5.f);
    soundBar.setOutlineColor(sf::Color::Green);
    soundBar.setPosition(920.f,780.f);

    soundIncrease.setPosition(1584.f,815.f);
    soundDecrease.setPosition(854.f,815.f);
    soundIncrease.rotate(180.f);

    musicBarArray.setPosition(920.f,630.f);
    soundBarArray.setPosition(920.f,780.f);

    // packs.push_back(Pack(resetBound,reset));
    // packs.push_back(Pack(saveBound,save));
}

sf::Vector2f Setting::posBackGroundLight()
{
    return backgroundLightSprite.getPosition();
}

sf::Vector2f Setting::posBackGroundLight2()
{
    return backgroundLight2Sprite.getPosition();
}

void Setting::setPosBackgroundLight(sf::Vector2f pos)
{
    backgroundLightSprite.setPosition(pos);
}

void Setting::setPosBackgroundLight2(sf::Vector2f pos)
{
    backgroundLight2Sprite.setPosition(pos);
} 

bool Setting::stateBackgroundLight()
{
    return lightScreen;
}  

void Setting::setBackground(bool isBackgoundLight)
{
    if (isBackgoundLight)
    {
        backgroundLight.loadFromFile("media/images/menu/background_glacial_mountains_lightened.png");
        backgroundLight2.loadFromFile("media/images/menu/background_glacial_mountains_lightened.png");
    }
    else
    {
        backgroundLight.loadFromFile("media/images/menu/background_glacial_mountains.png");
        backgroundLight2.loadFromFile("media/images/menu/background_glacial_mountains.png");
    }
}  

void Setting::setCurrent()
{
    arrayDirection[0]=oldArrayDirection[0];
    arrayDirection[1]=oldArrayDirection[1];
    arrayDirection[2]=oldArrayDirection[2];
    arrayDirection[3]=oldArrayDirection[3];
    wText.setString(arrayDirection[0]);
    sText.setString(arrayDirection[1]);
    aText.setString(arrayDirection[2]);
    dText.setString(arrayDirection[3]);
    controlType=oldControlType;
    if(controlType==0)
    {
        directionCircle.changeToDark();
        letterCircle.changeToLight();
    }
    else
    {
        directionCircle.changeToLight();
        letterCircle.changeToDark();
    }
    Controller::MOVE_UP_SET_1 = arrayDirection[0];
    Controller::MOVE_DOWN_SET_1 = arrayDirection[1];
    Controller::MOVE_LEFT_SET_1 = arrayDirection[2];
    Controller::MOVE_RIGHT_SET_1 = arrayDirection[3];
}

void Setting::setOldCurrent()
{
    oldArrayDirection[0]=arrayDirection[0];
    oldArrayDirection[1]=arrayDirection[1];
    oldArrayDirection[2]=arrayDirection[2];
    oldArrayDirection[3]=arrayDirection[3];
    oldControlType=controlType;
    if(controlType==0)
    {
        directionCircle.changeToDark();
        letterCircle.changeToLight();
    }
    else
    {
        directionCircle.changeToLight();
        letterCircle.changeToDark();
    }
    Controller::MOVE_UP_SET_1 = arrayDirection[0];
    Controller::MOVE_DOWN_SET_1 = arrayDirection[1];
    Controller::MOVE_LEFT_SET_1 = arrayDirection[2];
    Controller::MOVE_RIGHT_SET_1 = arrayDirection[3];
}

void Setting::setReset()
{
    arrayDirection[0]='w';
    arrayDirection[1]='s';
    arrayDirection[2]='a';
    arrayDirection[3]='d';
    wText.setString(arrayDirection[0]);
    sText.setString(arrayDirection[1]);
    aText.setString(arrayDirection[2]);
    dText.setString(arrayDirection[3]);
    controlType=0;
    directionCircle.changeToDark();
    letterCircle.changeToLight();
}

int Setting::processEvent(sf::Event& event,sf::RenderWindow& mWindow)
{
    sf::Vector2f mousePosition=mWindow.mapPixelToCoords(sf::Mouse::getPosition(mWindow));
    sf::FloatRect size;

    sf::FloatRect recBound=returnBound.getGlobalBounds();
    bool isMouseOn=recBound.contains(static_cast<float>(mousePosition.x),static_cast<float>(mousePosition.y));
    if(isMouseOn)
    {
        returnImage.loadFromFile("media/images/menu/Back2.png");
        returnImageSprite.setTexture(returnImage);
        if(event.type==sf::Event::MouseButtonPressed&&event.mouseButton.button==sf::Mouse::Left)
        {
            musicBarArray.setCurrent();
            musicBarArray.setMusic();
            soundBarArray.setCurrent();
            soundBarArray.setSound();
            setCurrent();
            return 0;
        }
    }
    else
    {
        returnImage.loadFromFile("media/images/menu/Back1.png");
        returnImageSprite.setTexture(returnImage);
    }
    
    recBound=wBound.getGlobalBounds();
    isMouseOn=recBound.contains(static_cast<float>(mousePosition.x),static_cast<float>(mousePosition.y));
    if(isMouseOn)
    {
        if(event.type==sf::Event::MouseButtonPressed&&event.mouseButton.button==sf::Mouse::Left)
        {
                wText.setFillColor(sf::Color::Cyan);
                isChosen=1;
        }
        if(isChosen==1&&event.type==sf::Event::TextEntered)
        {
            char c=static_cast<char>(event.text.unicode);
            cout<<c<<endl;
            arrayDirection[0]=c;
            string tmp="";
            tmp+=c;
            wText.setString(tmp);
            wText.setCharacterSize(sizeCharacterDirection);
            size=wText.getGlobalBounds();
            wText.setOrigin(size.width/2,size.height/2);
            wText.setPosition(sf::Vector2f(1318.f,265.f));
        }
    }
    else
    {
        if(isChosen==1)
        {
            wText.setFillColor(colorCharacter);
            isChosen=0;
        }
    }    

    recBound=sBound.getGlobalBounds();
    isMouseOn=recBound.contains(static_cast<float>(mousePosition.x),static_cast<float>(mousePosition.y));
    if(isMouseOn)
    {
        if(event.type==sf::Event::MouseButtonPressed&&event.mouseButton.button==sf::Mouse::Left)
        {
                sText.setFillColor(sf::Color::Cyan);
                isChosen=2;
        }
        if(isChosen==2&&event.type==sf::Event::TextEntered)
        {
            char c=static_cast<char>(event.text.unicode);
            cout<<c<<endl;
            arrayDirection[1]=c;
            string tmp="";
            tmp+=c;
            sText.setString(tmp);
            // sText.setCharacterSize(sizeCharacter);
            // size=sText.getGlobalBounds();
            // sText.setOrigin(size.width/2,size.height/2);
            // sText.setPosition(sf::Vector2f(1318.f,375.f));
        }
    }
    else
    {
        if(isChosen==2)
        {
            sText.setFillColor(colorCharacter);
            isChosen=0;
        }
    }    

    recBound=aBound.getGlobalBounds();
    isMouseOn=recBound.contains(static_cast<float>(mousePosition.x),static_cast<float>(mousePosition.y));
    if(isMouseOn)
    {
        if(event.type==sf::Event::MouseButtonPressed&&event.mouseButton.button==sf::Mouse::Left)
        {
                aText.setFillColor(sf::Color::Cyan);
                isChosen=3;
        }
        if(isChosen==3&&event.type==sf::Event::TextEntered)
        {
            char c=static_cast<char>(event.text.unicode);
            cout<<c<<endl;
            arrayDirection[2]=c;
            string tmp="";
            tmp+=c;
            aText.setString(tmp);
            // aText.setCharacterSize(sizeCharacter);
            // size=aText.getGlobalBounds();
            // aText.setOrigin(size.width/2,size.height/2);
            // aText.setPosition(sf::Vector2f(1208.f,375.f));
        }
    }
    else
    {
        if(isChosen==3)
        {
            aText.setFillColor(colorCharacter);
            isChosen=0;
        }
    }    

    recBound=dBound.getGlobalBounds();
    isMouseOn=recBound.contains(static_cast<float>(mousePosition.x),static_cast<float>(mousePosition.y));
    if(isMouseOn)
    {
        if(event.type==sf::Event::MouseButtonPressed&&event.mouseButton.button==sf::Mouse::Left)
        {
                dText.setFillColor(sf::Color::Cyan);
                isChosen=4;
        }
        if(isChosen==4&&event.type==sf::Event::TextEntered)
        {
            char c=static_cast<char>(event.text.unicode);
            cout<<c<<endl;
            arrayDirection[3]=c;
            string tmp="";
            tmp+=c;
            dText.setString(tmp);
            // dText.setCharacterSize(sizeCharacter);
            // size=dText.getGlobalBounds();
            // dText.setOrigin(size.width/2,size.height/2);
            // dText.setPosition(sf::Vector2f(1428.f,375.f));
        }
    }
    else
    {
        if(isChosen==4)
        {
            dText.setFillColor(colorCharacter);
            isChosen=0;
        }
    }    

    recBound=directionCircle.getGlobalBounds();
    isMouseOn=recBound.contains(static_cast<float>(mousePosition.x),static_cast<float>(mousePosition.y));
    if(isMouseOn)
    {
        directionCircle.changeToDark();
        if(event.type==sf::Event::MouseButtonPressed&&event.mouseButton.button==sf::Mouse::Left)
        {
            controlType=0;
        }
    }
    else
    {
        if(controlType) directionCircle.changeToLight();
    }

    recBound=letterCircle.getGlobalBounds();
    isMouseOn=recBound.contains(static_cast<float>(mousePosition.x),static_cast<float>(mousePosition.y));
    if(isMouseOn)
    {
        letterCircle.changeToDark();
        if(event.type==sf::Event::MouseButtonPressed&&event.mouseButton.button==sf::Mouse::Left)
        {
            controlType=1;
        }
    }
    else
    {
        if(!controlType) letterCircle.changeToLight();
    }

    recBound=musicIncrease.getGlobalBounds();
    isMouseOn=recBound.contains(static_cast<float>(mousePosition.x),static_cast<float>(mousePosition.y));
    if(isMouseOn)
    {
        musicIncrease.changeToDark();
        if(event.type==sf::Event::MouseButtonPressed&&event.mouseButton.button==sf::Mouse::Left)
        {
            musicBarArray.increaseByOne();
            musicBarArray.setMusic();
        }
    }
    else
    {
        musicIncrease.changeToLight();
    }

    recBound=musicDecrease.getGlobalBounds();
    isMouseOn=recBound.contains(static_cast<float>(mousePosition.x),static_cast<float>(mousePosition.y));
    if(isMouseOn)
    {
        musicDecrease.changeToDark();
        if(event.type==sf::Event::MouseButtonPressed&&event.mouseButton.button==sf::Mouse::Left)
        {
            musicBarArray.decreaseByOne();
            musicBarArray.setMusic();
        }
    }
    else
    {
        musicDecrease.changeToLight();
    }

    recBound=soundIncrease.getGlobalBounds();
    isMouseOn=recBound.contains(static_cast<float>(mousePosition.x),static_cast<float>(mousePosition.y));
    if(isMouseOn)
    {
        soundIncrease.changeToDark();
        if(event.type==sf::Event::MouseButtonPressed&&event.mouseButton.button==sf::Mouse::Left)
        {
            soundBarArray.increaseByOne();
            soundBarArray.setSound();
        }
    }
    else
    {
        soundIncrease.changeToLight();
    }

    recBound=soundDecrease.getGlobalBounds();
    isMouseOn=recBound.contains(static_cast<float>(mousePosition.x),static_cast<float>(mousePosition.y));
    if(isMouseOn)
    {
        soundDecrease.changeToDark();
        if(event.type==sf::Event::MouseButtonPressed&&event.mouseButton.button==sf::Mouse::Left)
        {
            soundBarArray.decreaseByOne();
            soundBarArray.setSound();
        }
    }
    else
    {
        soundDecrease.changeToLight();
    }

    recBound=resetBound.getGlobalBounds();
    isMouseOn=recBound.contains(static_cast<float>(mousePosition.x),static_cast<float>(mousePosition.y));
    if(isMouseOn)
    {
        reset.setScale(1.2,1.2);
        if(event.type==sf::Event::MouseButtonPressed&&event.mouseButton.button==sf::Mouse::Left)
        {
            musicBarArray.reset();
            soundBarArray.reset();
            setReset();
        }
    }
    else
    {
        reset.setScale(1,1);
    }

    recBound=saveBound.getGlobalBounds();
    isMouseOn=recBound.contains(static_cast<float>(mousePosition.x),static_cast<float>(mousePosition.y));
    if(isMouseOn)
    {
        save.setScale(1.2,1.2);
        if(event.type==sf::Event::MouseButtonPressed&&event.mouseButton.button==sf::Mouse::Left)
        {
            musicBarArray.setOldCurrent();
            soundBarArray.setOldCurrent();
            setOldCurrent();
            return 0;
        }
    }
    else
    {
        save.setScale(1,1);
    }

    return 3;
}

void Setting::update(sf::Time dt)
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

void Setting::draw(sf::RenderWindow& mWindow)
{
    // mWindow.draw(backgroundLightSprite);
    // mWindow.draw(backgroundLight2Sprite);
    mWindow.draw(title);
    mWindow.draw(returnBound);
    mWindow.draw(returnImageSprite);

    mWindow.draw(upSprite);
    mWindow.draw(downSprite);
    mWindow.draw(rightSprite);
    mWindow.draw(leftSprite);
    directionCircle.draw(mWindow);

    mWindow.draw(wBound);
    mWindow.draw(wSprite);
    mWindow.draw(sBound);
    mWindow.draw(sSprite);

    mWindow.draw(aBound);
    mWindow.draw(aSprite);
    mWindow.draw(dBound);
    mWindow.draw(dSprite);
    mWindow.draw(wText);
    mWindow.draw(sText);
    mWindow.draw(aText);
    mWindow.draw(dText);
    letterCircle.draw(mWindow);

    mWindow.draw(musicBound);
    mWindow.draw(music);
    mWindow.draw(musicBar);
    musicIncrease.draw(mWindow);
    musicDecrease.draw(mWindow);
    musicBarArray.draw(mWindow);
    mWindow.draw(soundBound);
    mWindow.draw(sound);
    mWindow.draw(soundBar);

    soundIncrease.draw(mWindow);
    soundDecrease.draw(mWindow);
    soundBarArray.draw(mWindow);

    mWindow.draw(resetBound);
    mWindow.draw(reset);
    mWindow.draw(saveBound);
    mWindow.draw(save);
}