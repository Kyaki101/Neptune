#include <iostream>
#include <SFML/Graphics.hpp>
#include "linearAlgebra/vector2D.h"
#include "system/state.h"
#include "system/world.h"

// constexpr unsigned int WIDTH = 640;
// constexpr unsigned int HEIGHT = 360;

constexpr int WIDTH = 1000;
constexpr int HEIGHT = 600;

int main() {
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    const auto* vector = new LA::Vector2D(2, 3);
    std::cout << vector -> getX() << " " << vector -> getY() << std::endl;
    sf::RenderWindow * window = new sf::RenderWindow(sf::VideoMode({WIDTH, HEIGHT}),
        "Title",
        sf::State::Windowed,
        settings);

    window->setFramerateLimit(120);

    sf::CircleShape circle(20.0f);

    sf::CircleShape container(290.0f);
    container.setPointCount(200);
    container.setOrigin(container.getGeometricCenter());
    container.setOutlineThickness(3.0f);
    container.setFillColor(sf::Color(255, 0, 0, 0));
    container.setOutlineColor(sf::Color::Black);
    container.setPosition({WIDTH / 2.0f, HEIGHT / 2.0f});

    circle.setOrigin(circle.getGeometricCenter());
    circle.setPosition({WIDTH / 2.0f, HEIGHT / 2.0f});
    circle.setFillColor(sf::Color::Black);
    circle.setOutlineThickness(2.0f);
    circle.setOutlineColor(sf::Color::Red);
    systemS::State test({ WIDTH / 2.0f + 90, HEIGHT / 2.0f }, 5);

    systemS::World::addState(test);

    while (window -> isOpen()) {
        while (const std::optional event = window -> pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window -> close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                    window -> close();
                }
            }
        }
        systemS::World::updateSystem();
        auto pos = systemS::World::getStates()[0].getPosition();

        window -> clear(sf::Color::White);

        circle.setPosition({(float)pos.getX(), (float)pos.getY()});

        //drawing
        window->draw(circle);
        window->draw(container);

        window -> display();
    }


    delete window;
}
