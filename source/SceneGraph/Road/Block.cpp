#include <SceneGraph/Road/Block.hpp>

RoadTextures::ID toTextureID(Block::Type type)
{
    switch (type)
    {
    case Block::Tree:
    return RoadTextures::Tree;
    case Block::Rock:
    return RoadTextures::Rock;
    // case Block::Bush:
    // return RoadTextures::Bush;
    case Block::None:
    return RoadTextures::None;
    }
    return RoadTextures::Tree;
}

Block::Block(Type type, const RoadTextureHolder& textures)
    : mType(type)
    , mSprite(textures[toTextureID(type)])
{
    sf::FloatRect bounds = mSprite.getLocalBounds();
    mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
    
    // if (bounds.width > 0 && bounds.height > 0) {
    //     float scaleX = Statistic::BLOCK_SIZE / bounds.width;
    //     float scaleY = Statistic::BLOCK_SIZE / bounds.height;

    //     mSprite.setScale(scaleX, scaleY);
    //     mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
    // } else {
    //     std::cerr << "Error: Invalid sprite dimensions" << std::endl;
    // }
}


void Block::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
}

bool Block::isCollide(const sf::FloatRect &rect) const {
    if(mType == None) return false;
    return mSprite.getGlobalBounds().intersects(rect);
}