#include <SceneGraph/Road/RoadSequence.hpp>

RoadSequence::RoadSequence(sf::View &view) : mCurrentRoadIndex(0), mView(view) {
    for (int i = 0; i < 6; ++i) {
        std::shared_ptr<Grass> road = std::make_shared<Grass>();
        road->setPosition(0, - i * Statistic::ROAD_HEIGHT);
        mRoads.insert(mRoads.begin(), road);
        this->pushFrontChild(std::move(road));
    }
    for (int i = 0; i < 40; i++) {
        pushBackRandomRoad();
    }

    mCurrentRoadIndex = 43;
    std::shared_ptr<Character> character = std::make_shared<Character>(mView, mCurrentRoadIndex);
    character->setPosition(22.f, - Statistic::ROAD_HEIGHT * 3 - 20);
    character->setScale(Statistic::CHARACTER_SIZE.x / character->getSpriteBounding().width, Statistic::CHARACTER_SIZE.y / character->getSpriteBounding().height);
    mCharacter = character;
    this->attachChild(std::move(character));
    this->moveChildToIndex(*mCharacter, mCurrentRoadIndex);
}   

void RoadSequence::updateCurrent(sf::Time dt, CommandQueue &commands) {
    updateRoads(dt);
    roadIndexControl();
    gameControl(dt);
}

void RoadSequence::roadIndexControl() {
    if (mCharacter->getCurrentRoadIndex() != mCurrentRoadIndex) {
        mCurrentRoadIndex = mCharacter->getCurrentRoadIndex();
        this->moveChildToIndex(*mCharacter, mCurrentRoadIndex);
    }
}

void RoadSequence::updateRoads(sf::Time dt) {
    if (mRoads.back()->getPosition().y > mView.getCenter().y + mView.getSize().y / 2) {
        popFrontRoad();
        pushBackRandomRoad();
        mCharacter->increaseCurrentRoadIndex();
    }
}

void RoadSequence::popFrontRoad() {
    std::shared_ptr<Road> road = mRoads.back();
    detachChild(*road);
    mRoads.pop_back();
}

void RoadSequence::pushBackRandomRoad() {
    int random = rand() % 20;
    if (random < 6) {
        std::shared_ptr<Grass> road = std::make_shared<Grass>();
        road->setPosition(0, mRoads.front()->getPosition().y - Statistic::ROAD_HEIGHT);
        mRoads.insert(mRoads.begin(), road);
        this->pushFrontChild(std::move(road));
    } else if (random < 16) {
        std::shared_ptr<VehicleLane> lane = std::make_shared<VehicleLane>();
        lane->setPosition(0, mRoads.front()->getPosition().y - Statistic::ROAD_HEIGHT);
        mRoads.insert(mRoads.begin(), lane);
        this->pushFrontChild(std::move(lane));
    }
    else {
        std::shared_ptr<River> river = std::make_shared<River>();
        river->setPosition(0, mRoads.front()->getPosition().y - Statistic::ROAD_HEIGHT);
        mRoads.insert(mRoads.begin(), river);
        this->pushFrontChild(std::move(river));
    }
}

void RoadSequence::resetCurrentView() {
    for (auto &road : mRoads) {
        road->setPosition(road->getPosition().x, road->getPosition().y + Statistic::RESET_VIEW_POSITION.y);
    }
    mCharacter->setPosition(mCharacter->getPosition().x, mCharacter->getPosition().y + Statistic::RESET_VIEW_POSITION.y);
}

void RoadSequence::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {}

