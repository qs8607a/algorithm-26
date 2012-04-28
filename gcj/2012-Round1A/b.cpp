#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
 
using namespace std;
 
typedef vector<bool> VB; typedef vector<double> VD;
typedef vector<int> VI; typedef vector<string> VS;

typedef unsigned int uint;
typedef unsigned long long ull;

struct Level
{
	int OneStar;
	int TwoStars;

	bool GotOne;
	bool GotTwo;
};

Level levels[1000];
int numLevels;
int numStars;
int res;

void Go()
{
	int oldNumStars = numStars;
	int lowestTwoStarIndex = -1;
	int lowestTwoStars = 1e9;

	//Get two stars
	for(int i=0;i<numLevels;i++)
	{
		if(levels[i].GotTwo == false && levels[i].TwoStars <= numStars)
		{
			levels[i].GotTwo = true;
			numStars++;

			if(levels[i].GotOne == false)
			{
				levels[i].GotOne = true;
				numStars++;
			}

			res++;
		}

		if(levels[i].GotTwo == false && levels[i].TwoStars < lowestTwoStars)
		{
			lowestTwoStarIndex = i;
			lowestTwoStars = levels[i].TwoStars;
		}
	}

	if(numStars != oldNumStars)
		return;

	if(lowestTwoStarIndex == -1)
		return;

	//Get one star
	
	int bestOneStar = -1;
	int bestOneStarIndex = -1;

	for(int i=0;i<numLevels;i++)
	{
		if(levels[i].GotOne == false && levels[i].OneStar <= numStars)
		{
			if(levels[i].TwoStars > bestOneStar)
			{
				bestOneStar = levels[i].TwoStars;
				bestOneStarIndex = i;
			}
		}
	}

	if(bestOneStarIndex != -1)
	{
		levels[bestOneStarIndex].GotOne = true;
		numStars++;
		res++;
	}
}

int main(void)
{
	string line;
	uint numTests;
	stringstream ss;

	getline(cin, line);
	ss << line;
	ss >> numTests;
	ss.clear();

	for(uint testCase=0; testCase < numTests; testCase++)
	{
		numLevels = 0;
		getline(cin, line);
		ss << line;
		ss >> numLevels;
		ss.clear();

		for(int i=0;i<numLevels;i++)
		{
			Level& level = levels[i];

			getline(cin, line);
			ss << line;
			ss >> level.OneStar;
			ss >> level.TwoStars;
			level.GotOne = level.GotTwo = false;
			ss.clear();
		}

		numStars = 0;
		res = 0;

		int oldNumStars = 0;
		do
		{
			oldNumStars = numStars;
			Go();
		}while(oldNumStars != numStars);

		bool tooBad = false;
		for(int i=0;i<numLevels;i++)
		{
			if(levels[i].GotTwo == false)
			{
				tooBad = true;
				break;
			}
		}

		printf("Case #%d: ", testCase+1);
		if(tooBad == true)
			printf("Too Bad\n");
		else
			printf("%d\n", res);
	}

	return 0;
}

