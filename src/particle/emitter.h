#ifndef EMITTER_
#define EMITTER_

#include "particle.h"
#include "Star.h"

class Emitter {
  public:
    
    static const int  pcount = 10;
    Particle  * particle[pcount];
    
    GLint startFrames[pcount];
 
    GLfloat pos[3];
    GLfloat target[3];
    GLfloat dir;  // in Grad
    GLfloat dirAbweichung  ; // in Grad
    
    GLfloat lifeTime;
    GLfloat lifeTimeAbweichung  ;
    
    GLfloat speed;
    GLfloat speedAbweichung  ;
    
    GLfloat size;
    GLfloat sizeAbweichung  ;
    
    
    GLfloat time;
    
    GLfloat freq;
    GLfloat cycl;
    
    GLboolean emitting;
      
    Emitter(GLfloat position[3], GLfloat etarget[3],GLfloat freq );
    ~Emitter();
    void startEmit();
    void stopEmit();
    void init();
    
    void calc();
    void draw();

};

#endif /*EMITTER_*/