void RoadSequence::gameControl(sf::Time dt) {
    if (mRoads[mCurrentRoadIndex - 1]->isHitDangerousObjects(mCharacter->getBoundingRect())) {
        std::cout << "Hit dangerous objects" << std::endl;
        return;
    }

    if (mRoads[mCurrentRoadIndex - 1]->getRoadType() == RoadType::River) {
        mCharacter->move(dt.asSeconds() * mRoads[mCurrentRoadIndex - 1]->getVelocity());
        isInRiver = true;
    }
    // } else if (isInRiver) {
    //     // float dx = mCharacter->getPosition().x - oldPos;
    //     // int index = dx / Statistic::CHARACTER_JUMP_DISTANCE_HORIZONTAL;
    //     // float newDx = index * Statistic::CHARACTER_JUMP_DISTANCE_HORIZONTAL;
    //     mCharacter->move(200 , 0);
    //     std::cout << "Out of river" << std::endl;
    //     isInRiver = false;
    // } else
    // {
    //     oldPos = mCharacter->getPosition().x;
    // }
    if(mRoads[mCurrentRoadIndex - 1]->getRoadType() != RoadType::River && isInRiver) {
        mCharacter->setPosition(0, mCharacter->getPosition().y);
        std::cout << "Out of river" << std::endl;
        isInRiver = false;
    }


    sf::FloatRect characterBounding = mCharacter->getBoundingRect();
    sf::FloatRect ifMoveLeft = characterBounding;
    ifMoveLeft.left -= Statistic::CHARACTER_JUMP_DISTANCE_HORIZONTAL;
    sf::FloatRect ifMoveRight = characterBounding;
    ifMoveRight.left += Statistic::CHARACTER_JUMP_DISTANCE_HORIZONTAL;
    sf::FloatRect ifMoveUp = characterBounding;
    ifMoveUp.top -= Statistic::CHARACTER_JUMP_DISTANCE_VERTICAL;
    sf::FloatRect ifMoveDown = characterBounding;
    ifMoveDown.top += Statistic::CHARACTER_JUMP_DISTANCE_VERTICAL;
    if(mRoads[mCurrentRoadIndex - 1]->isCollide(ifMoveLeft)) {
        mCharacter->canMoveLeft = false;
    } else {
        mCharacter->canMoveLeft = true;
    }
    if(mRoads[mCurrentRoadIndex - 1]->isCollide(ifMoveRight)) {
        mCharacter->canMoveRight = false;
    } else {
        mCharacter->canMoveRight = true;
    }
    if(mRoads[mCurrentRoadIndex - 2]->isCollide(ifMoveUp)) {
        mCharacter->canMoveUp = false;
    } else {
        mCharacter->canMoveUp = true;
    }
    if(mRoads[mCurrentRoadIndex]->isCollide(ifMoveDown)) {
        mCharacter->canMoveDown = false;
    } else {
        mCharacter->canMoveDown = true;
    }
}

int RoadSequence::getPlayerScore() {
    if (mCharacter->getLanePassed() > mPlayerScore) {
        mPlayerScore = mCharacter->getLanePassed();
    }
    return mPlayerScore;
}

void RoadSequence::writeData(std::ofstream &file) {
    file << this->getPosition().x << " " << this->getPosition().y << std::endl;
    file << mCurrentRoadIndex << std::endl;
    file << mRoads.size() << std::endl;
    
    for (int i = 0; i < mCurrentRoadIndex; i++) {
        file << mRoads[i]->getRoadType() << std::endl;
        mRoads[i]->writeData(file);
    }
    mCharacter->writeData(file);

    for (int i = mCurrentRoadIndex; i < mRoads.size(); i++) {
        file << mRoads[i]->getRoadType() << std::endl;
        mRoads[i]->writeData(file);
    }
}

void RoadSequence::readData(std::ifstream &file) {
    float x, y;
    file >> x >> y;
    this->setPosition(x, y);
    file >> mCurrentRoadIndex;
    int size;
    file >> size;
    mRoads.clear();
    this->clearChildren();
    for (int i = 0; i < mCurrentRoadIndex; i++) {
        int type;
        file >> type;
        std::shared_ptr<Grass> road;
        std::shared_ptr<VehicleLane> lane;
        std::shared_ptr<River> river;

        switch(type) {
            case RoadType::Grass:
                road = std::make_shared<Grass>(file);
                mRoads.push_back(road);
                this->attachChild(std::move(road));
                break;
            case RoadType::VehicleLane:
                lane = std::make_shared<VehicleLane>(file);
                mRoads.push_back(lane);
                this->attachChild(std::move(lane));
                break;
            case RoadType::River:
                river = std::make_shared<River>(file);
                mRoads.push_back(river);
                this->attachChild(std::move(river));
                break;
        };
    }

    std::shared_ptr<Character> character = std::make_shared<Character>(mView, file);
    mCharacter = character;
    this->attachChild(std::move(character));

    for (int i = mCurrentRoadIndex; i < size; i++) {
        int type;
        file >> type;
        std::shared_ptr<Grass> road;
        std::shared_ptr<VehicleLane> lane;
        std::shared_ptr<River> river;

        switch(type) {
            case RoadType::Grass:
                road = std::make_shared<Grass>(file);
                mRoads.push_back(road);
                this->attachChild(std::move(road));
                break;
            case RoadType::VehicleLane:
                lane = std::make_shared<VehicleLane>(file);
                mRoads.push_back(lane);
                this->attachChild(std::move(lane));
                break;
            case RoadType::River:
                river = std::make_shared<River>(file);
                mRoads.push_back(river);
                this->attachChild(std::move(river));
                break;
        };
    }
}