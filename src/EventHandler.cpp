#include "EventHandler.h"
EventHandler::EventHandler()
{
 
}

void EventHandler::addPlayer(Player * p,GLint number){
player = p;
 
}

void EventHandler::calc(){

//printf("Player %f \n",player->horF);

float timeConstant = (1000.0/ FRAMETIME);
 // On the ground
	if(leftPressed){
		player->horF = -(player->maxHorF + player->friction / timeConstant);
	}
	if(rightPressed ){
		player->horF = player->maxHorF - player->friction / timeConstant;
	}
	
	
	if (spacePressed && !player->jumping){
		 player->jumping = TRUE;
		 player->vertF = (player->maxVertF + 2*player->gravity +  1.1*player->horSpeed* player->horSpeed )  / timeConstant ;
	}
}
void EventHandler::processKeyboardEvents(SDL_Event *event){
		switch( event->type ) {
		case SDL_KEYDOWN:
			switch ( event->key.keysym.sym ) {
			case SDLK_ESCAPE:
				exit(0);
			break;
	
			case SDLK_q:
				exit(0);
				break;
	
			case SDLK_KP_PLUS:
				break;
			
			case SDLK_KP_MINUS:
			SDL_WM_ToggleFullScreen(SDL_GetVideoSurface());
				break;
		
			case SDLK_SPACE:
				spacePressed = TRUE;
				break;
			case SDLK_LEFT:
				leftPressed = TRUE;
				break;
			case SDLK_RIGHT:
				rightPressed = TRUE;
				break;
			case SDLK_DOWN:
				downPressed = TRUE;
				break;
			case SDLK_UP:
				upPressed = TRUE;
				break;
				
			case SDLK_w:
				wPressed = TRUE;
				break;
	
				
			case SDLK_s:
				sPressed = TRUE;
				break;
	
				
			case SDLK_a:
				aPressed = TRUE;
				break;
	
				
			case SDLK_d:
				dPressed = TRUE;
				break;
	
			case SDLK_y:
	
				break;
			case SDLK_x:
	
				break;
	
	 		case SDLK_f:
				SDL_WM_ToggleFullScreen(SDL_GetVideoSurface());
	
				break;
			case SDLK_v:
	
				break;
	
			default:
				break;
			}
			  break;

	  case SDL_KEYUP:
		switch(event->key.keysym.sym) {
		case SDLK_SPACE:
			spacePressed = FALSE;
			break;
		case SDLK_LEFT:
			leftPressed = FALSE;
			break;
		case SDLK_RIGHT:
			rightPressed = FALSE;
			break;
		case SDLK_DOWN:
			downPressed = FALSE;
			break;
		case SDLK_UP:
			upPressed = FALSE;
			break;

		case SDLK_w:
			wPressed = FALSE;
			break;
			
		case SDLK_s:
			sPressed = FALSE;
			break;
			
		case SDLK_a:
			aPressed = FALSE;
			break;
			
		case SDLK_d:
			dPressed = FALSE;
			break;


		default:
			break;
		  }
	break;
	
	case SDL_QUIT:
	exit (0);
	break;

	}
 
}

void EventHandler::processMouseEvents(SDL_Event *event){

int yMaus,xMaus;

	switch( event->type ) {

	case SDL_MOUSEMOTION:
		xMaus =  event->motion.y;
		yMaus =  event->motion.x;
			
	//	printf("Maus X: %d Y: %d\n",xMaus,yMaus);	
		break;
	}

}

void EventHandler::handleEvents(void){

 SDL_Event event;
	while( SDL_PollEvent( &event ) ) {
 
		
		processKeyboardEvents(&event );
		processMouseEvents(&event );
	}
}
EventHandler::~EventHandler()
{
}
