#include "main.h"
#include "explosions.h"

void create_particles()
{
	for (int j = 0; j <= asteroidWave; j++)
	{
		for (int i = 0; i < PARTICLE_COUNT; i++)
		{
			explosionsArray[i].pos.x = explosionPosition.x;
			explosionsArray[i].pos.y = explosionPosition.y;
			explosionsArray[i].pos.z = explosionPosition.z;

			// Random particle size
			float minSize = PARTICLE_MIN_SIZE;
			float maxSize = PARTICLE_MAX_SIZE;
			explosionsArray[i].size = (maxSize - minSize) * ((float)rand() / (float)RAND_MAX) + minSize;

			// Random particle speed
			float minSpeed = PARTICLE_MIN_SPEED;
			float maxSpeed = PARTICLE_MAX_SPEED;
			explosionsArray[i].speed = (maxSpeed - minSpeed) * ((float)rand() / (float)RAND_MAX) + minSpeed;

			// Random particle rotation
			float minRot = PARTICLE_MIN_ROTATION;
			float maxRot = PARTICLE_MAX_ROTATION;
			explosionsArray[i].rotation = (maxRot - minRot) * ((float)rand() / (float)RAND_MAX) + minRot;

			// Random particle rotation speed
			float minRotSpeed = PARTICLE_MIN_ROTATION_SPEED;
			float maxRotSpeed = PARTICLE_MAX_ROTATION_SPEED;
			explosionsArray[i].rotationSpeed = (maxRotSpeed - minRotSpeed) * ((float)rand() / (float)RAND_MAX) + minRotSpeed;

			// Random partical direction
			explosionsArray[i].direction.x = 2.0f * ((float)rand() / (float)RAND_MAX) - 1.0f;
			explosionsArray[i].direction.y = 2.0f * ((float)rand() / (float)RAND_MAX) - 1.0f;
			explosionsArray[i].direction.z = 2.0f * ((float)rand() / (float)RAND_MAX) - 1.0f;

			// Random partical colour
			explosionsArray[i].colour.x = (1 - 0) * ((float)rand() / (float)RAND_MAX);
			explosionsArray[i].colour.y = (1 - 0) * ((float)rand() / (float)RAND_MAX);
			explosionsArray[i].colour.z = (1 - 0) * ((float)rand() / (float)RAND_MAX);

			explosionsArray[i].duration = PARTICLE_DURATION;

			explosionsArray[i].isActive = true;
		}
	}
}

void draw_particles()
{
	for (int i = 0; i < PARTICLE_COUNT; i++)
	{
		if (explosionsArray[i].isActive)
		{
			//float mat_ambient[] = { 0.0f, 0.0f, 1.0f, 1.0f };
			float mat_diffuse[] = { explosionsArray[i].colour.x, explosionsArray[i].colour.y, explosionsArray[i].colour.z, explosionsArray[i].duration };
			float mat_specular[] = { 0.0f, 0.0f, 0.0f, 0.0f };
			//float mat_shininess[] = { 100.0 };

			//glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
			//glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

			glPushMatrix();
			glTranslatef(explosionsArray[i].pos.x, explosionsArray[i].pos.y, explosionsArray[i].pos.z);
			explosionsArray[i].rotation += explosionsArray[i].rotationSpeed * deltaTime;
			glRotatef(explosionsArray[i].rotation, 1, 1, 1);

			//glutSolidSphere(explosionsArray[i].size, 20, 20);
			glBegin(GL_QUADS);
			// top
			glNormal3f(0.0f, 1.0f, 0.0f);
			glVertex3f(-explosionsArray[i].size, explosionsArray[i].size, explosionsArray[i].size);
			glVertex3f(explosionsArray[i].size, explosionsArray[i].size, explosionsArray[i].size);
			glVertex3f(explosionsArray[i].size, explosionsArray[i].size, -explosionsArray[i].size);
			glVertex3f(-explosionsArray[i].size, explosionsArray[i].size, -explosionsArray[i].size);
			// left
			glNormal3f(0.0f, 0.0f, 1.0f);
			glVertex3f(explosionsArray[i].size, -explosionsArray[i].size, explosionsArray[i].size);
			glVertex3f(explosionsArray[i].size, explosionsArray[i].size, explosionsArray[i].size);
			glVertex3f(-explosionsArray[i].size, explosionsArray[i].size, explosionsArray[i].size);
			glVertex3f(-explosionsArray[i].size, -explosionsArray[i].size, explosionsArray[i].size);
			// bottom
			glNormal3f(0.0f, -1.0f, 0.0f);
			glVertex3f(explosionsArray[i].size, -explosionsArray[i].size, explosionsArray[i].size);
			glVertex3f(-explosionsArray[i].size, -explosionsArray[i].size, explosionsArray[i].size);
			glVertex3f(-explosionsArray[i].size, -explosionsArray[i].size, -explosionsArray[i].size);
			glVertex3f(explosionsArray[i].size, -explosionsArray[i].size, -explosionsArray[i].size);
			// right
			glNormal3f(0.0f, 0.0f, -1.0f);
			glVertex3f(explosionsArray[i].size, explosionsArray[i].size, -explosionsArray[i].size);
			glVertex3f(explosionsArray[i].size, -explosionsArray[i].size, -explosionsArray[i].size);
			glVertex3f(-explosionsArray[i].size, -explosionsArray[i].size, -explosionsArray[i].size);
			glVertex3f(-explosionsArray[i].size, explosionsArray[i].size, -explosionsArray[i].size);
			// back
			glNormal3f(1.0f, 0.0f, 0.0f);
			glVertex3f(explosionsArray[i].size, explosionsArray[i].size, -explosionsArray[i].size);
			glVertex3f(explosionsArray[i].size, explosionsArray[i].size, explosionsArray[i].size);
			glVertex3f(explosionsArray[i].size, -explosionsArray[i].size, explosionsArray[i].size);
			glVertex3f(explosionsArray[i].size, -explosionsArray[i].size, -explosionsArray[i].size);
			// front
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glVertex3f(-explosionsArray[i].size, -explosionsArray[i].size, explosionsArray[i].size);
			glVertex3f(-explosionsArray[i].size, explosionsArray[i].size, explosionsArray[i].size);
			glVertex3f(-explosionsArray[i].size, explosionsArray[i].size, -explosionsArray[i].size);
			glVertex3f(-explosionsArray[i].size, -explosionsArray[i].size, -explosionsArray[i].size);
			glEnd();
			glPopMatrix();
		}
	}
}

void move_particles()
{
	for (int i = 0; i < PARTICLE_COUNT; i++)
	{
		explosionsArray[i].pos.x += explosionsArray[i].direction.x * explosionsArray[i].speed * deltaTime;
		explosionsArray[i].pos.y += explosionsArray[i].direction.y * explosionsArray[i].speed * deltaTime;
		explosionsArray[i].pos.z += explosionsArray[i].direction.z * explosionsArray[i].speed * deltaTime;

		explosionsArray[i].duration -= PARTICLE_DECAY;

		if (explosionsArray[i].duration <= 0)
		{
			explosionsArray[i].isActive = false;
		}
	}
}