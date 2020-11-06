


#define LEVEL1_H_INCLUDED

# include "menu.h"
# include "timeScore.h"

//gh_x,gh2_y,gh3_y initial place of ghost 
//dghx,dgh2y,dgh3y movement space of ghost
//i,j for ball x and y cord movement
//flagCloak for appearing the cloak on level 1 screen
//mode_7() screen setting for level 1 completing
//mode_2() game over screen setting when ghost will eat the ball
 //ghmove() functions for the movement conditions of ghosts

int gh_x=255; 
int dghx=20; 
int dgh2y=10; 
int i;
int j;
int flagCloak=0;
int gh2_y=260;

int dgh3y =10; 
int gh3_y= 169; 



void mode_7() 
{
	if(mode==7){ 
		PlaySound(0,0,0);
		iClear();
	    iShowBMP2(0,0,"cgtt.bmp",0);
		iShowBMP(0,100,"cgt.bmp");
		iText(850,25,"Press n to go to next level", GLUT_BITMAP_HELVETICA_18);
	}
	
}
void mode_2() 
{
	if(mode==2){
	iShowBMP(0,0,"gmover.bmp");
	iText(850,35,"Press b to go back to menu", GLUT_BITMAP_HELVETICA_18);
	iSetColor(255,0,0);
	}
	


}

void ghmove(){  
	if(mode==1){
	gh_x += dghx; //in x co-ordinate it will add dghx=20
	

	if(gh_x > 450 || gh_x <250 ) //boundary setting for ghost 1 movement
		{
			dghx = -dghx; //after reaching boundary, it will come back dghx=20
	    }
	
	}
}
void gh2move(){ 
	if(mode==1){
	gh2_y += dgh2y;
	
	if(gh2_y >455 || gh2_y< 240 ) //boundary setting for ghost 2 movement
		{
			dgh2y = -dgh2y;
	}
	}
}

void gh3move(){
	if(mode==1){
	gh3_y += dgh3y;
	
	if(gh3_y <75 || gh3_y> 295 )  //boundary setting for ghost 3 movement
		{
			dgh3y = -dgh3y;
	}
	}
}

// BallMove() for creating the ball which will take the cloak
//RightxRestrict()  =conditions of rightside boundaries restriction
//LeftxRestrict()  =conditions of lefttside boundaries restriction
//UpyRestrict()  =conditions of upward boundaries restriction
//DownyRestrict()  = conditions of downward boundaries restriction

void BallMove(int dx,int dy) 
{
	
	iSetColor(0,255,255);
	iFilledCircle(39+dx,35+dy,18,70);

}

void RightxRestrict(int Rx,int Lx,int Uy,int Dy ) 
{
	if(39+i>Rx && 39+i<Lx && (35+j)<Uy && (35+j)>Dy)
	{
		i-=10;
	}
	
	
}
void LeftxRestrict(int lx,int rx,int ly,int ry) 
{
	if((39+i)<lx && (39+i)>rx  && (35+j)<ly && (35+j)>ry)
	{
		i+=10;
	}
}
void UpyRestrict(int Uy,int Dy,int Lx ,int Ly) 
{
	if((35+j)>Uy && (35+j)<Dy && (39+i)<Lx &&(39+i)>Ly)
	{
		j-=10;
	}
}

void DownyRestrict(int dy,int uy, int lx,int ly)
{ 
	if((35+j)<dy && (35+j)>uy && (39+i)<lx && (39+i)>ly)
	{
		j+=10;
	}
}

//drawing() =igraphical wrks and logics of level 1
//iClear() to clear the screen whenever required
//mode=2  showing game over screen 

