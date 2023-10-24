#include <GUI/GUIComponent.hpp>

namespace GUI {
    Component::Component() {
        this->mIsSelected = false;
        this->mIsActive = false;
    }

    Component::~Component() {}

    void Component::handleEvent(const sf::Event &event) {}
}