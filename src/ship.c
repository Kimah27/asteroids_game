#include "main.h"
#include "ship.h"

void draw_ship()
{
	if (ship.isAlive)
	{
		glPushMatrix();
		glTranslatef(ship.pos.x, ship.pos.y, ship.pos.z);
		glRotatef(-ship.yRotation + 90.0f, 0.0, 1.0, 0.0);
		glRotatef(-ship.zRotation, 0.0, 0.0, 1.0);
		draw_ship_body();
		draw_left_wing();
		draw_right_wing();
		//add_point_light();
		glPopMatrix();
	}
}

void draw_ship_body()
{
	//float mat_ambient[] = { SHIP_BODY_COLOUR, 1.0f };
	float mat_diffuse[] = { SHIP_BODY_COLOUR, 1.0f };
	float mat_specular[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	//float mat_shininess[] = { 100.0 };

	//glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	//glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glPushMatrix();
	glBegin(GL_QUADS);
	// top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-SHIP_SIZE_X, SHIP_SIZE_Y, SHIP_SIZE_Z);
	glVertex3f(SHIP_SIZE_X, SHIP_SIZE_Y, SHIP_SIZE_Z);
	glVertex3f(SHIP_SIZE_X, SHIP_SIZE_Y, -SHIP_SIZE_Z);
	glVertex3f(-SHIP_SIZE_X, SHIP_SIZE_Y, -SHIP_SIZE_Z);
	// left
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(SHIP_SIZE_X, -SHIP_SIZE_Y, SHIP_SIZE_Z);
	glVertex3f(SHIP_SIZE_X, SHIP_SIZE_Y, SHIP_SIZE_Z);
	glVertex3f(-SHIP_SIZE_X, SHIP_SIZE_Y, SHIP_SIZE_Z);
	glVertex3f(-SHIP_SIZE_X, -SHIP_SIZE_Y, SHIP_SIZE_Z);
	// bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(SHIP_SIZE_X, -SHIP_SIZE_Y, SHIP_SIZE_Z);
	glVertex3f(-SHIP_SIZE_X, -SHIP_SIZE_Y, SHIP_SIZE_Z);
	glVertex3f(-SHIP_SIZE_X, -SHIP_SIZE_Y, -SHIP_SIZE_Z);
	glVertex3f(SHIP_SIZE_X, -SHIP_SIZE_Y, -SHIP_SIZE_Z);
	// right
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(SHIP_SIZE_X, SHIP_SIZE_Y, -SHIP_SIZE_Z);
	glVertex3f(SHIP_SIZE_X, -SHIP_SIZE_Y, -SHIP_SIZE_Z);
	glVertex3f(-SHIP_SIZE_X, -SHIP_SIZE_Y, -SHIP_SIZE_Z);
	glVertex3f(-SHIP_SIZE_X, SHIP_SIZE_Y, -SHIP_SIZE_Z);
	// back
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(SHIP_SIZE_X, SHIP_SIZE_Y, -SHIP_SIZE_Z);
	glVertex3f(SHIP_SIZE_X, SHIP_SIZE_Y, SHIP_SIZE_Z);
	glVertex3f(SHIP_SIZE_X, -SHIP_SIZE_Y, SHIP_SIZE_Z);
	glVertex3f(SHIP_SIZE_X, -SHIP_SIZE_Y, -SHIP_SIZE_Z);
	// front
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-SHIP_SIZE_X, -SHIP_SIZE_Y, SHIP_SIZE_Z);
	glVertex3f(-SHIP_SIZE_X, SHIP_SIZE_Y, SHIP_SIZE_Z);
	glVertex3f(-SHIP_SIZE_X, SHIP_SIZE_Y, -SHIP_SIZE_Z);
	glVertex3f(-SHIP_SIZE_X, -SHIP_SIZE_Y, -SHIP_SIZE_Z);
	glEnd();
	glPopMatrix();
}

