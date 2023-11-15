#include <Menu/Setting.hpp>

Setting::Setting()
{
    colorBound=sf::Color::Green;
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

    musicBar.setSize(sf::Vector2f(sizeBound.x*8,sizeBound.y));
    musicBar.setFillColor(colorBound);
    musicBar.setPosition(820.f,630.f);

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

    soundBar.setSize(sf::Vector2f(sizeBound.x*8,sizeBound.y));
    soundBar.setFillColor(colorBound);
    soundBar.setPosition(820.f,780.f);

    packs.push_back(Pack(resetBound,reset));
    packs.push_back(Pack(saveBound,save));
}

int Setting::processEvent(sf::Event& event,sf::RenderWindow& mWindow)
{
    sf::Vector2i mousePosition=sf::Mouse::getPosition(mWindow);
    int size=packs.size();
    for(int i=0;i<size;i++)
    {
        auto& x=packs[i];
        sf::FloatRect recBound=x.getGlobalBounds();
        bool isMouseOn=recBound.contains(static_cast<float>(mousePosition.x),static_cast<float>(mousePosition.y));
        if(isMouseOn)
        {
            if(event.type==sf::Event::MouseButtonPressed&&event.mouseButton.button==sf::Mouse::Left)
            {

            }
        }
        else
        {

        }
    }
    sf::FloatRect recBound=returnBound.getGlobalBounds();
    bool isMouseOn=recBound.contains(static_cast<float>(mousePosition.x),static_cast<float>(mousePosition.y));
    if(isMouseOn)
    {
        if(event.type==sf::Event::MouseButtonPressed&&event.mouseButton.button==sf::Mouse::Left)
        {
            return 0;
        }
    }
    else
    {

    }
    return 3;
}

void Setting::draw(sf::RenderWindow& mWindow)
{
    mWindow.draw(backgroundSprite);
    mWindow.draw(title);
    mWindow.draw(returnBound);
    mWindow.draw(returnImageSprite);

    mWindow.draw(musicBound);
    mWindow.draw(music);
    mWindow.draw(musicBar);
    mWindow.draw(soundBound);
    mWindow.draw(sound);
    mWindow.draw(soundBar);
    mWindow.draw(resetBound);
    mWindow.draw(reset);
    mWindow.draw(saveBound);
    mWindow.draw(save);
}