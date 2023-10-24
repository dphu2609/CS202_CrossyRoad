#ifndef RIVER_HPP
#define RIVER_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <SceneGraph/Road/Road.hpp>

class River : public Road {
public:
    River();
    River(std::vector<std::string>> &oldData);
    virtual bool isCollide(const sf::FloatRect &rect) const;
    virtual std::vector<std::string> getData() const;
private:
    virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
    virtual void updateCurrent(sf::Time dt);
private:
    sf::Sprite mWater;
    std::vector<sf::Sprite> mWood;
    std::vector<std::vector<sf::Sprite>> mCrocodile;
    std::vector<sf::Clock> mCrocClock;
private:
    const float mWoodSpeed = 100.f;
};

#endif