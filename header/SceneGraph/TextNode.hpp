#ifndef TEXTNODE_HPP
#define TEXTNODE_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <SceneGraph/SceneNode.hpp>
#include <GlobalVar.hpp>

class TextNode : public SceneNode {
public:
    explicit TextNode(const sf::Font &font, const std::string &text, const int &size = 100, const sf::Color &color = sf::Color::White);
    void setString(const std::string &text);
private:
    virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
private:
    sf::Text mText;
};

#endif