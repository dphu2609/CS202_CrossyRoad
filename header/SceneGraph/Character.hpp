#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <SceneGraph/SceneNode.hpp>

class Character : public SceneNode {
public:
    Character();
private:
    virtual void updateCurrent(sf::Time dt);
    virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
    virtual unsigned int getCategory() const;
private:
    std::vector<sf::Sprite> mSprites; // a sequence of multiple states of character
    sf::Clock mClock; // use to change state of character
    float threshHold;
};

#endif