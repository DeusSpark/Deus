#include <Core/World.hpp>

#include <Game.hpp>

#include <Core/Camera.hpp>
#include <Debug/DebugLevel.hpp> //
#include <Levels/MapEditorLevel.hpp>

Camera World::m_camera;

World::World()
{
    m_spectatorMode = false;

    m_level = new MapEditorLevel();
}

World::~World()
{
    delete m_level;
}

void World::handleEvent(sf::Event& event)
{
    if (m_spectatorMode)
    {
        m_camera.handleEvent(event);
    }

    m_level->handleEvent(event);
}

void World::update(float dt)
{
    if (m_spectatorMode)
    {
        m_camera.update(dt);
    }

    m_level->update(dt);
}

void World::draw(Window& window)
{
    m_level->draw(window);
}

Camera& World::getCamera()
{
    return m_camera;
}

void World::changeLevel(Level* level)
{
    delete m_level;
    m_level = level;
}

void World::setSpectatorMode(bool spectatorMode)
{
    m_spectatorMode = spectatorMode;
}