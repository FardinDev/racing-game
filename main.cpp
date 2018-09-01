#include <windows.h>
#include <MMSystem.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <chrono>
#include<GL/glu.h>
#include <stdio.h>
#include <GL/glut.h>
#include <sstream>
#include <string>
using namespace std;

chrono::steady_clock sc;
std::ostringstream os;

float _angle = 0.0;
float angx = 222;
float angy = 90;
float angz = 0;
float car2lr = -0.3;
float zoom = 0.25;
float rl = 0.0;
float ud = -0.2;
float red= 0.0;
float green = 0.0;
float blue = 1.0;
float transboard = 1.0;
float greenalpha = 0.2;
float yellowalpha = 0.2;
float redalpha = 0.2;
float carm;
float tyremove;
float random = -1.0;
float mipl = 0.5;
float c1 = -0.3;
float c2 = 0.0;
float carro = 0;
float lifeud = 1.8;
float position = 0.0;
float zk = 0.0;
float yellowlife = 1.0;

double d = 0;

int x, y,wcount,rnt;
int lap = 0;
int laps = 0;
int car2go = 5;
int times = 100;
int randomcount =0;
int alpha = 1;
int countkey = 0;
int c = 0;
int point;

bool on;

auto start = sc.now();



string a="Speed : ";

string s = "00 KMPH";

string p = "Points : ";

string l = "Laps : ";

string ps = "0";

string racetime = "Race-time :";

string runtime = "0 sec";

string String;

string esc = "Press ESC to EXIT";

string ent = "Press ENTER to START/STOP";





void initRendering() {
	glEnable(GL_DEPTH_TEST);
}


void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}


void texts(){



glPushMatrix();//textpush

glTranslatef(9.3, 0.0, 0.0);

glColor3ub(0, 0, 0);
	glRasterPos3d(-5.4,2.6,0.0);

	for(int i=0;esc[i] != '\0';i++)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,esc[i]);


	glRasterPos3d(-6.0,2.35,0.0);

	for(int j=0; ent[j] != '\0';j++)

        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,ent[j]);




glPopMatrix();//textpop

glPushMatrix();/**textpush left **/

glTranslatef(0.5, 0.0, 0.1);

glColor3ub(230, 16, 50);
	glRasterPos3d(-5.5,2.6,0.0);

	for(int i=0;a[i] != '\0';i++)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,a[i]);


	glRasterPos3d(-4.9,2.6,0.0);

	for(int k=0; s[k] != '\0';k++)

        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,s[k]);

	glRasterPos3d(-5.5,2.35,0.0);

	for(int j=0; p[j] != '\0';j++)

        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,p[j]);


        	glRasterPos3d(-4.9,2.35,0.0);

	for(int jt=0; ps[jt] != '\0';jt++)

        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,ps[jt]);


	glRasterPos3d(-5.5,2.15,0.0);

	for(int la=0; l[la] != '\0';la++)

        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,l[la]);

	glRasterPos3d(-4.9,2.15,0.0);

	for(int st=0; String[st] != '\0';st++)

        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,String[st]);


       	glRasterPos3d(-5.5,1.95,0.0);

	for(int o=0; racetime[o] != '\0';o++)

        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,racetime[o]);


    glRasterPos3d(-4.7,1.95,0.0);

	for(int rt=0; runtime[rt] != '\0';rt++)

        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,runtime[rt]);




glPopMatrix();//textpop



}



/** texture*/



GLuint texture[3];



struct Image {


    unsigned long sizeX;


    unsigned long sizeY;


    char *data;


};


typedef struct Image Image;


int ImageLoad(char *filename, Image *image) {


    FILE *file;


    unsigned long size; // size of the image in bytes.


    unsigned long i; // standard counter.


    unsigned short int planes; // number of planes in image (must be 1)


    unsigned short int bpp; // number of bits per pixel (must be 24)


    char temp; // temporary color storage for bgr-rgb conversion.


    // make sure the file is there.


    if ((file = fopen(filename, "rb"))==NULL){


        printf("File Not Found : %s\n",filename);


        return 0;


    }


    // seek through the bmp header, up to the width/height:


    fseek(file, 18, SEEK_CUR);


    // read the width


    if ((i = fread(&image->sizeX, 4, 1, file)) != 1) {


        printf("Error reading width from %s.\n", filename);


        return 0;


    }


    //printf("Width of %s: %lu\n", filename, image->sizeX);


    // read the height


    if ((i = fread(&image->sizeY, 4, 1, file)) != 1) {


        printf("Error reading height from %s.\n", filename);


        return 0;


    }


    //printf("Height of %s: %lu\n", filename, image->sizeY);


    // calculate the size (assuming 24 bits or 3 bytes per pixel).


    size = image->sizeX * image->sizeY * 3;


    // read the planes


    if ((fread(&planes, 2, 1, file)) != 1) {


        printf("Error reading planes from %s.\n", filename);


        return 0;


    }


    if (planes != 1) {


        printf("Planes from %s is not 1: %u\n", filename, planes);


        return 0;


    }


    // read the bitsperpixel


    if ((i = fread(&bpp, 2, 1, file)) != 1) {


        printf("Error reading bpp from %s.\n", filename);


        return 0;


    }


    if (bpp != 24) {


        printf("Bpp from %s is not 24: %u\n", filename, bpp);


        return 0;


    }


    // seek past the rest of the bitmap header.


    fseek(file, 24, SEEK_CUR);


    // read the data.


    image->data = (char *) malloc(size);


    if (image->data == NULL) {


        printf("Error allocating memory for color-corrected image data");


        return 0;


    }


    if ((i = fread(image->data, size, 1, file)) != 1) {


        printf("Error reading image data from %s.\n", filename);


        return 0;


    }


    for (i=0;i<size;i+=3) { // reverse all of the colors. (bgr -> rgb)


        temp = image->data[i];


        image->data[i] = image->data[i+2];


        image->data[i+2] = temp;


    }


    // we're done.


    return 1;


}

