#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;

int main()
{
	srand(time(NULL));

	// 카드는 52장 
	int card[52];
	// 문양 3개, 숫자 3개 -> 카드를 뽑을 때
	int shape[3];
	int number[3];
	// 셔플용 변수
	int dest, sour, temp;
	// 
	int betting = 0;
	int money = 10000;
	int useCard = 0;

	// 카드값 초기화
	for (int i = 0; i < 52; i++)
	{
		card[i] = i;
	}
	// 카드 셔플
	for (int i = 0; i < 500; i++)
	{
		dest = rand() % 52;
		sour = rand() % 52;

		temp = card[dest];
		card[dest] = card[sour];
		card[sour] = temp;
	}
	while (true)
	{
		// 보여줄 카드 2장, 내 카드 1장 총 3장
		for (int i = 0; i < 3; i++)
		{
			// 뽑은 카드의 문양과 숫자는 여기서 결정
			shape[i] = card[i + useCard] / 13;
			number[i] = card[i + useCard] % 13;

			// 모양셋팅
			switch (shape[i])
			{
			case 0:
				cout << "♠";
				break;
			case 1:
				cout << "♣";
				break;
			case 2:
				cout << "◆";
				break;
			case 3:
				cout << "♥";
				break;
			} // end of switch(shape)

			switch (number[i])
			{
			case 0:
				cout << "A \t";
				break;
			case 10:
				cout << "J \t";
				break;
			case 11:
				cout << "Q \t";
				break;
			case 12:
				cout << "K \t";
				break;
			default:
				cout << number[i] + 1 << " \t";
				break;
			}// end of switch(number)
		}// end of for: 보여줄 카드 셋팅

		// 셋팅 값으로 출력
		cout << "총 금액: " << money << endl;
		cout << "금액을 베팅하시오: " << betting << endl;
		cin >> betting;

		if (money < 1000)
		{
			cout << "파산!!!! 집으로 돌아가라" << endl;
			break;
		}
		if (1000 > betting || betting > money)
		{
			cout << "베팅액은 1000 이상 소지금 이하" << endl;
			Sleep(1000);
			continue;
		}

		// 내 카드는 number[2]
		if (number[0] < number[2] && number[2] < number[1] ||
			number[0] > number[2] && number[2] > number[1])
		{
			cout << "카드 숫자: " << number[2] + 1 << endl;
			money += betting;
			cout << betting << "돈을 획득했다." << endl;
			Sleep(1000);
		}
		else
		{
			cout << "카드 숫자: " << number[2] + 1 << endl;
			money -= betting;
			cout << betting << "돈을 잃었다. !!!" << endl;
			Sleep(1000);
		}
		// 사용한 카드는 버린다.
		useCard += 3;
		cout << "현재 사용한 카드 수: " << useCard << endl;

		// 게임 종료
		if (useCard == 51)
		{
			cout << "카드가 없으므로 종료한다." << endl;
			break;
		}

	}// end of while(game over)
}
