#include <Menu/MainScreen.hpp>

MainScreen::MainScreen()
{
    pos=sf::Vector2f(700.f,100.f);
    sizeBound=sf::Vector2f(200.f,100.f);
    colorBound=sf::Color::Transparent;
    sizeTheme=sf::Vector2f(1920.f,1080.f);

    background.loadFromFile("D:/GitHub/CS202_CrossyRoad/media/images/menu/background_glacial_mountains.png");
    backgroundSprite.setTexture(background);
    sf::FloatRect sizeThemeOrigin=backgroundSprite.getGlobalBounds();
    backgroundSprite.setScale(sf::Vector2f(sizeTheme.x/sizeThemeOrigin.width,sizeTheme.y/sizeThemeOrigin.height));

    _font.loadFromFile("D:/GitHub/CS202_CrossyRoad/media/font/Alinore.otf");
    sizeCharacter=100;
    colorCharacter=sf::Color::White;

    title.setString("Crossy Road");
    title.setFont(_font);
    title.setCharacterSize(150);
    title.setFillColor(sf::Color::Green);
    title.setPosition(pos);

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

    newgameBound.setSize(sizeBound);
    newgameBound.setPosition(pos.x,pos.y*2);
    newgameBound.setFillColor(colorBound);

    highscoreBound.setSize(sizeBound);
    highscoreBound.setPosition(pos.x,pos.y*3);
    highscoreBound.setFillColor(colorBound);
    
    settingBound.setSize(sizeBound);
    settingBound.setPosition(pos.x,pos.y*4);
    settingBound.setFillColor(colorBound);
    
    instructionBound.setSize(sizeBound);
    instructionBound.setPosition(pos.x,pos.y*5);
    instructionBound.setFillColor(colorBound);
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