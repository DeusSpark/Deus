#include <Core/Window.hpp>

#include <Core/World.hpp>

Window::Window(const sf::Vector2u& size, const std::string& title) :
m_renderWindow(sf::VideoMode(size.x, size.y), title),
m_desktopSize(size.x, size.y),
m_title(title),
m_isFullscreen(false)
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

    if (event.type == sf::Event::EventType::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
    {
        m_renderWindow.close();
    }

    if (event.type == sf::Event::EventType::Resized)
    {
        World::getCamera().resize(sf::Vector2f(m_renderWindow.getSize()));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F11))
    {
        m_isFullscreen = !m_isFullscreen ? true : false;
        m_renderWindow.create(m_isFullscreen ? sf::VideoMode::getFullscreenModes()[0] : sf::VideoMode(m_desktopSize.x, m_desktopSize.y),
                              m_title,
                              m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
        m_renderWindow.setVerticalSyncEnabled(true);
        m_renderWindow.setKeyRepeatEnabled(false);
    }

    updateMousePos();
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
    m_renderWindow.setView(World::getCamera().getView());
}

void Window::display()
{
    m_renderWindow.display();
}

void Window::updateMousePos()
{
    m_mousePosScreen = sf::Mouse::getPosition();
    m_mousePosWindow = sf::Mouse::getPosition(m_renderWindow);
    m_mousePosView   = m_renderWindow.mapPixelToCoords(m_mousePosWindow);
}

const sf::Vector2i& Window::getMousePosScreen() const
{
    return m_mousePosScreen;
}

const sf::Vector2i& Window::getMousePosWindow() const
{
    return m_mousePosWindow;
}

const sf::Vector2f& Window::getMousePosView() const
{
    return m_mousePosView;
}

sf::Vector2u Window::getSize() const
{
    return m_renderWindow.getSize();
}