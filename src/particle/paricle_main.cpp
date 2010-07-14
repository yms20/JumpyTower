// openGl main Window Stub
// compile with : gcc mainWindowStub.c  -lglut
#include <GL/freeglut.h>
#include <math.h>

#include "particle.h"
#include "emitter.h"

//Callbacks
void display(void);
void Key(unsigned char key, int x, int y);
void timer(int value);

// Init
void init();


//Globals
static GLdouble wxmin = -75.5;
static GLdouble wxmax = 75.5;

static GLdouble wymin = -75.5;
static GLdouble wymax = 75.5;

static GLdouble angel = 0;
static GLdouble streuung = 0.5;
GLfloat pos1[3] = {0,0,0}; 
GLfloat pos2[3] = {1,0,0}; 

Emitter * e;

int main_(int argc, char ** argv){
  e = new Emitter(pos1,pos2,1);
  glutInit(&argc,argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(100,100);
  glutCreateWindow(argv[0]);
  init();
  
  glutKeyboardFunc(Key);  
  glutTimerFunc (1000, timer, 0);
  glutDisplayFunc(display);
//glutReshapeFunc(reshape);
//glutIdleFunc(idel);
  glutMainLoop();
  return 0 ;


}

void display(void){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  static GLUquadricObj * q;
  if ( q == 0){
    q = gluNewQuadric();
    gluQuadricDrawStyle(q,/*GLU_LINE*/GLU_FILL);
    
  }	


  e->draw();
  
  glFlush();
  
}

void init(void){
 // initLights();
  glClearColor(0.0,0.0,0.0,1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(wxmin,wxmax,wymin,wymax,-10,10);
}

void timer(int value){

  
  glutTimerFunc (100, timer, value +1);

  e->calc();
  glutPostRedisplay();
}
void Key(unsigned char key, int x, int y)
{
  GLint dir = -1;
  
  char str[10];
  switch (key) {
    case 27:  glutLeaveGameMode();    exit(0);        break;
   // case 'f': glutEnterGameMode(); break;
    case 'w': e->pos[1] += 10;  break;
    case 's': e->pos[1] -= 10; break;
      
    case 'a':  e->pos[0] -= 10; break;
    case 'd':  e->pos[0] += 10; break;
      
    case 'r': angel += 5; break;
    case 'f': angel -= 5; break;
    
    case 't': e->dirAbweichung += 0.5; break;
    case 'g': if (e->dirAbweichung > 0.5 )e->dirAbweichung -= 0.5; break;
    
  }
  e->target[0] = e->pos[0] + 10 * cos(angel/360 * 2 * M_PI);
  e->target[1] = e->pos[1] + 10 * sin(angel/360 * 2 * M_PI);
  printf("tx %lf ty %lf \n",e->target[0],e->target[1] );
}