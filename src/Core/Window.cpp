#include <Core/Window.hpp>

Window::Window(const sf::Vector2u& size, const std::string& title) : m_renderWindow(sf::VideoMode(size.x, size.y), title)
{
    m_renderWindow.setVerticalSyncEnabled(true);
    m_renderWindow.setKeyRepeatEnabled(false);
}

Window::~Window()
{
}

bool Window::poolEvent(sf::Event& event)
{
    bool b = m_renderWindow.pollEvent(event);

    if (event.type == sf::Event::EventType::Closed)
        m_renderWindow.close();

    if (event.type == sf::Event::EventType::Resized)
        m_camera->resize(sf::Vector2f(m_renderWindow.getSize()));

    return b;
}

void Window::draw(const sf::Drawable& object, const sf::RenderStates& states)
{
    m_renderWindow.draw(object, states);
}

void Window::close()
{
    m_renderWindow.close();
}

void Window::clear()
{
    m_renderWindow.clear();
    m_renderWindow.setView(m_camera->getView());
}

void Window::display()
{
    m_renderWindow.display();
}

const sf::RenderWindow& Window::getRenderWindow() const
{
    return m_renderWindow;
}

void Window::setCamera(Camera& camera)
{
    m_camera = &camera;
}