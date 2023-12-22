#include <State/PauseState.hpp>

PauseState::PauseState(StateStack &stack, sf::RenderWindow &window) : State(stack, window), mWindow(window) {
    buildScene();
}

void PauseState::draw() {
    sf::RectangleShape backgroundShape;
    backgroundShape.setFillColor(sf::Color(0, 0, 0, 170));
    backgroundShape.setSize(sf::Vector2f(mWindow.getSize()));
    backgroundShape.setOrigin(backgroundShape.getSize() / 2.f);
    backgroundShape.setPosition(mWindow.getView().getCenter());
    mWindow.setView(mWindow.getView());
    mWindow.draw(backgroundShape);
    // mWindow.draw(mSceneGraph);
    mWindow.draw(mGUIContainer);
    mWindow.draw(mPauseText);
    mWindow.draw(mHorizontalLine1);
    mWindow.draw(mHorizontalLine2);
    mWindow.draw(mVerticalLine1);
    mWindow.draw(mVerticalLine2);
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

    mPauseText.setFont(Resources::fonts[Fonts::ComfortaaRegular]);
    mPauseText.setString("Pause");
    mPauseText.setCharacterSize(150);
    mPauseText.setFillColor(sf::Color::White);
    mPauseText.setOutlineColor(sf::Color::Black);
    mPauseText.setOutlineThickness(2);
    mPauseText.setOrigin(mPauseText.getLocalBounds().width / 2.f, mPauseText.getLocalBounds().height / 2.f);
    mPauseText.setPosition(mWindow.getView().getCenter() + sf::Vector2f(0, -350));

    mHorizontalLine1.setSize(sf::Vector2f(1200, 5));
    mHorizontalLine1.setFillColor(sf::Color::White);
    mHorizontalLine1.setOrigin(mHorizontalLine1.getSize() / 2.f);
    mHorizontalLine1.setPosition(mWindow.getView().getCenter() + sf::Vector2f(0, -200));

    mHorizontalLine2.setSize(sf::Vector2f(1200, 5));
    mHorizontalLine2.setFillColor(sf::Color::White);
    mHorizontalLine2.setOrigin(mHorizontalLine2.getSize() / 2.f);
    mHorizontalLine2.setPosition(mWindow.getView().getCenter() + sf::Vector2f(0, 200));

    mVerticalLine1.setSize(sf::Vector2f(5, 500));
    mVerticalLine1.setFillColor(sf::Color::White);
    mVerticalLine1.setOrigin(mVerticalLine1.getSize() / 2.f);
    mVerticalLine1.setPosition(mWindow.getView().getCenter() + sf::Vector2f(-550, 0));

    mVerticalLine2.setSize(sf::Vector2f(5, 500));
    mVerticalLine2.setFillColor(sf::Color::White);
    mVerticalLine2.setOrigin(mVerticalLine2.getSize() / 2.f);
    mVerticalLine2.setPosition(mWindow.getView().getCenter() + sf::Vector2f(550, 0));

    sf::Color grey = sf::Color(128, 128, 128, 255);
    sf::Color darkGrey = sf::Color(64, 64, 64, 255);
    std::vector<sf::Color> continueButtonTextColor = {sf::Color::Black, sf::Color::Black};
    std::vector<sf::Color> continueButtonBackgroundColor = {sf::Color::White, grey};
    std::vector<sf::Color> continueButtonOutlineColor = {grey, sf::Color::White};
    GUI::Component *continueButton = new GUI::Button(
        continueAction, 
        sf::Vector2f(250, 50), 
        mWindow.getView().getCenter() + sf::Vector2f(-125, -145),
        Resources::fonts[Fonts::ComfortaaRegular], "Continue", 
        continueButtonTextColor, 
        continueButtonBackgroundColor, 
        continueButtonOutlineColor
    );
    
    std::function<void()> backToMenuAction = [&] () {
        Statistic::IS_GAME_OVER = true;
        requestStateClear();
        requestStackPush(States::Menu);
    };

    GUI::Component *backToMenuButton = new GUI::Button(
        backToMenuAction, 
        sf::Vector2f(250, 50), 
        mWindow.getView().getCenter() + sf::Vector2f(-125, 15),
        Resources::fonts[Fonts::ComfortaaRegular], "Main Menu", 
        continueButtonTextColor,
        continueButtonBackgroundColor,
        continueButtonOutlineColor
    );

    std::function<void()> restartAction = [&] () {
        Statistic::IS_GAME_OVER = false;
        requestStateClear();
        requestStackPush(States::Game);
    };

    GUI::Component *restartButton = new GUI::Button(
        restartAction, 
        sf::Vector2f(250, 50), 
        mWindow.getView().getCenter() + sf::Vector2f(-125, -65),
        Resources::fonts[Fonts::ComfortaaRegular], "Restart", 
        continueButtonTextColor,
        continueButtonBackgroundColor,
        continueButtonOutlineColor
    );

    std::function<void()> exitAction = [&] () {
        Statistic::IS_GAME_OVER = false;
        requestStateClear();
        requestStackPush(States::HighScore);
    };

    GUI::Component *exitButton = new GUI::Button(
        exitAction, 
        sf::Vector2f(250, 50), 
        mWindow.getView().getCenter() + sf::Vector2f(-125, 95),
        Resources::fonts[Fonts::ComfortaaRegular], "Exit", 
        continueButtonTextColor,
        continueButtonBackgroundColor,
        continueButtonOutlineColor
    );
    mGUIContainer.pack(continueButton);
    mGUIContainer.pack(backToMenuButton);
    mGUIContainer.pack(restartButton);
    mGUIContainer.pack(exitButton);
}
