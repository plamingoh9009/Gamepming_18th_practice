# include <iostream>

using namespace std;

int main()
{
	// ������� 4���� ���� �߿� 1������ �����ش�.
	int select_Num = 0;

	cout << "[1-4] �߿� 1���� ������ ����⸦ ����մϴ�. " << endl;
	cout << "�����Է�: ";
	cin >> select_Num;

	cout << select_Num << endl;

	// ���⼭ ��� ���� ����.
	switch (select_Num)
	{
	case 1:
		cout << "����� 1�� ���" << endl;

		for (int i = 0; i < 5; i++)
		{
			for (int k = 0; k <= i; k++)
			{
				cout << "��";
			}
			cout << endl;
		}
		break;

	case 2:
		cout << "����� 2�� ���" << endl;

		for (int i = 0; i < 5; i++)
		{
			// ���⼭ ������ ���ﰢ������ ���
			for (int k = 0; k < (4 - i); k++)
			{
				cout << "  ";
			}

			// ���⼭ ���� ���
			for (int p = 0; p <= i; p++)
			{
				cout << "��";
			}
			cout << endl;
		}
		break;

	case 3:
		cout << "����� 3�� ���" << endl;

		for (int i = 5; i > 0; i--)
		{
			for (int k = 0; k < i; k++)
			{
				cout << "��";
			}
			cout << endl;
		}
		break;

	case 4:
		cout << "����� 4�� ���" << endl;
		
		for (int i = 5; i > 0; i--)
		{
			// ���⼭ ������ �ﰢ������ ���
			for (int p = 0; p < 5 - i; p++)
			{
				cout << "  ";
			}

			// ���⼭ ���� ���ﰢ������ ���
			for (int k = 0; k < i; k++)
			{
				cout << "��";
			}
			cout << endl;
		}
		break;
	default:
		cout << "[1-4] ���� ������ �Է��ϼ���" << endl;
		break;
	} // end of switch

	system("pause");
	return 0;
}