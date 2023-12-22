#ifndef RESOURCEHOLDER_HPP
#define RESOURCEHOLDER_HPP

#include <bits/stdc++.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

namespace RoadTextures
{
    enum ID
    {
        Grass,
        Tree,
        Rock,
        Bush,
        Wood,
        UniformWater,
        AccelerateWater,
        SmallCarLeft,
        SmallCarRight,
        BigCarLeft,
        BigCarRight,
        TruckLeft,
        TruckRight,
        TrainLeft,
        TrainRight,
        TrafficLightRed,
        TrafficLightYellow,
        TrafficLightGreen,
        Road,
        Rail,
        None
    };
};

namespace CharacterTextures {
    enum ID {
        CharacterSkin1ForwardState1,
        CharacterSkin1ForwardState2,
        CharacterSkin1ForwardState3,
        CharacterSkin1ForwardState4,
        CharacterSkin1BackwardState1,
        CharacterSkin1BackwardState2,
        CharacterSkin1BackwardState3,
        CharacterSkin1BackwardState4,
        CharacterSkin1LeftState1,
        CharacterSkin1LeftState2,
        CharacterSkin1LeftState3,
        CharacterSkin1LeftState4,
        CharacterSkin1RightState1,
        CharacterSkin1RightState2,
        CharacterSkin1RightState3,
        CharacterSkin1RightState4
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
        PixelifySansRegular,
        JoystixMonospaceRegular,
        FiraMonoRegular
    };
};

namespace MenuTextures {
    enum ID {
        BackGroundLight,
        BackGroundDark,
        Return,
        ReturnDark
    };
};

namespace Sounds {
    enum ID {
        JumpSound,
        CarSound,
        TrainAlarmSound,
        TrainSound,
        TrafficSound,
        BackgroundMusic
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