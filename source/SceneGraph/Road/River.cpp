#include <SceneGraph/Road/River.hpp>
#include <random>

River::River() 
: areas(3)
,currentArea(1)
,spawnTime(sf::seconds(2.5f))
{
    for(int i = 0; i < Count; i++)
    {
        SceneNode::Ptr layer(new SceneNode());
        mSceneLayers[i] = layer.get();
        this->attachChild(std::move(layer));
    }
    std::shared_ptr <RiverArea> area1(std::make_shared<RiverArea>(RiverArea::Accelerate, Resources::roadTextures));
    areas[0] = area1.get();
    std::shared_ptr <RiverArea> area2(std::make_shared<RiverArea>(RiverArea::Uniform, Resources::roadTextures));
    areas[1] = area2.get();
    std::shared_ptr <RiverArea> area3(std::make_shared<RiverArea>(RiverArea::Accelerate, Resources::roadTextures));
    areas[2] = area3.get();
    area1->setPosition(-1.f * Statistic::ROAD_WIDTH / 4 - Statistic::ROAD_WIDTH / 8 , 0.f);
    area2->setPosition(0.f, 0.f);
    area3->setPosition(Statistic::ROAD_WIDTH / 4 + Statistic::ROAD_WIDTH / 8, 0.f);

    direction = (rand() % 2) ? 1 : -1;
    int speed = Statistic::MIN_RIVER_SPEED.x + rand() % (int)(Statistic::MAX_RIVER_SPEED.x - Statistic::MIN_RIVER_SPEED.x);

    area1->setDirection(direction);
    area2->setDirection(direction);
    area3->setDirection(direction);

    area1->setSpeed(sf::Vector2f(speed + Statistic::ADDING_RIVER_SPEED.x, 0));
    area2->setSpeed(sf::Vector2f(speed, 0));
    area3->setSpeed(sf::Vector2f(speed + Statistic::ADDING_RIVER_SPEED.x, 0));

    mSceneLayers[AreaLayer]->attachChild(std::move(area1));
    mSceneLayers[AreaLayer]->attachChild(std::move(area2));
    mSceneLayers[AreaLayer]->attachChild(std::move(area3));

}

void River::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
   
}
void River::updateCurrent(sf::Time dt, CommandQueue& commands)
{
    spawnWood();
    removeWood();
    for(auto& wood : woods)
    {
        areas[currentArea]->accelerate(wood, dt);
    }
}

void River::spawnWood()
{
    if(spawnClock.getElapsedTime() > spawnTime || woods.size() == 0)
    {
        std::shared_ptr<Wood> wood(std::make_shared<Wood>(Resources::roadTextures, Statistic::MAXIMUM_WOOD_LENGTH));
        if(direction == 1)
            wood->setPosition(-1.f * Statistic::ROAD_WIDTH / 2 - (Statistic::MINIMUM_WOOD_LENGTH + Statistic::MAXIMUM_WOOD_LENGTH) / 2, 0);
        else
            wood->setPosition(Statistic::ROAD_WIDTH / 2 + (Statistic::MINIMUM_WOOD_LENGTH + Statistic::MAXIMUM_WOOD_LENGTH) / 2, 0);
        woods.push_back(wood.get());
        mSceneLayers[WoodLayer]->attachChild(std::move(wood));
        spawnClock.restart();
    }
}

void River::removeWood()
{
    if(woods.size() == 0)
        return;

    if(woods[0]->getPosition().x > Statistic::ROAD_WIDTH / 2 + (Statistic::MINIMUM_WOOD_LENGTH + Statistic::MAXIMUM_WOOD_LENGTH) / 2 || woods[0]->getPosition().x < -1.f * Statistic::ROAD_WIDTH / 2 - (Statistic::MINIMUM_WOOD_LENGTH + Statistic::MAXIMUM_WOOD_LENGTH) / 2)
    {
        mSceneLayers[WoodLayer]->detachChild(*woods[0]);
        woods.erase(woods.begin());
    }
}

