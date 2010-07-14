#ifndef BRICK_H_
#define BRICK_H_
#include "global.h"
#include "GameObject.h"

class Brick: public GameObject
{
public:
	
	GLfloat center[2];
	GLfloat dim[2];
	GLint floor;
	Brick(GLfloat posX,GLfloat posY,GLfloat dimX,GLfloat dimY);
	
	
	// ----- Override Methods -----
	virtual void draw();
	virtual void calc();
	virtual GLboolean collides(GameObject * go) ;
	/*DEBUG*/ virtual void drawBorder() ;
	virtual ~Brick();
};

#endif /*BRICK_H_*/
