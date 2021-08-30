#pragma once

#include <Levels/Level.hpp>

class MapEditorLevel : public Level
{
public:
    MapEditorLevel();
    ~MapEditorLevel();

    void handleEvent(sf::Event& event) override;
    void update(float dt) override;
    void draw(Window& window) override;

private:
};
