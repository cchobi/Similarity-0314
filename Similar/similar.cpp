#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct Length {
	int longLen;
	int shortLen;
};

class Similar {
public:
	void getLongShortLength(const std::string& str1, const std::string& str2)
	{
		if (str1.length() >= str2.length()) {
			len.longLen = (int)str1.length();
			len.shortLen = (int)str2.length();
		}
		else
		{
			len.longLen = (int)str2.length();
			len.shortLen = (int)str1.length();
		}
	}
	int checkCharNums(const string& str1, const string& str2)
	{
		getLongShortLength(str1, str2);

		if (len.longLen == len.shortLen) return MAX_LENGTH_POINT;
		if (len.longLen >= (2 * len.shortLen)) return 0;

		return ((2 - (double)len.longLen / len.shortLen)* MAX_LENGTH_POINT);
	}

	int checkAlpha(const string& str1, const string& str2)
	{
		unordered_map<char, int> letterCount1 = getLetterCount(str1);
		unordered_map<char, int> letterCount2 = getLetterCount(str2);

		int sameCount = 0;
		int totalCount = letterCount1.size() + letterCount2.size();
		for (const auto& pair : letterCount1) {
			char letter = pair.first;
			if (letterCount2.find(letter) != letterCount2.end()) {
				if (letterCount2[letter] > 0) {
					sameCount++;
					totalCount--;
				}
			}
		}

		if (sameCount == 0) return 0;
		
		if (letterCount1.size() == letterCount2.size()
			&& letterCount1.size() == sameCount) {
			return MAX_ALPHA_POINT;
		}

		return (MAX_ALPHA_POINT * (double)sameCount / totalCount);
	}

	unordered_map<char, int> getLetterCount(const std::string& str) 
	{
		unordered_map<char, int> letterCount;
		for (char ch : str) {
			if (std::isalpha(ch)) {
				char uppercaseCh = std::toupper(ch);
				letterCount[uppercaseCh]++;
			}
		}

		return letterCount;
	}

private:
	Length len{ 0,0 };
	const int MAX_LENGTH_POINT = 60;
	const int MAX_ALPHA_POINT = 40;
};
