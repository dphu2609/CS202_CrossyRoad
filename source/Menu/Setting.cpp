#include <Menu/Setting.hpp>

Setting::Setting()
{
    colorBound=sf::Color::Transparent;
    sizeBound=sf::Vector2f(100.f,100.f);
    sizeTheme=sf::Vector2f(1920.f,1080.f);
    sizeCharacter=100;
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

int Setting::processEvent(sf::Event& event,sf::RenderWindow& mWindow)
{
    sf::Vector2i mousePosition=sf::Mouse::getPosition(mWindow);

    sf::FloatRect recBound=returnBound.getGlobalBounds();
    bool isMouseOn=recBound.contains(static_cast<float>(mousePosition.x),static_cast<float>(mousePosition.y));
    if(isMouseOn)
    {
        returnImage.loadFromFile("media/images/menu/Back2.png");
        returnImageSprite.setTexture(returnImage);
        if(event.type==sf::Event::MouseButtonPressed&&event.mouseButton.button==sf::Mouse::Left)
        {
            musicBarArray.setCurrent();
            soundBarArray.setCurrent();
            return 0;
        }
    }
    else
    {
        returnImage.loadFromFile("media/images/menu/Back1.png");
        returnImageSprite.setTexture(returnImage);
    }

    recBound=musicIncrease.getGlobalBounds();
    isMouseOn=recBound.contains(static_cast<float>(mousePosition.x),static_cast<float>(mousePosition.y));
    if(isMouseOn)
    {
        musicIncrease.changeToDark();
        if(event.type==sf::Event::MouseButtonPressed&&event.mouseButton.button==sf::Mouse::Left)
        {
            musicBarArray.increaseByOne();
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
    mTime+=dt;
    if(mTime>timePerFrame){
        if (lightScreen)
        {
            backgroundLight.loadFromFile("media/images/menu/background_glacial_mountains.png");
            backgroundLight2.loadFromFile("media/images/menu/background_glacial_mountains.png");
        }
        else
        {
            backgroundLight.loadFromFile("media/images/menu/background_glacial_mountains_lightened.png");
            backgroundLight2.loadFromFile("media/images/menu/background_glacial_mountains_lightened.png");
        }
        lightScreen = !lightScreen;
        mTime=sf::Time::Zero;
    }
    backgroundLightSprite.setPosition(backgroundLightSprite.getPosition().x-0.5,0.f);
    backgroundLight2Sprite.setPosition(backgroundLight2Sprite.getPosition().x-0.5,0.f);
    if(backgroundLight2Sprite.getPosition().x==0.f)
    {
        backgroundLightSprite.setPosition(0.f,0.f);
        backgroundLight2Sprite.setPosition(1920.f,0.f);
    }
}

void Setting::draw(sf::RenderWindow& mWindow)
{
    mWindow.draw(backgroundLightSprite);
    mWindow.draw(backgroundLight2Sprite);
    mWindow.draw(title);
    mWindow.draw(returnBound);
    mWindow.draw(returnImageSprite);

    mWindow.draw(upSprite);
    mWindow.draw(downSprite);
    mWindow.draw(rightSprite);
    mWindow.draw(leftSprite);

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