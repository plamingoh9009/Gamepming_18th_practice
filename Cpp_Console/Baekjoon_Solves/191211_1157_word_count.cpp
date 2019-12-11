#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	// 출력 속도 증가 코드
	ios::sync_with_stdio(NULL);
	cin.tie();

	// 변수 선언부
	char myStr[1000002] = { 0, };
	int alphabet_cnt[26] = { 0, };
	int length = 0;

	// 문자열 입력받아서 길이를 저장
	cin >> myStr;
	length = strlen(myStr);
	
	// 'A' = 65, 'a' = 97, 'Z' = 90
	// 문자열 길이만큼 반복문
	for (int i = 0; i < length; i++)
	{
		// 'a' 보다 작으면 대문자
		if (myStr[i] < 'a')
		{
			alphabet_cnt[myStr[i] - 'A'] += 1;
		}
		// 'a' 보다 작지 않으면 소문자
		else
		{
			alphabet_cnt[myStr[i] - 'a'] += 1;
		}
	}
	
	int manyNumber = -1;
	for (int i = 0; i < 26; i++)
	{
		// 가장 큰 수를 찾아서 manyNumber에 넣는다.
		if (alphabet_cnt[i] >= manyNumber)
		{
			manyNumber = alphabet_cnt[i];
		}
		//cout << alphabet_cnt[i] << " ";
	}
	//cout << endl;
	//cout << manyNumber << endl;

	// manyNumber를 찾을 때마다 manyCnt 를 더함.
	int manyCnt = 0;
	int manyIndex = -1;
	for (int i = 0; i < 26; i++)
	{
		if (alphabet_cnt[i] == manyNumber)
		{
			manyCnt++;
			// manyCnt를 올린 자리가 어딘지 manyIndex 값을 저장함.
			manyIndex = i;
		}
	}

	// 만약 manyCnt가 1이 아니라면 ?를 출력.
	// 1이라면 알파벳 대문자를 출력 -> 인덱스 + 'A' 하면 나온다.
	if (manyCnt == 1)
	{
		cout << (char)(manyIndex + 'A') << '\n';
	}
	else
	{
		cout << '?' << '\n';
	}

	system("pause");
	return 0;
}