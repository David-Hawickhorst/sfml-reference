#pragma once

#include <memory>
#include <string>

class Entity {
public:
    Entity(const std::string& tag, size_t id);

private:
    const size_t id_ = 0;
    std::string tag_ = "Default";
    bool alive_ = true;
};


Entity::Entity(const std::string& tag, size_t id) :
    tag_(tag),
    id_(id) {

}