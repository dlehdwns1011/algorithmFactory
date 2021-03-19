#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int numOfTuple = 0;
int sizeOfTuple = 0;
vector<pair<int, string>> candidate;
vector<vector<string>> v_data;

bool isCandidate(string str)
{
	set<vector<string>> set;
	for (int i = 0; i < numOfTuple; ++i)
	{
		vector<string> temp;
		for (int j = 0; j < str.size(); ++j)
		{
			int index = stoi(str.substr(j, 1));
			temp.push_back(v_data[i][index - 1]);
		}
		set.insert(temp);
	}

	if (set.size() != numOfTuple)
		return false;

	return true;
}

void powerSet(int index, string str, int limit) {
	if (index > sizeOfTuple)
	{
		if (str.size() == limit)
		{
			if (isCandidate(str))
				candidate.emplace_back(str.size(), str);
		}
		return;
	}

	// 현재 인덱스를 포함하는 경우
	powerSet(index + 1, str + to_string(index), limit);

	// 현재 인덱스를 포함하지 않는 경우
	powerSet(index + 1, str, limit);
}

int solution(vector<vector<string>> relation) {
	v_data = relation;
	numOfTuple = relation.size();
	sizeOfTuple = relation[0].size();

	// n개로 구성
	for (int n = 1; n <= sizeOfTuple; ++n)
		powerSet(1, "", n);

	sort(candidate.begin(), candidate.end());
	for (int i = 0; i < candidate.size() - 1; ++i)
	{
		if (candidate[i].first == 0)
			continue;

		for (int j = i + 1; j < candidate.size(); ++j)
			if (candidate[i].first < candidate[j].first)
			{
				bool flag = false;
				for (int h = 0; h < candidate[i].second.size(); ++h)
				{
					if (candidate[j].second.find(candidate[i].second[h]) == -1)
					{
						flag = true;
						break;
					}
				}
				if (!flag)
					candidate[j].first = 0;
			}
	}

	int result = 0;
	for (auto i : candidate)
	{
		if (i.first != 0)
			result++;
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<string>> v ;

	vector<string> ve1;
	ve1.push_back("100"); ve1.push_back("ryan"); ve1.push_back("music"); ve1.push_back("2");
	v.push_back(ve1);

	ve1.clear();
	ve1.push_back("200"); ve1.push_back("apeach"); ve1.push_back("math"); ve1.push_back("2");
	v.push_back(ve1);

	ve1.clear();
	ve1.push_back("300"); ve1.push_back("tube"); ve1.push_back("computer"); ve1.push_back("3");
	v.push_back(ve1);

	ve1.clear();
	ve1.push_back("400"); ve1.push_back("con"); ve1.push_back("computer"); ve1.push_back("4");
	v.push_back(ve1);

	ve1.clear();
	ve1.push_back("500"); ve1.push_back("muzi"); ve1.push_back("music"); ve1.push_back("3");
	v.push_back(ve1);

	ve1.clear();
	ve1.push_back("600"); ve1.push_back("apeach"); ve1.push_back("music"); ve1.push_back("2");
	v.push_back(ve1);

	
	auto result = solution(v);

	cout << result;
	
	return 0;
}
