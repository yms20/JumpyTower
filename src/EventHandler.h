#ifndef EVENTHANDLER_H_
#define EVENTHANDLER_H_

#include "global.h"
#include "Player.h"
class EventHandler
{
public:

Player * player;
 

int leftPressed, rightPressed, upPressed, downPressed;
int spacePressed;
int wPressed, sPressed, aPressed, dPressed;
	void calc();
	EventHandler();
	void addPlayer(Player * p,GLint number);
	virtual ~EventHandler();
	void processKeyboardEvents(SDL_Event *event);
	void processMouseEvents(SDL_Event * event);
	void handleEvents();
	
};

#endif /*EVENTHANDLER_H_*/
