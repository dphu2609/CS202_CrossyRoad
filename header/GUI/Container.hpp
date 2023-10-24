#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <GUI/Component.hpp>

class GUI::Container {
private: 
    std::vector<GUIComponent*> mChildren;
public:
    Container();
    void pack(GUIComponent *component);
    void handleEvent(sf::Event &event);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif