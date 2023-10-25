#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <GUI/Component.hpp>

class GUI::Container : public sf::Drawable, public sf::Transformable {
private: 
    std::vector<Component*> mChildren;
public:
    Container();
    void pack(Component *component);
    void handleEvent(sf::Event &event);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif