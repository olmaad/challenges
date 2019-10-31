// "C++ Variadics" task solution (https://www.hackerrank.com/challenges/cpp-variadics/problem)
// by Oleg Malts (olma@live.in)

#include <iostream>
#include <fstream>
#include <string>

#define TEST

using namespace std;

template<typename=void>
int reversed_binary_value()
{
	return 0;
}

template<bool value, bool... values>
int reversed_binary_value()
{
	return (reversed_binary_value<values...>() << 1) | value;
}

template <int n, bool...digits>
struct CheckValues {
	static void check(int x, int y)
	{
		CheckValues<n - 1, 0, digits...>::check(x, y);
		CheckValues<n - 1, 1, digits...>::check(x, y);
	}
};

template <bool...digits>
struct CheckValues<0, digits...> {
	static void check(int x, int y)
	{
		int z = reversed_binary_value<digits...>();
		std::cout << (z + 64 * y == x);
	}
};

void test(string path)
{
	cout << path << endl;

	ifstream testcase(path);

	int t = 0;
	testcase >> t;

	for (int i = 0; i != t; ++i)
	{
		int x = 0;
		int y = 0;
		testcase >> x >> y;

		CheckValues<6>::check(x, y);

		cout << endl;
	}
}

void run()
{
	int t = 0;
	std::cin >> t;

	for (int i = 0; i != t; ++i)
	{
		int x = 0;
		int y = 0;
		cin >> x >> y;

		CheckValues<6>::check(x, y);

		cout << "\n";
	}
}

int main()
{
#ifdef TEST
	test("tests/testcase0.txt");
#else
	run();
#endif

}
