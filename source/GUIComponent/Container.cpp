#include <GUI/Container.hpp>

GUI::Container::Container() {}

void GUI::Container::pack(GUI::Component *component) {
    mChildren.push_back(component);
}

void GUI::Container::handleEvent(sf::Event &event) {
    for (auto &child : mChildren) {
        child->handleEvent(event);
    }
}

void GUI::Container::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    for (auto &child : mChildren) {
        target.draw(*child, states);
    }
}