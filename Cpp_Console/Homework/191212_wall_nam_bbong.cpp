/*
규칙
1. 52장의 트럼프 카드를 사용한다.
 1-1) 힌트. 특수문자는 스다하크, K, Q, J, A
 1-2) A 는 무조건 1로 처리한다.
2. 컴퓨터가 카드 2장을 뽑아서 보여준다. (딜러)
3. 플레이어가 1장의 카드를 뽑는다. 랜덤
4. 딜러가 뽑은 2장의 카드 사이에 플레이어의 카드가 있는지 없는지
 4-1) 사이에 존재하면 돈을 딴다.
 4-2) 사이에 없으면 돈을 잃는다.
 4-3) 문양은 상관없이 오직 숫자로만 비교한다.
5. 카드는 뽑은 이후에 버린다.

6. 소지금이 존재한다. 기본값은 10000원
7. 베팅(베팅시스템)을 한 후 컴퓨터가 카드를 오픈하는 방식.

E. 종료조건은 카드를 다 썼을 때, 소지금이 다 떨어졌을 때
*/

#include <iostream>
#include <time.h>
#include <iomanip>
#include <string>

using namespace std;

// 데이터 타입 정의
typedef int(*DeckType_t)[13];

// 함수 선언부
// 덱에서 카드를 한 장 뽑는 함수
int *get_OneCard(DeckType_t myDeck);
// 덱에서 카드가 몇 장 남았는지 리턴하는 함수
int get_CardCount(DeckType_t myDeck);
// 카드를 1장 보여주는 함수
void show_MyCard(int *myCard, bool isPlayer);
// 테스트를 위해서 덱을 통째로 보여주는 함수
void show_MyDeck(const DeckType_t myDeck);

