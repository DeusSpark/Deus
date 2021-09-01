#include <Levels/MapEditorLevel/States/CreateTileState.hpp>

#include <Core/World.hpp>
#include <Game.hpp>
#include <Levels/MapEditorLevel/MapEditorLevel.hpp>

CreateTileState::CreateTileState()
{
}

CreateTileState::~CreateTileState()
{
}

void CreateTileState::handleEvent(sf::Event& event)
{
}

void CreateTileState::update(float dt)
{
    const sf::Vector2f& clickPos = Game::getWindow().getMousePosView();
    MapEditorLevel*     level    = reinterpret_cast<MapEditorLevel*>(Game::getWorld().getLevel());
    TileMap&            tileMap  = level->getTileMap();

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) || sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
    {
        if (tileMap.getGlobalBounds().contains(sf::Vector2i(clickPos)) && !level->getAtlasSprite().getGlobalBounds().contains(clickPos))
        {
            const sf::IntRect&  tileMapGlobalBounds = tileMap.getGlobalBounds();
            const sf::Vector2i& sizePerTile         = tileMap.getSizePerTile();
            const sf::Vector2f& indexPickupTexture  = level->getIndexPickupTexture();

            sf::Vector2f pixelPos;
            pixelPos.x = clickPos.x - tileMapGlobalBounds.left;
            pixelPos.y = clickPos.y - tileMapGlobalBounds.top;

            sf::Vector2i countTileBefore;
            countTileBefore.x = pixelPos.x / float(sizePerTile.x);
            countTileBefore.y = pixelPos.y / float(sizePerTile.y);

            sf::IntRect tileTextureRect;
            tileTextureRect.left   = indexPickupTexture.x * sizePerTile.x;
            tileTextureRect.top    = indexPickupTexture.y * sizePerTile.y;
            tileTextureRect.width  = sizePerTile.x;
            tileTextureRect.height = sizePerTile.y;

            Tile& tile = tileMap.getTile(level->getLayer(), countTileBefore.y, countTileBefore.x);

            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                tile.setTexture(tileMap.getTexture());
                tile.setTextureRect(tileTextureRect);
                tile.setNeedDraw(true);
                tile.setPosition(sf::Vector2f(sizePerTile.x * countTileBefore.x, sizePerTile.y * countTileBefore.y));
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
            {
                tile.setNeedDraw(false);
            }
        }
    }
}

void CreateTileState::draw(Window& window)
{
}
