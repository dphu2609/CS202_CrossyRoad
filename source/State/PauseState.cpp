#include <State/PauseState.hpp>

PauseState::PauseState(StateStack &stack, sf::RenderWindow &window) : State(stack, window), mWindow(window) {
    buildScene();
}

void PauseState::draw() {
    mWindow.draw(mSceneGraph);
    mWindow.draw(mGUIContainer);
}

void PauseState::update(sf::Time dt) {
    mSceneGraph.update(dt, mCommandQueue);
    mGUIContainer.update(dt);
}

void PauseState::handleEvent(sf::Event &event) {
    mSceneGraph.handleEvent(mWindow, event);
    mGUIContainer.handleEvent(mWindow, event);
}

void PauseState::buildScene() {
    std::function<void()> continueAction = [&] () {
        requestStackPop();
    };
    std::vector<sf::Color> continueButtonTextColor = {sf::Color::Black, sf::Color::White};
    std::vector<sf::Color> continueButtonBackgroundColor = {sf::Color::White, sf::Color::Black};
    std::vector<sf::Color> continueButtonOutlineColor = {sf::Color::Black, sf::Color::White};
    GUI::Component *continueButton = new GUI::Button(
        continueAction, 
        sf::Vector2f(800, 100), 
        mWindow.getView().getCenter(),
        Resources::fonts[Fonts::ComfortaaRegular], "Continue", 
        continueButtonTextColor, 
        continueButtonBackgroundColor, 
        continueButtonOutlineColor
    );
    mGUIContainer.pack(continueButton);
}