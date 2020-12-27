#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int testnum = 0;
	cin >> testnum;
	for (int itest = 0; itest < testnum; ++itest)
	{
		int testcase = 0; 
		cin >> testcase;
		vector< pair<int,string> > text;
		for (int icase = 0; icase < testcase; ++icase)
		{
			string input;
			cin >> input;
			text.emplace_back(input.size(), input);
		}
		sort(text.begin(), text.end());
		cout << "#" << itest + 1 << "\n";
		text.erase(unique(text.begin(), text.end()), text.end());
		
		for (int i = 0; i < text.size() ; ++i)
		{
			cout << text[i].second<<"\n";
		}
	}
	return 0;
}
