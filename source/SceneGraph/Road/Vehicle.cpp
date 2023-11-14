#include <SceneGraph/Road/Vehicle.hpp>

RoadTextures::ID toTextureID(Vehicle::Type type) {
    switch (type) {
    case Vehicle::SmallCar:
        return RoadTextures::SmallCar;
    case Vehicle::BigCar:
        return RoadTextures::BigCar;
    case Vehicle::Truck:
        return RoadTextures::Truck;
    case Vehicle::Train:
        return RoadTextures::Train;
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
    target.draw(mSprite, states);
}

void Vehicle::updateCurrent(sf::Time dt, CommandQueue &commandQueue) {
    move(dt);
}
 
void Vehicle::move(sf::Time dt) {
    float deltaX;
    switch (mType) {
        case SmallCar: {
            deltaX = Statistic::SMALL_CAR_SPEED * dt.asSeconds() * mDirection;
            break;
        }
        case BigCar: {
            deltaX = Statistic::BIG_CAR_SPEED * dt.asSeconds() * mDirection;
            break;
        }
        case Truck: {
            deltaX = Statistic::TRUCK_SPEED * dt.asSeconds() * mDirection;
            break;
        }
        case Train: {
            deltaX = Statistic::TRAIN_SPEED * dt.asSeconds() * mDirection;
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