#include <Core/Camera.hpp>

Camera::Camera(const sf::Vector2f& size) : m_view(sf::Vector2f(), size), m_size(size), m_speed(250.0f), m_position(0.0f, 0.0f)
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

const sf::Vector2f& Camera::getSize() const
{
    return m_size;
}

void Camera::resize(const sf::Vector2f& size)
{
    float aspectRatio = float(size.x) / float(size.y);
    m_view.setSize(m_size.x * aspectRatio, m_size.y);
}
