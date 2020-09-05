// "Dummy" task solution (https://www.hackerrank.com/challenges/dummy/problem)
// by Oleg Malts (olma@live.in)

#ifdef TEST
#include "debuglib.h"
#endif //TEST

#include <iostream>
#include <fstream>
#include <string>

int calculate(int number)
{
	return number;
}

void test(std::string path, int expected)
{
	std::cout << path << std::endl;

	std::ifstream testcase(path);

	int input = 0;

	testcase >> input;

	int result = calculate(input);

	assertOutput(std::cout, result, expected);
}

void run()
{
	int input = 0;

	std::cin >> input;

	int result = calculate(input);

	std::cout << result << std::endl;
}

int main()
{
#ifdef TEST
	test("tests/input.txt", 42);
#else
	run();
#endif

	return 0;
}
