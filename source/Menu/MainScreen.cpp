#include <Menu/MainScreen.hpp>

MainScreen::MainScreen()
{
    pos=sf::Vector2f(700.f,100.f);
    sizeBound=sf::Vector2f(200.f,100.f);
    colorBound=sf::Color::Transparent;
    // sizeTheme=sf::Vector2f(1920.f,1080.f);
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
    sizeCharacter=100;
    colorCharacter=sf::Color(240,246,204); //(240,246,204) (212,240,204)

    title.setString("Crossy Road");
    title.setFont(_font);
    title.setCharacterSize(200);
    title.setFillColor(sf::Color(29,151,29)); // (29,151,29) (246,237,160) (40,151,155) (24,145,149) (5,127,131)
    size=title.getGlobalBounds();
    title.setOrigin(size.width/2,size.height/2);
    title.setPosition(sf::Vector2f(960.f,50.f));
    title.setScale(1.75,0.8);

    pos=sf::Vector2f(960.f,pos.y*1.5);

    newgame.setString("New Game");
    newgame.setFont(_font);
    newgame.setCharacterSize(sizeCharacter);
    newgame.setFillColor(colorCharacter);
    size=newgame.getGlobalBounds();
    newgame.setOrigin(size.width/2,size.height/2);
    newgame.setPosition(pos.x,pos.y*2);

    highscore.setString("High Score");
    highscore.setFont(_font);
    highscore.setCharacterSize(sizeCharacter);
    highscore.setFillColor(colorCharacter);
    size=highscore.getGlobalBounds();
    highscore.setOrigin(size.width/2,size.height/2);
    highscore.setPosition(pos.x,pos.y*3);

    setting.setString("Setting");
    setting.setFont(_font);
    setting.setCharacterSize(sizeCharacter);
    setting.setFillColor(colorCharacter);
    size=setting.getGlobalBounds();
    setting.setOrigin(size.width/2,size.height/2);
    setting.setPosition(pos.x,pos.y*4);

    instruction.setString("Instruction");
    instruction.setFont(_font);
    instruction.setCharacterSize(sizeCharacter);
    instruction.setFillColor(colorCharacter);
    size=instruction.getGlobalBounds();
    instruction.setOrigin(size.width/2,size.height/2);
    instruction.setPosition(pos.x,pos.y*5);

    loadgame.setString("Load Game");
    loadgame.setFont(_font);
    loadgame.setCharacterSize(sizeCharacter);
    loadgame.setFillColor(colorCharacter);
    size=loadgame.getGlobalBounds();
    loadgame.setOrigin(size.width/2,size.height/2);
    loadgame.setPosition(pos.x,pos.y*6);

    newgameBound.setSize(sf::Vector2f(sizeBound.x*2,sizeBound.y));
    size=newgameBound.getGlobalBounds();
    newgameBound.setOrigin(size.width/2,size.height/6);
    newgameBound.setPosition(pos.x,pos.y*2);
    newgameBound.setFillColor(colorBound);

    highscoreBound.setSize(sf::Vector2f(sizeBound.x*2,sizeBound.y));
    size=highscoreBound.getGlobalBounds();
    highscoreBound.setOrigin(size.width/2,size.height/6);
    highscoreBound.setPosition(pos.x,pos.y*3);
    highscoreBound.setFillColor(colorBound);
    
    settingBound.setSize(sf::Vector2f(sizeBound.x*2,sizeBound.y));
    size=settingBound.getGlobalBounds();
    settingBound.setOrigin(size.width/2,size.height/6);
    settingBound.setPosition(pos.x,pos.y*4);
    settingBound.setFillColor(colorBound);
    
    instructionBound.setSize(sf::Vector2f(sizeBound.x*2,sizeBound.y));
    size=instructionBound.getGlobalBounds();
    instructionBound.setOrigin(size.width/2,size.height/6);
    instructionBound.setPosition(pos.x,pos.y*5);
    instructionBound.setFillColor(colorBound);

    loadgameBound.setSize(sf::Vector2f(sizeBound.x*2,sizeBound.y));
    size=loadgameBound.getGlobalBounds();
    loadgameBound.setOrigin(size.width/2,size.height/6);
    loadgameBound.setPosition(pos.x,pos.y*6);
    loadgameBound.setFillColor(colorBound);

    packs.push_back(Pack(newgameBound,newgame));
    packs.push_back(Pack(highscoreBound,highscore));
    packs.push_back(Pack(settingBound,setting));
    packs.push_back(Pack(instructionBound,instruction));
    packs.push_back(Pack(loadgameBound,loadgame));
}

