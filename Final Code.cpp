#include<GL/glut.h>
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>

#include<GL/gl.h>
#include<string.h>

#define sendwindow          0
#define receivewindow       1
#define safesending			2
#define packetcrashing      3
#define timeout				4
#pragma GCC diagnostic ignored "-Wwrite-strings"
//#define exit				5

#define		one				6
#define		two				7
#define		three			8
#define		four			9
#define		five			10
#define		six				11
#define		seven			12
#define		eight			13
#define		nine			14
#define		ten				15
#define		mainmenu		16
#define     sendop			17
#define dx 15
#define dy 25

int window;
int flag=0;

char E[1000]="msg";
FILE *f1,*f2;
char ch;
GLfloat x[25];
GLfloat y[20];
GLint i,j,k;
int w,h,a,b,c,e,d,l;




void *currentfont;


void setFont(void *font)
{
	currentfont=font;
}


void drawstring(float x,float y,float z,char *string) //to display text messages
{
	    char *c;
	glRasterPos3f(x,y,z);

	for(c=string;*c!='\0';c++)
	{	glColor3f(0.2,0.0,0.7);
		glutBitmapCharacter(currentfont,*c);
	}
}



void delay()
{  j=28000;
	while(j!=0)
	{	j--;
		i=28000;
		while(i!=0)
		{	i--;
		}
	}
}


void title()												// to draw the starting screen
{

	setFont(GLUT_BITMAP_HELVETICA_18);
		glBegin(GL_POLYGON);
			//glColor3f(0.0,0.1,0.2);
glColor3f(0.0,0.1,1.0);
		glVertex2i(0,500);
			glColor3f(0.0,1.0,0.0);
		glVertex2i(0,0);
		glColor3f(1.0,0.1,0.0);
		glVertex2i(500,0);
			glColor3f(0.0,0.1,0.2);
		glVertex2i(500,500);
	glEnd();
//	sndPlaySound("CHIMES.wav",SND_ASYNC);

	glColor3f(1.0,0.0,1.0);
	drawstring(20.0,435.0,1.0,"*  * G R A P H I C A L   I L L U S T R A T I O N   OF   S E L E C T I V E   R E P E A T    A R Q   P R O T O C O L *  *");

	glColor3f(1.0,1.0,1.0);
	drawstring(210.0,365.0,1.0,"SUBMITTED   BY");

	glColor3f(0.0,1.0,1.0);
	drawstring(180.0,340.0,1.0," ANKITH G                  4MU15CS004");

	glColor3f(0.0,1.0,1.0);
	drawstring(180.0,320.0,1.0," SANDESH S	              4MU15CS059");

	glColor3f(1.0,1.0,1.0);
	drawstring(190.0,260.0,1.0,"UNDER THE GUIDANCE OF");

	glColor3f(0.0,1.0,1.0);
	drawstring(190.0,230.0,1.0,"MRS.SOWMYA B J ");

		setFont(GLUT_BITMAP_HELVETICA_12);

	glColor3f(0.0,1.0,1.0);
	drawstring(270.0,230.0,1.0,     "    M.TECH.,B.E.");

	glColor3f(0.0,1.0,1.0);
	drawstring(220.0,215.0,1.0,"Asst.Prof, Dept of CSE");

	glColor3f(0.0,1.0,1.0);
	drawstring(230.0,200.0,1.0,"MRIT,MANDYA");


	setFont(GLUT_BITMAP_HELVETICA_18);
    setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
	drawstring(400.0,100.0,1.0," Press M -> continue");

	glFlush();
}

void draw(int c) // TO DRAW POLYGON FOR DISPLAY MENUS
{

    glBegin(GL_POLYGON);
glColor3f(1.0f,0.8f,0.0f);
		glVertex2i(0,425-c);
	glColor3f(0.8076,0.2,0.4076); 	//	glColor3f(0.4076,0.0,1.6076);
		glVertex2i(100,395-c);
		glColor3f(1.0f,0.7f,0.0f);
		glVertex2i(425,395-c);
		glColor3f(1.0f,0.4f,0.0f);
		glVertex2i(425,425-c);
	glEnd();
	glFlush();
}
void drawop(int d,int e) // TO DRAW POLYGON FOR selection a,b,c,detcMENUS
{

    glBegin(GL_POLYGON);
	glColor3f(0.2f,0.2f,0.7f);
		glVertex2i(d+57.5,320-e);
	glColor3f(0.2f,0.1f,0.8f);
		glVertex2i(d+147.5,320-e);
		glColor3f(0.2f,0.1f,0.7f);
		glVertex2i(d+147.5,300-e);
		glColor3f(0.2f,0.2f,0.8f);
		glVertex2i(d+57.5,300-e);
	glEnd();
	glFlush();
}

void text(void)											// to draw the text in menu screen
{	glClear(GL_COLOR_BUFFER_BIT);
	draw(0);
	draw(55);
	draw(110);
	draw(165);
	draw(220);
	draw(275);


	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(0.4932,0.9996,0.0);
	drawstring(152.0,455.0,1.0,"  S E L E C T I V E    R E P E A T    A R Q  ");

	glColor3f(1.0,1.0,1.0);
	drawstring(185.0,405.0,1.0,"Press W: SEND  WINDOW");

	glColor3f(1.0,1.0,1.0);
	drawstring(185.0,350.0,1.0,"Press R: RECEIVE  WINDOW");

	glColor3f(1.0,1.0,1.0);
	drawstring(185.0,295.0,1.0,"Press S: SAFE  SENDING");

	glColor3f(1.0,1.0,1.0);
	drawstring(185.0,240.0,1.0,"Press P: PACKET  CRASHING");

	glColor3f(1.0,1.0,1.0);
	drawstring(185.0,185.0,1.0,"Press T: TIME  OUT");

	glColor3f(1.0,1.0,1.0);
	drawstring(185.0,130.0,1.0,"Press E: EXIT");
	glFlush();
}


void timer0()
{
	glColor3f(1.4,1.9,0.78);
    glBegin(GL_LINE_LOOP);         // timer for frame 0
		glVertex2f(100,120);
	    glVertex2f(100,130);
		glVertex2f(225,130);
		glVertex2f(225,120);
    glEnd();
	glFlush();
}
void timer1()
{

	glColor3f(1.4,1.9,0.78);
    glBegin(GL_LINE_LOOP);         // timer for frame 1
		glVertex2f(100,100);
	    glVertex2f(100,110);
		glVertex2f(225,110);
		glVertex2f(225,100);
    glEnd();
	glFlush();


}

void timer2()
{
	glColor3f(1.4,1.9,0.78);
    glBegin(GL_LINE_LOOP);         // timer for frame 2
		glVertex2f(100,80);
	    glVertex2f(100,90);
		glVertex2f(225,90);
		glVertex2f(225,80);
    glEnd();
	glFlush();
}

void timer3()
{
	glColor3f(1.4,1.9,0.78);
    glBegin(GL_LINE_LOOP);         // timer for frame 3
		glVertex2f(360,120);
	    glVertex2f(360,130);
		glVertex2f(485,130);
		glVertex2f(485,120);
    glEnd();
	glFlush();
}

void timer4()
{
	glColor3f(1.4,1.9,0.78);
    glBegin(GL_LINE_LOOP);         // timer for frame 4
		glVertex2f(360,100);
	    glVertex2f(360,110);
		glVertex2f(485,110);
		glVertex2f(485,100);
    glEnd();
	glFlush();
}


void timer(float k,float l,float m,float n)
{
glColor3f(0.6076,0.0,0.6076);
    glBegin(GL_POLYGON);         // to call timer functions
		glVertex2f(l,m);
	    glVertex2f(l,n);
		glVertex2f(l+k,n);
		glVertex2f(l+k,m);
    glEnd();
	glFlush();

}

