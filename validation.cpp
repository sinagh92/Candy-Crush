#include<iostream>
#include<string>
#include<vector>
#include"SDL/SDL.h"
#include"MetaFunc.h"
#include"GameCore.h"
using namespace std;
bool IsValid(vector<string>& page,int width,int row1,int column1,int row2,int column2){
	int height=page.size();
	if(row1>height-1||row2>height-1||row1<0||row2<0)
			return false;
	if(column1>width-1||column2>width-1||column1<0||column2<0)
		return false;
	if(row1==row2)
		if(abs(column1-column2)==1){
			swap(page,row1,column1,row2,column2);
			if(Is3Candy(page,width))
			return true;
			else swap(page,row1,column1,row2,column2);
			}
	if(column1==column2)
		if(abs(row1-row2)==1){
			swap(page,row1,column1,row2,column2);
			if(Is3Candy(page,width))
			return true;
			else swap(page,row1,column1,row2,column2);
			}
		return false;
}

bool pagecheck(vector<string> page,int w){
	int width=w;
	int height=page.size();
	for(int row=0;row<height;row++){
		for(int column=0;column<width;column++){
			if(column<width)
				if(page[row][column]==page[row][column+1]){
					if(column>1)
						if(page[row][column]==page[row][column-2])
							return true;
					if(column<width-2)
						if(page[row][column]==page[row][column+3])
							return true;
					if(column>0&&row>0)
						if(page[row][column]==page[row-1][column-1])	
							return true;
					if(column>0&&row<height-1)
						if(page[row][column]==page[row+1][column-1])	
							return true;
					if(column<width-1&&row>0)
						if(page[row][column]==page[row-1][column+2])	
							return true;
					if(column<width-1&&row<height-1)
						if(page[row][column]==page[row+1][column+2])	
							return true;	
				}
			if(column<width-2){	
				if(page[row][column]==page[row][column+2]){
					if(row>0)
						if(page[row][column]==page[row-1][column+1])
							return true;
					if(row<height-1)
						if(page[row][column]==page[row+1][column+1])
							return true;
				}	
			}			
			if(row<height-2){
				if(page[row][column]==page[row+1][column]){
					if(column>0)
						if(page[row][column]==page[row+2][column-1]){
							return true;}
					if(column<width)
						if(page[row][column]==page[row+2][column+1]){
							return true;}
				}
			}
			if(row<height-1)
				if(page[row][column]==page[row+1][column]){

					if(row>1)
						if(page[row][column]==page[row-2][column])	
							return true;	
					if(row>0&&column>0)
						if(page[row][column]==page[row-1][column-1])
							return true;
					if(row>0&&column<width-1)
						if(page[row][column]==page[row-1][column+1])
							return true;
					if(row<height-2&&column>0)
						if(page[row][column]==page[row+2][column-1])
							return true;	
					if(row<height-2&&column<width)
						if(page[row][column]==page[row+2][column+1])
							return true;
					if(row<height-3)
						if(page[row][column]==page[row+3][column])
							return true;
				}
		}
	}
	return false;
}
