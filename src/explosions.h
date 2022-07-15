#ifndef EXPLOSIONS_H
#define EXPLOSIONS_H

typedef struct Explosions { Vec3 pos; Vec3 direction; float size; Vec3 colour; float rotation; float rotationSpeed; float speed; float duration; bool isActive; } Explosions;

#define PARTICLE_COUNT 30
#define PARTICLE_MIN_SIZE 0.5f
#define PARTICLE_MAX_SIZE 1.5f
#define PARTICLE_MIN_SPEED 0.01f
#define PARTICLE_MAX_SPEED 0.05f
#define PARTICLE_MIN_ROTATION 45.0f
#define PARTICLE_MAX_ROTATION 180.0f
#define PARTICLE_MIN_ROTATION_SPEED 0.02f
#define PARTICLE_MAX_ROTATION_SPEED 0.8f
#define PARTICLE_MIN_DIRECTION 0.0f
#define PARTICLE_MAX_DIRECTION 360.0f
#define PARTICLE_DURATION 1.0f
#define PARTICLE_DECAY 0.005f

Explosions explosionsArray[PARTICLE_COUNT];

Vec3 explosionPosition;

void create_particles();
void draw_particles();
void move_particles();

#endif