Image * loadTextureg(){


    Image *image2;


    // allocate space for texture


    image2 = (Image *) malloc(sizeof(Image));


    if (image2 == NULL) {


        printf("Error allocating space for image");


        exit(0);


    }


    if (!ImageLoad("C:\\Users\\ksk\\Desktop\\3D_Car_Race1517\\grass.bmp", image2)) {


        exit(1);


    }


    return image2;


}




Image * loadTexture(){


    Image *image1;


    // allocate space for texture


    image1 = (Image *) malloc(sizeof(Image));


    if (image1 == NULL) {


        printf("Error allocating space for image");


        exit(0);


    }


    if (!ImageLoad("C:\\Users\\ksk\\Desktop\\skydome2.bmp", image1)) {


        exit(1);


    }


    return image1;


}


void myinit(void)
{


    glClearColor (0.5, 0.5, 0.5, 0.0);


    glEnable(GL_DEPTH_TEST);


    glDepthFunc(GL_LESS);


    Image *image1 = loadTexture();


    if(image1 == NULL){


        printf("Image was not returned from loadTexture\n");


        exit(0);


    }



    Image *image2 = loadTextureg();


    if(image2 == NULL){


        printf("Image was not returned from loadTextureg\n");


        exit(0);


    }



    glPixelStorei(GL_UNPACK_ALIGNMENT, 2);


    // Create Texture


    glGenTextures(2, texture);


    glBindTexture(GL_TEXTURE_2D, texture[0]);


    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); //scale linearly when image bigger than texture


    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); //scale linearly when image smalled than texture


    glTexImage2D(GL_TEXTURE_2D, 0, 3, image1->sizeX, image1->sizeY, 0,


    GL_RGB, GL_UNSIGNED_BYTE, image1->data);


    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);









      // glGenTextures(3, texture);


    glBindTexture(GL_TEXTURE_2D, texture[2]);


    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); //scale linearly when image bigger than texture


    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); //scale linearly when image smalled than texture


    glTexImage2D(GL_TEXTURE_2D, 0, 3, image2->sizeX, image2->sizeY, 0,


    GL_RGB, GL_UNSIGNED_BYTE, image2->data);


    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPEAT);








    glShadeModel(GL_FLAT);










}



void myReshape(int w, int h){


    glViewport(0, 0, w, h);


    glMatrixMode(GL_PROJECTION);


    glLoadIdentity();


    gluPerspective(60.0, 1.0*(GLfloat)w/(GLfloat)h, 1.0, 30.0);



    glMatrixMode(GL_MODELVIEW);


    glLoadIdentity();


    glTranslatef(0.0, 0.0, -3.6);


}



/**texture end*/

void runt()
{
if (on)
   {

     auto endt = sc.now();
	 auto time_span = static_cast<chrono::duration<double>>(endt - start);


    rnt = (int) time_span.count()-12;

runtime = static_cast<ostringstream*>( &(ostringstream() << rnt) )->str();
runtime = runtime + " sec";


point =  lap;

ps = static_cast<ostringstream*>( &(ostringstream() << point*alpha) )->str();


}
}

void signalsound()
{

    PlaySoundA("F:\\utilities\\3D_Car_Race\\SoundEffects\\ping.wav",NULL,SND_ASYNC);
}

void lifeline()
{

    if(lifeud < 0.5)
    {
        yellowlife = 0.0;

    }
    else
    {
        yellowlife = 1.0;
    }

glPushMatrix();

glTranslatef(0,2.6,0);

glPushMatrix();

glPushMatrix();
glColor4f(0.0,0.0,0.0,1.0);

glScalef(1.8,0.2,0.01);
glutWireCube(1);
glPopMatrix();
glScalef(lifeud,0.2,0.01);

glColor4f(1.0,yellowlife,0.0,0.5);


glutSolidCube(1);

glPopMatrix();
glPopMatrix();




}


