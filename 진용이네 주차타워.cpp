#include <iostream>
#include <vector>

using namespace std;

int n, m;

bool isFull(bool * isExist)
{
	for (int i = 0; i < n; ++i)
	{
		if (isExist[i] == false)
			return false;
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test = 0;
	cin >> test;

	for (int testnum = 1; testnum <= test; ++testnum)
	{
		int pay[101] = { 0, };//자리의 요금
		int weight[2002] = { 0, };//차량의 무게
		int parking[2002] = { 0, };//index가 주차한 위치
		int wait[2002] = { 0, };//대기자
		int nowWait = 0;//대기순번
		int nowTurn = 0;//이제 주차할 대기번호
		int nowEmpty = 0;//비어있는 주차장의 최소값
		bool isExist[101] = { false, };

		cin >> n >> m;
		int result = 0;

		for (int i = 0; i < n; ++i)
			cin >> pay[i];

		for (int i = 1; i <= m; ++i)
			cin >> weight[i];

		for (int i = 0; i < 2 * m; ++i)
		{
			int input = 0;
			cin >> input;
			
			if (input > 0)
			{// 들어온다
				if (isFull(isExist))
				{//대기
					wait[nowWait] = input;
					++nowWait;
					continue;
				}

				isExist[nowEmpty] = true;
				parking[input] = nowEmpty;
				while (1)
				{
					++nowEmpty;
					if (isExist[nowEmpty] == false)
						break;
				}
			}
			else
			{// 나갔을 때 요금 정산
				input *= -1;
				isExist[parking[input]] = false;
				if (parking[input] < nowEmpty)
					nowEmpty = parking[input];
				result += weight[input] * pay[parking[input]];
			}

			if (nowTurn < nowWait)
			{//대기자 있니?
				if (!isFull(isExist))
				{//자리 있어
					isExist[nowEmpty] = true;
					parking[wait[nowTurn]] = nowEmpty;
					++nowTurn;
					while (1)
					{
						++nowEmpty;
						if (isExist[nowEmpty] == false)
							break;
					}
				}
			}
		}

		cout << "#" << testnum << " " << result << "\n";
	}

	return 0;
}
