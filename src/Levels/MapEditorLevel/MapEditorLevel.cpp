#include <Levels/MapEditorLevel/MapEditorLevel.hpp>

#include <Core/World.hpp>
#include <Game.hpp>

MapEditorLevel::MapEditorLevel() : m_layer(0), m_indexPickupTexture(0, 0)
{
    m_gameState = &m_pickupTileState;

    Game::getWorld().setSpectatorMode(true);

    m_tileMap.load("Dungeon_Tileset.txt");

    m_atlasSprite.setTexture(m_tileMap.getTexture());
    m_atlasSprite.setScale(sf::Vector2f(0.75f, 0.75f));

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

    const sf::Vector2f& clickPos = Game::getWindow().getMousePosView();

    sf::FloatRect atlasGlobalBounds   = m_atlasSprite.getGlobalBounds();
    sf::IntRect   tileMapGlobalBounds = m_tileMap.getGlobalBounds();

    if (tileMapGlobalBounds.contains(sf::Vector2i(clickPos)))
    {
        m_gameState = &m_createTileState;
    }

    if (atlasGlobalBounds.contains(clickPos))
    {
        m_gameState = &m_pickupTileState;
    }

    Level::handleEvent(event);
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

void MapEditorLevel::update(float dt)
{
    updateAtlas();
    updatePickupTexture();

    Level::update(dt);
}

void MapEditorLevel::updateAtlas()
{
    Camera& camera = World::getCamera();

    const sf::Vector2f& cameraPos        = camera.getPosition();
    const sf::Vector2f& cameraResolution = camera.getResolution();

    float aspectRation = camera.getAspectRation();

    int x = cameraPos.x - ((cameraResolution.x * aspectRation) / 2);
    int y = cameraPos.y - (cameraResolution.y / 2);

    m_atlasSprite.setPosition(x, y);
}

void MapEditorLevel::updatePickupTexture()
{
    sf::Vector2f mousePosView = Game::getWindow().getMousePosView();
    m_pickupTile.setPosition(mousePosView.x - (m_tileMap.getSizePerTile().x / 2.0f), mousePosView.y - (m_tileMap.getSizePerTile().y / 2.0f));
}

void MapEditorLevel::draw(Window& window)
{
    m_tileMap.draw(window);

    window.draw(m_atlasSprite);

    window.draw(m_pickupTile);
    Level::draw(window);
}

const sf::Vector2f& MapEditorLevel::getIndexPickupTexture() const
{
    return m_indexPickupTexture;
}

const sf::Sprite& MapEditorLevel::getAtlasSprite() const
{
    return m_atlasSprite;
}

TileMap& MapEditorLevel::getTileMap()
{
    return m_tileMap;
}

unsigned MapEditorLevel::getLayer() const
{
    return m_layer;
}

void MapEditorLevel::setPickupTile(const sf::IntRect& rect)
{
    m_pickupTile.setTextureRect(rect);
    m_indexPickupTexture.x = rect.left / m_tileMap.getSizePerTile().x;
    m_indexPickupTexture.y = rect.top / m_tileMap.getSizePerTile().y;
}