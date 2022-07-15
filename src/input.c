#include "main.h"
#include "input.h"

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		// Move ship forward
		case MOVE_FORWARD:
			movingForward = true;
			break;
		// Move ship up
		case MOVE_UP:
		case MOVE_UP_CAPS:
			movingUp = true;
			break;
		// Move ship down
		case MOVE_DOWN:
		case MOVE_DOWN_CAPS:
			movingDown = true;
			break;
		// Turn ship left
		case TURN_LEFT:
		case TURN_LEFT_CAPS:
			turningLeft = true;
			break;
		// Turn ship right
		case TURN_RIGHT:
		case TURN_RIGHT_CAPS:
			turningRight = true;
			break;
		// Quit game
		case EXIT_KEY:
			exit(EXIT_SUCCESS);
			break;
		// Toggle axes display
		case TOGGLE_AXES:
		case TOGGLE_AXES_CAPS:
			showAxes = !showAxes;
			break;
		default:
			break;
	}
}

void keyboard_up(unsigned char key, int x, int y)
{
	switch (key)
	{
		case MOVE_FORWARD:
			movingForward = false;
			break;
		case MOVE_UP:
		case MOVE_UP_CAPS:
			movingUp = false;
			break;
		case MOVE_DOWN:
		case MOVE_DOWN_CAPS:
			movingDown = false;
			break;
		case TURN_LEFT:
		case TURN_LEFT_CAPS:
			turningLeft = false;
			break;
		case TURN_RIGHT:
		case TURN_RIGHT_CAPS:
			turningRight = false;
			break;
		default:
			break;
	}
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		mouseDown = (state == GLUT_DOWN);
	}
}

void mouse_wheel(int button, int dir, int x, int y)
{
	if (dir > 0)
	{
		if (camera.dist > 10)
		{
			camera.dist -= 1;
		}
	}
	else
	{
		if (camera.dist < 60)
		{
			camera.dist += 1;
		}
	}
}