void drawing() 
{
	iClear();
	iShowBMP(0,0,"lvl1b.bmp");
	//iFilledRectangle();
	if(flagCloak==1) //for removing the cloak when the ball will move on that
	{
		iClear();
		
	}
		iShowBMP(0,0,"lvl1b.bmp");
		BallMove(i,j);
	
	
	if((39+i)>=(gh_x+25) && (35+j)<55) //conditions when ghost1 will eat the ball
	{
		iClear();
		i=0;
		j=0;
		flagCloak=0;
		mode=2; 
		
	}
	//printf("%d %d %d\n", i, j, gh2_y);
	if((39+i)>=210 && (i<280) && (35+j)<gh2_y+50 &&  (35+j)>(gh2_y)) //conditions when ghost2 will eat the ball
	{
		iClear();
		
		i=0;
		j=0;
		flagCloak=0;
		mode=2; 
		
	}
	if((20+i)>=570 && (i<640) && (35+j)<gh3_y+50 &&  (20+j)>(gh3_y)) //cnditions when ghost3 will eat the ball
	{
		iClear();
		i=0;
		j=0;
		flagCloak=0;
		mode=2; 
		
	}

	if((39+i)>=60 && (39+i)<=100 && (35+j)>576  && flagCloak==1) //conditions when ball will take the cloak
	{
		iClear();
		i=0;
		j=0;
		//flagCloak=0;
		mode=7;
		iPauseTimer(ghoriFl);
		//mode=3;
	}
	
	iSetColor(255,255,255);

	//rectangle(1-27) drawing fuctions

	iFilledRectangle(0,55,300,5);//1

	iFilledRectangle(355,55,280,5);//2

	iFilledRectangle(630,55,5,300);//3

	iFilledRectangle(335,355,300,5);//4

	iFilledRectangle(335,295,5,60);//5

	iFilledRectangle(335,295,230,5);//6

	iFilledRectangle(565,235,5,65);//7

	iFilledRectangle(270,230,300,5);//8

	iFilledRectangle(270,230,5,400);//9

	iFilledRectangle(60,630,215,5);//10

	iFilledRectangle(60,144,5,430);//11

	iFilledRectangle(0,144,60,5);//12

	iFilledRectangle(60,574,150,5);//13

	iFilledRectangle(210,355,5,224);//14

	iFilledRectangle(120,355,95,5);//15

	iFilledRectangle(120,355,5,164);//16

	iFilledRectangle(120,295,95,5);//17

	iFilledRectangle(120,144,5,156);//18

	iFilledRectangle(210,160,5,139);//19

	iFilledRectangle(210,160,350,5);//20

	iFilledRectangle(560,105,5,60);//21

	iFilledRectangle(352,105,212,5);//22

	iFilledRectangle(354,54,5,56);//23

	iFilledRectangle(270,445,355,5);//24
	iFilledRectangle(330,520,300,5);//25

	iFilledRectangle(625,445,5,75);//26

	iFilledRectangle(330,520,5,300);//27


	//iShowBMP2() and iShowBMP() show some picture or character on the screen
	//iText() to write something on the screen
	//iSetColor() to set the color of something
	//RightxRestricted() boundaries restriction places for the rightside rectangles
	//LeftxRestricted() boundaries restriction places for the leftside rectangles
	//UpyRestricted() boundaries restriction places for the upward rectangles
	//DownyxRestricted() boundaries restriction places for the downward rectangles



	iShowBMP2(gh_x,0,"ghost.bmp",0);
	iShowBMP2(210,gh2_y,"ghost2.bmp",0);
	iShowBMP2(570,gh3_y,"ghost3.bmp",0);

	iShowBMP(60,576,"images.bmp");
	iText(400,650,"Collect The Cloak And Escape!!");
	iSetColor(206, 82, 24);
	iShowBMP2(620,140,"level1.bmp",0);
	
	if(flagCloak==0)iShowBMP(400,300,"cloak.bmp"); //when flagcloak=0, cloak will appear on screen
	iSetColor(206, 82, 24);
	printf("%s\n", timeSc);//time
	iText(50,655,timeSc, GLUT_BITMAP_HELVETICA_18);
}


void RightxRestricted() 
{
	
    RightxRestrict(324,654,80,35);
	RightxRestrict(614,654,380,35);
	RightxRestrict(334,379,130,35);
	RightxRestrict(334,584,130,85);
	RightxRestrict(539,584,185,85);
	RightxRestrict(189,584,185,140);
	RightxRestrict(189,234,320,140);
	RightxRestrict(99,234,320,275);
	RightxRestrict(99,144,320,125);
	RightxRestrict(44,84,600,125);
	RightxRestrict(314,654,380,335);
	RightxRestrict(314,359,380,275);
	RightxRestrict(314,589,320,275);
	RightxRestrict(544,589,320,210);
	RightxRestrict(249,589,255,210);
	RightxRestrict(249,294,655,210);
	RightxRestrict(39,294,655,610);
	RightxRestrict(39,234,600,555);
	RightxRestrict(194,234,600,335);
	RightxRestrict(99,234,380,335);
	RightxRestrict(99,144,540,335);
	RightxRestrict(249,649,470,425);
	RightxRestrict(604,649,545,425);
	RightxRestrict(309,649,545,500);
	RightxRestrict(309,354,1000,500);
}

