#include <SceneGraph/Road/RoadSequence.hpp>

RoadSequence::RoadSequence(sf::View &view) : mRoadIndex(0), mView(view) {
    for (int i = 0; i < 6; ++i) {
        std::shared_ptr<Grass> road = std::make_shared<Grass>();
        road->setPosition(0, - i * Statistic::ROAD_HEIGHT);
        mRoads.push_back(road);
        this->pushFrontChild(std::move(road));
    }
    for (int i = 0; i < 30; i++) {
        pushBackRandomRoad();
    }
}   

void RoadSequence::updateCurrent(sf::Time dt, CommandQueue &commands) {
    updateRoads(dt);
}

void RoadSequence::updateRoads(sf::Time dt) {
    if (mRoads.front()->getPosition().y > mView.getCenter().y + mView.getSize().y / 2) {
        popFrontRoad();
        pushBackRandomRoad();
    }
}

void RoadSequence::popFrontRoad() {
    std::shared_ptr<Road> road = mRoads.front();
    detachChild(*road);
    mRoads.erase(mRoads.begin());
}

void RoadSequence::pushBackRandomRoad() {
    int random = rand() % 20;
    if (random < 6) {
        std::shared_ptr<Grass> road = std::make_shared<Grass>();
        road->setPosition(0, mRoads.back()->getPosition().y - Statistic::ROAD_HEIGHT);
        mRoads.push_back(road);
        this->pushFrontChild(std::move(road));
    } else if (random < 16) {
        std::shared_ptr<VehicleLane> lane = std::make_shared<VehicleLane>();
        lane->setPosition(0, mRoads.back()->getPosition().y - Statistic::ROAD_HEIGHT);
        mRoads.push_back(lane);
        this->pushFrontChild(std::move(lane));
    }
    else {
        std::shared_ptr<River> river = std::make_shared<River>();
        river->setPosition(0, mRoads.back()->getPosition().y - Statistic::ROAD_HEIGHT);
        mRoads.push_back(river);
        this->pushFrontChild(std::move(river));
    }

    // add river here
}

void RoadSequence::resetCurrentView() {
    for (auto &road : mRoads) {
        road->setPosition(road->getPosition().x, road->getPosition().y + Statistic::RESET_VIEW_POSITION.y);
    }
}

void RoadSequence::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {}