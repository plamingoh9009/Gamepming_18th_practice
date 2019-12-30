#include <iostream>
#include <string>

std::string string_reverse(std::string my_string);

int main()
{
	/*
	정수 num을 입력받아서 똑바로 읽었을 때, 거꾸로 읽었을 때가 같으면 true, 다르면 false를 출력하는 프로그램
	ex)
		Input: 121
		Output: true

		Input: -121
		Output: false
		Explanation: Reads 121- from right to left. Therefore it is not a palindrome.
	*/
	
	// 변수 선언부
	int num = 0;
	std::string s_num = {};
	std::string s_num_reverse = {};

	// 코드 메인
	// 정수 num을 입력받는다.
	std::cout << "Input: ";
	std::cin >> num;

	// 정수 num을 s_num에 string 형으로 저장한다.
	s_num = std::to_string(num);

	// 문자열을 거꾸로 뒤집기 위해서 string_reverse()를 콜한다.
	s_num_reverse = string_reverse(s_num);

	// s_num과 s_num_reverse를 비교해서 같으면 true, 틀리면 false를 출력한다.
	if (s_num.compare(s_num_reverse) != 0)
	{
		std::cout << "Output: false" << std::endl;
		std::cout << "Explanation: Reads " << s_num_reverse << " from right to left. ";
		std::cout << "Therefore it is not palindrome." << std::endl;
	}
	else
	{
		std::cout << "Output: true" << std::endl;
	}

	// system("pause")로 프로그램이 끝나도 결과를 보기 쉽도록 일시정지 한다.
	system("pause");
	return 0;
}

std::string string_reverse(std::string my_string)
{
	// string을 입력받아서 뒤집어 리턴하는 함수다.
	int s_length = my_string.length();
	// 맨 마지막에 NULL 문자를 넣기 위해서 1Byte를 추가확보한다.
	char* my_string_copy = new char[s_length + 1];

	s_length -= 1;
	for (int i = s_length; i >= 0; i--)
	{
		my_string_copy[s_length - i] = my_string[i];
	}
	my_string_copy[s_length + 1] = NULL;

	std::cout << "[run]: Reverse OK" << std::endl;
	std::cout << my_string_copy << std::endl;
	
	my_string = my_string_copy;
	return my_string;
}