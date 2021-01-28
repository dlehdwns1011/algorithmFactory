#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

vector<int> solution( vector<string> gems ) {
	vector<int> answer(2);
	set<string> num(gems.begin(), gems.end());
	unordered_map<string, int> map;

	int start = 0;
	int end = 0;

	for (auto& s : gems)
	{
		map[s]++;
		if (map.size() == num.size())
			break;
		end++;
	}
	int min = end - start;
	answer[0] = start + 1;
	answer[1] = end + 1;

	while (end < gems.size())
	{
		string startstring = gems[start];
		map[startstring]--;
		++start;

		if (map[startstring] == 0)
		{
			++end;
			for (; end < gems.size(); ++end) 
			{
				map[gems[end]]++;
				if (startstring == gems[end])
					break;
			}

			if (end == gems.size())
				break;
		}

		if (min > end - start)
		{
			answer[0] = start + 1;
			answer[1] = end + 1;
			min = end - start;
		}

	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;

	vector<string> gems;
	for (int i = 0; i < n; ++i)
	{
		string a;
		cin >> a;
		gems.emplace_back(a);
	}

	auto result = solution(gems);

	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << " ";
	}

	return 0;
}
