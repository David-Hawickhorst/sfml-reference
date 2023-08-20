#include "Player.h"
#include <iostream>

// section basics

#define PRINT_VEC2F(vec2f) \
    std::cout << #vec2f << ": (" << vec2f.x << ", " << vec2f.y << ")\n";

Player::Player() :
    movement_speed_(5.0f),
    bullet_velocity_(10.0f),
    curr_rotation_(Rotation::DOWN)
{
    // setup what the player will spawn in as
    shape_.setSize(sf::Vector2f(100, 50));
    shape_.setPosition(350, 275);
    shape_.setFillColor(sf::Color::Blue);
    shape_.setOrigin(shape_.getSize().x / 2, shape_.getSize().y / 2);  // make the center of the player the origin

    printDebug();
}

Player::~Player() {}


void Player::draw(sf::RenderWindow& window) {
    window.draw(shape_);
    for (auto& bullet : bullets_) {
        bullet.update();
        window.draw(bullet.shape);
    }

}

void Player::shoot() {
    // first vec is for the position of the bullet.
    // This will be the center of the player
    // need to take into account the rotation
    float current_rotation_angle = shape_.getRotation();

    sf::Vector2f curr_pose = shape_.getPosition();



    sf::Vector2f bullet_vel_vec = {0, bullet_velocity_};
    bullets_.emplace_back(shape_.getPosition(), bullet_vel_vec);
}

void Player::move(float xOffset, float yOffset) {
    shape_.move(xOffset, yOffset);
}

void Player::move(sf::Vector2f movement) {
    shape_.move(movement);
}

void Player::rotate(Rotation rotation) {
    shape_.setRotation((float)rotation);
    printDebug();
}


void Player::printDebug() const {
    using namespace std;
    PRINT_VEC2F(shape_.getOrigin())
//    cout << "Origin: (" << shape_.getOrigin().x << ", " << shape_.getOrigin().y << ")\n";
    PRINT_VEC2F(shape_.getPosition())
    cout << "Rotation: " << shape_.getRotation() << "\n";

    cout << "\n";
}

