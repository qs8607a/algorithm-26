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

#define FCMP(a,b) (((a)+1e-5>(b)) && ((a)-1e-5<(b)))

int lcw[101];

int lcm(int a, int b)
{
	int s, l;
	if(a > b) { l=a; s=b; }
	else { l=b; s=a; }

	if(l%s==0)
		return l;

	int r = l%s;
	while(r != 0)
	{
		l=s;
		s=r;
		r=l%s;
	}

	return (a*b)/s;
}

int main(void)
{
	lcw[0]=0;
	for(int i=1;i<=100;i++)
		lcw[i]=100;

	for(int i=1;i<=100;i++)
	{
		for(int j=1;j<=100;j++)
		{
			float x = (float)j * (float)i * .01f;
			int xi = (int)x;
			if( FCMP(x, (float)xi) )
			{
				lcw[i] = j;
				break;
			}
		}
	}

	string line;
	uint numTests;
	stringstream ss;

	getline(cin, line);
	ss << line;
	ss >> numTests;
	ss.clear();

	for(uint testCase=0; testCase < numTests; testCase++)
	{
		ull N, PD, PG;
		getline(cin, line);
		ss << line;
		ss >> N >> PD >> PG;
		ss.clear();

		bool broken;

		//int tg = lcm( lcw[PD], lcw[PG] );
		//if( (float)tg * ((float)PG*.01f) > ((float)N+1e-5) )

		if(lcw[PD] > N || (PG==100 && PD!=100) || (PG==0 && PD!=0))
			broken = true;
		else
			broken = false;

		cout << "Case #" << testCase+1 << ": " << (broken?"Broken":"Possible") << endl;
	}

	return 0;
}

