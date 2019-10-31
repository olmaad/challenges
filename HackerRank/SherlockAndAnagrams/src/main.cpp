// "Sherlock and Anagrams" task solution (https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem)
// by Oleg Malts (olma@live.in)

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>

#define TEST

using namespace std;

struct AnagramHash
{
	vector<char> counts;

	AnagramHash(const vector<char>& source) : counts(source) {}

	bool operator==(const AnagramHash& other) const
	{
		return counts == other.counts;
	}
};

namespace std
{
	template<>
	struct hash<AnagramHash>
	{
		size_t operator()(const AnagramHash& s) const noexcept
		{
			size_t result = s.counts.at(0);

			for (size_t it = 1; it < s.counts.size(); it++)
			{
				result = result ^ (s.counts.at(it) << it * 2);
			}

			return result;
		}
	};
}

int sherlockAndAnagrams(string s)
{
	size_t size = s.size();

	int result = 0;
	unordered_multiset<AnagramHash> anagramSet;

	for (size_t it = 0; it < size; it++)
	{
		vector<char> hashSource(26);

		fill(hashSource.begin(), hashSource.end(), 0);

		for (size_t secondaryIt = it; secondaryIt < size; secondaryIt++)
		{
			hashSource.at(s.at(secondaryIt) - 'a') += 1;

			auto emplaceIt = anagramSet.emplace(hashSource);
			auto count = anagramSet.count(*emplaceIt);

			if (count > 1)
			{
				result += count - 1;
			}
		}
	}

	return result;
}

void test(string path, vector<int> expected)
{
	cout << path << endl;

	ifstream testcase(path);

	int q = 0;
	testcase >> q;

	for (int it = 0; it < q; it++)
	{
		string s;

		testcase >> s;

		int result = sherlockAndAnagrams(s);

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
	int q = 0;
	cin >> q;

	ofstream fout(getenv("OUTPUT_PATH"));

	for (int it = 0; it < q; it++)
	{
		string s;

		cin >> s;

		int result = sherlockAndAnagrams(s);

		fout << result << "\n";
	}

	fout.close();
}

int main()
{
#ifdef TEST
	test("tests/testcase0.txt", { 4, 0 });
	test("tests/testcase1.txt", { 3, 10 });
	test("tests/testcase2.txt", { 5 });
#else
	run();
#endif

	return 0;
}