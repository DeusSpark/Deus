#include <GameCore/Tile.hpp>

#include <Core/Window.hpp>

Tile::Tile()
{
}

Tile::~Tile()
{
}

void Tile::draw(Window& window)
{
    window.draw(m_sprite);
}

void Tile::setTexture(const sf::Texture& texture)
{
    m_sprite.setTexture(texture);
}

void Tile::setTextureRect(const sf::IntRect& rect)
{
    m_sprite.setTextureRect(rect);
}

void Tile::setPosition(const sf::Vector2f& position)
{
    m_sprite.setPosition(position);
}