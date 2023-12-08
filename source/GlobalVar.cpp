#include <GlobalVar.hpp>

namespace Resources {
    ResourceHolder<sf::Texture, CharacterTextures::ID> characterTextures;
    ResourceHolder<sf::Font, Fonts::ID> fonts;
    ResourceHolder<sf::Texture, RoadTextures::ID> roadTextures;
}

namespace Controller {
    sf::Keyboard::Key MOVE_UP = sf::Keyboard::W;
    sf::Keyboard::Key MOVE_DOWN = sf::Keyboard::S;
    sf::Keyboard::Key MOVE_LEFT = sf::Keyboard::A;
    sf::Keyboard::Key MOVE_RIGHT = sf::Keyboard::D;

    sf::Keyboard::Key PAUSE = sf::Keyboard::Escape;
}


namespace Statistic {
    float SCREEN_WIDTH = 1920;
    float SCREEN_HEIGHT = 1080;

    float SCREEN_SPEED;
    float TRUCK_SPEED;
    float SMALL_CAR_SPEED;
    float BIG_CAR_SPEED;
    float TRAIN_SPEED;

    float ROAD_WIDTH = 2000;
    float ROAD_HEIGHT = 100;

    int DEFAULT_BLOCK = 5;
    int BLOCK_SIZE = 100;

    int PLAYER_SCORE = 0;
    int PLAYER_SKIN_TYPE = 0;

    sf::Vector2f CHARACTER_SIZE = sf::Vector2f(100, 150);
    sf::Vector2f CHARACTER_SPAWN_POSITION = sf::Vector2f(SCREEN_WIDTH / 2 - CHARACTER_SIZE.x /2, SCREEN_HEIGHT - 100);

<<<<<<< Updated upstream
    float CHARACTER_JUMP_DISTANCE = 100;
=======
    float CHARACTER_JUMP_DISTANCE_HORIZONTAL = 100;
    float CHARACTER_JUMP_DISTANCE_VERTICAL = 70;

    float MINIMUM_WOOD_LENGTH = 100;
    float MAXIMUM_WOOD_LENGTH = 200;

    sf::Vector2f MAX_RIVER_SPEED = sf::Vector2f(300, 0);
    sf::Vector2f MIN_RIVER_SPEED = sf::Vector2f(200, 0);
    sf::Vector2f ADDING_RIVER_SPEED = sf::Vector2f(100, 0);

    float WOOD_HEIGHT = 50;
    float SCREEN_SPEED = 50.f;
    float SCREEN_SPEED_DEFAULT = 50.f;
    float SCREEN_SPEED_INCREASE = 350.f;

    bool IS_GAME_OVER = false;

    bool IS_EXIT_TO_MENU = true;
>>>>>>> Stashed changes
};
