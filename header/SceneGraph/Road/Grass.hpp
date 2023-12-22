#ifndef GRASS_HPP
#define GRASS_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <SceneGraph/Road/Road.hpp>
#include <SceneGraph/Road/Block.hpp>

class Grass : public Road {
public:
    Grass(bool isCreateObject = true);
    Grass(std::ifstream &file);
    virtual bool isCollide(const sf::FloatRect &rect) const;
    virtual bool isBlock(sf::Vector2f position);
    void randomBlock();
    virtual RoadType::ID getRoadType() const {return RoadType::Grass;}
    void addBlock(int index, Block::Type type);
    void readData(std::ifstream &file);
    void writeData(std::ofstream &file);
private:
    virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
    virtual void updateCurrent(sf::Time dt);
private:
    sf::Sprite mGrass;
    int spaces;
    std::vector<Block*> mBlocks;
};

#endif