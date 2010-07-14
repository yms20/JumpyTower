#include "Brick.h"

Brick::Brick(GLfloat posX,GLfloat posY,GLfloat dimX,GLfloat dimY)
{
	center[0] = posX;
	center[1]= posY;
	dim[0]	= dimX;
	dim[1]	= dimY;
	border[0] = -dim[0]/2;
	border[1] = -dim[1]/2;
	border[2] = dim[0];
	border[3] = dim[1];
}

void Brick::draw(){
if (floor < 10)
glColor3f(1,0,0);
else if (floor < 20)
glColor3f(1,1,0);
else if (floor < 30)
glColor3f(0 ,1,0);
else if (floor < 40)
glColor3f(0,1,1);

glTranslatef(center[0],center[1],0);

glBegin(GL_POINTS);
glVertex2f(0,0);

glEnd();

glBegin(GL_POLYGON);

glVertex2f( - dim[0]/2,- dim[1]/2);
glVertex2f(+ dim[0]/2,- dim[1]/2);
glVertex2f(+ dim[0]/2,+ dim[1]/2);
glVertex2f(- dim[0]/2,+ dim[1]/2);

glEnd();

glTranslatef(-center[0],-center[1],0);
if (DEBUG) drawBorder();

}

GLboolean Brick::collides(GameObject * go){

	//	printf("Brick  %f %f Player %f %f\n",border[0],border[1],go->border[0],go->border[1] );
	if(go->border[0] > border[0] && go->border[0] < border[0]+ border[2] )  // Check X
	{
		printf("X Check true  player %f %f",go->border[0],go->border[1] );
		
		if(go->border[1] > border[1] && go->border[1] < border[1]+ border[3] )  // Check Y
		{
		printf("Y check true");
			return TRUE;
		}
	}
	return FALSE;

}

void Brick::drawBorder(){

	glColor3f(1,1,0);
  glLineWidth(2.0f);
  glLineStipple(2,0xAAFF);
  glEnable (GL_LINE_STIPPLE);

	glBegin(GL_LINE_LOOP);

	glVertex2f(border[0]             ,border[1]);
	glVertex2f(border[0] + border[2] ,border[1]);
	glVertex2f(border[0] + border[2] ,border[1] + border[3]);
	glVertex2f(border[0]             ,border[1] + border[3]);
	
	glEnd();
  glDisable (GL_LINE_STIPPLE);

}

void Brick::calc(){
		border[0] = center[0] - dim[0]/2;
	    border[1] = center[1] - dim[1]/2;
}

Brick::~Brick()
{
}
