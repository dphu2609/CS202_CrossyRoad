#include <Menu/MainScreen.hpp>

MainScreen::MainScreen()
{
    pos=sf::Vector2f(700.f,100.f);
    sizeBound=sf::Vector2f(200.f,100.f);
    colorBound=sf::Color::Green;
    sizeTheme=sf::Vector2f(1920.f,1080.f);
    sf::FloatRect size;

    background.loadFromFile("D:/GitHub/CS202_CrossyRoad/media/images/menu/background_glacial_mountains.png");
    backgroundSprite.setTexture(background);
    sf::FloatRect sizeThemeOrigin=backgroundSprite.getGlobalBounds();
    backgroundSprite.setScale(sf::Vector2f(sizeTheme.x/sizeThemeOrigin.width,sizeTheme.y/sizeThemeOrigin.height));

    _font.loadFromFile("D:/GitHub/CS202_CrossyRoad/media/font/Alinore.otf");
    sizeCharacter=100;
    colorCharacter=sf::Color::White;

    title.setString("Crossy Road");
    title.setFont(_font);
    title.setCharacterSize(200);
    title.setFillColor(sf::Color::Green);
    size=title.getGlobalBounds();
    title.setOrigin(size.width/2,size.height/2);
    title.setPosition(sf::Vector2f(960.f,50.f));
    title.setScale(1.75,0.8);

    pos=sf::Vector2f(pos.x,pos.y*1.5);

    newgame.setString("New Game");
    newgame.setFont(_font);
    newgame.setCharacterSize(sizeCharacter);
    newgame.setFillColor(colorCharacter);
    newgame.setPosition(pos.x,pos.y*2);

    highscore.setString("High Score");
    highscore.setFont(_font);
    highscore.setCharacterSize(sizeCharacter);
    highscore.setFillColor(colorCharacter);
    highscore.setPosition(pos.x,pos.y*3);

    setting.setString("Setting");
    setting.setFont(_font);
    setting.setCharacterSize(sizeCharacter);
    setting.setFillColor(colorCharacter);
    setting.setPosition(pos.x,pos.y*4);

    instruction.setString("Instruction");
    instruction.setFont(_font);
    instruction.setCharacterSize(sizeCharacter);
    instruction.setFillColor(colorCharacter);
    instruction.setPosition(pos.x,pos.y*5);

    newgameBound.setSize(sf::Vector2f(sizeBound.x*2,sizeBound.y));
    newgameBound.setPosition(pos.x,pos.y*2);
    newgameBound.setFillColor(colorBound);

    highscoreBound.setSize(sf::Vector2f(sizeBound.x*2,sizeBound.y));
    highscoreBound.setPosition(pos.x,pos.y*3);
    highscoreBound.setFillColor(colorBound);
    
    settingBound.setSize(sf::Vector2f(sizeBound.x*2,sizeBound.y));
    settingBound.setPosition(pos.x,pos.y*4);
    settingBound.setFillColor(colorBound);
    
    instructionBound.setSize(sf::Vector2f(sizeBound.x*2,sizeBound.y));
    instructionBound.setPosition(pos.x,pos.y*5);
    instructionBound.setFillColor(colorBound);

    packs.push_back(Pack(newgameBound,newgame));
    packs.push_back(Pack(highscoreBound,highscore));
    packs.push_back(Pack(settingBound,setting));
    packs.push_back(Pack(instructionBound,instruction));
}

int MainScreen::processEvent(sf::Event& event,sf::RenderWindow& mWindow)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(mWindow);
    int size=packs.size();
    for(int i=0;i<size;i++)
    {
        auto& x=packs[i];
        sf::FloatRect RecBound=x.getGlobalBounds();
        bool isMouseOn=RecBound.contains(static_cast<float>(mousePosition.x),static_cast<float>(mousePosition.y));
        if(isMouseOn)
        {
            if(event.type==sf::Event::MouseButtonPressed&&event.mouseButton.button==sf::Mouse::Left)
            {
                return i+1;
            }
        }
        else
        {
            
        }
    }
    return 0;
}

void MainScreen::draw(sf::RenderWindow& mWindow)
{
    mWindow.draw(backgroundSprite);
    mWindow.draw(title);
    mWindow.draw(newgameBound);
    mWindow.draw(newgame);
    mWindow.draw(highscoreBound);
    mWindow.draw(highscore);
    mWindow.draw(settingBound);
    mWindow.draw(setting);
    mWindow.draw(instructionBound);
    mWindow.draw(instruction);
}