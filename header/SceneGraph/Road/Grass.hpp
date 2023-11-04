#ifndef GRASS_HPP
#define GRASS_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <SceneGraph/Road/Road.hpp>
#include <SceneGraph/Road/Block.hpp>

class Grass : public Road {
public:
    Grass();
    virtual bool isCollide(const sf::FloatRect &rect) const;
    void randomBlock();
    void attachBlocks();
private:
    // void randomBlock();
private:
    virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
    virtual void updateCurrent(sf::Time dt);
private:
    sf::Sprite mGrass;
    int spaces;
    std::vector<Block*> mBlocks;
    
};

#endif