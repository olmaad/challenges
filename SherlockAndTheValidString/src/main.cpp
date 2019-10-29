// "Sherlock and the Valid String" task solution (https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem)
// by Oleg Malts (olma@live.in)

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <list>

#define TEST

using namespace std;

struct Verification
{
	bool result = true;
	int maxCount = 0;

	Verification(int max) : maxCount(max) {}

	virtual void verifyNext(int count) = 0;
};

struct NoRemoveVerification : public Verification
{
	NoRemoveVerification(int max) : Verification(max) {}

	void verifyNext(int count)
	{
		if (count != maxCount)
		{
			result = false;
		}
	}
};

struct MaxRemoveVerification : public Verification
{
	bool maxFound = false;

	MaxRemoveVerification(int max) : Verification(max) {}

	void verifyNext(int count)
	{
		if (count == maxCount)
		{
			if (maxFound)
			{
				result = false;
			}

			maxFound = true;
		}

		if (count != maxCount && count != maxCount - 1)
		{
			result = false;
		}
	}
};

struct MinRemoveVerification : public Verification
{
	bool minFound = false;

	MinRemoveVerification(int max) : Verification(max) {}

	void verifyNext(int count)
	{
		if (count == 1)
		{
			if (minFound)
			{
				result = false;
			}

			minFound = true;
		}

		if (count != maxCount && count != 1)
		{
			result = false;
		}
	}
};

string isValid(string s)
{
	vector<int> counts(26);

	fill(counts.begin(), counts.end(), 0);

	int maxCount = 0;

	for (auto& it : s)
	{
		auto& count = counts.at(it - 'a');

		count += 1;

		if (count > maxCount)
		{
			maxCount = count;
		}
	}

	list<shared_ptr<Verification>> verifications {
	make_shared<NoRemoveVerification>(maxCount),
	make_shared<MaxRemoveVerification>(maxCount),
	make_shared<MinRemoveVerification>(maxCount),
	};

	for (auto& it : counts)
	{
		if (it == 0)
		{
			continue;
		}

		for (auto& verification : verifications)
		{
			verification->verifyNext(it);
		}
	}

	for (auto& verification : verifications)
	{
		if (verification->result)
		{
			return "YES";
		}
	}

	return "NO";
}

void test(string path, string expected)
{
	cout << path << endl;

	ifstream testcase(path);

	string s;

	testcase >> s;

	string result = isValid(s);

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

	string result = isValid(s);

	ofstream fout(getenv("OUTPUT_PATH"));

	fout << result << "\n";

	fout.close();
}

int main()
{
#ifdef TEST
	test("tests/testcase0.txt", "NO");
	test("tests/testcase1.txt", "YES");
#else
	run();
#endif

	return 0;
}