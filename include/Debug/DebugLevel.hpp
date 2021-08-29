#pragma once

#include <SFML/Graphics/CircleShape.hpp>

#include <Levels/Level.hpp>

#include <World/TileMap.hpp>

class DebugLevel : public Level
{
public:
    DebugLevel();
    ~DebugLevel();

    void init() override;
    void handleEvent(sf::Event& event) override;
    void update(float dt) override;
    void draw(Window& window) override;

private:
    TileMap m_tileMap;
};
