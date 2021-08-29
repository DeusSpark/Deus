#pragma once

#include <string>

#include <Entities/Entity.hpp>
#include <Levels/Level.hpp>

class Camera;

class World
{
public:
    World();
    ~World();

    void handleEvent(sf::Event& event);
    void update(float dt);
    void draw(Window& window);

    void changeLevel(Level* level);
    void setCamera(Camera& camera);
    void setSpectatorMode(bool spectatorMode);

private:
    Level* m_level;

    Entity* m_player;

    Camera* m_camera;
    bool    m_spectatorMode;
};
