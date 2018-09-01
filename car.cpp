#include <iostream>
#include <stdlib.h>
#include <math.h>
#include<GL/glu.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;

int c = 0;
int x, y;

string a=" ";

//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float _angle = 0.0;
float _cameraAngle = 0.0;
float _ang_tri = 0.0;
float angx = 1;
float angy = 0;
float angz = 0;
float zoom = 1;
int countkey = 0;
float rl = 0.0;
float ud = 0.0;
//Draws the 3D scene
void drawScene() {


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	//glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(0.0, 0.0, -7.0); //Move forward 5 units



glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0.2,0.5,0.7, 1);



glColor3ub(168, 126, 68);
glPushMatrix(); //Save the transformations performed thus far



glTranslatef(rl, ud, 0.0); //Move to the center of the trapezoid
glScalef(zoom,zoom,zoom);
glRotated(angx,1.0, 0.0, 0.0);
glRotated(angy,0.0, 1.0, 0.0);
glRotated(angz,0.0, 0.0, 1.0);

glPushMatrix();

glTranslatef(-2.0,0.0,1);

glPushMatrix();
glColor3ub(255, 255, 0);

glBegin(GL_POLYGON);
glVertex3f(0,0,0);
glVertex3f(2,0,0);
glVertex3f(2,2,0);
glVertex3f(0,2,0);
glEnd();

glBegin(GL_POLYGON);
glVertex3f(2,0,0);
glVertex3f(2.4,0.3,0);
glVertex3f(2.4,2,0);
glVertex3f(2,2,0);
glEnd();

glBegin(GL_POLYGON);

glVertex3f(2.4,0.3,0);
glVertex3f(2.6,0.6,0);
glVertex3f(2.6,2,0);
glVertex3f(2.4,2,0);
glEnd();


glBegin(GL_POLYGON);


glVertex3f(2.6,0.6,0);
glVertex3f(3.2,0.6,0);
glVertex3f(3.2,2,0);
glVertex3f(2.6,2,0);

glEnd();


glBegin(GL_POLYGON);


glVertex3f(3.2,0.6,0);
glVertex3f(3.5,0.2,0);
glVertex3f(3.8,0.4,0);
glVertex3f(3.8,0.6,0);
glVertex3f(3.6,0.6,0);
glVertex3f(3.6,1.9,0);
glVertex3f(3.2,2,0);

glEnd();

glBegin(GL_POLYGON);


glColor3f(0,0,0);
glVertex3f(3.2,0.6,0.01);
glVertex3f(3.5,0.2,0.01);
glVertex3f(3.8,0.4,0.01);
glVertex3f(3.8,0.6,0.01);
glVertex3f(3.2,0.6,0.01);
glColor3f(1,1,0);
glEnd();

glBegin(GL_POLYGON);


glVertex3f(0,0.0,0.0);
glVertex3f(0,2,0);
glVertex3f(-0.5,1.2,0);
glVertex3f(-0.5,0,0);


glEnd();


glBegin(GL_POLYGON);



glVertex3f(-0.5,1.2,0);
glVertex3f(-2,1,0);
glVertex3f(-2,0.6,0);
glVertex3f(-1.9,0.4,0);
glVertex3f(-1.8,0.4,0);
glVertex3f(-1.6,0.6,0);
glVertex3f(-0.8,0.6,0);
glVertex3f(-0.5,0,0);
glEnd();

glBegin(GL_POLYGON);

glColor3f(0,0,0);

glVertex3f(3.6,1.9,0);
glVertex3f(3.6,1.9,-2);
glVertex3f(3.2,2,-2);
glVertex3f(3.2,2,0);
glEnd();

glBegin(GL_POLYGON);

glColor3f(0,0,0);


glVertex3f(3.2,2,0);
glVertex3f(3.2,2,-2);
glVertex3f(0,2,-2);
glVertex3f(0,2,0);

glEnd();

glBegin(GL_POLYGON);

glColor3f(0,0,0);


glVertex3f(0,2,0);
glVertex3f(0,2,-2);
glVertex3f(-0.5,1.2,-2);
glVertex3f(-0.5,1.2,0);

glEnd();




glBegin(GL_POLYGON);

glColor3f(1,1,0);

glVertex3f(-0.5,1.2,0);
glVertex3f(-0.5,1.2,-2);
glVertex3f(-2,1,-2);
glVertex3f(-2,1,0);


glEnd();

glBegin(GL_POLYGON);

glColor3f(1,1,0);

glVertex3f(-2,1,0);
glVertex3f(-2,1,-2);
glVertex3f(-2,0.6,-2);
glVertex3f(-2,0.6,0);

glEnd();


glBegin(GL_POLYGON);

