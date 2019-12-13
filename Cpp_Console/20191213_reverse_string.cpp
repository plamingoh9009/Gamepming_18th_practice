/*
	1. 문자열을 입력받아서 뒤집는 프로그램 짜기
	2. 뒤집어서 짝수번째만 출력하는 프로그램 짜기
*/
//#pragma warning(disable : 4996)
#include<iostream>
#include<string>

using namespace std;

// 문자열을 뒤집어주는 함수
void reverse_String(char *orignalString, const int length);

int main()
{
	// 문자열을 myString에 입력받는다.
	char myString[300] = { 0, };
	cout << "[문자열 입력]: ";
	cin.getline(myString, 300);
	// 입력받은 문자열의 길이를 구해놓는다.
	int mylength = strlen(myString);

	cout << "[main] myString: \t" << myString << endl;
	cout << "[main] &myString: \t" << &myString << endl;
	cout << "[main] mylength: \t" << mylength << endl;

	// 여기서 문자열을 뒤집는다.
	reverse_String(myString, mylength);
	// 성공적으로 뒤집었다면 myString을 출력했을 때
	// 뒤집어서 나올 것이다.
	cout << "[main] myString: \t" << myString << endl;
	//cout << "In main testPointer: \t" << testPointer << endl;

	system("pause");
	return 0;
}

void reverse_String(char *originalString, const int length)
{
	// 문자열을 받아서 뒤집어주는 함수다.

	// 원본 데이터의 훼손을 막기 위해서 카피해서 처리한다.
	char myString[300] = { 0, };

	//// 한글 받은 후 테스트 코드
	//if (originalString[0] == (char)164)
	//	cout << "true" << endl;
	//if (originalString[1] == (char)161)
	//	cout << "true" << endl;

	// 카피한 공간에 원본을 입력한다.
	int i = 0;
	// 입력받은 값을 직접 비교하기 위한 변수
	char nowCharactor = 0;

	for (int k = length - 1; k >= 0; k--)
	{
		//// originalString[k] 의 값을 확인해보기 위한부분
		//nowCharactor = originalString[k];
		//if ((int)nowCharactor >= (int)0xA4)
		//{
		//	cout << nowCharactor << endl;
		//	cout << "true" << endl;
		//}

		// 여기서 한글을 받은 경우를 처리한다.
		// 한글의 범위는 Hangle[N-1]Hangle[N] 일 때
		// Hangle[N-1] 이 0xA1 ~ 0xD1 를 가진다. -> 모든 한글 공통
		// Hangle[N] 은 받침이 없다면 거의 0xA1 ~ 0xD1 의 값을 가지지만
		// 받침이 있다면 그렇지 않은 경우도 많이 있다.
		if (
			(unsigned char)originalString[k - 1] >= (unsigned char)0xA1 &&
			(unsigned char)originalString[k] >= (unsigned char)0x50 &&
			(unsigned char)originalString[k - 1] != (unsigned char)0xCC
			)
		{
			// 1 Byte 공간에 164보다 큰 수가 넘어오면 한글로 간주한다.

			// 2 Byte [앞], [뒤] 중에 
			// myString [i], [i+1]
			// originalString [k-1], [k]
			// 요렇게 넣어줘야 에러가 없을 것이다.
			myString[i] = originalString[k - 1];
			myString[i + 1] = originalString[k];

			// i=0 일때, myString[0], [1] 에 값을 넣었으니
			// myString[2] 를 참조할 수 있도록 i 에 2를 더해준다.
			i += 2;
			// k=6 일때, originalString[5], [6] 를 참조했으니
			// originalString[4]를 참조할 수 있도록 k에 1을 빼준다.
			// 왜냐면 포문에서 하나 빼고 있으니까
			k--;
		}
		else
		{
			// 한글이 아닌 경우 그냥 그대로 처리한다.
			//cout << originalString[k] << endl;
			myString[i] = originalString[k];
			i++;
		}

	}// end of for: 문장을 전부 뒤집었음.
	// 널값을 넣지 않으면 에러가 난다.
	myString[i] = '\0';
	cout << endl;

	//cout << "[reverse_String] myString: \t" << myString << endl;
	//cout << "In reverse_String originalString: \t" << originalString << endl;
	//cout << length << endl;

	// 여기서 리턴할 originalString에 myString을 대입 해본다. 
	strcpy_s(originalString, 300, myString);

	//cout << originalString << endl;
	//cout << "[reverse_String] originalString: \t" << originalString << endl;
	//cout << "[reverse_String] originalString: \t" << &originalString << endl;
}
