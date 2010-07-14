#ifndef PARTICEL_H_
#define PARTICEL_H_
#include "../global.h"

class Particle {
  public :
    GLfloat birth;
    GLfloat lifetime ;
    GLfloat radius;
    GLfloat speed;
    
    GLfloat color[3];
    GLfloat pos[3];
    GLfloat dir; // Winkel ind Grad

    Particle(GLfloat p[3], GLfloat d, GLfloat siz, GLfloat speet, GLfloat lifet);
    ~Particle(){}
    virtual void draw();
    virtual void calc();


};

#endif /*PARTICEL_H_*/
