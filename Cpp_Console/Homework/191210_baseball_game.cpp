#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	/*
	���ھ߱� ����
	 1) �÷��̾ ���� 3���� �Է�
	 2) ��ǻ�͵� ���� 3���� �����. (ġƮ�� ���ڸ� �����ش�.)
	 3) ���� �Է��� ���ڿ� ���� ��Ʈ����ũ, ���� ������ �����ش�.
	 3-1) ���ڵ� ���� �ڸ��� ������ ��Ʈ����ũ
	 3-2) ���ڴ� ���� �ڸ��� �ٸ��� ��
	 4) ��� �ݺ�
	 E) ���������� 3 ��Ʈ����ũ �����ƿ�
	*/
	// ���� �õ� �ʱ�ȭ
	srand(time(NULL));

	// ���� �����
	int number[10];
	int comNumber[3];
	int myNumber[3];
	int dest, sour, temp;
	int ballCount;
	int strikeCount;

	// �߱����ӿ� �� ���� 0~9 10���� �ʱ�ȭ �ϴ� �κ�
	for (int i = 0; i < 10; i++)
	{
		number[i] = i;
	}

	// number �迭�� suffle �ϴ� �κ�
	for (int i = 0; i < 50; i++)
	{
		dest = rand() % 10;
		sour = rand() % 10;

		temp = number[dest];
		number[dest] = number[sour];
		number[sour] = temp;
	}

	// ��ǻ�Ͱ� �������� 3���� �����ϴ� �κ�
	for (int i = 0; i < 3; i++)
	{
		comNumber[i] = number[i];
	}
	
	// ��ǻ�Ͱ� �� ���ڰ� ���� �����ִ� �κ�
	cout << "��ǻ�Ͱ� �� ����: ";
	for (int i = 0; i < 3; i++)
	{
		cout << comNumber[i] << " ";
	}
	cout << endl;

	// ���� ������ ����Ǵ� �κ�
	while (true)
	{
		cout << "0~9���� ���ڸ� �Է��Ͻÿ� !!!" << endl;

		// ���ڸ� 3�� �Է¹޴´�.
		for (int i = 0; i < 3; i++)
		{
			cout << i + 1 << "��° ���ڸ� �Է�: ";
			cin >> myNumber[i];
		}

		// ��, ��Ʈ����ũ �ʱ�ȭ
		ballCount = 0;
		strikeCount = 0;

		// ���ھ߱����� �� ���� ��ǻ���� ���� ���ϴ� �κ�.
		// ��ǻ��
		for (int i = 0; i < 3; i++)
		{
			// �÷��̾�
			for (int k = 0; k < 3; k++)
			{
				// ��ǻ�� ���ڿ� ���� ������ ���ڰ� ������?
				if (comNumber[i] == myNumber[k])
				{
					// �ڸ����� ������?
					if (i == k)
					{
						strikeCount++;
					}
					else
					{
						ballCount++;
					}
				}
			// end of Player's for
			}
		// end of for
		}

		cout << ballCount << "�� " << strikeCount << "��Ʈ����ũ" << endl;

		// 3 ��Ʈ����ũ�� ���� �ƿ����� ������ ����ȴ�.
		if (strikeCount == 3)
		{
			cout << strikeCount << "��Ʈ����ũ!!! �����ƿ�!!!" << endl;
			break;
		}
	// end of while
	}

	system("pauses");
	return 0;
}