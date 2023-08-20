# Overview of game logic / flow


## EntityManager

- use Factory patter
- handle creation, storage, lifetime of ALL Entity objects

EntityManager functions:

- addEntity
- removeEntity
- storage
- bookKeeping

Ensure user cannot create its own Entities

Will store Entity objects in vector
```c++
typedef std::vector<std::shared_ptr<Entity>> EntityVector;
```

Will also store seperate vectors of Entity objects by their tag for quick retrieval
```c++
std::map<std::string, EntityVector>
```
### Entity Manager Implementation
```c++
typedef std::vector<std::shared_ptr<Entity>> EntityVec;
typedef std::map<std::string, EntityVec> EntityMap;

class EntityManager {
private:
    EntityVec entities_;
    EntityVec toAdd_;
    EntityMap entityMap_;
    size_t totalEntities_ = 0;
public:
    EntityManager();
    void update();
    std::shared_ptr<Entity> addEntity(const std::string& tag);
    EntityVec& getEntities();
    EntityVec& getEntities(const std::string& tag);
};

```


### Entity Tags

- may want to group Entities
- Entity is "tagged" by a string
  - an Enum or something would be more efficient, but doesn't matter for us. Maybe for AAA 
- Tile, Player, Bullet, Enemy
- EntityManager have function for quickly getting Entites of a given tag
- Ex: loop over all bullets



## Entity Implementation

```c++
class Entity {
  private:
    const size_t id_ = 0;
    const std::string tag_ = "Default";
    bool alive_ = true;
    
  public:
    std::shared_ptr<CTransform> cTransform;
    std::shared_ptr<CName> cName;
    std::shared_ptr<CShape> cShape;
    std::shared_ptr<CBBox> cBBox;
    Entity(const std::string& tag, size_t id);
};

```

## Basic game state flow

- poll for events (user input, key presses, mouse clicks etc.)
- update states (calculate new positions, collisions, spawn new objects, etc.)
- clear frame
- draw new frame (this uses the updated states)
- display new frame to window (screen)


## Planning

### Main Game Loop

```c++
int main() {
    window = createWindow();
    while(window.isOpen()) {
        while (window.pollEvents()) {
            // do whatever is needed when mouse clicked, key pressed, ...
        }
        
        // clears the current frame, so we can draw a new one
        window.clear();
        
        // fake function but update all needed object states here
        updateStates();

        // draw the updated objects
        window.drawObjects();
        
        // display them to the screen
        window.display();
    }
    return 0;
}

```

### Game Objects

Things that will be moving around on the screen

- Player(s)
- Enemy(s)
- ?PowerUps
- ?Pickups (health ... ?)

Common things between game objects (they all need to do these things)

- update() -> modify states
- draw() -> put them on the window
- remove() -> remove them from the screen
- collisionCheck() -> might not belong here, might go in different class. Need to check how collisions checks work with this lib

Potential abstract class for game objects?
```c++
class GameObject {
    virtual void update() = 0;
    virtual void draw() = 0;
};
```

