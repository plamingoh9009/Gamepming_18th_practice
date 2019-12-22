#include "GameBase.h"


int GameBase::input_choice()
{
	int myChoice = 0;
	while (true)
	{
		// Ż������: CHOICE_PAGE ������ ����� ��
		cin >> myChoice;
		if (PAGE_EXIT <= myChoice && myChoice < PAGE_END)
		{
			break;
		}
		else
		{
			// ���
			show_warnMessage(WARN_INVALID_INPUT);
		}// end of if-else: CHOICE_PAGE out of range �� ��
	}
	return myChoice;
}

void GameBase::show_warnMessage(WARN_MESSAGE myCase)
{
	switch (myCase)
	{
	case WARN_INVALID_INPUT:
		cout << "[���] �߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���." << endl;
		break;
	}
}

GameBase::GameBase()
{
}


GameBase::~GameBase()
{
}
