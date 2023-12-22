#include <State/EndState.hpp>
#include "GlobalVar.hpp"

EndState::EndState(StateStack &stack, sf::RenderWindow &window) : State(stack, window), mWindow(window) {
    buildScene();
}

void EndState::draw() {
    mBackground.setTexture(Resources::roadTextures[RoadTextures::Background]);
    mBackground.setOrigin(mBackground.getGlobalBounds().width / 2.f, mBackground.getGlobalBounds().height / 2.f);
    mBackground.setPosition(mWindow.getView().getCenter());
    mWindow.setView(mWindow.getView());
    mWindow.draw(mBackground);
    mWindow.draw(mGUIContainer);
    mWindow.draw(mEndText);
    mWindow.draw(HighScore);
    mWindow.draw(CharacterSprites[cur]);
}

void EndState::update(sf::Time dt) {
    mSceneGraph.update(dt, mCommandQueue);
    mGUIContainer.update(dt);   
    mChangeTime -= dt;
    if (mChangeTime <= sf::Time::Zero) {
        mChangeTime = sf::seconds(0.5f);
        cur = (cur + 1) % 2;
    }
}

void EndState::handleEvent(sf::Event &event) {
    mSceneGraph.handleEvent(mWindow, event);
    mGUIContainer.handleEvent(mWindow, event);
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        Statistic::IS_GAME_OVER = false;
        requestStackPop();
    }
}

void EndState::buildScene() {
    switch((int)Statistic::SCREEN_SPEED_DEFAULT) {
        case 50: {
            saveHighScore("data/HighScore1PEasy.txt");
            break;
        }

        case 70: {
            saveHighScore("data/HighScore1PMedi.txt");
            break;
        }

        case 90: {
            saveHighScore("data/HighScore1PHard.txt");
            break;
        }

        case 110: {
            saveHighScore("data/HighScore1PXtre.txt");
            break;
        }
    };
    sf::Sprite cry1(Resources::characterTextures[CharacterTextures::CharacterCry1]);
    cry1.setOrigin(cry1.getGlobalBounds().width / 2.f, cry1.getGlobalBounds().height / 2.f);
    cry1.setPosition(mWindow.getView().getCenter() + sf::Vector2f(450, 10 + 30));
    cry1.setScale(0.5f, 0.5f);
    CharacterSprites.push_back(cry1);

    sf::Sprite cry2(Resources::characterTextures[CharacterTextures::CharacterCry2]);
    cry2.setOrigin(cry2.getGlobalBounds().width / 2.f, cry2.getGlobalBounds().height / 2.f);
    cry2.setPosition(mWindow.getView().getCenter() + sf::Vector2f(450, 10 + 30));
    cry2.setScale(0.5f, 0.5f);
    CharacterSprites.push_back(cry2);

    mChangeTime = sf::seconds(0.5f);

    mEndText.setFont(Resources::fonts[Fonts::ComfortaaRegular]);
    mEndText.setString("Game Over");
    mEndText.setCharacterSize(150);
    mEndText.setFillColor(sf::Color::White);
    mEndText.setOutlineColor(sf::Color::Black);
    mEndText.setOutlineThickness(2);
    mEndText.setOrigin(mEndText.getLocalBounds().width / 2.f,mEndText.getLocalBounds().height / 2.f);
    mEndText.setPosition(mWindow.getView().getCenter() + sf::Vector2f(0, -350 + 30));

    HighScore.setFont(Resources::fonts[Fonts::RobotoRegular]);
    HighScore.setString("Your Score: " + std::to_string(Statistic::PLAYER_SCORE));
    HighScore.setCharacterSize(60);
    HighScore.setFillColor(sf::Color::White);
    HighScore.setOutlineColor(sf::Color::Black);
    HighScore.setOutlineThickness(2);
    HighScore.setOrigin(HighScore.getLocalBounds().width / 2.f,HighScore.getLocalBounds().height / 2.f);
    HighScore.setPosition(mWindow.getView().getCenter() + sf::Vector2f(0, -200 + 30));

    std::function<void()> restartAction = [&] () {
        Statistic::PLAYER_SCORE = 0;
        requestStateClear();
        requestStackPush(States::Game);
    };

    sf::Color grey = sf::Color(128, 128, 128, 255);
    sf::Color darkGrey = sf::Color(64, 64, 64, 255);
    std::vector<sf::Color> continueButtonTextColor = {sf::Color::Black, sf::Color::Black};
    std::vector<sf::Color> continueButtonBackgroundColor = {sf::Color::White, grey};
    std::vector<sf::Color> continueButtonOutlineColor = {grey, sf::Color::White};
    GUI::Component *restartButton = new GUI::Button(
        restartAction, 
        sf::Vector2f(250, 50), 
        mWindow.getView().getCenter() + sf::Vector2f(-125, -95 + 30),
        Resources::fonts[Fonts::ComfortaaRegular], "Try Again", 
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
        mWindow.getView().getCenter() + sf::Vector2f(-125, -15 + 30),
        Resources::fonts[Fonts::ComfortaaRegular], "Main Menu", 
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
        mWindow.getView().getCenter() + sf::Vector2f(-125, 65 + 30),
        Resources::fonts[Fonts::ComfortaaRegular], "Exit", 
        continueButtonTextColor,
        continueButtonBackgroundColor,
        continueButtonOutlineColor
    );
    mGUIContainer.pack(restartButton);
    mGUIContainer.pack(backToMenuButton);
    mGUIContainer.pack(exitButton);
}

EndState::~EndState()
{
   
}

void EndState::saveHighScore(const std::string &name)
{
    std::ifstream fin(name);
    std::vector<int> scores;
    int x; 
    fin >> x;
    while(!fin.eof()) {
        scores.push_back(x);
        fin >> x;
    }

    fin.close();
    for(auto &x : scores) {
        if(x == Statistic::PLAYER_SCORE) return;
    }
    
    scores.push_back(Statistic::PLAYER_SCORE);
    sort(scores.begin(), scores.end(), std::greater<int>());
    if(scores.size() > 5) scores.pop_back();

    std::ofstream fout(name);
    for(int i = 0; i < scores.size(); i++) {
        fout << scores[i] << "\n";
    }
    fout.close();
}

