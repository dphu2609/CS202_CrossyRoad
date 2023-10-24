#ifndef MUSICPLAYER_HPP
#define MUSICPLAYER_HPP

#include <SFML/Audio.hpp>
#include <bits/stdc++.h>

namespace Music {
    enum ID {
        MenuTheme,
        MissionTheme
    };
}

class MusicPlayer : private sf::NonCopyable {
public:
    MusicPlayer();
    void load(Music::ID theme, const std::string &filename);
    void play(Music::ID theme);
    void stop();
    void setPaused(bool paused);
    void setVolume(float volume);
private:
    sf::Music mMusic;
    std::map<Music::ID, std::string> mFilenames;
    float mVolume;
};

#include <Resources/MusicPlayer.inl>

#endif