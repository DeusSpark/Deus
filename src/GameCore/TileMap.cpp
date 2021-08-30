#include <GameCore/TileMap.hpp>

#include <SFML/Graphics/Sprite.hpp>

#include <fstream>
#include <iostream>
#include <math.h>
#include <sstream>

#include <Core/Window.hpp>
#include <Core/World.hpp>

TileMap::TileMap() : m_renderDistance(5, 5)
{
}

TileMap::~TileMap()
{
}

void TileMap::load(const std::string& tileMapName)
{
    std::fstream file("/home/deus/Документы/Deus/assets/" + tileMapName);

    if (!file.is_open())
        return;

    std::string textureName;
    file >> textureName;
    m_texture.loadFromFile("/home/deus/Документы/Deus/assets/" + textureName);

    int countLayers;

    file >> countLayers;

    file >> m_sizePerTile.x >> m_sizePerTile.y;

    m_tileMap.resize(countLayers);

    file >> m_size.x >> m_size.y;
    for (int z = 0; z < m_tileMap.size(); z++)
    {
        m_tileMap[z].resize(m_size.y);
        for (int y = 0; y < m_tileMap[z].size(); y++)
        {
            m_tileMap[z][y].resize(m_size.x);
            for (int x = 0; x < m_tileMap[z][y].size(); x++)
            {
                std::stringstream sstream;

                char buffer[3];
                file >> buffer;

                sstream << buffer;

                unsigned index;
                sstream >> index;
                index--;

                int countTilesY = (m_texture.getSize().y / m_sizePerTile.y);

                int yIndex = std::floor(float(index) / float(countTilesY));

                sf::IntRect rect{(index % 10) * m_sizePerTile.x, m_sizePerTile.y * yIndex, m_sizePerTile.x, m_sizePerTile.y}; // mb mistake

                Tile& tile = m_tileMap[z][y][x];
                if (index != -1)
                    tile.setTexture(m_texture);
                tile.setTextureRect(rect);
                tile.setPosition(sf::Vector2f(m_sizePerTile.x * x, m_sizePerTile.y * y));
            }
        }
    }
}

void TileMap::draw(Window& window)
{
    int cameraX = World::getCamera().getPosition().x;
    int cameraY = World::getCamera().getPosition().y;

    int fromX = cameraX / float(m_sizePerTile.x);
    int fromY = cameraY / float(m_sizePerTile.y);

    fromX = fromX - m_renderDistance.x < 0 ? 0 : fromX - m_renderDistance.x;
    fromY = fromY - m_renderDistance.y < 0 ? 0 : fromY - m_renderDistance.y;

    fromX = fromX + m_renderDistance.x * 2 > (m_size.x - 1) ? m_size.x - (m_renderDistance.x * 2) : fromX;
    fromY = fromY + m_renderDistance.y * 2 > (m_size.y - 1) ? m_size.y - (m_renderDistance.y * 2) : fromY;

    for (int z = 0; z < m_tileMap.size(); z++)
    {
        for (int y = 0; y < m_renderDistance.y * 2; y++)
        {
            for (int x = 0; x < m_renderDistance.x * 2; x++)
            {
                m_tileMap[z][fromY + y][fromX + x].draw(window);
            }
        }
    }
}