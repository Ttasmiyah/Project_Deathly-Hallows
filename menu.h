
#define MENU_H_INCLUDED
//mode=14 -the game will start
//drawMenuBox()-condition for the boxes
//menu()- menu screen setting with the images and boxes

int mode=14; 
	
int mposx,  mposy;

void drawMenuBox(int x_co , int y_co , int box_len , int box_wid) //this is the co-ordinates and width length position setting condition for the boxes
{
	if(mposx >= x_co && mposx <= x_co + box_len && mposy >= y_co && mposy <= y_co + box_wid)
	iSetColor(60,160,100);
	else
	iSetColor(60,200,100);
	iFilledRectangle(x_co , y_co , box_len , box_wid);
}
 void menu() 
 { 

 if(mode == 4)
	{
		iClear();
		iSetColor(255 , 255 , 255);
		iFilledRectangle(0 , 0 , 900, 600);
		
		iShowBMP(0 , 0,"images\\1b.bmp");
		iShowBMP2(70,0,"dth.bmp",0);

		drawMenuBox(675, 200, 200, 50); //this is the box position for 'newgame' box
		iSetColor(0,0,0);
		iText(715, 215 , "New Game ",GLUT_BITMAP_HELVETICA_18);

		drawMenuBox(675, 140, 200, 50); //this is the box position for 'instruction' box
		iSetColor(0,0,0);
		iText(715, 155 , "Instructions ",GLUT_BITMAP_HELVETICA_18);

		drawMenuBox(675, 400, 200, 50); //this is the box position for 'story' box
		iSetColor(0,0,0);
		iText(715, 415 , "Story",GLUT_BITMAP_HELVETICA_18);

		drawMenuBox(675, 80, 200, 50); //this is the box position for 'highscore' box
		iSetColor(0,0,0);
		iText(715, 95 , "High Score ",GLUT_BITMAP_HELVETICA_18);

		drawMenuBox(675, 20, 200, 50); //this is the box position for 'exit' box
		iSetColor(0,0,0);
		iText(750, 35 , "Exit ",GLUT_BITMAP_HELVETICA_18);

		
	}
 }
