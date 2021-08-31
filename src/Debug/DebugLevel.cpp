#include <Debug/DebugLevel.hpp>

#include <Game.hpp>

DebugLevel::DebugLevel()
{
    Game::getWorld().setSpectatorMode(true);
    m_tileMap.load("Dungeon_Tileset.txt");
}

DebugLevel::~DebugLevel()
{
}

void DebugLevel::handleEvent(sf::Event& event)
{
}

void DebugLevel::update(float dt)
{
}

void DebugLevel::draw(Window& window)
{
    m_tileMap.draw(window);
}
