#ifndef SDLFunc
#define SDLFunc
using namespace std;
void mouse(SDL_Event event,int& row1,int& column1,int& row2,int& column2,bool &newcommand);
void show(vector<string> page,SDL_Surface* screen,SDL_Surface* red,SDL_Surface* yellow,SDL_Surface* blue,SDL_Surface* green,SDL_Surface* orange,int width,int score,int time,SDL_Rect ScoreBoard,TTF_Font *font,SDL_Color textColor,SDL_Surface* scorepage);
#endif
