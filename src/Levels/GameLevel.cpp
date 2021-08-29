#include <Levels/GameLevel.hpp>

#include <Core/Window.hpp>

GameLevel::GameLevel()
{
}

GameLevel::~GameLevel()
{
}

void GameLevel::init()
{
}

void GameLevel::handleEvent(sf::Event& event)
{
    // static bool isKeyDown;
    // if (event.key.code == sf::Keyboard::Key::C)
    // {
    //     isKeyDown = !isKeyDown ? true : false;
    //     if (isKeyDown)
    //     {
    //         Pawn* nextPlayer = GameStatics::getPlayerController().getPlayer() == &m_skilet1 ? &m_skilet2 : &m_skilet1;
    //         GameStatics::getPlayerController().possess(nextPlayer);

    //         Pawn* nextBot = GameStatics::getAIcontroller().getBot() == &m_skilet1 ? &m_skilet2 : &m_skilet1;
    //         GameStatics::getAIcontroller().possess(nextBot);
    //     }
    // }
}

void GameLevel::update(float dt)
{
}

void GameLevel::draw(Window& window)
{
}
