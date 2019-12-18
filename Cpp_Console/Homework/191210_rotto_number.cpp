#include <iostream>
#include <time.h>

using namespace std;
/*
	지금 해볼 것.
	로또 번호 생성기를 만들어 보시오. 
	단) 배열을 꼭 섞어서 구현할 것.

	1. 로또 45개로 배열을 초기화
	2. 배열을 믹스믹스
	3. 결과는 배열의[0~5] 순서대로 6개만 뽑자.
*/

int main()
{
	int rotto_num_set[45] = { 0, };
	srand(time(NULL));

	// 여기서 로또번호 초기화 한다.
	for (int i = 0; i < 45; i++)
	{
		rotto_num_set[i] = i + 1;
	}

	// 여기서 로또번호를 섞는다.
	int dest, temp, sour;
	int mix_cnt = 100;
	for (int k = 0; k < mix_cnt; k++)
	{
		// 랜덤하게 섞을 두 좌표를 구한다.
		dest = rand() % 45;
		sour = rand() % 45;

		// 좌표를 바탕으로 실제 배열 값을 섞는다.
		temp = rotto_num_set[dest];
		rotto_num_set[dest] = rotto_num_set[sour];
		rotto_num_set[sour] = temp;
	}

	// 로또번호 셋이 섞였는지 확인하는 코드
	cout << "로또가 섞였는지 확인하는 Test Code 입니다. " << endl;
	cout << "Last dest: " << dest << endl;
	cout << "Last sour: " << sour << endl;
	for (int i = 0; i < 45; i++)
	{
		cout << rotto_num_set[i] << " ";
	}
	cout << endl;

	// 로또 번호 6개를 뽑을 예정.
	cout << endl;
	cout << "*** 내가 뽑은 로또번호 ***" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << rotto_num_set[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}