#include "main.h"
#include "camera.h"

void place_camera()
{
    gluLookAt(camera.pos.x, camera.pos.y, camera.pos.z, ship.pos.x, ship.pos.y, ship.pos.z, 0, 1, 0);
}

void update_camera_position()
{
    float yRotation = (ship.yRotation - 90.0f) * 3.14f / 180.0f;
    //float yRotation = (ship.yRotation) * 3.14f / 180.0f;
    float zRotation = (ship.zRotation + 80.0f) * 3.14f / 180.0f;

    camera.pos.x = ship.pos.x + camera.dist * cosf(yRotation) * sinf(zRotation);
    camera.pos.y = ship.pos.y + camera.dist * cosf(zRotation);
    camera.pos.z = ship.pos.z + camera.dist * sinf(yRotation) * sinf(zRotation);
}