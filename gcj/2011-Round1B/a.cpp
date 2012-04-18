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

char games[100][100];

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
		int numTeams;
		getline(cin, line);
		ss << line;
		ss >> numTeams;
		ss.clear();
		
		for(int i=0;i<numTeams;i++)
		{
			getline(cin, line);
			ss << line;
			for(int j=0;j<numTeams;j++)
				ss >> games[i][j];
			ss.clear();
		}

		float wp[100];
		float owp[100];
		float oowp[100];
		float opps[100];
		for(int i=0;i<100;i++)
			wp[i]=owp[i]=oowp[i]=opps[i]=0.f;

		for(int i=0;i<numTeams;i++)
		{
			int wins = 0;
			int numGames = 0;
			for(int j=0;j<numTeams;j++)
			{
				if(games[i][j] == '1')
					wins++;

				if(games[i][j] != '.')
					numGames++;
			}

			opps[i] = numGames;
			wp[i] = (float)wins / (float)numGames;
		}

		for(int team=0;team<numTeams;team++)
		{
			for(int opp=0;opp<numTeams;opp++)
			{
				if(opp==team)
					continue;

				if(games[team][opp]=='.')
					continue;
					
				int oppWins = 0;
				int oppGames = 0;
				for(int oppGame=0;oppGame<numTeams;oppGame++)
				{
					if(oppGame == team)
						continue;

					if(games[opp][oppGame] == '1')
						oppWins++;

					if(games[opp][oppGame] != '.')
						oppGames++;
				}
				owp[team] += (float)oppWins / (float)(oppGames);
			}
			owp[team] /= (float)(opps[team]);
		}

		for(int team=0;team<numTeams;team++)
		{
			for(int opp=0;opp<numTeams;opp++)
			{
				if(opp==team)
					continue;

				if(games[team][opp] == '.')
					continue;

				oowp[team] += owp[opp];
			}
			oowp[team] /= opps[team];
		}

		cout << "Case #" << testCase+1 << ": " << endl;

		for(int i=0;i<numTeams;i++)
		{
			float rpi = (0.25f * wp[i]) + (0.5f * owp[i]) + (0.25f * oowp[i]);
			cout << rpi << endl;
		}
	}

	return 0;
}

