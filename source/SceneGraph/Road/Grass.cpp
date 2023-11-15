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
        // std::cout << ptr->getPosition().x << " " << ptr->getPosition().y << std::endl;
        // if(ptr->getPosition().intersects(rect)) return true;
    }
    return false;
}

Grass::Grass()
: mGrass(Resources::roadTextures[RoadTextures::Grass], sf::IntRect(0, 0, Statistic::ROAD_WIDTH, Statistic::ROAD_HEIGHT))
, spaces(Statistic::ROAD_WIDTH / Statistic::BLOCK_SIZE)
, mBlocks(spaces)
{
    mGrass.setOrigin(Statistic::ROAD_WIDTH / 2, Statistic::ROAD_HEIGHT / 2);
    // mGrass.setScale(1, 1);
    // mGrass.setPosition(Statistic::ROAD_WIDTH / 2, Statistic::SCREEN_HEIGHT - 100);
    Resources::roadTextures[RoadTextures::Grass].setRepeated(true);
    // randomBlock();
    // for (auto &block : mBlocks) {
    //     this->attachChild(block);
    // }
}

void Grass::randomBlock()
{
    int numBlocks = spaces - 2 * Statistic::DEFAULT_BLOCK - 5;
    // float x = 0.f;
    float x = -1.f * Statistic::ROAD_WIDTH / 2 + Statistic::BLOCK_SIZE / 2;
    float y = 10.f;
    for(int i = 0; i < Statistic::DEFAULT_BLOCK; i++) {
        // mBlocks[i] = std::make_shared<Block>(Block::Tree, Resources::roadTextures);
        std::shared_ptr<Block> temp(std::make_shared<Block>(Block::Tree, Resources::roadTextures));
        mBlocks[i] = temp.get();
        mBlocks[i]->setScale(Statistic::BLOCK_SIZE / mBlocks[i]->getSpriteBounds().width, Statistic::BLOCK_SIZE / mBlocks[i]->getSpriteBounds().height);
        mBlocks[i]->setOrigin(Statistic::BLOCK_SIZE / 2, Statistic::BLOCK_SIZE / 2);
        // mBlocks[i]->setPosition(x, Statistic::SCREEN_HEIGHT - 100);
        mBlocks[i]->setPosition(x, y);
        this->attachChild(std::move(temp));
        x += Statistic::BLOCK_SIZE;
    }
    for(int i = Statistic::DEFAULT_BLOCK; i < spaces - Statistic::DEFAULT_BLOCK; i++) {
        if(!numBlocks)
        {
            // mBlocks[i] = std::make_shared<Block>(Block::Type::None, Resources::roadTextures);
            std::shared_ptr<Block> temp(std::make_shared<Block>(Block::None, Resources::roadTextures));
            mBlocks[i] = temp.get();
            mBlocks[i]->setScale(Statistic::BLOCK_SIZE / mBlocks[i]->getSpriteBounds().width, Statistic::BLOCK_SIZE / mBlocks[i]->getSpriteBounds().height);
            mBlocks[i]->setOrigin(Statistic::BLOCK_SIZE / 2, Statistic::BLOCK_SIZE / 2);
            // mBlocks[i]->setPosition(x, Statistic::SCREEN_HEIGHT - 100);
            mBlocks[i]->setPosition(x, y);
            this->attachChild(std::move(temp)); //
        }
        else
        {
            int type = rand() % Block::Type::Count;
            if (type == 0) {
                // mBlocks[i] = std::make_shared<Block>(Block::Type::Tree, Resources::roadTextures);
                std::shared_ptr<Block> temp(std::make_shared<Block>(Block::Tree, Resources::roadTextures));
                numBlocks--;
                mBlocks[i] = temp.get(); //
                this->attachChild(std::move(temp)); //
            } else if (type == 1) {
                // mBlocks[i] = std::make_shared<Block>(Block::Type::Rock, Resources::roadTextures);
                std::shared_ptr<Block> temp(std::make_shared<Block>(Block::Rock, Resources::roadTextures));
                numBlocks--;
                mBlocks[i] = temp.get(); //
                this->attachChild(std::move(temp)); //
            } 
            //else if (type == 2) {
            //     mBlocks[i] = std::make_shared<Block>(Block::Type::Bush, Resources::roadTextures);
            //     numBlocks--;
            //} 
            else{
                // mBlocks[i] = std::make_shared<Block>(Block::Type::None, Resources::roadTextures);
            std::shared_ptr<Block> temp(std::make_shared<Block>(Block::None, Resources::roadTextures));
              mBlocks[i] = temp.get(); //
            this->attachChild(std::move(temp)); //S
            
            }
            mBlocks[i]->setScale(Statistic::BLOCK_SIZE / mBlocks[i]->getSpriteBounds().width, Statistic::BLOCK_SIZE / mBlocks[i]->getSpriteBounds().height);
            mBlocks[i]->setOrigin(Statistic::BLOCK_SIZE / 2, Statistic::BLOCK_SIZE / 2);
            // mBlocks[i]->setPosition(x, Statistic::SCREEN_HEIGHT - 100);
            mBlocks[i]->setPosition(x, y);
        }
        x += Statistic::BLOCK_SIZE;
    }

    for(int i = spaces - Statistic::DEFAULT_BLOCK; i < spaces; i++) {
        // mBlocks[i] = std::make_shared<Block>(Block::Type::Tree, Resources::roadTextures);
         std::shared_ptr<Block> temp(std::make_shared<Block>(Block::Tree, Resources::roadTextures));
        mBlocks[i] = temp.get();
        mBlocks[i]->setScale(Statistic::BLOCK_SIZE / mBlocks[i]->getSpriteBounds().width, Statistic::BLOCK_SIZE / mBlocks[i]->getSpriteBounds().height);
        mBlocks[i]->setOrigin(Statistic::BLOCK_SIZE / 2, Statistic::BLOCK_SIZE / 2);
        // mBlocks[i]->setPosition(x, Statistic::SCREEN_HEIGHT - 100);
        mBlocks[i]->setPosition(x, y);
        this->attachChild(std::move(temp));
        x += Statistic::BLOCK_SIZE;
    }
}

void Grass::attachBlocks()
{
    // for(auto& ptr : mBlocks)
    // {
    //     this->attachChild(ptr);
    // }
}