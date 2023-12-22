#ifndef GLOBAL_VAR_HPP
#define GLOBAL_VAR_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Resources/ResourceHolder.hpp>
#include <Resources/GifHolder.hpp>

namespace Resources
{
    extern ResourceHolder<sf::Font, Fonts::ID> fonts;
    extern ResourceHolder<sf::Texture, CharacterTextures::ID> characterTextures;
    extern ResourceHolder<sf::Texture, RoadTextures::ID> roadTextures;
    extern ResourceHolder<sf::Texture, MenuTextures::ID> menuTextures;
    extern ResourceHolder<sf::SoundBuffer, Sounds::ID> sounds;

    extern GifHolder gifsHolder;
    // add more resource holder here
};

namespace Controller
{
    extern char MOVE_UP_SET_1;
    extern char MOVE_DOWN_SET_1;
    extern char MOVE_LEFT_SET_1;
    extern char MOVE_RIGHT_SET_1;

    extern char MOVE_UP_SET_2;
    extern char MOVE_DOWN_SET_2;
    extern char MOVE_LEFT_SET_2;
    extern char MOVE_RIGHT_SET_2;

    extern sf::Keyboard::Key PAUSE;
};

namespace Statistic
{
    extern float SCREEN_WIDTH;
    extern float SCREEN_HEIGHT;
    extern sf::FloatRect SCREEN_BOUNDING;

    extern sf::Vector2f INITIAL_ROAD_SEQUENCE_POSITION;

    extern float SCREEN_SPEED;

    extern float ROAD_WIDTH;
    extern float ROAD_HEIGHT;

    extern int BLOCK_NUMBER;
    extern int BLOCK_SIZE;
    extern float SMALL_CAR_LENGTH;
    extern float SMALL_CAR_HEIGHT;
    extern float BIG_CAR_LENGTH;
    extern float BIG_CAR_HEIGHT;
    extern float TRUCK_CAR_LENGTH;
    extern float TRUCK_CAR_HEIGHT;
    extern float TRAIN_LENGTH;
    extern float TRAIN_HEIGHT;
    extern sf::Vector2f TRAFFIC_LIGHT_SIZE;

    extern int PLAYER_SCORE;
    extern int PLAYER_SKIN_TYPE;

    extern sf::Vector2f CHARACTER_SIZE;
    extern sf::Vector2f CHARACTER_SPAWN_POSITION;

    extern float CHARACTER_JUMP_DISTANCE;
    extern sf::Vector2f INITIAL_VIEW_POSITION;
    extern sf::Vector2f RESET_VIEW_POSITION;

    extern float CHARACTER_JUMP_DISTANCE_HORIZONTAL;
    extern float CHARACTER_JUMP_DISTANCE_VERTICAL;

    extern sf::Vector2f MAX_RIVER_SPEED;
    extern sf::Vector2f MIN_RIVER_SPEED;
    extern sf::Vector2f ADDING_RIVER_SPEED; 
    extern float MINIMUM_WOOD_LENGTH;
    extern float MAXIMUM_WOOD_LENGTH;
    extern float WOOD_HEIGHT;
    
    extern float SCREEN_SPEED;
    extern float SCREEN_SPEED_DEFAULT;
    extern float SCREEN_SPEED_INCREASE;

    extern bool IS_GAME_OVER;
    extern bool IS_LOAD_FROM_FILE;

    extern std::string LOAD_FILE_NAME;

    extern float ENVIROMENT_SOUND_VOLUME;
    extern float MUSIC_SOUND_VOLUME;
};

#endif