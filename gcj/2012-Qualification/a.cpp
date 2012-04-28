#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include <cstdlib>


int main(void)
{
	const char* charMap = "yhesocvxduiglbkrztnwjpfmaq";
	string inLine;
	string outLine;

	string testCountStr;
	getline(cin, testCountStr);
	int testCount = atoi(testCountStr.c_str());
	
	for(int test=0;test<testCount;test++)
	{
		inLine = "";
		outLine = "";
		getline(cin, inLine);

		for(int i=0;i<inLine.length();i++)
		{
			if(inLine[i] >= 'a' && inLine[i] <= 'z')
				outLine += charMap[inLine[i]-'a'];
			else
				outLine += inLine[i];
		}

		cout << "Case #" << (test+1) << ": " << outLine << endl;
	}

	return 0;
}

