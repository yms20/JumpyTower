#ifndef MAIN_H_
#define MAIN_H_
#include "global.h"
#include "SDL/GameWindow.h"
#include "EventHandler.h"
#include "Level.h"

class Main
{
public:
Player * player ;
Level * level;

EventHandler * eh;

GLfloat time;
GLint view[2]; // upper an lower view coord 
GLint trim[2]; 
GLfloat clearColor[3];
	Main();

		void draw();
		void calc();
	void mainloop();
	
	GLboolean checkCollision( );

	virtual ~Main();
};

#endif /*MAIN_H_*/
