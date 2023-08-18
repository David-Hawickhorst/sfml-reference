//
// Created by david on 8/17/2023.
//

#ifndef SFML_EXAMPLES_DRAWING_PLAYER_H
#define SFML_EXAMPLES_DRAWING_PLAYER_H

#include "DrawableObject.h"

class Player : public DrawableObject {
public:
    // Con/De structors
    Player();
    ~Player();

    // game functions
    void draw(sf::RenderWindow& window) override;
    void move(float xOffset, float yOffset);


private:
    // drawables
    sf::RectangleShape boundingBox;
    sf::Sprite sprite;

    // game things
    float movement_speed = 5.0f;

public:
    //  Things like setters, getters, simple checks, etc. at the bottom, so they're easier to ignore
    sf::Vector2f getCurrentPosition() const {
        return sprite.getPosition();
    }

    float movementSpeed() const { return movement_speed; }
};

#endif //SFML_EXAMPLES_DRAWING_PLAYER_H
