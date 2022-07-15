#include "main.h"
#include "arena.h"

void draw_arena()
{
    // Top wall
    glPushMatrix();
    if ((ship.pos.y + SHIP_WARNING_RADIUS) < (ARENA_SCALE * 10))
    {
        glColor3f(ARENA_COLOUR);
    }
    else
    {
        glColor3f(ARENA_WARNING_COLOUR);
    }
    glScalef(ARENA_SCALE, ARENA_SCALE, ARENA_SCALE);
    glTranslatef(-WALL_DIVISIONS / 2.0f, WALL_DIVISIONS / 2.0f, -WALL_DIVISIONS / 2.0f);
    draw_wall();
    glPopMatrix();
    // Bottom wall
    glPushMatrix();
    if ((ship.pos.y - SHIP_WARNING_RADIUS) > (-ARENA_SCALE * 10))
    {
        glColor3f(ARENA_COLOUR);
    }
    else
    {
        glColor3f(ARENA_WARNING_COLOUR);
    }
    glScalef(ARENA_SCALE, ARENA_SCALE, ARENA_SCALE);
    glTranslatef(-WALL_DIVISIONS / 2.0f, -WALL_DIVISIONS / 2.0f, -WALL_DIVISIONS / 2.0f);
    draw_wall();
    glPopMatrix();
    // Left wall
    glPushMatrix();
    if ((ship.pos.z + SHIP_WARNING_RADIUS) < (ARENA_SCALE * 10))
    {
        glColor3f(ARENA_COLOUR);
    }
    else
    {
        glColor3f(ARENA_WARNING_COLOUR);
    }
    glScalef(ARENA_SCALE, ARENA_SCALE, ARENA_SCALE);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glTranslatef(-WALL_DIVISIONS / 2.0f, WALL_DIVISIONS / 2.0f, -WALL_DIVISIONS / 2.0f);
    draw_wall();
    glPopMatrix();
    // Right wall
    glPushMatrix();
    if ((ship.pos.z - SHIP_WARNING_RADIUS) > (-ARENA_SCALE * 10))
    {
        glColor3f(ARENA_COLOUR);
    }
    else
    {
        glColor3f(ARENA_WARNING_COLOUR);
    }
    glScalef(ARENA_SCALE, ARENA_SCALE, ARENA_SCALE);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glTranslatef(-WALL_DIVISIONS / 2.0f, -WALL_DIVISIONS / 2.0f, -WALL_DIVISIONS / 2.0f);
    draw_wall();
    glPopMatrix();
    // Front wall
    glPushMatrix();
    if ((ship.pos.x + SHIP_WARNING_RADIUS) < (ARENA_SCALE * 10))
    {
        glColor3f(ARENA_COLOUR);
    }
    else
    {
        glColor3f(ARENA_WARNING_COLOUR);
    }
    glScalef(ARENA_SCALE, ARENA_SCALE, ARENA_SCALE);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glTranslatef(-WALL_DIVISIONS / 2.0f, -WALL_DIVISIONS / 2.0f, -WALL_DIVISIONS / 2.0f);
    draw_wall();
    glPopMatrix();
    // Back wall
    glPushMatrix();
    if ((ship.pos.x - SHIP_WARNING_RADIUS) > (-ARENA_SCALE * 10))
    {
        glColor3f(ARENA_COLOUR);
    }
    else
    {
        glColor3f(ARENA_WARNING_COLOUR);
    }
    glScalef(ARENA_SCALE, ARENA_SCALE, ARENA_SCALE);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glTranslatef(-WALL_DIVISIONS / 2.0f, WALL_DIVISIONS / 2.0f, -WALL_DIVISIONS / 2.0f);
    draw_wall();
    glPopMatrix();
}

void draw_wall()
{
    glDisable(GL_LIGHTING);
    glBegin(GL_LINES);
    for (int i = 0; i <= WALL_DIVISIONS; i++)
    {
        glVertex3f((float)i, 0.0, 0.0);
        glVertex3f((float)i, 0, WALL_DIVISIONS);
        glVertex3f(0, 0, (float)i);
        glVertex3f(WALL_DIVISIONS, 0, (float)i);
    };
    glEnd();
    glEnable(GL_LIGHTING);
}

void ship_arena_collision()
{
    if (ship.pos.y + (SHIP_RADIUS) > (ARENA_SCALE * 10) || ship.pos.y - (SHIP_RADIUS) < (-ARENA_SCALE * 10) ||
        ship.pos.z + (SHIP_RADIUS) > (ARENA_SCALE * 10) || ship.pos.z - (SHIP_RADIUS) < (-ARENA_SCALE * 10) ||
        ship.pos.x + (SHIP_RADIUS) > (ARENA_SCALE * 10) || ship.pos.x - (SHIP_RADIUS) < (-ARENA_SCALE * 10))
    {
        if (ship.isAlive)
        {
            explosionPosition.x = ship.pos.x;
            explosionPosition.y = ship.pos.y;
            explosionPosition.z = ship.pos.z;
            create_particles();
        }

        ship.isAlive = false;
    }
}