/*
    Original Author: S. M. Shahriar Nirjon
    Last Modified by: Mohammad Saifur Rahman
    last modified: October 13, 2015
    Version: 2.0
*/

# include "iGraphics.h"
# include "bitmap_loader.h"
# include "level3.h"
#include "music.h"



//function iDraw() is called again and again by the system.

//mode_14() start screen
//prevMenu_1() to go back to main menu
// mode_1()-All the functions and logic of level 1 are in the level1 header file
// drawing()-every drawings and logical functions of level 1 
//mode_3() All the functions and logic of level 2 are in the level2 header file
//draw2() every drawings and logical functions of level 2 
//mode_4()-menu of the game
//menu()- all the functions and logic of menu in the menu header file
//mode_9()-All the functions and logic of level 3 are in the level3 header file
//playLevel3()-to play  level3
//mode_5()  instruction of the game.It's in the menu bar.
//mode_6() highscore of the game.It's in the menu bar.
//highScore() functions of highscore 
//mode_13() story of the game which is in the menu bar.

void mode_14() //start screen
{
	if(mode==14)
	{ 
	iText(900,20, "Press 'n' to start");	
	iShowBMP(250,0,"start.bmp");
	}
}
	
void highScore() 
{
	iShowBMP(0,0, "images\\hhScore.bmp");
	iSetColor(255 , 255, 255);

	iText(100 , 600, "MASTER OF DEATH", GLUT_BITMAP_TIMES_ROMAN_24);

	iText(500 , 600, "TIME", GLUT_BITMAP_TIMES_ROMAN_24);
	showHighScore();
}

void prevMenu_1() 
{
	iSetColor(255,255,255);
	iText(900,35,"Press b to go back", GLUT_BITMAP_HELVETICA_18);

}


void mode_1() //for level 1
{
	if(mode==1) 
	{
	  
	   drawing(); 
	   prevMenu_1();
	}
	
}

void mode_3() //for level 2
{
	
	if(mode==3)
		draw2(); 
}

void mode_4() //for menuscreen
{
	if(mode==4) 
		menu(); 
}


void mode_9()  //for level 3
{
	if(mode==9) 
	{
		iClear();
		playLevel3();
		
	}
}

void mode_5()  //for instruction screen
{
	if(mode==5) 
	{
		iClear();
		iShowBMP(0,0,"images\\instruction.bmp");
		prevMenu_1();
	}
}


void mode_6() //for setting highscore
{
	if(mode == 6) 
	{
		iClear();
		highScore(); 
		prevMenu_1();
	}
	
}
void mode_13() //for story screen
{
	if(mode==13) 
	{

	iClear();
    iShowBMP(0,0,"images\\story.bmp");
	prevMenu_1();
	}

}

//inGame() contains all the modes of game
//iDraw() the main function of the game.this will call the whole part of drawing of the game.
/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
//mode==9 - the logical part for the mouse movement of level 3


void inGame() 
{
	mode_1(); //this is for level1
	mode_2(); //this is for gameover screen
	mode_3(); //this is for level2
	mode_5(); //this is for instruction screen
	mode_4(); //this is for menu
	mode_6(); //this is for highscore screen
	mode_7(); //this is for level1 change screen
	mode_8(); //this is for level 2 change screen
	mode_9(); //this is for level3
	mode_10(); //this is for spell finding screen
	mode_11(); // this is for wand part after completing level 3
	mode_12(); //this screen is for end part of the game
	mode_13(); //this is for story screen
	mode_14(); //this is for start screen

	

}




void iDraw() 
{
	
	inGame();

}

