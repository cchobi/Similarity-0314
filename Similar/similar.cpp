#include <string>
#include <vector>
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

		if (len.longLen == len.shortLen) return 60;
		if (len.longLen >= (2 * len.shortLen)) return 0;

		return ((2 - (double)len.longLen / len.shortLen)*60);
	}

private:
	Length len;
};
