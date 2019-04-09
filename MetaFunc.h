#ifndef MetaFunc
#define MetaFunc
using namespace std;
vector<string> readinput(int &width,int &height,vector<double>& Prob);
char random(vector<double> prob);
void Fill_Page_Random(vector<string>& page,int width,vector<double> prob);
void swap(vector<string>& page,int row1,int column1,int row2,int column2);
int abs(int value);
#endif
