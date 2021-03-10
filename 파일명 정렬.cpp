#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

struct cmp {
	bool operator() (const pair<string, string>& a, const pair<string, string>& b) const {
		string loa = "";
		for (int i = 0; i < a.first.size(); i++) {
			loa += tolower(a.first[i]);
		}
		string lob = "";
		for (int i = 0; i < b.first.size(); i++) {
			lob += tolower(b.first[i]);
		}

		if (loa == lob) {
			int index2 = 0;
			while (a.second[index2] >= '0' && a.second[index2] <= '9')
				++index2;
			int inta = stoi(a.second.substr(0, index2));

			index2 = 0;
			while (b.second[index2] >= '0' && b.second[index2] <= '9')
				++index2;
			int intb = stoi(b.second.substr(0,index2));

			return inta < intb;
		}

		return loa < lob;
	}
};

vector<string> solution(vector<string> files) {
	vector<string> answer;
	multiset< pair<string,string>, cmp > list;

	for (int i = 0; i < files.size(); ++i)
	{
		//head
		string file = files[i];
		string head, tail;
		string number;

		int index = 0;
		while (file[index] < '0' || file[index] > '9')
			++index;
		head = file.substr(0, index);

		
		number = file.substr(index, file.size() - index);

		list.insert(make_pair(head, number));
	}


	for (auto it : list )
	{
		string an = it.first + it.second;
		answer.emplace_back(an);
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string case1[10] = { "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" };
	string case2[10] = { "F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat" };
	vector<string> files;
	int size1 = 6;
	int size2 = 4;
	for (int i = 0; i < size1; ++i)
		files.push_back(case1[i]);

	auto result = solution(files);

	for (int i = 0; i < size1; ++i)
		cout << result[i] << endl;

	files.clear();
	result.clear();

	for (int i = 0; i < size2; ++i)
		files.push_back(case2[i]);

	result = solution(files);

	for (int i = 0; i < size2; ++i)
		cout << result[i] << endl;
	

	return 0;
}
