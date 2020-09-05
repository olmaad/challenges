// "3D Surface Area" task solution (https://www.hackerrank.com/challenges/3d-surface-area/problem)
// by Oleg Malts (olma@live.in)

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#define TEST

using namespace std;

int surfaceArea(vector<vector<int>> A)
{
	int result = 0;

	for (auto& row : A)
	{
		int lastHeight = 0;

		for (auto& it : row)
		{
			result += abs(it - lastHeight);

			lastHeight = it;

			if (it > 0)
			{
				//Top and bottom
				result += 2;
			}
		}

		result += lastHeight;
	}

	int columns = A.at(0).size();

	for (int column = 0; column < columns; column++)
	{
		int lastHeight = 0;

		for (int row = 0; row < A.size(); row++)
		{
			int height = A.at(row).at(column);

			result += abs(height - lastHeight);

			lastHeight = height;
		}

		result += lastHeight;
	}

	return result;
}

void test(string path, int expected)
{
	cout << path << endl;

	ifstream testcase(path);

	int H = 0;
	int W = 0;

	testcase >> H >> W;

	vector<vector<int>> A(H);

	for (int i = 0; i < H; i++)
	{
		A.at(i).resize(W);

		for (int j = 0; j < W; j++)
		{
			testcase >> A.at(i).at(j);
		}
	}

	int result = surfaceArea(A);

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
	int H = 0;
	int W = 0;

	cin >> H >> W;

	vector<vector<int>> A(H);

	for (int i = 0; i < H; i++)
	{
		A.at(i).resize(W);

		for (int j = 0; j < W; j++)
		{
			cin >> A.at(i).at(j);
		}
	}

	int result = surfaceArea(A);

	ofstream fout(getenv("OUTPUT_PATH"));

	fout << result << "\n";

	fout.close();
}

int main()
{
#ifdef TEST
	test("tests/testcase0.txt", 6);
	test("tests/testcase1.txt", 60);
#else
	run();
#endif

	return 0;
}
