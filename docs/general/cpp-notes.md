# Notes about some c++ stuff

## Virtual Funcs

virtual
- virtual funcs can be overridden in derived classes
- the most derived implementation of the virtual function will be used
- `virtual void foo();`

pure virtual
- pure virtual makes it an abstract class and derived classes must provide an implementation for that function
- make pure virtual by adding = 0 at end of function
- `virtual void foo() = 0;`
- if the state of the object should not be modified via the function, add a const qualifier
- `virtual void foo() const = 0;`

### Actual Example
this is how I used the abstract class in my code. I wanted to be able to label certain classes as "drawable" meaning that those classes would be putting something on the screen that would need to be called with something like `window.draw(objectToDraw);`.

I didn't want to have to write that line for every single object that I want drawn. Especially if objects will be dynamically created.

I created an abstract class like so
```c++
#include <SFML/Graphics.hpp>
class Drawable {
public:
    virtual void draw(sf::RenderWindow& window) = 0;
};
```

An example of a drawable object would be the player so here is the simple implementation of that
```c++
#include "Drawable.h"
class Player : public Drawable {
public:
    Player();
    ~Player();
    void draw(sf::RenderWindow& window) { window.draw(shape_)};  // this implements the required draw() from Drawable
private:
    sf::RectangleShape shape_;  // the object on screen to represent the player
};
```

To be able to make it easier to update every object that needs to be drawn, I created something that would manage all the draws
```c++
#include "Drawable.h"
class DrawableManager {
public:
    void drawObjects(sf::RenderWindow& window) const {
        for (const auto& drawable : drawables) {
            drawable.draw(window);
        }
    }
    
    void add(Drawable* drawable) {
        drawables.push_back(drawable);
    }
private:
    std::vector<Drawable*> drawables;
};
```