void draw_left_wing()
{
	//float mat_ambient[] = { 0.0f, 0.0f, 1.0f, 1.0f };
	float mat_diffuse[] = { SHIP_WING_COLOUR, 1.0f };
	float mat_specular[] = { SHIP_WING_COLOUR, 1.0f };
	//float mat_shininess[] = { 100.0 };

	//glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	//glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glPushMatrix();
	glTranslatef(1.0f, 0.5f, 2.0f);
	glRotatef(-wingRotation, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	// top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-WING_SIZE_X, WING_SIZE_Y, WING_SIZE_Z);
	glVertex3f(WING_SIZE_X, WING_SIZE_Y, WING_SIZE_Z);
	glVertex3f(WING_SIZE_X, WING_SIZE_Y, -WING_SIZE_Z);
	glVertex3f(-WING_SIZE_X, WING_SIZE_Y, -WING_SIZE_Z);
	// left
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(WING_SIZE_X, -WING_SIZE_Y, WING_SIZE_Z);
	glVertex3f(WING_SIZE_X, WING_SIZE_Y, WING_SIZE_Z);
	glVertex3f(-WING_SIZE_X, WING_SIZE_Y, WING_SIZE_Z);
	glVertex3f(-WING_SIZE_X, -WING_SIZE_Y, WING_SIZE_Z);
	// bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(WING_SIZE_X, -WING_SIZE_Y, WING_SIZE_Z);
	glVertex3f(-WING_SIZE_X, -WING_SIZE_Y, WING_SIZE_Z);
	glVertex3f(-WING_SIZE_X, -WING_SIZE_Y, -WING_SIZE_Z);
	glVertex3f(WING_SIZE_X, -WING_SIZE_Y, -WING_SIZE_Z);
	// right
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(WING_SIZE_X, WING_SIZE_Y, -WING_SIZE_Z);
	glVertex3f(WING_SIZE_X, -WING_SIZE_Y, -WING_SIZE_Z);
	glVertex3f(-WING_SIZE_X, -WING_SIZE_Y, -WING_SIZE_Z);
	glVertex3f(-WING_SIZE_X, WING_SIZE_Y, -WING_SIZE_Z);
	// back
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(WING_SIZE_X, WING_SIZE_Y, -WING_SIZE_Z);
	glVertex3f(WING_SIZE_X, WING_SIZE_Y, WING_SIZE_Z);
	glVertex3f(WING_SIZE_X, -WING_SIZE_Y, WING_SIZE_Z);
	glVertex3f(WING_SIZE_X, -WING_SIZE_Y, -WING_SIZE_Z);
	// front
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-WING_SIZE_X, -WING_SIZE_Y, WING_SIZE_Z);
	glVertex3f(-WING_SIZE_X, WING_SIZE_Y, WING_SIZE_Z);
	glVertex3f(-WING_SIZE_X, WING_SIZE_Y, -WING_SIZE_Z);
	glVertex3f(-WING_SIZE_X, -WING_SIZE_Y, -WING_SIZE_Z);
	glEnd();
	glPopMatrix();
}

