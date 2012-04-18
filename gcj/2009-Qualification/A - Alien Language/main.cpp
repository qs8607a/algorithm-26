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

vector<string> dictionary;

int main(void)
{
	string line;
	uint numTests;
	stringstream ss;

	uint numTokens, numDictionaryWords;

	getline(cin, line);
	ss << line;
	ss >> numTokens >> numDictionaryWords >> numTests;

    for(uint i=0;i<numDictionaryWords;i++)
    {
        getline(cin, line);
        dictionary.push_back(line);
    }

	for(uint testCase=0; testCase < numTests; testCase++)
	{
	    string pattern;
	    getline(cin, pattern);

	    vector<string> tokens;
	    for(uint i=0;i<numTokens;i++)
            tokens.push_back("");

        uint tokenIndex = 0;

	    for(uint i=0;i<pattern.length();i++)
	    {
	        if(pattern[i] == '(')
            {
                i++;
                while(pattern[i] != ')')
                {
                    tokens[tokenIndex] += pattern[i];
                    i++;
                }
            }
            else
                tokens[tokenIndex] += pattern[i];

            tokenIndex++;
	    }


	    vector<bool> matches;
	    for(uint i=0;i<dictionary.size();i++)
            matches.push_back(true);

        for(uint i=0;i<tokens.size();i++)
        {
            for(uint j=0;j<dictionary.size();j++)
            {
                if(matches[j] == false)
                    continue;

                if(find(tokens[i].begin(), tokens[i].end(), dictionary[j][i]) == tokens[i].end())
                    matches[j] = false;
            }
        }

	    int res = 0;
	    for(uint i=0;i<matches.size();i++)
            if(matches[i] == true)
                res++;

		cout << "Case #" << testCase+1 << ": " << res << endl;
	}

	return 0;
}

