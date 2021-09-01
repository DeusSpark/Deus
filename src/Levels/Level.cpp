#include <Levels/Level.hpp>

#include <GameCore/GameState.hpp>

Level::Level()
{
}

Level::~Level()
{
}

void Level::handleEvent(sf::Event& event)
{
    if (m_gameState)
        m_gameState->handleEvent(event);
}

void Level::update(float dt)
{
    if (m_gameState)
        m_gameState->update(dt);
}

void Level::draw(Window& window)
{
    if (m_gameState)
        m_gameState->draw(window);
}
