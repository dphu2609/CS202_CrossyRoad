#include <Resources/Gif.hpp>

Gif::Gif(const std::vector<sf::Texture> &textures, sf::Time duration) {
    mSprites.resize(textures.size());
    for (int i = 0; i < textures.size(); ++i) {
        mSprites[i].setTexture(textures[i]);
    }
    mDuration = duration;
    mElapsedTime = sf::Time::Zero;
    mCurrentSprite = 0;
}

Gif::Gif(const Gif &other) {
    mSprites[0] = other.mSprites[0];
    mDuration = other.mDuration;
    mElapsedTime = other.mElapsedTime;
    mCurrentSprite = other.mCurrentSprite;
}

void Gif::set(const std::vector<sf::Texture> &textures, sf::Time duration) {
    mSprites.resize(textures.size());
    for (int i = 0; i < textures.size(); ++i) {
        mSprites[i].setTexture(textures[i]);
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
