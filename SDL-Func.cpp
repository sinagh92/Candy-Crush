#include<iostream>
#include<vector>
#include<string>
#include"SDL/SDL_ttf.h"
#include"SDL/SDL.h"
#define xScale 100
#define yScale 100
#define FONT_ADDRESS "arial.ttf"
using namespace std;
void mouse(SDL_Event event,int& row1,int& column1,int& row2,int& column2,bool &newcommand){
		static bool firstpoint=true;
		static bool secondpoint=false;
		int x=0,y=0;
		if(firstpoint){	
			x=event.button.x;
			y=event.button.y;
			row1=y/yScale;
			column1=x/xScale;
		}	
		if(secondpoint){
			newcommand=true;		
			x=event.button.x;
			y=event.button.y;
			row2=y/yScale;
			column2=x/xScale;
		}
		if(secondpoint==true){secondpoint=false;firstpoint=true;}
		else if(firstpoint==true){secondpoint=true;firstpoint=false;}
}
void show(vector<string> page,SDL_Surface* screen,SDL_Surface* red,SDL_Surface* yellow,SDL_Surface* blue,SDL_Surface* green,SDL_Surface* orange,int width,int score,int time,SDL_Rect ScoreBoard,TTF_Font *font,SDL_Color textColor,SDL_Surface* scorepage){
	int height=page.size();
	char buff[256];
	SDL_Surface* textSurface=NULL;
	SDL_Rect shape;
	for(int row=0;row<height;row++)
		{
			for(int column=0;column<width;column++)
				{
					shape.x=column*100;
					shape.y=row*100;			
					if(page[row][column]=='r'){SDL_BlitSurface(red,NULL,screen,&shape);}
					if(page[row][column]=='b'){SDL_BlitSurface(blue,NULL,screen,&shape);}
					if(page[row][column]=='y'){SDL_BlitSurface(yellow,NULL,screen,&shape);}
			 		if(page[row][column]=='g'){SDL_BlitSurface(green,NULL,screen,&shape);}		
					if(page[row][column]=='o'){SDL_BlitSurface(orange,NULL,screen,&shape);}
				}	
		}
	sprintf(buff,"Score : %d Time : %d",score,time);
	textSurface=TTF_RenderText_Solid(font,buff,textColor);
	SDL_BlitSurface(scorepage,NULL,screen,&ScoreBoard);
	SDL_BlitSurface(textSurface,NULL,screen,&ScoreBoard);
	SDL_Flip(screen);
}
