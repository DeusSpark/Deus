#include <Game.hpp>

Game::Game() : m_window(sf::VideoMode(200, 200), "SFML works!")
{
}

Game::~Game()
{
}

void Game::run()
{
    while (m_window.isOpen())
    {
        event();
        update();
        render();
    }
}

void Game::event()
{
    while (m_window.pollEvent(m_event))
    {
        if (m_event.type == sf::Event::Closed)
            m_window.close();
    }
}

void Game::update()
{
}

void Game::render()
{
    m_window.clear();

    m_window.display();
}