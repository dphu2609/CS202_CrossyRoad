#include <GlobalVar.hpp>

namespace Resources {
    ResourceHolder<sf::Texture, Textures::ID> textures;
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