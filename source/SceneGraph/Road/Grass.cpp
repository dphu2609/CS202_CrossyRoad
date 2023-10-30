#include <SceneGraph/Road/Grass.hpp>

Grass::Grass()
{

}
Grass::Grass(std::vector<std::string> &oldData)
{

}
bool Grass::isCollide(const sf::FloatRect &rect) const
{
    return true;
}
std::vector<std::string> Grass::getData() const
{
    return {};
}

void Grass::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{

}
void Grass::updateCurrent(sf::Time dt)
{

}