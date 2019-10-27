// "Encryption" task solution (https://www.hackerrank.com/challenges/encryption/problem)
// by Oleg Malts (olma@live.in)

#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>

#define TEST

using namespace std;

string encryption(string s)
{
	ostringstream result;
	string temp;

	remove_copy(s.begin(), s.end(), back_inserter(temp), ' ');

	double sqr = sqrt(temp.size());
	int lines = floor(sqr);
	int columns = ceil(sqr);

	if (lines * columns < temp.size())
	{
		lines++;
	}

	for (int x = 0; x < columns; x++)
	{
		for (int y = 0; y < lines; y++)
		{
			if (temp.size() <= x + y * columns)
			{
				break;
			}

			result << temp.at(x + y * columns);
		}

		if (x < columns - 1)
		{
			result << ' ';
		}
	}

	return result.str();
}

void test(string path, string expected)
{
	cout << path << endl;

	ifstream testcase(path);

	string s;
	testcase >> s;

	string result = encryption(s);

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
	string s;
	cin >> s;

	string result = encryption(s);

	ofstream fout(getenv("OUTPUT_PATH"));

	fout << result << "\n";

	fout.close();
}

int main()
{
#ifdef TEST
	test("tests/testcase0.txt", "hae and via ecy");
	test("tests/testcase1.txt", "fto ehg ee dd");
	test("tests/testcase2.txt", "clu hlt io");
#else
	run();
#endif

	return 0;
}
