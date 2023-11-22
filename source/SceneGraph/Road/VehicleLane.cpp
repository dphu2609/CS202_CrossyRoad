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

void VehicleLane::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(mRoadSprite, states);
    for (Vehicle *vehicle : mVehicles) {
        target.draw(*vehicle, states);
    }
}

void VehicleLane::updateCurrent(sf::Time dt, CommandQueue &commandQueue) {
    vehicleControl(dt);
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
        this->attachChild(std::move(vehicle));
        mSpawnTimer.restart();
    }
    while (!mVehicles.empty() && mVehicles.front()->isOutOfBound()) {
        detachChild(*mVehicles.front());
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
