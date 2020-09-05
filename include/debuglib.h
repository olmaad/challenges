#include <iostream>

template<typename T>
void assertOutput(std::ostream& output, const T& result, const T& expected)
{
	if (result == expected)
	{
		std::cout << "[OK]: " << result << std::endl;
	}
	else
	{
		std::cout << "[FAIL]: " << result << std::endl;
	}
}

template<template <typename> class TContainer, typename TResult>
void assertOutput(std::ostream& output, const TContainer<TResult>& result, const TContainer<TResult>& expected)
{
	if (std::equal(result.begin(), result.end(), expected.begin()))
	{
		std::cout << "[OK]"<< std::endl;
	}
	else
	{
		std::cout << "[FAIL]" << std::endl
			<< "Result:" << std::endl;

		for (auto& it : result)
		{
			std::cout << it << std::endl;
		}

		std::cout << "Expected:" << std::endl;

		for (auto& it : expected)
		{
			std::cout << it << std::endl;
		}
	}
}
