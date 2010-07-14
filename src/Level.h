#ifndef LEVEL_H_
#define LEVEL_H_


#include "GameObject.h"
#include "Player.h"
#include "Brick.h"

class Level : public GameObject
{
public:

// ------ Fields -----
static const GLint objectCount = 10;
Brick * objects[objectCount];

GLfloat dim[2];
GLfloat size;
GLint floor;
GLint levelSpeed;


// ----- Override Methods -----
	virtual void draw();
	virtual void calc();
	virtual GLboolean collides(GameObject * go) ;
	/*DEBUG*/ virtual void drawBorder() ;

//------ Methods -------
	Level(GLfloat posX,GLfloat posY);
	 ~Level();
	void init(); 
	void moveObjectsDown();

};

#endif /*LEVEL_H_*/
