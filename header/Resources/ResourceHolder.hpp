#ifndef RESOURCEHOLDER_HPP
#define RESOURCEHOLDER_HPP

#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>

namespace Textures {
    enum ID {
        PlayButton,
        PlayButtonWhite,
        PlayButtonHovered,
        PauseButton,
        PauseButtonWhite,
        PauseButtonHovered,
        NextButton,
        NextButtonWhite,
        NextButtonHovered,
        PrevButton,
        PrevButtonWhite,
        PrevButtonHovered,
        ReplayButton,
        ReplayButtonWhite,
        ReplayButtonHovered,
        ReturnButton,
        ReturnButtonWhite,
        ReturnButtonHovered
    };
};

namespace Fonts {
    enum ID {
        ComfortaaRegular,
        FiraSansRegular,
        GreatVibesRegular,
        TiltWarpRegular,
        RobotoRegular,
        RobotoItalic,
        RobotoBold,
        RussoOne,
        FiraMonoRegular
    };
};

template <typename Resource, typename Identifier>
class ResourceHolder {
public:
    void load(Identifier id, const std::string& filename);
    Resource& operator [] (Identifier id);
    const Resource& operator [] (Identifier id) const;
private:
    std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
};

#include <Resources/ResourceHolder.inl>
#endif