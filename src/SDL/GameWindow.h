#ifndef GAMEWINDOW_H_
#define GAMEWINDOW_H_

#include "../global.h"

class GameWindow
{
public:

	Mix_Music *music;
	const SDL_VideoInfo* video; 
	
	GameWindow();
	void init();
	
	virtual ~GameWindow();
};

#endif /*GAMEWINDOW_H_*/
