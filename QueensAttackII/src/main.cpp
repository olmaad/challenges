// "Queen's Attack II" task solution (https://www.hackerrank.com/challenges/queens-attack-2/problem)
// by Oleg Malts (olma@live.in)

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

#define TEST

using namespace std;

struct s_point
{
	s_point() : row(0), column(0) {}
	s_point(int r, int c) : row(r), column(c) {}

	int row;
	int column;
};

struct s_obstacles
{
	s_point top;
	s_point topRight;
	s_point right;
	s_point bottomRight;
	s_point bottom;
	s_point bottomLeft;
	s_point left;
	s_point topLeft;
};

int queensAttack(int n, int k, int r_q, int c_q, vector<s_point> obstacles)
{
	s_obstacles valuableObstacles;
	valuableObstacles.top = s_point(n + 1, c_q);
	valuableObstacles.topRight = s_point(r_q + min(n + 1 - r_q, n + 1 - c_q), c_q + min(n + 1 - r_q, n + 1 - c_q));
	valuableObstacles.right = s_point(r_q, n + 1);
	valuableObstacles.bottomRight = s_point(r_q - min(r_q, n + 1 - c_q), c_q + min(r_q, n + 1 - c_q));
	valuableObstacles.bottom = s_point(0, c_q);
	valuableObstacles.bottomLeft = s_point(r_q - min(r_q, c_q), c_q - min(r_q, c_q));
	valuableObstacles.left = s_point(r_q, 0);
	valuableObstacles.topLeft = s_point(r_q + min(n + 1 - r_q, c_q), c_q - min(n + 1 - r_q, c_q));

	for (auto& obstacle : obstacles)
	{
		// Top
		if (obstacle.column == c_q && obstacle.row > r_q && obstacle.row < valuableObstacles.top.row)
		{
			valuableObstacles.top = obstacle;
		}
		// Top right
		else if (obstacle.row > r_q && obstacle.row - r_q == obstacle.column - c_q && obstacle.row < valuableObstacles.topRight.row)
		{
			valuableObstacles.topRight = obstacle;
		}
		// Right
		else if (obstacle.row == r_q && obstacle.column > c_q && obstacle.column < valuableObstacles.right.column)
		{
			valuableObstacles.right = obstacle;
		}
		// Bottom right
		else if (obstacle.column > c_q && r_q - obstacle.row == obstacle.column - c_q && obstacle.column < valuableObstacles.bottomRight.column)
		{
			valuableObstacles.bottomRight = obstacle;
		}
		// Bottom
		else if (obstacle.column == c_q && obstacle.row < r_q && obstacle.row > valuableObstacles.bottom.row)
		{
			valuableObstacles.bottom = obstacle;
		}
		// Bottom left
		else if (obstacle.column < c_q && r_q - obstacle.row == c_q - obstacle.column && obstacle.column > valuableObstacles.bottomLeft.column)
		{
			valuableObstacles.bottomLeft = obstacle;
		}
		// Left
		else if (obstacle.row == r_q && obstacle.column < c_q && obstacle.column > valuableObstacles.left.column)
		{
			valuableObstacles.left = obstacle;
		}
		// Top left
		else if (obstacle.row > r_q && obstacle.row - r_q == c_q - obstacle.column && obstacle.column > valuableObstacles.topLeft.column)
		{
			valuableObstacles.topLeft = obstacle;
		}
	}

	int result =
		valuableObstacles.top.row - r_q - 1 +
		valuableObstacles.topRight.row - r_q - 1 +
		valuableObstacles.right.column - c_q - 1 +
		r_q - valuableObstacles.bottomRight.row - 1 +
		r_q - valuableObstacles.bottom.row - 1 +
		r_q - valuableObstacles.bottomLeft.row - 1 +
		c_q - valuableObstacles.left.column - 1 +
		valuableObstacles.topLeft.row - r_q - 1;

	return result;
}

void test(string path, int expected)
{
	cout << path << endl;

	ifstream testcase(path);

	int n = 0;
	int k = 0;
	int r_q = 0;
	int c_q = 0;

	testcase >> n >> k >> r_q >> c_q;

	vector<s_point> obstacles(k);

	for (int it = 0; it < k; it++)
	{
		testcase >> obstacles.at(it).row >> obstacles.at(it).column;
	}

	int result = queensAttack(n, k, r_q, c_q, obstacles);

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
	int k = 0;
	int r_q = 0;
	int c_q = 0;

	cin >> n >> k >> r_q >> c_q;

	vector<s_point> obstacles(k);

	for (int it = 0; it < k; it++)
	{
		cin >> obstacles.at(it).row >> obstacles.at(it).column;
	}

	int result = queensAttack(n, k, r_q, c_q, obstacles);

	ofstream fout(getenv("OUTPUT_PATH"));

	fout << result << "\n";

	fout.close();
}

int main()
{
#ifdef TEST
	test("tests/testcase0.txt", 9);
	test("tests/testcase1.txt", 10);
#else
	run();
#endif

	return 0;
}
