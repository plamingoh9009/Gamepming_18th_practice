#include <iostream>
#include <conio.h>

using namespace std;

/*
	������ : enumeration �ٿ��� enum
	������ Ÿ���� ����� ����.
	������ Ÿ���� ������� ���ڷ� ǥ���ǳ� �����δ� �������̴�.

	������ ���� �� �ִ� ������ ������ ������ ���� Ÿ�Դϴ�.
	� ������ ���� �� �ִ� ���� ������ �������ִٸ�
	������ ��� �������� ���°� ���ϴ�.

	�ڵ��� �������� ��������.
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

	// ����
	MOTION motion;
	// ���� ����� enum�� ��������� �Է¹��� �� �ִ�.
	motion = L_WALK;
	switch (motion)
	{
	case R_WALK:
		cout << "���������� �ȴ´�!!" << endl;
		break;
	case L_WALK:
		cout << "�������� �ȴ´�!!" << endl;
		break;
	case R_RUN:
		cout << "�������� �ڴ�." << endl;
		break;
	case L_RUN:
		cout << "���������� �ڴ�." << endl;
		break;
	}
	cout << endl << endl;

	if (motion == L_WALK)
	{
		motion = R_RUN;

		if (motion == R_RUN)
		{
			cout << "���������� �ڴ�." << endl;
		}
	}

	/*
		�������� ����ؼ� ����Ű �Ǵ� ��Ÿ���
		���¸� ǥ���� ��.
		ex) A �� ������ �������� ���� ǥ��
			�ٸ� �������� ��ȯ�ϸ� �� ���⵵ ǥ���Ѵ�.
	*/

	//enum myMotion �� �������ؼ� �ʱ�ȭ�Ѵ�.
	myMotion::MOTION action;
	action = myMotion::P_KEY;

	// �ݺ��Ѵ�.
	while (true)
	{
		// �Է��� �޾ƺ���.
		int ch_Motion;
		cout << "����Է� ����." << endl;
		ch_Motion = _getch();

		// ȭ��ǥ �Է� �޾��� ���� ó���Ѵ�.
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
		// ����Ű �Է¹޾����� �Ʒ��� ������ �����Ѵ�.
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
			}// end of switch: �Է¹��� Ű
		}
		
		// ���� ����
		show_Motion(action);
	}// end of while: ��� �Է¹ޱ�
	system("pause");
	return 0;
}

void show_Motion(myMotion::MOTION action)
{
	switch (action)
	{
	case myMotion::LEFT_ARROW:
		cout << "�������� ���� ~~~" << endl;
		break;
	case myMotion::RIGHT_ARROW:
		cout << "���������� ���� ~~~" << endl;
		break;
	case myMotion::UP_ARROW:
		cout << "���� ���� ~~~" << endl;
		break;
	case myMotion::DOWN_ARROW:
		cout << "�Ʒ��� ���� ~~~" << endl;
		break;
	case myMotion::W_KEY:
		cout << "���� ���� ~~~" << endl;
		break;
	case myMotion::A_KEY:
		cout << "�������� ���� ~~~" << endl;
		break;
	case myMotion::S_KEY:
		cout << "�Ʒ��� ���� ~~~" << endl;
		break;
	case myMotion::D_KEY:
		cout << "���������� ���� ~~~" << endl;
		break;
	case myMotion::P_KEY:
		cout << "�Ͻ����� �Ѵ� ~~~" << endl;
		break;
	default:
		break;
	}
}

void update()
{
	// �����ϴ� ��
}

void render()
{
	// �׸��� ��
}