void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		if(mx >= 675 && mx <= 875 && my >= 200 && my <= 250 && mode == 4) 
		{
			int gh_x=255; 
            int dghx=20; 
            int dgh2y=10; 
            int i;
            int j;
            flagCloak=0;
            int gh2_y=260;
            int dgh3y =10; 
            int gh3_y= 169; 
			tm=0;
			mode = 1;
			PlaySound(0,0,0);
		    PlaySound("music\\tokyo.wav", NULL,SND_LOOP|SND_ASYNC);
			iResumeTimer(ghoriFl); //this will start counting time
		}

		if(mx >= 675 && mx <= 875 && my >= 140 && my <= 190 && mode == 4) //mouse movement for instruction screen in menu
		{
			mode = 5;
		}

		if(mx >= 675 && mx <= 875 && my >= 20 && my <= 70 && mode == 4) //mouse movement for ending the game screen
		{
			exit(0);
		}

		if(mx >= 675 && mx <= 875 && my >= 80 && my <= 130 && mode == 4) //mouse movement for 'highscore' screen in menu
		{
			mode = 6 ;
		}

		if(mx >= 675 && mx <= 875 && my >=400 && my <= 450 && mode == 4) //mouse movement for 'story' screen in menu
		{
			mode = 13;
		}
		if(mode==9) //this is the logical part for the mouse movement of level 3
		{
			int i=0, j=0;
			for(i=0; i<10; i++)
			{
				if(strcmp(tl[i].tiles, "0.bmp")==0)
				{
					j=i;
					break;
				}
			}
			printf("%d %d %d %d\n", mx, my, tl[i].x, tl[i].y);
			if(mx<=tl[i].x+400 && mx>=tl[i].x+200 && my<=tl[i].y+200 && my>=tl[i].y)
			{
				for(j=0; j<10; j++)
				{
					if(mx<=tl[j].x+200 && mx>=tl[j].x && my<=tl[j].y+200 && my>=tl[j].y)
					{
						break;
					}
				}	
			}
			else if(mx<=tl[i].x && mx>=tl[i].x-200 && my<=tl[i].y+200 && my>=tl[i].y)
			{
				for(j=0; j<10; j++)
				{
					if(mx<=tl[j].x+200 && mx>=tl[j].x && my<=tl[j].y+200 && my>=tl[j].y)
					{
						break;
					}
				}
			}
			else if(mx<=tl[i].x+200 && mx>=tl[i].x && my<=tl[i].y+400 && my>=tl[i].y+200)
			{
				for(j=0; j<10; j++)
				{
					if(mx<=tl[j].x+200 && mx>=tl[j].x && my<=tl[j].y+200 && my>=tl[j].y)
					{
						break;
					}
				}
			}
			else if(mx<=tl[i].x+200 && mx>=tl[i].x && my<=tl[i].y && my>=tl[i].y-200)
			{
				for(j=0; j<10; j++)
				{
					if(mx<=tl[j].x+200 && mx>=tl[j].x && my<=tl[j].y+200 && my>=tl[j].y)
					{
						break;
					}
				}
			}
			if(j!=10)
			{
				strcpy(temp.tiles, tl[i].tiles);
				strcpy(tl[i].tiles, tl[j].tiles);
				strcpy(tl[j].tiles, temp.tiles);
			}
		}
	}
		
		

	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
	//place your code here

 mposx = mx;
 mposy = my;
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
//by pressing 'b' menu screen will appear
//by pressing 'n' level 1 will finish and level 2 will appear, when mode=7
//iResumeTimer(ghoriFl) for resuming timer
//by pressing 'n' level 2 will finish and level 3 will appear, when mode=8
//by pressing 'n' level 3 spell found screen will disappear and wand getting screen will appear, when mode=10
//mode=11  spell using screen
//by pressing 'n' spell finding screen will disappear and end screen will appear, when mode=11
//mode=12  is for ending part screen
//by pressing 'o' music will be turned off
//PlaySound(0,0,0)  will stop playing music
//by pressing 's' music will be turned on
//by pressing 'e' spell sound will be turned on
void iKeyboard(unsigned char key)
{
	if(mode==12)
	{
		if(key=='\b')
		{
			if(ind>0)ind--;
			player[ind]='\0';
		}
		else if(key=='\r')
		{
			player[ind]='\0';
			updateHighScore();
			mode=6;
		}
		else
		{
			player[ind]=key;
			ind++;
		}
	}
	if(mode!=12 && key == 'b') 
	{
		PlaySound(0,0,0);
		PlaySound("music\\hpmldy.wav", NULL,SND_LOOP|SND_ASYNC);
		mode=4;
	}
	


	if(mode!=12 && key== 'n') 
	{
		if(mode==14){
			mode=4;}
		if(mode==7)
		{
		   int shipX=420, shipY=50;
		   PlaySound(0,0,0);
		   PlaySound("music\\pirate.wav", NULL,SND_LOOP|SND_ASYNC);
		   mode=3;
		   iResumeTimer(ghoriFl); 
		}
		if(mode==8) 
		{
           PlaySound(0,0,0);
		   PlaySound("music\\titanium.wav", NULL,SND_LOOP|SND_ASYNC);
		   mode=9;
		   iResumeTimer(ghoriFl); 
		}
		if(mode==10) 
		{
			PlaySound(0,0,0);
			PlaySound("music\\hp_piano.wav", NULL,SND_LOOP|SND_ASYNC);
			mode=11; 
			
		}
		else if(mode==11)
		{
			PlaySound(0,0,0);
			PlaySound("music\\hp_piano.wav", NULL,SND_LOOP|SND_ASYNC);
			mode=12; 
			
		}
		
	}	
	
	if(key=='o') 
	{
		musicOn= false; //the boolean value is initialized as false
		if(!musicOn){
			PlaySound(0,0,0); 
		
		}
	}
	if(key=='s'){ 
		musicOn=true; //the boolean value is initialized as true
		if(musicOn && mode==4){ 
			PlaySound("music\\hpmldy.wav", NULL,SND_LOOP|SND_ASYNC); //in menu different music will be played
			
		}
		else if(musicOn && mode==1){
			PlaySound("music\\tokyo.wav", NULL,SND_LOOP|SND_ASYNC); //in level 1 different music will be played
		}
		else if(musicOn && mode==3){
			PlaySound("music\\pirate.wav", NULL,SND_LOOP|SND_ASYNC); //in level 2 different music will be played
		}
		else if(musicOn && mode==9){
			PlaySound("music\\titanium.wav", NULL,SND_LOOP|SND_ASYNC); //in level 3 different music will be played
		}
		else if(musicOn && mode==10){
			PlaySound("music\\hp_piano.wav", NULL,SND_LOOP|SND_ASYNC); //for spell using screen
		}
		else if(musicOn && mode==11){
			PlaySound("music\\expelliarmus.wav", NULL,SND_ASYNC); //for spell using screen
		}
	}
	if(key== 'e'){
		if(mode==11){ 
		   PlaySound("music\\expelliarmus.wav", NULL,SND_ASYNC); 
		}

	}
	//place your codes for other keys here
}


