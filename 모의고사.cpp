#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> answer1({ 1, 2, 3, 4, 5 });					int i1 = 0;
	vector<int> answer2({ 2, 1, 2, 3, 2, 4, 2, 5 });		int i2 = 0;
	vector<int> answer3({ 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 });	int i3 = 0;
	
	int per1 = 0, per2 = 0, per3 = 0;

	for (int answer : answers)
	{
		if (answer1[i1] == answer)
			++per1;
		if (answer2[i2] == answer)
			++per2;
		if (answer3[i3] == answer)
			++per3;

		++i1; ++i2; ++i3;

		if (answer1.size() == i1)
			i1 = 0;
		if (answer2.size() == i2)
			i2 = 0;
		if (answer3.size() == i3)
			i3 = 0;
	}

	set<pair<int, int>,greater<pair<int,int>> > intSet;
	intSet.emplace(per1, 1);
	intSet.emplace(per2, 2);
	intSet.emplace(per3, 3);
	int top = (*(intSet.begin())).first;
	for (auto i : intSet)
	{
		if (i.first != top)
			break;

		answer.push_back(i.second);
	}
	sort(answer.begin(), answer.end());
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	auto result = solution({ 1, 3, 2, 4, 2 });

	for (auto i : result)
		cout << i << " ";
//	cout << result << " ";

	
	return 0;
}
