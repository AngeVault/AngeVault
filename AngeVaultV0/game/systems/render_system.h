#pragma once
#include "ecs/system.h"
#include "ecs/registry.h"
#include "components/transform2d.h"
#include "components/sprite_component.h"
#include "components/geometry.h"
#include "utils/texture_factory.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <string>

class RenderSystem : public ISystem {
public:
    explicit RenderSystem(sf::RenderWindow& window) : m_window(window) {
        priority = 10; // s'exécute en dernier, après physique et script
    }

    void onUpdate(Registry& registry, float dt) override {
        struct Entry { int layer; Geometry* geo; sf::Transform transform; };
        std::vector<Entry> drawList;

        registry.view<Transform2D, Geometry>([&](Entity e, Transform2D& t, Geometry& g) {
            drawList.push_back({ g.layer, &g, t.getLocalMatrix() });
            });

        std::sort(drawList.begin(), drawList.end(), [](const Entry& a, const Entry& b) { return a.layer < b.layer; });

        for (auto& entry : drawList) {
            std::visit([&](auto& shapeData) {
                using T = std::decay_t<decltype(shapeData)>;
				if constexpr (std::is_same_v<T, Geometry::SpriteData>) {
				m_sprite.setTexture(resolveTexture(shapeData.textureId));
				m_sprite.setTextureRect(shapeData.rect);
				m_sprite.setColor(shapeData.tint);
				m_sprite.setOrigin({ shapeData.rect.size.x / 2.f, shapeData.rect.size.y / 2.f });
				m_window.draw(m_sprite, entry.transform);

				}
                else if constexpr (std::is_same_v<T, Geometry::BoxData>) 
                {
					m_rect.setSize(shapeData.halfSize * 2.f);
					m_rect.setOrigin(shapeData.halfSize);
					m_rect.setFillColor(shapeData.style.fillColor);
					m_rect.setOutlineColor(shapeData.style.outlineColor);
					m_rect.setOutlineThickness(shapeData.style.outlineThickness);
                    if (shapeData.style.textureId != "")
                    {
					    m_rect.setTexture(&resolveTexture(shapeData.style.textureId));
                    }
					else
					{
						m_rect.setTexture(nullptr);
					}
					m_window.draw(m_rect, entry.transform);
                }
				else if constexpr (std::is_same_v<T, Geometry::CircleData>)
				{
					sf::CircleShape circle(shapeData.radius);
					circle.setOrigin({ shapeData.radius, shapeData.radius });
					circle.setFillColor(shapeData.style.fillColor);
					circle.setOutlineColor(shapeData.style.outlineColor);
					circle.setOutlineThickness(shapeData.style.outlineThickness);
					if (shapeData.style.textureId != "")
					{
						circle.setTexture(&resolveTexture(shapeData.style.textureId));
					}
					else
					{
						circle.setTexture(nullptr);
					}
					m_window.draw(circle, entry.transform);
				}
				else if constexpr (std::is_same_v<T, Geometry::PolygonData>)
				{
					sf::ConvexShape polygon;
					polygon.setPointCount(shapeData.points.size());
					for (size_t i = 0; i < shapeData.points.size(); ++i) {
						polygon.setPoint(i, shapeData.points[i]);
					}
					polygon.setFillColor(shapeData.style.fillColor);
					polygon.setOutlineColor(shapeData.style.outlineColor);
					polygon.setOutlineThickness(shapeData.style.outlineThickness);
					if (shapeData.style.textureId != "")
					{
						polygon.setTexture(&resolveTexture(shapeData.style.textureId));
					}
					else
					{
						polygon.setTexture(nullptr);
					}
					m_window.draw(polygon, entry.transform);
				}
            }, entry.geo->data);
        }
    }

private:
    sf::RenderWindow& m_window;
	sf::Texture dummyTexture;
    sf::Sprite m_sprite{ dummyTexture };
	sf::RectangleShape m_rect;
	sf::CircleShape m_circle;
	sf::ConvexShape m_polygon;
    std::unordered_map<std::string, sf::Texture> m_textureCache;

    sf::Texture& resolveTexture(const std::string& id) 
    {
        if (auto it = m_textureCache.find(id); it != m_textureCache.end())
            return it->second;

        sf::Texture tex;
        if (!tex.loadFromFile("assets/" + id + ".png"))
            tex = TextureFactory::createCheckerboard({ 32, 32 }, sf::Color(255, 0, 255), sf::Color::Black);

        auto [inserted, _] = m_textureCache.emplace(id, std::move(tex));
        return inserted->second;
    }
};