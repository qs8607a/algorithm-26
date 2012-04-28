#include <iostream>
#include <sstream>
using namespace std;

#include <cstdlib>


int main(void)
{
	string numInputsStr;
	getline(cin, numInputsStr);

	int numInputs = atoi(numInputsStr.c_str());

	for(int i=0;i<numInputs;i++)
	{
		string inputLine;
		getline(cin, inputLine);

		stringstream ss;
		ss << inputLine;

		int numGooglers = 0;
		ss >> numGooglers;

		int numSurprises = 0;
		ss >> numSurprises;

		int p = 0;
		ss >> p;

		int beatsP = 0;
		int needsSurprise = 0;

		for(int j=0;j<numGooglers;j++)
		{
			int totalScore;
			ss >> totalScore;

			int baseScore = totalScore / 3;
			int maxScore = baseScore + 2;
			if((totalScore % 3) < 2)
				maxScore = baseScore + 1;

			maxScore = min(maxScore, totalScore);

			if(maxScore >= p)
				beatsP++;

			if((totalScore%3) == 0 && baseScore < p && maxScore >= p)
				needsSurprise++;
			else if((totalScore%3) == 2 && baseScore+1 < p && maxScore >= p)
				needsSurprise++;
		}

		if(needsSurprise > numSurprises)
			beatsP -= (needsSurprise - numSurprises);	

		cout << "Case #" << (i+1) << ": " << beatsP << endl;
	}
}

