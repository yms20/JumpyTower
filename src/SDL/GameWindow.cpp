#include "GameWindow.h"

GameWindow::GameWindow()
{
	init();
	printf("GameWindow inited\n");
}
void GameWindow::init(){
	
	// ------------SDL ---------------------
//const SDL_VideoInfo* video; 
    if ( SDL_Init(SDL_INIT_VIDEO) < 0 ) {
        fprintf(stderr, "Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }  
    /* Quit SDL properly on exit */
    atexit(SDL_Quit);

    /* Get the current video information */
    video = SDL_GetVideoInfo( );
    if( video == NULL ) {
        fprintf(stderr, "Couldn't get video information: %s\n", SDL_GetError());
        exit(1);
    }

	SDL_WM_SetCaption("Window Title","Icon Title");
    /* Set the minimum requirements for the OpenGL window */
    SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

    /* Note the SDL_DOUBLEBUF flag is not required to enable double 
     * buffering when setting an OpenGL video mode. 
     * Double buffering is enabled or disabled using the 
     * SDL_GL_DOUBLEBUFFER attribute.
     */
    if( SDL_SetVideoMode( WIDTH, HEIGHT, video->vfmt->BitsPerPixel, SDL_OPENGL /*| SDL_FULLSCREEN */) == 0 ) {
        fprintf(stderr, "Couldn't set video mode: %s\n", SDL_GetError());
        exit(1);
        
        // ------------openGL ---------------------
          /* Make the viewport cover the whole window - 100 */
   // glViewport(0, 0, WIDTH  , HEIGHT);

    /* Set the camera projection matrix:
     * field of view: 90 degrees
     * near clipping plane at 0.1
     * far clipping plane at 100.0
     */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
   glOrtho(0,WIDTH,0,HEIGHT,-10,10);
    
    /*
 float aspect = (float)WIDTH / (float)HEIGHT;
    gluPerspective(60.0, aspect, 150, 1000.0);
    
    gluLookAt(0,200,-300
    			,0,100,0
    			,0,1,0);
    			
   */
    /* We're done with the camera, now matrix operations 
     * will affect the modelview matrix
     * */
    glMatrixMode(GL_MODELVIEW);

    /* set the clear color to grey */

    glClearColor(0.5, 0.5 ,0.5, 0);
    //glClearColor(0.0, 0.0 ,0.0, 0);
    /* We want z-buffer tests enabled*/
//    glEnable(GL_DEPTH_TEST);

    /* Do draw back-facing polygons*/
  //  glDisable(GL_CULL_FACE);


// Notwendig fuer Texturen
		//glEnable(GL_BLEND);
       // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        
        // ------------SDLmixer ---------------------
	}
}

GameWindow::~GameWindow()
{
}
