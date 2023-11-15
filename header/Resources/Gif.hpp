#ifndef GIF_HPP
#define GIF_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

class Gif : public sf::Drawable, public sf::Transformable {
private:
    std::vector<sf::Sprite> mSprites;
    sf::Time mDuration;
    sf::Clock mClock;
    sf::Time mElapsedTime;
    int mCurrentSprite;
public:
    Gif() {}
    Gif(const std::vector<sf::Sprite> &sprites, sf::Time duration);
    Gif(const Gif &other);
    void set(const std::vector<sf::Sprite> &textures, sf::Time duration);
    void set(const Gif &other);
    void update(sf::Time dt);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::FloatRect getGlobalBounds() const;
};

#endif
