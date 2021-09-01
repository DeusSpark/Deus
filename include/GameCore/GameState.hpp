#pragma once

namespace sf
{
class Event;
}

class Window;

class GameState
{
public:
    GameState();
    virtual ~GameState();

    virtual void handleEvent(sf::Event& event) = 0;
    virtual void update(float dt)              = 0;
    virtual void draw(Window& window)          = 0;
};
