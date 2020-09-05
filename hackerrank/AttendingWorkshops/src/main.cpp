// "Attending Workshops" task solution (https://www.hackerrank.com/challenges/attending-workshops/problem)
// by Oleg Malts (olma@live.in)

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Solution start

#include <vector>
#include <algorithm>

struct Workshop
{
	int startTime;
	int duration;
	int endTime;

	Workshop() {}
	Workshop(int start, int d) : startTime(start), duration(d), endTime(start + d) {}

	bool operator<(const Workshop& other) const
	{
		return (startTime < other.startTime);
	}
};

struct Available_Workshops
{
	int n;
	vector<Workshop> workshops;
};

Available_Workshops* initialize(int start_time[], int duration[], int n)
{
	auto inited = new Available_Workshops;

	inited->n = n;
	inited->workshops.resize(n);

	for (int it = 0; it < n; it++)
	{
		inited->workshops.at(it) = Workshop(start_time[it], duration[it]);
	}

	sort(inited->workshops.begin(), inited->workshops.end());

	return inited;
}

int CalculateMaxWorkshops(Available_Workshops* workshops)
{
	int result = 1;
	Workshop lastWorkshop = workshops->workshops.at(0);

	for (auto& workshop : workshops->workshops)
	{
		if (workshop.startTime >= lastWorkshop.endTime)
		{
			lastWorkshop = workshop;
			result += 1;

			continue;
		}

		if (workshop.endTime < lastWorkshop.endTime)
		{
			lastWorkshop = workshop;

			continue;
		}
	}

	return result;
}

// Solution end

void test(string path, int expected)
{
	cout << path << endl;

	ifstream testcase(path);

	int n = 0;
	testcase >> n;

	int* start_time = new int[n];
	int* duration = new int[n];

	for (int i = 0; i < n; i++)
	{
		testcase >> start_time[i];
	}

	for (int i = 0; i < n; i++)
	{
		testcase >> duration[i];
	}

	Available_Workshops * ptr;
	ptr = initialize(start_time, duration, n);

	int result = CalculateMaxWorkshops(ptr);

	if (result == expected)
	{
		cout << "[OK]: " << result << endl;
	}
	else
	{
		cout << "[FAIL]: " << result << endl;
	}
}

int main(int argc, char *argv[])
{
	test("tests/testcase0.txt", 4);
	test("tests/testcase1.txt", 49);

	return 0;
}
