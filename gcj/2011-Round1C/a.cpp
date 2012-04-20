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

char p[50][50];

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
		int R, C;
		getline(cin, line);
		ss.clear();
		ss << line;
		ss >> R >> C;

		for(int r=0;r<R;r++)
		{
			getline(cin, line);
			ss.clear();
			ss << line;
			for(int c=0;c<C;c++)
				ss >> p[r][c];
		}

		bool ok=true;
		int cont=0;
		for(int r=0;r<R && ok;r++)
		{
			cont=0;
			for(int c=0;c<C;c++)
			{
				if(p[r][c] == '#') cont++;
				else
				{
					if(cont & 1)
					{
						ok=false;
						break;
					}
					else cont=0;
				}
			}
			if(cont & 1)
			{
				ok=false;
				break;
			}
		}

		if(ok == false)
		{
			cout << "Case #" << testCase+1 << ": " << endl << "Impossible" << endl;
			continue;
		}

		for(int c=0;c<C && ok;c++)
		{
			cont=0;
			for(int r=0;r<R;r++)
			{
				if(p[r][c] == '#') cont++;
				else
				{
					if(cont & 1)
					{
						ok=false;
						break;
					}
					else cont=0;
				}
			}
			if(cont & 1)
			{
				ok=false;
				break;
			}
		}

		if(ok == false)
		{
			cout << "Case #" << testCase+1 << ": " << endl << "Impossible" << endl;
			continue;
		}

		for(int r=0;r<R;r++)
		{
			for(int c=0;c<C;c++)
			{
				if(p[r][c]=='#')
				{
					p[r][c]=p[r+1][c+1]='/';
					p[r+1][c]=p[r][c+1]='\\';
				}
			}
		}

		cout << "Case #" << testCase+1 << ": " << endl;
		for(int r=0;r<R;r++)
		{
			for(int c=0;c<C;c++)
				cout << p[r][c];
			cout << endl;
		}
	}

	return 0;
}

