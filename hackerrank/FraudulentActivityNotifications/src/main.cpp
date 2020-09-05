// "Fraudulent Activity Notifications" task solution (https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem)
// by Oleg Malts (olma@live.in)

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>

#define TEST

using namespace std;

int activityNotifications(vector<int> expenditure, int dataLength)
{
	int result = 0;

	auto dataFront = expenditure.begin();
	auto dataBack = expenditure.begin();

	vector<int> sortedData(dataLength);

	for (int it = 0; it < dataLength; it++)
	{
		dataBack++;

		sortedData.at(it) = expenditure.at(it);
	}

	sort(sortedData.begin(), sortedData.end());

	for (size_t it = dataLength; it < expenditure.size(); it++)
	{
		double median = 0;

		if (dataLength % 2 == 0)
		{
			median = static_cast<double>(sortedData.at(sortedData.size() / 2 - 1) + sortedData.at(sortedData.size() / 2)) / 2;
		}
		else
		{
			median = sortedData.at((sortedData.size() - 1) / 2);
		}

		if (expenditure.at(it) >= median * 2)
		{
			result += 1;
		}

		auto findResult = find(sortedData.begin(), sortedData.end(), *dataFront);

		sortedData.erase(findResult);

		auto lowerResult = lower_bound(sortedData.begin(), sortedData.end(), expenditure.at(it));

		sortedData.insert(lowerResult, expenditure.at(it));

		dataFront++;
		dataBack++;
	}

	return result;
}

void test(string path, int expected)
{
	cout << path << endl;

	ifstream testcase(path);

	int n = 0;
	int d = 0;

	testcase >> n >> d;

	vector<int> expenditure(n);

	for (int it = 0; it < n; it++)
	{
		testcase >> expenditure.at(it);
	}

	int result = activityNotifications(expenditure, d);

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
	int d = 0;

	cin >> n >> d;

	vector<int> expenditure(n);

	for (int it = 0; it < n; it++)
	{
		cin >> expenditure.at(it);
	}

	int result = activityNotifications(expenditure, d);

	ofstream fout(getenv("OUTPUT_PATH"));

	fout << result << "\n";

	fout.close();
}

int main()
{
#ifdef TEST
	test("tests/mytestcase0.txt", 2);
#else
	run();
#endif

	return 0;
}
