#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;

int main()
{
	srand(time(NULL));

	int number[25];
	int dest, sour, temp;
	int inputNum;
	int bingoCount = 0;

	// �ʱ�ȭ
	for (int i = 0; i < 25; i++)
	{
		number[i] = i + 1;
	}

	for (int i = 0; i < 25; i++)
	{
		dest = rand() % 25;
		sour = rand() % 25;

		temp = number[dest];
		number[dest] = number[sour];
		number[sour] = temp;
	}

	// ���� ���� �ڵ�
	while (true)
	{
		system("cls");
		cout << "��̾��� ���� ���� ~ " << endl;
		cout << "���� ī��Ʈ: " << bingoCount << endl;

		// �� �׸���
		for (int i = 0; i < 25; i++)
		{
			// ���� ���ڰ� 35��
			if (number[i] == 35)
			{
				// ���ڸ� #���� ǥ����.
				cout << (char)number[i] << "\t";
			}
			else
			{
				cout << number[i] << "\t";
			}

			// 5������ 1���� ���� ���.
			if ((i + 1) % 5 == 0)
			{
				cout << "\n\n" << endl;
			}
		} // end of for

		cout << "���ϴ� ���ڸ� �Է��Ͻÿ�: ";
		cin >> inputNum;

		for (int i = 0; i < 25; i++)
		{
			if (number[i] == inputNum)
			{
				number[i] = 35;
			}
		}

		// ���� �˻� �κ�
		bingoCount = 0;
		for (int i = 0; i < 5; i++)
		{
			// ���� �˻�
			if (number[i * 5] == 35 &&
				number[i * 5 + 1] == 35 &&
				number[i * 5 + 2] == 35 &&
				number[i * 5 + 3] == 35 &&
				number[i * 5 + 4] == 35)
			{
				bingoCount++;
			}

			// ���� �˻�
			if (number[i] == 35 &&
				number[i + 5 * 1] == 35 &&
				number[i + 5 * 2] == 35 &&
				number[i + 5 * 3] == 35 &&
				number[i + 5 * 4] == 35)
			{
				bingoCount++;
			}
		}// end of for

		// ���� �밢�� �˻�
		if (number[0] == 35 &&
			number[6] == 35 &&
			number[12] == 35 &&
			number[18] == 35 &&
			number[24] == 35)
		{
			bingoCount++;
		}

		// ������ �밢�� �˻�
		if (number[4] == 35 &&
			number[8] == 35 &&
			number[12] == 35 &&
			number[16] == 35 &&
			number[20] == 35)
		{
			bingoCount++;
		}

		// ����ī��Ʈ�� 3�̸�
		if (bingoCount >= 3)
		{
			cout << "������ ���ư���~~" << endl;
			break;
		}
	}// end of while
}