#include "Player.h"

Player::Player() {
    // setup what the player will spawn in as
    boundingBox.setSize(sf::Vector2f(200, 100));
    boundingBox.setPosition(300, 250);
    boundingBox.setFillColor(sf::Color::Red);
}

Player::~Player() {}

void Player::draw(sf::RenderWindow& window) {
    window.draw(boundingBox);
}


void Player::move(float xOffset, float yOffset)
{
    sprite.move(xOffset, yOffset);
    boundingBox.move(xOffset, yOffset);
}

