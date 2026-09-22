#pragma once
#include "ecs/system.h"
#include "ecs/registry.h"
#include "components/transform2d.h"
#include "components/sprite_component.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>

class RenderSystem : public ISystem {
public:
    explicit RenderSystem(sf::RenderWindow& window) : m_window(window) {
        priority = 10; // s'exécute en dernier, après physique et script
    }

    void onUpdate(Registry& registry, float dt) override {
        // Collecte + tri par layer
        struct Entry { int layer; sf::Sprite* sprite; sf::Transform transform; };
        std::vector<Entry> drawList;

        registry.view<Transform2D, SpriteComponent>(
            [&](Entity e, Transform2D& t, SpriteComponent& sc) {
                drawList.push_back({ sc.layer, &sc.sprite, t.getLocalMatrix() });
            });

        std::sort(drawList.begin(), drawList.end(),
            [](const Entry& a, const Entry& b) { return a.layer < b.layer; });

        for (auto& entry : drawList)
            m_window.draw(*entry.sprite, entry.transform);
    }

private:
    sf::RenderWindow& m_window;
};