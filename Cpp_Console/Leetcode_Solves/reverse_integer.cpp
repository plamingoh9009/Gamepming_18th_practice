#include <iostream>
#include <string>

// string_reverse()�� �����.
std::string string_reverse(std::string my_string);

int main()
{
	/* 
	32bit ���� num�� �Է� �޴´�. num�� ����� ����ϴ� ���α׷��̴�. 
	ex) 123 -> 321
		-123 -> -321
		120 -> 21
	*/

	int num;
	std::string s_num;
	bool is_signed = false;

	// ������ �Է¹޴� �κ�
	std::cout << "���� 1�� �Է� : ";
	std::cin >> num;

	// ���⼭ ����ó��. 
	// ���� ������� is_signed = true, ����� �ٲ۴�.
	if (num < 0)
	{
		is_signed = true;
		num = num * -1;
	}
	else
	{
		is_signed = false;
	}

	// s_num �� num�� ���ڿ��� �����Ѵ�.
	s_num = std::to_string(num);

	// string_reverse()�� ���ؼ� ���ڿ��� �����´�.
	s_num = string_reverse(s_num);
	std::cout << s_num << std::endl;

	// num�� s_num�� int ������ �ٲ㼭 �����Ѵ�.
	num = std::stoi(s_num);
	std::cout << "[run]: string�� int�� ��ȯ�մϴ�. " << std::endl;

	// ���� is_signed �� true ��� -1�� ���ϰ� ����Ѵ�.
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
	// string�� �̰����� �� �Ѿ�Դ��� Ȯ���Ѵ�.
	std::cout << "[run]: string_reverse �Լ��Դϴ�. " << std::endl;

	// s_length�� my_string ���̸� �����Ѵ�.
	int s_length = my_string.length();
	// ���ڿ��� ����� ���� char* �� s_length ���̸�ŭ �����Ҵ� �޴´�.
	// ���ڿ��� �������� NULL�� �־ ���� �˷��� �ϱ� ������ 1byte �߰� �Ҵ��Ѵ�.
	char* my_string_copy = new char[s_length+1];

	// �ݺ����� ������ ���ڿ��� �����´�.
	s_length -= 1;
	for (int i = s_length; i >= 0; i--)
	{
		my_string_copy[s_length - i] = my_string[i];
	}
	// ���ڿ��� ���� �˸��� NULL�� ���� ������ �ٸ� �������� �о������.
	my_string_copy[s_length + 1] = NULL;
	
	// my_string_copy�� �޸� �����ϱ� ���ؼ� my_string�� ���� ���ϴ�.
	my_string = my_string_copy;
	delete[] my_string_copy;

	return my_string;
}