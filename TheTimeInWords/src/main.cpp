// "The Time in Words" task solution (https://www.hackerrank.com/challenges/the-time-in-words/problem)
// by Oleg Malts (olma@live.in)

#include <iostream>
#include <fstream>
#include <map>
#include <string>

#define TEST

using namespace std;

map<int, string> minutesToWordsMap = {
{ 1, "one minute" },
{ 2, "two minutes" },
{ 3, "three minutes" },
{ 4, "four minutes" },
{ 5, "five minutes" },
{ 6, "six minutes" },
{ 7, "seven minutes" },
{ 8, "eight minutes" },
{ 9, "nine minutes" },
{ 10, "ten minutes" },
{ 11, "eleven minutes" },
{ 12, "twelve minutes" },
{ 13, "thirteen minutes" },
{ 14, "fourteen minutes" },
{ 15, "quarter" },
{ 16, "sixteen minutes" },
{ 17, "seventeen minutes" },
{ 18, "eighten minutes" },
{ 19, "nineteen minutes" },
{ 20, "twenty" },
{ 30, "half" }
};

map<int, string> hoursToWordsMap = {
{ 1, "one" },
{ 2, "two" },
{ 3, "three" },
{ 4, "four" },
{ 5, "five" },
{ 6, "six" },
{ 7, "seven" },
{ 8, "eight" },
{ 9, "nine" },
{ 10, "ten" },
{ 11, "eleven" },
{ 12, "twelve" }
};

string timeInWords(int h, int m)
{
	if (m == 0)
	{
		return hoursToWordsMap.at(h) + " o' clock";
	}

	if (m <= 30)
	{
		if (m < 20)
		{
			return minutesToWordsMap.at(m) + " past " + hoursToWordsMap.at(h);
		}
		else if (m == 20)
		{
			return minutesToWordsMap.at(m) + " minutes past " + hoursToWordsMap.at(h);
		}
		else if (m < 30)
		{
			return minutesToWordsMap.at(20) + " " + minutesToWordsMap.at(m % 10) + " past " + hoursToWordsMap.at(h);
		}
		else
		{
			return minutesToWordsMap.at(30) + " past " + hoursToWordsMap.at(h);
		}
	}
	else
	{
		h = h + 1;

		if (h > 12)
		{
			h = 1;
		}

		m = 60 - m;

		if (m < 20)
		{
			return minutesToWordsMap.at(m) + " to " + hoursToWordsMap.at(h);
		}
		else if (m == 20)
		{
			return minutesToWordsMap.at(m) + " minutes to " + hoursToWordsMap.at(h);
		}
		else
		{
			return minutesToWordsMap.at(20) + " " + minutesToWordsMap.at(m % 10) + " to " + hoursToWordsMap.at(h);
		}
	}

	return {};
}

void test(string path, string expected)
{
	cout << path << endl;

	ifstream testcase(path);

	int h = 0;
	testcase >> h;

	int m = 0;
	testcase >> m;

	string result = timeInWords(h, m);

	if (result == expected)
	{
		cout << "[OK]: " << result << endl;
	}
	else
	{
		cout << "[FAIL]: " << result << endl;
	}
}

void run()
{
	int h = 0;
	cin >> h;

	int m = 0;
	cin >> m;

	string result = timeInWords(h, m);

	ofstream fout(getenv("OUTPUT_PATH"));

	fout << result << "\n";

	fout.close();
}

int main()
{
#ifdef TEST
	test("tests/testcase0.txt", "thirteen minutes to six");
	test("tests/testcase1.txt", "three o' clock");
	test("tests/testcase2.txt", "quarter past seven");
#else
	run();
#endif

	return 0;
}

