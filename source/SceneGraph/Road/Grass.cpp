#include <SceneGraph/Road/Grass.hpp>

void Grass::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mGrass, states);
}

void Grass::updateCurrent(sf::Time dt)
{
    
}

bool Grass::isCollide(const sf::FloatRect &rect) const
{
    for(auto& ptr : mBlocks)
    {
        if(ptr != nullptr && ptr->getBoundingRect().intersects(rect))
            return true;
    }
    return false;
}

Grass::Grass()
: mGrass(Resources::roadTextures[RoadTextures::Grass], sf::IntRect(100 - Statistic::ROAD_WIDTH, 100 - Statistic::ROAD_HEIGHT, Statistic::ROAD_WIDTH, Statistic::ROAD_HEIGHT))
, spaces(Statistic::ROAD_WIDTH / Statistic::BLOCK_SIZE)
, mBlocks(spaces, nullptr)
{
    mGrass.setOrigin(Statistic::ROAD_WIDTH / 2, Statistic::ROAD_HEIGHT / 2);
    Resources::roadTextures[RoadTextures::Grass].setRepeated(true);
    randomBlock();
}

void Grass::addBlock(int index, Block::Type type)
{
    if(index < 0 || index >= spaces) return;
    float x = -1.f * Statistic::ROAD_WIDTH / 2 + Statistic::BLOCK_SIZE / 2 + index * Statistic::BLOCK_SIZE;
    float y = 10.f;
    std::shared_ptr<Block> temp(std::make_shared<Block>(type, Resources::roadTextures));

    mBlocks[index] = temp.get();
    // mBlocks[index]->setScale(Statistic::BLOCK_SIZE / mBlocks[index]->getSpriteBounds().height, Statistic::BLOCK_SIZE / mBlocks[index]->getSpriteBounds().height);
    mBlocks[index]->setOrigin(mBlocks[index]->getBoundingRect().width / 2, mBlocks[index]->getBoundingRect().height / 2);
    mBlocks[index]->setPosition(x, y);
    this->attachChild(std::move(temp));
}

void Grass::randomBlock()
{
    int numBlocks = Statistic::BLOCK_NUMBER;
    while(numBlocks)
    {   
        int type = 1 + rand() % (Block::Type::Count - 1);
        int index = rand() % spaces;
        if(mBlocks[index] == nullptr)
        {
            addBlock(index, (Block::Type)type);
            numBlocks--;
        }
    }
}

bool Grass::isBlock(sf::Vector2f position)
{
    int index = (position.x + Statistic::ROAD_WIDTH / 2) / Statistic::BLOCK_SIZE;
    if(index < 0 || index >= spaces) return false;
    if(mBlocks[index] == nullptr) return false;
    return true;
}
