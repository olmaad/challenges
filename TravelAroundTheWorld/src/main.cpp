// "Travel around the world" task solution (https://www.hackerrank.com/challenges/travel-around-the-world/problem)
// by Oleg Malts (olma@live.in)

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#define TEST

using namespace std;

int calculate(int64_t capacity, vector<int>& fuelInCities, vector<int>& travelCosts)
{
	size_t size = fuelInCities.size();

	int result = 0;
	int64_t segmentSum = 0;

	for (size_t it = 1; it <= size; it++)
	{
		segmentSum = segmentSum - travelCosts.at(size - it);

		if (segmentSum + capacity < 0)
		{
			return 0;
		}

		segmentSum = segmentSum + fuelInCities.at(size - it);

		if (segmentSum >= 0)
		{
			result += 1;
			segmentSum = 0;
		}
	}

	if (segmentSum >= 0)
	{
		return result;
	}

	bool corrected = false;
	int64_t correctionSegmentSum = 0;

	for (size_t it = 1; it <= size; it++)
	{
		segmentSum = segmentSum - travelCosts.at(size - it);
		correctionSegmentSum = correctionSegmentSum - travelCosts.at(size - it);

		if (segmentSum + capacity < 0)
		{
			return 0;
		}

		segmentSum = segmentSum + fuelInCities.at(size - it);
		correctionSegmentSum = correctionSegmentSum + fuelInCities.at(size - it);

		if (segmentSum >= 0)
		{
			corrected = true;
		}

		if (correctionSegmentSum >= 0)
		{
			if (corrected)
			{
				break;
			}

			result -= 1;
			correctionSegmentSum = 0;
		}
	}

	return result;
}

void test(string path, int expected)
{
	cout << path << endl;

	ifstream testcase(path);

	int n = 0;
	int64_t c = 0;

	testcase >> n >> c;

	vector<int> fuelInCities(n);

	for (int it = 0; it < n; it++)
	{
		testcase >> fuelInCities.at(it);
	}

	vector<int> travelCosts(n);

	for (int it = 0; it < n; it++)
	{
		testcase >> travelCosts.at(it);
	}

	int result = calculate(c, fuelInCities, travelCosts);

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
	int64_t c = 0;

	cin >> n >> c;

	vector<int> fuelInCities(n);

	for (int it = 0; it < n; it++)
	{
		cin >> fuelInCities.at(it);
	}

	vector<int> travelCosts(n);

	for (int it = 0; it < n; it++)
	{
		cin >> travelCosts.at(it);
	}

	int result = calculate(c, fuelInCities, travelCosts);

	ofstream fout(getenv("OUTPUT_PATH"));

	fout << result << "\n";

	fout.close();
}

int main()
{
#ifdef TEST
	test("tests/mytestcase0.txt", 1);
	test("tests/testcase0.txt", 67608);
	test("tests/testcase1.txt", 67740);
	test("tests/testcase3.txt", 68074);
	test("tests/testcase6.txt", 67428);
#else
	run();
#endif

	return 0;
}
