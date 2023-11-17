#include <Menu/Menu.hpp>

Menu::Menu()
{
    state=0;
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