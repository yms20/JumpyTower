
#ifndef PARTICLE
#define PARTICLE
#include "particle.h"
#include <GL/glut.h>


Particle::Particle(GLfloat p[3], GLfloat d, GLfloat siz, GLfloat speet, GLfloat lifet){
 
  lifetime = lifet;
  radius = siz;
  speed = speet;
  dir = d;
  
  pos[0] = p[0];
  pos[1] = p[1];
  pos[2] = 0;
}

void Particle::calc(){
 
  
  /*if (pos[0] >= 70){
  dir = dir + 180 - 2 * dir ;
  }
  if (pos[0] <= -70){
    dir = dir + 180 - 2 * dir ;
  }
  
  
  if (pos[1] >= 70){
    dir = 360 - dir ;
  }
  
  if (pos[1] <= -70){
    dir = 360 -  dir ;
  }*/
  
  lifetime --; 
  
    GLfloat rad = dir /360 * 2*M_PI;
    pos[0] += speed * cos(rad);
    pos[1] += speed * sin(rad);
   // pos[2] += dir[2];
  }


void Particle::draw(){


  static GLUquadricObj * q;
  if ( q == 0){
    q = gluNewQuadric();
    gluQuadricDrawStyle(q,/*GLU_LINE*/GLU_FILL);
    
  }	
  
  glTranslatef(pos[0],pos[1],pos[2]);
  
  gluSphere(q,radius,16,16); // r, subdiv,subdiv
  glTranslatef(-pos[0],-pos[1],-pos[2]);

}

#endif