void draw_right_wing()
{
	//float mat_ambient[] = { 0.0f, 0.0f, 1.0f, 1.0f };
	float mat_diffuse[] = { SHIP_WING_COLOUR, 1.0f };
	float mat_specular[] = { SHIP_WING_COLOUR, 1.0f };
	//float mat_shininess[] = { 100.0 };

	//glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	//glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glPushMatrix();
	glTranslatef(1.0f, 0.5f, -2.0f);
	glRotatef(wingRotation, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	// top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-WING_SIZE_X, WING_SIZE_Y, WING_SIZE_Z);
	glVertex3f(WING_SIZE_X, WING_SIZE_Y, WING_SIZE_Z);
	glVertex3f(WING_SIZE_X, WING_SIZE_Y, -WING_SIZE_Z);
	glVertex3f(-WING_SIZE_X, WING_SIZE_Y, -WING_SIZE_Z);
	// left
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(WING_SIZE_X, -WING_SIZE_Y, WING_SIZE_Z);
	glVertex3f(WING_SIZE_X, WING_SIZE_Y, WING_SIZE_Z);
	glVertex3f(-WING_SIZE_X, WING_SIZE_Y, WING_SIZE_Z);
	glVertex3f(-WING_SIZE_X, -WING_SIZE_Y, WING_SIZE_Z);
	// bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(WING_SIZE_X, -WING_SIZE_Y, WING_SIZE_Z);
	glVertex3f(-WING_SIZE_X, -WING_SIZE_Y, WING_SIZE_Z);
	glVertex3f(-WING_SIZE_X, -WING_SIZE_Y, -WING_SIZE_Z);
	glVertex3f(WING_SIZE_X, -WING_SIZE_Y, -WING_SIZE_Z);
	// right
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(WING_SIZE_X, WING_SIZE_Y, -WING_SIZE_Z);
	glVertex3f(WING_SIZE_X, -WING_SIZE_Y, -WING_SIZE_Z);
	glVertex3f(-WING_SIZE_X, -WING_SIZE_Y, -WING_SIZE_Z);
	glVertex3f(-WING_SIZE_X, WING_SIZE_Y, -WING_SIZE_Z);
	// back
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(WING_SIZE_X, WING_SIZE_Y, -WING_SIZE_Z);
	glVertex3f(WING_SIZE_X, WING_SIZE_Y, WING_SIZE_Z);
	glVertex3f(WING_SIZE_X, -WING_SIZE_Y, WING_SIZE_Z);
	glVertex3f(WING_SIZE_X, -WING_SIZE_Y, -WING_SIZE_Z);
	// front
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-WING_SIZE_X, -WING_SIZE_Y, WING_SIZE_Z);
	glVertex3f(-WING_SIZE_X, WING_SIZE_Y, WING_SIZE_Z);
	glVertex3f(-WING_SIZE_X, WING_SIZE_Y, -WING_SIZE_Z);
	glVertex3f(-WING_SIZE_X, -WING_SIZE_Y, -WING_SIZE_Z);
	glEnd();
	glPopMatrix();
}

void move_ship()
{
	move_ship_forward();
	turn_ship_up();
	turn_ship_down();
	turn_ship_left();
	turn_ship_right();
}

void move_ship_forward()
{
	if (ship.isAlive)
	{
		if (movingForward)
		{
			float yRotation = (ship.yRotation + 90.0f) * 3.14f / 180.0f;
			float zRotation = (ship.zRotation + 90.0f) * 3.14f / 180.0f;

			ship.pos.x += cosf(yRotation) * sinf(zRotation) * movementSpeed * deltaTime;
			ship.pos.y -= cosf(zRotation) * movementSpeed * deltaTime;
			ship.pos.z += sinf(yRotation) * sinf(zRotation) * movementSpeed * deltaTime;

			if (wingRotation > 0)
			{
				wingRotation -= 0.5f;
			}
		}
		else if (!movingForward)
		{
			if (wingRotation < 45)
			{
				wingRotation += 0.25f;
			}
		}
	}
}

void turn_ship_up()
{
	if (ship.isAlive)
	{
		if (movingUp)
		{
			if (ship.zRotation < 70)
			{
				ship.zRotation += turningSpeed * deltaTime;
			}
		}
	}
}

void turn_ship_down()
{
	if (ship.isAlive)
	{
		if (movingDown)
		{
			if (ship.zRotation > -70)
			{
				ship.zRotation -= turningSpeed * deltaTime;
			}
		}
	}
}

void turn_ship_left()
{
	if (ship.isAlive)
	{
		if (turningLeft)
		{
			ship.yRotation -= turningSpeed * deltaTime;
		}
	}
}

