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
int numStars;
int res;

void GoBack(int curLevel, bool twoOnly, int targetStars)
{
	//Look for two stars
	for(int i=0;i<curLevel;i++)
	{
		if(levels[i].GotTwo == false && levels[i].TwoStars <= numStars)
		{
			levels[i].GotTwo = true;
			numStars++;

			if(numStars >= targetStars)
				return;
		}
	}

	//Look for one star
	for(int i=0;i<curLevel;i++)
	{
		if(levels[i].GotOne == false && levels[i].OneStar <= numStars)
		{
			levels[i].GotOne = true;
			numStars++;

			if(numStars >= targetStars)
				return;
		}
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
		int numLevels = 0;
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
		bool tooBad = false;

		for(int i=0;i<numLevels;i++)
		{
			int oldNumStars = numStars;

			//Can earn two stars now?
			if(levels[i].TwoStars <= numStars)
			{
				levels[i].GotTwo = true;
				numStars++;
				continue;
			}

			//Can't get two here yet.  Go back and earn more.
			else
			{
				GoBack(i, true, levels[i].TwoStars);
				if(numStars != oldNumStars)
				  continue;
			}

			//Can earn two stars now? (made redundant by the continue after GoBack above).
			if(levels[i].TwoStars <= numStars)
			{
				levels[i].GotTwo = true;
				numStars++;
				continue;
			}

			//Still can't get two here.  Try to pass the level at least.
			else
			{
				if(levels[i].OneStar <= numStars)
				{
					levels[i].GotOne = true;
					numStars++;
					continue;
				}

				//Not enough for the one-star pass.  Go get more.
				else
				{
					GoBack(i, false, levels[i].OneStar);
					if(numStars != oldNumStars)
					  continue;
				}
			}

			if(numStars == oldNumStars)
			{
				tooBad = true;
				break;
			}
		}

		//Go back and two-star everything (unnecessary?)
		for(int i=0;i<numLevels;i++)
		{
		  if(levels[i].GotTwo == false)
		  {
			 if(levels[i].TwoStars <= numStars)
			 {
				levels[i].GotTwo = true;
				numStars++;
				i = -1;
				continue;
			 }
		  }
		}

		printf("Case #%d: ", testCase+1);
		if(tooBad == true)
			printf("Too Bad\n");
		else
			printf("%d\n", numStars);
	}

	return 0;
}

