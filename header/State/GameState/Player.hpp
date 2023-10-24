#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <CommandQueue.hpp>

class Player {
public:
    void handleEvent(const sf::Event &event, CommandQueue &commands);
    void handleRealtimeInput(CommandQueue &commands);
};

#endif