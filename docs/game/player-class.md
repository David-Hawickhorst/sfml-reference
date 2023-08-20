# Player Class

## movement stuff

have enum for amount to rotate like 
```c++
enum class Rotations {
    DOWN = 0,
    LEFT = 90,
    UP = 180,
    RIGHT = 270
};
```

## shooting

- spawn bullet at center of player
- based on rotation, send bullet in that direction