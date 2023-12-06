#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

namespace GUI {
    class Component : public sf::Drawable, public sf::Transformable {
    public:
        typedef std::shared_ptr<Component> Ptr;
    public:
        Component() {}
        virtual void update(sf::Time dt) = 0;
        virtual void handleEvent(sf::RenderWindow &window, sf::Event &event) = 0;
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;
    };
}
#endif // GUI_COMPONENT_HPP