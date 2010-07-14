#include "Star.h"

Star::Star(GLfloat p[3], GLfloat d, GLfloat siz, GLfloat speet, GLfloat lifet) : Particle (p,d, siz, speet,lifet)
{
	  lifetime = lifet;
  radius = siz;
  speed = speet;
  dir = d;
  
  pos[0] = p[0];
  pos[1] = p[1];
  pos[2] = 0;
}

void Star::draw(){

float r = 20;
int cnt =  0 ;
glColor4f(rand()%100/100.0f,
			rand()%100/100.0f,
			0.81,
			0.1f);

  glTranslatef(pos[0],pos[1],pos[2]);
	glBegin(GL_POLYGON);
	for (float i = -M_PI ; i < M_PI  ; i +=(2*M_PI) / 10 ) {
		cnt++;
		if ( cnt %2 ) r = 7;	else r= 15;
		glVertex2f(sin(i)*r ,cos(i)*r );
		
	}
	
	
	glEnd();  
  glTranslatef(-pos[0],-pos[1],-pos[2]);
}

void Star::calc(){

  lifetime --; 
  //dir = 270;
    GLfloat rad = dir /360 * 2*M_PI;
    pos[0] += speed * cos(rad);
    pos[1] += speed * sin(rad);
    
}
Star::~Star()
{
}