glColor3f(0,0,0);

glVertex3f(3.5,0.2,0);
glVertex3f(3.8,0.4,0);

glVertex3f(3.8,0.4,-2);
glVertex3f(3.5,0.2,-2);



glEnd();


glBegin(GL_POLYGON);

glColor3f(0,0,0);


glVertex3f(3.8,0.4,0);
glVertex3f(3.8,0.6,0);
glVertex3f(3.8,0.6,-2);
glVertex3f(3.8,0.4,-2);




glEnd();


glBegin(GL_POLYGON);

glColor3f(1,1,0);

glVertex3f(3.6,0.6,0);
glVertex3f(3.8,0.6,0);
glVertex3f(3.8,0.6,-2);
glVertex3f(3.6,0.6,-2);
glVertex3f(3.6,1.9,-2);
glVertex3f(3.6,1.9,0);


glEnd();




glBegin(GL_POLYGON);//window

glColor3f(0,0,0);

glVertex3f(-0.2,1.2,0.01);
glVertex3f(1.3,1.2,0.01);
glVertex3f(1.3,1.9,0.01);
glVertex3f(0.15,1.9,0.01);
glEnd();


glBegin(GL_POLYGON);

glColor3f(0,0,0);


glVertex3f(1.5,1.2,0.01);
glVertex3f(3.5,1.2,0.01);
glVertex3f(3.5,1.8,0.01);
glVertex3f(3.2,1.9,0.01);
glVertex3f(1.5,1.9,0.01);
glEnd();


glBegin(GL_POLYGON);

glColor3f(0,0,0);


glVertex3f(1.38,0,0.01);
glVertex3f(1.42,0,0.01);
glVertex3f(1.42,2,0.01);
glVertex3f(1.38,2,0.01);

glEnd();

glBegin(GL_POLYGON);

glColor3f(0,0,0);


glVertex3f(-0.5,0,0.01);
glVertex3f(2,0,0.01);
glVertex3f(2.4,0.3,0.01);
glVertex3f(-0.65,0.3,0.01);

glEnd();


glBegin(GL_POLYGON);

glColor3f(0,0,0);

glVertex3f(3.601,0.6,0);
glVertex3f(3.601,0.6,-0.2);
glVertex3f(3.601,1.9,-0.2);
glVertex3f(3.601,1.9,0);


glEnd();




glPopMatrix();







glPushMatrix();////bodyz
glTranslatef(0.0,0.0,-2);

glColor3ub(255, 255, 0);

glBegin(GL_POLYGON);
glVertex3f(0,0,0);
glVertex3f(2,0,0);
glVertex3f(2,2,0);
glVertex3f(0,2,0);
glEnd();

glBegin(GL_POLYGON);
glVertex3f(2,0,0);
glVertex3f(2.4,0.3,0);
glVertex3f(2.4,2,0);
glVertex3f(2,2,0);
glEnd();

glBegin(GL_POLYGON);

glVertex3f(2.4,0.3,0);
glVertex3f(2.6,0.6,0);
glVertex3f(2.6,2,0);
glVertex3f(2.4,2,0);
glEnd();


glBegin(GL_POLYGON);


glVertex3f(2.6,0.6,0);
glVertex3f(3.2,0.6,0);
glVertex3f(3.2,2,0);
glVertex3f(2.6,2,0);

glEnd();


glBegin(GL_POLYGON);


glVertex3f(3.2,0.6,0);
glVertex3f(3.5,0.2,0);
glVertex3f(3.8,0.4,0);
glVertex3f(3.8,0.6,0);
glVertex3f(3.6,0.6,0);
glVertex3f(3.6,1.9,0);
glVertex3f(3.2,2,0);

glEnd();

glBegin(GL_POLYGON);

glColor3f(0,0,0);

glVertex3f(3.2,0.6,-0.01);
glVertex3f(3.5,0.2,-0.01);
glVertex3f(3.8,0.4,-0.01);
glVertex3f(3.8,0.6,-0.01);
glVertex3f(3.2,0.6,-0.01);
glColor3f(1,1,0);
glEnd();

glBegin(GL_POLYGON);


glVertex3f(0,0.0,0.0);
glVertex3f(0,2,0);
glVertex3f(-0.5,1.2,0);
glVertex3f(-0.5,0,0);


glEnd();


glBegin(GL_POLYGON);



glVertex3f(-0.5,1.2,0);
glVertex3f(-2,1,0);
glVertex3f(-2,0.6,0);
glVertex3f(-2,0.4,0);
glVertex3f(-1.8,0.4,0);
glVertex3f(-1.6,0.6,0);
glVertex3f(-0.8,0.6,0);
glVertex3f(-0.5,0,0);
glEnd();



