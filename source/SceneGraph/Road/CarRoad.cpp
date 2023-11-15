// #include <SceneGraph/Road/CarRoad.hpp>

// CarRoad::CarRoad() {
//     Resources::roadTextures[RoadTextures::Road].setRepeated(true);
//     mRoadSprite.setTexture(Resources::roadTextures[RoadTextures::Grass]);
//     mRoadSprite.setTextureRect(sf::IntRect(0, 0, Statistic::ROAD_WIDTH, Statistic::ROAD_HEIGHT));

//     mType = rand() % Type::Count;
//     mDirection = rand() % 2;
//     if (mDirection == 0) {
//         mDirection = -1;
//     }
// }

// void CarRoad::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {
//     target.draw(mRoadSprite, states);
// }


// void CarRoad::vehicleGenerator() {
// }

// void CarRoad::vehicleController() {

// }