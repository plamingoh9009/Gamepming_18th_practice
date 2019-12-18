/*
	1. ���ڿ��� �Է¹޾Ƽ� ������ ���α׷� ¥��
	2. ����� ¦����°�� ����ϴ� ���α׷� ¥��
*/

// �̰� ���� �޽����� �����ϴ� �Լ���.
//#pragma warning(disable : 4996)
#include<iostream>
#include<string>

using namespace std;

// ���ڿ��� �������ִ� �Լ�
void reverse_String(char *orignalString, const int length);
// ���ڿ��� ¦����°�� ����ϴ� �Լ�
void show_EvenString(char *originalString, const int length);

int main()
{
	// ���ڿ��� myString�� �Է¹޴´�.
	char myString[300] = { 0, };
	cout << "[���ڿ� �Է�]: ";
	cin.getline(myString, 300);
	// �Է¹��� ���ڿ��� ���̸� ���س��´�.
	int myLength = strlen(myString);

	cout << "[Main] myString: \t" << myString << endl;
	cout << "[Main] myLength: \t" << myLength << endl;
	//cout << "[main] &myString: \t" << &myString << endl;

	// ���⼭ ���ڿ��� �����´�.
	reverse_String(myString, myLength);
	// ���������� �������ٸ� myString�� ������� ��
	// ����� ���� ���̴�.
	cout << "[Main] myString: \t" << myString << endl;
	//cout << "In main testPointer: \t" << testPointer << endl;

	// ���⼭ ������ ���ڿ��� ¦����° ���ڸ��� ����Ѵ�.
	show_EvenString(myString, myLength);

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
	
	// �Է¹��� ���� ���� ���ϱ� ���� ����
	char nowCharactor = 0;
	int i = 0;
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

void show_EvenString(char *originalString, const int length)
{
	// �Ѱܹ��� ���ڿ��� ������� ¦����°�� ����ϴ� ���α׷�
	
	// ���� �������� �Ѽ��� ���� ���ؼ� ī���ؼ� ����Ѵ�.
	char myString[300] = { 0, };
	strcpy_s(myString, 300, originalString);
	// ����� ������� ��� �迭�� �����.
	char evenString[300] = { 0, };

	// ���� length ��ŭ �ݺ����� �ѹ��� ������ ¦����° ���ڸ� ����Ѵ�.
	// �ѱ��� «�͵Ǿ� �ֱ� ������ ��¿ �� ���� �ٸ� ������ ���ڸ� �־ ����ؾ� �Ѵ�.
	// stringCounter: ���° �������� ���� ����
	int stringCounter = 0;
	int indexOf_Even = 0;
	for (int i=0; i < length; i++)
	{
		// length�� ũ��� ������ ������ �ٸ� ���ִ�.

		// �ڿ������� Ȯ���� ���� �ٸ��� �տ��� Ȯ���� 1���� �����̸� ����ϴ�.
		if(	(unsigned char)myString[i] >= (unsigned char)0xA1 )
		{
			// ���� �ѱ��̶�� nowCharactor�� 2 Byte�� �ִ´�.
			stringCounter++;
			if (stringCounter % 2 == 0)
			{
				evenString[indexOf_Even] = myString[i];
				evenString[indexOf_Even + 1] = myString[i + 1];

				// ¦�� ���� ������ myString�� ���� ������ �ٸ���
				// ���ο� �ε����� ����Ѵ�.
				indexOf_Even += 2;
			}
			// stringCounter �� Ȧ������ Ȯ�� �߱⶧���� i�� ������ 
			// if�� ���ο� ����� ����.
			// 2 Byte�� Ȯ�������� i�� �߰��� �����Ѵ�.
			i++;
		}
		else
		{
			// �ѱ� �ƴϸ� nowCharactor�� 1 Byte�� �ִ´�.
			stringCounter++;
			if (stringCounter % 2 == 0)
			{
				evenString[indexOf_Even] = myString[i];

				indexOf_Even++;
			}
		}// end ���ǹ�: �ѱ��̸� ��, �ƴϸ� ����
	}// end of for: ���ڿ��� ������ Ȯ������.
	// ������ �������� evenString�� ���� �˸��� ���ؼ� null���� �־��ش�.
	evenString[indexOf_Even] = '\0';

	// ��� �κ��̴�.
	cout << endl;
	cout << "[EvenString]: \t";
	cout << evenString << endl;
}
