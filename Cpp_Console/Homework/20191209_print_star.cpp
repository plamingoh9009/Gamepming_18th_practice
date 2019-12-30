# include <iostream>

using namespace std;

int main()
{
	// 별찍기의 4가지 유형 중에 1가지를 보여준다.
	int select_Num = 0;

	cout << "[1-4] 중에 1가지 유형의 별찍기를 출력합니다. " << endl;
	cout << "숫자입력: ";
	cin >> select_Num;

	cout << select_Num << endl;

	// 여기서 출력 조건 설정.
	switch (select_Num)
	{
	case 1:
		cout << "별찍기 1번 출력" << endl;

		for (int i = 0; i < 5; i++)
		{
			for (int k = 0; k <= i; k++)
			{
				cout << "★";
			}
			cout << endl;
		}
		break;

	case 2:
		cout << "별찍기 2번 출력" << endl;

		for (int i = 0; i < 5; i++)
		{
			// 여기서 공백을 역삼각형으로 출력
			for (int k = 0; k < (4 - i); k++)
			{
				cout << "  ";
			}

			// 여기서 별을 출력
			for (int p = 0; p <= i; p++)
			{
				cout << "★";
			}
			cout << endl;
		}
		break;

	case 3:
		cout << "별찍기 3번 출력" << endl;

		for (int i = 5; i > 0; i--)
		{
			for (int k = 0; k < i; k++)
			{
				cout << "★";
			}
			cout << endl;
		}
		break;

	case 4:
		cout << "별찍기 4번 출력" << endl;
		
		for (int i = 5; i > 0; i--)
		{
			// 여기서 공백을 삼각형으로 출력
			for (int p = 0; p < 5 - i; p++)
			{
				cout << "  ";
			}

			// 여기서 별을 역삼각형으로 출력
			for (int k = 0; k < i; k++)
			{
				cout << "★";
			}
			cout << endl;
		}
		break;
	default:
		cout << "[1-4] 범위 내에서 입력하세요" << endl;
		break;
	} // end of switch

	system("pause");
	return 0;
}