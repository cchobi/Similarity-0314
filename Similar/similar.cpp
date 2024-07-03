#include <string>
#include <vector>
using namespace std;

class Similar {
public:
	int checkCharNum(const string& str1, const string& str2)
	{
		int longLen = 0;
		int shortLen = 0;
		if (str1.length() >= str2.length()) {
			longLen = (int)str1.length();
			shortLen = (int)str2.length();
		}
		else
		{
			longLen = (int)str2.length();
			shortLen = (int)str1.length();
		}

		if (longLen == shortLen) return 60;
		if (longLen == (2 * shortLen)) return 0;

		return ((2 - (double)longLen / shortLen)*60);
	}
};
