#include <SceneGraph/Road/Vehicle.hpp>

RoadTextures::ID toTextureID(Vehicle::Type type) {
    switch (type) {
        case Vehicle::SmallCarLeft: {
            return RoadTextures::SmallCarLeft;
        }
        case Vehicle::SmallCarRight: {
            return RoadTextures::SmallCarRight;
        }
        case Vehicle::BigCarLeft: {
            return RoadTextures::BigCarLeft;
        }
        case Vehicle::BigCarRight: {
            return RoadTextures::BigCarRight;
        }
        case Vehicle::TruckLeft: {
            return RoadTextures::TruckLeft;
        }
        case Vehicle::TruckRight: {
            return RoadTextures::TruckRight;
        }
        case Vehicle::TrainLeft: {
            return RoadTextures::TrainLeft;
        }
        case Vehicle::TrainRight: {
            return RoadTextures::TrainRight;
        }
    }
    return RoadTextures::None;
}

Vehicle::Vehicle(Type type, const RoadTextureHolder& textures, int direction)
: mType(type) , mSprite(textures[toTextureID(type)]), mDirection(direction) {
    sf::FloatRect bounds = mSprite.getLocalBounds();    
    this->setScale(Statistic::BLOCK_SIZE / bounds.width, Statistic::BLOCK_SIZE / bounds.height);   //
    bounds = mSprite.getGlobalBounds();  //
    this->setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Vehicle::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
    // states.transform *= getTransform();
    target.draw(mSprite, states);
}

void Vehicle::updateCurrent(sf::Time dt, CommandQueue &commandQueue) {
    move(dt);
}
 
void Vehicle::move(sf::Time dt) {
    float deltaX;
    switch (mType) {
        case SmallCarLeft: {
            deltaX = mSmallCarSpeed * dt.asSeconds() * mDirection;
            break;
        }
        case SmallCarRight: {
            deltaX = mSmallCarSpeed * dt.asSeconds() * mDirection;
            break;
        }
        case BigCarLeft: {
            deltaX = mBigCarSpeed * dt.asSeconds() * mDirection;
            break;
        }
        case BigCarRight: {
            deltaX = mBigCarSpeed * dt.asSeconds() * mDirection;
            break;
        }
        case TruckLeft: {
            deltaX = mTruckSpeed * dt.asSeconds() * mDirection;
            break;
        }
        case TruckRight: {
            deltaX = mTruckSpeed * dt.asSeconds() * mDirection;
            break;
        }
        case TrainLeft: {
            deltaX = mTrainSpeed * dt.asSeconds() * mDirection;
            break;
        }
        case TrainRight: {
            deltaX = mTrainSpeed * dt.asSeconds() * mDirection;
            break;
        }
    }
    this->setPosition(this->getPosition().x + deltaX, this->getPosition().y);  
}

bool Vehicle::isCollide(const sf::FloatRect &rect) const {
    if(mType == None) return false;
    return mSprite.getGlobalBounds().intersects(rect);
}

sf::FloatRect Vehicle::getGlobalBounds() {
    return mSprite.getGlobalBounds();
}

bool Vehicle::isOutOfBound() {
    if (mDirection == -1) {
        return this->getPosition().x < -Statistic::SCREEN_WIDTH / 2 - Statistic::BLOCK_SIZE * 3;
    } else {
        return this->getPosition().x > Statistic::SCREEN_WIDTH / 2 + Statistic::BLOCK_SIZE * 3;
    }
}