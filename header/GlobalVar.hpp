#ifndef GLOBAL_VAR_HPP
#define GLOBAL_VAR_HPP

#include <SFML/Graphics.hpp>
#include <Resources/ResourceHolder.hpp>
#include <Resources/GifHolder.hpp>

namespace Resources
{
    extern ResourceHolder<sf::Font, Fonts::ID> fonts;
    extern ResourceHolder<sf::Texture, CharacterTextures::ID> characterTextures;
    extern ResourceHolder<sf::Texture, RoadTextures::ID> roadTextures;

    extern GifHolder gifsHolder;
    // add more resource holder here
};

namespace Controller
{
    extern sf::Keyboard::Key MOVE_UP;
    extern sf::Keyboard::Key MOVE_DOWN;
    extern sf::Keyboard::Key MOVE_LEFT;
    extern sf::Keyboard::Key MOVE_RIGHT;

    extern sf::Keyboard::Key PAUSE;
};

namespace Statistic
{
    extern float SCREEN_WIDTH;
    extern float SCREEN_HEIGHT;

    extern float SCREEN_SPEED;

    extern float ROAD_WIDTH;
    extern float ROAD_HEIGHT;

    extern int DEFAULT_BLOCK;
    extern int BLOCK_SIZE;
    extern float SMALL_CAR_LENGTH;
    extern float SMALL_CAR_HEIGHT;
    extern float BIG_CAR_LENGTH;
    extern float BIG_CAR_HEIGHT;
    extern float TRUCK_CAR_LENGTH;
    extern float TRUCK_CAR_HEIGHT;
    extern float TRAIN_LENGTH;
    extern float TRAIN_HEIGHT;

    extern int PLAYER_SCORE;
    extern int PLAYER_SKIN_TYPE;

    extern sf::Vector2f CHARACTER_SIZE;
    extern sf::Vector2f CHARACTER_SPAWN_POSITION;

    extern float CHARACTER_JUMP_DISTANCE_HORIZONTAL;
    extern float CHARACTER_JUMP_DISTANCE_VERTICAL;

    extern float SCREEN_SPEED;
};

#endif