void move1()  //MOVEMENT OF FRAME 0  (in safe sending)
{

	float i,j,temp=0.3,k=0;

    glColor3f(1.0,0.8,0.4);
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(30.0,125.0,1.0," Timer 0");

	timer0();


	setFont(GLUT_BITMAP_HELVETICA_12);
	glColor3f(1.0f,1.0f,0.0f);
    drawstring(58.5,300.0,1.0,"FRAME 0 sending ...........");

   for(j=0;j<4;j=j+temp) //movement of data packet within the frame
	 {   glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(55,265-j);glVertex2i(55,280-j);glVertex2i(60,280-j);glVertex2i(60,265-j);
    glEnd();
    glFlush();


	 glColor3f(0.2,0.0,0.7);   // to remove traces create movement of frame in black
		 glBegin(GL_QUADS);
	  glVertex2i(55,265-j);glVertex2i(55,280-j);glVertex2i(60,280-j);glVertex2i(60,265-j);
    glEnd();
    glFlush();
	 }


	 for(j=0;j<60;j=j+temp) //movement of data packet from top to down
	 {   glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(55,238-j);glVertex2i(55,253-j);glVertex2i(60,253-j);glVertex2i(60,238-j);
    glEnd();
    glFlush();

	k+=0.05;
	timer(k,102.5,122,128);


	 glColor3f(0.2,0.0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(55,238-j);glVertex2i(55,253-j);glVertex2i(60,253-j);glVertex2i(60,238-j);
    glEnd();
    glFlush();
	 }


 for(i=0;i<231;i=i+temp) //movement of data packet sidewise
	 {   glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(60+i,178);glVertex2i(60+i,183);glVertex2i(75+i,183);glVertex2i(75+i,178);
    glEnd();
    glFlush();


	k+=0.05;
	timer(k,102.5,122,128);


   glColor3f(0.2,0.0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(60+i,178);glVertex2i(60+i,183);glVertex2i(75+i,183);glVertex2i(75+i,178);
    glEnd();
    glFlush();
 }




for(j=0;j<60;j=j+temp) //to move the  packet from bottom to top
{
	glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(305,178+j);glVertex2i(305,193+j);glVertex2i(310,193+j);glVertex2i(310,178+j);
    glEnd();
    glFlush();

	k+=0.05;
	timer(k,102.5,122,128);

	glColor3f(0.2,0.0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(305,178+j);glVertex2i(305,193+j);glVertex2i(310,193+j);glVertex2i(310,178+j);
    glEnd();
      glFlush();

	}

	setFont(GLUT_BITMAP_HELVETICA_12);
	glColor3f(0.2f,0.0f,0.7f);
    drawstring(58.5,300.0,1.0,"FRAME 0 sending ...........");

    glColor3f(1.0,1.0,0.0);
    drawstring(58.5,300.0,1.0,"FRAME 0 sent");

   // delay();

	setFont(GLUT_BITMAP_HELVETICA_12);
	glColor3f(0.2,0.0,0.7);
    drawstring(58.5,300.0,1.0,"FRAME 0 sent");
    f2=fopen("output.txt","w");
	while((ch=fgetc(f1))!=EOF){
		fputc(ch,f2);
	}
}


void move2()   // SIMULTANEOUS  MOVEMENT OF ACK 1 AND FRAME 1(in safe sending)
{


	float i,j,temp=0.3,k=0,l=0;

	setFont(GLUT_BITMAP_HELVETICA_18);

	glColor3f(1.0,0.8,0.4);
	drawstring(30.0,105.0,1.0," Timer 1");


	setFont(GLUT_BITMAP_HELVETICA_12);

    glColor3f(1.0f,1.0f,0.0f);
    drawstring(58.5,300.0,1.0,"FRAME 1 sending ...........");

    glColor3f(1.0f,1.0f,0.0f);
 	drawstring(370.0,300.0,1.0,"........... sending ACK1 ");

	timer1();





     for(j=0;j<4;j=j+temp) //movement of data packet within the frame
	 {   glColor3f(0,1,1);
		 glBegin(GL_QUADS);
	  glVertex2i(320,265-j);glVertex2i(320,275-j);glVertex2i(325,275-j);glVertex2i(325,265-j);
    glEnd();
    glFlush();

	glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(70,265-j);glVertex2i(70,280-j);glVertex2i(75,280-j);glVertex2i(75,265-j);
    glEnd();
    glFlush();

	glColor3f(0.2,0.0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(70,265-j);glVertex2i(70,280-j);glVertex2i(75,280-j);glVertex2i(75,265-j);
    glEnd();
    glFlush();


	 glColor3f(0.2,0.0,0.7);   // to remove traces create movement of frame in black
		 glBegin(GL_QUADS);
	  glVertex2i(320,265-j);glVertex2i(320,275-j);glVertex2i(325,275-j);glVertex2i(325,265-j);
    glEnd();
    glFlush();
	 }



	 for(j=0;j<60;j=j+temp) //movement of data packet from top to down
	 {   glColor3f(0,1,1);
		 glBegin(GL_QUADS);
	  glVertex2i(320,228-j);glVertex2i(320,238-j);glVertex2i(325,238-j);glVertex2i(325,228-j);
    glEnd();
    glFlush();

	 glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(70,238-j);glVertex2i(70,253-j);glVertex2i(75,253-j);glVertex2i(75,238-j);
    glEnd();
    glFlush();


    k+=0.05;
	timer(k,156.5,122,128);
	timer(k,102.5,102,108);



	glColor3f(0.2,0.0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(320,228-j);glVertex2i(320,238-j);glVertex2i(325,238-j);glVertex2i(325,228-j);
    glEnd();
    glFlush();

	glColor3f(0.2,0.0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(70,238-j);glVertex2i(70,253-j);glVertex2i(75,253-j);glVertex2i(75,238-j);
    glEnd();
    glFlush();


	 }

for(i=0;i<235;i=i+temp) //movement of data packet sidewise
	 {   glColor3f(0,1,1);
		 glBegin(GL_QUADS);
	  glVertex2i(310-i,168);glVertex2i(310-i,173);glVertex2i(320-i,173);glVertex2i(320-i,168);
    glEnd();
    glFlush();


	glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(70+i,178);glVertex2i(70+i,183);glVertex2i(85+i,183);glVertex2i(85+i,178);
    glEnd();
    glFlush();


	k+=0.05;
	timer(k,156.5,122,128);
	timer(k,102.5,102,108);



    glColor3f(0.2,0.0,0.7);
	glBegin(GL_QUADS);
	glVertex2i(310-i,168);glVertex2i(310-i,173);glVertex2i(320-i,173);glVertex2i(320-i,168);
    glEnd();
    glFlush();

	glColor3f(0.2,0.0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(70+i,178);glVertex2i(70+i,183);glVertex2i(85+i,183);glVertex2i(85+i,178);
    glEnd();
    glFlush();



 }



for(j=0;j<63;j=j+temp) //to move the  packet from bottom to top
{
	glColor3f(0,1,1);
		 glBegin(GL_QUADS);
	  glVertex2i(70,168+j);glVertex2i(70,178+j);glVertex2i(75,178+j);glVertex2i(75,168+j);
    glEnd();
    glFlush();

	glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(320,178+j);glVertex2i(320,193+j);glVertex2i(325,193+j);glVertex2i(325,178+j);
    glEnd();
    glFlush();

	k+=0.05;
	timer(k,156.5,122,128);
	timer(k,102.5,102,108);


	glColor3f(0.2,0.0,0.7);	//find here
		 glBegin(GL_QUADS);
	  glVertex2i(70,168+j);glVertex2i(70,178+j);glVertex2i(75,178+j);glVertex2i(75,168+j);
    glEnd();
      glFlush();

	  	glColor3f(0.2,0.0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(320,178+j);glVertex2i(320,193+j);glVertex2i(325,193+j);glVertex2i(325,178+j);
    glEnd();
      glFlush();


	}


	setFont(GLUT_BITMAP_HELVETICA_12);

	glColor3f(0.2f,0.0f,0.7f);
    drawstring(58.5,300.0,1.0,"FRAME 1 sending ...........");

    	glColor3f(0.2f,0.0f,0.7f);
 	drawstring(370.0,300.0,1.0,"........... sending ACK1 ");

	glColor3f(1.0,1.0,0.0);
    drawstring(58.5,300.0,1.0,"FRAME 1 sent ");

    glColor3f(1.0f,1.0f,0.0f);
 drawstring(370.0,300.0,1.0,"ACK1 Recieved ");

	glColor3f(0.2,0.0,0.7);
	glBegin(GL_POLYGON);
	glVertex2f(10,115);
	glVertex2f(10,135);
	glVertex2f(230,135);
	glVertex2f(230,115);
	glEnd();
	glFlush();

	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,0.8,0.4);
	drawstring(80.0,125.0,1.0," Frame 0 sent successfully");


 //  delay();

	setFont(GLUT_BITMAP_HELVETICA_12);

    glColor3f(0.2,0.0,0.7);
    drawstring(58.5,300.0,1.0,"FRAME 1 sent ");

    	glColor3f(0.2f,0.0f,0.7f);
 	drawstring(370.0,300.0,1.0,"ACK1 Recieved ");




}
void move3()  // MOVEMENT OF FRAME 2 ( FRAME 2 lost in packet crashing)
{

float i,j,temp=0.3;
float k=0;
timer2();

    glColor3f(1.0,0.8,0.4);
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(30.0,85.0,1.0,"Timer 2");

	setFont(GLUT_BITMAP_HELVETICA_12);

	glColor3f(1.0f,1.0f,0.0f);
    drawstring(58.5,300.0,1.0,"FRAME 2 sending ...........");



for(j=0;j<4;j=j+temp) //movement of data packet within the frame
	 {
		glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(85,265-j);glVertex2i(85,280-j);glVertex2i(90,280-j);glVertex2i(90,265-j);
    glEnd();
    glFlush();


	k+=0.05;
	timer(k,102.5,82,88);

	glColor3f(0.2,0.0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(85,265-j);glVertex2i(85,280-j);glVertex2i(90,280-j);glVertex2i(90,265-j);
    glEnd();
    glFlush();

	}

 for(j=0;j<60;j=j+temp) //movement of data packet from top to down
	 {   glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(85,238-j);glVertex2i(85,253-j);glVertex2i(90,253-j);glVertex2i(90,238-j);
    glEnd();
    glFlush();

	k+=0.05;
	timer(k,102.5,82,88);

	 glColor3f(0.2,0.0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(85,238-j);glVertex2i(85,253-j);glVertex2i(90,253-j);glVertex2i(90,238-j);
    glEnd();
    glFlush();
	 }

for(i=0;i<167;i=i+temp) //movement of data packet sidewise
	 {   glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(85+i,178);glVertex2i(85+i,183);glVertex2i(100+i,183);glVertex2i(100+i,178);
    glEnd();
    glFlush();

	k+=0.05;
	timer(k,102.5,82,88);


  glColor3f(0.2,0.0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(85+i,178);glVertex2i(85+i,183);glVertex2i(100+i,183);glVertex2i(100+i,178);
    glEnd();
    glFlush();



}

	setFont(GLUT_BITMAP_HELVETICA_12);

	glColor3f(0.2f,0.0f,0.7f);
    drawstring(58.5,300.0,1.0,"FRAME 2 sending ...........");


	glColor3f(1.0f,1.0f,0.0f);
 	drawstring(185.0,165.0,1.0,"FRAME 2 lost");


	//glColor3f(1.0f,1.0f,0.0f);
    //drawstring(160.0,265.0,1.0,"FRAME 2 lost");

//	delay();

	glColor3f(0.2f,0.0f,0.7f);
 	drawstring(185.0,265.0,1.0,"FRAME 2 lost");



}

void move4() // RESENDING OF FRAME 2 (in packet crashing)
{


	float i,j,temp=0.3;
	 timer2();
	 timer4();
	 timer3();
	 float k=0;
	 float p=0;

	setFont(GLUT_BITMAP_HELVETICA_12);

	glColor3f(1.0f,1.0f,1.0f);
    drawstring(58.5,300.0,1.0,"FRAME 2 Resending ...........");

     for(j=0;j<4;j=j+temp) //movement of data packet within the frame
	 {   glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(85,265-j);glVertex2i(85,280-j);glVertex2i(90,280-j);glVertex2i(90,265-j);
    glEnd();
    glFlush();

		k+=0.03;
	timer(k,102.5,82,88);

	 glColor3f(0.2,0.0,0.7);   // to remove traces create movement of frame in black
		 glBegin(GL_QUADS);
	  glVertex2i(85,265-j);glVertex2i(85,280-j);glVertex2i(90,280-j);glVertex2i(90,265-j);
    glEnd();
    glFlush();
	 }

	 for(j=0;j<60;j=j+temp) //movement of data packet from top to down
	 {   glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(85,238-j);glVertex2i(85,253-j);glVertex2i(90,253-j);glVertex2i(90,238-j);
    glEnd();
    glFlush();

	k+=0.03;
	timer(k,102.5,82,88);
	timer(k,396.5,102,108);
	p+=0.01;
	timer(p,430.5,122,128);


	glColor3f(0.2,0.0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(85,238-j);glVertex2i(85,253-j);glVertex2i(90,253-j);glVertex2i(90,238-j);
    glEnd();
    glFlush();
	 }

for(i=0;i<231;i=i+temp) //movement of data packet sidewise
	 {   glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(85+i,178);glVertex2i(85+i,183);glVertex2i(100+i,183);glVertex2i(100+i,178);
    glEnd();
    glFlush();

	k+=0.03;
	timer(k,102.5,82,88);
	timer(k,396.5,102,108);

	p+=0.01;

	timer(p,430.5,122,128);


   glColor3f(0.2,0.0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(85+i,178);glVertex2i(85+i,183);glVertex2i(100+i,183);glVertex2i(100+i,178);
    glEnd();
    glFlush();




}



for(j=0;j<60;j=j+temp) //to move the  packet from bottom to top
{
	glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(335,178+j);glVertex2i(335,193+j);glVertex2i(340,193+j);glVertex2i(340,178+j);
    glEnd();
    glFlush();

	k+=0.03;
	timer(k,102.5,82,88);
	timer(k,396.5,102,108);

	p+=0.01;

	timer(p,430.5,122,128);


     glColor3f(0.2,0.0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(335,178+j);glVertex2i(335,193+j);glVertex2i(340,193+j);glVertex2i(340,178+j);
    glEnd();
      glFlush();

	}

	setFont(GLUT_BITMAP_HELVETICA_12);

   	glColor3f(0.2f,0.0f,0.7f);
    drawstring(58.5,300.0,1.0,"FRAME 2 Resending ...........");


    glColor3f(1.0f,1.0f,1.0f);
    drawstring(58.5,300.0,1.0,"FRAME 2 sent");


//	delay();

	glColor3f(0.2f,0.0f,0.7f);
    drawstring(58.5,300.0,1.0,"FRAME 2 sent");

}


void move5()  // sending of frame 3
{


	float i,j,temp=0.3;
	timer2();
	timer3();

    float k=0,l=0;

    glColor3f(1.0,0.8,0.4);
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(320.0,125.0,1.0,"Timer 3");

	setFont(GLUT_BITMAP_HELVETICA_12);

    glColor3f(1.0f,1.0f,0.0f);
    drawstring(58.5,300.0,1.0,"FRAME 3 sending ...........");



     for(j=0;j<4;j=j+temp) //movement of data packet within the frame
	 {
	glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(100,265-j);glVertex2i(100,280-j);glVertex2i(105,280-j);glVertex2i(105,265-j);
    glEnd();
    glFlush();

	k+=0.03;
	timer(k,136.5,82,88);


	glColor3f(0.2,0.0,0.7);   // to remove traces create movement of frame in black
		 glBegin(GL_QUADS);
	  glVertex2i(100,265-j);glVertex2i(100,280-j);glVertex2i(105,280-j);glVertex2i(105,265-j);
    glEnd();
    glFlush();

	 }




	 for(j=0;j<50;j=j+temp) //movement of data packet from top to down
	 {
	glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(100,238-j);glVertex2i(100,253-j);glVertex2i(105,253-j);glVertex2i(105,238-j);
    glEnd();
    glFlush();

		k+=0.03;
	timer(k,136.5,82,88);
    timer(k,362.5,122,128);


	glColor3f(0.2,0.0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(100,238-j);glVertex2i(100,253-j);glVertex2i(105,253-j);glVertex2i(105,238-j);
    glEnd();
    glFlush();


	 }

for(i=0;i<235;i=i+temp) //movement of data packet sidewise
	 {

	glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(100+i,183);glVertex2i(100+i,188);glVertex2i(115+i,188);glVertex2i(115+i,183);
    glEnd();
    glFlush();

	k+=0.03;
	timer(k,136.5,82,88);
	timer(k,362.5,122,128);

		glColor3f(0.2,0.0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(100+i,183);glVertex2i(100+i,188);glVertex2i(115+i,188);glVertex2i(115+i,183);
    glEnd();
    glFlush();

 }



for(j=0;j<55;j=j+temp) //to move the  packet from bottom to top
{

	glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(350,183+j);glVertex2i(350,198+j);glVertex2i(355,198+j);glVertex2i(355,183+j);
    glEnd();
    glFlush();

	k+=0.03;
	timer(k,136.5,82,88);
	timer(k,362.5,122,128);


    glColor3f(0.2,0.0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(350,183+j);glVertex2i(350,198+j);glVertex2i(355,198+j);glVertex2i(355,183+j);
    glEnd();
    glFlush();

	}


	setFont(GLUT_BITMAP_HELVETICA_12);

    	glColor3f(0.2f,0.0f,0.7f);
    drawstring(58.5,300.0,1.0,"FRAME 3 sending ...........");

	glColor3f(0.2f,0.0f,0.7f);
 	drawstring(370.0,300.0,1.0,"........... sending NAK2 ");

	glColor3f(1.0,1.0,0.0);
    drawstring(58.5,300.0,1.0,"FRAME 3 sent ");


//	delay();


	glColor3f(0.2,0.0,0.7);
    drawstring(58.5,300.0,1.0,"FRAME 3 sent ");


}


void move6()  // RESENDING OF FRAME 1(in packet crashing)
{

float i,j,temp=0.3;

glBegin(GL_LINE_LOOP);
	 glColor3f(0.2,0,0.7);
	glVertex2f(100,120);
	glVertex2f(225,120);
	glVertex2f(225,130);
	glVertex2f(100,130);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);
	 glColor3f(0.2,0,0.7);
	glVertex2f(100,120);
	glVertex2f(225,120);
	glVertex2f(225,130);
	glVertex2f(100,130);
	glEnd();
	glFlush();

for(j=0;j<4;j=j+temp) //movement of data packet within the frame
	 {   glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(70,265-j);glVertex2i(70,280-j);glVertex2i(75,280-j);glVertex2i(75,265-j);
    glEnd();
    glFlush();

	 glColor3f(0.2,0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(70,265-j);glVertex2i(70,280-j);glVertex2i(75,280-j);glVertex2i(75,265-j);
    glEnd();
    glFlush();

	}

 for(j=0;j<60;j=j+temp) //movement of data packet from top to down
	 {   glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(70,238-j);glVertex2i(70,253-j);glVertex2i(75,253-j);glVertex2i(75,238-j);
    glEnd();
    glFlush();

	setFont(GLUT_BITMAP_HELVETICA_12);

	glColor3f(1.0f,1.0f,0.0f);
    drawstring(58.5,300.0,1.0,"FRAME 1 sending .....");


		  glColor3f(0.2,0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(70,238-j);glVertex2i(70,253-j);glVertex2i(75,253-j);glVertex2i(75,238-j);
    glEnd();
    glFlush();
	 }

for(i=0;i<231;i=i+temp) //movement of data packet sidewise
	 {   glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(70+i,178);glVertex2i(70+i,183);glVertex2i(85+i,183);glVertex2i(85+i,178);
    glEnd();
    glFlush();



	glColor3f(1.0f,1.0f,0.0f);
 	drawstring(58.5,300.0,1.0,"FRAME 1 resending ...................");


  glColor3f(0.2,0.0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(70+i,178);glVertex2i(70+i,183);glVertex2i(85+i,183);glVertex2i(85+i,178);
    glEnd();
    glFlush();
 }


for(j=0;j<60;j=j+temp) //to move the  packet from bottom to top
{
	glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(320,178+j);glVertex2i(320,193+j);glVertex2i(325,193+j);glVertex2i(325,178+j);
    glEnd();
    glFlush();


	setFont(GLUT_BITMAP_HELVETICA_12);

	glColor3f(1.0f,1.0f,0.0f);
 	drawstring(58.5,300.0,1.0,"FRAME 0 sending ...............................");


	glColor3f(0.2,0.0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(320,178+j);glVertex2i(320,193+j);glVertex2i(325,193+j);glVertex2i(325,178+j);
    glEnd();
      glFlush();

	}

	glColor3f(1.0,1.0,1.0);
	drawstring(70,268.0,0.0,"1");
	glColor3f(1.0,1.0,1.0);
	drawstring(85,268.0,0.0,"2");
	glColor3f(1.0,1.0,1.0);
	drawstring(100,268.0,0.0,"3");
	glColor3f(1.0,1.0,1.0);
	drawstring(320,268.0,0.0,"1");
	glColor3f(1.0,1.0,1.0);
	drawstring(365,268.0,0.0,"4");




}


void move7()  // MOVEMENT OF ACK 4 (in packet crashing)
{


	float i,j,temp=0.3;


     for(j=0;j<4;j=j+temp) //movement of data packet within the frame
	 {   glColor3f(0,1,1);
		 glBegin(GL_QUADS);
	  glVertex2i(365,265-j);glVertex2i(365,275-j);glVertex2i(370,275-j);glVertex2i(370,265-j);
    glEnd();
    glFlush();


	 	  glColor3f(0.2,0,0.7);   // to remove traces create movement of frame in black
		 glBegin(GL_QUADS);
	  glVertex2i(365,265-j);glVertex2i(365,275-j);glVertex2i(370,275-j);glVertex2i(370,265-j);
    glEnd();
    glFlush();

	 }


	 for(j=0;j<50;j=j+temp) //movement of data packet from top to down
	 {   glColor3f(0,1,1);
		 glBegin(GL_QUADS);
	  glVertex2i(365,228-j);glVertex2i(365,238-j);glVertex2i(370,238-j);glVertex2i(370,228-j);
    glEnd();
    glFlush();


	 	 glColor3f(0.2,0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(365,228-j);glVertex2i(365,238-j);glVertex2i(370,238-j);glVertex2i(370,228-j);
    glEnd();
    glFlush();

	 }

for(i=0;i<235;i=i+temp) //movement of data packet sidewise
	 {
		glColor3f(0,1,1);
		 glBegin(GL_QUADS);
	  glVertex2i(355-i,178);glVertex2i(355-i,183);glVertex2i(365-i,183);glVertex2i(365-i,178);
    glEnd();
    glFlush();



	setFont(GLUT_BITMAP_HELVETICA_12);

	glColor3f(1.0f,1.0f,0.0f);
 	drawstring(58.5,300.0,1.0,"FRAME 1 resending ...................");




   glColor3f(0.2,0.0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(355-i,178);glVertex2i(355-i,183);glVertex2i(365-i,183);glVertex2i(365-i,178);
    glEnd();
    glFlush();


 }



for(j=0;j<55;j=j+temp) //to move the  packet from bottom to top
{
	glColor3f(0,1,1);
		 glBegin(GL_QUADS);
	  glVertex2i(115,178+j);glVertex2i(115,188+j);glVertex2i(120,188+j);glVertex2i(120,178+j);
    glEnd();
    glFlush();


	glColor3f(1.0f,1.0f,0.0f);
 	drawstring(58.5,300.0,1.0,"FRAME 0 sending ...............................");




	glColor3f(0.2,0.0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(115,178+j);glVertex2i(115,188+j);glVertex2i(120,188+j);glVertex2i(120,178+j);
    glEnd();
      glFlush();


	}
	glColor3f(1.0,1.0,1.0);
	drawstring(365,268.0,0.0,"4");


}

void move8()  // MOVEMENT OF ACK 4 (in packet crashing)
{


	float i,j,temp=0.3;
	float k=0;
	timer1();

	setFont(GLUT_BITMAP_HELVETICA_12);

    glColor3f(1.0f,1.0f,0.0f);
 	drawstring(370.0,300.0,1.0,"........... sending ACK2 ");


     for(j=0;j<4;j=j+temp) //movement of data packet within the frame
	 {   glColor3f(0,1,1);
		 glBegin(GL_QUADS);
	  glVertex2i(335,265-j);glVertex2i(335,275-j);glVertex2i(340,275-j);glVertex2i(340,265-j);
    glEnd();
    glFlush();


	 	 glColor3f(0.2,0.0,0.7);   // to remove traces create movement of frame in black
		 glBegin(GL_QUADS);
	  glVertex2i(335,265-j);glVertex2i(335,275-j);glVertex2i(340,275-j);glVertex2i(340,265-j);
    glEnd();
    glFlush();

	 }


	 for(j=0;j<50;j=j+temp) //movement of data packet from top to down
	 {   glColor3f(0,1,1);
		 glBegin(GL_QUADS);
	  glVertex2i(335,228-j);glVertex2i(335,238-j);glVertex2i(340,238-j);glVertex2i(340,228-j);
    glEnd();
    glFlush();

	k+=0.05;
	timer(k,136.5,102,108);

	 	glColor3f(0.2,0.0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(335,228-j);glVertex2i(335,238-j);glVertex2i(340,238-j);glVertex2i(340,228-j);
    glEnd();
    glFlush();

	 }

for(i=0;i<235;i=i+temp) //movement of data packet sidewise
	 {
		glColor3f(0,1,1);
		 glBegin(GL_QUADS);
	  glVertex2i(325-i,178);glVertex2i(325-i,183);glVertex2i(335-i,183);glVertex2i(335-i,178);
    glEnd();
    glFlush();

	k+=0.05;
	timer(k,136.5,102,108);


   glColor3f(0.2,0.0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(325-i,178);glVertex2i(325-i,183);glVertex2i(335-i,183);glVertex2i(335-i,178);
    glEnd();
    glFlush();


 }



for(j=0;j<55;j=j+temp) //to move the  packet from bottom to top
{
	glColor3f(0,1,1);
		 glBegin(GL_QUADS);
	  glVertex2i(85,178+j);glVertex2i(85,188+j);glVertex2i(90,188+j);glVertex2i(90,178+j);
    glEnd();
    glFlush();

	k+=0.05;
	timer(k,136.5,102,108);



	glColor3f(0.2,0.0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(85,178+j);glVertex2i(85,188+j);glVertex2i(90,188+j);glVertex2i(90,178+j);
    glEnd();
      glFlush();
}


	glColor3f(0.2f,0.0f,0.7f);
 drawstring(370.0,300.0,1.0,"........... sending ACK2 ");

	glColor3f(0.2,0.0,0.7);
	glBegin(GL_POLYGON);
	glVertex2f(10,95);
	glVertex2f(10,115);
	glVertex2f(230,115);
	glVertex2f(230,95);
	glEnd();
	glFlush();

	setFont(GLUT_BITMAP_HELVETICA_18);

    glColor3f(1.0,0.8,0.4);
	drawstring(80.0,105.0,1.0," Frame 1 sent successfully");

//	delay();

}
void move9()   // MOVEMENT OF ACK 1 (in safe sending)
{


	float i,j,temp=0.5;

	setFont(GLUT_BITMAP_HELVETICA_12);

	 	glColor3f(0.2f,0.0f,0.7f);
 	drawstring(58.5,300.0,1.0,"      FRAME 0 sent");


    glColor3f(0.0f,1.0f,0.0f);
 	drawstring(370.0,300.0,1.0," .... sending ACK1 ");




     for(j=0;j<4;j=j+temp) //movement of data packet within the frame
	 {   glColor3f(0,1,1);
		 glBegin(GL_QUADS);
	  glVertex2i(320,265-j);glVertex2i(320,275-j);glVertex2i(325,275-j);glVertex2i(325,265-j);
    glEnd();
    glFlush();


	 glColor3f(0.2,0.0,0.7);   // to remove traces create movement of frame in black
		 glBegin(GL_QUADS);
	  glVertex2i(320,265-j);glVertex2i(320,275-j);glVertex2i(325,275-j);glVertex2i(325,265-j);
    glEnd();
    glFlush();
	 }


	 for(j=0;j<60;j=j+temp) //movement of data packet from top to down
	 {   glColor3f(0,1,1);
		 glBegin(GL_QUADS);
	  glVertex2i(320,228-j);glVertex2i(320,238-j);glVertex2i(325,238-j);glVertex2i(325,228-j);
    glEnd();
    glFlush();

	setFont(GLUT_BITMAP_HELVETICA_12);

	 	glColor3f(0.2f,0.0f,0.7f);
 	drawstring(370.0,300.0,1.0," .... sending ACK1 ");

	 glColor3f(0.0f,1.0f,0.0f);
 	drawstring(370.0,300.0,1.0,".............. sending ACK1 ");

	glColor3f(0.2,0.0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(320,228-j);glVertex2i(320,238-j);glVertex2i(325,238-j);glVertex2i(325,228-j);
    glEnd();
    glFlush();

	 }

for(i=0;i<235;i=i+temp) //movement of data packet sidewise
	 {   glColor3f(0,1,1);
		 glBegin(GL_QUADS);
	  glVertex2i(310-i,168);glVertex2i(310-i,173);glVertex2i(320-i,173);glVertex2i(320-i,168);
    glEnd();
    glFlush();

		setFont(GLUT_BITMAP_HELVETICA_12);

		 	glColor3f(0.2f,0.0f,0.7f);
 	drawstring(370.0,300.0,1.0,".............. sending ACK1 ");



	  glColor3f(0.0f,1.0f,0.0f);
 	drawstring(370.0,300.0,1.0,"........................... sending ACK1 ");



   glColor3f(0.2,0.0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(310-i,168);glVertex2i(310-i,173);glVertex2i(320-i,173);glVertex2i(320-i,168);
    glEnd();
    glFlush();

 }


for(j=0;j<63;j=j+temp) //to move the  packet from bottom to top
{
	glColor3f(0,1,1);
		 glBegin(GL_QUADS);
	  glVertex2i(70,168+j);glVertex2i(70,178+j);glVertex2i(75,178+j);glVertex2i(75,168+j);
    glEnd();
    glFlush();



	setFont(GLUT_BITMAP_HELVETICA_12);

		 	glColor3f(0.2f,0.0f,0.7f);
 	drawstring(370.0,300.0,1.0,"........................... sending ACK1 ");



	  glColor3f(0.0f,1.0f,0.0f);
 	drawstring(58.5,300.0,1.0,"..................................... sending ACK1 ");



	glColor3f(0.2,0.0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(70,168+j);glVertex2i(70,178+j);glVertex2i(75,178+j);glVertex2i(75,168+j);
    glEnd();
      glFlush();


	}




	setFont(GLUT_BITMAP_HELVETICA_12);

	  	glColor3f(0.2f,0.0f,0.7f);
 	drawstring(58.5,300.0,1.0,"..................................... sending ACK1 ");


     glColor3f(0.0f,1.0f,0.0f);
 	drawstring(58.5,300.0,1.0,"   ACK1 received");



	setFont(GLUT_BITMAP_HELVETICA_12);
	glColor3f(1.0,1.0,1.0);
	drawstring(55,268.0,0.0,"0");

	glColor3f(1.0,1.0,1.0);
	drawstring(320,268.0,0.0,"1");

//	delay();

     	glColor3f(0.2f,0.0f,0.7f);
 	drawstring(58.5,300.0,1.0,"   ACK1 received");


}


void move10()  // SIMULTANEOUS MOVEMENT  OF NAK 2 AS FRAME 2 IS LOST AND  FRAME 4  (in packet crashing)
{


	float i,j,temp=0.3;

	timer2();
	timer3();
	timer4();
	float k=0;


    glColor3f(1.0,0.8,0.4);
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(320.0,105.0,1.0,"Timer 4");

	setFont(GLUT_BITMAP_HELVETICA_12);

    glColor3f(1.0f,1.0f,0.0f);
    drawstring(58.5,300.0,1.0,"FRAME 4 sending ...........");

	glColor3f(1.0f,1.0f,0.0f);
 	drawstring(370.0,300.0,1.0,"........... sending NAK2 ");


     for(j=0;j<4;j=j+temp) //movement of data packet within the frame
	 {   glColor3f(1,1,0);
		 glBegin(GL_QUADS);
	  glVertex2i(335,265-j);glVertex2i(335,275-j);glVertex2i(340,275-j);glVertex2i(340,265-j);
    glEnd();
    glFlush();

	glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(115,265-j);glVertex2i(115,280-j);glVertex2i(120,280-j);glVertex2i(120,265-j);
    glEnd();
    glFlush();

	 	 glColor3f(0.2,0.0,0.7);   // to remove traces create movement of frame in black
		 glBegin(GL_QUADS);
	  glVertex2i(335,265-j);glVertex2i(335,275-j);glVertex2i(340,275-j);glVertex2i(340,265-j);
    glEnd();
    glFlush();


	glColor3f(0.2,0.0,0.7);   // to remove traces create movement of frame in black
		 glBegin(GL_QUADS);
	  glVertex2i(115,265-j);glVertex2i(115,280-j);glVertex2i(120,280-j);glVertex2i(120,265-j);
    glEnd();
    glFlush();

	 }




	 for(j=0;j<50;j=j+temp) //movement of data packet from top to down
	 {   glColor3f(1,1,0);
		 glBegin(GL_QUADS);
	  glVertex2i(335,228-j);glVertex2i(335,238-j);glVertex2i(340,238-j);glVertex2i(340,228-j);
    glEnd();
    glFlush();

	k+=0.03;
	timer(k,170.5,82,88);
	timer(k,396.5,122,128);
	timer(k,362.5,102,108);


	glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(115,238-j);glVertex2i(115,253-j);glVertex2i(120,253-j);glVertex2i(120,238-j);
    glEnd();
    glFlush();


	 glColor3f(0.2,0.0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(335,228-j);glVertex2i(335,238-j);glVertex2i(340,238-j);glVertex2i(340,228-j);
    glEnd();
    glFlush();

	glColor3f(0.2,0.0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(115,238-j);glVertex2i(115,253-j);glVertex2i(120,253-j);glVertex2i(120,238-j);
    glEnd();
    glFlush();


	 }

for(i=0;i<235;i=i+temp) //movement of data packet sidewise
	 {   glColor3f(1,1,0);
		 glBegin(GL_QUADS);
	  glVertex2i(325-i,178);glVertex2i(325-i,183);glVertex2i(335-i,183);glVertex2i(335-i,178);
    glEnd();
    glFlush();

k+=0.03;
	timer(k,170.5,82,88);
	timer(k,396.5,122,128);
	timer(k,362.5,102,108);

	glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(115+i,183);glVertex2i(115+i,188);glVertex2i(130+i,188);glVertex2i(130+i,183);
    glEnd();
    glFlush();


   glColor3f(0.2,0.0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(325-i,178);glVertex2i(325-i,183);glVertex2i(335-i,183);glVertex2i(335-i,178);
    glEnd();
    glFlush();


		glColor3f(0.2,0.0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(115+i,183);glVertex2i(115+i,188);glVertex2i(130+i,188);glVertex2i(130+i,183);
    glEnd();
    glFlush();

 }



for(j=0;j<55;j=j+temp) //to move the  packet from bottom to top
{
	glColor3f(1,1,0);
		 glBegin(GL_QUADS);
	  glVertex2i(85,178+j);glVertex2i(85,188+j);glVertex2i(90,188+j);glVertex2i(90,178+j);
    glEnd();
    glFlush();

	glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(365,183+j);glVertex2i(365,198+j);glVertex2i(370,198+j);glVertex2i(370,183+j);
    glEnd();
    glFlush();

	k+=0.03;
	timer(k,170.5,82,88);
    timer(k,396.5,122,128);
	timer(k,362.5,102,108);


	glColor3f(0.2,0.0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(85,178+j);glVertex2i(85,188+j);glVertex2i(90,188+j);glVertex2i(90,178+j);
    glEnd();
      glFlush();

	  glColor3f(0.2,0.0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(365,183+j);glVertex2i(365,198+j);glVertex2i(370,198+j);glVertex2i(370,183+j);
    glEnd();
    glFlush();

	}

	setFont(GLUT_BITMAP_HELVETICA_12);

  glColor3f(0.2,0.0,0.7);
    drawstring(58.5,300.0,1.0,"FRAME 4 sending ...........");

	glColor3f(0.2f,0.0f,0.7f);
 	drawstring(370.0,300.0,1.0,"........... sending NAK2 ");


	glColor3f(1.0,1.0,0.0);
    drawstring(58.5,300.0,1.0,"FRAME 4 sent ");

    glColor3f(1.0f,1.0f,0.0f);
 	drawstring(370.0,300.0,1.0,"NAK2 Recieved ");

//	delay();


	glColor3f(0.2,0.0,0.7);
    drawstring(58.5,300.0,1.0,"FRAME 4 sent ");

  	glColor3f(0.2,0.0,0.7);
 	drawstring(370.0,300.0,1.0,"NAK2 Recieved ");




}

void move11()  // MOVEMENT OF ACK 4 (in packet crashing)
{


	float i,j,temp=0.3;
	timer2();
	timer3();
	timer4();
	float k=0;
	float p=0;

	setFont(GLUT_BITMAP_HELVETICA_12);

	glColor3f(1.0f,1.0f,0.0f);
 	drawstring(370.0,300.0,1.0,"........... sending ACK4 ");



     for(j=0;j<4;j=j+temp) //movement of data packet within the frame
	 {   glColor3f(0,1,1);
		 glBegin(GL_QUADS);
	  glVertex2i(380,265-j);glVertex2i(380,275-j);glVertex2i(385,275-j);glVertex2i(385,265-j);
    glEnd();
    glFlush();

	k+=0.03;
	timer(k,136.5,82,88);

	 	  glColor3f(0.2,0,0.7);   // to remove traces create movement of frame in black
		 glBegin(GL_QUADS);
	  glVertex2i(380,265-j);glVertex2i(380,275-j);glVertex2i(385,275-j);glVertex2i(385,265-j);
    glEnd();
    glFlush();

	 }


	 for(j=0;j<50;j=j+temp) //movement of data packet from top to down
	 {   glColor3f(0,1,1);
		 glBegin(GL_QUADS);
	  glVertex2i(380,228-j);glVertex2i(380,238-j);glVertex2i(385,238-j);glVertex2i(385,228-j);
    glEnd();
    glFlush();

	k+=0.03;
	timer(k,136.5,82,88);
	timer(k,431.5,102,108);
	p+=0.01;
	timer(p,442,122,128);


	 	 glColor3f(0.2,0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(380,228-j);glVertex2i(380,238-j);glVertex2i(385,238-j);glVertex2i(385,228-j);
    glEnd();
    glFlush();

	 }

for(i=0;i<235;i=i+temp) //movement of data packet sidewise
	 {
		glColor3f(0,1,1);
		 glBegin(GL_QUADS);
	  glVertex2i(370-i,178);glVertex2i(370-i,183);glVertex2i(380-i,183);glVertex2i(380-i,178);
    glEnd();
    glFlush();

	k+=0.03;
	timer(k,136.5,82,88);
	timer(k,431.5,102,108);

	p+=0.01;
	timer(p,442,122,128);


    glColor3f(0.2,0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(370-i,178);glVertex2i(370-i,183);glVertex2i(380-i,183);glVertex2i(380-i,178);
    glEnd();
    glFlush();


 }



for(j=0;j<55;j=j+temp) //to move the  packet from bottom to top
{
	glColor3f(0,1,1);
		 glBegin(GL_QUADS);
	  glVertex2i(130,178+j);glVertex2i(130,188+j);glVertex2i(135,188+j);glVertex2i(135,178+j);
    glEnd();
    glFlush();

	k+=0.03;
	timer(k,136.5,82,88);
	timer(k,431.5,102,108);

	p+=0.01;
	timer(p,442,122,128);



	 glColor3f(0.2,0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(130,178+j);glVertex2i(130,188+j);glVertex2i(135,188+j);glVertex2i(135,178+j);
    glEnd();
      glFlush();


	}
	glColor3f(1.0,1.0,1.0);
	drawstring(365,268.0,0.0,"4");



	glColor3f(0.2f,0.0f,0.7f);
 	drawstring(370.0,300.0,1.0,"........... sending ACK4 ");



    glColor3f(1.0f,1.0f,0.0f);
 	drawstring(370.0,300.0,1.0,"NAK4 Recieved ");

//	delay();


	    glColor3f(0.2f,0.0f,0.7f);
 	drawstring(370.0,300.0,1.0,"NAK4 Recieved ");




}

void move12()
{


	float i,j,temp=0.3;
	float k=0;
	timer1();

	setFont(GLUT_BITMAP_HELVETICA_12);

	glColor3f(1.0f,1.0f,0.0f);
 	drawstring(370.0,300.0,1.0,"........... sending ACK2 ");


     for(j=0;j<4;j=j+temp) //movement of data packet within the frame
	 {   glColor3f(0,1,1);
		 glBegin(GL_QUADS);
	  glVertex2i(335,265-j);glVertex2i(335,275-j);glVertex2i(340,275-j);glVertex2i(340,265-j);
    glEnd();
    glFlush();


	 	  glColor3f(0.2,0,0.7);   // to remove traces create movement of frame in black
		 glBegin(GL_QUADS);
	  glVertex2i(335,265-j);glVertex2i(335,275-j);glVertex2i(340,275-j);glVertex2i(340,265-j);
    glEnd();
    glFlush();

	 }


	 for(j=0;j<50;j=j+temp) //movement of data packet from top to down
	 {   glColor3f(0,1,1);
		 glBegin(GL_QUADS);
	  glVertex2i(335,228-j);glVertex2i(335,238-j);glVertex2i(340,238-j);glVertex2i(340,228-j);
    glEnd();
    glFlush();

	k+=0.03;
	timer(k,136.5,102,108);

	 	 glColor3f(0.2,0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(335,228-j);glVertex2i(335,238-j);glVertex2i(340,238-j);glVertex2i(340,228-j);
    glEnd();
    glFlush();

	 }

for(i=0;i<65;i=i+temp) //movement of data packet sidewise
	 {
		glColor3f(0,1,1);
		 glBegin(GL_QUADS);
	  glVertex2i(325-i,178);glVertex2i(325-i,183);glVertex2i(335-i,183);glVertex2i(335-i,178);
    glEnd();
    glFlush();

	k+=0.03;
	timer(k,136.5,102,108);



    glColor3f(0.2,0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(325-i,178);glVertex2i(325-i,183);glVertex2i(335-i,183);glVertex2i(335-i,178);
    glEnd();
    glFlush();


 }

	    glColor3f(0.2f,0.0f,0.7f);
 	drawstring(370.0,300.0,1.0,"........... sending ACK2 ");

}

void move13()   // SIMULTANEOUS  MOVEMENT OF ACK 1 AND FRAME 1(in safe sending)
{


	float i,j,temp=0.5;
	float k=0;
	timer1();
	timer2();

	setFont(GLUT_BITMAP_HELVETICA_18);

		glColor3f(1.0,0.8,0.4);
	drawstring(30.0,105.0,1.0," Timer 1");

	setFont(GLUT_BITMAP_HELVETICA_12);

    glColor3f(1.0f,1.0f,0.0f);
    drawstring(58.5,300.0,1.0,"FRAME 1 Resending ...........");

    glColor3f(1.0f,1.0f,0.0f);
 	drawstring(370.0,300.0,1.0,"........... sending ACK3 ");



     for(j=0;j<4;j=j+temp) //movement of data packet within the frame
	 {   glColor3f(0,1,1);
		 glBegin(GL_QUADS);
	  glVertex2i(350,265-j);glVertex2i(350,275-j);glVertex2i(355,275-j);glVertex2i(355,265-j);
    glEnd();
    glFlush();

	glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(70,265-j);glVertex2i(70,280-j);glVertex2i(75,280-j);glVertex2i(75,265-j);
    glEnd();
    glFlush();

	 glColor3f(0.2,0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(70,265-j);glVertex2i(70,280-j);glVertex2i(75,280-j);glVertex2i(75,265-j);
    glEnd();
    glFlush();


	  glColor3f(0.2,0,0.7);  // to remove traces create movement of frame in black
		 glBegin(GL_QUADS);
	  glVertex2i(350,265-j);glVertex2i(350,275-j);glVertex2i(355,275-j);glVertex2i(355,265-j);
    glEnd();
    glFlush();
	 }


	 for(j=0;j<60;j=j+temp) //movement of data packet from top to down
	 {   glColor3f(0,1,1);
		 glBegin(GL_QUADS);
	  glVertex2i(350,228-j);glVertex2i(350,238-j);glVertex2i(355,238-j);glVertex2i(355,228-j);
    glEnd();
    glFlush();

	 glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(70,238-j);glVertex2i(70,253-j);glVertex2i(75,253-j);glVertex2i(75,238-j);
    glEnd();
    glFlush();

	k+=0.03;
	timer(k,102.5,102,108);
	timer(k,148.5,82,88);



		 glColor3f(0.2,0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(350,228-j);glVertex2i(350,238-j);glVertex2i(355,238-j);glVertex2i(355,228-j);
    glEnd();
    glFlush();

	 glColor3f(0.2,0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(70,238-j);glVertex2i(70,253-j);glVertex2i(75,253-j);glVertex2i(75,238-j);
    glEnd();
    glFlush();

	 }

for(i=0;i<235;i=i+temp) //movement of data packet sidewise
	 {   glColor3f(0,1,1);
		 glBegin(GL_QUADS);
	  glVertex2i(340-i,168);glVertex2i(340-i,173);glVertex2i(350-i,173);glVertex2i(350-i,168);
    glEnd();
    glFlush();

	k+=0.03;
	timer(k,102.5,102,108);
	timer(k,148.5,82,88);



	glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(70+i,178);glVertex2i(70+i,183);glVertex2i(85+i,183);glVertex2i(85+i,178);
    glEnd();
    glFlush();


    glColor3f(0.2,0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(340-i,168);glVertex2i(340-i,173);glVertex2i(350-i,173);glVertex2i(350-i,168);
    glEnd();
    glFlush();

 	glColor3f(0.2,0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(70+i,178);glVertex2i(70+i,183);glVertex2i(85+i,183);glVertex2i(85+i,178);
    glEnd();
    glFlush();

 }



for(j=0;j<63;j=j+temp) //to move the  packet from bottom to top
{
	glColor3f(0,1,1);
		 glBegin(GL_QUADS);
	  glVertex2i(100,168+j);glVertex2i(100,178+j);glVertex2i(105,178+j);glVertex2i(105,168+j);
    glEnd();
    glFlush();

	glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(320,178+j);glVertex2i(320,193+j);glVertex2i(325,193+j);glVertex2i(325,178+j);
    glEnd();
    glFlush();

	k+=0.03;
	timer(k,102.5,102,108);
	timer(k,148.5,82,88);


	 glColor3f(0.2,0,0.7);	
		 glBegin(GL_QUADS);
	  glVertex2i(100,168+j);glVertex2i(100,178+j);glVertex2i(105,178+j);glVertex2i(105,168+j);
    glEnd();
      glFlush();
 	
	 glColor3f(0.2,0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(320,178+j);glVertex2i(320,193+j);glVertex2i(325,193+j);glVertex2i(325,178+j);
    glEnd();
      glFlush();


	}


	setFont(GLUT_BITMAP_HELVETICA_12);

	 	glColor3f(0.2f,0.0f,0.7f);
    drawstring(58.5,300.0,1.0,"FRAME 1 Resending ...........");
	    glColor3f(0.2f,0.0f,0.7f);
 	drawstring(370.0,300.0,1.0,"........... sending ACK3 ");


glColor3f(1.2,0.6,1.6);
drawstring(315.0,248.0,1.0,"DUPLICATE " );//Frame 1");

glColor3f(1.2,0.6,1.6);
drawstring(310.0,238.0,1.0,"FRAME 1 Discarded ");
glFlush();



}

void move14() // RESENDING OF FRAME 2 (in packet crashing)
{


	float i,j,temp=0.3;
	 timer2();
	 float k=0;
	 float q=0;

	glColor3f(1.0,0.8,0.4);
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(30.0,85.0,1.0,"Timer 2");

	setFont(GLUT_BITMAP_HELVETICA_12);

	glColor3f(1.0f,1.0f,1.0f);
    drawstring(58.5,300.0,1.0,"FRAME 2 Sending ...........");


     for(j=0;j<4;j=j+temp) //movement of data packet within the frame
	 {   glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(85,265-j);glVertex2i(85,280-j);glVertex2i(90,280-j);glVertex2i(90,265-j);
    glEnd();
    glFlush();

		k+=0.07;
	timer(k,145.5,102,108);
	q+=0.04;
	timer(q,102.5,82,88);



 glColor3f(0.2,0,0.7);  // to remove traces create movement of frame in black
		 glBegin(GL_QUADS);
	  glVertex2i(85,265-j);glVertex2i(85,280-j);glVertex2i(90,280-j);glVertex2i(90,265-j);
    glEnd();
    glFlush();
	 }

	 for(j=0;j<60;j=j+temp) //movement of data packet from top to down
	 {   glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(85,238-j);glVertex2i(85,253-j);glVertex2i(90,253-j);glVertex2i(90,238-j);
    glEnd();
    glFlush();

	k+=0.07;
	timer(k,145.5,102,108);
	q+=0.04;
	timer(q,102.5,82,88);


 glColor3f(0.2,0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(85,238-j);glVertex2i(85,253-j);glVertex2i(90,253-j);glVertex2i(90,238-j);
    glEnd();
    glFlush();
	 }

for(i=0;i<231;i=i+temp) //movement of data packet sidewise
	 {   glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(85+i,178);glVertex2i(85+i,183);glVertex2i(100+i,183);glVertex2i(100+i,178);
    glEnd();
    glFlush();

	k+=0.07;
	timer(k,145.5,102,108);
	q+=0.04;
	timer(q,102.5,82,88);

	setFont(GLUT_BITMAP_HELVETICA_12);

	glColor3f(1.0f,1.0f,1.0f);
	drawstring(58.5,300.0,1.0,"FRAME 2 Sending ...........");

 //	drawstring(160.0,370.0,1.0,"FRAME 2 sending...................");



 glColor3f(0.2,0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(85+i,178);glVertex2i(85+i,183);glVertex2i(100+i,183);glVertex2i(100+i,178);
    glEnd();
    glFlush();
 }



for(j=0;j<60;j=j+temp) //to move the  packet from bottom to top
{
	glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  glVertex2i(335,178+j);glVertex2i(335,193+j);glVertex2i(340,193+j);glVertex2i(340,178+j);
    glEnd();
    glFlush();

	k+=0.05;
	timer(k,145.5,102,108);
	q+=0.04;
	timer(q,102.5,82,88);

   setFont(GLUT_BITMAP_HELVETICA_12);

	/////glColor3f(1.0f,1.0f,0.0f);
 	/////drawstring(160.0,365.0,1.0,"FRAME 0 sending ...............................");


 glColor3f(0.2,0,0.7);
		 glBegin(GL_QUADS);
	  glVertex2i(335,178+j);glVertex2i(335,193+j);glVertex2i(340,193+j);glVertex2i(340,178+j);
    glEnd();
      glFlush();

	}

    	glColor3f(0.2f,0.0f,0.7f);
    drawstring(58.5,300.0,1.0,"FRAME 2 Sending ...........");

//	delay();

 glColor3f(0.2,0,0.7);
	glBegin(GL_POLYGON);
	glVertex2f(0,98);
	glVertex2f(0,115);
	glVertex2f(228,115);
	glVertex2f(228,98);
	glEnd();
	glFlush();

	//delay();


	setFont(GLUT_BITMAP_HELVETICA_18);

    glColor3f(1.0,0.8,0.4);
	drawstring(80.0,105.0,1.0," TIME OUT !!");
	glFlush();

	delay();
	delay();

	setFont(GLUT_BITMAP_HELVETICA_18);

    glColor3f(0.2,0,0.7);
	drawstring(80.0,105.0,1.0," TIME OUT !!");
	glFlush();



	glColor3f(1.0,0.8,0.4);
	drawstring(228.0,105.0,1.0," TIMER 1 restarted");
	glFlush();



}




void slide(GLint maxx,GLint maxy,GLfloat x0,GLfloat y0) // TO DRAW WINDOWS (Rectangular Mesh)
{
	for(i=0;i<maxx;i++)
		x[i]=x0+i*dx;

	for(j=0;j<maxy;j++)
		y[j]=y0+j*dy;

	for(i=0;i<maxx-1;i++)
		for(j=0;j<maxy-1;j++)
		{

	       glBegin(GL_LINE_LOOP);
		   glVertex2f(x[i],y[j]);
		   glVertex2f(x[i],y[j+1]);
		   glVertex2f(x[i+1],y[j+1]);
		   glVertex2f(x[i+1],y[j]);
		   glEnd();
		   glFlush();


		}

}

void computer(int a)									// to draw the sender and receiver computers
{


	glColor3f(0.0,0.0,1.0);//monitor
	glBegin(GL_LINE_LOOP);
	glVertex2f(a+25,400);	
	glVertex2f(a+25,450);
	glVertex2f(a+90,450);
	glVertex2f(a+90,400);
	glEnd();
	glFlush();
	


	glColor3f(1.0,0.0,0.0);// INNER monitor
	glBegin(GL_LINE_LOOP);
	glVertex2f(a+27,402);
	glVertex2f(a+27,448);
	glVertex2f(a+88,448);
	glVertex2f(a+88,402);
	glEnd();
	glFlush();

	glColor3f(0.7,0.0,0.2);//vertical stand
	glBegin(GL_LINES);
	glVertex2f(a+45,400);
	glVertex2f(a+45,395);
	glVertex2f(a+69,400);
	glVertex2f(a+69,395);
	glEnd();
	glFlush();

	glColor3f(0.0,0.392,0.0); //horizontal stand
	glBegin(GL_QUADS);
	glVertex2f(a+38,395);
	glVertex2f(a+77,395);
	glVertex2f(a+77,390);
	glVertex2f(a+38,390);


	glEnd();
	glFlush();


	//glColor3f(5.2,0.6,0.2); //CPU
	glBegin(GL_POLYGON);
	glVertex2f(a+20,390);
	glColor3f(0.0,0.0,1.0);
	glVertex2f(a+95,390);
	glVertex2f(a+95,370);
	glVertex2f(a+20,370);
	glEnd();
	glFlush();


	glColor3f(0.7,0.8,0.2);  //CPU CD DRIVE
	glBegin(GL_QUADS);
	glVertex2f(a+35,385);
	glVertex2f(a+55,385);
	glVertex2f(a+55,380);
	glVertex2f(a+35,380);
	glEnd();
	glFlush();



	glColor3f(0.7,0.2,0.8);  //CPU USB
	glBegin(GL_QUADS);
	glVertex2f(a+72,381);
	glVertex2f(a+80,381);
	glVertex2f(a+80,378);
	glVertex2f(a+72,378);
	glEnd();
	glFlush();

	                          //drop lines
	glBegin(GL_POLYGON);
	glColor3f(0.403,0.392,0.482);
	glVertex2f(a+57.5,370);
	glColor3f(0.303,0.292,0.382);
    glVertex2f(a+60.5,370);
	glColor3f(0.203,0.192,0.282);
    glVertex2f(a+60.5,350);
	glColor3f(0.103,0.092,0.182);
	glVertex2f(a+57.5,350);
	glEnd();
	glFlush();
	                           //backbone cable
	glBegin(GL_POLYGON);
	glColor3f(0.403,0.392,0.482);
	glVertex2f(57.5,350);
	glColor3f(0.303,0.292,0.382);
	glVertex2f(460.5,350);
	glColor3f(0.203,0.192,0.282);
	glVertex2f(460.5,340);
	glColor3f(0.103,0.092,0.182);
	glVertex2f(57.5,340);
	glEnd();
	glFlush();


	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(210,475);
	glVertex2f(225,475);
	glVertex2f(225,480);
	glVertex2f(210,480);
	glEnd();
	glFlush();

	setFont(GLUT_BITMAP_HELVETICA_12);
    glColor3f(1.0,1.0,1.0);
	drawstring(230.0,475.5,1.0,"DATA FRAMES");		//frame indicators
	glFlush();

	glColor3f(0.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(330,475);
	glVertex2f(345,475);
	glVertex2f(345,480);
	glVertex2f(330,480);
	glEnd();
	glFlush();

    glColor3f(1.0,1.0,1.0);
	drawstring(350.0,475.5,1.0,"ACK ");
	glFlush();

	glColor3f(1.0,1.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(430,475);
	glVertex2f(445,475);
	glVertex2f(445,480);
	glVertex2f(430,480);
	glEnd();
	glFlush();

    glColor3f(1.0,1.0,1.0);
	drawstring(450.0,475.5,1.0,"NAK");
	glFlush();

}


void computers()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0f,1.0f,1.0f);
	setFont(GLUT_BITMAP_HELVETICA_12);
 	drawstring(425.0,453.0,1.0,"COM-5");

	computer(400);

	glColor3f(1.0f,1.0f,1.0f);
	setFont(GLUT_BITMAP_HELVETICA_12);
 	drawstring(325.0,453.0,1.0,"COM-4");

	computer(300);

	glColor3f(1.0f,1.0f,1.0f);
	setFont(GLUT_BITMAP_HELVETICA_12);
 	drawstring(225.0,453.0,1.0,"COM-3");

	computer(200);

	glColor3f(1.0f,1.0f,1.0f);
	setFont(GLUT_BITMAP_HELVETICA_12);
 	drawstring(125.0,453.0,1.0,"COM-2");

	computer(100);

	glColor3f(1.0f,1.0f,1.0f);
	setFont(GLUT_BITMAP_HELVETICA_12);
 	drawstring(25.0,453.0,1.0,"COM-1");

	computer(0);
}
void draw6(void)				// text for keyboard interaction

{

	glColor3f(0.2,0.0,0.7);
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(0,135);
	glVertex2f(500,135);
	glVertex2f(500,0);
	glEnd();
	glFlush();


	glColor3f(1.0f,1.0f,1.0f);
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(360.0,130.0,1.0,"DO U WISH TO CONTINUE?");
	glColor3f(1.0f,1.0f,1.0f);
	drawstring(360.0,110.0,1.0,"PRESS  Y/N");
	glFlush();

}
void draw1(void)  // DRAWING OF SEND WINDOW WITH ITS LABELS
{
	// SENDER WINDOW
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.8,0.0);
	slide(25,2,50,250);				// Initial set of frames in BLUE color

	glColor3f(1.0,0.8,0.0);
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(210.0,405.0,1.0,"S E N D   W I N D O W");


	setFont(GLUT_BITMAP_HELVETICA_12);
	glColor3f(1.0,1.0,1.0);
	drawstring(50,220.0,0.0,"FRAMES  ALREADY");
	glColor3f(1.0,1.0,1.0);
	drawstring(50,210.0,0.0,"ACKNOWLEDGED");

	glColor3f(1.0,1.0,1.0);
	drawstring(125,220.0,0.0,"FRAMES SENT");
	glColor3f(1.0,1.0,1.0);
	drawstring(125,210.0,0.0,"BUT NOT");
	glColor3f(1.0,1.0,1.0);
	drawstring(125,200.0,0.0,"ACKNOWLEDGED");

	glColor3f(1.0,1.0,1.0);
	drawstring(195,220.0,0.0,"FRAMES THAT");
	glColor3f(1.0,1.0,1.0);
	drawstring(195,210.0,0.0,"CAN BE SENT");

	glColor3f(1.0,1.0,1.0);
	drawstring(290,220.0,0.0,"FRAMES THAT CAN NOT BE SENT");

	glColor3f(0.0,1.0,1.0);
	drawstring(127,278.0,0.0,"Sf");
	glColor3f(0.0,1.0,1.0);
	drawstring(70,300.0,0.0,"( Sf: FIRST OUTSTANDING FRAME )");

	glColor3f(0.0,1.0,1.0);
	drawstring(187,278.0,0.0,"Sn");
	glColor3f(0.0,1.0,1.0);
	drawstring(195,300.0,0.0,"( Sn: NEXT FRAME TO SEND )");

	glColor3f(1.0,1.0,1.0);
	drawstring(55,260.0,0.0,"11");
	glColor3f(1.0,1.0,1.0);
	drawstring(69,260.0,0.0,"12");
	glColor3f(1.0,1.0,1.0);
	drawstring(84,260.0,0.0,"13");
	glColor3f(1.0,1.0,1.0);
	drawstring(99,260.0,0.0,"14");
	glColor3f(1.0,1.0,1.0);
	drawstring(114,260.0,0.0,"15");
	glColor3f(1.0,1.0,1.0);
	drawstring(130,260.0,0.0,"0");
	glColor3f(1.0,1.0,1.0);
	drawstring(147,260.0,0.0,"1");
	glColor3f(1.0,1.0,1.0);
	drawstring(163,260.0,0.0,"2");
	glColor3f(1.0,1.0,1.0);
	drawstring(177,260.0,0.0,"3");
	glColor3f(1.0,1.0,1.0);
	drawstring(191,260.0,0.0,"4");
	glColor3f(1.0,1.0,1.0);
	drawstring(206,260.0,0.0,"5");
	glColor3f(1.0,1.0,1.0);
	drawstring(221,260.0,0.0,"6");
	glColor3f(1.0,1.0,1.0);
	drawstring(236,260.0,0.0,"7");
	glColor3f(1.0,1.0,1.0);
	drawstring(251,260.0,0.0,"8");
	glColor3f(1.0,1.0,1.0);
	drawstring(266,260.0,0.0,"9");
	glColor3f(1.0,1.0,1.0);
	drawstring(280,260.0,0.0,"10");
	glColor3f(1.0,1.0,1.0);
	drawstring(295,260.0,0.0,"11");
	glColor3f(1.0,1.0,1.0);
	drawstring(310,260.0,0.0,"12");
	glColor3f(1.0,1.0,1.0);
	drawstring(324,260.0,0.0,"13");
	glColor3f(1.0,1.0,1.0);
	drawstring(339,260.0,0.0,"14");
	glColor3f(1.0,1.0,1.0);
	drawstring(354,260.0,0.0,"15");
	glColor3f(1.0,1.0,1.0);
	drawstring(370,260.0,0.0,"0");
	glColor3f(1.0,1.0,1.0);
	drawstring(385,260.0,0.0,"1");
	glColor3f(1.0,1.0,1.0);
	drawstring(400,260.0,0.0,"2");

	glEnd();
	glFlush();

	glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);																				  // Send window in WHITE color
		glVertex2f(125,240);
	    glVertex2f(245,240);
		glVertex2f(245,285);
		glVertex2f(125,285);
    glEnd();
	glFlush();

	glColor3f(0.0,1.0,0.0);
	glEnd();
	glFlush();
	glColor3f(1.0,0.0,0.0);
	slide(5,2,185,250);																				 // Frames that are yet to be sent in RED color
	glFlush();
	glEnd();


	//delay();

}


void draw2(void)																						 // DRAWING OF RECEIVE WINDOW WITH ITS LABELS
{
																										// RECIVER WINDOW
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	glFlush();

	glColor3f(1.0,0.8,0.0);//	glColor3f(0.0,0.0,1.0);
	slide(25,2,50,250);																					 // Initial set of frames in BLUE color
	glEnd();
	glFlush();

		glColor3f(1.0,0.8,0.0);
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(210.0,405.0,1.0,"R E C I E V E    W I N D O W");


	setFont(GLUT_BITMAP_HELVETICA_12);
	glColor3f(1.0,1.0,1.0);
	drawstring(60,220.0,0.0,"FRAMES  ALREADY RECIEVED");

	glColor3f(1.0,1.0,1.0);
	drawstring(172,220.0,0.0,"FRAMES THAT CAN BE RECIEVED");
	glColor3f(1.0,1.0,1.0);
	drawstring(172,210.0,0.0,"AND STORED FOR LATER DELIVERY");
	glColor3f(1.0,1.0,1.0);
	drawstring(172,200.0,0.0,"( GREEN BOXES ALREADY RECIEVED )");


	glColor3f(1.0,1.0,1.0);
	drawstring(300,220.0,0.0,"FRAMES THAT CAN NOT BE RECIEVED");

	glColor3f(1.0,1.0,1.0);
	drawstring(175,278.0,0.0,"Rn");
	glColor3f(1.0,1.0,1.0);
	drawstring(120,300.0,0.0,"( Rn: NEXT FRAME EXPECTED )");

	glColor3f(1.0,1.0,1.0);
	drawstring(55,260.0,0.0,"11");
	glColor3f(1.0,1.0,1.0);
	drawstring(69,260.0,0.0,"12");
	glColor3f(1.0,1.0,1.0);
	drawstring(84,260.0,0.0,"13");
	glColor3f(1.0,1.0,1.0);
	drawstring(99,260.0,0.0,"14");
	glColor3f(1.0,1.0,1.0);
	drawstring(114,260.0,0.0,"15");
	glColor3f(1.0,1.0,1.0);
	drawstring(130,260.0,0.0,"0");
	glColor3f(1.0,1.0,1.0);
	drawstring(147,260.0,0.0,"1");
	glColor3f(1.0,1.0,1.0);
	drawstring(163,260.0,0.0,"2");
	glColor3f(1.0,1.0,1.0);
	drawstring(177,260.0,0.0,"3");
	glColor3f(1.0,1.0,1.0);
	drawstring(191,260.0,0.0,"4");
	glColor3f(1.0,1.0,1.0);
	drawstring(206,260.0,0.0,"5");
	glColor3f(1.0,1.0,1.0);
	drawstring(221,260.0,0.0,"6");
	glColor3f(1.0,1.0,1.0);
	drawstring(236,260.0,0.0,"7");
	glColor3f(1.0,1.0,1.0);
	drawstring(251,260.0,0.0,"8");
	glColor3f(1.0,1.0,1.0);
	drawstring(266,260.0,0.0,"9");
	glColor3f(1.0,1.0,1.0);
	drawstring(280,260.0,0.0,"10");
	glColor3f(1.0,1.0,1.0);
	drawstring(295,260.0,0.0,"11");
	glColor3f(1.0,1.0,1.0);
	drawstring(310,260.0,0.0,"12");
	glColor3f(1.0,1.0,1.0);
	drawstring(324,260.0,0.0,"13");
	glColor3f(1.0,1.0,1.0);
	drawstring(339,260.0,0.0,"14");
	glColor3f(1.0,1.0,1.0);
	drawstring(354,260.0,0.0,"15");
	glColor3f(1.0,1.0,1.0);
	drawstring(370,260.0,0.0,"0");
	glColor3f(1.0,1.0,1.0);
	drawstring(385,260.0,0.0,"1");
	glColor3f(1.0,1.0,1.0);
	drawstring(400,260.0,0.0,"2");



	glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);																		  // Send window in WHITE color
		glVertex2f(170,240);
	    glVertex2f(290,240);
		glVertex2f(290,285);
		glVertex2f(170,285);
    glEnd();
	glFlush();

	glColor3f(1.0,0.0,0.0);
	slide(2,2,170,250);																		// Frames already sent and yet to be acknowledged in GREEN
	glEnd();
	glFlush();

	glColor3f(0.0,1.0,0.0);
	slide(2,2,185,250);
	glEnd();
	glFlush();

	glColor3f(1.0,0.0,0.0);
	slide(3,2,200,250);
	glEnd();
	glFlush();

	glColor3f(0.0,1.0,0.0);
	slide(2,2,230,250);
	glEnd();
	glFlush();

	glColor3f(1.0,0.0,0.0);
	slide(2,2,245,250);
	glEnd();
	glFlush();

	glColor3f(0.0,1.0,0.0);
	slide(2,2,260,250);
	glEnd();
	glFlush();

	glColor3f(1.0,0.0,0.0);
	slide(2,2,275,250);


	glEnd();
	glFlush();

draw6();
   // delay();

}



void draw3(int m,int l)																						  // DRAWING OF SAFE SENDING
{
																											//Sender site initial window
	glClear(GL_COLOR_BUFFER_BIT);
	computers();

	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(0.4932,0.9996,0.0);
	drawstring(m+30.0,435.0,1.0,E);


	glColor3f(0.0,0.0,1.0);																						// active line indicator
	glBegin(GL_POLYGON);
	glVertex2f(59.5+m,348);
	glVertex2f(59.5+m,342);
	glVertex2f(155.5+l,342);
	glVertex2f(155.5+l,348);
	glEnd();
	glFlush();


	glColor3f(1.6,1.9,1.2);
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(60.0,475.5,1.0,"S A F E    S E N D I N G");

	setFont(GLUT_BITMAP_HELVETICA_12);
	glColor3f(1.0,1.0,1.0);
	drawstring(55,268.0,0.0,"0");
	glColor3f(1.0,1.0,1.0);
	drawstring(69,268.0,0.0," 1");
	glColor3f(1.0,1.0,1.0);
	drawstring(84,268.0,0.0,"2");
	glColor3f(1.0,1.0,1.0);
	drawstring(99,268.0,0.0,"3");
	glColor3f(1.0,1.0,1.0);
	drawstring(114,268.0,0.0,"4");
	glColor3f(1.0,1.0,1.0);
	drawstring(130,268.0,0.0,"5");
	glColor3f(1.0,1.0,1.0);
	drawstring(147,268.0,0.0,"6");
	glColor3f(1.0,1.0,1.0);
	drawstring(163,268.0,0.0,"7");
	glColor3f(1.0,1.0,1.0);
	drawstring(177,268.0,0.0,"0");

	glColor3f(1.0,1.0,1.0);
	drawstring(305,268.0,0.0,"0");
	glColor3f(1.0,1.0,1.0);
	drawstring(320,268.0,0.0,"1");
	glColor3f(1.0,1.0,1.0);
	drawstring(334,268.0,0.0," 2");
	glColor3f(1.0,1.0,1.0);
	drawstring(349,268.0,0.0,"3");
	glColor3f(1.0,1.0,1.0);
	drawstring(364,268.0,0.0,"4");
	glColor3f(1.0,1.0,1.0);
	drawstring(379,268.0,0.0,"5");
	glColor3f(1.0,1.0,1.0);
	drawstring(394,268.0,0.0,"6");
	glColor3f(1.0,1.0,1.0);
	drawstring(409,268.0,0.0,"7");
	glColor3f(1.0,1.0,1.0);
	drawstring(424,268.0,0.0,"0");

																											//SENDER SIDE

	glColor3f(0.0,0.0,1.0);																				 // Initial set of frames in BLUE color
	slide(10,2,50,260);
	glFlush();

	glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);																				  // Send window in WHITE color
		glVertex2f(50,255);
	    glVertex2f(110,255);
		glVertex2f(110,290);
		glVertex2f(50,290);
    glEnd();
	glFlush();


	glColor3f(0.0,0.0,1.0);
	slide(10,2,300,260);																				   // Initial set of frames in BLUE color
	glEnd();
	glFlush();

	glColor3f(1.0,0.0,0.0);																				 // initial sending frames in red
    slide(5,2,50,260);
    glEnd();
	glFlush();



glColor3f(1.0,0.0,0.0);																					 // receiver window in red
slide(5,2,300,260);
glEnd();
	glFlush();

	glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);																				  // receiver window in WHITE color
		glVertex2f(300,255);
	    glVertex2f(360,255);
		glVertex2f(360,290);
		glVertex2f(300,290);
    glEnd();
	glFlush();

  // delay();
   glColor3f(0.0,1.0,0.0);																				 //Frame 0 sent and becoming green
   slide(2,2,50,260);
   glEnd();
   glFlush();


   glColor3f(1.0,0.0,0.0);																				  // sliding the window and becoming green
slide(4,2,65,260);
glEnd();
	glFlush();


move1();																								// movement of data packet


glColor3f(0.0,0.0,1.0);																					 // sliding the window and becoming green
slide(2,2,300,260);
glEnd();
	glFlush();

	glColor3f(1.0,0.0,0.0);																				 // 4th frame red
slide(2,2,360,260);
glEnd();
	glFlush();

glColor3f(0.2,0.0,0.7);
    glBegin(GL_LINE_LOOP);																				 // To remove initial WHITE window trace
		glVertex2f(300,255);
	    glVertex2f(360,255);
		glVertex2f(360,290);
		glVertex2f(300,290);
    glEnd();
	glFlush();


glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);																				  // moving the reciever window in WHITE color
		glVertex2f(315,255);
	    glVertex2f(375,255);
		glVertex2f(375,290);
		glVertex2f(315,290);
    glEnd();
	glFlush();

glColor3f(0.0,0.0,1.0);																					 // To remove traces
glBegin(GL_LINES);
glVertex2f(300,260);
glVertex2f(300,285);
glEnd();
glFlush();

glColor3f(1.0,0.0,0.0);																					// To remove traces
glBegin(GL_LINES);
glVertex2f(360,260);
glVertex2f(360,285);
glEnd();
glFlush();


glColor3f(0.0,1.0,0.0);																					// sliding the window and becoming green
slide(2,2,65,260);
glEnd();
	glFlush();

glColor3f(0.0,0.0,1.0);																					// sliding the window and becoming green
slide(1,2,300,260);
glEnd();
	glFlush();

move2();
	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(0.4932,0.9996,0.0);
	drawstring(l+130.0,435.0,1.0,E);

		setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(0.2,0.0,0.7);
	drawstring(m+30.0,435.0,1.0,E);




	glColor3f(1.0,1.0,1.0);
	drawstring(69,268.0,0.0," 1");
	glColor3f(1.0,1.0,1.0);
	drawstring(55,268.0,0.0,"0");

	glColor3f(1.0,1.0,1.0);
	drawstring(320,268.0,0.0,"1");


glColor3f(0.0,0.0,1.0);																				  // sliding the window and becoming blue
slide(2,2,50,260);
glEnd();
	glFlush();

glColor3f(0.2,0.0,0.7);
    glBegin(GL_LINE_LOOP);																			 // To remove initial WHITE window trace
		glVertex2f(50,255);
	    glVertex2f(50,290);
		glVertex2f(110,290);
		glVertex2f(110,255);
    glEnd();
	glFlush();

	glColor3f(1.0,0.0,0.0);																				// sliding the window and becoming blue
 slide(2,2,110,260);
glBegin(GL_LINES);
glVertex2f(110,260);
glVertex2f(110,285);
glEnd();
	glFlush();



glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);																			 // moving the reciever window in WHITE color
		glVertex2f(65,255);
	    glVertex2f(65,290);
		glVertex2f(125,290);
		glVertex2f(125,255);
    glEnd();
	glFlush();



glColor3f(0.0,0.0,1.0);																					//to remove traces
glBegin(GL_LINES);
glVertex2f(50,260);
glVertex2f(50,285);
glEnd();
glFlush();

glColor3f(0.2,0.0,0.7);
    glBegin(GL_LINE_LOOP);																			  // moving the reciever window in WHITE color
		glVertex2f(315,255);
	    glVertex2f(375,255);
		glVertex2f(375,290);
		glVertex2f(315,290);
    glEnd();
	glFlush();

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(315,260);
	glVertex2f(315,285);
	glVertex2f(375,260);
	glVertex2f(375,285);
	glEnd();
	glFlush();

	glColor3f(0.0,0.0,1.0);																			// sliding the window and becoming green
slide(3,2,300,260);
glEnd();
	glFlush();


glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);																			  // moving the reciever window in WHITE color
		glVertex2f(330,255);
	    glVertex2f(330,290);
		glVertex2f(390,290);
		glVertex2f(390,255);
    glEnd();
	glFlush();


glColor3f(1.0,0.0,0.0);																				 // sliding the window and becoming green
slide(2,2,375,260);
glEnd();
	glFlush();


move8();

	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
	drawstring(m+30.0,435.0,1.0,"message sent");

	setFont(GLUT_BITMAP_HELVETICA_12);

	glColor3f(1.0,1.0,1.0);
	drawstring(334,268.0,0.0," 2");


glColor3f(0.2,0.0,0.7);
    glBegin(GL_LINE_LOOP);																				  // remove window trace
		glVertex2f(65,255);
	    glVertex2f(65,290);
		glVertex2f(125,290);
		glVertex2f(125,255);
    glEnd();
	glFlush();


glColor3f(1.0,0.0,0.0);																					// sliding the window and becoming green
slide(5,2,80,260);
glEnd();
	glFlush();

	glColor3f(0.0,0.0,1.0);																				 // sliding the window and becoming green
slide(3,2,50,260);
glEnd();
	glFlush();


glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);																			   // moving the reciever window in WHITE color
		glVertex2f(80,255);
	    glVertex2f(80,290);
		glVertex2f(140,290);
		glVertex2f(140,255);
    glEnd();
	glFlush();

	delay();


}
void draw4(int m,int l)																						 // DRAWING OF PACKET CRASHNG
{
																										//second screen for lost packet
//delay();


glClear(GL_COLOR_BUFFER_BIT);
	computers();
		glColor3f(0.0,0.0,1.0);																						// active line indicator
	glBegin(GL_POLYGON);
	glVertex2f(59.5+m,348);
	glVertex2f(59.5+m,342);
	glVertex2f(155.5+l,342);
	glVertex2f(155.5+l,348);
	glEnd();
	glFlush();
glColor3f(1.6,1.9,1.2);

	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(60.0,475.5,1.0,"P A C K E T   C R A S H I N G");

	setFont(GLUT_BITMAP_HELVETICA_12);
	glColor3f(1.0,1.0,1.0);
	drawstring(56,268.0,0.0,"0");
	glColor3f(1.0,1.0,1.0);
	drawstring(70,268.0,0.0,"1");
	glColor3f(1.0,1.0,1.0);
	drawstring(85,268.0,0.0,"2");
	glColor3f(1.0,1.0,1.0);
	drawstring(100,268.0,0.0,"3");
	glColor3f(1.0,1.0,1.0);
	drawstring(114,268.0,0.0," 4");
	glColor3f(1.0,1.0,1.0);
	drawstring(130,268.0,0.0,"5");
	glColor3f(1.0,1.0,1.0);
	drawstring(147,268.0,0.0,"6");
	glColor3f(1.0,1.0,1.0);
	drawstring(163,268.0,0.0,"7");
	glColor3f(1.0,1.0,1.0);
	drawstring(177,268.0,0.0,"0");

	glColor3f(1.0,1.0,1.0);
	drawstring(305,268.0,0.0,"0");
	glColor3f(1.0,1.0,1.0);
	drawstring(320,268.0,0.0,"1");
	glColor3f(1.0,1.0,1.0);
	drawstring(334,268.0,0.0," 2");
	glColor3f(1.0,1.0,1.0);
	drawstring(349,268.0,0.0,"3");
	glColor3f(1.0,1.0,1.0);
	drawstring(365,268.0,0.0,"4");
	glColor3f(1.0,1.0,1.0);
	drawstring(379,268.0,0.0," 5");
	glColor3f(1.0,1.0,1.0);
	drawstring(394,268.0,0.0,"6");
	glColor3f(1.0,1.0,1.0);
	drawstring(409,268.0,0.0,"7");
	glColor3f(1.0,1.0,1.0);
	drawstring(424,268.0,0.0,"0");


	glColor3f(0.0,0.0,1.0);
	slide(10,2,50,260);																					// Initial set of frames in BLUE color

	glColor3f(1.0,0.0,0.0);
	slide(5,2,50,260);																					 // red frames in window
	glEnd();
	glFlush();

	glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);																				// send window in WHITE color
		glVertex2f(50,255);
	    glVertex2f(50,290);
		glVertex2f(110,290);
		glVertex2f(110,255);
    glEnd();
	glFlush();




																										//Reciver Window
	glColor3f(0.0,0.0,1.0);
	slide(10,2,300,260);																				// Initial set of frames in BLUE color
	glEnd();
	glFlush();

	glColor3f(1.0,0.0,0.0);
	slide(5,2,300,260);																				   // red frames in window
	glEnd();
	glFlush();

	glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);																				// moving the reciever window in WHITE color
		glVertex2f(300,255);
	    glVertex2f(360,255);
		glVertex2f(360,290);
		glVertex2f(300,290);
    glEnd();
	glFlush();



//	delay();

	glColor3f(0.0,1.0,0.0);
    slide(2,2,50,260);																					// red frames in window
	glEnd();
	glFlush();

	move1();


glColor3f(0.0,0.0,1.0);																					 // sliding the window and becoming green
slide(2,2,300,260);
glEnd();
	glFlush();

	glColor3f(1.0,0.0,0.0);																				// 4th frame red
slide(2,2,360,260);
glEnd();
	glFlush();

glColor3f(0.2,0.0,0.7);
    glBegin(GL_LINE_LOOP);																				// To remove initial WHITE window trace
		glVertex2f(300,255);
	    glVertex2f(360,255);
		glVertex2f(360,290);
		glVertex2f(300,290);
    glEnd();
	glFlush();


glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);																				 // moving the reciever window in WHITE color
		glVertex2f(315,255);
	    glVertex2f(375,255);
		glVertex2f(375,290);
		glVertex2f(315,290);
    glEnd();
	glFlush();

glColor3f(0.0,0.0,1.0);																					// To remove traces
glBegin(GL_LINES);
glVertex2f(300,260);
glVertex2f(300,285);
glEnd();
glFlush();

glColor3f(1.0,0.0,0.0);																					 // To remove traces
glBegin(GL_LINES);
glVertex2f(360,260);
glVertex2f(360,285);
glEnd();
glFlush();



 glColor3f(0.0,1.0,0.0);																				 // sliding the window and becoming green
slide(2,2,65,260);
glEnd();
	glFlush();


	move2();


glColor3f(0.0,0.0,1.0);																					 // sliding the window and becoming blue
slide(2,2,50,260);
glEnd();
	glFlush();

glColor3f(0.2,0.0,0.7);
    glBegin(GL_LINE_LOOP);																				 // To remove initial WHITE window trace
		glVertex2f(50,255);
	    glVertex2f(50,290);
		glVertex2f(110,290);
		glVertex2f(110,255);
    glEnd();
	glFlush();

glColor3f(1.0,0.0,0.0);																					// sliding the window and becoming blue
slide(2,2,110,260);
glBegin(GL_LINES);
glVertex2f(110,260);
glVertex2f(110,285);
glEnd();
	glFlush();



glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);																				 // moving the reciever window in WHITE color
		glVertex2f(65,255);
	    glVertex2f(65,290);
		glVertex2f(125,290);
		glVertex2f(125,255);
    glEnd();
	glFlush();



glColor3f(0.0,0.0,1.0);																					//to remove traces
glBegin(GL_LINES);
glVertex2f(50,260);
glVertex2f(50,285);
glEnd();
glFlush();

glColor3f(0.2,0.0,0.7);
    glBegin(GL_LINE_LOOP);																			  // moving the reciever window in WHITE color
		glVertex2f(315,255);
	    glVertex2f(375,255);
		glVertex2f(375,290);
		glVertex2f(315,290);
    glEnd();
	glFlush();

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(315,260);
	glVertex2f(315,285);
	glVertex2f(375,260);
	glVertex2f(375,285);
	glEnd();
	glFlush();

glColor3f(0.0,0.0,1.0);																					// sliding the window and becoming green
slide(3,2,300,260);
glEnd();
	glFlush();




glColor3f(1.0,0.0,0.0);																					// sliding the window and becoming green
slide(2,2,375,260);
glEnd();
	glFlush();

	glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);																				 // moving the reciever window in WHITE color
		glVertex2f(330,255);
	    glVertex2f(330,290);
		glVertex2f(390,290);
		glVertex2f(390,255);
    glEnd();
	glFlush();


	setFont(GLUT_BITMAP_HELVETICA_12);
	glColor3f(1.0,1.0,1.0);
	drawstring(56,268.0,0.0,"0");
		glColor3f(1.0,1.0,1.0);
	drawstring(320,268.0,0.0,"1");

move8();

setFont(GLUT_BITMAP_HELVETICA_12);
	glColor3f(1.0,1.0,1.0);
	drawstring(70,268.0,0.0,"1");

glColor3f(0.2,0.0,0.7);
    glBegin(GL_LINE_LOOP);																				 // remove window trace
		glVertex2f(65,255);
	    glVertex2f(65,290);
		glVertex2f(125,290);
		glVertex2f(125,255);
    glEnd();
	glFlush();


glColor3f(1.0,0.0,0.0);																					 // sliding the window and becoming green
slide(5,2,80,260);
glEnd();
	glFlush();

	glColor3f(0.0,0.0,1.0);																				 // sliding the window and becoming green
slide(3,2,50,260);
glEnd();
	glFlush();


glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);																				 // moving the reciever window in WHITE color
		glVertex2f(80,255);
	    glVertex2f(80,290);
		glVertex2f(140,290);
		glVertex2f(140,255);
    glEnd();
	glFlush();

	glColor3f(0.0,1.0,0.0);
	slide(2,2,80,260);
	glFlush();

move3();

	glColor3f(1.0,0.0,0.0);																				//packet crashing
	glBegin(GL_POLYGON);
	glVertex2f(240,168);
	glVertex2f(255,168);
	glVertex2f(260,178);
	glVertex2f(265,168);
	glVertex2f(280,168);
	glVertex2f(267.5,163);
	glVertex2f(280,153);
	glVertex2f(260,163);
	glVertex2f(240,153);
	glVertex2f(252.5,163);
	glEnd();
	glFlush();


	glColor3f(0.2,0.0,0.7);																				//to remove traces
	glBegin(GL_TRIANGLES);
	glVertex2f(240,168);
	glVertex2f(260,178);
	glVertex2f(255,168);
    glEnd();
	glFlush();

    glBegin(GL_TRIANGLES);
	glVertex2f(240,168);
	glVertex2f(252.5,163);
	glVertex2f(240,153);
	glEnd();
	glFlush();


	glColor3f(0.0,0.0,1.0);
	slide(2,2,65,260);
	glFlush();


	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
	glVertex2f(80,260);
	glVertex2f(80,285);
	glEnd();

  glColor3f(0.0,1.0,0.0);
	slide(2,2,95,260);
	glFlush();


   move5();

   glColor3f(1.0,1.0,1.0);
	drawstring(334,268.0,0.0," 2");


   glColor3f(0.0,1.0,0.0);
	slide(2,2,345,260);
	glFlush();

    glColor3f(0.0,1.0,0.0);
	slide(2,2,110,260);
	glFlush();


	move10();

	glColor3f(0.0,1.0,0.0);
	slide(2,2,360,260);
	glFlush();

	glColor3f(0.2,0,0.7);
    glBegin(GL_POLYGON);																			 //to remove timer trace
		glVertex2f(100,80);
	    glVertex2f(100,90);
		glVertex2f(225,90);
		glVertex2f(225,80);
    glEnd();
	glFlush();

	glColor3f(0.2,0.0,0.7);																			//packet crashing
	glBegin(GL_POLYGON);
	glVertex2f(240,168);
	glVertex2f(255,168);
	glVertex2f(260,178);
	glVertex2f(265,168);
	glVertex2f(280,168);
	glVertex2f(267.5,163);
	glVertex2f(280,153);
	glVertex2f(260,163);
	glVertex2f(240,153);
	glVertex2f(252.5,163);
	glEnd();
	glFlush();


	glColor3f(0.2,0.0,0.7);																			//to remove traces
	glBegin(GL_TRIANGLES);
	glVertex2f(240,168);
	glVertex2f(260,178);
	glVertex2f(255,168);
    glEnd();
	glFlush();

    glBegin(GL_TRIANGLES);
	glVertex2f(240,168);
	glVertex2f(252.5,163);
	glVertex2f(240,153);
	glEnd();
	glFlush();

	glColor3f(0.2f,0.0f,0.7f);
    drawstring(185.0,165.0,1.0,"FRAME 2 lost");

	move4();
	glColor3f(1.0,1.0,1.0);
	drawstring(334,268.0,0.0," 2");

glColor3f(0.0,1.0,0.0);
	slide(2,2,330,260);
	glFlush();

 //delay();

	glColor3f(0.2,0.0,0.7);
    glBegin(GL_LINE_LOOP);																			// moving the reciever window in WHITE color
		glVertex2f(330,255);
	    glVertex2f(330,290);
		glVertex2f(390,290);
		glVertex2f(390,255);
    glEnd();
	glFlush();


	glColor3f(0.0,0.0,1.0);
	slide(6,2,300,260);
	glFlush();


glColor3f(1.0,0.0,0.0);
	slide(5,2,375,260);
	glFlush();

	glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);																			// moving the reciever window in WHITE color
		glVertex2f(375,255);
	    glVertex2f(375,290);
		glVertex2f(435,290);
		glVertex2f(435,255);
    glEnd();
	glFlush();

move11();

	glColor3f(1.0,1.0,1.0);
	drawstring(85,268.0,0.0,"2");
	glColor3f(1.0,1.0,1.0);
	drawstring(100,268.0,0.0,"3");
	glColor3f(1.0,1.0,1.0);
	drawstring(114,268.0,0.0," 4");
	glColor3f(1.0,1.0,1.0);
	drawstring(379,268.0,0.0," 5");


glColor3f(0.2,0.0,0.7);
    glBegin(GL_LINE_LOOP);																			 // moving the reciever window in WHITE color
		glVertex2f(80,255);
	    glVertex2f(80,290);
		glVertex2f(140,290);
		glVertex2f(140,255);
    glEnd();
	glFlush();


glColor3f(0.0,0.0,1.0);
	slide(6,2,50,260);
	glFlush();


glColor3f(1.0,0.0,0.0);
	slide(5,2,125,260);
	glFlush();


glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);																			 // moving the reciever window in WHITE color
		glVertex2f(125,255);
	    glVertex2f(125,290);
		glVertex2f(185,290);
		glVertex2f(185,255);
    glEnd();
	glFlush();

}

void draw5(int m, int l)																					// to show time out
{

																									//Sender site initial window
	glClear(GL_COLOR_BUFFER_BIT);
		computers();
	glColor3f(0.0,0.0,1.0);
	slide(10,2,50,260);																				// Initial set of frames in BLUE color
	glFlush();
	glColor3f(0.0,0.0,1.0);																						// active line indicator
	glBegin(GL_POLYGON);
	glVertex2f(59.5+500,348);//m
	glVertex2f(59.5+m,342);
	glVertex2f(155.5+l,342);
	glVertex2f(155.5+l,348);
	glEnd();
	glFlush();
	glColor3f(1.6,1.9,1.2);

	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(60.0,475.5,1.0,"T I M E    O U T");

	setFont(GLUT_BITMAP_HELVETICA_12);
	glColor3f(1.0,1.0,1.0);
	drawstring(55,268.0,0.0,"0");
	glColor3f(1.0,1.0,1.0);
	drawstring(69,268.0,0.0," 1");
	glColor3f(1.0,1.0,1.0);
	drawstring(84,268.0,0.0," 2");
	glColor3f(1.0,1.0,1.0);
	drawstring(99,268.0,0.0,"3");
	glColor3f(1.0,1.0,1.0);
	drawstring(114,268.0,0.0,"4");
	glColor3f(1.0,1.0,1.0);
	drawstring(130,268.0,0.0,"5");
	glColor3f(1.0,1.0,1.0);
	drawstring(147,268.0,0.0,"6");
	glColor3f(1.0,1.0,1.0);
	drawstring(163,268.0,0.0,"7");
	glColor3f(1.0,1.0,1.0);
	drawstring(177,268.0,0.0,"0");

	glColor3f(1.0,1.0,1.0);
	drawstring(305,268.0,0.0,"0");
	glColor3f(1.0,1.0,1.0);
	drawstring(320,268.0,0.0,"1");
	glColor3f(1.0,1.0,1.0);
	drawstring(334,268.0,0.0," 2");
	glColor3f(1.0,1.0,1.0);
	drawstring(349,268.0,0.0," 3");
	glColor3f(1.0,1.0,1.0);
	drawstring(364,268.0,0.0,"4");
	glColor3f(1.0,1.0,1.0);
	drawstring(379,268.0,0.0,"5");
	glColor3f(1.0,1.0,1.0);
	drawstring(394,268.0,0.0,"6");
	glColor3f(1.0,1.0,1.0);
	drawstring(409,268.0,0.0,"7");
	glColor3f(1.0,1.0,1.0);
	drawstring(424,268.0,0.0,"0");





	glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);																			 // Send window in WHITE color
		glVertex2f(50,255);
	    glVertex2f(110,255);
		glVertex2f(110,290);
		glVertex2f(50,290);
    glEnd();
	glFlush();


	glColor3f(0.0,0.0,1.0);
	slide(10,2,300,260);																			 // Initial set of frames in BLUE color
	glEnd();
	glFlush();

	glColor3f(1.0,0.0,0.0);																			 // initial sending frames in red
slide(5,2,50,260);
glEnd();
	glFlush();



glColor3f(1.0,0.0,0.0);																				 // receiver window in red
slide(5,2,300,260);
glEnd();
	glFlush();
	glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);																			 // receiver window in WHITE color
		glVertex2f(300,255);
	    glVertex2f(360,255);
		glVertex2f(360,290);
		glVertex2f(300,290);
    glEnd();
	glFlush();
   glColor3f(0.0,1.0,0.0);																			//Frame 0 sent and becoming green
   slide(2,2,50,260);
   glEnd();
   glFlush();



   glColor3f(1.0,0.0,0.0);																			 // sliding the window and becoming green
slide(4,2,65,260);
glEnd();
	glFlush();


move1();																							// movement of data packet

glColor3f(0.0,0.0,1.0);																				// sliding the window and becoming green
slide(2,2,300,260);
glEnd();
	glFlush();

	glColor3f(1.0,0.0,0.0);																			// 4th frame red
slide(2,2,360,260);
glEnd();
	glFlush();

glColor3f(0.2,0.0,0.7);
    glBegin(GL_LINE_LOOP);																			// To remove initial WHITE window trace
		glVertex2f(300,255);
	    glVertex2f(360,255);
		glVertex2f(360,290);
		glVertex2f(300,290);
    glEnd();
	glFlush();


glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);																			  // moving the reciever window in WHITE color
		glVertex2f(315,255);
	    glVertex2f(375,255);
		glVertex2f(375,290);
		glVertex2f(315,290);
    glEnd();
	glFlush();

glColor3f(0.0,0.0,1.0);																				// To remove traces
glBegin(GL_LINES);
glVertex2f(300,260);
glVertex2f(300,285);
glEnd();
glFlush();

glColor3f(1.0,0.0,0.0);																				// To remove traces
glBegin(GL_LINES);
glVertex2f(360,260);
glVertex2f(360,285);
glEnd();
glFlush();



glColor3f(0.0,1.0,0.0);																				// sliding the window and becoming green
slide(2,2,65,260);
glEnd();
	glFlush();

glColor3f(0.0,0.0,1.0);																				// sliding the window and becoming green
slide(1,2,300,260);
glEnd();
	glFlush();

move2();

	setFont(GLUT_BITMAP_HELVETICA_12);

	glColor3f(1.0,1.0,1.0);
	drawstring(69,268.0,0.0," 1");
	glColor3f(1.0,1.0,1.0);
	drawstring(320,268.0,0.0,"1");



glColor3f(0.0,0.0,1.0);																				// sliding the window and becoming blue
slide(2,2,50,260);
glEnd();
	glFlush();

glColor3f(0.2,0.0,0.7);
    glBegin(GL_LINE_LOOP);																			 // To remove initial WHITE window trace
		glVertex2f(50,255);
	    glVertex2f(50,290);
		glVertex2f(110,290);
		glVertex2f(110,255);
    glEnd();
	glFlush();

	glColor3f(1.0,0.0,0.0);																			// sliding the window and becoming blue
 slide(2,2,110,260);
glBegin(GL_LINES);
glVertex2f(110,260);
glVertex2f(110,285);
glEnd();
	glFlush();



glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);																			 // moving the reciever window in WHITE color
		glVertex2f(65,255);
	    glVertex2f(65,290);
		glVertex2f(125,290);
		glVertex2f(125,255);
    glEnd();
	glFlush();



glColor3f(0.0,0.0,1.0);																				//to remove traces
glBegin(GL_LINES);
glVertex2f(50,260);
glVertex2f(50,285);
glEnd();
glFlush();


glColor3f(0.2,0.0,0.7);
    glBegin(GL_LINE_LOOP);																			 // moving the reciever window in WHITE color
		glVertex2f(315,255);
	    glVertex2f(375,255);
		glVertex2f(375,290);
		glVertex2f(315,290);
    glEnd();
	glFlush();

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(315,260);
	glVertex2f(315,285);
	glVertex2f(375,260);
	glVertex2f(375,285);
	glEnd();
	glFlush();

	glColor3f(0.0,0.0,1.0);																			// sliding the window and becoming green
slide(3,2,300,260);
glEnd();
	glFlush();



glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);																			 // moving the reciever window in WHITE color
		glVertex2f(330,255);
	    glVertex2f(330,290);
		glVertex2f(390,290);
		glVertex2f(390,255);
    glEnd();
	glFlush();


glColor3f(1.0,0.0,0.0);																				// sliding the window and becoming green
slide(2,2,375,260);
glEnd();
	glFlush();


	move12();

	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0f,1.0f,1.0f);
    drawstring(280.0,163.0,1.0,"ACK 2 lost");


		glColor3f(0.0,1.0,1.0);																		//packet crashing
	glBegin(GL_POLYGON);
	glVertex2f(240,168);
	glVertex2f(255,168);
	glVertex2f(260,178);
	glVertex2f(265,168);
	glVertex2f(280,168);
	glVertex2f(267.5,163);
	glVertex2f(280,153);
	glVertex2f(260,163);
	glVertex2f(240,153);
	glVertex2f(252.5,163);
	glEnd();
	glFlush();




	glColor3f(0.2,0.0,0.7);																			//to remove traces
	glBegin(GL_TRIANGLES);
	glVertex2f(240,168);
	glVertex2f(260,178);
	glVertex2f(255,168);
    glEnd();
	glFlush();

    glBegin(GL_TRIANGLES);
	glVertex2f(240,168);
	glVertex2f(252.5,163);
	glVertex2f(240,153);
	glEnd();
	glFlush();

glColor3f(0.0,1.0,0.0);																				// sliding the window and becoming green
slide(2,2,80,260);
glEnd();
	glFlush();

		glColor3f(0.2,0.0,0.7);
    glBegin(GL_POLYGON);																			// moving the reciever window in WHITE color
		glVertex2f(358,120);
	    glVertex2f(358,130);
		glVertex2f(485,130);
		glVertex2f(485,120);
    glEnd();
	glFlush();


    move14();

	setFont(GLUT_BITMAP_HELVETICA_12);

	glColor3f(1.0,1.0,1.0);
	drawstring(334,268.0,0.0,"2");
		setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(0.2f,0.0f,0.7f);
    drawstring(280.0,163.0,1.0,"ACK 2 lost");


	glColor3f(0.2,0.0,0.7);
    glBegin(GL_POLYGON);																			 // moving the reciever window in WHITE color
		glVertex2f(98,100);
	    glVertex2f(98,112);
		glVertex2f(225,112);
		glVertex2f(225,100);
    glEnd();
	glFlush();


glColor3f(0.2,0.0,0.7);
    glBegin(GL_LINE_LOOP);																			// moving the reciever window in WHITE color
		glVertex2f(330,255);
	    glVertex2f(330,290);
		glVertex2f(390,290);
		glVertex2f(390,255);
    glEnd();
	glFlush();


glColor3f(0.0,0.0,1.0);																				// sliding the window and becoming green
slide(4,2,300,260);
glEnd();
	glFlush();


glColor3f(1.0,0.0,0.0);																				// sliding the window and becoming green
slide(2,2,390,260);
glEnd();
	glFlush();


	glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);																			 // moving the reciever window in WHITE color
		glVertex2f(345,255);
	    glVertex2f(345,290);
		glVertex2f(405,290);
		glVertex2f(405,255);
    glEnd();
	glFlush();


	glColor3f(0.2,0.0,0.7);																			//packet crashing
	glBegin(GL_POLYGON);
	glVertex2f(240,168);
	glVertex2f(255,168);
	glVertex2f(260,178);
	glVertex2f(265,168);
	glVertex2f(280,168);
	glVertex2f(267.5,163);
	glVertex2f(280,153);
	glVertex2f(260,163);
	glVertex2f(240,153);
	glVertex2f(252.5,163);
	glEnd();
	glFlush();

move13();
setFont(GLUT_BITMAP_HELVETICA_12);
	glColor3f(1.0,1.0,1.0);
	drawstring(55,268.0,0.0,"0");
	glColor3f(1.0,1.0,1.0);
	drawstring(69,268.0,0.0," 1");
	glColor3f(1.0,1.0,1.0);
	drawstring(84,268.0,0.0," 2");
	glColor3f(1.0,1.0,1.0);
	drawstring(349,268.0,0.0,"3");


glColor3f(0.2,0.0,0.7);
    glBegin(GL_LINE_LOOP);																			 // moving the reciever window in WHITE color
		glVertex2f(65,255);
	    glVertex2f(65,290);
		glVertex2f(125,290);
		glVertex2f(125,255);
    glEnd();
	glFlush();

	glColor3f(0.0,0.0,1.0);																			// sliding the window and becoming green
slide(4,2,50,260);
glEnd();
	glFlush();

glColor3f(1.0,0.0,0.0);																				 // sliding the window and becoming green
slide(5,2,95,260);
glEnd();
	glFlush();


	glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);																			 // moving the reciever window in WHITE color
		glVertex2f(95,255);
	    glVertex2f(95,290);
		glVertex2f(155,290);
		glVertex2f(155,255);
    glEnd();
	glFlush();



}

void output(int x, int y, char *string)
{
  int len, i;

  glRasterPos2f(x, y);
  len = (int) strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
  }
}

void send_options(void)																				// to draw the text in menu screen
{
	glClear(GL_COLOR_BUFFER_BIT);
	computers();
	drawop(0,0);
	drawop(100,0);
	drawop(200,0);
	drawop(300,0);
	drawop(0,40);
	drawop(100,40);
	drawop(200,40);
	drawop(300,40);
	drawop(100,80);
	drawop(200,80);

	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(0.98392,0.49,0.0);
	drawstring(180.0,185.0,1.0,"SENDING OPTIONS(select any one)");

	glColor3f(1.0,1.0,1.0);
	drawstring(67.5,305.0,1.0,"Press A for 1-2");

	glColor3f(1.0,1.0,1.0);
	drawstring(167.5,305.0,1.0,"Press B for 1-3");

	glColor3f(1.0,1.0,1.0);
	drawstring(267.5,305.0,1.0,"Press C for 1-4");

	glColor3f(1.0,1.0,1.0);
	drawstring(367.0,305.0,1.0,"Press D for 1-5");

	glColor3f(1.0,1.0,1.0);
	drawstring(67.5,265.0,1.0,"Press F for 2-3");

	glColor3f(1.0,1.0,1.0);
	drawstring(167.5,265.0,1.0,"Press G for 2-4");

	glColor3f(1.0,1.0,1.0);
	drawstring(267.5,265.0,1.0,"Press H for 2-5");

	glColor3f(1.0,1.0,1.0);
	drawstring(367.5,265.0,1.0,"Press I for 3-4");

	glColor3f(1.0,1.0,1.0);
	drawstring(167.5,225.0,1.0,"Press J for 3-5");

	glColor3f(1.0,1.0,1.0);
	drawstring(267.5,225.0,1.0,"Press K for 4-5");

	glFlush();
}



void menuSelect(int value)
{
  switch (value)
  {
	  case mainmenu:
      text();
	  break;
    case sendwindow:
      draw1();
	  draw6();
      break;

	case sendop:
      send_options();draw6();
      break;

	case one:
      draw3(0,0);
      break;

	case two:
      draw3(0,100);
      break;

	case three:
      draw3(0,200);
      break;

	case four:
      draw3(0,300);
      break;

	case five:
      draw3(100,100);
      break;

	case six:
      draw3(100,200);
      break;

	case seven:
      draw3(100,300);
      break;

	case eight:
      draw3(200,200);
      break;

	case nine:
      draw3(200,300);
      break;

	case ten:
      draw3(300,300);
      break;
    case receivewindow:
      draw2();draw6();
      break;

    case safesending:
      send_options();draw6();
      break;

    case packetcrashing:
      draw4(100,300);delay();draw6();;
	  break;

	case timeout:
      draw5(0,300);
	  break;

  }


}


void mykeyboard(unsigned char key,int x,int y)
{

	switch(key)
	{	case 'e':
		case 'E':exit(0);			break;
		case 's':
		case 'S':send_options();draw6();break;//draw3();			delay();break;	//safe sending
	    case 'a':
		case 'A':draw3(0,0);delay();draw6();break;
		case 'b':
		case 'B':draw3(0,100);delay();draw6();break;
		case 'c':
		case 'C':draw3(0,200);delay();draw6();break;
		case 'd':
		case 'D':draw3(0,300);delay();draw6();break;
		case 'f':
		case 'F':draw3(100,100);delay();draw6();break;
		case 'g':
		case 'G':draw3(100,200);delay();draw6();break;
		case 'h':
		case 'H':draw3(100,300);delay();draw6();break;
		case 'i':
		case 'I':draw3(200,200);delay();draw6();break;
		case 'j':
		case 'J':draw3(200,300);delay();draw6();break;
		case 'k':
		case 'K':draw3(300,300);delay();draw6();break;
		case 'w':
		case 'W':draw1();draw6();break;	//send window
		case 'r':
		case 'R':draw2();delay();draw6();break;	//receive window
		case 'p':
		case 'P':draw4(100,300);delay();draw6();break;	//packet crashing
		case 't':
		case 'T':draw5(0,300);delay();draw6();break;	//time out*/
		case 'y':
		case 'Y':text();break;
		case 'n':
		case 'N':exit(0);
		case 'm':
		case 'M':flag=1;glutPostRedisplay();break;
		default:return;
	}

	//glutPostRedisplay();
}


void myInit()
{
    glClearColor(0.2,0.0,0.7,0.0);
	glColor3f(0.2f,0.0f,0.7f);
	glPointSize(5.0);
	gluOrtho2D(0.0,500.0,0.0,500.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

}
void display(void)
{		glClear(GL_COLOR_BUFFER_BIT);
	if(flag==0)
	{title();}

	//delay();
	//delay();
	if(flag==1) {text();}

}

int main(int argc, char ** argv)
{
	 int fillmenu = 0;
//	printf("-----------------------\n enter a message less than ten characters\n-----------------------\n ");
//		gets(E);
	//	printf("\n-----------------------\n");
//	if(strlen(E)>10)
//	{
	//	printf("message length exceeded \n\n\n");
		//main();
	//	exit(0);
//	}
 f1=fopen("input.txt","r");

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
  	glutInitWindowPosition(0,0);
	glutInitWindowSize(1000,650);
	
	glutCreateWindow("Selective Repeat ARQ");
		glutKeyboardFunc(mykeyboard);
    glutDisplayFunc(display);


	myInit();
  fillmenu = glutCreateMenu(menuSelect);
  glutAddMenuEntry("sendop", sendop);
  glutAddMenuEntry("from1-2", one);
  glutAddMenuEntry("from1-3", two);
  glutAddMenuEntry("from1-4", three);
  glutAddMenuEntry("from1-5", four);
  glutAddMenuEntry("from2-3", five);
  glutAddMenuEntry("from2-4", six);
  glutAddMenuEntry("from2-5", seven);
  glutAddMenuEntry("from3-4", eight);
  glutAddMenuEntry("from3-5", nine);
  glutAddMenuEntry("from4-5", ten);

  glutCreateMenu(menuSelect);
  glutAddMenuEntry("Back To Main Menu", mainmenu);
  glutAddMenuEntry("sendwindow", sendwindow);
  glutAddMenuEntry("receivewindow", receivewindow);
  glutAddSubMenu("safesending", fillmenu);
  glutAddMenuEntry("packetcrashing",packetcrashing );
  glutAddMenuEntry("timeou",timeout);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
  glutMainLoop();


}
