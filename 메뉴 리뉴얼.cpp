#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;
vector<string> resultString;
int maxIndex;

void powerSet(int index, string ori, string now) {
	if (index >= ori.size()) {
		if (now.size() == maxIndex)
			resultString.push_back(now);
		return;
	}

	// 현재 인덱스를 포함하는 경우
	powerSet(index + 1, ori , now + ori[index]);

	// 현재 인덱스를 포함하지 않는 경우
	powerSet(index + 1, ori , now);
}

string make_dup(string a, string b)
{
	string result = "";
	for (int i = 0; i < a.size(); ++i)
	{
		int index = b.find(a[i]);
		if (index != -1)
			result += a[i];
	}
	sort(result.begin(),result.end());
	return result;
}

int exist_string(vector<string> orders, string a)
{
	int result = 0;
	for (int i = 0; i < orders.size(); ++i)
	{
		bool flag = true;
		for (int j = 0; j < a.size(); ++j)
		{
			if (orders[i].find(a[j]) == -1)
				flag = false;
		}
		if(flag) result++;
	}
			
	return result;
}

vector<string> solution(vector<string> orders, vector<int> course) {
	
	int max[11] = { 0, };
	set<string> maxString[11];

	for (int i = 0; i < orders.size() - 1; ++i)
	{
		for (int j = i + 1; j < orders.size(); ++j)
		{
			for (int h = 0; h < course.size(); ++h)
			{
				resultString.clear();
				maxIndex = course[h];
				powerSet(0, make_dup(orders[i], orders[j]), "");

				for (int g = 0; g < resultString.size(); ++g)
				{
					int num = exist_string(orders, resultString[g]);
					if (max[maxIndex] < num)
					{
						maxString[maxIndex].clear();
						maxString[maxIndex].insert(resultString[g]);
						max[maxIndex] = num;
					}
					else if (max[maxIndex] == num)
					{
						maxString[maxIndex].insert(resultString[g]);
					}
				}
			}
		}
	}

	set<string> tempset;
	for (int h = 0; h < course.size(); ++h)
	{
		tempset.insert(maxString[course[h]].begin(), maxString[course[h]].end());
	}

	vector<string> answer(tempset.begin(), tempset.end());

	return answer;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < resultString.size(); ++i)
	{
		cout << resultString[i] <<" ";
	}

	string arr[20] = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
	int cours[10] = { 2,3,4 };
	vector<string> v;
	vector<int> v2;

	for(int i = 0 ; i < 6 ; ++i)
		v.emplace_back(arr[i]);

	for (int i = 0; i < 3; ++i)
		v2.emplace_back(cours[i]);

	auto result = solution(v, v2);

	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] <<" ";
	}
	
	return 0;
}
