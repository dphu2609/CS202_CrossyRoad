#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>

class Menu
{
public:
    Menu(); 
    void update(sf::Time dt);
    void handleEvent(const sf::Event& event);
    void draw(int& state, sf::RenderWindow& mWindow);
private:
    int state;
    
};

#endif //MENU_HPP