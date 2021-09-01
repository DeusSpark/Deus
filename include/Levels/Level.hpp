#pragma once

namespace sf
{
class Event;
}

class Window;
class GameState;

class Level
{
public:
    Level();
    virtual ~Level();

    virtual void handleEvent(sf::Event& event);
    virtual void update(float dt);
    virtual void draw(Window& window);

protected:
    GameState* m_gameState;
};
