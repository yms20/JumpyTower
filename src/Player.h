#ifndef PLAYER_H_
#define PLAYER_H_

#include "global.h"
#include "GameObject.h"
#include "particle/emitter.h"
class Player : public GameObject
{
public:
	Emitter * e;
	
	GLfloat dir; // direction in Dergees
	GLfloat speed;
	
	GLint lastFloor;
	GLint tmpLastFloor;
	
	
	GLfloat maxHorSpeed ;
	GLfloat horSpeed ;
	
	GLfloat horF ;
	GLfloat maxHorF ;
	GLfloat friction;
	GLfloat jumpPower;
	
	GLfloat vertF;
	GLfloat maxVertF ;
	
static const 	GLfloat gravity = 40;
	GLfloat vertSpeed;
	GLfloat maxVertSpeed;
	
	
	GLboolean jumping;
	
	GLfloat radius;
	GLfloat pos[2];
	GLfloat nextPos[2];

	Player();
	
	// ----- Override Methods -----
	virtual void draw();
	virtual void calc();
	virtual GLboolean collides(GameObject * go) ;
	/*DEBUG*/ virtual void drawBorder() ;
	virtual ~Player();
};

#endif /*PLAYER_H_*/
