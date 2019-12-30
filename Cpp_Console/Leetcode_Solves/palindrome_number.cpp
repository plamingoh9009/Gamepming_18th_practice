#include <iostream>
#include <string>

std::string string_reverse(std::string my_string);

int main()
{
	/*
	���� num�� �Է¹޾Ƽ� �ȹٷ� �о��� ��, �Ųٷ� �о��� ���� ������ true, �ٸ��� false�� ����ϴ� ���α׷�
	ex)
		Input: 121
		Output: true

		Input: -121
		Output: false
		Explanation: Reads 121- from right to left. Therefore it is not a palindrome.
	*/
	
	// ���� �����
	int num = 0;
	std::string s_num = {};
	std::string s_num_reverse = {};

	// �ڵ� ����
	// ���� num�� �Է¹޴´�.
	std::cout << "Input: ";
	std::cin >> num;

	// ���� num�� s_num�� string ������ �����Ѵ�.
	s_num = std::to_string(num);

	// ���ڿ��� �Ųٷ� ������ ���ؼ� string_reverse()�� ���Ѵ�.
	s_num_reverse = string_reverse(s_num);

	// s_num�� s_num_reverse�� ���ؼ� ������ true, Ʋ���� false�� ����Ѵ�.
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

	// system("pause")�� ���α׷��� ������ ����� ���� ������ �Ͻ����� �Ѵ�.
	system("pause");
	return 0;
}

std::string string_reverse(std::string my_string)
{
	// string�� �Է¹޾Ƽ� ������ �����ϴ� �Լ���.
	int s_length = my_string.length();
	// �� �������� NULL ���ڸ� �ֱ� ���ؼ� 1Byte�� �߰�Ȯ���Ѵ�.
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