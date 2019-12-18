#include "SlidePuzzle.h"



void SlidePuzzle::init_()
{
	// ������ ����� ���� ���ڸ� �ʱ�ȭ�Ѵ�.
	int number = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k < 5; k++)
		{
			_board[i][k] = number + 1;
			_answerBoard[i][k] = number + 1;
			number++;
		}
	}
	_board[4][4] = 0;
	_answerBoard[4][4] = 0;

	// _isGameOver�� �ʱ�ȭ�Ѵ�.
	_isGameOver = false;
}

void SlidePuzzle::run_()
{
	// ������ ���⼭ ���۵ȴ�.
	// ���带 ���⼭ ���´�.
	suffle_board();

	while (_isGameOver == false)
	{
		// ������ ���ư��� ���� ���带 ���� �׸���, 
		// �Է� ���� ��ǥ�� ������Ʈ �Ѵ�.
		show_board();
		update_();

		// ������ �������� �ƴ��� Ȯ���ؼ� ���̸� �����Ѵ�.
		if (is_gameOver() == true)
		{
			// ������ �¸� �޽����� ���鼭 ����
			show_board();
			cout << "Player Win !!!" << endl;
			system("pause");
			break;
		}
	}
}

void SlidePuzzle::exit_()
{
	// ������ ����� �� ȣ���Ѵ�.
	// ������ ���Ḧ �˸��� �Լ���.
	cout << "������ �����ϰ� �����մϴ�." << endl;
	Sleep(2000);
}

void SlidePuzzle::update_()
{
	// �Է��� �޾Ƽ� ���带 ������Ʈ �ϴ� �Լ���.
	// 1. ���� �Է��� ���� ������
	// 2. ������Ʈ�� ����Ѵ�.
	// 3. ���� ��갪�� range�� �����
	// 4. �ƹ��ϵ� �Ͼ�� �ʴ´�.

	// �Է� �޴� �κ�
	int key = 0;
	if (_kbhit() == 1)
	{
		// _kbhit ���� ������ ����Ű�� �޾Ҵ��� Ȯ���Ѵ�.
		key = _getch();
		// ����Ű �޾Ҵ��� Ȯ��
		if (key == 224)
		{
			key = _getch();
		}

		// �Է��� a �̸� �������� �����Ѵ�.
		if (key == (int)'A' || key == (int)'a')
		{
			init_();
		}
		// �Է��� -1�̸� ������ �����Ѵ�.
		if (key == (int)'Q' || key == (int)'q')
		{
			_isGameOver = true;
		}

		/*cout << key << endl;
		system("pause");*/
		/*cout << isValid(key) << endl;
		system("pause");*/
		// Ű ���� ���� ��� ���⼭ isValid �Լ��� ������ �ƴ��� Ȯ��
		if (isValid(key) == true)
		{
			// ���� �ƴ϶�� swap_ �Լ��� �������� ���� �����Ѵ�.
			swap_(key);
		}
	}// end of if: Ű ���� ���� ���
	else
	{
		// Ű ���� ���� ��� �� ��ٸ���.
		// Ű ���� ���� �� ���带 �ٽ� �� �� �׷��ָ� �߰� ���۸� ���� �� �ִ�.
		show_board();
		Sleep(1000);
	}
}

void SlidePuzzle::suffle_board()
{
	// ���带 �����ϰ� ���� �Լ���. �迭�� ���� �������� ������
	// ���� ������ �迭�� ���� �� �����ϱ� �������� �����ϴ� Ÿ����
	// ����Ű !!!
	//cout << "Call Suffle Board" << endl;

	// rand() �õ尪�� �ʱ�ȭ �Ѵ�.
	srand((unsigned int)time(NULL));

	int keySet[4] = { KEY_LEFT, KEY_UP, KEY_RIGHT, KEY_DOWN };

	// ��� ����Ű�� �������� ���Ѵ�.
	int i = 0;
	while(i < 500)
	{
		// ���� ����Ű ����
		int key = rand() % 4;
		
		if (isValid(keySet[key]))
		{
			// ���� �ƴ� ��� �����Ѵ�.
			swap_(keySet[key]);
			// ���ҿ� ������ ��츸 ī��Ʈ�� �ø���.
			i++;
		}
		// ���ҿ� ������ ��� ī��Ʈ�� ���� �ʴ´�.
	}
}

