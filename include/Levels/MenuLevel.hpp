#pragma once

#include <Levels/Level.hpp>

class MenuLevel : public Level
{
public:
    MenuLevel();
    ~MenuLevel();

    void init() override;
    void handleEvent(sf::Event& event) override;
    void update(float dt) override;
    void draw(Window& window) override;
};
