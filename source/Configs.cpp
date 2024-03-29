#include <Configs.hpp>

namespace Resources {
    ResourceHolder<sf::Texture, CharacterTextures::ID> characterTextures;
    ResourceHolder<sf::Font, Fonts::ID> fonts;
    ResourceHolder<sf::Texture, RoadTextures::ID> roadTextures;
    ResourceHolder<sf::Texture, MenuTextures::ID> menuTextures;
    ResourceHolder<sf::SoundBuffer, Sounds::ID> sounds;

    GifHolder gifsHolder;
}


namespace Controller {
    char MOVE_UP_SET_1 = 'w';
    char MOVE_DOWN_SET_1 = 's';
    char MOVE_LEFT_SET_1 = 'a';
    char MOVE_RIGHT_SET_1 = 'd';

    char MOVE_UP_SET_2 = static_cast<char>(24);
    char MOVE_DOWN_SET_2 = static_cast<char>(25);
    char MOVE_LEFT_SET_2 = static_cast<char>(27);
    char MOVE_RIGHT_SET_2 = static_cast<char>(26);

    sf::Keyboard::Key PAUSE = sf::Keyboard::Escape;
}


namespace Statistic {
    float SCREEN_WIDTH = 1920;
    float SCREEN_HEIGHT = 1080;
    sf::FloatRect SCREEN_BOUNDING = sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT * 2);
    sf::Vector2f INITIAL_ROAD_SEQUENCE_POSITION = sf::Vector2f(Statistic::ROAD_WIDTH / 2 - 40, Statistic::CHARACTER_SPAWN_POSITION.y + Statistic::ROAD_HEIGHT * 5);

    float ROAD_WIDTH = 2000;
    float ROAD_HEIGHT = 70;

    int BLOCK_NUMBER = 5;
    int BLOCK_SIZE = 100;
    float SMALL_CAR_LENGTH = 80;
    float SMALL_CAR_HEIGHT = 45;
    float BIG_CAR_LENGTH = 110;
    float BIG_CAR_HEIGHT = 50;
    float TRUCK_CAR_LENGTH = 150;
    float TRUCK_CAR_HEIGHT = 60;
    float TRAIN_LENGTH = 1500;
    float TRAIN_HEIGHT = 70;
    sf::Vector2f TRAFFIC_LIGHT_SIZE = sf::Vector2f(40, 100);


    int PLAYER_SCORE = 0;
    int PLAYER_SKIN_TYPE = 0;

    sf::Vector2f CHARACTER_SIZE = sf::Vector2f(50, 70);
    sf::Vector2f CHARACTER_SPAWN_POSITION = sf::Vector2f(SCREEN_WIDTH / 2 - CHARACTER_SIZE.x /2, SCREEN_HEIGHT - 150);
    sf::Vector2f INITIAL_VIEW_POSITION = sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 300);
    sf::Vector2f RESET_VIEW_POSITION = sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 290);

    float CHARACTER_JUMP_DISTANCE = 100;
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

    bool IS_GAME_OVER = true;
    bool IS_LOAD_FROM_FILE = false;

    std::string LOAD_FILE_NAME = "data/save.dat";

    float ENVIROMENT_SOUND_VOLUME = 100.f;
    float MUSIC_SOUND_VOLUME = 100.f;

    bool IS_EXIT_TO_MENU = true;
    bool IS_GAME_PAUSE = false;
};

namespace GameSounds {
    sf::Sound HIT_SOUND;
    sf::Sound JUMP_SOUND;
    sf::Sound TRAFFIC_SOUND;
    sf::Sound TRAIN_SOUND;
};
