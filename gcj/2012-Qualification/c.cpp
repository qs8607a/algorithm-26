#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include <cmath>
#include <cstdlib>
#include <set>

int numDigits(int num)
{
	int res = 0;

	while(num > 0)
	{
		num /= 10;
		res++;
	}

	return res;
}

int rotateNum(int num, int times)
{
	int nDigits = numDigits(num);

	int mulPlace = 1;
	for(int i=0;i<times;i++)
		mulPlace *= 10;

	int part = num % mulPlace;
	num /= mulPlace;
	
	int replace = 1;
	for(int i=0;i<nDigits-times;i++)
		replace *= 10;

	num += part * replace;

	return num;
}

int main(void)
{
	string numCasesStr;
	getline(cin, numCasesStr);
	int numCases = atoi(numCasesStr.c_str());

	for(int inCase=0;inCase<numCases;inCase++)
	{
		stringstream ss;
		string inLine;
		getline(cin, inLine);
		ss << inLine;

		int A = 0, B = 0;
		ss >> A;
		ss >> B;

		int numPairs = 0;

		for(int n=A;n<B;n++)
		{
			int digits = numDigits(n);
			set<int> argh;
			for(int i=0;i<digits-1;i++)
			{
				int m = rotateNum(n,i+1);
				if(m > n && m <= B)
				{
					argh.insert(m);
					//cout << n << ", " << m << endl;
				}
			}
			numPairs += argh.size();
		}

		cout << "Case #" << inCase+1 << ": " << numPairs << endl;
	}
}

