Skip to content
Search or jump to��

Pull requests
Issues
Marketplace
Explore

@zxwnstn
Learn Git and GitHub without any code!
Using the Hello World guide, you��ll start a branch, write comments, and open a pull request.


0
01zxwnstn / Gamepming_18th_practice
forked from plamingoh9009 / Gamepming_18th_practice
Code Pull requests 0 Actions Projects 0 Wiki Security Insights Settings
Gamepming_18th_practice / Cpp_Console / 191210_rotto_number.cpp
plamingoh9009 Create 191210_rotto_number.cpp
f3b6a61 6 hours ago
62 lines(53 sloc)  1.21 KB

#include <iostream>
#include <time.h>

using namespace std;
/*
	���� �غ� ��.
	�ζ� ��ȣ �����⸦ ����� ���ÿ�.
	��) �迭�� �� ��� ������ ��.
	1. �ζ� 45���� �迭�� �ʱ�ȭ
	2. �迭�� �ͽ��ͽ�
	3. ����� �迭��[0~5] ������� 6���� ����.
*/

int main()
{
	int rotto_num_set[45] = { 0, };
	srand(time(NULL));

	// ���⼭ �ζǹ�ȣ �ʱ�ȭ �Ѵ�.
	for (int i = 0; i < 45; i++)
	{
		rotto_num_set[i] = i + 1;
	}

	// ���⼭ �ζǹ�ȣ�� ���´�.
	int dest, temp, sour;
	int mix_cnt = 100;
	for (int k = 0; k < mix_cnt; k++)
	{
		// �����ϰ� ���� �� ��ǥ�� ���Ѵ�.
		dest = rand() % 45;
		sour = rand() % 45;

		// ��ǥ�� �������� ���� �迭 ���� ���´�.
		temp = rotto_num_set[dest];
		rotto_num_set[dest] = rotto_num_set[sour];
		rotto_num_set[sour] = temp;
	}

	// �ζǹ�ȣ ���� �������� Ȯ���ϴ� �ڵ�
	cout << "�ζǰ� �������� Ȯ���ϴ� Test Code �Դϴ�. " << endl;
	cout << "Last dest: " << dest << endl;
	cout << "Last sour: " << sour << endl;
	for (int i = 0; i < 45; i++)
	{
		cout << rotto_num_set[i] << " ";
	}
	cout << endl;

	// �ζ� ��ȣ 6���� ���� ����.
	cout << endl;
	cout << "*** ���� ���� �ζǹ�ȣ ***" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << rotto_num_set[i] << " ";
	}
	cout << endl;

	cout << "zxwnstn����" << endl;

	system("pause");
	return 0;
}
