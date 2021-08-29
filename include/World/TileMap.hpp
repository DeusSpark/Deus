#pragma once

#include <SFML/Graphics.hpp>

#include <string>

class Window;

class TileMap
{
public:
    TileMap();
    ~TileMap();

    bool load(const std::string& name, const sf::Vector2u& tileSize, const int* tiles, unsigned int width, unsigned int height);
    void draw(Window& window);

private:
    sf::VertexArray m_vertices;
    sf::Texture     m_tileset;
};
