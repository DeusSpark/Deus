#include <GameCore/Tile.hpp>

#include <Core/Window.hpp>

Tile::Tile() : m_needDraw(false)
{
}

Tile::~Tile()
{
}

void Tile::draw(Window& window)
{
    if (m_needDraw)
        window.draw(m_sprite);
}

bool Tile::needDraw() const
{
    return m_needDraw;
}

const sf::IntRect& Tile::getTextureRect() const
{
    return m_sprite.getTextureRect();
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

void Tile::setNeedDraw(bool needDraw)
{
    m_needDraw = needDraw;
}