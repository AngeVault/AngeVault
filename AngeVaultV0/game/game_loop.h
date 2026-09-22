#pragma once
#include <SFML/Graphics.hpp>
#include "ecs/registry.h"
#include "ecs/system_manager.h"

class Game {
public:
    Game();
    ~Game() = default;
    void run();

    Registry& registry() { return m_registry; }
    SystemManager& systems() { return m_systems; }

    sf::RenderWindow& window() { return m_window; }

private:
    sf::RenderWindow m_window;
    bool             m_isRunning;
    sf::Clock        m_clock;
    Registry         m_registry;
    SystemManager    m_systems;

    void handleEvents();
    void update(float dt);
    void render();
};