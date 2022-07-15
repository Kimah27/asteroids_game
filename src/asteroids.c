#include "main.h"
#include "explosions.h"

void create_asteroids()
{
	for (int i = 0; i <= asteroidWave; i++)
	{
		float minSize = ASTEROID_MIN_SIZE;
		float maxSize = ASTEROID_MAX_SIZE;
		// Asteroid radius
		asteroidArray[i].radius = (maxSize - minSize) * ((((float)rand()) / (float)RAND_MAX)) + minSize;

		float minSpeed = ASTEROID_MIN_SPEED;
		float maxSpeed = ASTEROID_MAX_SPEED;
		// Generate random speed between min and max
		asteroidArray[i].speed = (maxSpeed - minSpeed) * ((((float)rand()) / (float)RAND_MAX)) + minSpeed;

		// Asteroid spawn location
		float theta = rand() * 3.14f * 2.0f;
		float phi = rand() * 3.14f;
		asteroidArray[i].pos.x = sinf(phi) * cosf(theta) * (ARENA_SCALE * 20);
		asteroidArray[i].pos.y = sinf(phi) * sinf(theta) * (ARENA_SCALE * 20);
		asteroidArray[i].pos.z = cosf(theta) * (ARENA_SCALE * 20);
		printf("x: %f  y: %f  z:%f\n", asteroidArray[i].pos.x, asteroidArray[i].pos.y, asteroidArray[i].pos.z);

		float minRot = ASTEROID_MIN_ROTATION;
		float maxRot = ASTEROID_MAX_ROTATION;
		// Generate random speed between min and max
		asteroidArray[i].rotationSpeed = (maxRot - minRot) * ((((float)rand()) / (float)RAND_MAX)) + minRot;

		// Asteroid spawn trajectory
		asteroidArray[i].trajectory.x = ship.pos.x - asteroidArray[i].pos.x;
		asteroidArray[i].trajectory.y = ship.pos.y - asteroidArray[i].pos.y;
		asteroidArray[i].trajectory.z = ship.pos.z - asteroidArray[i].pos.z;

		// Set asteroid health
		asteroidArray[i].hitPoints = (int)asteroidArray[i].radius / 8;

		asteroidArray[i].isAlive = true;
		asteroidArray[i].isSpawned = true;
		asteroidArray[i].inArena = false;
	}
}

void draw_asteroids()
{
	if (asteroidWave > 0)
	{
		for (int i = 0; i < asteroidWave; i++)
		{
			if (asteroidArray[i].isAlive)
			{
				//float mat_ambient[] = { 0.0f, 0.0f, 1.0f, 1.0f };
				float mat_diffuse[] = { ASTEROID_COLOUR, 1.0f };
				float mat_specular[] = { 0.2f, 0.0f, 0.0f, 0.0f };
				//float mat_shininess[] = { 100.0 };

				//glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
				glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
				//glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

				glPushMatrix();
				glTranslatef(asteroidArray[i].pos.x, asteroidArray[i].pos.y, asteroidArray[i].pos.z);
				asteroidArray[i].rotation += asteroidArray[i].rotationSpeed * deltaTime;
				glRotatef(asteroidArray[i].rotation, 1, 1, 1);
				glutSolidSphere(asteroidArray[i].radius, 20, 20);
				glPopMatrix();
			}
		}
	}
}

void move_asteroids()
{
	for (int i = 0; i < asteroidWave; i++)
	{
		asteroidArray[i].pos.x += asteroidArray[i].trajectory.x * asteroidArray[i].speed * deltaTime;
		asteroidArray[i].pos.y += asteroidArray[i].trajectory.y * asteroidArray[i].speed * deltaTime;
		asteroidArray[i].pos.z += asteroidArray[i].trajectory.z * asteroidArray[i].speed * deltaTime;
	}
}

void bouncies()
{
	for (int i = 0; i < asteroidWave; i++)
	{
		if (asteroidArray[i].pos.x <= (ARENA_SCALE * 9) - asteroidArray[i].radius && asteroidArray[i].pos.x >= (-ARENA_SCALE * 9) + asteroidArray[i].radius &&
			asteroidArray[i].pos.y <= (ARENA_SCALE * 9) - asteroidArray[i].radius && asteroidArray[i].pos.y >= (-ARENA_SCALE * 9) + asteroidArray[i].radius &&
			asteroidArray[i].pos.z <= (ARENA_SCALE * 9) - asteroidArray[i].radius && asteroidArray[i].pos.z >= (-ARENA_SCALE * 9) + asteroidArray[i].radius)

		{
			asteroidArray[i].inArena = true;
		}

		if (asteroidArray[i].inArena)
		{
			if (asteroidArray[i].pos.x - asteroidArray[i].radius < (-ARENA_SCALE * 10) || asteroidArray[i].pos.x + asteroidArray[i].radius > (ARENA_SCALE * 10))
			{
				asteroidArray[i].trajectory.x = -asteroidArray[i].trajectory.x;
			}

			if (asteroidArray[i].pos.y - asteroidArray[i].radius < (-ARENA_SCALE * 10) || asteroidArray[i].pos.y + asteroidArray[i].radius > (ARENA_SCALE * 10))
			{
				asteroidArray[i].trajectory.y = -asteroidArray[i].trajectory.y;
			}

			if (asteroidArray[i].pos.z - asteroidArray[i].radius < (-ARENA_SCALE * 10) || asteroidArray[i].pos.z + asteroidArray[i].radius > (ARENA_SCALE * 10))
			{
				asteroidArray[i].trajectory.z = -asteroidArray[i].trajectory.z;
			}
		}
	}
}

void asteroid_ship_collision()
{
	for (int i = 0; i < asteroidWave; i++)
	{
		if (asteroidArray[i].isAlive && asteroidArray[i].isSpawned)
		{
			float distX = asteroidArray[i].pos.x - ship.pos.x;
			float distY = asteroidArray[i].pos.y - ship.pos.y;
			float distZ = asteroidArray[i].pos.z - ship.pos.z;
			float dist = sqrtf((distX * distX) + (distY * distY) + (distZ * distZ));

			if (dist <= ship.radius + asteroidArray[i].radius)
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
	}
}

void asteroid_bullet_check()
{
	for (int i = 0; i < 30; i++)
	{
		asteroid_bullet_collision(i);
	}
}

void asteroid_bullet_collision(int index)
{
	for (int i = 0; i < bulletCount; i++)
	{
		if (bullets[i].isActive && asteroidArray[index].isAlive && asteroidArray[index].inArena)
		{
			float distX = bullets[i].pos.x - asteroidArray[index].pos.x;
			float distY = bullets[i].pos.y - asteroidArray[index].pos.y;
			float distZ = bullets[i].pos.z - asteroidArray[index].pos.z;
			float dist = sqrtf((distX * distX) + (distY * distY) + (distZ * distZ));

			if (dist <= asteroidArray[index].radius)
			{
				asteroidArray[index].hitPoints -= 1;

				if (asteroidArray[index].hitPoints > 0)
				{
					bullets[i].isActive = false;
				}
				else if (asteroidArray[index].hitPoints <= 0)
				{
					explosionPosition.x = asteroidArray[index].pos.x;
					explosionPosition.y = asteroidArray[index].pos.y;
					explosionPosition.z = asteroidArray[index].pos.z;
					create_particles();

					asteroidArray[index].isAlive = false;
					bullets[i].isActive = false;
				}
			}
		}
	}
}
