/*
��Ģ
1. 52���� Ʈ���� ī�带 ����Ѵ�.
 1-1) ��Ʈ. Ư�����ڴ� ������ũ, K, Q, J, A
 1-2) A �� ������ 1�� ó���Ѵ�.
2. ��ǻ�Ͱ� ī�� 2���� �̾Ƽ� �����ش�. (����)
3. �÷��̾ 1���� ī�带 �̴´�. ����
4. ������ ���� 2���� ī�� ���̿� �÷��̾��� ī�尡 �ִ��� ������
 4-1) ���̿� �����ϸ� ���� ����.
 4-2) ���̿� ������ ���� �Ҵ´�.
 4-3) ������ ������� ���� ���ڷθ� ���Ѵ�.
5. ī��� ���� ���Ŀ� ������.

6. �������� �����Ѵ�. �⺻���� 10000��
7. ����(���ýý���)�� �� �� ��ǻ�Ͱ� ī�带 �����ϴ� ���.

E. ���������� ī�带 �� ���� ��, �������� �� �������� ��
*/

#include <iostream>
#include <time.h>
#include <iomanip>
#include <string>

using namespace std;

// ������ Ÿ�� ����
typedef int(*DeckType_t)[13];

// �Լ� �����
// ������ ī�带 �� �� �̴� �Լ�
int *get_OneCard(DeckType_t myDeck);
// ������ ī�尡 �� �� ���Ҵ��� �����ϴ� �Լ�
int get_CardCount(DeckType_t myDeck);
// ī�带 1�� �����ִ� �Լ�
void show_MyCard(int *myCard, bool isPlayer);
// �׽�Ʈ�� ���ؼ� ���� ��°�� �����ִ� �Լ�
void show_MyDeck(const DeckType_t myDeck);

