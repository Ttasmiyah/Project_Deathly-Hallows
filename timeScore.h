#include <stdio.h>

struct savedScores{
	int time;
	char pl[30];
}sc[5], tempSc;

int tm=0;
char timeSc[20];
char player[30];
int ind=0;
int ghoriFl;
FILE* highScoreFile;

//ghori() - this is for printing the time on screen and continuously adding seconds
//updateHighScore()- this is for making a file and keeping the player name and time score in that file within 5 players
//showHighScore()- in this function the file is being opened again and the player names and scores are kept in order in the highscore screen in menu
                     
void ghori(){ //function for timer
	tm++;
	sprintf(timeSc, "Time: %d", tm); //for prnting the timer in the gamescreen
	
}

void updateHighScore()
{
	iPauseTimer(ghoriFl);
	highScoreFile = fopen("highScore.txt", "r");
	int i=0, j;
	while(fscanf(highScoreFile ,"%s %d", &sc[i].pl, &sc[i].time)!=EOF)
	{
		i++;
	}
	fclose(highScoreFile); 
	for(i=0; i<5; i++)
	{
		if(tm<sc[i].time)
		{
			for(j=4; j>i; j--)
			{
				sc[j]=sc[j-1];
			}
			sc[i].time=tm;
			strcpy(sc[i].pl, player);
			break;
		}
	}
	highScoreFile = fopen("highScore.txt", "w");
	for(i=0; i<5; i++)
	{
		fprintf(highScoreFile,"%s %d\n", sc[i].pl, sc[i].time);
	}
	fclose(highScoreFile);

}
void showHighScore()
{
	highScoreFile = fopen("highScore.txt", "r");
	int i=0, j;
	while(fscanf(highScoreFile ,"%s %d", &sc[i].pl, &sc[i].time)!=EOF)
	{
		i++;
	}
	fclose(highScoreFile);
	char Score[5][100];
	for(i=0; i<5; i++)
	{
		sprintf(Score[i], "%s -                                         %d", sc[i].pl, sc[i].time);
	}
	iText(133, 500, Score[0]);
	iText(133, 426, Score[1]);
	iText(133, 350, Score[2]);
	iText(133, 274, Score[3]);
	iText(133, 200, Score[4]);
}