void SlidePuzzle::show_board()
{
	// ���ڿ� Ư�����ڸ� ���� �����ֱ� ���� ������.
	string number = "";
	// ������Ʈ �� ���带 �����ִ� �Լ���.
	system("cls");
	cout << "*** Sliding Puzzle Game ***" << endl;
	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << "==================" << endl;
		//cout << "----------------------------" << endl;
		for (int k = 0; k < 5; k++)
		{
			//cout << "| ";
			// _board ���� 0�̸� Ư������, ���ڸ� �״��
			// number�� �ִ´�.
			if (_board[i][k] == 0)
			{
				number = "��";
			}
			else
			{
				number = to_string(_board[i][k]);
			}
			cout << setw(2) << number << "  ";
		}
		cout << endl;
		//cout << endl;
	}
	cout << "==================" << endl;
	//cout << "----------------------------" << endl;
}

bool SlidePuzzle::is_gameOver()
{
	bool gameOver = false;
	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k < 5; k++)
		{
			if (_board[i][k] != _answerBoard[i][k])
			{
				// ���� ����� ���� ������ loop Ż��
				gameOver = false;
				return gameOver;
			}
		}
	}
	// ������ ������ Ż���ߴٸ� _board�� ����� ����.
	gameOver = true;

	return gameOver;
}

bool SlidePuzzle::isValid(int key)
{
	bool myValid = false;

	// ���� 0�� ��� �ִ��� �˾Ƴ���.
	int* zeroPos = get_zeroPos();
	/*cout << zeroPos[0] << " " << zeroPos[1] << endl;
	system("pause");*/
	// ������ �� �ִ��� �ƴ��� ���θ� �����Ѵ�.
	switch (key)
	{
		// zeroPos[1] �� x ��
		// zeroPos[0] �� y ���̴�.
	case KEY_LEFT:
		// ������ ��� (x�� - 1)�� 0���� ũ�ų� ���ƾ� �Ѵ�.
		if (zeroPos[1] - 1 >= 0)
		{
			myValid = true;
		}
		break;
	case KEY_UP:
		// ������ ��� (y�� - 1)�� 0���� ũ�ų� ���ƾ� �Ѵ�.
		if (zeroPos[0] - 1 >= 0)
		{
			myValid = true;
		}
		break;
	case KEY_RIGHT:
		// �������� ��� (x�� + 1)�� 4���� �۰ų� ���ƾ� �Ѵ�.
		if (zeroPos[1] + 1 <= 4)
		{
			myValid = true;
		}
		break;
	case KEY_DOWN:
		// �Ʒ����� ��� (y�� + 1)�� 4���� ũ�ų� ���ƾ� �Ѵ�.
		if (zeroPos[0] + 1 <= 4)
		{
			myValid = true;
		}
		break;
	}
	return myValid;
}

void SlidePuzzle::swap_(int key)
{
	// 0 �� ��ġ�� ã�� ������ key ���� ������ ��� �������� �������� ���Ѵ�.
	int *zeroPos = get_zeroPos();
	int x = zeroPos[1];
	int y = zeroPos[0];
	switch (key)
	{
		// zeroPos[1] �� x��
		// zeroPos[0] �� y���̴�.
	case KEY_LEFT:
		// (x�� - 1) �� �����Ѵ�.
		_board[y][x] = _board[y][x - 1];
		_board[y][x - 1] = 0;
		break;
	case KEY_UP:
		// (y�� - 1) �� �����Ѵ�.
		_board[y][x] = _board[y - 1][x];
		_board[y - 1][x] = 0;
		break;
	case KEY_RIGHT:
		// (x�� + 1) �� �����Ѵ�.
		_board[y][x] = _board[y][x + 1];
		_board[y][x + 1] = 0;
		break;
	case KEY_DOWN:
		// (y�� + 1) �� �����Ѵ�.
		_board[y][x] = _board[y + 1][x];
		_board[y + 1][x] = 0;
		break;
	}
}

int * SlidePuzzle::get_zeroPos()
{
	int zeroPos[2] = { 0, 0 };
	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k < 5; k++)
		{
			if (_board[i][k] == 0)
			{
				zeroPos[0] = i;
				zeroPos[1] = k;
			}
		}
	}
	return zeroPos;
}

SlidePuzzle::SlidePuzzle()
{
}


SlidePuzzle::~SlidePuzzle()
{
	exit_();
}
