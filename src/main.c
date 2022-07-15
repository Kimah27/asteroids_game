#include "main.h"

int main(int argc, char** argv)
{
    set_initial();
    init_app(&argc, argv);
    glutMainLoop();
    return(EXIT_SUCCESS);
}

void set_initial()
{
    oldTimeSinceStart = 0;
    showAxes = false;

    camera.rotation = 0.0;
    camera.dist = 35.0;
    camera.height = 15.0;

    movementSpeed = MOVEMENT_SPEED;
    turningSpeed = TURNING_SPEED;
    wingRotation = WING_ROTATION;
    ship.yRotation = 90.0f;
    ship.radius = SHIP_RADIUS;
    ship.isAlive = true;

    bulletSpeed = BULLET_SPEED;
    shootIndex = 0;
    bulletCount = BULLET_NUMBER;

    asteroidWave = 0;
}

void init_app(int* argcp, char** argv)
{
    glutInit(argcp, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(1920, 1080);
    glutCreateWindow("s3685738 - Assignment 2");
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);
    glutIdleFunc(on_idle);

    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboard_up);
    glutMouseFunc(mouse);
    glutMouseWheelFunc(mouse_wheel);

    init_lighting();

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_NORMALIZE);
}

void init_lighting()
{
    float ambient[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    //float diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    //float specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    glEnable(GL_LIGHTING);
    //glShadeModel(GL_FLAT);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    //glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    //glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    glEnable(GL_LIGHT0);
}

void on_reshape(int width, int height)
{
    double aspect = (float)width / height;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, width, height);
    gluPerspective(45.0, aspect, 1.0, 1000);
}

void on_display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    render_frame();
    glutSwapBuffers();

    int err;
    while ((err = glGetError()) != GL_NO_ERROR)
    {
        printf("Error: %s\n", gluErrorString(err));
    }
}

void on_idle()
{
    update_camera_position();
    glutPostRedisplay();
}

void render_frame()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    place_camera();
    calculateDeltaTime();
    timer();

    draw_axes();
    draw_arena();
    ship_arena_collision();

    draw_ship();
    move_ship();
    draw_bullets();
    shooting();
    move_bullets();

    draw_asteroids();
    move_asteroids();
    bouncies();
    asteroid_ship_collision();
    asteroid_bullet_check();

    draw_particles();
    move_particles();

    next_level();
    game_over();
}

void draw_axes()
{
    if (showAxes)
    {
        glDisable(GL_LIGHTING);
        glBegin(GL_LINES);
            // X axes
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(-100.0f, 0.0f, 0.0f);
            glVertex3f(100.0f, 0.0f, 0.0f);
            // Y axes
            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex3f(0.0f, -100.0f, 0.0f);
            glVertex3f(0.0f, 100.0f, 0.0f);
            // Z axes
            glColor3f(0.0f, 0.0f, 1.0f);
            glVertex3f(0.0f, 0.0f, -100.0f);
            glVertex3f(0.0f, 0.0f, 100.0f);
        glEnd();
        glEnable(GL_LIGHTING);
    }
}

void game_over()
{
    if (ship.isAlive)
    {
        gameOver = time + GAME_OVER;
    }

    if (!ship.isAlive)
    {
        if (time > gameOver)
        {
            ship.pos.x = 0.0f;
            ship.pos.y = 0.0f;
            ship.pos.z = 0.0f;
            ship.yRotation = 90.0f;
            ship.zRotation = 0.0f;

            ship.isAlive = true;

            asteroidWave = 0;
            for (int i = 0; i < 30; i++)
            {
                asteroidArray[i].isAlive = false;
                asteroidArray[i].isSpawned = false;
                asteroidArray[i].inArena = false;
            }

        }
    }
}

void next_level()
{
    int count = 0;

    for (int i = 0; i <= asteroidWave; i++)
    {
        if (asteroidArray[i].isSpawned && !asteroidArray[i].isAlive)
        {
            count++;
        }

        if (count == asteroidWave)
        {
            create_asteroids();

            asteroidWave++;
        }
    }
}