int main()
{
	// 카드의 정보가 담긴 덱을 만든다.
	// 덱 안의 카드는 처음에 하나도 안썼기 때문에 0으로 초기화한다.
	// 카드마크는 0~3 순서대로 스, 다, 하, 클
	int cardDeck[4][13] = { 0, };
	// 기본적으로 10000원 가지고 시작한다.
	int myMoney = 10000;
	// isPlayer 가지고 딜러인지, 플레이어인지 구분한다.
	bool isPlayer = false;

	// 게임은 종료되기 전까지 여기서 돈다.
	while (true)
	{
		// 남은 카드가 몇장인지 세는 부분
		int cardCount = 0;

		// 딜러가 카드를 뽑기 직전 탈출 여부를 확인한다.
		// 딜러가 뽑을 때는 카드가 3장 이상 남아있어야 한다.
		cardCount = get_CardCount(cardDeck);
		// 게임의 마지막이다. 여기서 탈출 조건을 만든다.
		if (cardCount < 3)
		{
			cout << endl;
			cout << "[Game Over] 남은 카드가 모자랍니다. 게임을 종료합니다." << endl;
			cout << "[소지금] " << myMoney << "\t" <<
				"[남은카드] " << cardCount << endl;
			break;
		}
		else if (myMoney < 100)
		{
			cout << endl;
			cout << "[Game Over] 소지금이 모자랍니다. 게임을 종료합니다." << endl;
			cout << "[소지금] " << myMoney << "\t" <<
				"[남은카드] " << cardCount << endl;
			break;
		}

		// 여기서 딜러가 카드를 2장 뽑아서 보여준다.
		int dealer_FirstPick[2] = { 0, };
		int dealer_SecondPick[2] = { 0, };
		int *card_Pick = nullptr;

		// 딜러가 카드를 1장 뽑은 다음에는 포인터를 초기화해야 오류가 없다.
		card_Pick = get_OneCard(cardDeck);
		dealer_FirstPick[0] = *(card_Pick + 0);
		dealer_FirstPick[1] = *(card_Pick + 1);
		card_Pick = nullptr;

		card_Pick = get_OneCard(cardDeck);
		dealer_SecondPick[0] = *(card_Pick + 0);
		dealer_SecondPick[1] = *(card_Pick + 1);
		card_Pick = nullptr;

		isPlayer = false;
		show_MyCard(dealer_FirstPick, isPlayer);
		show_MyCard(dealer_SecondPick, isPlayer);

		//show_MyDeck(cardDeck);

		// 입력 받기 직전에 탈출 여부를 확인한다.
		// 내가 뽑을 때는 남은 카드가 1장 이상 있어야 한다.
		cardCount = get_CardCount(cardDeck);
		// 게임의 마지막이다. 여기서 탈출 조건을 만든다.
		if (cardCount < 1)
		{
			cout << endl;
			cout << "[Game Over] 남은 카드가 모자랍니다. 게임을 종료합니다." << endl;
			cout << "[소지금] " << myMoney << "\t" <<
				"[남은카드] " << cardCount << endl;
			break;
		}
		else if (myMoney < 100)
		{
			cout << endl;
			cout << "[Game Over] 소지금이 모자랍니다. 게임을 종료합니다." << endl;
			cout << "[소지금] " << myMoney << "\t" <<
				"[남은카드] " << cardCount << endl;
			break;
		}

		// 여기서 소지금이 얼마인지, 배팅을 얼마나 할건지
		// 남은 카드가 몇장인지 보여준다.
		cardCount = get_CardCount(cardDeck);
		cout << "[소지금] " << myMoney << "\t" << 
			"[남은카드] " << cardCount << endl;
		cout << "[베팅] 1. [100]" << "   " <<
			"2. [300]" << "   " <<
			"3. [1000]" << "   " <<
			"게임종료는 -1을 입력하세요." << endl;

		int myAction = 0;
		int myBatting = 0;
		cin >> myAction;

		// 여기서 입력에 따른 예외처리를 한다.
		switch (myAction)
		{
		case 1:
			// 1번은 100원 배팅이다.
			myBatting = 100;
			break;
		case 2:
			// 2번은 300원 배팅이다.
			myBatting = 300;
			break;
		case 3:
			// 3번은 1000원 배팅이다.
			myBatting = 1000;
			break;
		case -1:
			// -1은 종료다.
			cout << "게임을 종료합니다." << endl;
			system("pause");
			exit(0);
			break;
		default:
			cout << "잘못된 번호를 골랐습니다. " <<
				"다시 선택하세요." << endl;
			break;
		}

		// 위에서 입력을 받았으면 나도 카드를 1장 받는다.
		int player_Pick[2] = { 0, };
		card_Pick = get_OneCard(cardDeck);
		player_Pick[0] = *(card_Pick + 0);
		player_Pick[1] = *(card_Pick + 1);
		card_Pick = nullptr;

		isPlayer = true;
		show_MyCard(player_Pick, isPlayer);
		// 카드를 받았으면 소지금 부분을 내 배팅금으로 바꿔서 보여준다.
		cardCount = get_CardCount(cardDeck);
		cout << "[베팅액] " << myBatting << "\t" <<
			"[남은카드] " << cardCount << endl;
		// 보여주면서 일시정지를 걸어야 게임을 하는 듯한 느낌을 준다.
		system("pause");

		// 두 카드 중에서 큰 쪽과 작은 쪽을 나눈다.
		int bigCard = -1;
		int smallCard = -1;
		if (dealer_FirstPick[1] > dealer_SecondPick[1])
		{
			bigCard = dealer_FirstPick[1];
			smallCard = dealer_SecondPick[1];
		}
		else
		{
			bigCard = dealer_SecondPick[1];
			smallCard = dealer_FirstPick[1];
		}

		// 내 카드랑 비교해서 이긴 결과와 진 결과를 보여준다.
		if (smallCard < player_Pick[1] &&
			player_Pick[1] < bigCard)
		{
			// 내 카드가 smallCard ~ bigCard 면 내 승리.
			// 돈을 번다.
			myMoney += myBatting * 2;
			cout << "[결과] Player의 승리 !!! " <<
				"[소지금] + " << myBatting * 2 << endl;
		}
		else
		{
			// 비기는 경우는 없으니 나머지 경우는 전부 패배
			// 돈을 잃는다.
			myMoney -= myBatting;
			cout << "[결과] Player의 패배 ㅜㅜ " <<
				"[소지금] - " << myBatting << endl;
		}

	} // end of while
	
	//show_MyDeck(cardDeck);
	
	//cout << dealer_FirstPick[0] << " " << dealer_FirstPick[1] << endl;
	//cout << "Main dealer_FirstPick: " << dealer_FirstPick << endl;
	//cout << "Main dealer_SecondPick: " << dealer_SecondPick << endl;

	system("pause");
	return 0;
}