void car()
{







glPushMatrix();

glTranslatef(0.1,-0.1, 5);
glPushMatrix();//carpush

glScalef(0.8,0.8,0.8);
glScalef(zoom,zoom,zoom);
glTranslatef(0.2, -2.9, random*2);


glPushMatrix();

glTranslatef(position/100+((c1/1)), 0.0, 0.0);

glPushMatrix();//carpush

glPushMatrix();
glColor4f(red,green,blue,0.5);
//
glRotatef(carro*2,0.0,1.0,0.0);

glPushMatrix();







/**car*/
glPushMatrix(); //Save the transformations performed thus far



//Move to the center of the trapezoid

glRotated(5,1.0, 0.0, 0.0);
glRotated(90,0.0, -1.0, 0.0);
glRotated(0,0.0, 0.0, 1.0);



glPushMatrix();


glPushMatrix();

glScalef(2.7,2.7,2.7);
glTranslatef(-0.6, 0.9, 0.0);


glPushMatrix(); //tpush
glScalef(0.2,0.2,0.2);
glTranslatef(0, -4, 0);

glPushMatrix(); //tpush
glTranslatef(-3, 0, 2);



glPushMatrix(); //t1

glColor3ub(0,0,0);

glTranslatef(0.0, 0.0, 0.0);

glPushMatrix();
glRotatef(tyremove,0,1,0);
glRotatef(_angle,0,0,1);
glutSolidTorus(0.4,0.7,9,29);
glPopMatrix();
glPopMatrix();

glPushMatrix(); //t2


glColor3ub(0,0,0);

glTranslatef(0.0, 0.0, -4.0);

glPushMatrix();
glRotatef(tyremove,0,1,0);
glRotatef(_angle,0,0,1);
glutSolidTorus(0.4,0.7,9,29);
glPopMatrix();

glPopMatrix();

glPushMatrix(); //t3



glTranslatef(7.5, 0.0, 0.0);

glRotatef(_angle,0,0,1);
glutSolidTorus(0.4,0.7,9,29);


glPopMatrix();

glPushMatrix(); //t4



glTranslatef(7.5, 0.0, -4.0);

glRotatef(_angle,0,0,1);
glutSolidTorus(0.4,0.7,9,29);


glPopMatrix();

glPopMatrix();//tpop


glPopMatrix();

glPopMatrix();//tpop





glPopMatrix();


glPushMatrix();

glTranslatef(-2.0,0.0,1);


glPushMatrix();
glColor3ub(255, 0, 0);

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

glEnd();

glBegin(GL_POLYGON);

glColor3f(1,0,0);

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

glColor3f(1,0,0);

glVertex3f(-0.5,1.2,0);
glVertex3f(-0.5,1.2,-2);
glVertex3f(-2,1,-2);
glVertex3f(-2,1,0);


glEnd();

glBegin(GL_POLYGON);

glColor3f(1,0,0);

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

glColor3f(1,0,0);

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

glColor3ub(255, 0, 0);

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

glEnd();

glBegin(GL_POLYGON);
glColor3f(1,0,0);

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





glPopMatrix();

/**car*/



glPopMatrix();
glPopMatrix();
glPopMatrix();//carpop
glPopMatrix();

glPopMatrix();

glPopMatrix();
}


void car2()
{


if(on)
{


random =(rand() /(float)RAND_MAX)*0.1;
}







glPushMatrix();

glTranslatef(-1.1+car2lr,-0.1, car2go);
glPushMatrix();//carpush

glScalef(0.8,0.8,0.8);
glScalef(zoom,zoom,zoom);
glTranslatef(-1, -2.9, random);


glPushMatrix();

glTranslatef(position/100+((c1*2)), 0.0, 0.0);

glPushMatrix();//carpush
//glTranslatef(position/100+((c1/1)), 0.0, 0.0);
glPushMatrix();
glColor4f(red,green,blue,0.5);
//
glRotatef(0,0.0,1.0,0.0);

glPushMatrix();







/**car*/
glPushMatrix(); //Save the transformations performed thus far



//Move to the center of the trapezoid

glRotated(5,1.0, 0.0, 0.0);
glRotated(90,0.0, -1.0, 0.0);
glRotated(0,0.0, 0.0, 1.0);



glPushMatrix();


glPushMatrix();

glScalef(2.7,2.7,2.7);
glTranslatef(-0.6, 0.9, 0.0);


glPushMatrix(); //tpush
glScalef(0.2,0.2,0.2);
glTranslatef(0, -4, 0);

glPushMatrix(); //tpush
glTranslatef(-3, 0, 2);



glPushMatrix(); //t1

glColor3ub(0,0,0);

glTranslatef(0.0, 0.0, 0.0);

glPushMatrix();
glRotatef(0,0,1,0);
glRotatef(_angle,0,0,1);
glutSolidTorus(0.4,0.7,9,29);
glPopMatrix();
glPopMatrix();

glPushMatrix(); //t2


glColor3ub(0,0,0);

glTranslatef(0.0, 0.0, -4.0);

glPushMatrix();
glRotatef(0,0,1,0);
glRotatef(_angle,0,0,1);
glutSolidTorus(0.4,0.7,9,39);
glPopMatrix();

glPopMatrix();

glPushMatrix(); //t3



glTranslatef(7.5, 0.0, 0.0);

glRotatef(_angle,0,0,1);
glutSolidTorus(0.4,0.7,9,29);


glPopMatrix();

glPushMatrix(); //t4



glTranslatef(7.5, 0.0, -4.0);

glRotatef(_angle,0,0,1);
glutSolidTorus(0.4,0.7,9,29);


glPopMatrix();

glPopMatrix();//tpop


glPopMatrix();

glPopMatrix();//tpop





glPopMatrix();


glPushMatrix();

glTranslatef(-2.0,0.0,1);


glPushMatrix();
glColor3ub(0, 0, 255);

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

glEnd();

glBegin(GL_POLYGON);

glColor3f(0,0,1);

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

glColor3f(0,0,1);

glVertex3f(-0.5,1.2,0);
glVertex3f(-0.5,1.2,-2);
glVertex3f(-2,1,-2);
glVertex3f(-2,1,0);


glEnd();

glBegin(GL_POLYGON);



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

glColor3f(0,0,1);

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

glColor3ub(0, 0, 255);

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

glEnd();

glBegin(GL_POLYGON);
glColor3f(0,0,1);

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





glPopMatrix();

/**car*/



glPopMatrix();
glPopMatrix();
glPopMatrix();//carpop
glPopMatrix();

glPopMatrix();

glPopMatrix();
}