/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
//at level 1, right arrow click wll move the ball to right side
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}

	if(key == GLUT_KEY_RIGHT  && mode==1) 
	{
		i+=10;
		if(39+i>679)
	{
		i-=10; //for boundary
	}
		RightxRestricted(); //right restriction boundary function for the maze lines
	}

	
	if(key == GLUT_KEY_LEFT  && mode==1)
	{
		i-=10;
		
		if(39+i>=400 && 39+i<=430 && 35+j>=300 && 35+j<=330 && (39+i)>=400 && (39+i)<=430 && (35+j)>=300 && (35+j)<=330)
			flagCloak=1; //this is for reaching the cloak at left side and when the ball will reach the cloak, the cloak will disappear.
			
		if((39+i)<19)
		{
			i+=10;
		}
		LeftxRestricted(); //left restriction boundaries function for the maze lines

	}
	if(key == GLUT_KEY_UP && mode==1)
	{
		if(35+j<=670)j+=10;
		

		UpyRestricted();//upper restriction boundaries function for the maze lines
	}
	if(key == GLUT_KEY_DOWN && mode==1)
	{
		j-=10;
		//printf("%d",35+j);
		if((35+j)<20)
	{
		j+=10;
	}
		
		DownyRestricted(); //down restriction boundaries function for the maze lines
	}

	if(key == GLUT_KEY_RIGHT  && mode==3) //level 3 arrow movements
	{
		if(shipX<=815)shipX+=20; //inside the level 2 screen boundary,right side movement of ship in x-co ordinate
	}

	
	if(key == GLUT_KEY_LEFT  && mode==3)
	{ 
		if(shipX>=205)shipX-=20;  //inside the level 2 screen boundary, left side movement of ship in x-co ordinate
	}
	if(key == GLUT_KEY_UP && mode == 3) //moving up
	{
		if(shipY < 650)
		{
			shipY += 15; //inside the level 2 screen boundary, upper side movement of ship in y-co ordinate
		}
	}
	
	if(key == GLUT_KEY_DOWN && mode == 3) //moving down
	{
		if(shipY > 0)
		{
			shipY -= 15; //inside the level 2 screen boundary,downward movement of ship in y-co ordinate
        }
	}
	//place your codes for other keys here
}
//genLevel3()  function call for generating level 3
//music() function call is for playing music
//flagCloak=0 for appearing the cloak on level 1 screen
//iSetTimer()  ghosts movement speed 
//createShips() function call of level 3 for creating the enemies
//iPauseTimer() to pause the time
int main()
{
	//place your own initialization codes here.
	
	genLevel3(); 
	i=0;
	j=0;
	music(); 
	
	flagCloak=0; 
	iSetTimer(200,ghmove);
	iSetTimer(200,gh2move);  
	iSetTimer(200,gh3move);

    createShips();
	iSetTimer(50, shipAttack);

	ghoriFl=iSetTimer(1000,ghori); //setting the timer for seconds
	iPauseTimer(ghoriFl);
	
	iInitialize(1100, 700, "Deathly Hallows");
	iStart();
	return 0;
}
