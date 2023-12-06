#include <SceneGraph/Road/RiverArea.hpp>

RiverArea::RiverArea(Type type, const RoadTextureHolder& textures)
: mType(type)
, mSprite(Resources::roadTextures[toTextureID(type)], sf::IntRect(0, 0, toRiverLength(type), Statistic::ROAD_HEIGHT))
{
    mSprite.setOrigin(mSprite.getGlobalBounds().width / 2, mSprite.getGlobalBounds().height / 2);
    Resources::roadTextures[toTextureID(mType)].setRepeated(true);
}

void RiverArea::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
}

void RiverArea::accelerate(Wood*& wood, sf::Time dt)
{
   sf::Vector2f distance = dt.asSeconds() * waterSpeed;
   wood->move((float)direction * distance);
}


RoadTextures::ID toTextureID(RiverArea::Type type)
{
    switch (type)
    {
    case RiverArea::Uniform:
    return RoadTextures::UniformWater;
    case RiverArea::Accelerate:
    return RoadTextures::AccelerateWater;
    }
    return RoadTextures::UniformWater;
}

float toRiverLength(RiverArea::Type type)
{
    switch (type)
    {
    case RiverArea::Uniform:
    return Statistic::ROAD_WIDTH / 2;
    case RiverArea::Accelerate:
    return Statistic::ROAD_WIDTH / 4;
    }
    return 0;
}