void life()
{

glPushMatrix();
glTranslatef(-c1,0,0);
glPushMatrix();

glTranslatef(carm/2.5, 0.0,-50+(angz/5));
glColor4f(1.0,0.0,0.0,0.5);
glutSolidSphere(1,30,30);
glPopMatrix();
glPopMatrix();
if(position > -5 && position < 5 && angz == 307.5)
{
    lifeud = lifeud + 0.5;





    if (lifeud > 1.8)

    {
        lifeud = 1.8;
    }
}


}


void obstackle()
{
glPushMatrix();
glTranslatef(-c1, 0.0,0.0);
    glPushMatrix();

glTranslatef(carm/2.5, 0.0,-50+(angz/5));

/**obstacle*/
glPushMatrix();

glPushMatrix();
glTranslatef(-2.45,-1.7,2);
glColor3f(0,0,0);
glutSolidCube(2);


glPushMatrix();

glTranslatef(0,0.4,1);
glScalef(1,1,1);

glPushMatrix();//conestart

glColor3ub(255, 102, 0);
glRotatef(90,-1,0,0);
glutWireCone(0.3,1,50,60);

glPopMatrix();

glPushMatrix();
glTranslatef(-0.6,0,0);
glColor3ub(255, 102, 0);
glRotatef(90,-1,0,0);
glutWireCone(0.3,1,50,60);

glPopMatrix();

glPushMatrix();
glTranslatef(0.6,0,0);
glColor3ub(255, 102, 0);
glRotatef(90,-1,0,0);
glutWireCone(0.3,1,50,60);

glPopMatrix();

glPopMatrix();





glPopMatrix();




glPopMatrix();
glPopMatrix();


/**obstacle*/



glPopMatrix();


if(position<= -9 && position >= -16  && angz > 247  && angz < 289)

{




    lifeud = lifeud - 0.05;


}









}


void goBoard() {





	 auto endt = sc.now();
	 auto time_span = static_cast<chrono::duration<double>>(endt - start);






	 if(time_span.count()>2 && time_span.count()<5 )
     {
       greenalpha = 0.2;
 yellowalpha = 0.2;
redalpha = 1.0;





     }
	else if(time_span.count()>5 && time_span.count()<8 )
     {
       greenalpha = 0.2;
 yellowalpha = 1.0;
redalpha = 0.2;



     }
     else if(time_span.count()>8 && time_span.count()<12 )
     {
       greenalpha = 1.0;
 yellowalpha = 0.2;
redalpha = 0.2;



     }
     else if (time_span.count()>12)
    {
    greenalpha = 0.0;
 yellowalpha = 0.0;
redalpha = 0.0;

transboard = -8.0;

texts();
runt();
lifeline();

     }

	 if(time_span.count()>2.1 && time_span.count()<2.3 )
     {
signalsound();



     }
	else if(time_span.count()>5.1 && time_span.count()<5.3 )
     {
signalsound();


     }
     else if(time_span.count()>8.1 && time_span.count()<8.3 )
     {
  signalsound();



     }

glPushMatrix();
glTranslatef(0.0,transboard,0.0);
glPushMatrix();
glScalef(1.0,0.5,0.01);
glTranslatef(0.0,transboard,0.0);
glColor4f(0.0,0.0,0.0,0.5);

glutSolidCube(2);

glPopMatrix();

glPushMatrix();//red light
glTranslatef(0.0,0.8,0.0);
glColor4f(1.0,0.0,0.0,redalpha);

glutSolidSphere(0.1,20,20);



glTranslatef(-0.3,0.0,0.0);
glutSolidSphere(0.1,20,20);

glTranslatef(0.6,0.0,0.0);
glutSolidSphere(0.1,20,20);


glPopMatrix();

glPushMatrix();//y light
glTranslatef(0.0,0.5,0.0);
glColor4f(1.0,1.0,0.0,yellowalpha);

glutSolidSphere(0.1,20,20);

glTranslatef(-0.3,0.0,0.0);
glutSolidSphere(0.1,20,20);

glTranslatef(0.6,0.0,0.0);
glutSolidSphere(0.1,20,20);

glPopMatrix();

glPushMatrix();//g light
glTranslatef(0.0,0.2,0.0);
glColor4f(0.0,1.0,0.0,greenalpha);

glutSolidSphere(0.1,20,20);

glTranslatef(-0.3,0.0,0.0);
glutSolidSphere(0.1,20,20);

glTranslatef(0.6,0.0,0.0);
glutSolidSphere(0.1,20,20);

glPopMatrix();



glPopMatrix();//carpop





glColor4f(1.0, 1.0, 1.0, 0.8);


	glRasterPos3d(-0.82,transboard-0.2,0.1);

	for(int j=0; ent[j] != '\0';j++)

        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,ent[j]);

}


void gameoverText()
{
    string gover = "YOU ARE OUT OF FUEL!!";
string gover1 = "GAME OVER";

string escs = "PRESS Esc TO EXIT";
    glPushMatrix();//textpush

glTranslatef(0, 0.1, 6);

glColor3ub(0, 0, 0);
	glRasterPos3d(-0.1,0.05,0.0);

	for(int i=0;gover[i] != '\0';i++)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,gover[i]);


	glRasterPos3d(-0.05,0,0.0);

	for(int j=0; gover1[j] != '\0';j++)

        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,gover1[j]);

	glRasterPos3d(-0.085,-0.05,0.0);

	for(int k=0; escs[k] != '\0';k++)

        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,escs[k]);




glPopMatrix();//textpop


}


