// "Climbing the Leaderboard" task solution (https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem)
// by Oleg Malts (olma@live.in)

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

#define TEST

using namespace std;

vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
	vector<int> result;
	vector<int> uniqueScores;

	unique_copy(scores.begin(), scores.end(), back_inserter(uniqueScores));

	for (auto& it : alice)
	{
		int rPlace = distance(uniqueScores.rbegin(), upper_bound(uniqueScores.rbegin(), uniqueScores.rend(), it));

		result.push_back(uniqueScores.size() - rPlace + 1);
	}

	return result;
}

void test(string path, const vector<int>& expected)
{
	cout << path << endl;

	ifstream testcase(path);

	int scores_count = 0;
	testcase >> scores_count;

	vector<int> scores(scores_count);

	for (int i = 0; i < scores_count; i++)
	{
		testcase >> scores.at(i);
	}

	int alice_count = 0;
	testcase >> alice_count;

	vector<int> alice(alice_count);

	for (int i = 0; i < alice_count; i++)
	{
		testcase >> alice.at(i);
	}

	vector<int> result = climbingLeaderboard(scores, alice);

	for (int it = 0; it < result.size(); it++)
	{
		if (result.at(it) == expected.at(it))
		{
			cout << "[OK]: " << result.at(it) << endl;
		}
		else
		{
			cout << "[FAIL]: " << result.at(it) << endl;
		}
	}
}

void run()
{
	int scores_count = 0;
	cin >> scores_count;

	vector<int> scores(scores_count);

	for (int i = 0; i < scores_count; i++)
	{
		cin >> scores.at(i);
	}

	int alice_count = 0;
	cin >> alice_count;

	vector<int> alice(alice_count);

	for (int i = 0; i < alice_count; i++)
	{
		cin >> alice.at(i);
	}

	vector<int> result = climbingLeaderboard(scores, alice);

	ofstream fout(getenv("OUTPUT_PATH"));

	for (int i = 0; i < result.size(); i++)
	{
		fout << result[i] << "\n";
	}

	fout.close();
}

int main()
{
#ifdef TEST
	test("tests/testcase0.txt", { 6, 4, 2, 1 });
	test("tests/testcase1.txt", { 6, 5, 4, 2, 1 });
#else
	run();
#endif

	return 0;
}
