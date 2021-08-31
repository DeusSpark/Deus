#pragma once

#include <Levels/Level.hpp>

#include <SFML/Graphics/Sprite.hpp>

#include <GameCore/TileMap.hpp>

class MapEditorLevel : public Level
{
public:
    MapEditorLevel();
    ~MapEditorLevel();

    void handleEvent(sf::Event& event) override;
    void update(float dt) override;
    void draw(Window& window) override;

private:
    TileMap    m_tileMap;
    sf::Sprite m_atlas;
    sf::Sprite m_pickupTile;

    sf::Vector2f m_indexPickupTexture;

    unsigned m_layer;

    void updateAtlas();
    void updatePickupTexture();
    void updatePickuperTile();

    void handleLayers();
    void handlePickupTile();
};