void gameover()
{





glPushMatrix();

glTranslatef(0,0,5.5);


glPushMatrix();

glPushMatrix();
glScalef(1.0,0.5,0.01);

glColor4f(1.0,0.0,0.0,0.5);

glutSolidCube(10);

glPopMatrix();



glPopMatrix();





greenalpha = 0.1;
if(on)
{


on = !on;

}





glPopMatrix();


gameoverText();



}


void flags()

{



    glPushMatrix();
glTranslatef(-c1/2,0,0);
glRotatef(0.3,-1,0,0);
glPushMatrix();

glTranslatef(carm/2.5, 0.0,(angz/8));
glColor4f(1.0,1.0,1.0,0.8);

    glPushMatrix();/** mainpush*/
glTranslatef(-2.5,0.0,4.5);

glTranslatef(-3,-0.6,0);
glScalef(zoom,zoom,zoom);




for(int i = 0; i > -500; i -=8 )
{
   glPushMatrix();
glTranslatef(0,0.1,i);
glPushMatrix();
glTranslatef(0,0,0);
glColor3ub(255,255,0);

glBegin(GL_POLYGON);

glVertex3f(0,0,0);
glVertex3f(1,.5,0);
glVertex3f(0,1,0);

glEnd();
glPopMatrix();




glPushMatrix();
glScalef(0.1,2,0.1);
glColor3ub(0,0,0);

glutSolidCube(1);


glPopMatrix();


/** */
glPushMatrix();

glTranslatef(0,0,4);

glPushMatrix();
glTranslatef(0,0,0);
glColor3ub(255,0,0);

glBegin(GL_POLYGON);

glVertex3f(0,0,0);
glVertex3f(1,.5,0);
glVertex3f(0,1,0);

glEnd();
glPopMatrix();




glPushMatrix();
glScalef(0.1,2,0.1);
glColor3ub(0,0,0);

glutSolidCube(1);


glPopMatrix();








glPopMatrix();


/**xaxis*/
glPushMatrix();

glRotatef(180,0,-1,0);
glTranslatef(-30,0,0);
glPushMatrix();
glTranslatef(0,0.1,0);
glPushMatrix();
glTranslatef(0,0,0);
glColor3ub(255,255,0);

glBegin(GL_POLYGON);

glVertex3f(0,0,0);
glVertex3f(1,.5,0);
glVertex3f(0,1,0);

glEnd();
glPopMatrix();




glPushMatrix();
glScalef(0.1,2,0.1);
glColor3ub(0,0,0);

glutSolidCube(1);


glPopMatrix();



glPushMatrix();

glTranslatef(0,0,4);

glPushMatrix();
glTranslatef(0,0,0);
glColor3ub(255,0,0);

glBegin(GL_POLYGON);

glVertex3f(0,0,0);
glVertex3f(1,.5,0);
glVertex3f(0,1,0);

glEnd();
glPopMatrix();




glPushMatrix();
glScalef(0.1,2,0.1);
glColor3ub(0,0,0);

glutSolidCube(1);


glPopMatrix();

glPopMatrix();



glPopMatrix();


glPopMatrix();

glPopMatrix();

/////////////////////////////////////////////////////////////
/*

*/









}
glPopMatrix();/** mainpop*/


glPopMatrix();

glPopMatrix();





}



void lamppost()
{
glPushMatrix();
glTranslatef(-c1/2,0,0);
glPushMatrix();

glTranslatef(carm/2.5, 0.0,(angz/8));
glColor4f(1.0,1.0,1.0,0.8);


    glPushMatrix();/** mainpush

glRotatef(angx,1.0,0,0);
glRotatef(angy,0.0,1,0);
glRotatef(angz,0.0,0,1);*/


glTranslatef(3.5,0.5,-zk);


for(int i = 0; i > -200; i-= 4)
{



glPushMatrix();

glTranslatef(0,0.0,i);

glPushMatrix();/**lamppost*/

glScalef(0.2,4,0.2);
glutSolidCube(1);



glPopMatrix();

glPushMatrix();
glTranslatef(-0.4,2,0);
glScalef(1,0.2,0.2);
glutSolidCube(1);



glPopMatrix();/**lamppost ends*/

glPushMatrix();/**-xaxis*/
glTranslatef(-10,0,0);
glRotatef(180,0,1,0);





glPushMatrix();/**lamppost*/

glScalef(0.2,4,0.2);
glutSolidCube(1);



glPopMatrix();

glPushMatrix();
glTranslatef(-0.4,2,0);
glScalef(1,0.2,0.2);
glutSolidCube(1);



glPopMatrix();/**lamppost ends*/

glPopMatrix();/**-xaxis*/





glPopMatrix();


}




glPopMatrix();/** mainpop*/




glPopMatrix();
glPopMatrix();




}


void drawScene() {



glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -7.0);


glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0.2,0.5,0.7, 1);



glColor3ub(61, 68, 79);
glPushMatrix();
glScalef(4.36, 4.36, 4.36);







glTranslatef(c1, c2, 0.0);

glPushMatrix();
glTranslatef(rl, ud, 0.0);
glScalef(3.0,0.01,4.0);
glRotated(angx,1.0, 0.0, 0.0);
glRotated(angy,0.0, 1.0, 0.0);
glRotated(angz,0.0, 0.0, 1.0);

glutSolidTorus(0.2,3.0,30,50);





glPushMatrix(); /**everything but road*/

glPushMatrix();//white line
glColor3ub(255,255, 255);
glScalef(1,1,0.05);
glutSolidTorus(0.2,3.1,30,50);
glPopMatrix();

glPushMatrix();//y right

glTranslatef(0.0,0.0,0.19);
glPushMatrix();

