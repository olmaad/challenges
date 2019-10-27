// "Organizing Containers of Balls" task solution (https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem)
// by Oleg Malts (olma@live.in)

#include <vector>
#include <set>
#include <iostream>
#include <fstream>
#include <string>

#define TEST

using namespace std;

void fillSums(vector<vector<int>>& containers, vector<vector<int>>& sums)
{
	size_t size = containers.size();

	for (auto& it : sums)
	{
		it.resize(size);
		fill(it.begin(), it.end(), 0);
	}

	for (int containerIt = 0; containerIt < size; containerIt++)
	{
		for (int it = 0; it < size; it++)
		{
			for (int x = 0; x < size; x++)
			{
				if (x != it)
				{
					sums.at(containerIt).at(x) += containers.at(containerIt).at(it);
				}
			}

			for (int y = 0; y < size; y++)
			{
				if (y != containerIt)
				{
					sums.at(y).at(it) -= containers.at(containerIt).at(it);
				}
			}
		}
	}
}

bool checkSumMatrix(const vector<vector<int>>& sums, const set<int>& exclude, int from)
{
	if (from >= sums.size())
	{
		return true;
	}

	bool result = false;

	auto& currentSum = sums.at(from);

	for (int it = 0; it < currentSum.size(); it++)
	{
		if (currentSum.at(it) == 0 && !exclude.count(it))
		{
			auto newExclude = exclude;
			newExclude.emplace(it);

			if (checkSumMatrix(sums, newExclude, from + 1))
			{
				result = true;
			}
		}
	}

	return result;
}

string organizingContainers(vector<vector<int>>& containers)
{
	size_t size = containers.size();

	vector<vector<int>> sums(size);

	fillSums(containers, sums);

	if (checkSumMatrix(sums, {}, 0))
	{
		return "Possible";
	}

	return "Impossible";
}

void test(string path, const vector<string>& expected)
{
	cout << path << endl;

	ifstream testcase(path);

	int q = 0;

	testcase >> q;

	for (int it = 0; it < q; it++)
	{
		int n = 0;

		testcase >> n;

		vector<vector<int>> container(n);

		for (int i = 0; i < n; i++)
		{
			container[i].resize(n);

			for (int j = 0; j < n; j++)
			{
				testcase >> container.at(i).at(j);
			}
		}

		string result = organizingContainers(container);

		if (result == expected.at(it))
		{
			cout << "[OK]: " << result << endl;
		}
		else
		{
			cout << "[FAIL]: " << result << endl;
		}
	}
}

void run()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	int q = 0;

	cin >> q;

	for (int it = 0; it < q; it++)
	{
		int n = 0;

		cin >> n;

		vector<vector<int>> container(n);

		for (int i = 0; i < n; i++)
		{
			container[i].resize(n);

			for (int j = 0; j < n; j++)
			{
				cin >> container.at(i).at(j);
			}
		}

		string result = organizingContainers(container);

		fout << result << "\n";
	}

	fout.close();
}

int main()
{
#ifdef TEST
	test("tests/testcase0.txt", { "Possible", "Impossible" });
	test("tests/testcase1.txt", {
	"Possible",
	"Possible",
	"Possible",
	"Impossible",
	"Possible",
	"Impossible",
	"Possible",
	"Possible",
	"Possible",
	"Possible"});
#else
	run();
#endif

	return 0;
}
