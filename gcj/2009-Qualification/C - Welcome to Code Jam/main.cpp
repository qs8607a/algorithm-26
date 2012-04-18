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

string target = "welcome to code jam";
int ways[20][501];

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
	    getline(cin, line);

	    memset(ways, 0, sizeof(ways));

	    for(uint i=0;i<line.length();i++)
	    {
            for(uint j=0;j<target.length();j++)
            {
                if(line[i] == target[j])
                {
                    //q welcome to code jam p
                    if(j == 0)
                    {
                        ways[j][i]++;
                        ways[j][i] %= 10000;
                    }
                    else
                    {
                        for(uint k=0;k<i;k++)
                        {
                            ways[j][i] += ways[j-1][k];
                            ways[j][i] %= 10000;
                        }
                    }
                }
            }
	    }

        int res = 0;
        for(uint i=0;i<line.length();i++)
        {
            res += ways[target.length()-1][i];
            res %= 10000;
        }

        printf("Case #%d: %04d\n", testCase+1, res);
	}

	return 0;
}