// sf::Vector2f MainScreen::posBackGroundLight()
// {
//     return backgroundLightSprite.getPosition();
// }

// sf::Vector2f MainScreen::posBackGroundLight2()
// {
//     return backgroundLight2Sprite.getPosition();
// }

// void MainScreen::setPosBackgroundLight(sf::Vector2f pos)
// {
//     backgroundLightSprite.setPosition(pos);
// }

// void MainScreen::setPosBackgroundLight2(sf::Vector2f pos)
// {
//     backgroundLight2Sprite.setPosition(pos);
// } 

// bool MainScreen::stateBackgroundLight()
// {
//     return lightScreen;
// }  

// void MainScreen::setBackground(bool isBackgoundLight)
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

void MainScreen::loadGame()
{
    Statistic::IS_LOAD_FROM_FILE=true;
    Statistic::IS_GAME_OVER=false;
}

int MainScreen::processEvent(sf::Event& event,sf::RenderWindow& mWindow)
{   
    sf::Vector2f mousePosition = mWindow.mapPixelToCoords(sf::Mouse::getPosition(mWindow));
    int size=packs.size();
    for(int i=0;i<size;i++)
    {
        auto& x=packs[i];
        sf::FloatRect recBound = x.getGlobalBounds();
        bool isMouseOn = recBound.contains(mousePosition);
        if(isMouseOn)
        {
            sf::FloatRect size;
            if(i==0) 
            {
                newgame.setCharacterSize(120);
                size=newgame.getGlobalBounds();
                newgame.setOrigin(size.width/2,size.height/2);
            }
            else if(i==1) 
            {
                highscore.setCharacterSize(120);
                size=highscore.getGlobalBounds();
                highscore.setOrigin(size.width/2,size.height/2);
            }
            else if(i==2) 
            {
                setting.setCharacterSize(120);
                size=setting.getGlobalBounds();
                setting.setOrigin(size.width/2,size.height/2);
            }
            else if(i==3) 
            {
                instruction.setCharacterSize(120);
                size=instruction.getGlobalBounds();
                instruction.setOrigin(size.width/2,size.height/2);
            }
            else if(i==4) 
            {
                loadgame.setCharacterSize(120);
                size=loadgame.getGlobalBounds();
                loadgame.setOrigin(size.width/2,size.height/2);
            }
            if(event.type==sf::Event::MouseButtonPressed&&event.mouseButton.button==sf::Mouse::Left)
            {
                if(i==4)
                {
                    loadGame();
                    return 0;
                }
                return i+1;
            }
            return 0;
        }
        else
        {
            sf::FloatRect size;
            if(i==0) 
            {
                newgame.setCharacterSize(100);
                size=newgame.getGlobalBounds();
                newgame.setOrigin(size.width/2,size.height/2);
            }
            else if(i==1) 
            {
                highscore.setCharacterSize(100);
                size=highscore.getGlobalBounds();
                highscore.setOrigin(size.width/2,size.height/2);
            }
            else if(i==2) 
            {
                setting.setCharacterSize(100);
                size=setting.getGlobalBounds();
                setting.setOrigin(size.width/2,size.height/2);
            }
            else if(i==3) 
            {
                instruction.setCharacterSize(100);
                size=instruction.getGlobalBounds();
                instruction.setOrigin(size.width/2,size.height/2);
            }
            else if(i==4) 
            {
                loadgame.setCharacterSize(100);
                size=loadgame.getGlobalBounds();
                loadgame.setOrigin(size.width/2,size.height/2);
            }
        }
    }
    return 0;
}

void MainScreen::update(sf::Time dt)
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

void MainScreen::draw(sf::RenderWindow& mWindow)
{
    // mWindow.draw(backgroundLightSprite);
    // mWindow.draw(backgroundLight2Sprite);
    mWindow.draw(title);
    mWindow.draw(newgameBound);
    mWindow.draw(newgame);
    mWindow.draw(highscoreBound);
    mWindow.draw(highscore);
    mWindow.draw(settingBound);
    mWindow.draw(setting);
    mWindow.draw(instructionBound);
    mWindow.draw(instruction);
    mWindow.draw(loadgameBound);
    mWindow.draw(loadgame);
} 