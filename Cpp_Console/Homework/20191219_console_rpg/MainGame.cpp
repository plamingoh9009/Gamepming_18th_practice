#include "MainGame.h"



void MainGame::init_()
{
	_isGameOver = false;
}

void MainGame::run_()
{
	// ���ο��� ������ �����ϸ� ȣ��Ǵ� �Լ���.
	// 1. ���⼭ ���� ȣ���Ѵ�.
	Map stage1_town;
	stage1_town.init_(1);

	// loop�� ����ؼ� Ű�Է� �ް�, �ٽ� �׸���.
	int myKey = 0;
	bool isStageOver = stage1_town.get_isStageOver();
	while (isStageOver == false)
	{
		// ������ ������ Ű�� �Է¹ް�, ������Ʈ �ϰ�, �׸���.
		myKey = inputKey();
		stage1_town.update_map(myKey);

		// Ż�������� q�� �Է¹޾��� ��
		if (myKey == 'q' || myKey == 'Q')
		{
			isStageOver = true;
			stage1_town.set_isStageOver(true);
		}
	}
}

void MainGame::exit_()
{
	cout << "���α׷��� �����ϰ� �����մϴ�." << endl;
	Sleep(1000);
}

int MainGame::inputKey()
{
	int myKey = 0;
	if (_kbhit())
	{
		// Ű �Է��� ���� ��� ����ġ ���� �Ἥ �� ����Ű�� �°� �����Ѵ�.
		myKey = _getch();
		if (myKey == 224)
		{
			myKey = _getch();
			return myKey;
			/*cout << "True" << endl;*/
		}// end of if: ����Ű �Է� �޾Ҵٸ�
		else if (myKey == 'q' || myKey == 'Q')
		{
			return myKey;
		}// end of if: ����Ű�� �Է� �޾Ҵٸ�
	}
	else
	{
		// Ű �Է��� ���� ���
		//Sleep(300);
	}
	return 0;
}

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
	exit_();
}

