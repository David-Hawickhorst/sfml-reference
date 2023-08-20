//
// Created by david on 8/18/2023.
//

#include "Bullet.h"

Bullet::Bullet(sf::Vector2f startPose, sf::Vector2f vel) :
    velocity(vel) {
    shape.setSize(sf::Vector2f(5, 5));
    shape.setPosition(startPose);
}

void Bullet::update() {
    shape.move(velocity);
}

