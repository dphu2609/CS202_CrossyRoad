#include <SceneGraph/Road/Wood.hpp>

Wood::Wood(const RoadTextureHolder& textures, float maxLength) 
: length(maxLength)
,  mSprite(Resources::roadTextures[RoadTextures::Wood], sf::IntRect(0, 0, Statistic::MINIMUM_WOOD_LENGTH + rand() % (int)maxLength, Statistic::WOOD_HEIGHT))
{
    mSprite.setOrigin(mSprite.getGlobalBounds().width / 2, mSprite.getGlobalBounds().height / 2);
    Resources::roadTextures[RoadTextures::Wood].setRepeated(true);
}

bool Wood::isCollide(const sf::FloatRect& rect) const
{
    return getBoundingRect().intersects(rect);
}
void Wood::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
}