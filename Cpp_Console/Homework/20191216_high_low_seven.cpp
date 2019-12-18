#include <iostream>
#include <string>
#include <time.h>
#include <iomanip>
#include <Windows.h>

using namespace std;

typedef int (*deckType_t)[13];

// 카드를 1장 받는 함수다.
void get_oneCard(deckType_t myDeck, int *myCard);
// 내 덱에 카드가 몇장 남았는지 세는 함수다.
int get_countOfcardDeck(deckType_t myDeck);
// 내 덱과 카드를 보는 함수다.
void show_myDeck(deckType_t myDeck);
void show_myCard(int myCard[2], bool isPlayer);
// 베팅금액을 받는 함수다.
int set_bettingMoney(int card_count, int myMoney);
// high, low, seven 중 하나의 액션을 받아서 myMoney를 업데이트 하는 함수
int set_action(int myCard[2]);
// 게임의 종료를 알리는 함수다.
void show_gameOver();

int main()
{
	int cardDeck[4][13] = { 0, };
	int my_money = 10000;

	// 반복문으로 게임을 돌린다.
	while (true)
	{
		// 카드를 딜러가 3장 뽑는다.
		int dealer_cards[3][2] = { 0, };
		bool isPlayer = false;
		for (int i = 0; i < 3; i++)
		{
			get_oneCard(cardDeck, dealer_cards[i]);

			/*cout << "[Main]: " << dealer_cards[0][0] << " "
				<< dealer_cards[0][1] << endl;*/

			show_myCard(dealer_cards[i], isPlayer);
		}// end of for: 딜러가 3장을 뽑는다.

		int card_count = get_countOfcardDeck(cardDeck);
		int betting = set_bettingMoney(card_count, my_money);

		// 베팅을 했으니, 내 카드를 1장 뽑는다.
		int player_card[2] = { 0, };
		isPlayer = true;
		get_oneCard(cardDeck, player_card);
		// player_card Test code
		/*cout << "player_card: " << player_card[0] << " "
			<< player_card[1] << endl;
		show_myCard(player_card, isPlayer);
		system("pause");*/
		// set_action 함수를 불러서 high, low, seven 중 하나를 선택한다.
		// 리턴은 종료여부와 승패여부다.
		int is_gameWin = set_action(player_card);
		// 액션을 받은 다음에는 내 카드를 보여준다.
		Sleep(1000);
		show_myCard(player_card, isPlayer);

		if (is_gameWin == -1)
		{
			// set_action에서 종료를 받았을 경우 프로그램을 종료한다.
			show_gameOver();
			break;
		}
		else if (is_gameWin == 1)
		{
			my_money += (betting * 2);
			cout << "[승리] Player Win !!!" << "\t" <<
				"+ " << betting*2 << " [소지금]: " << my_money << endl;
		}
		else
		{
			my_money -= betting;
			cout << "[패배] Player Lose ...ㅜ" << "\t" <<
				"- " << betting << "[소지금]: " << my_money << endl;
		}
		// 잠시 기다렸다가 보기 좋게 정리한다.
		Sleep(2000);
		system("cls");

		// 남은 카드를 세서 4장보다 작을경우 종료한다.
		// 소지금이 1000원 아래로 떨어졌을 경우 종료한다.
		card_count = get_countOfcardDeck(cardDeck);
		if (my_money < 1000 || card_count < 4)
		{
			show_gameOver();
			break;
		}

	}// end of while: 게임을 종료한다.

	system("pause");
	return 0;
}

void get_oneCard(deckType_t myDeck, int* myCard)
{
	// 여기서 랜덤시드 초기화
	srand(time(NULL));

	// 뽑은 카드가 중복된다면 다시 뽑는다.
	while (true)
	{
		// 랜덤 돌려서 mark, number를 뽑는다.
		int mark = rand() % 4;
		int number = rand() % 13;

		if (myDeck[mark][number] == 0)
		{
			myCard[0] = mark;
			myCard[1] = number;
			
			// 내 카드덱에서 뽑은 카드를 버린다.
			myDeck[mark][number] = -1;
			break;
		}
	}// end of while: 카드를 뽑는 반복문

	//// Test Code
	//show_myDeck(myDeck);
	//cout << myCard[0] << " " << myCard[1] << endl;
}

void show_myDeck(deckType_t myDeck)
{
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 13; k++)
		{
			cout << myDeck[i][k] << " ";
		}
		cout << endl;
	}
}

