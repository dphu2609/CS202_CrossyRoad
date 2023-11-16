#ifndef RIVER_HPP
#define RIVER_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <SceneGraph/SceneNode.hpp>
#include <GlobalVar.hpp>

typedef ResourceHolder<sf::Texture, RoadTextures::ID> RoadTextureHolder;

class Wood : public SceneNode
{
    private:
    Sprite mSprite;
    public:
    sf::FloatRect getSpriteBounds() const { return mSprite.getGlobalBounds(); }
    sf::FloatRect getBoundingRect() const { return getWorldTransform().transformRect(mSprite.getGlobalBounds()); }
    bool isCollide(const sf::FloatRect& rect) const ;
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
}

class RiverArea : public SceneNode
{
    public:
    enum Type
    {
        uniform,
        accelerate
    }
    private:
    sf::Sprite mSprite;
    Type mType;
    sf::Vector2f waterSpeed;
    int direction;
    public:
    RiverArea(Type type, const RoadTextureHolder& textures);
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const; 
    void accelerate(Wood& wood);
}

class River : public SceneNode {
private:
    // sf::Sprite accelerateSprite;
    // sf::Sprite uniformSprite;
    enum Layer
    {
        AreaLayer,
        WoodLayer,
        count
    }
    std::vector<RiverArea*> areas;
    std::vector<Wood*> woods;
    int currentArea;
    int direction;
    sf::seconds spawnTime;
private:
    River();
    virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
    virtual void updateCurrent(sf::Time dt);
public:


};

River::River() : areas(3)
{
    // for(int i = 0; i < 5; i++)
    // {
    //     areas.push_back(new RiverArea(RiverArea::uniform, Resources::roadTextures));
    //     areas[i]->setPosition(Statistic::SCREEN_WIDTH / 2, Statistic::SCREEN_HEIGHT / 2);
    //     this->attachChild(areas[i]);
    // }
    std::unique_ptr <RiverArea> area1(new RiverArea(RiverArea::accelerate, Resources::roadTextures));
    areas[0] = area1.get();
    std::unique_ptr <RiverArea> area2(new RiverArea(RiverArea::uniform, Resources::roadTextures));
    areas[1] = area2.get();
    std::unique_ptr <RiverArea> area3(new RiverArea(RiverArea::accelerate, Resources::roadTextures));
    areas[2] = area3.get();
    float width = Statistic::ROAD_WIDTH / 4;
    int x = -1.f * Statistic::ROAD_WIDTH / 2 + width / 2;
    for(auto& area : areas)
    {
        area->setPosition(x, 0);
        x += width;
        this->attachChild(std::move(area));
    }

}



#endif