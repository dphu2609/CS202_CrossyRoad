#ifndef SCENENODE_HPP
#define SCENENODE_HPP

#include <SFML/Graphics.hpp>  
#include <SFML/Audio.hpp>
#include <bits/stdc++.h>
#include <CommandQueue.hpp>

struct Command;
class CommandQueue;

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable {
public:
    typedef std::shared_ptr<SceneNode> Ptr;
    SceneNode();
    virtual ~SceneNode() {}

    void attachChild(Ptr child);
    void pushFrontChild(Ptr child);
    Ptr detachChild(const SceneNode& node);
    int getChildIndex(const SceneNode& node);
    void moveChildToIndex(const SceneNode& node, int index);
    void clearChildren();   

    void update(sf::Time dt, CommandQueue& commandQueue);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void handleEvent(sf::RenderWindow &window, sf::Event &event);
private: 
    SceneNode* mParent;
    std::vector<Ptr> mChildren;
private:
    virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {}
    virtual void updateCurrent(sf::Time dt, CommandQueue& commandQueue) {}
    virtual void handleCurrentEvent(sf::RenderWindow &window, sf::Event &event) {}
    void drawBoundingRect(sf::RenderTarget& target, sf::RenderStates) const;
    virtual void resetCurrentView() {}
public:
    void resetView();
public:
    virtual unsigned int getCategory() const {return 0;}
    void onCommand(const Command &command, sf::Time dt);
public: // use for character
    virtual void moveLeft() {}
    virtual void moveRight() {}
    virtual void moveUp() {}
    virtual void moveDown() {}
public: // use for road
    virtual bool isCollide(const sf::FloatRect &rect) const {return false;}
    sf::FloatRect getGlobalBounds() const {return sf::FloatRect();}
public:
    virtual std::vector<std::string> getData() const {return {};}
    sf::Vector2f			getWorldPosition() const;
	sf::Transform			getWorldTransform() const;
    virtual sf::FloatRect	getBoundingRect() const;
public:
    void setEnvSoundVolume(float volume);
private:
    virtual void setCurrentEnvSoundVolume(float volume) {}
    virtual void stopEnvSound() {}
public:
    void stopTotalEnvSound();
};

#endif // SCENENODE_HPP