void LeftxRestricted() 
{
	    LeftxRestrict(324,0,80,35);
		LeftxRestrict(84,0,165,125);
		LeftxRestrict(654,334,80,35);
		LeftxRestrict(654,614,380,35);
		LeftxRestrict(379,334,130,35);
		LeftxRestrict(584,334,130,85);
		LeftxRestrict(584,539,185,85);
		LeftxRestrict(584,189,185,140);
		LeftxRestrict(234,189,320,140);
		LeftxRestrict(234,99,320,275);
		LeftxRestrict(144,99,320,125);
		LeftxRestrict(84,44,600,125);
		LeftxRestrict(654,314,380,335);
		LeftxRestrict(359,314,380,275);

		LeftxRestrict(589,314,320,275);
		LeftxRestrict(589,544,320,210);
		LeftxRestrict(589,249,255,210);
		LeftxRestrict(294,249,655,210);
		LeftxRestrict(294,39,655,610);
		LeftxRestrict(234,39,600,555);
		LeftxRestrict(234,194,600,335);
		LeftxRestrict(234,99,540,335);
		LeftxRestrict(144,99,540,335);
		LeftxRestrict(649,249,470,425);
		LeftxRestrict(649,604,545,425);
		LeftxRestrict(649,309,545,500);
		LeftxRestrict(354,309,1000,500);
}

void UpyRestricted()
{ 
	    UpyRestrict(35,80,324,0);
		UpyRestrict(125,165,84,0);
		UpyRestrict(35,380,654,614);
		UpyRestrict(35,130,379,334);
		UpyRestrict(85,130,584,334);
		UpyRestrict(85,185,584,539);
		UpyRestrict(140,185,584,189);
		UpyRestrict(140,320,234,189);
		UpyRestrict(275,320,234,99);
		UpyRestrict(125,320,144,99);
		UpyRestrict(125,600,84,44);
		UpyRestrict(325,380,654,314);
		UpyRestrict(275,380,359,314);

        UpyRestrict(275,320,589,314);
		UpyRestrict(210,320,589,544);
		UpyRestrict(210,255,589,249);
		UpyRestrict(210,655,294,249);
		UpyRestrict(610,655,294,39);
		UpyRestrict(555,600,234,39);
		UpyRestrict(335,600,234,194);
		UpyRestrict(335,380,234,99);
		UpyRestrict(335,540,144,99);
		UpyRestrict(425,470,649,249);
		UpyRestrict(425,545,649,604);
		UpyRestrict(500,545,649,309);
		UpyRestrict(500,1000,649,309);
}

void DownyRestricted() 
{
	    DownyRestrict(80,35,324,0);
		DownyRestrict(80,35,654,334);
		DownyRestrict(380,35,654,614);
		DownyRestrict(130,35,379,334);
		DownyRestrict(130,85,584,334);
		DownyRestrict(185,85,584,539);
		DownyRestrict(185,140,584,189);
		DownyRestrict(320,140,234,189);
		DownyRestrict(320,275,234,99);
		DownyRestrict(320,125,144,99);
		DownyRestrict(606,125,84,44);
		DownyRestrict(380,325,654,314);
		DownyRestrict(380,275,359,314);
		DownyRestrict(320,275,589,314);
		DownyRestrict(320,210,589,544);
		DownyRestrict(255,210,589,249);
		DownyRestrict(655,210,294,249);
		DownyRestrict(655,610,294,39);
		DownyRestrict(600,555,234,39);
		DownyRestrict(600,335,234,194);
		DownyRestrict(380,335,234,99);
		DownyRestrict(540,335,144,99);
		DownyRestrict(470,425,649,249);
		DownyRestrict(545,425,649,604);
		DownyRestrict(545,500,649,309);
		DownyRestrict(1000,500,354,309);

}


	


	

