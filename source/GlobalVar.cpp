#include <GlobalVar.hpp>

namespace Resources {
    ResourceHolder<sf::Texture, CharacterTextures::ID> characterTextures;
    ResourceHolder<sf::Font, Fonts::ID> fonts;
}

namespace Controller {
    sf::Keyboard::Key MOVE_UP_1P = sf::Keyboard::W;
    sf::Keyboard::Key MOVE_DOWN_1P = sf::Keyboard::S;
    sf::Keyboard::Key MOVE_LEFT_1P = sf::Keyboard::A;
    sf::Keyboard::Key MOVE_RIGHT_1P = sf::Keyboard::D;
    sf::Keyboard::Key MOVE_UP_2P = sf::Keyboard::Up;
    sf::Keyboard::Key MOVE_DOWN_2P = sf::Keyboard::Down;
    sf::Keyboard::Key MOVE_LEFT_2P = sf::Keyboard::Left;
    sf::Keyboard::Key MOVE_RIGHT_2P = sf::Keyboard::Right;

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

    int PLAYER_SCORE = 0;
    int PLAYER_SKIN_TYPE = 0;

    sf::Vector2f CHARACTER_SIZE = sf::Vector2f(200, 200);
    sf::Vector2f CHARACTER_SPAWN_POSITION = sf::Vector2f(SCREEN_WIDTH / 2 - CHARACTER_SIZE.x /2, SCREEN_HEIGHT - 100);

    float CHARACTER_JUMP_DISTANCE = 100;
};
