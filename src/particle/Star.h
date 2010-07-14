#ifndef STAR_H_
#define STAR_H_

#include "particle.h"

class Star : public Particle
{
public:
	Star(GLfloat p[3], GLfloat d, GLfloat siz, GLfloat speet, GLfloat lifet);
	virtual ~Star();
	     void draw();
      void calc();
};

#endif /*STAR_H_*/
