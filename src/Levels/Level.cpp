#include <Levels/Level.hpp>

Level::Level()
{
}

Level::~Level()
{
}

void Level::setWorld(World& world)
{
    m_world = &world;
}
