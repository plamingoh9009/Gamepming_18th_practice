#include <iostream>

using namespace std;
/*
	변수는 컴퓨터의 메모리에 생성된다.
	 -> 메모리에 일정한 공간을 확보해두고 값을 저장 또는 가져오는 방식

	* 포인터: 가르키다(이정표)
	메모리의 한 지점을 가리키는 변수다.
	포인터는 메모리의 번지를 값으로 가진다.
	즉 포인터를 주소값이라고 한다.
	포인터를 선언할 때는 *를 붙혀서 사용한다.
	모든 변수에는 메모리의 주소값이 있다.


	시스템이 32bit, 64bit 인경우 메모리의 주소 표현방법이 달라진다.
*/
int main()
{
	int num = 10;
	cout << "num의 값: \t" << num << endl;
	// & 붙히면 변수의 주소를 알 수 있다.
	cout << "num의 주소값: \t" << &num << endl;

	// 포인터 변수의 선언방법
	// 타입 * 변수이름
	int *p;
	// 포인터 변수에는 일반적인 변수 값을 넣을 수 없다.
	p = &num;
	cout << "P의 값: \t" << p << endl;
	cout << endl;

	cout << "P의 주소값: \t" << &p << endl;

	// 역참조 -> p를 역참조(포인터 변수 앞에 *)
	// 역참조를 하면 값을 가져오거나 변경할 수 있다.
	cout << "*p(num의 값): \t" << *p << endl;

	// 현재 p는 주소값을 가지고 있는 상태에서
	// 아래와 같이 값을 변경할 수 있다.
	*p = 777;
	cout << "역참조후(num의 값): \t" << num << endl;
	// 포인터는 역참조를 이용해 값을 변경할 수 있는 것이 
	// 포인터의 역할이다. (핵심 포인트)

	int **pp;
	pp = &p;
	cout << "pp의 값은(p의 주소값): \t" << pp << endl;
	cout << endl;

	cout << "*pp가 가르키고 있는 값(num의 주소값): " << *pp << endl;
	cout << endl;

	cout << "**pp가 가르키고 있는 값은(num의 값): " << **pp << endl;
	cout << endl;

	**pp = 1234;
	cout << "변경된 num의 값: " << num << endl;
	cout << endl;

	const char* str = "abced";
	
	cout << str << endl;
	cout << endl;
	cout << (int*)str << endl;
	cout << endl;

	str = "dasdas";
	cout << str << endl;

	system("pause");
	return 0;
}