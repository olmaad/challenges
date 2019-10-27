// "The Bomberman Game" task solution (https://www.hackerrank.com/challenges/bomber-man/problem)
// by Oleg Malts (olma@live.in)

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#define TEST

using namespace std;

struct Cell
{
	enum InitialCellType
	{
		ictUnknown = -1,
		ictEmpty,
		ictNearBomb,
		ictBomb
	};

	InitialCellType type;

	Cell() : type(ictUnknown) {}
	Cell(InitialCellType t) : type(t) {}

	char getStateAt(int iteration)
	{
		int loopIteration = (iteration - 3) % 4;

		switch (type)
		{
		case Cell::ictEmpty:
		{
			if (loopIteration == 0)
			{
				return '.';
			}
			else
			{
				return 'O';
			}
		}
		case Cell::ictNearBomb:
		{
			if (loopIteration == 0 || loopIteration == 2)
			{
				return '.';
			}
			else
			{
				return 'O';
			}
		}
		case Cell::ictBomb:
		{
			if (loopIteration == 2)
			{
				return '.';
			}
			else
			{
				return 'O';
			}
		}
		}

		return ' ';
	}
};

void markNearBomb(Cell& cell)
{
	if (cell.type == Cell::ictUnknown)
	{
		cell.type = Cell::ictEmpty;
	}
}

void markBomb(size_t row, size_t column, vector<vector<Cell>>& cellGrid)
{
	size_t height = cellGrid.size();
	size_t length = cellGrid.at(0).size();

	cellGrid.at(row).at(column).type = Cell::ictEmpty;

	if (row > 0)
	{
		markNearBomb(cellGrid.at(row - 1).at(column));
	}

	if (row + 1 < height)
	{
		markNearBomb(cellGrid.at(row + 1).at(column));
	}

	if (column > 0)
	{
		markNearBomb(cellGrid.at(row).at(column - 1));
	}

	if (column + 1 < length)
	{
		markNearBomb(cellGrid.at(row).at(column + 1));
	}
}

void markNearEmpty(Cell& cell)
{
	if (cell.type == Cell::ictEmpty)
	{
		cell.type = Cell::ictNearBomb;
	}
}

void markEmpty(size_t row, size_t column, vector<vector<Cell>>& cellGrid)
{
	size_t height = cellGrid.size();
	size_t length = cellGrid.at(0).size();

	cellGrid.at(row).at(column).type = Cell::ictBomb;

	if (row > 0)
	{
		markNearEmpty(cellGrid.at(row - 1).at(column));
	}

	if (row + 1 < height)
	{
		markNearEmpty(cellGrid.at(row + 1).at(column));
	}

	if (column > 0)
	{
		markNearEmpty(cellGrid.at(row).at(column - 1));
	}

	if (column + 1 < length)
	{
		markNearEmpty(cellGrid.at(row).at(column + 1));
	}
}

vector<string> bomberMan(int n, vector<string>& grid)
{
	size_t height = grid.size();
	size_t length = grid.at(0).size();

	if (n == 1)
	{
		return grid;
	}

	vector<string> result(height);

	if (n == 2)
	{
		for (auto& it : result)
		{
			it.resize(length);

			fill(it.begin(), it.end(), 'O');
		}

		return result;
	}

	vector<vector<Cell>> cellGrid(height);

	for (auto& it : cellGrid)
	{
		it.resize(length);
	}

	for (size_t row = 0; row < height; row++)
	{
		for (size_t column = 0; column < length; column++)
		{
			switch (grid.at(row).at(column))
			{
			case 'O':
			{
				markBomb(row, column, cellGrid);
				break;
			}
			}
		}
	}

	for (size_t row = 0; row < height; row++)
	{
		for (size_t column = 0; column < length; column++)
		{
			auto& cell = cellGrid.at(row).at(column);

			if (cell.type == Cell::ictUnknown)
			{
				markEmpty(row, column, cellGrid);
			}
		}
	}

	for (size_t row = 0; row < height; row++)
	{
		result.at(row).resize(length);

		for (size_t column = 0; column < length; column++)
		{
			result.at(row).at(column) = cellGrid.at(row).at(column).getStateAt(n);
		}
	}

	return result;
}

void test(string path)
{
	cout << path << endl;

	ifstream testcase(path);

	int r = 0;
	int c = 0;
	int n = 0;

	testcase >> r >> c >> n;

	vector<string> grid(r);

	for (int i = 0; i < r; i++)
	{
		testcase >> grid.at(i);
	}

	auto result = bomberMan(n, grid);

	for (auto& it : result)
	{
		cout << it << endl;
	}
}

void run()
{
	int r = 0;
	int c = 0;
	int n = 0;

	cin >> r >> c >> n;

	vector<string> grid(r);

	for (int i = 0; i < r; i++)
	{
		cin >> grid.at(i);
	}

	auto result = bomberMan(n, grid);

	ofstream fout(getenv("OUTPUT_PATH"));

	for (auto& it : result)
	{
		fout << it << "\n";
	}

	fout.close();
}

int main()
{
#ifdef TEST
	test("tests/testcase0.txt");
	test("tests/testcase1.txt");
#else
	run();
#endif

	return 0;
}
