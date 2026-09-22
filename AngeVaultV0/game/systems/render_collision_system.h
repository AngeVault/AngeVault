#pragma once
#include "ecs/system.h"
#include "ecs/registry.h"
#include "components/transform2d.h"
#include "components/collider2d.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>

class RenderCollisionSystem : public ISystem {
public:
    explicit RenderCollisionSystem(sf::RenderWindow& window) : m_window(window) {
        priority = 11; // s'exécute en dernier, après physique et script et après render
    }

    void onUpdate(Registry& registry, float dt) override 
	{

		registry.view<Collider2D, Transform2D>(
			[&](Entity e, Collider2D& c, Transform2D& t)
			{
				sf::Vector2f worldPos = t.getPosition() + c.offset;
				if (c.type() == Collider2D::ShapeType::Circle)
				{
					sf::CircleShape circle;
					auto shape = std::get<Collider2D::Circle>(c.shape);
					circle.setRadius(shape.radius);
					circle.setOrigin({ shape.radius, shape.radius });
					circle.setPosition(worldPos);
					circle.setFillColor(sf::Color::Transparent);
					circle.setOutlineColor(sf::Color::Red);
					circle.setOutlineThickness(1);
					m_window.draw(circle);
				}
				else if (c.type() == Collider2D::ShapeType::Box)
				{
					sf::RectangleShape rect;
					auto shape = std::get<Collider2D::Box>(c.shape);
					rect.setSize({ shape.halfSize.x * 2, shape.halfSize.y * 2 });
					rect.setOrigin({ shape.halfSize.x, shape.halfSize.y });
					rect.setPosition(worldPos);
					rect.setFillColor(sf::Color::Transparent);
					rect.setOutlineColor(sf::Color::Red);
					rect.setOutlineThickness(1);
					m_window.draw(rect);
				}
				else if (c.type() == Collider2D::ShapeType::Polygon)
				{
					sf::ConvexShape polygon;
					auto shape = std::get<Collider2D::Polygon>(c.shape);
					polygon.setPointCount(shape.points.size());
					for (int i = 0; i < shape.points.size(); i++)
					{
						polygon.setPoint(i, shape.points[i]);
					}
					polygon.setPosition(worldPos);
					polygon.setFillColor(sf::Color::Transparent);
					polygon.setOutlineColor(sf::Color::Red);
					polygon.setOutlineThickness(1);
					m_window.draw(polygon);
				}
				else if (c.type() == Collider2D::ShapeType::Capsule)
				{
					sf::ConvexShape capsule;
					auto shape = std::get<Collider2D::Capsule>(c.shape);
					capsule.setPointCount(30 * 2);
					int index = 0;
					float longueurCorpse = shape.height - shape.radius * 2;

					for (int i = 0; i < 30; i++)
					{
						float angle = 0.0f + (180.f* i / (30.f - 1));
						float angleRad = angle * (3.14159f / 180.0f);
						capsule.setPoint(i, 
							{ cos(angleRad) * shape.radius,
							((longueurCorpse / 2) + shape.radius) * sin(angleRad)});
					}

					for (int i = 0; i < 30; i++)
					{
						float angle = 180.0f + (180.f* i / (30.f - 1));
						float angleRad = angle * (3.14159f / 180.0f);
						capsule.setPoint(30 + i,
							{ cos(angleRad) * shape.radius,
							((longueurCorpse / 2) + shape.radius) * sin(angleRad)});
					}
					capsule.setPosition(worldPos);
					capsule.setFillColor(sf::Color::Transparent);
					capsule.setOutlineColor(sf::Color::Red);
					capsule.setOutlineThickness(1);
					m_window.draw(capsule);

				}
				else if (c.type() == Collider2D::ShapeType::Ellipse)
				{
					sf::ConvexShape ellipse;
					auto shape = std::get<Collider2D::Ellipse>(c.shape);
					ellipse.setPointCount(60);
					for (int i = 0; i < 60; i++)
					{
						float angleRad = (2.f * 3.14159f * i) / 60.f;

						float x = shape.radii.x * cos(angleRad);
						float y = shape.radii.y * sin(angleRad);
						ellipse.setPoint(i, { x, y });

					}
					ellipse.setPosition(worldPos);
					ellipse.setFillColor(sf::Color::Transparent);
					ellipse.setOutlineColor(sf::Color::Red);
					ellipse.setOutlineThickness(1);
					m_window.draw(ellipse);

				}

			});
    }

private:
    sf::RenderWindow& m_window;
};