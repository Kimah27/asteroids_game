#ifndef INPUT_H
#define INPUT_H

#define EXIT_KEY 27
#define MOVE_FORWARD 32
#define MOVE_UP 'w'
#define MOVE_UP_CAPS 'W'
#define MOVE_DOWN 's'
#define MOVE_DOWN_CAPS 'S'
#define TURN_LEFT 'a'
#define TURN_LEFT_CAPS 'A'
#define TURN_RIGHT 'd'
#define TURN_RIGHT_CAPS 'D'
#define TOGGLE_AXES 'x'
#define TOGGLE_AXES_CAPS 'X'

bool movingForward;
bool movingUp;
bool movingDown;
bool turningLeft;
bool turningRight;
bool mouseDown;

void keyboard(unsigned char key, int x, int y);
void keyboard_up(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);
void mouse_wheel(int button, int dir, int x, int y);

#endif
