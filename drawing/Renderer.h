//
// Created by david on 8/17/2023.
//

#ifndef SFML_EXAMPLES_DRAWING_RENDERER_H
#define SFML_EXAMPLES_DRAWING_RENDERER_H
#include "DrawableObject.h"

class Renderer {
public:
    void draw(DrawableObject& drawable, sf::RenderWindow& window) {
        drawable.draw(window);
    }
};


#endif //SFML_EXAMPLES_DRAWING_RENDERER_H
