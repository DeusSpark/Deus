#pragma once

#include <Levels/Level.hpp>

#include <SFML/Graphics/Sprite.hpp>

#include <GameCore/TileMap.hpp>
#include <Levels/MapEditorLevel/States/CreateTileState.hpp>
#include <Levels/MapEditorLevel/States/PickupTileState.hpp>

class MapEditorLevel : public Level
{
public:
    MapEditorLevel();
    ~MapEditorLevel();

    void handleEvent(sf::Event& event) override;
    void update(float dt) override;
    void draw(Window& window) override;

    const sf::Vector2f& getIndexPickupTexture() const;
    const sf::Sprite&   getAtlasSprite() const;
    TileMap&            getTileMap();
    unsigned            getLayer() const;

    void setPickupTile(const sf::IntRect& rect);

private:
    PickupTileState m_pickupTileState;
    CreateTileState m_createTileState;

    TileMap    m_tileMap;
    sf::Sprite m_atlasSprite;
    sf::Sprite m_pickupTile;

    sf::Vector2f m_indexPickupTexture;

    unsigned m_layer;

    void updateAtlas();
    void updatePickupTexture();

    void handleLayers();
};
