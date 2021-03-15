#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

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

int find_dup(vector<string> orders, string a)
{
	int result = 0;
	for (int i = 0; i < orders.size(); ++i)
	{
		if (make_dup(a, orders[i]) == a)
			result++;
	}
			
	return result;
}

vector<string> solution(vector<string> orders, vector<int> course) {
	
	int max[11] = { 0, };
	set<string> maxString[11];

	for (int i = 0; i < orders.size() - 1 ; ++i)
	{
		for (int j = i + 1; j < orders.size(); ++j)
		{
			string result = make_dup(orders[i], orders[j]);
			if (result.size() < 2)
				continue;
			int dup = find_dup(orders, result);
			for (int h = 0; h < course.size(); ++h)
			{
				if (course[h] == result.size())
				{
					if (max[course[h]] < dup)
					{
						maxString[course[h]].clear();
						maxString[course[h]].insert(result);
						max[course[h]] = dup;
					}
					else if (max[course[h]] == dup)
					{
						maxString[course[h]].insert(result);
					}
					break;
				}
			}
		}
	}

	set<string> set;
	for (int i = 0; i < course.size(); ++i)
	{
		if(maxString[course[i]].size() != 0)
			set.insert(maxString[course[i]].begin(), maxString[course[i]].end());
	}
		
	vector<string> answer(set.begin(), set.end());
	return answer;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string arr[20] = { "ACD","AC","AC","ABC","ABC","ABCD","ACD","BADCE","AB","AB","AB","AB","AB","CA"};
	int cours[10] = { 2,3,4 };
	vector<string> v;
	vector<int> v2;

	for(int i = 0 ; i < 14 ; ++i)
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
