#pragma once

#include <SFML/Graphics/Sprite.hpp>

class Window;

class Tile
{
public:
    Tile();
    ~Tile();

    void draw(Window& window);

    void setTexture(const sf::Texture& texture);
    void setTextureRect(const sf::IntRect& rect);
    void setPosition(const sf::Vector2f& position);

private:
    sf::Sprite m_sprite;
};
