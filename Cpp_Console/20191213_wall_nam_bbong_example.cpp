#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;

int main()
{
	srand(time(NULL));

	// ī��� 52�� 
	int card[52];
	// ���� 3��, ���� 3�� -> ī�带 ���� ��
	int shape[3];
	int number[3];
	// ���ÿ� ����
	int dest, sour, temp;
	// 
	int betting = 0;
	int money = 10000;
	int useCard = 0;

	// ī�尪 �ʱ�ȭ
	for (int i = 0; i < 52; i++)
	{
		card[i] = i;
	}
	// ī�� ����
	for (int i = 0; i < 500; i++)
	{
		dest = rand() % 52;
		sour = rand() % 52;

		temp = card[dest];
		card[dest] = card[sour];
		card[sour] = temp;
	}
	while (true)
	{
		// ������ ī�� 2��, �� ī�� 1�� �� 3��
		for (int i = 0; i < 3; i++)
		{
			// ���� ī���� ����� ���ڴ� ���⼭ ����
			shape[i] = card[i + useCard] / 13;
			number[i] = card[i + useCard] % 13;

			// ������
			switch (shape[i])
			{
			case 0:
				cout << "��";
				break;
			case 1:
				cout << "��";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			} // end of switch(shape)

			switch (number[i])
			{
			case 0:
				cout << "A \t";
				break;
			case 10:
				cout << "J \t";
				break;
			case 11:
				cout << "Q \t";
				break;
			case 12:
				cout << "K \t";
				break;
			default:
				cout << number[i] + 1 << " \t";
				break;
			}// end of switch(number)
		}// end of for: ������ ī�� ����

		// ���� ������ ���
		cout << "�� �ݾ�: " << money << endl;
		cout << "�ݾ��� �����Ͻÿ�: " << betting << endl;
		cin >> betting;

		if (money < 1000)
		{
			cout << "�Ļ�!!!! ������ ���ư���" << endl;
			break;
		}
		if (1000 > betting || betting > money)
		{
			cout << "���þ��� 1000 �̻� ������ ����" << endl;
			Sleep(1000);
			continue;
		}

		// �� ī��� number[2]
		if (number[0] < number[2] && number[2] < number[1] ||
			number[0] > number[2] && number[2] > number[1])
		{
			cout << "ī�� ����: " << number[2] + 1 << endl;
			money += betting;
			cout << betting << "���� ȹ���ߴ�." << endl;
			Sleep(1000);
		}
		else
		{
			cout << "ī�� ����: " << number[2] + 1 << endl;
			money -= betting;
			cout << betting << "���� �Ҿ���. !!!" << endl;
			Sleep(1000);
		}
		// ����� ī��� ������.
		useCard += 3;
		cout << "���� ����� ī�� ��: " << useCard << endl;

		// ���� ����
		if (useCard == 51)
		{
			cout << "ī�尡 �����Ƿ� �����Ѵ�." << endl;
			break;
		}

	}// end of while(game over)
}
