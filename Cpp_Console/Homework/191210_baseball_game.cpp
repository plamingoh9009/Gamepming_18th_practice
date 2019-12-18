#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	/*
	숫자야구 게임
	 1) 플레이어가 숫자 3개를 입력
	 2) 컴퓨터도 숫자 3개를 만든다. (치트로 숫자를 보여준다.)
	 3) 내가 입력한 숫자에 따라서 스트라이크, 볼을 가려서 보여준다.
	 3-1) 숫자도 같고 자리도 같으면 스트라이크
	 3-2) 숫자는 같고 자리가 다르면 볼
	 4) 계속 반복
	 E) 종료조건은 3 스트라이크 삼진아웃
	*/
	// 랜덤 시드 초기화
	srand(time(NULL));

	// 변수 선언부
	int number[10];
	int comNumber[3];
	int myNumber[3];
	int dest, sour, temp;
	int ballCount;
	int strikeCount;

	// 야구게임에 쓸 숫자 0~9 10개를 초기화 하는 부분
	for (int i = 0; i < 10; i++)
	{
		number[i] = i;
	}

	// number 배열을 suffle 하는 부분
	for (int i = 0; i < 50; i++)
	{
		dest = rand() % 10;
		sour = rand() % 10;

		temp = number[dest];
		number[dest] = number[sour];
		number[sour] = temp;
	}

	// 컴퓨터가 랜덤숫자 3개를 저장하는 부분
	for (int i = 0; i < 3; i++)
	{
		comNumber[i] = number[i];
	}
	
	// 컴퓨터가 낸 숫자가 뭔지 보여주는 부분
	cout << "컴퓨터가 낸 숫자: ";
	for (int i = 0; i < 3; i++)
	{
		cout << comNumber[i] << " ";
	}
	cout << endl;

	// 실제 게임이 진행되는 부분
	while (true)
	{
		cout << "0~9까지 숫자를 입력하시오 !!!" << endl;

		// 숫자를 3개 입력받는다.
		for (int i = 0; i < 3; i++)
		{
			cout << i + 1 << "번째 숫자를 입력: ";
			cin >> myNumber[i];
		}

		// 볼, 스트라이크 초기화
		ballCount = 0;
		strikeCount = 0;

		// 숫자야구에서 내 값과 컴퓨터의 값을 비교하는 부분.
		// 컴퓨터
		for (int i = 0; i < 3; i++)
		{
			// 플레이어
			for (int k = 0; k < 3; k++)
			{
				// 컴퓨터 숫자와 내가 선택한 숫자가 같은지?
				if (comNumber[i] == myNumber[k])
				{
					// 자리까지 같은지?
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

		cout << ballCount << "볼 " << strikeCount << "스트라이크" << endl;

		// 3 스트라이크면 삼진 아웃으로 게임이 종료된다.
		if (strikeCount == 3)
		{
			cout << strikeCount << "스트라이크!!! 삼진아웃!!!" << endl;
			break;
		}
	// end of while
	}

	system("pauses");
	return 0;
}