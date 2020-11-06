#include "level2.h"


//x, y- tiles x and y cord
//temp-temporary variable for swapping
//t[10]- allocating space for tiles
//tl[10]-10 tiles
//genLevel3()- creating a puzzle box,printing the numbers,copying the tiles to the allocating space
//mode_10()-to show the congrats3 image
//mode_11()-to show the wand image
//playLevel3()-comparing the tiles with its allocated place in a for loop and playing the game
//mode =10 -to show the congrats screen


struct tile{
	int x, y;
	char tiles[10];
}tl[10], temp;

char t[10];


void genLevel3()
{
	
	int i=0, k=0 ,j=0;
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			sprintf(t, "%d.bmp", k);
			strcpy(tl[k].tiles, t);
			tl[k].x=j*200+60; //200 for distance between the tiles && 60 for x nd y cord
			tl[k].y=i*200+60;
			k++;
		}
	}
}

void mode_10()
{
	if(mode==10)
	{
	   iClear();
	   iShowBMP(0,0, "congrats3.bmp");
	}
}
void mode_11()
{
	if(mode==11)
	{
	   iClear();
	   iShowBMP(0,0,"wand.bmp");
	   iSetColor(255,255,255);
	   iText(815, 50 , "Press 'e' to use the spell ",GLUT_BITMAP_HELVETICA_18);
	   iText(815, 30, "Then press 'n' to go next ",GLUT_BITMAP_HELVETICA_18);
	 
	}

}
void mode_12()
{
	if(mode==12)
	{
		iClear();
		iShowBMP(0,0,"mod.bmp");
		iSetColor(255,255,255);
		iShowBMP2(70,500,"END.bmp", 0);
		iText(100, 150, "Enter Name: ");
		iText(200, 150, player);
	}

}

void playLevel3()
{
	iClear();
	iShowBMP(0,0,"images\\b3.bmp");
	iShowBMP2(690,110,"level3.bmp",0);
	iText(750, 300 , "Spell:",GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP2(790,115,"spl.bmp",255);


	for(int i=0; i<9; i++)
	{
		iShowBMP(tl[i].x, tl[i].y, tl[i].tiles);
	}
	if(strcmp(tl[6].tiles, "1.bmp")==0 && strcmp(tl[7].tiles, "2.bmp")==0&& strcmp(tl[8].tiles, "3.bmp")==0 && 
		strcmp(tl[5].tiles, "4.bmp")==0 && strcmp(tl[4].tiles, "5.bmp")==0 && strcmp(tl[3].tiles, "6.bmp")==0 && 
		strcmp(tl[0].tiles, "7.bmp")==0 && strcmp(tl[1].tiles, "8.bmp")==0 && strcmp(tl[2].tiles, "0.bmp")==0)
	{
		
			
			mode=10;
	}
	
}
