//
// Created by david on 8/17/2023.
//

#ifndef SFML_EXAMPLES_DRAWING_PLAYER_H
#define SFML_EXAMPLES_DRAWING_PLAYER_H

#include "../bullet/Bullet.h"

#include <SFML/Graphics.hpp>
#include <vector>

enum class Rotation {
    DOWN = 0,
    LEFT = 90,
    UP = 180,
    RIGHT = 270
};


class Player {
public:
    Player();
    ~Player();

    // game functions
    void update();
    void draw(sf::RenderWindow& window);
    void shoot();

    // movement, rotation, position related
    void move(sf::Vector2f movement);
    void move(float xOffset, float yOffset);
    void rotate(Rotation rotation);

    // setters, getters, etc
    float movementSpeed() const { return movement_speed_; }
    void printDebug() const;

private:
    // drawables
    sf::RectangleShape shape_;
    sf::ConvexShape triangle_;

    // game things
    float movement_speed_;
    float bullet_velocity_;
    std::vector<Bullet> bullets_;

    // pose stuff
    Rotation curr_rotation_;
};

#endif //SFML_EXAMPLES_DRAWING_PLAYER_H
