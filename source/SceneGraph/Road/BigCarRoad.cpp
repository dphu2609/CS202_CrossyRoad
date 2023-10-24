#include <SceneGraph/Road/BigCarRoad.hpp>

BigCarRoad::BigCarRoad() {}

BigCarRoad::BigCarRoad(std::vector<std::string> &oldData) {}

bool BigCarRoad::isCollide(const sf::FloatRect &rect) const {
    // for (auto &car : mCar) {
    //     if (car.getGlobalBounds().intersects(rect)) {
    //         return true;
    //     }
    // }
    // return false;
}

std::vector<std::string> BigCarRoad::getData() const {
    return {};
}

void BigCarRoad::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {
    // target.draw(mRoad, states);
    // for (auto &car : mCar) {
    //     target.draw(car, states);
    // }
}

void BigCarRoad::updateCurrent(sf::Time dt) {
    // for (auto &car : mCar) {
    //     car.move(-mCarSpeed * dt.asSeconds(), 0.f);
    //     if (car.getPosition().x < -car.getGlobalBounds().width) {
    //         car.setPosition(1920.f, car.getPosition().y);
    //     }
    // }
} // copilot, not me