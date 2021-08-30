#pragma once

#include <Levels/Level.hpp>

#include <Debug/DebugShape.hpp>
#include <GameCore/TileMap.hpp>

class DebugLevel : public Level
{
public:
    DebugLevel();
    ~DebugLevel();

    void handleEvent(sf::Event& event) override;
    void update(float dt) override;
    void draw(Window& window) override;

private:
    TileMap m_tileMap;
};
