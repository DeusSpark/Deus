#include <Levels/MapEditorLevel.hpp>

#include <iostream>

#include <Core/World.hpp>
#include <Game.hpp>

MapEditorLevel::MapEditorLevel() : m_layer(0), m_indexPickupTexture(0, 0)
{
    Game::getWorld().setSpectatorMode(true);

    m_tileMap.load("Dungeon_Tileset.txt");

    m_atlas.setTexture(m_tileMap.getTexture());
    m_atlas.setScale(sf::Vector2f(0.75f, 0.75f));

    m_pickupTile.setTexture((m_tileMap.getTexture()));
    m_pickupTile.setTextureRect(sf::IntRect(0, 0, m_tileMap.getSizePerTile().x, m_tileMap.getSizePerTile().y));
}

MapEditorLevel::~MapEditorLevel()
{
    m_tileMap.save();
}

void MapEditorLevel::handleEvent(sf::Event& event)
{
    handleLayers();
    handlePickupTile();
}

void MapEditorLevel::handleLayers()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1))
        m_layer = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2))
        m_layer = 1;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3))
        m_layer = 2;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num4))
        m_layer = 3;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num5))
        m_layer = 4;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num6))
        m_layer = 5;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num7))
        m_layer = 6;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num8))
        m_layer = 7;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num9))
        m_layer = 8;
}

void MapEditorLevel::handlePickupTile()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        const sf::Vector2f& clickPos          = Game::getWindow().getMousePosView();
        sf::FloatRect       atlasGlobalBounds = m_atlas.getGlobalBounds();

        if (atlasGlobalBounds.contains(clickPos))
        {
            const sf::Vector2i& sizePerTile  = m_tileMap.getSizePerTile();
            const sf::Vector2f& textureScale = m_atlas.getScale();

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

            m_pickupTile.setTextureRect(rect);

            m_indexPickupTexture.x = rect.left / sizePerTile.x;
            m_indexPickupTexture.y = rect.top / sizePerTile.y;
        }
    }
}

void MapEditorLevel::update(float dt)
{
    updateAtlas();
    updatePickupTexture();
    updatePickuperTile();
}

void MapEditorLevel::updateAtlas()
{
    Camera& camera = World::getCamera();

    const sf::Vector2f& cameraPos        = camera.getPosition();
    const sf::Vector2f& cameraResolution = camera.getResolution();

    float aspectRation = camera.getAspectRation();

    int x = cameraPos.x - ((cameraResolution.x * aspectRation) / 2);
    int y = cameraPos.y - (cameraResolution.y / 2);

    m_atlas.setPosition(x, y);
}

void MapEditorLevel::updatePickupTexture()
{
    sf::Vector2f mousePosView = Game::getWindow().getMousePosView();
    m_pickupTile.setPosition(mousePosView.x - (m_tileMap.getSizePerTile().x / 2.0f), mousePosView.y - (m_tileMap.getSizePerTile().y / 2.0f));
}

void MapEditorLevel::updatePickuperTile()
{
    const sf::Vector2f& clickPos = Game::getWindow().getMousePosView();

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) || sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
    {
        if (m_tileMap.getGlobalBounds().contains(sf::Vector2i(clickPos)) && !m_atlas.getGlobalBounds().contains(clickPos))
        {
            const sf::IntRect&  tileMapGlobalBounds = m_tileMap.getGlobalBounds();
            const sf::Vector2i& sizePerTile         = m_tileMap.getSizePerTile();

            sf::Vector2f pixelPos;
            pixelPos.x = clickPos.x - tileMapGlobalBounds.left;
            pixelPos.y = clickPos.y - tileMapGlobalBounds.top;

            sf::Vector2i countTileBefore;
            countTileBefore.x = pixelPos.x / float(sizePerTile.x);
            countTileBefore.y = pixelPos.y / float(sizePerTile.y);

            sf::IntRect tileTextureRect;
            tileTextureRect.left   = m_indexPickupTexture.x * sizePerTile.x;
            tileTextureRect.top    = m_indexPickupTexture.y * sizePerTile.y;
            tileTextureRect.width  = sizePerTile.x;
            tileTextureRect.height = sizePerTile.y;

            Tile& tile = m_tileMap.getTile(m_layer, countTileBefore.y, countTileBefore.x);

            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                tile.setTexture(m_tileMap.getTexture());
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

void MapEditorLevel::draw(Window& window)
{
    m_tileMap.draw(window);

    window.draw(m_atlas);

    window.draw(m_pickupTile);
}
