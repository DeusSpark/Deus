#pragma once

#include <Levels/Level.hpp>

class GameLevel : public Level
{
public:
    GameLevel();
    ~GameLevel();

    void handleEvent(sf::Event& event) override;
    void update(float dt) override;
    void draw(Window& window) override;
};
