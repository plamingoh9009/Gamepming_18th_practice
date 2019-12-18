#include <iostream>
#include <conio.h>

using namespace std;

/*
	열거형 : enumeration 줄여서 enum
	열거형 타입의 멤버를 선언.
	열거형 타입의 멤버들은 문자로 표현되나 실제로는 정수값이다.

	변수가 가질 수 있는 가능한 값들을 나열해 놓은 타입니다.
	어떤 변수가 가질 수 있는 값의 종류가 정해져있다면
	정수형 대신 열거형을 쓰는게 편리하다.

	코드의 가독성이 좋아진다.
*/
enum color
{
	RED,
	GREEN, 
	BLUE, 
	BLACK,
	WHITE
};
enum DIRECTION
{
	FORWARD,
	LEFT,
	RIGHT,
	BACK
};
enum MOTION
{
	R_WALK,
	L_WALK,
	R_RUN,
	L_RUN
};

namespace myMotion
{
	enum MOTION
	{
		LEFT_ARROW,
		RIGHT_ARROW,
		UP_ARROW,
		DOWN_ARROW,
		W_KEY,
		A_KEY,
		S_KEY,
		D_KEY,
		P_KEY
	};
}

void show_Motion(myMotion::MOTION action);

int main()
{
	cout << RED << endl;
	cout << GREEN << endl;
	cout << BLUE << endl;
	cout << BLACK << endl;
	cout << WHITE << endl;

	// 선언
	MOTION motion;
	// 위에 선언된 enum의 멤버변수를 입력받을 수 있다.
	motion = L_WALK;
	switch (motion)
	{
	case R_WALK:
		cout << "오른쪽으로 걷는다!!" << endl;
		break;
	case L_WALK:
		cout << "왼쪽으로 걷는다!!" << endl;
		break;
	case R_RUN:
		cout << "왼쪽으로 뛴다." << endl;
		break;
	case L_RUN:
		cout << "오른쪽으로 뛴다." << endl;
		break;
	}
	cout << endl << endl;

	if (motion == L_WALK)
	{
		motion = R_RUN;

		if (motion == R_RUN)
		{
			cout << "오른쪽으로 뛴다." << endl;
		}
	}

	/*
		열거형을 사용해서 방향키 또는 기타등등
		상태를 표시할 것.
		ex) A 를 누르면 왼쪽으로 간다 표시
			다른 방향으로 전환하면 그 방향도 표시한다.
	*/

	//enum myMotion 을 쓰기위해서 초기화한다.
	myMotion::MOTION action;
	action = myMotion::P_KEY;

	// 반복한다.
	while (true)
	{
		// 입력을 받아본당.
		int ch_Motion;
		cout << "모션입력 받음." << endl;
		ch_Motion = _getch();

		// 화살표 입력 받았을 때를 처리한다.
		if (ch_Motion == 224)
		{
			ch_Motion = _getch();

			switch (ch_Motion)
			{
			case 72:
				action = myMotion::UP_ARROW;
				break;
			case 75:
				action = myMotion::LEFT_ARROW;
				break;
			case 77:
				action = myMotion::RIGHT_ARROW;
				break;
			case 80:
				action = myMotion::DOWN_ARROW;
				break;
			}
		}
		// 방향키 입력받았으면 아래의 내용을 생략한다.
		else 
		{
			switch (ch_Motion)
			{
			case 'W':
			case 'w':
				action = myMotion::W_KEY;
				break;
			case 'A':
			case 'a':
				action = myMotion::A_KEY;
				break;
			case 'S':
			case 's':
				action = myMotion::S_KEY;
				break;
			case 'D':
			case 'd':
				action = myMotion::D_KEY;
				break;
			case 'P':
			case 'p':
				action = myMotion::P_KEY;
				break;
			}// end of switch: 입력받은 키
		}
		
		// 상태 보기
		show_Motion(action);
	}// end of while: 모션 입력받기
	system("pause");
	return 0;
}

void show_Motion(myMotion::MOTION action)
{
	switch (action)
	{
	case myMotion::LEFT_ARROW:
		cout << "왼쪽으로 간다 ~~~" << endl;
		break;
	case myMotion::RIGHT_ARROW:
		cout << "오른쪽으로 간다 ~~~" << endl;
		break;
	case myMotion::UP_ARROW:
		cout << "위로 간다 ~~~" << endl;
		break;
	case myMotion::DOWN_ARROW:
		cout << "아래로 간다 ~~~" << endl;
		break;
	case myMotion::W_KEY:
		cout << "위로 간다 ~~~" << endl;
		break;
	case myMotion::A_KEY:
		cout << "왼쪽으로 간다 ~~~" << endl;
		break;
	case myMotion::S_KEY:
		cout << "아래로 간다 ~~~" << endl;
		break;
	case myMotion::D_KEY:
		cout << "오른쪽으로 간다 ~~~" << endl;
		break;
	case myMotion::P_KEY:
		cout << "일시정지 한다 ~~~" << endl;
		break;
	default:
		break;
	}
}

void update()
{
	// 연산하는 곳
}

void render()
{
	// 그리는 곳
}