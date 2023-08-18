/// \brief An example of how to have a pure virtual class (interface) for classes that will draw something to the window

#ifndef SFML_EXAMPLES_DRAWING_DRAWABLEOBJECT_H
#define SFML_EXAMPLES_DRAWING_DRAWABLEOBJECT_H

#include <SFML/Graphics.hpp>


class DrawableObject {
public:
    virtual void draw(sf::RenderWindow& window) = 0;
};

#endif //SFML_EXAMPLES_DRAWING_DRAWABLEOBJECT_H
