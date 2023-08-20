//
// Created by david on 8/18/2023.
//

#pragma once

#include <SFML/Graphics.hpp>

class Bullet
{
public:
    Bullet(sf::Vector2f startPose, sf::Vector2f velocity_vec);

    void update();

    void setSize(sf::Vector2f size) { shape.setSize(size); }

    sf::RectangleShape shape;
    sf::Vector2f velocity;

};