glBegin(GL_POLYGON);//window

glColor3f(0,0,0);

glVertex3f(-0.2,1.2,-0.01);
glVertex3f(1.3,1.2,-0.01);
glVertex3f(1.3,1.9,-0.01);
glVertex3f(0.15,1.9,-0.01);
glEnd();


glBegin(GL_POLYGON);

glColor3f(0,0,0);


glVertex3f(1.5,1.2,-0.01);
glVertex3f(3.5,1.2,-0.01);
glVertex3f(3.5,1.8,-0.01);
glVertex3f(3.2,1.9,-0.01);
glVertex3f(1.5,1.9,-0.01);
glEnd();


glBegin(GL_POLYGON);

glColor3f(0,0,0);


glVertex3f(1.38,0,-0.01);
glVertex3f(1.42,0,-0.01);
glVertex3f(1.42,2,-0.01);
glVertex3f(1.38,2,-0.01);

glEnd();

glBegin(GL_POLYGON);

glColor3f(0,0,0);


glVertex3f(-0.5,0,-0.01);
glVertex3f(2,0,-0.01);
glVertex3f(2.4,0.3,-0.01);
glVertex3f(-0.65,0.3,-0.01);

glEnd();


glBegin(GL_POLYGON);

glColor3f(0,0,0);

glVertex3f(3.601,0.6,0);
glVertex3f(3.601,0.6,0.2);
glVertex3f(3.601,1.9,0.2);
glVertex3f(3.601,1.9,0);


glEnd();





glPopMatrix();

glPushMatrix();
glRotatef(90,0,1,0);
glTranslatef(1,1.2,3.7);
glutSolidTorus(0.2,0.4,10,30);

glPopMatrix();

glPopMatrix();


glPopMatrix();
glColor3ub(0, 255, 0);
	glRasterPos3d(-5,-2.0,0.0);

	for(int i=0;a[i] != '\0';i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,a[i]);

glutSwapBuffers();



}



void update(int value) {
	_angle += 2.0f;
	if (_angle > 360) {
		_angle -= 360;
	}
	_ang_tri += 2.0f;
	if (_ang_tri > 360) {
		_ang_tri -= 360;
	}

	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(50, update, 0);

}

void keyboard(unsigned char key, int x, int y)
{


	switch (key)
	{

	    case 27:
   exit(1);
	break;


    case 'x':
   angx = angx + 4.5;
   	if (angx > 355) {
		angx = 1;
	}
	break;
	  case 'y':
   angy = angy + 4.5;
      	if (angy > 360) {
		angy = 0.0;
      	}
	break;
	  case 'z':
   angz = angz + 4.5;
      	if (angz > 360) {
		angz = 0.0;
      	}
	break;
	  case '+':
   zoom = zoom +0.050;
   if (zoom > 2)
   {
       zoom = 2.0;
   }
	break;
		  case '-':

   zoom = zoom -0.050;
   if(zoom < 0)
   {
       zoom = 0.0499998;
   }
	break;
	case 'r' :
	angx = 1;
	angy = 0;
	angz = 0;
    rl = 0.0;
	ud = 0.0;

	zoom = 1;
	break;
	case '8':
	ud = ud + 0.1;
	break;

    case '2':
	ud = ud - 0.1;
	break;

    case '4':
	rl = rl - 0.1;
	break;

	case '6':
	rl = rl + 0.1;
	break;

	case '5':


    rl = 0.0;

	ud = 0.0;

	break;
		case '9':
	rl = rl + 0.1;
	ud = ud + 0.1;
	break;
			case '7':
	rl = rl - 0.1;
	ud = ud + 0.1;
	break;

			case '1':
	rl = rl - 0.1;
	ud = ud - 0.1;
	break;

			case '3':
	rl = rl + 0.1;
	ud = ud - 0.1;
	break;

	default:
	break;

	}
	countkey++;
    cout<<"Step : " << countkey <<endl;
    cout<<"pressed : "<<key<<endl;
    cout<<"x : "<<angx-1<<"` "<<"y : "<<angy<<"` "<<"z : "<<angz<<"` "<<endl;
    cout<<"zoom = "<<zoom<<"; Translate(x,y) : ("<<rl<<","<<ud<<")"<<endl;
    cout<<endl;


}

int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1366, 768);

	//Create the window
	glutCreateWindow("Pyramid 3d");
	//gluOrtho2D(-800, 800, -800,800);
	initRendering();



	//Set handler functions
	glutDisplayFunc(drawScene);

	glutReshapeFunc(handleResize);

    glutKeyboardFunc(keyboard);




	glutTimerFunc(10, update, 0); //Add a timer

	glutMainLoop();
	return 0;
}
