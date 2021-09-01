#pragma once

#include <GameCore/GameState.hpp>

class PickupTileState : public GameState
{
public:
    PickupTileState();
    ~PickupTileState();

    void handleEvent(sf::Event& event) override;
    void update(float dt) override;
    void draw(Window& window) override;
};
