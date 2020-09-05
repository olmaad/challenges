// "Day 25: Running Time and Complexity" task solution (https://www.hackerrank.com/challenges/30-running-time-and-complexity/problem)
// by Oleg Malts (olma@live.in)

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <tuple>
#include <list>
#include <cmath>

#define TEST

using namespace std;

vector<tuple<int, bool>> filter(vector<int> numbers)
{
	int max_number = *max_element(numbers.begin(), numbers.end());
	int table_size = (sqrt(max_number) + 1);

	vector<bool> table(table_size, true);

	for (int it = 2; it * it < table_size; ++it)
	{
		if (table.at(it - 1) == false)
		{
			continue;
		}

		for (int p = it * it; p <= table_size; p += it * 2)
		{
			table[p - 1] = false;
		}
	}

	list<int> primes{2};

	for (int it = 3; it <= table_size; it += 2)
	{
		if (table.at(it - 1))
		{
			primes.push_back(it);
		}
	}

	vector<tuple<int, bool>> result(numbers.size());

	transform(numbers.begin(), numbers.end(), result.begin(), [&primes](const auto element)
	{
		if (element == 1)
		{
			return make_tuple(element, false);
		}

		if (element <= 3)
		{
			return make_tuple(element, true);
		}

		if (!(element & 0x1))
		{
			return make_tuple(element, false);
		}

		for (auto it : primes)
		{
			if (it >= element)
			{
				break;
			}

			if (element % it == 0)
			{
				return make_tuple(element, false);
			}
		}

		return make_tuple(element, true);
	});

	return result;
}

void test(string path, const vector<int>& expected)
{
	cout << path << endl;

	ifstream testcase(path);

	int test_count = 0;

	testcase >> test_count;

	vector<int> numbers(test_count);

	for (int it = 0; it < test_count; ++it)
	{
		testcase >> numbers[it];
	}

	auto result = filter(numbers);

	for (int it = 0; it < result.size() && it < expected.size(); ++it)
	{
		if (get<1>(result.at(it)) != expected.at(it))
		{
			cout << "[FAIL]" << endl;
			return;
		}
	}

	cout << "[OK]" << endl;
}

void run()
{
	int test_count = 0;

	cin >> test_count;

	vector<int> numbers(test_count);

	for (int it = 0; it < test_count; ++it)
	{
		cin >> numbers[it];
	}

	auto result = filter(numbers);

	for (auto it : result)
	{
		if (get<1>(it))
		{
			cout << "Prime" << endl;
		}
		else
		{
			cout << "Not prime" << endl;
		}
	}
}

int main()
{
#ifdef TEST
	test("tests/testcase0.txt", { false, true, true, false });
	test("tests/testcase5.txt", { false });
#else
	run();
#endif

	return 0;
}
