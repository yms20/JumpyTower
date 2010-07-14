#include "Level.h"

Level::Level(GLfloat posX,GLfloat posY)
{
	
	dim[0]= 2;
	dim[1]= 3;
	size = 300;
	
	levelSpeed = 2;
	pos[0] = posX;
	pos[1] = posY;
		floor = 0 ;
		border[0] = pos[0] - dim[0] *size/2;
		border[1] = pos[1] - dim[1] *size/2;
		border[2] = dim[0] *size;
		border[3] = dim[1] *size;
		
		init();
}

Level::~Level()
{
}

void Level::draw(){
	for(int i = 0; i < objectCount; i ++){
 
			objects[i]->draw();
	}
if (DEBUG) drawBorder();

}

void Level::drawBorder(){
	glColor3f(1,1,0);
  glLineWidth(2.0f);
  glLineStipple(4,0xAA);
  glEnable (GL_LINE_STIPPLE);

	glBegin(GL_LINE_LOOP);

	glVertex2f(border[0]             ,border[1]);
	glVertex2f(border[0] + border[2] ,border[1]);
	glVertex2f(border[0] + border[2] ,border[1] + border[3]);
	glVertex2f(border[0]             ,border[1] + border[3]);
	
	glEnd();
  glDisable (GL_LINE_STIPPLE);
}

void Level::calc(){

	moveObjectsDown();
	Brick *  b;
	for (int i = 1; i < objectCount; ++i) {
		b = (Brick*)objects[i];
		b->calc();
	}
}

void Level::moveObjectsDown(){
	
	for (int i = 1; i < objectCount; ++i) {
		if ( (((Brick*)objects[i])->center[1]-=levelSpeed )  < border[1] ){
				
			floor++;
			if (floor % 10 == 0){
			 	delete(objects[i]);
				objects[i] = new Brick((border[0]+border[2]/2) ,(border[1]+border[3])  ,(dim[0]*size),30);
				((Brick*)objects[i])->floor = floor;
			
			} else {
				GLint pos[2];
				GLint dim[2];
				dim[0] = 100 + (rand() % 3) * 100;
				dim[1] = 15; 
				pos[0] =border[0]+ dim[0]/2 + rand()% ( (int)border[2] - dim[0]);
			 	delete(objects[i]);
				objects[i] = new Brick(pos[0] ,border[1]+border[3]  ,dim[0],dim[1]);
				((Brick*)objects[i])->floor = floor;
			}
		}		
	}
}

void Level::init(){
	
	for (int i = 0; i < objectCount; ++i) {
	
	floor++;
	GLint pos[2];
	GLint dim[2];
		dim[0] = 100 + (rand() % 3) * 50;
		dim[1] = 15; 
		pos[0] =border[0]+ dim[0]/2 + rand()% ( (int)border[2] - dim[0]);
		pos[1] =border[1] + (i-1) * (border[3])/ (objectCount-1) ;
		 delete(objects[i]);
	objects[i] = new Brick(pos[0] ,pos[1] ,dim[0],dim[1]);
	((Brick*)objects[i])->floor = floor;
	}

}

GLboolean Level::collides(GameObject * go){



Player * p = (Player*)go;
Player * q = (Player*)go;

q->pos[0] = p->pos[0] + p->horSpeed;
q->pos[1] = p->pos[1] + 5;


if (p->border[0] < border[0] ){
	p->pos[0] = border[0] + p->radius;
 p->horSpeed *= -1;
}	
if ( p->border[0] + p->border[2] > border[0] + border[2] ){
	p->pos[0] = border[0] + border[2] - p->radius;
 	p->horSpeed *= -1;
}

if (p->vertSpeed <= 0){
	 Brick * b ;
	for (int i = 1; i < objectCount; ++i) {
		
		b = (Brick*)objects[i];
		if (b->collides(p) || b->collides(q) ){
			p->jumping = FALSE;
			return TRUE;
		}
	}
}
return FALSE;
}