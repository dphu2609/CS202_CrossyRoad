#ifndef GLOBAL_VAR_HPP
#define GLOBAL_VAR_HPP

#include <SFML/Graphics.hpp>
#include <Resources/ResourceHolder.hpp>

namespace Resources {
    extern ResourceHolder<sf::Font, Fonts::ID> fonts;
    extern ResourceHolder<sf::Texture, CharacterTextures::ID> characterTextures;
    // add more resource holder here
};

namespace Controller {
    extern sf::Keyboard::Key MOVE_UP_1P;
    extern sf::Keyboard::Key MOVE_DOWN_1P;
    extern sf::Keyboard::Key MOVE_LEFT_1P;
    extern sf::Keyboard::Key MOVE_RIGHT_1P;

    extern sf::Keyboard::Key PAUSE;
};

namespace Statistic {
    extern float SCREEN_WIDTH;
    extern float SCREEN_HEIGHT;

    extern float SCREEN_SPEED;
    extern float TRUCK_SPEED;
    extern float SMALL_CAR_SPEED;
    extern float BIG_CAR_SPEED;
    extern float TRAIN_SPEED;

    extern int PLAYER_SCORE;
    extern int PLAYER_SKIN_TYPE;
    
    extern sf::Vector2f CHARACTER_SIZE;
    extern sf::Vector2f CHARACTER_SPAWN_POSITION;
    extern float CHARACTER_JUMP_DISTANCE;
};

#endif