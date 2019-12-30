#include <iostream>
#include <string>

// string_reverse()를 만든다.
std::string string_reverse(std::string my_string);

int main()
{
	/* 
	32bit 정수 num을 입력 받는다. num을 뒤집어서 출력하는 프로그램이다. 
	ex) 123 -> 321
		-123 -> -321
		120 -> 21
	*/

	int num;
	std::string s_num;
	bool is_signed = false;

	// 정수를 입력받는 부분
	std::cout << "정수 1개 입력 : ";
	std::cin >> num;

	// 여기서 예외처리. 
	// 만약 음수라면 is_signed = true, 양수로 바꾼다.
	if (num < 0)
	{
		is_signed = true;
		num = num * -1;
	}
	else
	{
		is_signed = false;
	}

	// s_num 에 num를 문자열로 저장한다.
	s_num = std::to_string(num);

	// string_reverse()를 콜해서 문자열을 뒤집는다.
	s_num = string_reverse(s_num);
	std::cout << s_num << std::endl;

	// num에 s_num을 int 형으로 바꿔서 저장한다.
	num = std::stoi(s_num);
	std::cout << "[run]: string을 int로 전환합니다. " << std::endl;

	// 만약 is_signed 가 true 라면 -1을 곱하고 출력한다.
	if (is_signed == true)
	{
		num = num * -1;
		is_signed = false;
	}
	std::cout << num << std::endl;

	system("pause");
	return 0;
}

std::string string_reverse(std::string my_string)
{
	// string이 이곳으로 잘 넘어왔는지 확인한다.
	std::cout << "[run]: string_reverse 함수입니다. " << std::endl;

	// s_length에 my_string 길이를 저장한다.
	int s_length = my_string.length();
	// 문자열을 뒤집어서 받을 char* 를 s_length 길이만큼 동적할당 받는다.
	// 문자열의 마지막에 NULL을 넣어서 끝을 알려야 하기 때문에 1byte 추가 할당한다.
	char* my_string_copy = new char[s_length+1];

	// 반복문을 돌려서 문자열을 뒤집는다.
	s_length -= 1;
	for (int i = s_length; i >= 0; i--)
	{
		my_string_copy[s_length - i] = my_string[i];
	}
	// 문자열의 끝을 알리는 NULL을 넣지 않으면 다른 영역까지 읽어버린다.
	my_string_copy[s_length + 1] = NULL;
	
	// my_string_copy를 메모리 해제하기 위해서 my_string을 덮어 씁니다.
	my_string = my_string_copy;
	delete[] my_string_copy;

	return my_string;
}