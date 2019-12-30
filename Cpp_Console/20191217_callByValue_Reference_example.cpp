#include <iostream>

using namespace std;
/*
	Call by Value
	�⺻������ c���� �����ϴ� ����̴�. �Լ����� ���� ������ ����
	�����ϴ� ����̴�. ���ڷ� ���޵Ǵ� ������ �Լ��� �Ű������� �����Ѵ�.
	�̷��� �Ǹ� ���ڷ� ������ �����ʹ� ������ ������ �ȴ�.
	�Ű������� �����ص� ������ �������� ������ ��ġ�� �ʴ´�.
	�������� �ٲ� �ʿ䰡 ���� ��� ����Ѵ�.

	Call by Reference
	�Լ����� ���� �����ϴ� ��� �ּҰ��� �����ϴ� ����̴�.
	�����͸� �̿��� �ּҰ��� �Ѱ��ִ� ���. 
	��, ������ ���� a�� b�� ������ a, b �ּҰ� ���޵Ǿ� ���� ���� ����ȴ�.
*/
void swap_v(int, int);
void swap_r(int*, int*);

int main()
{
	int a = 10;
	int b = 20;

	cout << a << " " << b << endl;
	swap_v(a, b);
	cout << a << " " << b << endl;
	swap_r(&a, &b);
	cout << a << " " << b << endl;

	system("pause");
	return 0;
}

void swap_v(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swap_r(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
