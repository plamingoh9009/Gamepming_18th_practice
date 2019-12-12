#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie();

	// 변수 선언부
	int numA, numB;
	cin >> numA >> numB;

	cout.precision(12);
	cout << (double)numA / numB;

	system("pause");
	return 0;
}