int main()
{
	// ī���� ������ ��� ���� �����.
	// �� ���� ī��� ó���� �ϳ��� �Ƚ�� ������ 0���� �ʱ�ȭ�Ѵ�.
	// ī�帶ũ�� 0~3 ������� ��, ��, ��, Ŭ
	int cardDeck[4][13] = { 0, };
	// �⺻������ 10000�� ������ �����Ѵ�.
	int myMoney = 10000;
	// isPlayer ������ ��������, �÷��̾����� �����Ѵ�.
	bool isPlayer = false;

	// ������ ����Ǳ� ������ ���⼭ ����.
	while (true)
	{
		// ���� ī�尡 �������� ���� �κ�
		int cardCount = 0;

		// ������ ī�带 �̱� ���� Ż�� ���θ� Ȯ���Ѵ�.
		// ������ ���� ���� ī�尡 3�� �̻� �����־�� �Ѵ�.
		cardCount = get_CardCount(cardDeck);
		// ������ �������̴�. ���⼭ Ż�� ������ �����.
		if (cardCount < 3)
		{
			cout << endl;
			cout << "[Game Over] ���� ī�尡 ���ڶ��ϴ�. ������ �����մϴ�." << endl;
			cout << "[������] " << myMoney << "\t" <<
				"[����ī��] " << cardCount << endl;
			break;
		}
		else if (myMoney < 100)
		{
			cout << endl;
			cout << "[Game Over] �������� ���ڶ��ϴ�. ������ �����մϴ�." << endl;
			cout << "[������] " << myMoney << "\t" <<
				"[����ī��] " << cardCount << endl;
			break;
		}

		// ���⼭ ������ ī�带 2�� �̾Ƽ� �����ش�.
		int dealer_FirstPick[2] = { 0, };
		int dealer_SecondPick[2] = { 0, };
		int *card_Pick = nullptr;

		// ������ ī�带 1�� ���� �������� �����͸� �ʱ�ȭ�ؾ� ������ ����.
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

		// �Է� �ޱ� ������ Ż�� ���θ� Ȯ���Ѵ�.
		// ���� ���� ���� ���� ī�尡 1�� �̻� �־�� �Ѵ�.
		cardCount = get_CardCount(cardDeck);
		// ������ �������̴�. ���⼭ Ż�� ������ �����.
		if (cardCount < 1)
		{
			cout << endl;
			cout << "[Game Over] ���� ī�尡 ���ڶ��ϴ�. ������ �����մϴ�." << endl;
			cout << "[������] " << myMoney << "\t" <<
				"[����ī��] " << cardCount << endl;
			break;
		}
		else if (myMoney < 100)
		{
			cout << endl;
			cout << "[Game Over] �������� ���ڶ��ϴ�. ������ �����մϴ�." << endl;
			cout << "[������] " << myMoney << "\t" <<
				"[����ī��] " << cardCount << endl;
			break;
		}

		// ���⼭ �������� ������, ������ �󸶳� �Ұ���
		// ���� ī�尡 �������� �����ش�.
		cardCount = get_CardCount(cardDeck);
		cout << "[������] " << myMoney << "\t" << 
			"[����ī��] " << cardCount << endl;
		cout << "[����] 1. [100]" << "   " <<
			"2. [300]" << "   " <<
			"3. [1000]" << "   " <<
			"��������� -1�� �Է��ϼ���." << endl;

		int myAction = 0;
		int myBatting = 0;
		cin >> myAction;

		// ���⼭ �Է¿� ���� ����ó���� �Ѵ�.
		switch (myAction)
		{
		case 1:
			// 1���� 100�� �����̴�.
			myBatting = 100;
			break;
		case 2:
			// 2���� 300�� �����̴�.
			myBatting = 300;
			break;
		case 3:
			// 3���� 1000�� �����̴�.
			myBatting = 1000;
			break;
		case -1:
			// -1�� �����.
			cout << "������ �����մϴ�." << endl;
			system("pause");
			exit(0);
			break;
		default:
			cout << "�߸��� ��ȣ�� ������ϴ�. " <<
				"�ٽ� �����ϼ���." << endl;
			break;
		}

		// ������ �Է��� �޾����� ���� ī�带 1�� �޴´�.
		int player_Pick[2] = { 0, };
		card_Pick = get_OneCard(cardDeck);
		player_Pick[0] = *(card_Pick + 0);
		player_Pick[1] = *(card_Pick + 1);
		card_Pick = nullptr;

		isPlayer = true;
		show_MyCard(player_Pick, isPlayer);
		// ī�带 �޾����� ������ �κ��� �� ���ñ����� �ٲ㼭 �����ش�.
		cardCount = get_CardCount(cardDeck);
		cout << "[���þ�] " << myBatting << "\t" <<
			"[����ī��] " << cardCount << endl;
		// �����ָ鼭 �Ͻ������� �ɾ�� ������ �ϴ� ���� ������ �ش�.
		system("pause");

		// �� ī�� �߿��� ū �ʰ� ���� ���� ������.
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

		// �� ī��� ���ؼ� �̱� ����� �� ����� �����ش�.
		if (smallCard < player_Pick[1] &&
			player_Pick[1] < bigCard)
		{
			// �� ī�尡 smallCard ~ bigCard �� �� �¸�.
			// ���� ����.
			myMoney += myBatting * 2;
			cout << "[���] Player�� �¸� !!! " <<
				"[������] + " << myBatting * 2 << endl;
		}
		else
		{
			// ���� ���� ������ ������ ���� ���� �й�
			// ���� �Ҵ´�.
			myMoney -= myBatting;
			cout << "[���] Player�� �й� �̤� " <<
				"[������] - " << myBatting << endl;
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
	// ���⼭ ���� �õ带 �ʱ�ȭ�Ѵ�.
	srand(time(NULL));
	// ���� ���� ī��� myPick�� �����Ѵ�.
	int myPick[2] = { 0, };
	// ���⼭ ī�带 �����ϰ� �� �� �̴´�.
	// ���� �ߺ� ī���� �ߺ��� �ƴҶ����� �ٽ� �̴´�.
	bool isOver = false;
	while (isOver != true)
	{
		// mark: ī���� ��ũ
		// number: ī���� ����
		int mark = rand() % 4;
		int number = rand() % 13;

		// ���� ī�尡 ������ �̾Ҵ� ī������ �ߺ��� �˻��Ѵ�.
		if (myDeck[mark][number] == 0)
		{
			// myDeck���� Ȯ���� ���� 0�̸� �Ȼ��� ī��ϱ� myPick��
			// ��ǥ�� �����ϰ� ������ �����Ѵ�.
			myPick[0] = mark;
			myPick[1] = number;
			isOver = true;
		}
	}
	//cout << myPick[0] << " " << myPick[1] << endl;

	// ������ ���� �ڸ��� 1�� �ٲ۴�.
	myDeck[myPick[0]][myPick[1]] = 1;
	//show_MyDeck(myDeck);

	// ���� ī���� ��ǥ�� �����Ѵ�.
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
	// ī�带 �����ִ� �Լ���.
	int mark = myCard[0];
	int number = myCard[1];

	// ���� �����͸� ��� �������� �ٲٴ� �κ��̴�.
	string s_mark = "";
	string s_number = "";

	switch (mark)
	{
	case 0:
		// 0���� �����̵�
		s_mark = "��";
		break;
	case 1:
		// 1���� ���̾�
		s_mark = "��";
		break;
	case 2:
		// 2���� ��Ʈ
		s_mark = "��";
		break;
	case 3:
		// 3���� Ŭ�ι�
		s_mark = "��";
		break;
	}
	// ���������� number�� ���ڿ� ch_number�� �ٲٴ� �κ��̴�.
	number++;
	switch (number)
	{
	case 1:
		// 1�� ���̽���.
		s_number = "A";
		break;
	case 11:
		// 11�� ���̴�.
		s_number = "J";
		break;
	case 12:
		// 12�� ���̴�.
		s_number = "Q";
		break;
	case 13:
		// 13�� ŷ�̴�.
		s_number = "K";
		break;
	default:
		// �������� �׳� �״�δ�.
		s_number = to_string(number);
		break;
	}

	// ī�� �����ִ� ���� �����.
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
	// ������ �� �׽�Ʈ�� ���ؼ� ���� ��ä�� �����ִ� �Լ���.
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			cout << myDeck[i][j] << " ";
		}
		cout << endl;
	}
}