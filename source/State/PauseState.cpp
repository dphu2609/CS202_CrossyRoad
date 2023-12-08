#include <State/PauseState.hpp>

PauseState::PauseState(StateStack &stack, sf::RenderWindow &window) : State(stack, window), mWindow(window) {
    buildScene();
}

void PauseState::draw() {
    sf::RectangleShape backgroundShape;
    backgroundShape.setFillColor(sf::Color(0, 0, 0, 100));
    backgroundShape.setSize(sf::Vector2f(mWindow.getSize()));
    backgroundShape.setOrigin(backgroundShape.getSize() / 2.f);
    backgroundShape.setPosition(mWindow.getView().getCenter());
    mWindow.setView(mWindow.getView());
    mWindow.draw(backgroundShape);
    // mWindow.draw(mSceneGraph);
    mWindow.draw(mGUIContainer);
}

void PauseState::update(sf::Time dt) {
    mSceneGraph.update(dt, mCommandQueue);
    mGUIContainer.update(dt);   
}

void PauseState::handleEvent(sf::Event &event) {
    mSceneGraph.handleEvent(mWindow, event);
    mGUIContainer.handleEvent(mWindow, event);
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        Statistic::IS_GAME_OVER = false;
        requestStackPop();
    }
}

void PauseState::buildScene() {
    std::function<void()> continueAction = [&] () {
        Statistic::IS_GAME_OVER = false;
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
