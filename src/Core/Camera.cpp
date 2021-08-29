#include <Core/Camera.hpp>

Camera::Camera(const sf::Vector2f& size) : m_view(sf::Vector2f(), size), m_size(size), m_speed(200.0f)
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
        m_view.move(velocity * dt);
    }
}

const sf::View& Camera::getView() const
{
    return m_view;
}

void Camera::resize(const sf::Vector2f& size)
{
    float aspectRatio = float(size.x) / float(size.y);
    m_view.setSize(m_size.x * aspectRatio, m_size.y);
}
