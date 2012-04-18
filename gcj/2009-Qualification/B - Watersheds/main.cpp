#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
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

int elevation[100][100];
int flow[100][100];
int basin[100][100];

const int north = 0;
const int south = 1;
const int east = 2;
const int west = 3;
const int none = 4;

int nextBasin = 0;
void solveBasin(int r, int c)
{
    if(basin[r][c] != -1)
        return;

    if(flow[r][c] == none)
    {
        basin[r][c] = nextBasin;
        nextBasin++;
        return;
    }

    int nr = r;
    int nc = c;

    if(flow[r][c] == north) nr = r-1;
    else if(flow[r][c] == south) nr = r+1;
    else if(flow[r][c] == east) nc = c+1;
    else if(flow[r][c] == west) nc = c-1;

    solveBasin(nr, nc);
    basin[r][c] = basin[nr][nc];
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
	    int width, height;
	    getline(cin, line);
	    ss << line;
	    ss >> height;
	    ss >> width;
	    ss.clear();


	    for(int r=0;r<height;r++)
	    {
	        getline(cin, line);
	        ss << line;
	        for(int c=0;c<width;c++)
                ss >> elevation[r][c];
            ss.clear();
	    }


	    for(int r=0;r<height;r++)
	    {
	        for(int c=0;c<width;c++)
	        {
	            flow[r][c] = none;
	            int minElev = elevation[r][c];

	            if(r > 0 && elevation[r-1][c] < minElev)
	            {
	                minElev = elevation[r-1][c];
	                flow[r][c] = north;
	            }
	            if(c > 0 && elevation[r][c-1] < minElev)
	            {
	                minElev = elevation[r][c-1];
	                flow[r][c] = west;
	            }
	            if(c < width-1 && elevation[r][c+1] < minElev)
	            {
	                minElev = elevation[r][c+1];
	                flow[r][c] = east;
	            }
	            if(r < height-1 && elevation[r+1][c] < minElev)
	            {
	                minElev = elevation[r+1][c];
	                flow[r][c] = south;
	            }
	        }
	    }

        nextBasin = 0;
        memset(basin, -1, sizeof(basin));

        for(int r=0;r<height;r++)
            for(int c=0;c<width;c++)
                basin[r][c] = -1;

	    for(int r=0;r<height;r++)
	        for(int c=0;c<width;c++)
	            solveBasin(r,c);

		cout << "Case #" << testCase+1 << ": " << endl;

		for(int r=0;r<height;r++)
		{
		    for(int c=0;c<width;c++)
		    {
		        cout << (char)('a'+basin[r][c]);
		        if(c != width-1)
                    cout << " ";
		    }
		    cout << endl;
		}
	}

	return 0;
}

