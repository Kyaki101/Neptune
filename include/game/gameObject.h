//
// Created by Emanuel Rojas on 1/18/26.
//

#ifndef CMAKE_PROJECT_TEMPLATE_GAMEOBJECT_H
#define CMAKE_PROJECT_TEMPLATE_GAMEOBJECT_H
#include <SFML/Graphics/CircleShape.hpp>

#include "physics/circleCollider.h"
#include "physics/physicsBody.h"

namespace game {
    class GameObject {
    private:
        sf::CircleShape g;
        sf::Color color;
        physics::PhysicsBody pb;
        physics::BodyType type;
    public:
        GameObject(
                physics::BodyType type,
                double radius,
                sf::Color color,
                LA::Vector2D position,
                LA::Vector2D velocity)
                : type(type),
                  g(radius),
                  color(color),
                  pb(physics::PhysicsBody(
                      systemS::State(position, velocity, 1),
                      type,
                      std::make_unique<physics::CircleCollider>(radius)))
        {
            g.setFillColor(color);
            g.setPosition({(float) position.getX(), (float) position.getY()});
            g.setOrigin(g.getGeometricCenter());
        }
    };
}

#endif //CMAKE_PROJECT_TEMPLATE_GAMEOBJECT_H