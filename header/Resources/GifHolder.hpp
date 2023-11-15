#ifndef GIF_HOLDER_HPP
#define GIF_HOLDER_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <Resources/Gif.hpp>

namespace GIFs {
    enum ID {
        CharacterSkin1Forward,
        CharacterSkin1Backward,
        CharacterSkin1Left,
        CharacterSkin1Right
    };
};

class GifHolder {
private:
    std::map<GIFs::ID, std::unique_ptr<Gif>> mGifs;
public:
    Gif& operator[] (GIFs::ID id);
    const Gif& operator[] (GIFs::ID id) const;
    void load(GIFs::ID id, const std::vector<sf::Texture> &textures, sf::Time duration);
};

#endif