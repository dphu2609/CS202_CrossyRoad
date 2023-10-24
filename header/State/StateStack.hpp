#ifndef STATESTACK_HPP
#define STATESTACK_HPP

#include <SceneGraph/SceneNode.hpp>
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

namespace States {
    enum ID {
        None,
        Menu,
        Settings,
        HighScore,
        Game,
        Pause,
        GameOver
    };
};

class StateStack;

class State {
public:
    typedef std::unique_ptr<State> Ptr;
    explicit State(StateStack& stack, sf::RenderWindow &window);
    virtual void update() {}
    virtual void draw() {}
    virtual void handleEvent(sf::Event &event) {}
protected: 
    void requestStackPush(States::ID stateID);
    void requestStackPop();
    void requestStateClear();
public:
    sf::RenderWindow &mWindow;
    std::array<SceneNode*, 20> mSceneLayers;
    SceneNode mSceneGraph;
private:
    virtual void buildScene() = 0;
private: 
    StateStack *mStack;
};

class StateStack : private sf::NonCopyable {
public: 
    enum Action {
        Push,
        Pop,
        Clear
    };
public: 
    explicit StateStack(sf::RenderWindow &window);

    template <typename T>
    void registerState(States::ID stateID);

    void update();
    void draw();
    void handleEvent(sf::Event& event);

    void pushState(States::ID stateID);
    void popState();
    void clearStates();

    bool isEmpty() const;

private:
    sf::RenderWindow &mWindow;
private:
    State::Ptr createState(States::ID stateID);
    void applyPendingChanges();

private:
    struct PendingChange {
        explicit PendingChange(Action action, States::ID stateID = States::None);
        Action action;
        States::ID stateID;
    };
private:
    std::vector<State::Ptr> mStack;
    std::vector<PendingChange> mPendingList;
    std::map<States::ID, std::function<State::Ptr()>> mFactories;
};
#endif