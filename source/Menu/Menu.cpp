#include <Menu/Menu.hpp>

Menu::Menu()
{
    state=0;
}

void Menu::draw(int state, sf::RenderWindow& mWindow)
{
    if(state==0)
    {
        mainscreen.draw(mWindow);
    }
    else if(state==1)
    {
        newgame.draw(mWindow);
    }
    else if(state==2)
    {
        highscore.draw(mWindow);
    }
    else if(state==3)
    {
        
    }
    else if(state==4)
    {
        instruction.draw(mWindow);
    }
}