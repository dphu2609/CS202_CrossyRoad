#include <Menu/Menu.hpp>

Menu::Menu()
{
    state=0;
    isPlay=false;
    isBackgroundLight=true;
    posBackgroundLight=sf::Vector2f(0.f,0.f);
    posBackgroundLight2=sf::Vector2f(1920.f,0.f);
}

bool Menu::playState()
{
    return isPlay;
}

void Menu::processEvent(sf::Event& event,sf::RenderWindow& mWindow)
{
    if(isPlay==false){
        if (state == 0)
        {
            state = mainscreen.processEvent(event, mWindow);
        }
        else if (state == 1)
        {
            state = newgame.processEvent(event, mWindow);
        }
        else if (state == 2)
        {
            state = highscore.processEvent(event, mWindow);
        }
        else if (state == 3)
        {
            state = setting.processEvent(event, mWindow);
        }
        else if (state == 4)
        {
            state = instruction.processEvent(event, mWindow);
        }
        else if(state==5)
        {
            isPlay=true;
        }
    }
    else{

    }
}

void Menu::update(sf::Time dt)
{
    if(isPlay==false){
        if (state == 0)
        {
            mainscreen.setBackground(isBackgroundLight);
            mainscreen.setPosBackgroundLight(posBackgroundLight);
            mainscreen.setPosBackgroundLight2(posBackgroundLight2);
            mainscreen.update(dt);
            isBackgroundLight=mainscreen.stateBackgroundLight();
            posBackgroundLight=mainscreen.posBackGroundLight();
            posBackgroundLight2=mainscreen.posBackGroundLight2();
        }
        else if (state == 1)
        {
            newgame.setBackground(isBackgroundLight);
            newgame.setPosBackgroundLight(posBackgroundLight);
            newgame.setPosBackgroundLight2(posBackgroundLight2);
            newgame.update(dt);
            isBackgroundLight=newgame.stateBackgroundLight();
            posBackgroundLight=newgame.posBackGroundLight();
            posBackgroundLight2=newgame.posBackGroundLight2();
        }
        else if (state == 2)
        {
            highscore.setBackground(isBackgroundLight);
            highscore.setPosBackgroundLight(posBackgroundLight);
            highscore.setPosBackgroundLight2(posBackgroundLight2);
            highscore.update(dt);
            isBackgroundLight=highscore.stateBackgroundLight();
            posBackgroundLight=highscore.posBackGroundLight();
            posBackgroundLight2=highscore.posBackGroundLight2();
        }
        else if (state == 3)
        {
            setting.setBackground(isBackgroundLight);
            setting.setPosBackgroundLight(posBackgroundLight);
            setting.setPosBackgroundLight2(posBackgroundLight2);
            setting.update(dt);
            isBackgroundLight=setting.stateBackgroundLight();
            posBackgroundLight=setting.posBackGroundLight();
            posBackgroundLight2=setting.posBackGroundLight2();
        }
        else if (state == 4)
        {
            instruction.setBackground(isBackgroundLight);
            instruction.setPosBackgroundLight(posBackgroundLight);
            instruction.setPosBackgroundLight2(posBackgroundLight2);
            instruction.update(dt);
            isBackgroundLight=instruction.stateBackgroundLight();
            posBackgroundLight=instruction.posBackGroundLight();
            posBackgroundLight2=instruction.posBackGroundLight2();
        }
    }
    else{

    }
}

void Menu::draw(sf::RenderWindow& mWindow)
{
    if(isPlay==false){
        if (state == 0)
        {
            mainscreen.draw(mWindow);
        }
        else if (state == 1)
        {
            newgame.draw(mWindow);
        }
        else if (state == 2)
        {
            highscore.draw(mWindow);
        }
        else if (state == 3)
        {
            setting.draw(mWindow);
        }
        else if (state == 4)
        {
            instruction.draw(mWindow);
        }
    }
    else{

    }
}