glColor3ub(255,255, 0);
glScalef(1,1.0,0.05);
glutSolidTorus(0.5,3.5,30,50);
glPopMatrix();
glPushMatrix();
glColor3ub(0,0, 0);
glScalef(1,1.0,0.051);
glutSolidTorus(0.5,3.5,30,50);
glPopMatrix();
glPopMatrix();

glPushMatrix();//y left
glTranslatef(0.0,0.0,-0.19);
glPushMatrix();

glColor3ub(255,255, 0);
glScalef(1,1.0,0.05);
glutSolidTorus(0.5,3.5,30,50);
glPopMatrix();
glPushMatrix();
glColor3ub(0,0, 0);
glScalef(1,1.0,0.051);
glutSolidTorus(0.5,3.5,30,50);
glPopMatrix();
glPopMatrix();


/**
glPushMatrix();//grass
glColor3ub(86, 200, 64);
glTranslatef(0, 0.0, 0.4);
glutWireTorus(0.2,3.1,60,50);
glPopMatrix();

glPushMatrix();//mountain
glColor3ub(0, 0, 255);
glTranslatef(0, 0.0, 0.8);
glutWireTorus(0.201,3.1,60,50);
glPopMatrix();


glPushMatrix();//mountain
glColor3ub(0, 0, 255);
glTranslatef(0, 0.0, -0.8);
glutWireTorus(0.3,3.9,60,50);
glPopMatrix();


glPushMatrix();//grass
glColor3ub(86, 194, 64);
glTranslatef(0, 0.0, -0.4);


glutWireTorus(0.2,3.1,60,50);

glPopMatrix();

*/





glPushMatrix();//middle line
glTranslatef(0.0, 0.0, 0.1);
glPushMatrix();//line
glColor3ub(255, 255, 0);
glScalef(0.6,0.8,0.01);
glTranslatef(0, 3.5, 0.0);
glutSolidCube(1);

glPopMatrix();

glPushMatrix();//line
glColor3ub(255, 255, 0);
glScalef(0.6,0.8,0.01);
glTranslatef(0, -3.5, 0.0);
glutSolidCube(1);

glPopMatrix();

glPushMatrix();//line
//glColor3ub(255, 255, 255);
glScalef(0.6,0.8,0.01);
glTranslatef(3.5, 0.0, 0.0);
glutSolidCube(1);

glPopMatrix();

glPushMatrix();//line
//glColor3ub(255, 255, 255);
glScalef(0.6,0.8,0.01);
glTranslatef(-3.5, 0.0, 0.0);
glutSolidCube(1);

glPopMatrix();


glPushMatrix();//line
//glColor3ub(0,255,255);
glScalef(0.6,0.8,0.01);
glRotated(60,0.0, 0.0, 1.0);
glTranslatef(0, 3.5, 0);
glutSolidCube(1);

glPopMatrix();

glPushMatrix();//line
//glColor3ub(0,255,255);
glScalef(0.6,0.8,0.01);
glRotated(60,0.0, 0.0, -1.0);
glTranslatef(0, 3.5, 0);
glutSolidCube(1);

glPopMatrix();

glPushMatrix();//line
//glColor3ub(0,255,255);
glScalef(0.6,0.8,0.01);
glRotated(60,0.0, 0.0, 1.0);
glTranslatef(0, -3.5, 0);
glutSolidCube(1);

glPopMatrix();

