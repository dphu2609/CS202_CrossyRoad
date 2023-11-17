#include <GlobalVar.hpp>

namespace Resources {
    ResourceHolder<sf::Texture, CharacterTextures::ID> characterTextures;
    ResourceHolder<sf::Font, Fonts::ID> fonts;
    ResourceHolder<sf::Texture, RoadTextures::ID> roadTextures;

    GifHolder gifsHolder;
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
    sf::FloatRect SCREEN_BOUNDING = sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT * 2);

    float ROAD_WIDTH = 2000;
    float ROAD_HEIGHT = 70;

    int DEFAULT_BLOCK = 5;
    int BLOCK_SIZE = 100;
    float SMALL_CAR_LENGTH = 120;
    float SMALL_CAR_HEIGHT = 120;
    float BIG_CAR_LENGTH = 130;
    float BIG_CAR_HEIGHT = 130;
    float TRUCK_CAR_LENGTH = 200;
    float TRUCK_CAR_HEIGHT = 160;
    float TRAIN_LENGTH = 1500;
    float TRAIN_HEIGHT = 70;


    int PLAYER_SCORE = 0;
    int PLAYER_SKIN_TYPE = 0;

    sf::Vector2f CHARACTER_SIZE = sf::Vector2f(50, 70);
    sf::Vector2f CHARACTER_SPAWN_POSITION = sf::Vector2f(SCREEN_WIDTH / 2 - CHARACTER_SIZE.x /2, SCREEN_HEIGHT - 100);
    sf::Vector2f INITIAL_VIEW_POSITION = sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 300);
    sf::Vector2f RESET_VIEW_POSITION = sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 290);

    float CHARACTER_JUMP_DISTANCE_HORIZONTAL = 100;
    float CHARACTER_JUMP_DISTANCE_VERTICAL = 70;

    float SCREEN_SPEED = 50.f;
    float SCREEN_SPEED_DEFAULT = 50.f;
    float SCREEN_SPEED_INCREASE = 350.f;
};
