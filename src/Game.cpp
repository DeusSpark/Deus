#include <Game.hpp>

Window Game::m_window;
World  Game::m_world;

Game::Game()
{
}

Game::~Game()
{
}

void Game::run()
{
    while (m_window.m_renderWindow.isOpen())
    {
        m_dt = m_clock.restart();
        handleEvent();
        update();
        draw();
    }
}

void Game::handleEvent()
{
    sf::Event event;
    while (m_window.poolEvent(event))
    {
        m_world.handleEvent(event);
    }
}

void Game::update()
{
    m_world.update(m_dt.asSeconds());
}

void Game::draw()
{
    m_window.clear();

    m_world.draw(m_window);

    m_window.display();
}

Window& Game::getWindow()
{
    return m_window;
}

World& Game::getWorld()
{
    return m_world;
}