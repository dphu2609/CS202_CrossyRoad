#include <SceneGraph/TextNode.hpp>

TextNode::TextNode(const sf::Font &font, const std::string &text, const int &size, const sf::Color &color) {
    mText.setFont(font);
    mText.setString(text);
    mText.setCharacterSize(size);
    mText.setFillColor(color);
}

void TextNode::setString(const std::string &text) {
    mText.setString(text);
}

void TextNode::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(mText, states);
}
