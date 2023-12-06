#include <SceneGraph/Road/VehicleLane.hpp>

Vehicle::Type toVehicleType(int type) {
    switch (type) {
        case VehicleLane::SmallCarLeft :
            return Vehicle::SmallCarLeft;
        case VehicleLane::SmallCarRight :
            return Vehicle::SmallCarRight;
        case VehicleLane::BigCarLeft :
            return Vehicle::BigCarLeft;
        case VehicleLane::BigCarRight :
            return Vehicle::BigCarRight;
        case VehicleLane::TruckLeft :
            return Vehicle::TruckLeft;
        case VehicleLane::TruckRight :
            return Vehicle::TruckRight;
        case VehicleLane::TrainLeft:
            return Vehicle::TrainLeft;
        case VehicleLane::TrainRight :
            return Vehicle::TrainRight;
    }
    return Vehicle::None;
}

VehicleLane::VehicleLane() {
    mType = rand() % Type::Count;
    mSceneLayers[RoadLayer] = new SceneNode();
    mSceneLayers[VehicleLayer] = new SceneNode();
    mSceneLayers[TrafficLightLayer] = new SceneNode();
    for (int i = 0; i < CountLayer; ++i) {
        this->attachChild(std::unique_ptr<SceneNode>(mSceneLayers[i]));
    }
    switch (mType) {
        case SmallCarLeft: 
        case SmallCarRight:
        case BigCarLeft: 
        case BigCarRight:
        case TruckLeft: 
        case TruckRight: {
            Resources::roadTextures[RoadTextures::Road].setRepeated(true);
            std::shared_ptr<SpriteNode> roadSprite = std::make_shared<SpriteNode>(Resources::roadTextures[RoadTextures::Road]);
            roadSprite->setTextureRect(sf::IntRect(0, 0, Statistic::ROAD_WIDTH, Statistic::ROAD_HEIGHT));
            roadSprite->setOrigin(Statistic::ROAD_WIDTH / 2, Statistic::ROAD_HEIGHT / 2);
            mSceneLayers[RoadLayer]->attachChild(std::move(roadSprite));
            break;
        }
        case TrainLeft: 
        case TrainRight: {
            Resources::roadTextures[RoadTextures::Rail].setRepeated(true);
            std::shared_ptr<SpriteNode> roadSprite = std::make_shared<SpriteNode>(Resources::roadTextures[RoadTextures::Rail]);
            roadSprite->setTextureRect(sf::IntRect(0, 0, Statistic::ROAD_WIDTH, Statistic::ROAD_HEIGHT));
            roadSprite->setOrigin(Statistic::ROAD_WIDTH / 2, Statistic::ROAD_HEIGHT / 2);
            mSceneLayers[RoadLayer]->attachChild(std::move(roadSprite));


            std::shared_ptr<SpriteNode> trafficLight = std::make_shared<SpriteNode>(Resources::roadTextures[RoadTextures::TrafficLightRed]);
            mTrafficLights.push_back(trafficLight);
            mSceneLayers[TrafficLightLayer]->attachChild(std::move(trafficLight));

            std::shared_ptr<SpriteNode> trafficLight2 = std::make_shared<SpriteNode>(Resources::roadTextures[RoadTextures::TrafficLightYellow]);
            mTrafficLights.push_back(trafficLight2);

            std::shared_ptr<SpriteNode> trafficLight3 = std::make_shared<SpriteNode>(Resources::roadTextures[RoadTextures::TrafficLightGreen]);
            mTrafficLights.push_back(trafficLight3);

            mTrafficLights[0]->setOrigin(mTrafficLights[0]->getGlobalBounds().width / 2, mTrafficLights[0]->getGlobalBounds().height / 2);
            mTrafficLights[1]->setOrigin(mTrafficLights[1]->getGlobalBounds().width / 2, mTrafficLights[1]->getGlobalBounds().height / 2);
            mTrafficLights[2]->setOrigin(mTrafficLights[2]->getGlobalBounds().width / 2, mTrafficLights[2]->getGlobalBounds().height / 2);

            mTrafficLights[0]->setScale(Statistic::TRAFFIC_LIGHT_SIZE.x / mTrafficLights[0]->getGlobalBounds().width, Statistic::TRAFFIC_LIGHT_SIZE.y / mTrafficLights[0]->getGlobalBounds().height);
            mTrafficLights[1]->setScale(Statistic::TRAFFIC_LIGHT_SIZE.x / mTrafficLights[1]->getGlobalBounds().width, Statistic::TRAFFIC_LIGHT_SIZE.y / mTrafficLights[1]->getGlobalBounds().height);
            mTrafficLights[2]->setScale(Statistic::TRAFFIC_LIGHT_SIZE.x / mTrafficLights[2]->getGlobalBounds().width, Statistic::TRAFFIC_LIGHT_SIZE.y / mTrafficLights[2]->getGlobalBounds().height);

            int randomTrafficLightPosition = rand() % 2;
            if (randomTrafficLightPosition == 0) {
                mTrafficLights[0]->setPosition(- Statistic::ROAD_WIDTH / 2 + 350, -15);
                mTrafficLights[1]->setPosition(- Statistic::ROAD_WIDTH / 2 + 350, -15);
                mTrafficLights[2]->setPosition(- Statistic::ROAD_WIDTH / 2 + 350, -15);
            } else {
                mTrafficLights[0]->setPosition(Statistic::ROAD_WIDTH / 2 - 350, -15);
                mTrafficLights[1]->setPosition(Statistic::ROAD_WIDTH / 2 - 350, -15);
                mTrafficLights[2]->setPosition(Statistic::ROAD_WIDTH / 2 - 350, -15);
            }
            mTrafficLightState = 0;
        }
    }

    switch (mType) {
        case SmallCarLeft :
        case BigCarLeft :
        case TruckLeft :
        case TrainLeft :
            mDirection = -1;
            break;
        case SmallCarRight :
        case BigCarRight :
        case TruckRight :
        case TrainRight : 
            mDirection = 1;
            break;
    }
}

