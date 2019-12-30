/*
	1. 문자열을 입력받아서 뒤집는 프로그램 짜기
	2. 뒤집어서 짝수번째만 출력하는 프로그램 짜기
*/

// 이건 워닝 메시지를 무시하는 함수다.
//#pragma warning(disable : 4996)
#include<iostream>
#include<string>

using namespace std;

// 문자열을 뒤집어주는 함수
void reverse_String(char *orignalString, const int length);
// 문자열을 짝수번째만 출력하는 함수
void show_EvenString(char *originalString, const int length);

int main()
{
	// 문자열을 myString에 입력받는다.
	char myString[300] = { 0, };
	cout << "[문자열 입력]: ";
	cin.getline(myString, 300);
	// 입력받은 문자열의 길이를 구해놓는다.
	int myLength = strlen(myString);

	cout << "[Main] myString: \t" << myString << endl;
	cout << "[Main] myLength: \t" << myLength << endl;
	//cout << "[main] &myString: \t" << &myString << endl;

	// 여기서 문자열을 뒤집는다.
	reverse_String(myString, myLength);
	// 성공적으로 뒤집었다면 myString을 출력했을 때
	// 뒤집어서 나올 것이다.
	cout << "[Main] myString: \t" << myString << endl;
	//cout << "In main testPointer: \t" << testPointer << endl;

	// 여기서 뒤집은 문자열의 짝수번째 문자만을 출력한다.
	show_EvenString(myString, myLength);

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
	
	// 입력받은 값을 직접 비교하기 위한 변수
	char nowCharactor = 0;
	int i = 0;
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

void show_EvenString(char *originalString, const int length)
{
	// 넘겨받은 문자열을 순서대로 짝수번째만 출력하는 프로그램
	
	// 원본 데이터의 훼손을 막기 위해서 카피해서 사용한다.
	char myString[300] = { 0, };
	strcpy_s(myString, 300, originalString);
	// 출력할 결과물을 담는 배열을 만든다.
	char evenString[300] = { 0, };

	// 받은 length 만큼 반복문을 한바퀴 돌려서 짝수번째 글자를 출력한다.
	// 한글이 짬뽕되어 있기 때문에 어쩔 수 없이 다른 변수에 글자를 넣어서 출력해야 한다.
	// stringCounter: 몇번째 글자인지 세는 변수
	int stringCounter = 0;
	int indexOf_Even = 0;
	for (int i=0; i < length; i++)
	{
		// length의 크기는 글자의 갯수와 다를 수있다.

		// 뒤에서부터 확인할 때랑 다르게 앞에서 확인은 1개의 조건이면 충분하다.
		if(	(unsigned char)myString[i] >= (unsigned char)0xA1 )
		{
			// 만약 한글이라면 nowCharactor에 2 Byte를 넣는다.
			stringCounter++;
			if (stringCounter % 2 == 0)
			{
				evenString[indexOf_Even] = myString[i];
				evenString[indexOf_Even + 1] = myString[i + 1];

				// 짝수 글자 갯수는 myString의 글자 갯수와 다르니
				// 새로운 인덱스를 사용한다.
				indexOf_Even += 2;
			}
			// stringCounter 가 홀수더라도 확인 했기때문에 i의 증가는 
			// if문 여부와 상관이 없다.
			// 2 Byte를 확인했으니 i도 추가로 전진한다.
			i++;
		}
		else
		{
			// 한글 아니면 nowCharactor에 1 Byte를 넣는다.
			stringCounter++;
			if (stringCounter % 2 == 0)
			{
				evenString[indexOf_Even] = myString[i];

				indexOf_Even++;
			}
		}// end 조건문: 한글이면 참, 아니면 거짓
	}// end of for: 문자열의 끝까지 확인했음.
	// 루프가 끝났으면 evenString의 끝을 알리기 위해서 null값을 넣어준다.
	evenString[indexOf_Even] = '\0';

	// 출력 부분이다.
	cout << endl;
	cout << "[EvenString]: \t";
	cout << evenString << endl;
}