glPushMatrix();//line
//glColor3ub(0,255,255);
glScalef(0.6,0.8,0.01);
glRotated(60,0.0, 0.0, -1.0);
glTranslatef(0, -3.5, 0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();//line
//glColor3ub(0,0,255);
glScalef(0.6,0.8,0.01);
glRotated(60,0.0, 0.0, 1.0);
glTranslatef(3.5, 0.1, 0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();//line
//glColor3ub(0,0,255);
glScalef(0.6,0.8,0.01);
glRotated(60,0.0, 0.0, -1.0);
glTranslatef(3.5, 0.1, 0);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();//line
//glColor3ub(0,0,255);
glScalef(0.6,0.8,0.01);
glRotated(60,0.0, 0.0, 1.0);
glTranslatef(-3.5, 0.1, 0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();//line
//glColor3ub(0,0,255);
glScalef(0.6,0.8,0.01);
glRotated(60,0.0, 0.0, -1.0);
glTranslatef(-3.5, 0.1, 0);
glutSolidCube(1);
glPopMatrix();

glPopMatrix();

glPushMatrix();//middle line
glTranslatef(0.0, 0.0, -0.1);
glPushMatrix();//line
glColor3ub(255, 255, 0);
glScalef(0.6,0.8,0.01);
glTranslatef(0, 3.5, 0.0);
glutSolidCube(1);

glPopMatrix();

glPushMatrix();//line
//glColor3ub(255, 255, 0);
glScalef(0.6,0.8,0.01);
glTranslatef(0, -3.5, 0.0);
glutSolidCube(1);

glPopMatrix();

glPushMatrix();//line
//glColor3ub(255, 255, 255);
glScalef(0.6,0.8,0.01);
glTranslatef(3.5, 0.0, 0.0);
glutSolidCube(1);

glPopMatrix();

glPushMatrix();//line
//glColor3ub(255, 255, 255);
glScalef(0.6,0.8,0.01);
glTranslatef(-3.5, 0.0, 0.0);
glutSolidCube(1);

glPopMatrix();


glPushMatrix();//line
//glColor3ub(0,255,255);
glScalef(0.6,0.8,0.01);
glRotated(60,0.0, 0.0, 1.0);
glTranslatef(0, 3.5, 0);
glutSolidCube(1);

glPopMatrix();

glPushMatrix();//line
//glColor3ub(0,255,255);
glScalef(0.6,0.8,0.01);
glRotated(60,0.0, 0.0, -1.0);
glTranslatef(0, 3.5, 0);
glutSolidCube(1);

glPopMatrix();

glPushMatrix();//line
//glColor3ub(0,255,255);
glScalef(0.6,0.8,0.01);
glRotated(60,0.0, 0.0, 1.0);
glTranslatef(0, -3.5, 0);
glutSolidCube(1);

glPopMatrix();

glPushMatrix();//line
//glColor3ub(0,255,255);
glScalef(0.6,0.8,0.01);
glRotated(60,0.0, 0.0, -1.0);
glTranslatef(0, -3.5, 0);
glutSolidCube(1);

glPopMatrix();

glPushMatrix();//line
//glColor3ub(0,0,255);
glScalef(0.6,0.8,0.01);
glRotated(60,0.0, 0.0, 1.0);
glTranslatef(3.5, 0.1, 0);
glutSolidCube(1);

glPopMatrix();

glPushMatrix();//line
//glColor3ub(0,0,255);
glScalef(0.6,0.8,0.01);
glRotated(60,0.0, 0.0, -1.0);
glTranslatef(3.5, 0.1, 0);
glutSolidCube(1);

glPopMatrix();


glPushMatrix();//line
//glColor3ub(0,0,255);
glScalef(0.6,0.8,0.01);
glRotated(60,0.0, 0.0, 1.0);
glTranslatef(-3.5, 0.1, 0);
glutSolidCube(1);

glPopMatrix();

glPushMatrix();//line
//glColor3ub(0,0,255);
glScalef(0.6,0.8,0.01);
glRotated(60,0.0, 0.0, -1.0);
glTranslatef(-3.5, 0.1, 0);
glutSolidCube(1);

glPopMatrix();

glPopMatrix();



glPopMatrix();



glPopMatrix();

glPopMatrix();/**everything but road*/














  glEnable(GL_TEXTURE_2D);
    glPushMatrix(); /**SKY**/
glTranslatef((angy - 90)/2,-3.0,-125.0);

glColor4f(0.0,0.0,0.0,1.0);
glBindTexture(GL_TEXTURE_2D, texture[0]);
glBegin(GL_QUADS);
glTexCoord2f(0.0, 0.0);
glVertex3f(-120.0,-120.0,0.0);

glTexCoord2f(1.0, 0.0);
glVertex3f(120.0,-120.0,0.0);

 glTexCoord2f(1.0, 1.0);
glVertex3f(120.0,120.0,0.0);

glTexCoord2f(0.0, 1.0);
glVertex3f(-120.0,120.0,0.0);
glEnd();

glDisable(GL_TEXTURE_2D);
glPopMatrix();





 glPushMatrix();

glRotatef(90.18,-1,0,0);

 glEnable(GL_TEXTURE_2D);

    glPushMatrix(); /**grass**/
glTranslatef(0,10,-0.76);

glColor4f(1.0,0.0,0.0,1.0);
glBindTexture(GL_TEXTURE_2D, texture[2]);

glRotatef(angz/3,0,0,1);
glBegin(GL_QUADS);
glTexCoord2f(0.0, 0.0);
glVertex3f(-50.0,-50.0,0.0);

glTexCoord2f(1.0, 0.0);
glVertex3f(50.0,-50.0,0.0);

 glTexCoord2f(1.0, 1.0);
glVertex3f(50.0,50.0,0.0);

glTexCoord2f(0.0, 1.0);
glVertex3f(-50.0,50.0,0.0);
glEnd();


glPopMatrix();

glPopMatrix();




glDisable(GL_TEXTURE_2D);
glPopMatrix();



if (c1 > 0.8 || c1 < -0.8)
    {
wcount = 2;
            times = 40;
            s = "20 KMPH";

}
if (lap > 0 &&  lap % 10 == 0)

{
life();

}


if(lap% 12 == 0)

{
    obstackle();


}

if(lap > 0 && lap% 12 == 0)

{

       car2lr = car2lr+0.01;

}




if(lifeud == 0)

{
            gameover();




}

if(car2lr > 0.8 && wcount > 6 && position < -3)
{
    lifeud = 0.5;
}







car();
car2();
goBoard();
lamppost();
flags();





glutSwapBuffers();



}


void update(int value) {
	_angle += 2.0f;
	if (_angle > 360) {
		_angle -= 360;
	}

if(on){

	angz = angz + 7.5;
      	if (angz > 360) {
		angz = 0.0;

			lap++;
            angy = angy - mipl;
			 c1 = c1 + mipl *0.1;
			 car2lr =  c1 + mipl *0.1;


			if (angy < 84)
            {
                mipl = -mipl;
                 //c1 = c1 - 0.05;

            }
            else if (angy > 94){

                mipl = -mipl;
            }

      	}
}

laps = lap / 10;

String = static_cast<ostringstream*>( &(ostringstream() << laps) )->str();






if (lap > 0 && lap % 2 == 0)
{
    lifeud = lifeud -0.0015;

    if (lifeud < 0)
    {
        lifeud = 0;



    }

}




	glutPostRedisplay();


	glutTimerFunc(times, update, 0);

}

void backsound()
{
        PlaySoundA("F:\\utilities\\3D_Car_Race\\SoundEffects\\mmm.wav",NULL,SND_ASYNC);
}


void keyboard(unsigned char key, int x, int y)
{


	switch (key)
	{

	  case 27:
	      cout<<endl;
	      cout<<endl;
	      cout<<"--------------GAME OVER---------------"<<endl;

   exit(1);
	break;


	  case 'y':
   angy = angy + 0.5;
      	if (angy > 360) {
		angy = 0.0;
      	}
	break;

		  case 't':
   angy = angy - 0.5;
      	if (angy < 0.0) {
		angy = 0.0;
      	}
	break;


	/** accelareate **/
	  case 'w':


  if(on){

         red = 0.0;
            blue = 1.0;
            car2go++;
            if(car2go > 6)
            {
                car2go = 6;
            }

      	wcount++;
      	if (wcount == 1)
      	{times = 45;
      	s = "10 KMPH";}
      	else if (wcount == 2 )
        {
            times = 40;
            s = "20 KMPH";
        }
        else if (wcount == 3 )
        {
            times = 35;
            s = "30 KMPH";
        }

        else if (wcount == 4 )
        {
            times = 32;
            s = "40 KMPH";
        }

        else if (wcount == 5 )
        {
            times = 30;
            s = "50 KMPH";
        }

         else if (wcount == 6 )
        {
            times = 27;
            s = "70 KMPH";
        }
         else if (wcount == 7 )
        {
            times = 25;
            s = "80 KMPH";
        }
        else if (wcount == 8)
        {
            times = 23;
            s = "100 KMPH";
        }
        else if(wcount == 9)
            {
            times = 20;
            s = "120 KMPH";
            }
            else if (wcount > 10)
            {
              wcount = 9;
            }
      	}


	break;

/** break **/

      case 's':

	    if(on)
	         {

            red = 1.0;
            blue = 0.0;
            car2go--;





	         	wcount--;
	         	if (wcount == 1)
      	{times = 45;
      	s = "10 KMPH";}
      	else if (wcount == 2 )
        {
            times = 40;
            s = "20 KMPH";
        }
        else if (wcount == 3 )
        {
            times = 35;
            s = "30 KMPH";
        }

        else if (wcount == 4 )
        {
            times = 32;
            s = "40 KMPH";
        }

        else if (wcount == 5 )
        {
            times = 30;
            s = "50 KMPH";
        }

         else if (wcount == 6 )
        {
            times = 27;
            s = "70 KMPH";
        }
         else if (wcount == 7 )
        {
            times = 25;
            s = "80 KMPH";
        }
        else if (wcount == 8)
        {
            times = 23;
            s = "100 KMPH";
        }

        else if(wcount < 0)
            {
            //times = 1500;

            times = times + 15;
            s = "00 KMPH";
            wcount = 0;





            }
	         }

	break;


/** start/stop **/
	case 13:

	    if(greenalpha == 1.0 || greenalpha == 0.0)
        {


   on = !on;

   if(on)
   {


   s = "05 KMPH";
   PlaySoundA("F:\\utilities\\3D_Car_Race\\SoundEffects\\carStart.wav",NULL,SND_SYNC);

   backsound();


   }
   else
   {
      s = "00 KMPH";

   }

        }

	break;

	  case '+':
   zoom = zoom +0.0050;

	break;
		  case '-':

   zoom = zoom -0.0050;

	break;

/** left **/
case 'a':

       if(on){

              tyremove = tyremove + 8;

   if(tyremove > 32)
   {
       tyremove = 32;
   }


            carm = carm + 0.5;

            carro++;
            if (carm > 10)
            {
                carm = 10;
            }

           // carm = 0;

	c1 = c1 + 0.05;




	if(c1 > 1.5)

    {

        c1 = 1.5;



    }



    	position = position -1;


       }


	break;

/** right **/
     case 'd':

if(on){

   tyremove = tyremove - 8;

      if(tyremove < -32)
   {
       tyremove = -32;
   }



      if(on){
            carm = carm -0.5;
            carro--;
            if (carm < -10)
            {
                carm = -10;
            }
	c1 = c1 - 0.05;



if(c1 < -1.5)
    {
        c1 = -1.5;

    }
position = position + 1.0;




      }
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





	default:
	break;

}
	countkey++;


if (carro > 0)
{
    carro = carro - 0.6;

}
if(carro < 0 )
{
    carro = carro + 0.6;

}

if( tyremove > 0)
{
    tyremove = tyremove - 3;
}
if( tyremove < 0)
{
    tyremove = tyremove + 3;
}

    cout<<"Step : " << countkey <<endl;
    cout<<"pressed : "<<key<<endl;
    cout<<"x : "<<angx-1<<"` "<<"y : "<<angy<<"` "<<"z : "<<angz<<"` "<<endl;
    cout<<"zoom = "<<zoom<<"; Translate(x,y) : ("<<rl<<","<<ud<<")"<<endl;
    cout<<"zoom = "<<zoom<<"; Translate(c1,c2) : ("<<c1<<","<<c2<<")" << "laps "<<lap<<endl;

    cout<<" position " << position<<"   random : "<< random <<"` " <<endl;
    cout<<"car 2 : "<<car2lr<<" seconds !!!";

    cout<<endl;





}


int main(int argc, char** argv) {




	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(800, 600);


	glutCreateWindow("3D CAR RACE");

	initRendering();

glutReshapeFunc (myReshape);
myinit();


	glutDisplayFunc(drawScene);

	glutReshapeFunc(handleResize);

    glutKeyboardFunc(keyboard);








 glutTimerFunc(40, update, 0);
  glutFullScreen();


	glutMainLoop();

	return 0;
}
