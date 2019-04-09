#include<iostream>
#include<string>
#include<vector>
#include"MetaFunc.h"
using namespace std;
bool Is3Candy(vector<string> page,int width){
	int height=page.size();
	for(int row=0;row<height;row++)
	{
		for(int column=0;column<width;column++)
		{
			if(column<width-2)
			if(page[row][column]==page[row][column+1]&&page[row][column]==page[row][column+2])
					return true;
			if(row<height-2)
			if(page[row][column]==page[row+1][column]&&page[row][column]==page[row+2][column])
					return true;

		}
	}
		return false;
}


void Crush(vector<string>& page,vector<double> prob,int width,int& score)
{	
	int count=0;
	int randisneed=0;
	int height=page.size();
	for(int row=0;row<height;row++)
	{
		for(int column=0;column<width;column++)
		{	
			if(column<width-2)
				if(page[row][column]==page[row][column+1]&&page[row][column]==page[row][column+2]){
					for(int i=column;i<width;i++)
					{
						if(page[row][column]==page[row][i])
							count=count+1;
					}
					for(int j=row;j>0;j--){
						for(int i=column;i<count+column;i++)
							page[j][i]=page[j-1][i];
					}
					for(int i=column;i<column+count;i++)
						page[0][i]=random(prob);
					score=count+score;
					count=0;
				}
			if(row<height-2)
				if(page[row][column]==page[row+1][column]&&page[row][column]==page[row+2][column]){
					for(int i=row;i<height;i++)
					{
						if(page[row][column]==page[i][column])
							count=count+1;
					}
					for(int i=0;i<count;i++){
						for(int j=row+count-1;j>=0;j--){
							if(j-1>=0)	
								page[j][column]=page[j-1][column];
							if(j-1<0)
								page[j][column]=random(prob);
						}
					}
					score=count+score;
					count=0;	
				}
		}
	} 	
		if(Is3Candy(page,width))
			Crush(page,prob,width,score);	
}
