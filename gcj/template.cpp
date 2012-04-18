#include <algorithm>
#include <cctype>
#include <cmath>
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
		cout << "Case #" << testCase+1 << ": " << endl;
	}

	return 0;
}

