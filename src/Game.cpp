#include <Game.hpp>

Game::Game()
{
    m_window.setCamera(m_camera);
    m_world.setCamera(m_camera);
}

Game::~Game()
{
}

void Game::run()
{
    while (m_window.getRenderWindow().isOpen())
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