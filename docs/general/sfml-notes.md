# How to do certain things in sfml

## Getting mouse postion
```c++
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        sf::Vector2i globalMousePos = sf::Mouse::getPosition(); // Global mouse position
        sf::Vector2i windowMousePos = sf::Mouse::getPosition(window); // Local mouse position in the window

        // Convert local mouse position to global
        sf::Vector2i localToGlobal = window.mapCoordsToPixel(sf::Vector2f(windowMousePos));

        window.clear();

        // Draw objects onto the window
        // ...

        window.display();
    }

    return 0;
}
```

## normalize event polling so that mouse movement doesn't interfere with key input
```c++
int main() {
    // ...

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Keyboard input handling
        float movementSpeed = 5.0f;

        sf::Vector2f movement(0.0f, 0.0f); // Movement vector for the player

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            movement.y -= movementSpeed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            movement.y += movementSpeed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            movement.x -= movementSpeed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            movement.x += movementSpeed;
        }

        // Normalize the movement vector to ensure consistent speed diagonally
        if (movement != sf::Vector2f(0.0f, 0.0f)) {
            float length = std::sqrt(movement.x * movement.x + movement.y * movement.y);
            movement /= length;
        }

        player.move(movement.x, movement.y);

        window.clear();

        // Draw objects onto the window
        // ...

        window.draw(player);

        window.display();
    }

    return 0;
}

```

## Collision Detection
```c++

/* General process for collision detection:
 * 1: need classes for each object that can collide. Player, enemy, projectile, etc
 * 2: Each game loop, check for collisions
 * 3: Removal Logic
 * 4: Update Loop - update positions of all game objects
 * 5: Draw - draw the remaining enemies, player, projectiles, etc
 * More: fancy algos such as: quad trees, spatial hashing to optimize collision checks
*/
///////////////////////////////////////////////////////////////////
// for rectangle objects
///////////////////////////////////////////////////////////////////
if (projectile.getGlobalBounds().intersects(enemy.getGlobalBounds())) {
    // this means a collision has been detected
    /*
     * perform whatever desired logic for collision such as...
     * decrease enemy health,
     * remove enemy from screen,
     * remove bullet from screen,
     * make explosion,
     * etc
     */
}

///////////////////////////////////////////////////////////////////
// for circle objects ( using distance between centers and radii)
///////////////////////////////////////////////////////////////////

sf::Vector2f projectileCenter = projectile.getPosition();
sf::Vector2f enemyCenter = enemy.getPosition();
float distance = std::sqrt(
std::pow(projectileCenter.x - enemyCenter.x, 2) +
std::pow(projectileCenter.y - enemyCenter.y, 2)
);
if (distance < projectileRadius + enemyRadius) {
// Collision detected
// Perform removal logic
}

///////////////////////////////////////////////////////////////////
// Removal logic
///////////////////////////////////////////////////////////////////

/*
 * When a collision is detected, you should remove the collided enemy from your game. You can do this by removing the enemy object from your list or container that holds all the enemies. Make sure to properly handle memory management (deleting or deallocating memory) if necessary.
 */
// Assuming you have a vector to store enemies
std::vector<Enemy> enemies;

// When collision is detected
// Find the index of the collided enemy
// ...
enemies.erase(enemies.begin() + indexOfCollidedEnemy);


```

