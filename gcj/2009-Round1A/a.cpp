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

char* itoa(int value, char* result, int base) {
		// check that the base if valid
		if (base < 2 || base > 36) { *result = '\0'; return result; }
	
		char* ptr = result, *ptr1 = result, tmp_char;
		int tmp_value;
	
		do {
			tmp_value = value;
			value /= base;
			*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
		} while ( value );
	
		// Apply negative sign
		if (tmp_value < 0) *ptr++ = '-';
		*ptr-- = '\0';
		while(ptr1 < ptr) {
			tmp_char = *ptr;
			*ptr--= *ptr1;
			*ptr1++ = tmp_char;
		}
		return result;
}

char nstr[1048576];
set<int> seen;
bool isHappy(int n, int base)
{
	if(seen.find(n) != seen.end())
	{
		seen.clear();
		return false;
	}

	seen.insert(n);

	itoa(n, nstr, base);
	int nn = 0;
	for(int i=0;nstr[i] != 0;i++)
		nn += ((nstr[i]-'0') * (nstr[i]-'0'));

	if(nn==1)
	{
		seen.clear();
		return true;
	}

	return isHappy(nn, base);
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
		getline(cin, line);
		vector<int> bases;
		int testBase;
		ss << line;
		while(ss.good() && !ss.eof())
		{
			int base;
			ss >> base;
			testBase = base;
			bases.push_back(base);
		}
		ss.clear();

		int res=2;
		while(true)
		{
			if(isHappy(res, testBase))
			{
				bool happy = true;
				for(int i=0;i<bases.size()-1;i++)
				{
					if(isHappy(res, bases[i]) == false)
					{
						happy = false;
						break;
					}
				}
				if(happy)
					break;
			}

			res++;
		}

		cout << "Case #" << testCase+1 << ": " << res << endl;
	}

	return 0;
}

