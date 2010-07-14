#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "global.h" 
class GameObject
{
public:
	GLfloat pos[2];
	GLfloat border[4];

	GameObject();
	virtual void draw() = 0;
	virtual void calc() = 0;
	virtual GLboolean collides(GameObject * go) = 0; 
	/*DEBUG*/ virtual void drawBorder() = 0;
	virtual ~GameObject();
};

#endif /*GAMEOBJECT_H_*/
