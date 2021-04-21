#include <string>
#include <vector>
using namespace std;
bool checkTF(string s)
{
	vector<int> recent;

	for (auto seg : s)
	{
		switch (seg)
		{
		case '[':
			recent.push_back(0);
			break;
		case ']':
			if (recent.size() == 0) return false;
			if (recent[recent.size() - 1] != 0) return false;

			recent.pop_back();
			break;

		case '{':
			recent.push_back(1);
			break;
		case '}':
			if (recent.size() == 0) return false;
			if (recent[recent.size() - 1] != 1) return false;

			recent.pop_back();
			break;

		case '(':
			recent.push_back(2);
			break;
		case ')':
			if (recent.size() == 0) return false;
			if (recent[recent.size() - 1] != 2) return false;

			recent.pop_back();
			break;
		}
	}
	return true;
}

int solution(string s) {
	int answer = 0;
	int size = s.size();

	if (size % 2 != 0) return 0;
	for (int i = 0; i < size; ++i)
	{
		if (checkTF(s)) answer++;
		s += s[0];
		s.erase(0,1);
	}

	return answer;
}
