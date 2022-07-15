#ifndef ASTEROIDS_H
#define ASTEROIDS_H

typedef struct Asteroid { Vec3 pos; Vec3 trajectory; float speed; float rotation; float rotationSpeed; float radius; int hitPoints; bool isAlive; bool isSpawned; bool inArena; } Asteroid;

#define ASTEROID_MIN_SIZE 10.0f
#define ASTEROID_MAX_SIZE 30.0f
#define ASTEROID_MIN_SPEED 0.0001f
#define ASTEROID_MAX_SPEED 0.0003f
#define ASTEROID_MIN_ROTATION -0.25f
#define ASTEROID_MAX_ROTATION 0.25f
#define ASTEROID_COLOUR 1.0f, 0.5f, 0.0f

int asteroidWave;

Asteroid asteroidArray[30];

void create_asteroids();
void draw_asteroids();
void move_asteroids();
void bouncies();
void asteroid_ship_collision();
void asteroid_bullet_check();
void asteroid_bullet_collision(int index);

#endif
