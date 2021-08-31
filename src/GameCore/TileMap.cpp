#include <GameCore/TileMap.hpp>

#include <SFML/Graphics/Sprite.hpp>

#include <fstream>
#include <iostream>
#include <math.h>

#include <Core/Window.hpp>
#include <Core/World.hpp>

TileMap::TileMap() : m_renderDistance(20, 10)
{
}

TileMap::~TileMap()
{
}

void TileMap::load(const std::string& tileMapName)
{
    m_tileMapName = tileMapName;
    std::fstream file("assets/maps/" + m_tileMapName);

    file >> m_textureName;
    m_texture.loadFromFile("assets/textures/" + m_textureName);

    int countLayers;

    file >> countLayers;
    file >> m_sizePerTile.x >> m_sizePerTile.y;
    file >> m_size.x >> m_size.y;

    m_globalBounds.left   = 0;
    m_globalBounds.top    = 0;
    m_globalBounds.width  = m_size.x * m_sizePerTile.x;
    m_globalBounds.height = m_size.y * m_sizePerTile.y;

    m_tileMap.resize(countLayers);
    for (int z = 0; z < m_tileMap.size(); z++)
    {
        m_tileMap[z].resize(m_size.y);
        for (int y = 0; y < m_tileMap[z].size(); y++)
        {
            m_tileMap[z][y].resize(m_size.x);
            for (int x = 0; x < m_tileMap[z][y].size(); x++)
            {
                char buffer[3];
                file >> buffer;

                sstream << buffer;

                unsigned index;
                sstream >> index;
                sstream.clear();
                index--;

                int countTilesY = m_texture.getSize().y / m_sizePerTile.y;

                int yIndex = std::floor(float(index) / float(countTilesY));

                sf::IntRect rect;
                rect.left   = int(index % 10) * m_sizePerTile.x;
                rect.top    = m_sizePerTile.y * yIndex;
                rect.width  = m_sizePerTile.x;
                rect.height = m_sizePerTile.y;

                Tile& tile = m_tileMap[z][y][x];
                if (index != -1)
                {
                    tile.setTexture(m_texture);
                    tile.setNeedDraw(true);
                }
                tile.setTextureRect(rect);
                tile.setPosition(sf::Vector2f(m_sizePerTile.x * x, m_sizePerTile.y * y));
            }
        }
    }
}

void TileMap::save()
{
    std::ofstream file("assets/maps/" + m_tileMapName);
    file << m_textureName << " ";
    file << m_tileMap.size() << " ";
    file << m_sizePerTile.x << " " << m_sizePerTile.y << " ";
    file << m_tileMap[0].size() << " " << m_tileMap[0][0].size() << std::endl << std::endl;

    for (int z = 0; z < m_tileMap.size(); z++)
    {
        for (int y = 0; y < m_tileMap[z].size(); y++)
        {
            for (int x = 0; x < m_tileMap[z][y].size(); x++)
            {
                if (m_tileMap[z][y][x].needDraw())
                {
                    const sf::IntRect& tileTextureRect = m_tileMap[z][y][x].getTextureRect();

                    sf::Vector2f posIndex;
                    posIndex.x = tileTextureRect.left / m_sizePerTile.x;
                    posIndex.y = tileTextureRect.top / m_sizePerTile.y;

                    sstream << posIndex.y << posIndex.x;

                    int index;
                    sstream >> index;
                    sstream.clear();

                    index++;
                    file << index << " ";
                }
                else
                {
                    file << 0 << " ";
                }
            }
            file << std::endl;
        }
        file << std::endl;
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

Tile& TileMap::getTile(unsigned layer, unsigned y, unsigned x)
{
    if (m_tileMap.size() < layer + 1)
    {
        int oldSize = m_tileMap.size();

        m_tileMap.resize(layer + 1);
        for (int z = oldSize; z < m_tileMap.size(); z++)
        {
            for (int y = 0; y < m_size.y; y++)
            {
                m_tileMap[z].resize(m_size.y);
                for (int x = 0; x < m_size.x; x++)
                {
                    m_tileMap[z][y].resize(m_size.x);
                }
            }
        }
    }
    return m_tileMap[layer][y][x];
}

const sf::Texture& TileMap::getTexture() const
{
    return m_texture;
}

const sf::Vector2i TileMap::getSizePerTile() const
{
    return m_sizePerTile;
}

const sf::IntRect& TileMap::getGlobalBounds() const
{
    return m_globalBounds;
}