#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	// ��� �ӵ� ���� �ڵ�
	ios::sync_with_stdio(NULL);
	cin.tie();

	// ���� �����
	char myStr[1000002] = { 0, };
	int alphabet_cnt[26] = { 0, };
	int length = 0;

	// ���ڿ� �Է¹޾Ƽ� ���̸� ����
	cin >> myStr;
	length = strlen(myStr);
	
	// 'A' = 65, 'a' = 97, 'Z' = 90
	// ���ڿ� ���̸�ŭ �ݺ���
	for (int i = 0; i < length; i++)
	{
		// 'a' ���� ������ �빮��
		if (myStr[i] < 'a')
		{
			alphabet_cnt[myStr[i] - 'A'] += 1;
		}
		// 'a' ���� ���� ������ �ҹ���
		else
		{
			alphabet_cnt[myStr[i] - 'a'] += 1;
		}
	}
	
	int manyNumber = -1;
	for (int i = 0; i < 26; i++)
	{
		// ���� ū ���� ã�Ƽ� manyNumber�� �ִ´�.
		if (alphabet_cnt[i] >= manyNumber)
		{
			manyNumber = alphabet_cnt[i];
		}
		//cout << alphabet_cnt[i] << " ";
	}
	//cout << endl;
	//cout << manyNumber << endl;

	// manyNumber�� ã�� ������ manyCnt �� ����.
	int manyCnt = 0;
	int manyIndex = -1;
	for (int i = 0; i < 26; i++)
	{
		if (alphabet_cnt[i] == manyNumber)
		{
			manyCnt++;
			// manyCnt�� �ø� �ڸ��� ����� manyIndex ���� ������.
			manyIndex = i;
		}
	}

	// ���� manyCnt�� 1�� �ƴ϶�� ?�� ���.
	// 1�̶�� ���ĺ� �빮�ڸ� ��� -> �ε��� + 'A' �ϸ� ���´�.
	if (manyCnt == 1)
	{
		cout << (char)(manyIndex + 'A') << '\n';
	}
	else
	{
		cout << '?' << '\n';
	}

	system("pause");
	return 0;
}