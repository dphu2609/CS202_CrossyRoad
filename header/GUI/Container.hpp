#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <GUI/Component.hpp>

namespace GUI {
    class Container;
};

class GUI::Container : public sf::Drawable, public sf::Transformable {
private: 
    std::vector<Component*> mChildren;
public:
    Container();
    ~Container();
    void pack(Component *component);
    void update(sf::Time dt);
    void handleEvent(sf::RenderWindow &window, sf::Event &event);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif