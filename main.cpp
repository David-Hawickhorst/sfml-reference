// project includes
#include "drawing/Renderer.h"
#include "drawing/Player.h"

// 3rd party libs
#include <SFML/Graphics.hpp>

// std includes
#include <iostream>

// main window stuff
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

int main() {
    std::string window_title = "SFML Window Title";  // making this non-const because maybe I want to change it?

    // create the main window for the game
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), window_title);

    Renderer renderer;

    Player player;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                player.move(0, -player.movementSpeed());
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                player.move(0, player.movementSpeed());
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                player.move(-player.movementSpeed(), 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                player.move(player.movementSpeed(), 0);
            }
        }

        // clear the screen to draw new stuff
        window.clear();

        // draw any elements that need to be drawn
        renderer.draw(player, window);

        // display the new frame to the window
        window.display();

    }



    return 0;
}
