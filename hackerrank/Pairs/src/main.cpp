// "Pairs" task solution (https://www.hackerrank.com/challenges/pairs/problem)
// by Oleg Malts (olma@live.in)

#include <vector>
#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#define TEST

using namespace std;

int calculate(int target, vector<int>& numbers)
{
	sort(numbers.begin(), numbers.end());

	int result = 0;

	auto it = numbers.begin() + 1;
	auto search = numbers.begin();

	for (; it != numbers.end(); it++)
	{
		for (; search != it; search++)
		{
			if (*search > *it - target)
			{
				break;
			}
			else if (*search == *it - target)
			{
				result += 1;
				break;
			}
		}
	}

	return result;
}

void test(string path, int expected)
{
	cout << path << endl;

	ifstream testcase(path);

	int count = 0;
	int target = 0;

	testcase >> count >> target;

	vector<int> numbers(count);

	for (int it = 0; it < count; ++it)
	{
		testcase >> numbers[it];
	}

	int result = calculate(target, numbers);

	if (true)
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
	int count = 0;
	int target = 0;

	cin >> count >> target;

	vector<int> numbers(count);

	for (int it = 0; it < count; ++it)
	{
		cin >> numbers[it];
	}

	int result = calculate(target, numbers);

	cout << result << endl;
}

int main()
{
#ifdef TEST
	test("tests/testcase0.txt", 3);
#else
	run();
#endif

	return 0;
}
