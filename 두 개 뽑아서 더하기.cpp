#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
	set<int> s;
	int size = numbers.size();

	for (int i = 0; i < size - 1 ; ++i)
		for (int j = i+1; j < size; ++j)
			s.insert(numbers[i] + numbers[j]);

	vector<int> answer(s.begin(),s.end());
	return answer;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> numbers;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		numbers.emplace_back(num);
	}
	
	auto result = solution(numbers);

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}

	return 0;
}
