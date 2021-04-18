#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (int i = 0; i < commands.size(); ++i)
	{
		multiset<int> intSet(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1]);
		int count = 1;
		for (int j : intSet)
		{
			if (count == commands[i][2])
			{
				answer.push_back(j);
				break;
			}
			++count;
		}
	}
	

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	auto result = solution({ 1, 5, 2, 6, 3, 7, 4 }, { { 2, 5, 3 }, { 4, 4, 1 }, { 1, 7, 3 } });

	for (auto i : result)
		cout << i << " ";
//	cout << result << " ";

	
	return 0;
}
