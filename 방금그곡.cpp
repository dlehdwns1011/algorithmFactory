#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solution(string m, vector<string> musicinfos) {

	string answer = "";
	int maxtime = 0;

	for (int i = 0; i < musicinfos.size(); ++i)
	{
		string music = musicinfos[i];

		string starthour = "";
		starthour += music[0];
		starthour += music[1];
		int hour1 = stoi(starthour);
		string startmin = "";
		startmin += music[3]; 
		startmin += music[4];
		int min1 = stoi(startmin);
		
		string endhour = "";
		endhour += music[6];
		endhour += music[7];
		int hour2 = stoi(endhour);
		string endmin = "";
		endmin += music[9];
		endmin += music[10];
		int min2 = stoi(endmin);

		int time = (hour2 * 60 - hour1 * 60) + (min2 - min1);

		int index = music.find(",");
		music.erase(music.begin(), music.begin() + index + 1);
		index = music.find(",");
		music.erase(music.begin(), music.begin() + index + 1);
		index = music.find(",");
		string name = music.substr(0, index);
		music.erase(music.begin(), music.begin() + index + 1);

		string making = "";
		int makingindex = 0;
		for (int j = 0; j < time; ++j)
		{
			if (makingindex == music.size())
				makingindex = 0;

			making += music[makingindex];
			++makingindex;
			if (music[makingindex] == '#')
			{
				making += music[makingindex];
				++makingindex;
			}
		}

		while (1)
		{
			int findindex = making.find(m);
			if (findindex == -1)
				break;

			if (making[findindex + m.size()] == '#')
			{
				making.erase(making.begin(), making.begin() + m.size());
				continue;
			}
				
			making.erase(making.begin(), making.begin() + m.size());
			if (time > maxtime)
			{
				answer = name;
				maxtime = time;
			}
		}
	}

	if (answer == "")
		return "(None)";

	return answer;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<string> mu;
	string m;
	string s;

	cin >> m;
	cin >> s;
	mu.emplace_back(s);
	cin >> s;
	mu.emplace_back(s);


	auto result = solution(m, mu);

	cout << result;

	return 0;
}
