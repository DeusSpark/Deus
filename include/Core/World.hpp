#pragma once

#include <string>

#include <Entities/Entity.hpp>
#include <Levels/Level.hpp>

#include <Core/Camera.hpp>
#include <Levels/MapEditorLevel/MapEditorLevel.hpp>

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
    Level* getLevel();

    void changeLevel(Level* level);
    void setSpectatorMode(bool spectatorMode);

    static Camera& getCamera();

private:
    static Camera m_camera;

    Level* m_level;
    MapEditorLevel m_mapEditorLevel;

    Entity* m_player;

    bool m_spectatorMode;
};
