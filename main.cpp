// project includes
#include "player/Player.h"

// 3rd party libs
#include <SFML/Graphics.hpp>

// std includes
#include <iostream>


#define PRINT_VEC2F(vec2f) \
    std::cout << #vec2f << ": (" << vec2f.x << ", " << vec2f.y << ")" << std::endl;


int main() {
    // create the main window for the game
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;
    std::string window_title = "SFML Window Title";

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), window_title);
    window.setFramerateLimit(60);  // window.setVerticalSyncEnabled(true);

    Player player;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // handle events
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { window.close(); }

            /* Player Movement across screen
             The origin (0, 0) is located in the top-left corner of the window.
             The x-coordinate increases as you move to the right.
             The y-coordinate increases as you move down.
             So, when you want to move something to the right, you are indeed moving in the positive x-direction.
             If you want to move something downwards, you are moving in the positive y-direction.

             Visual representation
             (0, 0) -----> +X
               |
               |
               |
               v
              + Y
             */
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                player.move(0, -player.movementSpeed());
                player.rotate(Rotation::UP);
            }
            // down
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                player.move(0, player.movementSpeed());
                player.rotate(Rotation::DOWN);

            }
            // left
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                player.move(-player.movementSpeed(), 0);
                player.rotate(Rotation::LEFT);

            }
            // right
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                player.move(player.movementSpeed(), 0);
                player.rotate(Rotation::RIGHT);

            }


            // shoot
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                player.shoot();

            }
        }

        // clear the screen to drawObject new stuff
        window.clear();

        // drawObject any elements that need to be drawn
        player.draw(window);

        // display the new frame to the window
        window.display();
    }
    return 0;
}
