#pragma once

#include <string>

#include <Entities/Entity.hpp>
#include <Levels/Level.hpp>

#include <Core/Camera.hpp>

class World
{
    friend class Game;

private:
    World();
    ~World();

    void handleEvent(sf::Event& event);
    void update(float dt);
    void draw(Window& window);

public:
    void changeLevel(Level* level);
    void setSpectatorMode(bool spectatorMode);

    static Camera& getCamera();

private:
    static Camera m_camera;

    Level* m_level;

    Entity* m_player;

    bool m_spectatorMode;
};
