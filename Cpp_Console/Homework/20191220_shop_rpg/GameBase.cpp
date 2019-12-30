#include "GameBase.h"


int GameBase::input_choice()
{
	int myChoice = 0;
	while (true)
	{
		// 탈출조건: CHOICE_PAGE 범위를 벗어났을 때
		cin >> myChoice;
		if (PAGE_EXIT <= myChoice && myChoice < PAGE_END)
		{
			break;
		}
		else
		{
			// 경고
			show_warnMessage(WARN_INVALID_INPUT);
		}// end of if-else: CHOICE_PAGE out of range 일 때
	}
	return myChoice;
}

void GameBase::show_warnMessage(WARN_MESSAGE myCase)
{
	switch (myCase)
	{
	case WARN_INVALID_INPUT:
		cout << "[경고] 잘못된 입력입니다. 다시 입력하세요." << endl;
		break;
	}
}

GameBase::GameBase()
{
}


GameBase::~GameBase()
{
}
