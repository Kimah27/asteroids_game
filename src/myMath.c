#include "main.h"
#include "myMath.h"

void calculateDeltaTime()
{
	timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
	deltaTime = timeSinceStart - oldTimeSinceStart;
	oldTimeSinceStart = timeSinceStart;
}
void timer()
{
	time = glutGet(GLUT_ELAPSED_TIME);
}

float calculateDirectionX(float angle)
{
	float dirX = sinf(-angle * 3.14f / 180.0f);

	return dirX;
}

float calculateDirectionY(float angle)
{
	float dirY = cosf(-angle * 3.14f / 180.0f);

	return dirY;
}

float calculateMagnitude(float x, float y)
{
	float magnitude = sqrtf(x * x + y * y);

	return magnitude;
}

float normaliseX(float x, float y)
{
	float mag = calculateMagnitude(x, y);
	float normX = x / mag;

	return normX;
}

float normaliseY(float x, float y)
{
	float mag = calculateMagnitude(x, y);
	float normY = y / mag;

	return normY;
}