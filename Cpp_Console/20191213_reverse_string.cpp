/*
	1. ���ڿ��� �Է¹޾Ƽ� ������ ���α׷� ¥��
	2. ����� ¦����°�� ����ϴ� ���α׷� ¥��
*/
//#pragma warning(disable : 4996)
#include<iostream>
#include<string>

using namespace std;

// ���ڿ��� �������ִ� �Լ�
void reverse_String(char *orignalString, const int length);

int main()
{
	// ���ڿ��� myString�� �Է¹޴´�.
	char myString[300] = { 0, };
	cout << "[���ڿ� �Է�]: ";
	cin.getline(myString, 300);
	// �Է¹��� ���ڿ��� ���̸� ���س��´�.
	int mylength = strlen(myString);

	cout << "[main] myString: \t" << myString << endl;
	cout << "[main] &myString: \t" << &myString << endl;
	cout << "[main] mylength: \t" << mylength << endl;

	// ���⼭ ���ڿ��� �����´�.
	reverse_String(myString, mylength);
	// ���������� �������ٸ� myString�� ������� ��
	// ����� ���� ���̴�.
	cout << "[main] myString: \t" << myString << endl;
	//cout << "In main testPointer: \t" << testPointer << endl;

	system("pause");
	return 0;
}

void reverse_String(char *originalString, const int length)
{
	// ���ڿ��� �޾Ƽ� �������ִ� �Լ���.

	// ���� �������� �Ѽ��� ���� ���ؼ� ī���ؼ� ó���Ѵ�.
	char myString[300] = { 0, };

	//// �ѱ� ���� �� �׽�Ʈ �ڵ�
	//if (originalString[0] == (char)164)
	//	cout << "true" << endl;
	//if (originalString[1] == (char)161)
	//	cout << "true" << endl;

	// ī���� ������ ������ �Է��Ѵ�.
	int i = 0;
	// �Է¹��� ���� ���� ���ϱ� ���� ����
	char nowCharactor = 0;

	for (int k = length - 1; k >= 0; k--)
	{
		//// originalString[k] �� ���� Ȯ���غ��� ���Ѻκ�
		//nowCharactor = originalString[k];
		//if ((int)nowCharactor >= (int)0xA4)
		//{
		//	cout << nowCharactor << endl;
		//	cout << "true" << endl;
		//}

		// ���⼭ �ѱ��� ���� ��츦 ó���Ѵ�.
		// �ѱ��� ������ Hangle[N-1]Hangle[N] �� ��
		// Hangle[N-1] �� 0xA1 ~ 0xD1 �� ������. -> ��� �ѱ� ����
		// Hangle[N] �� ��ħ�� ���ٸ� ���� 0xA1 ~ 0xD1 �� ���� ��������
		// ��ħ�� �ִٸ� �׷��� ���� ��쵵 ���� �ִ�.
		if (
			(unsigned char)originalString[k - 1] >= (unsigned char)0xA1 &&
			(unsigned char)originalString[k] >= (unsigned char)0x50 &&
			(unsigned char)originalString[k - 1] != (unsigned char)0xCC
			)
		{
			// 1 Byte ������ 164���� ū ���� �Ѿ���� �ѱ۷� �����Ѵ�.

			// 2 Byte [��], [��] �߿� 
			// myString [i], [i+1]
			// originalString [k-1], [k]
			// �䷸�� �־���� ������ ���� ���̴�.
			myString[i] = originalString[k - 1];
			myString[i + 1] = originalString[k];

			// i=0 �϶�, myString[0], [1] �� ���� �־�����
			// myString[2] �� ������ �� �ֵ��� i �� 2�� �����ش�.
			i += 2;
			// k=6 �϶�, originalString[5], [6] �� ����������
			// originalString[4]�� ������ �� �ֵ��� k�� 1�� ���ش�.
			// �ֳĸ� �������� �ϳ� ���� �����ϱ�
			k--;
		}
		else
		{
			// �ѱ��� �ƴ� ��� �׳� �״�� ó���Ѵ�.
			//cout << originalString[k] << endl;
			myString[i] = originalString[k];
			i++;
		}

	}// end of for: ������ ���� ��������.
	// �ΰ��� ���� ������ ������ ����.
	myString[i] = '\0';
	cout << endl;

	//cout << "[reverse_String] myString: \t" << myString << endl;
	//cout << "In reverse_String originalString: \t" << originalString << endl;
	//cout << length << endl;

	// ���⼭ ������ originalString�� myString�� ���� �غ���. 
	strcpy_s(originalString, 300, myString);

	//cout << originalString << endl;
	//cout << "[reverse_String] originalString: \t" << originalString << endl;
	//cout << "[reverse_String] originalString: \t" << &originalString << endl;
}
