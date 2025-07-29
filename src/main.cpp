#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>  // for sf::VideoMode and sf::Vector2u
#include "./../include/linear_algebra/vector2d.h"
#include <iostream>


int main() {
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(800, 600)), "SFML Window");
    linear_algebra::Vector2D tes(2.0, 2.0);
    std::cout << tes.getX() << std::endl;

    while (window.isOpen()) {
        std::optional<sf::Event::Closed> event;
        while (window.pollEvent()) {

        }

        window.clear();
        window.display();
    }

    return 0;
}

