// "The Grid Search" task solution (https://www.hackerrank.com/challenges/the-grid-search/problem)
// by Oleg Malts (olma@live.in)

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#define TEST

using namespace std;

bool searchNextLine(size_t expectedPos, vector<string>& G, int gIt, vector<string>& P, int pIt)
{
	if (pIt >= P.size())
	{
		return true;
	}

	if (gIt >= G.size())
	{
		return false;
	}

	size_t pos = G.at(gIt).find(P.at(pIt), expectedPos);

	if (pos != expectedPos)
	{
		return false;
	}

	return searchNextLine(expectedPos, G, gIt + 1, P, pIt + 1);
}

string gridSearch(vector<string>& G, vector<string>& P)
{
	size_t gRowSize = G.at(0).size();
	size_t pRowSize = P.at(0).size();

	for (size_t gIt = 0; gIt < G.size(); gIt++)
	{
		size_t pos = G.at(gIt).find(P.at(0));

		while (pos != string::npos)
		{
			if (searchNextLine(pos, G, gIt + 1, P, 1))
			{
				return "YES";
			}

			pos = G.at(gIt).find(P.at(0), pos + 1);
		}
	}

	return "NO";
}

void test(string path, vector<string> expected)
{
	cout << path << endl;

	ifstream testcase(path);

	int t = 0;
	testcase >> t;

	for (int it = 0; it < t; it++)
	{
		int R = 0;
		int C = 0;

		testcase >> R >> C;

		vector<string> G(R);

		for (int i = 0; i < R; i++)
		{
			testcase >> G.at(i);
		}

		int r = 0;
		int c = 0;

		testcase >> r >> c;

		vector<string> P(r);

		for (int i = 0; i < r; i++)
		{
			testcase >> P.at(i);
		}

		string result = gridSearch(G, P);

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
	int t = 0;
	cin >> t;

	ofstream fout(getenv("OUTPUT_PATH"));

	for (int it = 0; it < t; it++)
	{
		int R = 0;
		int C = 0;

		cin >> R >> C;

		vector<string> G(R);

		for (int i = 0; i < R; i++)
		{
			cin >> G.at(i);
		}

		int r = 0;
		int c = 0;

		cin >> r >> c;

		vector<string> P(r);

		for (int i = 0; i < r; i++)
		{
			cin >> P.at(i);
		}

		string result = gridSearch(G, P);

		fout << result << "\n";
	}

	fout.close();
}

int main()
{
#ifdef TEST
	test("tests/testcase0.txt", { "YES", "NO" });
	test("tests/testcase1.txt", { "NO", "YES" });
#else
	run();
#endif

	return 0;
}
