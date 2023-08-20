# Intro to ECS (Entities, Components, Systems) Architecture

## Entity Component

- Entity: object in game
- Component: Properites that can attach to Entities
  - examples: position, speed
  - bounding box
  - health, weapon, damage

## ECS Game Programming

- composition based design
- Entity: Anything in game
  - player, platform, tile, bullet, enemy
- Component: properties attached to entites
  - position, texture, animation, health, gravity
  - componentes are pure data
    - This means there is no logic attached to a component such as move logic
- Systems: code / logic that drives behavior
  - movement, rendering, sound, physics

## ECS Example Entity / Components

- Player
  - Pose, speeds, bbox, sprite, health, gravity, input
- Enemy
  - pose, speed, bbox, sprite, health, AI
- Bullet
  - pose, speed, angle, bbox, sprite, damage, lifespan
- Tile
  - pose, bbox, sprite


## ECS Example System

- Movement
  - for (e : entities) { e.pose += e.speed; }
- Collision
  - for (b : bullets)
    - for (e : enemies)
      - if (Physics:IsCollision(b, e))
        - e.health -= b.damage;
        - b.destroy();
- Rendering 
  - for (e : entities) { window.draw(e.sprite, e.pose); }


## Engine Architecture

- GameEngine
  - Scene
    - Systems
    - EntityManger
      - Entity
        - Component


## Component Storage Options

1. only 1 of every component per entity, store a variable for each compnent type
2. store single container of Components. Then use addComponent, getComponent funcs for more generality


### Example Component Class

quicker setup, worse scaling

```c++
class Entity {
public:
    shard_ptr<CTransform> cTransform;
    shard_ptr<CName> cName;
    shard_ptr<CShape> cShape;
    shard_ptr<cBBox> cBBox;
    
    Entity() {}
    ~Entity() { /* free memory properly with RAII standars */ }
};
```


### Component Collection

scales better, requires many more base classes and whatnot
```c++
class Entity {
private:
    vector<Component> components_;
public:
    Entity() {}
    void addComponent<T>(args);
    void getComponent<T>(args);
};
```


### CTransform example

```c++
class CTransform {
public:
    Vec2 position = {0, 0};
    Vec2 velocity = {0, 0};
    CTransform() {}
    CTransform(const Vec2 &p, const Vec2 &v)
        : position(p), velocity(v) {}
};
```

### CShape exapmle class

```c++
class CShape {
public:
    sf::CircleShape shape;
    CShape() {}
};
```