void show_myCard(int myCard[2], bool isPlayer)
{
	if (isPlayer == true)
	{
		cout << "[Player Card]" << endl;
	}
	else
	{
		cout << "[Dealer Card]" << endl;
	}
	cout << endl;
	//cout << "[show_myCard]: " << myCard[0] << " " << myCard[1] << endl;

	// 카드의 마크를 결정하는 곳
	string mark;
	switch (myCard[0])
	{
		// myCard[0] 의 값에 따라서 출력할 마크가 달라진다.
	case 0:
		mark = "♠";
		break;
	case 1:
		mark = "◇";
		break;
	case 2:
		mark = "♡";
		break;
	case 3:
		mark = "♣";
		break;
	}// end of switch: 출력할 마크를 결정한다.

	// 특수 숫자는 A, J, Q, K 로 바꾸고, 평범한 숫자는 그냥 출력한다.
	string number;
	switch (myCard[1] + 1)
	{
	case 1:
		number = "A";
		break;
	case 11:
		number = "J";
		break;
	case 12:
		number = "Q";
		break;
	case 13:
		number = "K";
		break;
	default:
		number = to_string(myCard[1]);
		break;
	}
	//cout << mark << number << endl;

	// 여기서 카드를 이쁘게 보여준다.
	cout << "==========" << endl;
	cout << "||" << mark << setw(2) << 
		number << "\t" << "||" << endl;

	cout << "||" << "   \t" << "||" << endl;
	cout << "||" << "   \t" << "||" << endl;
	cout << "||" << "   \t" << "||" << endl;

	cout << "||" << "  " << mark << setw(2) <<
		number << "||" << endl;
	cout << "==========" << endl;

	// 여기서 1초씩 딜레이를 건다.
	Sleep(1000);
}

int get_countOfcardDeck(deckType_t myDeck)
{
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 13; k++)
		{
			if (myDeck[i][k] == 0)
			{
				count++;
			}
		}
	}
	return count;
}

int set_bettingMoney(int card_count, int myMoney)
{
	int betting = 0;
	while (true)
	{
		// 남은 카드가 몇장인지 보여주면서 베팅금을 정한다.
		cout << "[알림]: 베팅은 1000원 이상, 소지금 이하만 가능합니다." << endl;
		cout << "[소지금] " << myMoney << "원" << "\t";
		cout << "[남은카드] " << card_count << " 장" << endl;
		cout << "[베팅]: ";
		cin >> betting;

		if (1000 <= betting && betting <= myMoney)
		{
			break;
		}
	}// end of while: 베팅금 셋팅하는 반복문
	
	return betting;
}

int set_action(int myCard[2])
{
	// 액션을 enum으로 정의한다.
	enum action 
	{
		EXIT = -1,
		HIGH = 1,
		LOW,
		SEVEN
	};
	// enum을 쓰기 위해서는 왠지 한번 초기화해야 한다.
	action _myAction = EXIT;

	int myAction = 0;
	while (true)
	{
		cout << "[1. High]" << "\t";
		cout << "[2. Low]" << "\t";
		cout << "[3. Seven]" << "\t";
		cout << "[-1. Exit]" << endl;
		cin >> myAction;

		if (myAction == -1 || (1 <= myAction && myAction <= 3))
		{
			// 입력 범위가 옳으면 while문을 빠져 나간다.
			break;
		}
		else
		{
			// 입력 범위가 틀리면 while 문을 계속 돈다.
			cout << "[알림]: 잘못된 번호를 선택했습니다." << endl;
		}
	}// end of while: action을 입력받는 루프문

	// myAction 결과에 따라서 게임의 결과가 나뉜다.
	int is_gameWin = 0;
	switch (myAction)
	{
	case EXIT:
		return -1;
		break;
	case HIGH:
		if (myCard[1]+1 > 7)
		{
			is_gameWin = 1;
		}
		break;
	case LOW:
		if (myCard[1]+1 < 7)
		{
			is_gameWin = 1;
		}
		break;
	case SEVEN:
		if (myCard[1]+1 == 7)
		{
			is_gameWin = 1;
		}
		break;
	default:
		break;
	}// end of switch: 내 action에 따른 게임 승패를 결정

	// 종료를 받았을 경우 리턴 -1
	// 정상 작동은 리턴 1, 0
	return is_gameWin;
}

void show_gameOver()
{
	cout << endl;
	cout << "[알림]: 게임을 종료합니다." << endl;
}
