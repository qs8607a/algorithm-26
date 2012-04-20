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

int edges[1000000];
int ai[1000000];

int main(void)
{
	string line;
	uint numTests;
	stringstream ss;

	getline(cin, line);
	ss << line;
	ss >> numTests;

	for(uint testCase=0; testCase < numTests; testCase++)
	{
		int numStars, buildTime, numBoosters, period;
		ss.clear();
		getline(cin, line);
		ss << line;
		ss >> numBoosters >> buildTime >> numStars >> period;
		for(int i=0;i<period;i++)
			ss >> ai[i];

		for(int n=0;n<numStars;n++)
			edges[n]=ai[n%period]*2;
		// buildTime /= 2;

		int useless=0;
		int uselessPart=0;
		int usefulPart = 0;
		int uselessIndex=0;
		while(useless < buildTime && uselessIndex < numStars)
		{
			uselessPart = useless;
			useless += edges[uselessIndex];
			if(useless >= buildTime)
			{
				uselessPart += (buildTime - uselessPart);
				usefulPart = useless - buildTime;
			}
			else
				uselessIndex++;
		}

		vector<int> fixme;

		if(usefulPart > 0)
		{
			uselessIndex++;
			fixme.push_back(usefulPart);
		}

		for(int i=uselessIndex;i<numStars;i++)
			fixme.push_back(edges[i%period]);

		sort(fixme.begin(),fixme.end(),greater<int>());
		
		for(int i=0;i<numBoosters;i++)
			fixme[i] /= 2;

		ull res = uselessPart;
		for(int i=0;i<fixme.size();i++)
			res += fixme[i];

		cout << "Case #" << testCase+1 << ": " << res << endl;
	}

	return 0;
}

