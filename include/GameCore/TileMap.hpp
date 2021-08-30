#pragma once

#include <SFML/Graphics/Texture.hpp>

#include <string>
#include <vector>

#include <GameCore/Tile.hpp>

class Window;

class TileMap
{
public:
    TileMap();
    ~TileMap();

    void load(const std::string& tileMapName);
    void draw(Window& window);

private:
    std::vector<std::vector<std::vector<Tile>>> m_tileMap;

    sf::Texture  m_texture;
    sf::Vector2f m_position;
    sf::Vector2i m_sizePerTile;
    sf::Vector2i m_size;
    sf::Vector2i m_renderDistance;
};

// void TileMap::draw(Window& window)
// {
//     int cameraX = World::getCamera().getPosition().x;
//     int cameraY = World::getCamera().getPosition().y;

//     int fromX = cameraX / float(m_sizePerTile.x);
//     int fromY = cameraY / float(m_sizePerTile.y);

//     fromX = fromX - m_renderDistance.x < 0 ? 0 : fromX - m_renderDistance.x;
//     fromY = fromY - m_renderDistance.y < 0 ? 0 : fromY - m_renderDistance.y;

//     fromX = fromX + m_renderDistance.x > m_size.x - 1 ? m_size.x - 1 - m_renderDistance.x * 2 : fromX;
//     fromY = fromY + m_renderDistance.y > m_size.y - 1 ? m_size.y - 1 - m_renderDistance.y * 2 : fromY;

//     for (int z = 0; z < m_tileMap.size(); z++)
//     {
//         for (int y = 0; y < m_renderDistance.y * 2; y++)
//         {
//             for (int x = 0; x < m_renderDistance.x * 2; x++)
//             {
//                 m_tileMap[z][fromY + y][fromX + x].draw(window);
//             }
//         }
//     }
// }