void VehicleLane::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {}

void VehicleLane::updateCurrent(sf::Time dt, CommandQueue &commandQueue) {
    vehicleControl(dt);
    if (mType == TrainLeft || mType == TrainRight) trafficLightControl(dt);
}

void VehicleLane::vehicleControl(sf::Time dt) {
    float spawnTime;
    switch (mType) {
        case SmallCarLeft: 
        case SmallCarRight: {
            spawnTime = mSmallCarSpawnTime;
            break;
        }
        case BigCarLeft: 
        case BigCarRight: {
            spawnTime = mBigCarSpawnTime;
            break;
        }
        case TruckLeft: 
        case TruckRight: {
            spawnTime = mTruckSpawnTime;
            break;
        }
        case TrainLeft: 
        case TrainRight: {
            spawnTime = mTrainSpawnTime;
            break;
        }
    }
    if (mSpawnTimer.getElapsedTime().asSeconds() > spawnTime || mVehicles.size() == 0) {
        std::shared_ptr<Vehicle> vehicle = std::make_shared<Vehicle>(toVehicleType(mType), Resources::roadTextures, mDirection);
        vehicle->setPosition(-mDirection * (Statistic::ROAD_WIDTH / 2 + vehicle->getGlobalBounds().width), 0);
        mVehicles.push_back(vehicle.get());
        mSceneLayers[VehicleLayer]->attachChild(std::move(vehicle));
        mSpawnTimer.restart();
    }
    while (!mVehicles.empty() && mVehicles.front()->isOutOfBound()) {
        mSceneLayers[VehicleLayer]->detachChild(*mVehicles.front());
        mVehicles.erase(mVehicles.begin());
    } 
}

bool VehicleLane::isHitDangerousObjects(const sf::FloatRect &bounds) const {
    for (auto &vehicle : mVehicles) {
        if (vehicle->getBoundingRect().intersects(bounds)) {
            return true;
        }
    }
    return false;
}

void VehicleLane::readData(std::ifstream &file) {
    std::vector<std::vector<float>> pos;
    int size;
    file >> mType >> mDirection >> size;
    for (int i = 0; i < size; ++i) {
        pos.push_back(std::vector<float>());
        float x, y;
        file >> x >> y;
        pos.back().push_back(x);
        pos.back().push_back(y);
    }

    switch (mType) {
        case SmallCarLeft: 
        case SmallCarRight:
        case BigCarLeft: 
        case BigCarRight:
        case TruckLeft: 
        case TruckRight: {
            Resources::roadTextures[RoadTextures::Road].setRepeated(true);
            mRoadSprite.setTexture(Resources::roadTextures[RoadTextures::Road]);
            mRoadSprite.setTextureRect(sf::IntRect(0, 0, Statistic::ROAD_WIDTH, Statistic::ROAD_HEIGHT));
            mRoadSprite.setOrigin(Statistic::ROAD_WIDTH / 2, Statistic::ROAD_HEIGHT / 2);
            break;
        }
        case TrainLeft: 
        case TrainRight: {
            Resources::roadTextures[RoadTextures::Rail].setRepeated(true);
            mRoadSprite.setTexture(Resources::roadTextures[RoadTextures::Rail]);
            mRoadSprite.setTextureRect(sf::IntRect(0, 0, Statistic::ROAD_WIDTH, Statistic::ROAD_HEIGHT));
            mRoadSprite.setOrigin(Statistic::ROAD_WIDTH / 2, Statistic::ROAD_HEIGHT / 2);
        }
    }

    for (int i = 0; i < size; ++i) {
        std::shared_ptr<Vehicle> vehicle = std::make_shared<Vehicle>(toVehicleType(mType), Resources::roadTextures, mDirection);
        vehicle->setPosition(pos[i][0], pos[i][1]);
        mVehicles.push_back(vehicle.get());
        mSceneLayers[VehicleLayer]->attachChild(std::move(vehicle));
    }
}

void VehicleLane::writeData(std::ofstream &file) {
    file << mType << " " << mDirection << " " << mVehicles.size() << std::endl;
    for (auto &vehicle : mVehicles) {
        file << vehicle->getPosition().x << " " << vehicle->getPosition().y << std::endl;
    }
}

void VehicleLane::trafficLightControl(sf::Time dt) {
    mSceneLayers[TrafficLightLayer]->clearChildren();
    if (mSpawnTimer.getElapsedTime().asSeconds() < 1.f) {
        mSceneLayers[TrafficLightLayer]->attachChild(mTrafficLights[0]);
    }
    else if (mSpawnTimer.getElapsedTime().asSeconds() < 2.25) {
        mSceneLayers[TrafficLightLayer]->attachChild(mTrafficLights[2]);
    }
    else if (mSpawnTimer.getElapsedTime().asSeconds() < 3.f) {
        mSceneLayers[TrafficLightLayer]->attachChild(mTrafficLights[1]);
    }
    else {
        mSceneLayers[TrafficLightLayer]->attachChild(mTrafficLights[0]);
    }
}