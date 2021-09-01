#pragma once

#include <GameCore/GameState.hpp>

class CreateTileState : public GameState
{
public:
    CreateTileState();
    ~CreateTileState();

    void handleEvent(sf::Event& event) override;
    void update(float dt) override;
    void draw(Window& window) override;
};
