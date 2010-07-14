
#include "emitter.h"

#ifndef EMITTER
#define EMITTER


Emitter::Emitter(GLfloat position[3], GLfloat etarget[3],GLfloat freq ){

  
  pos[0] = position[0];
  pos[1] = position[1];
  pos[2] = position[2];
  
  target[0]=etarget[0];
  target[1]=etarget[1];
  target[2]=etarget[2];
  
  init();
}
Emitter::~Emitter(){}

void targetToRad(GLfloat pos[2], GLfloat target[2] , GLfloat * dir){
  
  float ank = sqrt((pos[0] - target[0])* (pos[0] - target[0]) ); // abs delta x
  float geg = sqrt((pos[1] - target[1]) * (pos[1] - target[1]) ); // abs delta y
  
  
  float hy = sqrt(ank *ank  + geg * geg);
  
  
  *dir = asin(geg/hy) /(2*M_PI) * 360;
  // Sonderfaelle ank == 0 &&
  if (target[0] > pos[0]  && target[1] > pos[1] )
   * dir += 0;

    if ( target[0] < pos[0] && target[1] > pos[1] )
   * dir = 90 +  90 - *dir;

  // geg == 0 &&
    if ( target[0] > pos[0]  && target[1] < pos[1] )
      * dir = 270 +  90 - *dir;

    if ( target[0] < pos[0] && target[1] < pos[1] )
   * dir += 180;
     
 // printf("ank %f, geg %f, hy %f, dir %f \n",ank,geg,hy,*dir);
}

void Emitter::init(){
 
  printf("Emitter initing\n");
  
  targetToRad(pos,target , &dir); 
  dirAbweichung  = 180;
    
  lifeTime = 20;
  lifeTimeAbweichung = 5  ;
    
  speed = 4;
  GLfloat speedAbweichung = 3  ;
    
  
  size = 10;
  sizeAbweichung = 2;
   time = 0;
   freq= 2; // alle wieviel frames ein particel emittiert wird
   cycl = pcount;  // wie lange geht ein cyclus bis alle particel emittiert sind
  emitting = 1;
  
   
  GLint sFrame = 0;
  for(int i = 0 ; i < pcount; i ++){
    sFrame += freq;  
    startFrames[i] = i* freq;
    particle[i] = new Star(pos, 
                               dir + dirAbweichung - rand()%(1 + (int)(2*dirAbweichung)),
                                   size + sizeAbweichung - rand()%(int) (2*sizeAbweichung), 
                                       speed + speedAbweichung - rand()%(int)(2*speedAbweichung),
                                           lifeTime ); //
  }
} 


void Emitter::calc(){

  if (emitting){
    time += 1;
    
    
    targetToRad(pos,target , &dir); 
    
    for(int i = 0 ; i < pcount; i ++){
      if(startFrames[i] < time)
        particle[i]->calc();
      if(particle[i]->lifetime < 0){
        particle[i]->lifetime = lifeTime ;
        particle[i]->pos[0] = pos[0] ;
        particle[i]->pos[1] = pos[1] ;
        particle[i]->pos[2] = pos[2] ;
        
        particle[i]->dir = dir+ dirAbweichung - rand()%(int)(2*dirAbweichung) ;
      }
    }
  }
} 



void Emitter::draw(){
  //printf("Emitter %f\n", time);
  glColor3f(1,1,1);
/*  glBegin(GL_LINES);
   glVertex2f(pos[0],pos[1]);
   glVertex2f(pos[0] +lifeTime* (speed + speedAbweichung) * cos(dir/360 * 2 * M_PI),
              pos[1] + lifeTime* (speed + speedAbweichung) * sin(dir/360 * 2 * M_PI));
    
    glVertex2f(pos[0],pos[1]);
    glVertex2f(pos[0] +lifeTime* (speed + speedAbweichung) * cos((dir - dirAbweichung)/360 * 2 * M_PI),
               pos[1] +lifeTime* (speed + speedAbweichung) * sin((dir - dirAbweichung)/360 * 2 * M_PI));
    
    glVertex2f(pos[0],pos[1]);
    glVertex2f(pos[0] + lifeTime* (speed + speedAbweichung) * cos((dir + dirAbweichung)/360 * 2 * M_PI),
               pos[1] + lifeTime* (speed + speedAbweichung) * sin((dir + dirAbweichung)/360 * 2 * M_PI));
  glEnd();
*/
  if(emitting){
  
    for(int i = 0 ; i < pcount; i ++){
      if(particle[i]->lifetime > 0)
        particle[i]->draw();
    
    }
  }
} 

void  Emitter::startEmit(){
emitting = 1;
}
void  Emitter::stopEmit(){ 
	emitting = 0;
}


#endif