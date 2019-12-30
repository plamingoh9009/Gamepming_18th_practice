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

	// 초기화
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

	// 게임 메인 코드
	while (true)
	{
		system("cls");
		cout << "재미없는 빙고 게임 ~ " << endl;
		cout << "빙고 카운트: " << bingoCount << endl;

		// 판 그리자
		for (int i = 0; i < 25; i++)
		{
			// 빙고 숫자가 35면
			if (number[i] == 35)
			{
				// 숫자를 #으로 표시함.
				cout << (char)number[i] << "\t";
			}
			else
			{
				cout << number[i] << "\t";
			}

			// 5개마다 1번씩 줄을 띈다.
			if ((i + 1) % 5 == 0)
			{
				cout << "\n\n" << endl;
			}
		} // end of for

		cout << "원하는 숫자를 입력하시오: ";
		cin >> inputNum;

		for (int i = 0; i < 25; i++)
		{
			if (number[i] == inputNum)
			{
				number[i] = 35;
			}
		}

		// 빙고 검사 부분
		bingoCount = 0;
		for (int i = 0; i < 5; i++)
		{
			// 가로 검사
			if (number[i * 5] == 35 &&
				number[i * 5 + 1] == 35 &&
				number[i * 5 + 2] == 35 &&
				number[i * 5 + 3] == 35 &&
				number[i * 5 + 4] == 35)
			{
				bingoCount++;
			}

			// 세로 검사
			if (number[i] == 35 &&
				number[i + 5 * 1] == 35 &&
				number[i + 5 * 2] == 35 &&
				number[i + 5 * 3] == 35 &&
				number[i + 5 * 4] == 35)
			{
				bingoCount++;
			}
		}// end of for

		// 왼쪽 대각선 검사
		if (number[0] == 35 &&
			number[6] == 35 &&
			number[12] == 35 &&
			number[18] == 35 &&
			number[24] == 35)
		{
			bingoCount++;
		}

		// 오른쪽 대각선 검사
		if (number[4] == 35 &&
			number[8] == 35 &&
			number[12] == 35 &&
			number[16] == 35 &&
			number[20] == 35)
		{
			bingoCount++;
		}

		// 빙고카운트가 3이면
		if (bingoCount >= 3)
		{
			cout << "집으로 돌아가자~~" << endl;
			break;
		}
	}// end of while
}