# include "level1.h"

//mode_8() congratulation screen showing
//iShowBMP2() and iShowBMP() show some picture or character on the screen
//iText() to write something on the screen
//x - enemyship x cord, y- enemyship y cord ,sp - speed of enemy
//enSh[10]-structure array for 10 enemyship
//createShips() - to show the enemyship randomly on the screen
//shipAttack() - for the collision between the ship and enemy
//                 and collecting the stone

int shipX=420, shipY=50;
void mode_8() 
{
	if(mode==8){
		PlaySound(0,0,0);
		iClear();
	    iShowBMP2(0,0,"stonet.bmp",0);
		iShowBMP(0,100,"stone.bmp");
		iText(850,25,"Press n to go to next level", GLUT_BITMAP_HELVETICA_18);
	}
	
}
struct enemyShip{
	int x, y, sp;
}enSh[10];

void createShips(){
	int i;
	for(i=0; i<10; i++){
		enSh[i].x = rand()%750;// always greater than 200;
		enSh[i].y=700;
		enSh[i].sp=rand()%9+7;
	}
}

void shipAttack(){ 
	if(mode==3){
		int i;
	for(i=0; i<10; i++){
		enSh[i].y-=enSh[i].sp;
		 if(enSh[i].y<=shipY+50 && enSh[i].y+50>=shipY && enSh[i].x<=shipX+70 && shipX<=enSh[i].x+70) //collision
		
		{
			iClear();
			i=0;
			mode=2;
		}
		if(enSh[i].y<=0){
			enSh[i].x=rand()%800;
			enSh[i].y=600;
			
		}
	}
	if(shipX>=800 && shipX<=865 && shipY>=600 && shipY<=665) //collecting stone
	{
		iClear();
		mode=8;
		iPauseTimer(ghoriFl);
	}
	}
}

//draw2()- showing the enemy character dementor by a restriction
//iShowBMP2() and iShowBMP() show some picture or character on the screen
//iText() to write something on the screen


void draw2(){
	iClear();
	

	iShowBMP(0,0,"images\\sand.bmp");
	iShowBMP(900,0,"images\\sand.bmp");
	iShowBMP2(200,0,"images\\sea.bmp",0);
	iShowBMP2(800,600,"images\\stone.bmp",0);
	
	iDelayMS(50);
	
	iShowBMP2(shipX, shipY, "images\\ship.bmp", 0);
	int i;
	for(i=0; i<10; i++)
	{
		if(enSh[i].x >= 200 && enSh[i].x <= 800) //dementor restriction
			
			iShowBMP2(enSh[i].x,enSh[i].y, "images\\dementor.bmp",0);
	}

	iText(400,600,"Collect The Stone And Escape!!",GLUT_BITMAP_HELVETICA_18);
	iSetColor(128, 0, 64);
	iText(500,650,"LEVEL 2", GLUT_BITMAP_HELVETICA_18);
	printf("%s\n", timeSc);//time
	iText(50,655,timeSc, GLUT_BITMAP_HELVETICA_18);
	
	
}