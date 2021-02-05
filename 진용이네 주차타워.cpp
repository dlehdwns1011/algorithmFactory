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
		int pay[101] = { 0, };//�ڸ��� ���
		int weight[2002] = { 0, };//������ ����
		int parking[2002] = { 0, };//index�� ������ ��ġ
		int wait[2002] = { 0, };//�����
		int nowWait = 0;//������
		int nowTurn = 0;//���� ������ ����ȣ
		int nowEmpty = 0;//����ִ� �������� �ּҰ�
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
			{// ���´�
				if (isFull(isExist))
				{//���
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
			{// ������ �� ��� ����
				input *= -1;
				isExist[parking[input]] = false;
				if (parking[input] < nowEmpty)
					nowEmpty = parking[input];
				result += weight[input] * pay[parking[input]];
			}

			if (nowTurn < nowWait)
			{//����� �ִ�?
				if (!isFull(isExist))
				{//�ڸ� �־�
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
