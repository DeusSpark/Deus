#pragma once

#include <SFML/Graphics/Sprite.hpp>

class Window;

class Tile
{
public:
    Tile();
    ~Tile();

    void draw(Window& window);

    bool needDraw() const;

    const sf::IntRect& getTextureRect() const;

    void setTexture(const sf::Texture& texture);
    void setTextureRect(const sf::IntRect& rect);
    void setPosition(const sf::Vector2f& position);
    void setNeedDraw(bool needDraw);

private:
    sf::Sprite m_sprite;

    bool m_needDraw;
};
