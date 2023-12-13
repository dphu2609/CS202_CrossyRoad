#include <State/MenuState.hpp>

MenuState::MenuState(StateStack &stack, sf::RenderWindow &window) : State(stack, window), mWindow(window) {
    buildScene();
}

void MenuState::draw() {
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

void MenuState::update(sf::Time dt) {
    mSceneGraph.update(dt, mCommandQueue);
    mGUIContainer.update(dt);   
}

void MenuState::handleEvent(sf::Event &event) {
    mSceneGraph.handleEvent(mWindow, event);
    mGUIContainer.handleEvent(mWindow, event);
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        Statistic::IS_GAME_OVER = false;
        requestStackPop();
    }
}

void MenuState::buildScene() {
    std::function<void()> newGameAction = [&] () {
        requestStackPush(States::Game);
    };
    std::vector<sf::Color> newGameButtonTextColor = {sf::Color::Black, sf::Color::White};
    std::vector<sf::Color> newGameButtonBackgroundColor = {sf::Color::White, sf::Color::Black};
    std::vector<sf::Color> newGameButtonOutlineColor = {sf::Color::Black, sf::Color::White};
    GUI::Component *newGameButton = new GUI::Button(
        newGameAction, 
        sf::Vector2f(800, 100), 
        mWindow.getView().getCenter(),
        Resources::fonts[Fonts::ComfortaaRegular], "NEW GAME", 
        newGameButtonTextColor, 
        newGameButtonBackgroundColor, 
        newGameButtonOutlineColor
    );
    mGUIContainer.pack(newGameButton);

    std::function<void()> loadGameAction = [&] () {
        Statistic::IS_LOAD_FROM_FILE = true;
        requestStackPush(States::Game);
    };
    std::vector<sf::Color> loadGameButtonTextColor = {sf::Color::Black, sf::Color::White};
    std::vector<sf::Color> loadGameButtonBackgroundColor = {sf::Color::White, sf::Color::Black};
    std::vector<sf::Color> loadGameButtonOutlineColor = {sf::Color::Black, sf::Color::White};
    GUI::Component *loadGameButton = new GUI::Button(
        loadGameAction, 
        sf::Vector2f(800, 100), 
        mWindow.getView().getCenter() + sf::Vector2f(0, 200),
        Resources::fonts[Fonts::ComfortaaRegular], "LOAD GAME", 
        loadGameButtonTextColor, 
        loadGameButtonBackgroundColor, 
        loadGameButtonOutlineColor
    );
    mGUIContainer.pack(loadGameButton);
}