void turn_ship_right()
{
	if (ship.isAlive)
	{
		if (turningRight)
		{
			ship.yRotation += turningSpeed * deltaTime;
		}
	}
}

void draw_bullets()
{
	//float mat_ambient[] = { 0.0f, 0.0f, 1.0f, 1.0f };
	float mat_diffuse[] = { BULLET_COLOUR, 1.0f };
	float mat_specular[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	//float mat_shininess[] = { 100.0 };

	//glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	//glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	for (int i = 0; i < bulletCount; i++)
	{
		if (bullets[i].isActive)
		{
			glPushMatrix();
			glTranslatef(bullets[i].pos.x, bullets[i].pos.y, bullets[i].pos.z);
			bullets[i].rotation += BULLET_ROTATION * deltaTime;
			glRotatef(-bullets[i].yRotation + 90.0f, 0.0f, 1.0f, 0.0f);
			glRotatef(-bullets[i].zRotation, 0.0f, 0.0f, 1.0f);
			glRotatef(bullets[i].rotation, 1.0f, 0.0f, 0.0f);
			//glutSolidSphere(1, 20, 20);
			glBegin(GL_QUADS);
			glNormal3f(1.0f, 0.0f, 0.0f);
			glVertex3f(BULLET_SIZE, -BULLET_SIZE, BULLET_SIZE);
			glVertex3f(BULLET_SIZE, -BULLET_SIZE, -BULLET_SIZE);
			glVertex3f(BULLET_SIZE, BULLET_SIZE, -BULLET_SIZE);
			glVertex3f(BULLET_SIZE, BULLET_SIZE, BULLET_SIZE);
			glEnd();
			glPopMatrix();
		}
	}
}

void shooting()
{
	if (mouseDown && ship.isAlive)
	{
		if (time > nextShot)
		{
			bullets[shootIndex].pos.x = ship.pos.x + sinf(-ship.zRotation * 3.14f / 180.0f) * 0.1f;
			bullets[shootIndex].pos.y = ship.pos.y + cosf(-ship.zRotation * 3.14f / 180.0f) * 0.1f;
			bullets[shootIndex].pos.z = ship.pos.z;

			bullets[shootIndex].yRotation = ship.yRotation;
			bullets[shootIndex].zRotation = ship.zRotation;

			bullets[shootIndex].isActive = true;
			bullets[shootIndex].speed = bulletSpeed;
			//bullets[shootIndex].speed = 0.02;

			bullets[shootIndex].rotation = BULLET_ROTATION;

			//bullets[shootIndex].facing.y = ship.yRotation;
			//bullets[shootIndex].facing.z = ship.zRotation;

			if (shootIndex == 4)
			{
				shootIndex = 0;
			}
			else
			{
				shootIndex++;
			}

			nextShot = time + PLAYER_FIRE_RATE;
		}
	}
}

void move_bullets()
{
	for (int i = 0; i < bulletCount; i++)
	{
		float yRotation = (bullets[i].yRotation + 90.0f) * 3.14f / 180.0f;
		float zRotation = (bullets[i].zRotation + 90.0f) * 3.14f / 180.0f;

		bullets[i].pos.x += cosf(yRotation) * sinf(zRotation) * bullets[i].speed * deltaTime;
		bullets[i].pos.y -= cosf(zRotation) * bullets[i].speed * deltaTime;
		bullets[i].pos.z += sinf(yRotation) * sinf(zRotation) * bullets[i].speed * deltaTime;
	}
}

void add_point_light()
{
	float ambient[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float position[] = { 0.0f, 0.0f, 0.0f, 1.0f };

	glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT1, GL_POSITION, position);
	glEnable(GL_LIGHT1);

	// Add point for reference
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glTranslatef(-4.0f, 0.0f, 0.0f);
	glPointSize(10);
	glBegin(GL_POINTS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glEnd();
	glPopMatrix();
	glEnable(GL_LIGHTING);
}
