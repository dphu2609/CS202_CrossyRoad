#ifndef COMMANDQUEUE_HPP
#define COMMANDQUEUE_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <SceneGraph/SceneNode.hpp>

namespace Category {
    enum ID {
        None = 0,
        Player = 1 << 0
    };
};

struct Command {
    Command();
    std::function<void(SceneNode&, sf::Time)> action;
    unsigned int category;
};

class CommandQueue {
public:
    void push(const Command &command);
    Command pop();
    bool isEmpty() const;
private:
    std::queue<Command> mQueue;
};


#endif