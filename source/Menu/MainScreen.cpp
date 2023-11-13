#include <Menu/MainScreen.hpp>

MainScreen::MainScreen()
{
    pos=sf::Vector2f(50.f,50.f);
    sizeBound=sf::Vector2f(70.f,50.f);

    background.loadFromFile("media/images/menu/background_glacial_mountains.png");
    backgroundSprite.setTexture(background);

    _font.loadFromFile("media/font/Alinore.otf");
    
    title.setString("CrossyRoad");
    title.setFont(_font);
    title.setCharacterSize(30);
    title.setFillColor(sf::Color::Green);
    title.setPosition(pos);

    newgame.setString("New Game");
    newgame.setFont(_font);
    newgame.setCharacterSize(20);
    newgame.setFillColor(sf::Color::Blue);
    newgame.setPosition(pos.x,pos.y*2);

    highscore.setString("High Score");
    highscore.setFont(_font);
    highscore.setCharacterSize(20);
    highscore.setFillColor(sf::Color::Blue);
    highscore.setPosition(pos.x,pos.y*3);

    setting.setString("Setting");
    setting.setFont(_font);
    setting.setCharacterSize(20);
    setting.setFillColor(sf::Color::Blue);
    setting.setPosition(pos.x,pos.y*4);

    instruction.setString("Instruction");
    instruction.setFont(_font);
    instruction.setCharacterSize(20);
    instruction.setFillColor(sf::Color::Blue);
    instruction.setPosition(pos.x,pos.y*5);

    newgameBound.setSize(sizeBound);
    newgameBound.setPosition(pos.x,pos.y*2);

    highscoreBound.setSize(sizeBound);
    highscoreBound.setPosition(pos.x,pos.y*3);

    settingBound.setSize(sizeBound);
    settingBound.setPosition(pos.x,pos.y*4);

    instructionBound.setSize(sizeBound);
    instructionBound.setPosition(pos.x,pos.y*5);
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