int *get_OneCard(DeckType_t myDeck)
{
	// 여기서 랜덤 시드를 초기화한다.
	srand(time(NULL));
	// 내가 뽑은 카드는 myPick에 저장한다.
	int myPick[2] = { 0, };
	// 여기서 카드를 랜덤하게 한 장 뽑는다.
	// 만약 중복 카드라면 중복이 아닐때까지 다시 뽑는다.
	bool isOver = false;
	while (isOver != true)
	{
		// mark: 카드의 마크
		// number: 카드의 숫자
		int mark = rand() % 4;
		int number = rand() % 13;

		// 랜덤 카드가 기존에 뽑았던 카드인지 중복을 검사한다.
		if (myDeck[mark][number] == 0)
		{
			// myDeck에서 확인한 값이 0이면 안뽑은 카드니까 myPick에
			// 좌표를 저장하고 루프를 종료한다.
			myPick[0] = mark;
			myPick[1] = number;
			isOver = true;
		}
	}
	//cout << myPick[0] << " " << myPick[1] << endl;

	// 덱에서 뽑은 자리는 1로 바꾼다.
	myDeck[myPick[0]][myPick[1]] = 1;
	//show_MyDeck(myDeck);

	// 뽑은 카드의 좌표를 리턴한다.
	//cout << "pick_Card() myPick: " << myPick << endl;
	return myPick;
}

int get_CardCount(DeckType_t myDeck)
{
	int cardCount = 0;
	for(int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 13; k++)
		{
			if (myDeck[i][k] == 0)
			{
				cardCount++;
			}
		}
	}
	//cout << "cardCount() side " << cardCount << endl;
	//show_MyDeck(myDeck);
	return cardCount;
}

void show_MyCard(int * myCard, bool isPlayer)
{
	// 카드를 보여주는 함수다.
	int mark = myCard[0];
	int number = myCard[1];

	// 숫자 데이터를 출력 포맷으로 바꾸는 부분이다.
	string s_mark = "";
	string s_number = "";

	switch (mark)
	{
	case 0:
		// 0번은 스페이드
		s_mark = "♠";
		break;
	case 1:
		// 1번은 다이아
		s_mark = "◇";
		break;
	case 2:
		// 2번은 하트
		s_mark = "♡";
		break;
	case 3:
		// 3번은 클로버
		s_mark = "♣";
		break;
	}
	// 숫자형태의 number를 문자열 ch_number로 바꾸는 부분이다.
	number++;
	switch (number)
	{
	case 1:
		// 1은 에이스다.
		s_number = "A";
		break;
	case 11:
		// 11은 잭이다.
		s_number = "J";
		break;
	case 12:
		// 12는 퀸이다.
		s_number = "Q";
		break;
	case 13:
		// 13은 킹이다.
		s_number = "K";
		break;
	default:
		// 나머지는 그냥 그대로다.
		s_number = to_string(number);
		break;
	}

	// 카드 보여주는 폼을 만든다.
	cout << "=============" << endl;
	cout << "||" << s_mark << " " << setw(2) 
		<< s_number << "    " << "||" << endl;
	cout << "||" << "    " << "     ||" << endl;
	cout << "||" << "    " << "     ||" << endl;
	cout << "||" << "    " << "     ||" << endl;
	cout << "||" << "    " << "     ||" << endl;
	cout << "||" << "    " << "     ||" << endl;
	cout << "||" << "    " << s_mark << " " << setw(2) 
		<< s_number << "||" << endl;
	cout << "=============" << endl;

	if (isPlayer == true)
	{
		cout << "[Player's Pick]: " << s_mark << " " << s_number << endl;
	}
	else
	{
		cout << "[Dealer's Pick]: " << s_mark << " " << s_number << endl;
	}
	//cout << myCard << endl;
}

void show_MyDeck(const DeckType_t myDeck)
{
	// 개발할 때 테스트를 위해서 덱을 통채로 보여주는 함수다.
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			cout << myDeck[i][j] << " ";
		}
		cout << endl;
	}
}