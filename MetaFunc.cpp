#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;
vector<string> readinput(int &width, int &height, vector<double> &Prob)
{
	string CandyRow;
	vector<string> InitCandy;
	double probability;
	cin >> height;
	cin >> width;
	for (int color = 0; color < 5; color++)
	{
		cin >> probability;
		Prob.push_back(probability);
	}
	for (int row = 0; row < height; row++)
	{
		cin >> CandyRow;
		InitCandy.push_back(CandyRow);
	}

	return InitCandy;
}
char random(vector<double> prob)
{
	double randNum = (rand() % 100) / (double)100;
	double temp = 0;
	temp = prob[0];
	if (randNum < temp)
		return 'r';
	temp = temp + prob[1];
	if (randNum < temp)
		return 'b';
	temp = temp + prob[2];
	if (randNum < temp)
		return 'g';
	temp = temp + prob[3];
	if (randNum < temp)
		return 'y';
	return 'o';
}
void Fill_Page_Random(vector<string> &page, int width, vector<double> prob)
{
	int height = page.size();
	for (int row = 0; row < height; row++)
	{
		for (int column = 0; column < width; column++)
		{
			page[row][column] = random(prob);
		}
	}
}
void swap(vector<string> &page, int row1, int column1, int row2, int column2)
{
	char temp = page[row1][column1];
	page[row1][column1] = page[row2][column2];
	page[row2][column2] = temp;
}

int abs(int value)
{
	if (value < 0)
		return -value;
	else
		return value;
}
