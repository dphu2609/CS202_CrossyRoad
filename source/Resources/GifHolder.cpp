#include <Resources/GifHolder.hpp>

Gif& GifHolder::operator[] (GIFs::ID id) {
    auto found = mGifs.find(id);   
    if (found == mGifs.end()) {
        throw std::runtime_error("GifHolder::[] - resource not found");
    }
    return *(found->second);
}

const Gif& GifHolder::operator[] (GIFs::ID id) const {
    auto found = mGifs.find(id);
    if (found == mGifs.end()) {
        throw std::runtime_error("GifHolder::[] - resource not found");
    }
    return *(found->second);
}

void GifHolder::load(GIFs::ID id, const std::vector<sf::Sprite> &sprites, sf::Time duration) {
    std::unique_ptr<Gif> gif = std::make_unique<Gif>(sprites, duration);
    mGifs.insert(std::make_pair(id, std::move(gif)));
}