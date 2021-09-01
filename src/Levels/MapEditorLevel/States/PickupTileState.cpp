#include <Levels/MapEditorLevel/States/PickupTileState.hpp>

#include <Core/World.hpp>
#include <Game.hpp>
#include <Levels/MapEditorLevel/MapEditorLevel.hpp>

PickupTileState::PickupTileState()
{
}

PickupTileState::~PickupTileState()
{
}

void PickupTileState::handleEvent(sf::Event& event)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        MapEditorLevel* level = reinterpret_cast<MapEditorLevel*>(Game::getWorld().getLevel());

        const sf::Sprite& atlasSprite = level->getAtlasSprite();

        const sf::Vector2f& clickPos = Game::getWindow().getMousePosView();

        sf::FloatRect atlasGlobalBounds = atlasSprite.getGlobalBounds();

        if (atlasGlobalBounds.contains(clickPos))
        {
            const sf::Vector2i& sizePerTile  = level->getTileMap().getSizePerTile();
            const sf::Vector2f& textureScale = atlasSprite.getScale();

            sf::Vector2f pixelPos;
            pixelPos.x = clickPos.x - atlasGlobalBounds.left;
            pixelPos.y = clickPos.y - atlasGlobalBounds.top;

            sf::Vector2i countTileBefore;
            countTileBefore.x = pixelPos.x / float(sizePerTile.x * textureScale.x);
            countTileBefore.y = pixelPos.y / float(sizePerTile.y * textureScale.y);

            sf::IntRect rect;
            rect.left   = countTileBefore.x * sizePerTile.x;
            rect.top    = countTileBefore.y * sizePerTile.y;
            rect.width  = sizePerTile.x;
            rect.height = sizePerTile.y;

            level->setPickupTile(rect);
        }
    }
}

void PickupTileState::update(float dt)
{
}

void PickupTileState::draw(Window& window)
{
}
