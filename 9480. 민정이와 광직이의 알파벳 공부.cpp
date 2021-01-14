#include <iostream>
#include <vector>
#include <algorithm>

// 두번째 시도

using namespace std;
vector<string> v;
int result = 0;
string perf = "11111111111111111111111111";

void combination(string check, int curindex)
{
	string checkstring = v[curindex];

	for (int i = 0; i < checkstring.length(); ++i)
		check[(int)checkstring[i] - (int)'a'] = '1';

	if (check == perf)
	{
		result += pow(2, v.size() - curindex - 1);
		return;
	}

	for (int i = curindex + 1; i < v.size(); ++i)
		combination(check, i);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test = 0;
	cin >> test;

	for (int testnum = 1; testnum <= test; ++testnum)
	{
		int n;
		cin >> n;

		for (int j = 0; j < n; ++j)
		{
			string input;
			cin >> input;
			v.emplace_back(input);
		}

		for (int i = 0; i < n; ++i)
		{
			combination("00000000000000000000000000", i);
		}

		cout << "#" << testnum << " " << result << "\n";
		result = 0;
		v.clear();
	}

	return 0;
}



// 처음 시도
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<string> v;
string resultstring;
int result;

bool isExist(string word)
{
	if (word.length() < 26)
		return false;

	sort(word.begin(), word.end());
	word.erase(std::unique(word.begin(), word.end()), word.end());

	if (word.length() < 26)
		return false;

	int index = 0;
	for (int i = 97; i < 123; ++i)
	{
		if (i != (int)(word[index]))
			return false;
		++index;
	}

	return true;
}

void Combination(vector<string> comb, int r, int index, int depth)
{
	if (r == 0)
	{
		for (int i = 0; i < comb.size(); i++)
			resultstring += comb[i];

		if (isExist(resultstring))
			result++;

		resultstring.clear();
		return;
	}
	else if (depth == v.size())  // depth == n
	{
		return;
	}
	else
	{
		comb[index] = v[depth];
		Combination(comb, r - 1, index + 1, depth + 1);

		Combination(comb, r, index, depth + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test = 0;
	cin >> test;

	for (int testnum = 1; testnum <= test; ++testnum)
	{
		result = 0;

		cin >> n;
		v.clear(); resultstring = "";
		for (int j = 0; j < n; ++j)
		{
			string input;
			cin >> input;
			v.emplace_back(input);
		}

		for (int i = 1; i <= n; ++i)
		{
			vector<string> comb(i);
			Combination(comb, i, 0, 0);
		}

		cout << "#" << testnum << " " << result << "\n";
		v.clear();
	}

	return 0;
}

