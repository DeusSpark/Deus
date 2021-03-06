#include <Core/Camera.hpp>

Camera::Camera(const sf::Vector2f& resolution) : m_view(sf::Vector2f(), resolution), m_resolution(resolution), m_speed(250.0f), m_position(0.0f, 0.0f)
{
}

Camera::~Camera()
{
}

void Camera::handleEvent(sf::Event& event)
{
    m_direction.x = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A);
    m_direction.y = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);
}

void Camera::update(float dt)
{
    if (m_direction.x != 0 || m_direction.y != 0)
    {
        sf::Vector2f velocity{m_direction * m_speed};
        m_position += velocity * dt;
        m_view.move(velocity * dt);
    }
}

const sf::View& Camera::getView() const
{
    return m_view;
}

const sf::Vector2f& Camera::getPosition() const
{
    return m_position;
}

const sf::Vector2f& Camera::getResolution() const
{
    return m_resolution;
}

float Camera::getAspectRation() const
{
    return float(m_size.x) / float(m_size.y);
}

void Camera::resize(const sf::Vector2f& size)
{
    m_size = size;
    m_view.setSize(m_resolution.x * getAspectRation(), m_resolution.y);
}
