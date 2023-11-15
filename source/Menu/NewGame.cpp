#include <Menu/NewGame.hpp>

NewGame::NewGame()
{
    colorBound=sf::Color::Green;
    sizeBound=sf::Vector2f(100.f,100.f);
    sizeTheme=sf::Vector2f(1920.f,1080.f);
    sizeCharacter=100;
    modePos=sf::Vector2f(1500.f,300.f);
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
    title.setScale(1.75,1.f);
    title.setPosition(sf::Vector2f(200.f,0.f));

    returnBound.setSize(sizeBound);
    returnBound.setFillColor(colorBound);
    returnBound.setPosition(50.f,50.f);

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

    firstPlayer.loadFromFile("D:/GitHub/CS202_CrossyRoad/media/images/characters/1.png");
    firstPlayerSprite.setTexture(firstPlayer);
    size=firstPlayerSprite.getGlobalBounds();
    firstPlayerSprite.setOrigin(size.width/2,size.height/2);
    firstPlayerSprite.setPosition(sf::Vector2f(437.5,550.f));
    firstPlayerSprite.setScale(0.6,0.6);

    secondPlayer.loadFromFile("D:/GitHub/CS202_CrossyRoad/media/images/characters/1.png");
    secondPlayerSprite.setTexture(secondPlayer);
    size=secondPlayerSprite.getGlobalBounds();
    secondPlayerSprite.setOrigin(size.width/2,size.height/2);
    secondPlayerSprite.setPosition(sf::Vector2f(1062.5,550.f));
    secondPlayerSprite.setScale(0.6,0.6);

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

    playBound.setSize(sf::Vector2f(sizeBound.x*2,sizeBound.y));
    playBound.setFillColor(colorBound);
    playBound.setPosition(1500.f,800.f);

    play.setString("Play");
    play.setFont(_font);
    play.setCharacterSize(sizeCharacter);
    play.setFillColor(colorCharacter);
    play.setPosition(1500.f,800.f);

    packs.push_back(Pack(onepBound,onep));
    packs.push_back(Pack(twopBound,twop));
    packs.push_back(Pack(playBound,play));
}

int NewGame::processEvent(sf::Event& event,sf::RenderWindow& mWindow)
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
    return 1;
}

void NewGame::draw(sf::RenderWindow& mWindow)
{
    mWindow.draw(backgroundSprite);
    mWindow.draw(title);
    mWindow.draw(returnBound);
    mWindow.draw(onepBound);
    mWindow.draw(onep);
    mWindow.draw(twopBound);
    mWindow.draw(twop);
    mWindow.draw(firstpBound);
    mWindow.draw(firstp);
    mWindow.draw(secondpBound);
    mWindow.draw(secondp);
    mWindow.draw(firstPlayerSprite);
    mWindow.draw(secondPlayerSprite);
    mWindow.draw(easy);
    mWindow.draw(medium);
    mWindow.draw(hard);
    mWindow.draw(extreme);
    mWindow.draw(playBound);
    mWindow.draw(play);
}