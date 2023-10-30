#ifndef GRASS_HPP
#define GRASS_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <SceneGraph/Road/Road.hpp>

class Grass : public Road {
// public:
//     Grass();
    // Grass(std::vector<std::string> &oldData);
    virtual bool isCollide(const sf::FloatRect &rect) const;
//     virtual std::vector<std::string> getData() const;
// private:
//     virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
//     virtual void updateCurrent(sf::Time dt);
private:
    sf::Sprite mGrass;
    std::vector<sf::Sprite> mTree;
    std::vector<sf::Sprite> mRock;
    std::vector<sf::Sprite> mBush;
    std::vector<sf::Sprite> mAnimal;
    sf::Clock mClock;
};

#endif