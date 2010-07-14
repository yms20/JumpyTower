#include "Player.h"

Player::Player()
{
	pos[0] = WIDTH/2;
	pos[1] = 11;
	dir = 90;
	speed = 2 ; 
	GLfloat eTarget[3] = {WIDTH/2,0,0};
	e = new Emitter(pos,eTarget, 1);
	lastFloor = 0;
	tmpLastFloor = 1;
	
	radius = 20;
	
	border[0] = - radius;
	border[1] = - radius;
	border[2] = 2 * radius;
	border[3] = 2 * radius;
	
	friction = 1.7;
	maxHorSpeed = 23;
	maxHorF = 4;
	horSpeed = 0;
	maxVertF = 600;
	maxVertSpeed = 40;	
		
	printf("Debug: Player Constructor Ended\n");
}
void Player::draw(){
	//printf("Player pos[0] %f pos[1] %f",pos[0],pos[1]);

glTranslatef(pos[0], pos[1],0);
	  static GLUquadricObj * s;
  if ( s == 0){
    s = gluNewQuadric();
  }
  gluQuadricDrawStyle(s,GLU_FILL);
  glColor3f(1.0f,1.0f,0.0f);
  gluDisk(s,0.0,radius,10,1);

glColor3f(1,0,1);
glBegin(GL_LINES);

glVertex2f(0,0);
glVertex2f(30* cos(dir/360.0 * 2*M_PI),30 * sin(dir/360.0 * 2*M_PI));

glEnd();

glTranslatef(-pos[0], -pos[1],0);
if (DEBUG) drawBorder();
e->draw();



//printf("Debug: Player pos(%.0f,%.0f) speed(%.0f) grav(%.0f)\n",pos[0],pos[1],speed,gravity);
}

void Player::drawBorder(){

  glLineWidth(2.0f);
  glLineStipple(2,0xAAA0);
  glEnable (GL_LINE_STIPPLE);

	glBegin(GL_LINE_LOOP);

	glVertex2f(border[0]             ,border[1]);
	glVertex2f(border[0] + border[2] ,border[1]);
	glVertex2f(border[0] + border[2] ,border[1] + border[3]);
	glVertex2f(border[0]             ,border[1] + border[3]);
	
	glEnd();
  glDisable (GL_LINE_STIPPLE);


	glBegin(GL_LINES);

	glVertex2f(pos[0] - radius  -4            ,pos[1]);
	glVertex2f(pos[0]  - radius  -4           ,pos[1] + vertSpeed* 5);
	
	glEnd();
  
  
}

void Player::calc(){
	
	border[0] = pos[0] - radius;
	border[1] = pos[1] - radius;
	
	e->pos[0] = pos[0];
	e->pos[1] = pos[1];
	e->calc();
	
	// Geschwindigkeit erhoehen wenn nich max erreicht
	if (horSpeed < maxHorSpeed && horSpeed > maxHorSpeed *-1)
	{
		horSpeed += horF; 
	}
	
 
 
	
 		vertF -= gravity /( 1000.0f / FRAMETIME); 	
	
	vertSpeed += vertF;
	
	//Reibung von Horizontaler Kraft abziehen
	 if (horSpeed != 0 )
	{
		if (horSpeed >= 0){
			horSpeed -= friction;
			if (horSpeed < 0 )
			 horSpeed = 0;
		}else if (horSpeed  <= 0){
			horSpeed += friction;
			if (horSpeed > 0 )
			 horSpeed = 0;
		}else {
			horSpeed = 0;
		}		
	}
	

	 if (pos[1] < 40 )
	{ 
		pos[1] = 40;
		vertSpeed = 0; 
	} 

pos[0] += horSpeed; //speed * cos(dir/360.0 * 2*M_PI);
pos[1] += vertSpeed ;
	horF = 0;
	vertF = 0;
}

GLboolean Player::collides(GameObject *go){
return FALSE;
}

Player::~Player()
{
	

}
