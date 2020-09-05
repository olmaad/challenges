// "Day 28: RegEx, Patterns, and Intro to Databases" task solution (https://www.hackerrank.com/challenges/30-regex-patterns/problem)
// by Oleg Malts (olma@live.in)

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <tuple>
#include <list>
#include <regex>

#define TEST

using namespace std;

list<string> filter(const list<tuple<string, string>>& input)
{
	regex email_regex("[a-z.]+@gmail\.com$");
	smatch email_match;

	string name;
	string email;

	list<string> result;

	for (auto& it : input)
	{
		tie(name, email) = it;

		if (regex_match(email, email_match, email_regex))
		{
			result.push_back(name);
		}
	}

	result.sort();

	return result;
}

void test(string path, const list<string>& expected)
{
	cout << path << endl;

	ifstream testcase(path);

	int test_count = 0;

	testcase >> test_count;

	list<tuple<string, string>> input;

	for (int it = 0; it < test_count; ++it)
	{
		string name;
		string email;

		testcase >> name >> email;

		input.push_back(make_tuple(name, email));
	}

	auto result = filter(input);

	if (equal(result.begin(), result.end(), expected.begin()))
	{
		cout << "[OK]" << endl;
	}
	else
	{
		cout << "[FAIL]" << endl;
	}
}

void run()
{
	int test_count = 0;

	cin >> test_count;

	list<tuple<string, string>> input;

	for (int it = 0; it < test_count; ++it)
	{
		string name;
		string email;

		cin >> name >> email;

		input.push_back(make_tuple(name, email));
	}

	auto result = filter(input);

	for (const auto& it : result)
	{
		cout << it << "\n";
	}
}

int main()
{
#ifdef TEST
	test("tests/testcase0.txt", { "julia", "julia", "riya", "samantha", "tanya" });
#else
	run();
#endif

	return 0;
}
