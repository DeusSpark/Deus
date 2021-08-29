#include <Core/World.hpp>

#include <Core/Camera.hpp>
#include <Debug/DebugLevel.hpp>

World::World()
{
    m_spectatorMode = false;

    m_level = new DebugLevel();
    m_level->setWorld(*this);
    m_level->init();
}

World::~World()
{
}

void World::handleEvent(sf::Event& event)
{
    if (m_spectatorMode)
    {
        m_camera->handleEvent(event);
    }

    m_level->handleEvent(event);
}

void World::update(float dt)
{
    if (m_spectatorMode)
    {
        m_camera->update(dt);
    }

    m_level->update(dt);
}

void World::draw(Window& window)
{
    m_level->draw(window);
}

void World::changeLevel(Level* level)
{
    delete m_level;
    m_level = level;
    m_level->setWorld(*this);
    m_level->init();
}

void World::setCamera(Camera& camera)
{
    m_camera = &camera;
}

void World::setSpectatorMode(bool spectatorMode)
{
    m_spectatorMode = spectatorMode;
}