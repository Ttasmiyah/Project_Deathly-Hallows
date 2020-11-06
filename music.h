
//music() -functions which will be called when the music plays
// mode==14 - start & menubar music 
// mode==1 - level 1 music
// mode==3 -level 2 music
// mode==9 - level 3 music
// mode==11 -spell using screen music

bool musicOn= true; //initialinzing the variable as true which will turn on the music
void music(){
	if(musicOn && mode==14 ){
		PlaySound("music\\hpmldy.wav", NULL,SND_LOOP|SND_ASYNC); 
		
	}
	if(musicOn && mode==1){

		PlaySound("music\\tokyo.wav", NULL,SND_LOOP|SND_ASYNC); 
	}
	if(musicOn && mode==3){
		PlaySound("music\\pirate.wav", NULL,SND_LOOP|SND_ASYNC); 

	}
	if(musicOn && mode==9){
		PlaySound("music\\titanium.wav", NULL,SND_LOOP|SND_ASYNC); 

	}
	if(musicOn && mode==11){
		PlaySound("music\\expelliarmus.wav", NULL,SND_ASYNC); 

	}




}