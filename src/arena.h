#ifndef ARENA_H
#define ARENA_H

#define WALL_DIVISIONS 20
#define ARENA_SCALE 10
#define ARENA_COLOUR 0.1f, 0.1f, 0.1f
#define ARENA_WARNING_COLOUR 1.0f, 0.0f, 0.0f

void draw_arena();
void draw_wall();
void ship_arena_collision();

#endif
