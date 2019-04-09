#include<iostream>
#include<string>
#include <vector>
#include"SDL/SDL.h"
#include"SDL/SDL_ttf.h"
#include"SDL-Func.h"
#include"validation.h"
#include"SDL-Func.h"
#include"MetaFunc.h"
#include"GameCore.h"
#define xScale 100
#define yScale 100
#define FONT_ADDRESS "arial.ttf"
using namespace std;
int main(int argc,char* argv[]){
	vector<string> page;
	vector<double> prob;
	int height=0,width=0;
	int score=0;
	int row1=0,row2=0,column1=0,column2=0;
	int time_in_ms=0;
	Uint32 start_time=0;
	Uint32 time_in_s=0;
	char buff[256];
	// SDL Init
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	// Font Part Initialization
	SDL_Color textColor ={0,0xff,0};
	TTF_Font *font = NULL;
	int fontsize=yScale/3;
	font = TTF_OpenFont(FONT_ADDRESS,fontsize);

	SDL_WM_SetCaption("Candy Crush",NULL);
	// SDL Surface Pointers
	SDL_Surface* finalscore=NULL;
	SDL_Surface* scorepage=NULL;
	SDL_Surface* green=NULL;
	SDL_Surface* orange=NULL;
	SDL_Surface* red=NULL;
	SDL_Surface* blue=NULL;
	SDL_Surface* yellow=NULL;
	SDL_Surface* screen=NULL;
	//SDL Image 
	red=SDL_LoadBMP("red.bmp");
	blue=SDL_LoadBMP("blue.bmp");
	yellow=SDL_LoadBMP("yello.bmp");
	orange=SDL_LoadBMP("orange.bmp");
	green=SDL_LoadBMP("green.bmp");
	scorepage=SDL_LoadBMP("scorepage.bmp");
	// Control Flags
	bool end=false;
	bool newcommand=false;
	// Initialization Functions
	page=readinput(width,height,prob);
	screen= SDL_SetVideoMode(width*xScale,height*yScale+yScale,32,SDL_SWSURFACE);
	Crush(page,prob,width,score);
	score=0;

	SDL_Rect ScoreBoard;
	ScoreBoard.x=0;
	ScoreBoard.y=height*yScale;
	SDL_Event event;
	start_time=SDL_GetTicks();

	while(!end){		
		while(SDL_PollEvent(&event)){
			newcommand=false;
			if(event.type == SDL_QUIT)
				end=true;
			if(event.type == SDL_MOUSEBUTTONDOWN)
				if(event.button.button==SDL_BUTTON_LEFT)
					mouse(event,row1,column1,row2,column2,newcommand);			
			if(newcommand){
				if(IsValid(page,width,row1,column1,row2,column2))
					Crush(page,prob,width,score);	
				if(!pagecheck(page,width)){
					SDL_Delay(1000);
					Fill_Page_Random(page,width,prob);
					int tempScore=score;
					Crush(page,prob,width,score);
					score=tempScore;		
				}
			}
		}
		if(time_in_ms>60000)
			end=true;
		time_in_ms=SDL_GetTicks()-start_time;
		int time_in_S=60-time_in_ms/1000;
		show(page,screen,red,yellow,blue,green,orange,width,score,time_in_S,ScoreBoard,font,textColor,scorepage);
	}
	sprintf(buff,"Your Score is : %d Good luck!!",score);
	finalscore=TTF_RenderText_Solid(font,buff,textColor);
	SDL_BlitSurface(scorepage,NULL,screen,&ScoreBoard);
	SDL_BlitSurface(finalscore,NULL,screen,&ScoreBoard);
	SDL_Flip(screen);	
	SDL_Delay(2000);
	// Free Pointers
	TTF_CloseFont(font);
	SDL_FreeSurface(red);
	SDL_FreeSurface(yellow);
	SDL_FreeSurface(blue);
	SDL_FreeSurface(green);
	SDL_FreeSurface(orange);
	SDL_FreeSurface(finalscore);
	SDL_FreeSurface(scorepage);
	SDL_FreeSurface(screen);
	SDL_Quit();

	return 0;
}
