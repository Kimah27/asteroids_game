#ifndef MYMATH_H
#define MYMATH_H

typedef struct Vec3 { float x; float y; float z; } Vec3;

int timeSinceStart;
int deltaTime;
int oldTimeSinceStart;
int time;

void calculateDeltaTime();
void timer();

float calculateDirectionX(float angle);
float calculateDirectionY(float angle);
float calculateMagnitude(float x, float y);
float normaliseX(float x, float y);
float normaliseY(float x, float y);

#endif
