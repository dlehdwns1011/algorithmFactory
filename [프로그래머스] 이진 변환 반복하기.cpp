#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
	vector<int> answer;
	int trynum = 0;
	int zero = 0;
	
	while (s != "1")
	{
		string temp;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '1') temp += '1';
			else ++zero;
		}

		int sizeofstring = temp.size();
		s = "";
		while (sizeofstring > 1)
		{
			if (sizeofstring % 2 == 1) s += '1';
			else s += '0';
			sizeofstring /= 2;
		}
		s += '1';
		reverse(s.begin(), s.end());
		++trynum;
	}

	answer.emplace_back(trynum);
	answer.emplace_back(zero);

	return answer;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input;
	cin >> input;
	
	auto result = solution(input);

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}

	return 0;
}
