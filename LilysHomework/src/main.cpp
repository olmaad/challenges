// "Lily's Homework" task solution (https://www.hackerrank.com/challenges/lilys-homework/problem)
// by Oleg Malts (olma@live.in)

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#define TEST

using namespace std;

template<typename Iterator>
int calculate(vector<int> arr, Iterator sortedIt)
{
	int result = 0;

	auto arrIt = arr.begin();

	while (arrIt != arr.end())
	{
		if (*arrIt != *sortedIt)
		{
			auto requested = find(arrIt, arr.end(), *sortedIt);

			int temp = *arrIt;
			*arrIt = *requested;
			*requested = temp;

			result += 1;
		}

		arrIt++;
		sortedIt++;
	}

	return result;
}

int lilysHomework(vector<int>& arr)
{
	auto sorted = arr;

	sort(sorted.begin(), sorted.end());

	int resultForward = calculate(arr, sorted.begin());
	int resultBackward = calculate(arr, sorted.rbegin());

	return min(resultForward, resultBackward);
}

void test(string path, int expected)
{
	cout << path << endl;

	ifstream testcase(path);

	int n = 0;
	testcase >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++)
	{
		testcase >> arr.at(i);
	}

	int result = lilysHomework(arr);

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
	int n = 0;
	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr.at(i);
	}

	int result = lilysHomework(arr);

	ofstream fout(getenv("OUTPUT_PATH"));

	fout << result << "\n";

	fout.close();
}

int main()
{
#ifdef TEST
	test("tests/testcase0.txt", 2);
	test("tests/testcase1.txt", 2);
	test("tests/testcase2.txt", 268);
#else
	run();
#endif

	return 0;
}
