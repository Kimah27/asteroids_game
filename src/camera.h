#ifndef CAMERA_H
#define CAMERA_H

#include "myMath.h"

typedef struct Camera { Vec3 pos; float rotation; float dist; float height; } Camera;

Camera camera;

void place_camera();
void update_camera_position();

#endif
