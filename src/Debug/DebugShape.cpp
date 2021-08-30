#include <Debug/DebugShape.hpp>

#include <Core/Window.hpp>

DebugShape::DebugShape()
{
    m_shape.setRadius(50.0f);
    m_shape.setFillColor(sf::Color::Green);
}

DebugShape::~DebugShape()
{
}

void DebugShape::handleEvent(sf::Event& event)
{
}

void DebugShape::update(float dt)
{
}

void DebugShape::draw(Window& window)
{
    window.draw(m_shape);
}