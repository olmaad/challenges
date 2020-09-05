// "Bit Array" task solution (https://www.hackerrank.com/challenges/bitset-1/problem)
// by Oleg Malts (olma@live.in)

#include <string>
#include <iostream>
#include <fstream>
#include <cstring>

#define TEST

using namespace std;

int calculate(int N, uint32_t S, uint32_t P, uint32_t Q)
{
	int result = 1;

	uint32_t first = S & 0x7FFFFFFF;
	uint32_t last = first;

	for (int counter = 1; counter < N; ++counter)
	{
		uint32_t current = (last * P + Q) & 0x7FFFFFFF;

		if (current == first || current == last)
		{
			return result;
		}

		last = current;
		++result;
	}

	return result;
}

void test(string path, int expected)
{
	cout << path << endl;

	ifstream testcase(path);

	int N = 0;
	uint32_t S = 0;
	uint32_t P = 0;
	uint32_t Q = 0;

	testcase >> N >> S >> P >> Q;

	int result = calculate(N, S, P, Q);

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
	int N = 0;
	uint32_t S = 0;
	uint32_t P = 0;
	uint32_t Q = 0;

	cin >> N >> S >> P >> Q;

	int result = calculate(N, S, P, Q);

	cout << result << "\n";
}

int main()
{
#ifdef TEST
	test("tests/input10.txt", 3);
	test("tests/testcase5.txt", 31);
	test("tests/testcase6.txt", 100000000);
	test("tests/testcase8.txt", 26);
#else
	run();
#endif

	return 0;
}
