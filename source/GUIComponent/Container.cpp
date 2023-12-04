#include <GUI/Container.hpp>

GUI::Container::Container() {}

GUI::Container::~Container() {
    for (auto &child : mChildren) {
        delete child;
    }
}

void GUI::Container::pack(GUI::Component *component) {
    mChildren.push_back(component);
}

void GUI::Container::handleEvent(sf::RenderWindow &window, sf::Event &event) {
    for (auto &child : mChildren) {
        child->handleEvent(window, event);
    }
}

void GUI::Container::update(sf::Time dt) {
    for (auto &child : mChildren) {
        child->update(dt);
    }
}

void GUI::Container::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    for (auto &child : mChildren) {
        target.draw(*child, states);
    }
}