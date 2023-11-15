#include <SceneGraph/Road/CarRoad.hpp>

Vehicle::Type toVehicleType(int type) {
    switch (type) {
        case CarRoad::SmallCarLeft :
            return Vehicle::SmallCarLeft;
        case CarRoad::SmallCarRight :
            return Vehicle::SmallCarRight;
        case CarRoad::BigCarLeft :
            return Vehicle::BigCarLeft;
        case CarRoad::BigCarRight :
            return Vehicle::BigCarRight;
        case CarRoad::TruckLeft :
            return Vehicle::TruckLeft;
        case CarRoad::TruckRight :
            return Vehicle::TruckRight;
        case CarRoad::TrainLeft:
            return Vehicle::TrainLeft;
        case CarRoad::TrainRight :
            return Vehicle::TrainRight;
    }
    return Vehicle::None;
}

CarRoad::CarRoad() {
    Resources::roadTextures[RoadTextures::Road].setRepeated(true);
    mRoadSprite.setTexture(Resources::roadTextures[RoadTextures::Road]);
    mRoadSprite.setTextureRect(sf::IntRect(0, 0, Statistic::ROAD_WIDTH, Statistic::ROAD_HEIGHT));
    mRoadSprite.setOrigin(Statistic::ROAD_WIDTH / 2, Statistic::ROAD_HEIGHT / 2);

    mType = rand() % Type::TrainLeft;

    switch (mType) {
        case SmallCarLeft :
            mDirection = -1;
            break;
        case SmallCarRight :
            mDirection = 1;
            break;
        case BigCarLeft :
            mDirection = -1;
            break;
        case BigCarRight :
            mDirection = 1;
            break;
        case TruckLeft :
            mDirection = -1;
            break;
        case TruckRight :
            mDirection = 1;
            break;
        case TrainLeft:
            mDirection = -1;
            break;
        case TrainRight :
            mDirection = 1;
            break;
    }
}

void CarRoad::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(mRoadSprite, states);
    for (Vehicle *vehicle : mVehicles) {
        target.draw(*vehicle, states);
    }
}

void CarRoad::updateCurrent(sf::Time dt, CommandQueue &commandQueue) {
    vehicleControl(dt);
}

void CarRoad::vehicleControl(sf::Time dt) {
    float spawnTime;
    switch (mType) {
        case SmallCarLeft: {
            spawnTime = mSmallCarSpawnTime;
            break;
        }
        case SmallCarRight: {
            spawnTime = mSmallCarSpawnTime;
            break;
        }
        case BigCarLeft: {
            spawnTime = mBigCarSpawnTime;
            break;
        }
        case BigCarRight: {
            spawnTime = mBigCarSpawnTime;
            break;
        }
        case TruckLeft: {
            spawnTime = mTruckSpawnTime;
            break;
        }
        case TruckRight: {
            spawnTime = mTruckSpawnTime;
            break;
        }
        case TrainLeft: {
            spawnTime = mTrainSpawnTime;
            break;
        }
        case TrainRight: {
            spawnTime = mTrainSpawnTime;
            break;
        }
    }
    if (mSpawnTimer.getElapsedTime().asSeconds() > spawnTime) {
        std::shared_ptr<Vehicle> vehicle = std::make_shared<Vehicle>(toVehicleType(mType), Resources::roadTextures, mDirection);
        vehicle->setPosition(-mDirection * (Statistic::ROAD_WIDTH / 2 + Statistic::BLOCK_SIZE), 0);
        mVehicles.push_back(vehicle.get());
        this->attachChild(std::move(vehicle));
        mSpawnTimer.restart();
    }
    while (!mVehicles.empty() && mVehicles.front()->isOutOfBound()) {
        detachChild(*mVehicles.front());
        mVehicles.erase(mVehicles.begin());
    } 

    

    // if (!mVehicles.empty()) {
    //     std::cout << mVehicles.front()->getPosition().x << " " << mVehicles.front()->getPosition().y << std::endl;
    // }
}
