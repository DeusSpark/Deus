#pragma once

#include <Entities/Entity.hpp>

#include <SFML/System/Vector2.hpp>

class DebugEntity : public Entity
{
public:
    DebugEntity();
    ~DebugEntity();

    void handleEvent(sf::Event& event) override;
    void update(float dt) override;
};
