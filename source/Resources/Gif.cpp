#include <Resources/Gif.hpp>

Gif::Gif(const std::vector<sf::Sprite> &sprites, sf::Time duration) {
    for (int i = 0; i < sprites.size(); ++i) {
        mSprites.push_back(sf::Sprite(sprites[i]));
    }
    mDuration = duration;
    mElapsedTime = sf::Time::Zero;
    mCurrentSprite = 0;
}

Gif::Gif(const Gif &other) {
    mSprites = other.mSprites;
    mDuration = other.mDuration;
    mElapsedTime = other.mElapsedTime;
    mCurrentSprite = other.mCurrentSprite;
}

void Gif::set(const std::vector<sf::Sprite> &sprites, sf::Time duration) {
    for (int i = 0; i < sprites.size(); ++i) {
        mSprites.push_back(sf::Sprite(sprites[i]));
    }
    mDuration = duration;
    mElapsedTime = sf::Time::Zero;
    mCurrentSprite = 0;
}

void Gif::set(const Gif &other) {
    mSprites = other.mSprites;
    mDuration = other.mDuration;
    mElapsedTime = other.mElapsedTime;
    mCurrentSprite = other.mCurrentSprite;
}

void Gif::update(sf::Time dt) {
    mElapsedTime += dt;
    if (mElapsedTime >= mDuration) {
        mElapsedTime -= mDuration;
        mCurrentSprite = (mCurrentSprite + 1) % mSprites.size();
    }
}

void Gif::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(mSprites[mCurrentSprite], states);
}

sf::FloatRect Gif::getGlobalBounds() const {
    return getTransform().transformRect(mSprites[mCurrentSprite].getGlobalBounds());
}
