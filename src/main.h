#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#if _WIN32
#   include <Windows.h>
#endif

#if __APPLE__
#   include <OpenGL/gl.h>
#   include <OpenGL/glu.h>
#   include <GLUT/glut.h>
#else
#   include <GL/gl.h>
#   include <GL/glu.h>
#   include <GL/glut.h>
#endif

#include "myMath.h"
#include "input.h"
#include "camera.h"
#include "ship.h"
#include "arena.h"
#include "asteroids.h"
#include "explosions.h"

#define GAME_OVER 2000
bool showAxes;
int gameOver;

int main(int argc, char** argv);
void set_initial();
void init_app(int* argcp, char** argv);
void init_lighting();
void on_reshape(int width, int height);
void on_display();
void on_idle();
void render_frame();
void game_over();
void next_level();
void draw_axes();

#endif
