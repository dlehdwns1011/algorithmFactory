#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;
int solution(vector<int> priorities, int location) {
	int answer = 0;
	multiset<int, greater<int> > intSet(priorities.begin(), priorities.end());

	auto itr = intSet.begin();
	for (int j = 0; j <= priorities.size(); ++j)
	{
		if (j == priorities.size())
			j = 0;

		if (priorities[j] == (*itr))
		{
			++answer; ++itr;
			if (location == j)
				return answer;
		}
	}
	
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	auto result = solution({ 1, 1, 9, 1, 1, 1 },0);

	cout << result << " ";

	
	return 0;
}
