#ifndef SHIP_H
#define SHIP_H

typedef struct Ship { Vec3 pos; float yRotation; float zRotation; float radius; bool isAlive; } Ship;
typedef struct Bullets { Vec3 pos; float yRotation; float zRotation; float size; bool isActive; float speed; float rotation; } Bullets;

#define SHIP_SIZE_X 3.0f
#define SHIP_SIZE_Y 1.0f
#define SHIP_SIZE_Z 1.0f
#define WING_SIZE_X 1.0f
#define WING_SIZE_Y 0.1f
#define WING_SIZE_Z 2.0f
#define WING_ROTATION 45.0f
#define MOVEMENT_SPEED 0.05f
#define TURNING_SPEED 0.1f
#define SHIP_RADIUS 3.0f
#define SHIP_WARNING_RADIUS 20.0f
#define PLAYER_FIRE_RATE 1000
#define BULLET_NUMBER 5
#define BULLET_SPEED 1.0f
#define BULLET_ROTATION 0.25f
#define SHIP_BODY_COLOUR 1.0f, 0.0f, 0.0f
#define SHIP_WING_COLOUR 0.0f, 0.0f, 1.0f
#define BULLET_COLOUR 0.0f, 1.0f, 0.0f
#define BULLET_SIZE 2.0f

float movementSpeed;
float turningSpeed;
float wingRotation;

int shootIndex;
bool canShoot;
int nextShot;
int bulletCount;
float bulletSpeed;

Ship ship;
Bullets bullets[5];

void draw_ship();
void draw_ship_body();
void draw_left_wing();
void draw_right_wing();
void move_ship();
void move_ship_forward();
void turn_ship_up();
void turn_ship_down();
void turn_ship_left();
void turn_ship_right();
void draw_bullets();
void shooting();
void move_bullets();
void add_point_light();

#endif
