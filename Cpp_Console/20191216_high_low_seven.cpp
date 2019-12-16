#include <iostream>
#include <string>
#include <time.h>
#include <iomanip>
#include <Windows.h>

using namespace std;

typedef int (*deckType_t)[13];

// ī�带 1�� �޴� �Լ���.
void get_oneCard(deckType_t myDeck, int *myCard);
// �� ���� ī�尡 ���� ���Ҵ��� ���� �Լ���.
int get_countOfcardDeck(deckType_t myDeck);
// �� ���� ī�带 ���� �Լ���.
void show_myDeck(deckType_t myDeck);
void show_myCard(int myCard[2], bool isPlayer);
// ���ñݾ��� �޴� �Լ���.
int set_bettingMoney(int card_count, int myMoney);
// high, low, seven �� �ϳ��� �׼��� �޾Ƽ� myMoney�� ������Ʈ �ϴ� �Լ�
int set_action(int myCard[2]);
// ������ ���Ḧ �˸��� �Լ���.
void show_gameOver();

int main()
{
	int cardDeck[4][13] = { 0, };
	int my_money = 10000;

	// �ݺ������� ������ ������.
	while (true)
	{
		// ī�带 ������ 3�� �̴´�.
		int dealer_cards[3][2] = { 0, };
		bool isPlayer = false;
		for (int i = 0; i < 3; i++)
		{
			get_oneCard(cardDeck, dealer_cards[i]);

			/*cout << "[Main]: " << dealer_cards[0][0] << " "
				<< dealer_cards[0][1] << endl;*/

			show_myCard(dealer_cards[i], isPlayer);
		}// end of for: ������ 3���� �̴´�.

		int card_count = get_countOfcardDeck(cardDeck);
		int betting = set_bettingMoney(card_count, my_money);

		// ������ ������, �� ī�带 1�� �̴´�.
		int player_card[2] = { 0, };
		isPlayer = true;
		get_oneCard(cardDeck, player_card);
		// player_card Test code
		/*cout << "player_card: " << player_card[0] << " "
			<< player_card[1] << endl;
		show_myCard(player_card, isPlayer);
		system("pause");*/
		// set_action �Լ��� �ҷ��� high, low, seven �� �ϳ��� �����Ѵ�.
		// ������ ���Ῡ�ο� ���п��δ�.
		int is_gameWin = set_action(player_card);
		// �׼��� ���� �������� �� ī�带 �����ش�.
		Sleep(1000);
		show_myCard(player_card, isPlayer);

		if (is_gameWin == -1)
		{
			// set_action���� ���Ḧ �޾��� ��� ���α׷��� �����Ѵ�.
			show_gameOver();
			break;
		}
		else if (is_gameWin == 1)
		{
			my_money += (betting * 2);
			cout << "[�¸�] Player Win !!!" << "\t" <<
				"+ " << betting*2 << " [������]: " << my_money << endl;
		}
		else
		{
			my_money -= betting;
			cout << "[�й�] Player Lose ...��" << "\t" <<
				"- " << betting << "[������]: " << my_money << endl;
		}
		// ��� ��ٷȴٰ� ���� ���� �����Ѵ�.
		Sleep(2000);
		system("cls");

		// ���� ī�带 ���� 4�庸�� ������� �����Ѵ�.
		// �������� 1000�� �Ʒ��� �������� ��� �����Ѵ�.
		card_count = get_countOfcardDeck(cardDeck);
		if (my_money < 1000 || card_count < 4)
		{
			show_gameOver();
			break;
		}

	}// end of while: ������ �����Ѵ�.

	system("pause");
	return 0;
}

void get_oneCard(deckType_t myDeck, int* myCard)
{
	// ���⼭ �����õ� �ʱ�ȭ
	srand(time(NULL));

	// ���� ī�尡 �ߺ��ȴٸ� �ٽ� �̴´�.
	while (true)
	{
		// ���� ������ mark, number�� �̴´�.
		int mark = rand() % 4;
		int number = rand() % 13;

		if (myDeck[mark][number] == 0)
		{
			myCard[0] = mark;
			myCard[1] = number;
			
			// �� ī�嵦���� ���� ī�带 ������.
			myDeck[mark][number] = -1;
			break;
		}
	}// end of while: ī�带 �̴� �ݺ���

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

	// ī���� ��ũ�� �����ϴ� ��
	string mark;
	switch (myCard[0])
	{
		// myCard[0] �� ���� ���� ����� ��ũ�� �޶�����.
	case 0:
		mark = "��";
		break;
	case 1:
		mark = "��";
		break;
	case 2:
		mark = "��";
		break;
	case 3:
		mark = "��";
		break;
	}// end of switch: ����� ��ũ�� �����Ѵ�.

	// Ư�� ���ڴ� A, J, Q, K �� �ٲٰ�, ����� ���ڴ� �׳� ����Ѵ�.
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

	// ���⼭ ī�带 �̻ڰ� �����ش�.
	cout << "==========" << endl;
	cout << "||" << mark << setw(2) << 
		number << "\t" << "||" << endl;

	cout << "||" << "   \t" << "||" << endl;
	cout << "||" << "   \t" << "||" << endl;
	cout << "||" << "   \t" << "||" << endl;

	cout << "||" << "  " << mark << setw(2) <<
		number << "||" << endl;
	cout << "==========" << endl;

	// ���⼭ 1�ʾ� �����̸� �Ǵ�.
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
		// ���� ī�尡 �������� �����ָ鼭 ���ñ��� ���Ѵ�.
		cout << "[�˸�]: ������ 1000�� �̻�, ������ ���ϸ� �����մϴ�." << endl;
		cout << "[������] " << myMoney << "��" << "\t";
		cout << "[����ī��] " << card_count << " ��" << endl;
		cout << "[����]: ";
		cin >> betting;

		if (1000 <= betting && betting <= myMoney)
		{
			break;
		}
	}// end of while: ���ñ� �����ϴ� �ݺ���
	
	return betting;
}

int set_action(int myCard[2])
{
	// �׼��� enum���� �����Ѵ�.
	enum action 
	{
		EXIT = -1,
		HIGH = 1,
		LOW,
		SEVEN
	};
	// enum�� ���� ���ؼ��� ���� �ѹ� �ʱ�ȭ�ؾ� �Ѵ�.
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
			// �Է� ������ ������ while���� ���� ������.
			break;
		}
		else
		{
			// �Է� ������ Ʋ���� while ���� ��� ����.
			cout << "[�˸�]: �߸��� ��ȣ�� �����߽��ϴ�." << endl;
		}
	}// end of while: action�� �Է¹޴� ������

	// myAction ����� ���� ������ ����� ������.
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
	}// end of switch: �� action�� ���� ���� ���и� ����

	// ���Ḧ �޾��� ��� ���� -1
	// ���� �۵��� ���� 1, 0
	return is_gameWin;
}

void show_gameOver()
{
	cout << endl;
	cout << "[�˸�]: ������ �����մϴ�." << endl;
}
