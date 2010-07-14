#include "Main.h"

Main::Main()
{
	printf("JumpyTower v0.01\n");
	eh = new EventHandler();
	player = new Player();
	level = new Level(WIDTH/2,HEIGHT/2);
	level->init();
	
	eh->addPlayer(player,1);
 
	view[0] = 200;
	view[1] = 850;
	trim[0] = 500;
	trim[1] = 1180;
	
	clearColor[0] = 0;
	clearColor[1] = 0;
	clearColor[2] = 0;
	
	eh->player->pos[1] = view[0]; 
	eh->player->pos[0] = trim[0] + (trim[1] - trim[0])/2; 
	time = 0 ;
}





GLboolean Main::checkCollision(){
	
return level->collides(player);
}



void Main::calc(){
	eh->calc();
	level->calc();
	player->calc();
	
	if (player->speed > 0)	
			player->speed-= sqrt(player->speed/10)/2;


		// Borders
		
	if (player->pos[0] > trim[1] -20 || player->pos[0] < trim[0] +20 )		
			player->speed = 0;
			
			// Collusion
			
	if ( checkCollision() )
	{
 		clearColor[0] = 0.3;
 		player->vertSpeed = 0;
 		player->vertF = player->gravity / (1000/ FRAMETIME);
	} else 
 		clearColor[0] = 0;
	
	if (player->pos[1] > level->border[1] + level->border[3] - 100 && player->vertSpeed > 0){
		level->levelSpeed = player->vertSpeed;
		player->pos[1] -=player->vertSpeed;
	}else 
	level->levelSpeed = 1;

} // calc

// The Programms Mai Loop
void Main::mainloop(){
	for (;;){
		
    	eh->handleEvents();
    	calc();
		draw();
//Start Playing Sound
  //  Mix_PlayMusic(music, -1);
	SDL_Delay( FRAMETIME);
	}
}
void initGL(){

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
   glOrtho(0,WIDTH,0,HEIGHT,-10,10);
   glMatrixMode(GL_MODELVIEW);
   glClearColor(0, 0 ,0, 0);
   
}

void Main::draw(){
	
     glClearColor(clearColor[0],clearColor[1],clearColor[2],1);
    glClear(GL_COLOR_BUFFER_BIT  | GL_DEPTH_BUFFER_BIT);


	level->draw();
	player->draw();


	 

   SDL_GL_SwapBuffers();
   SDL_Delay( 20);
}

Main::~Main()
{
}

int main(int argc, char **argv) {
	Main m;
	GameWindow gw;
	initGL();
	m.mainloop();
}
