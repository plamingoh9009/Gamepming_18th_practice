#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// �������� ����ؼ� �����ִ� �Լ�
void show_board(int (*my_board)[5]);

int main()
{
	/*
	������� �����
	 1) 5X5 �����ǿ��� player, computer�� ���� �����ϴ� ���� ����
	 2) �� �������� 1~25�� ���ڰ� �����ϰ� ������.
	 3) �� ��: ���� ���ڸ� �Է��ϸ� ��ŷ �Ѵٴ� �ǹ̷� Ư������ ������ �־���.
	 4) ��ǻ�� ��: ���� ���ڸ� ������. (����)

	 * Ư������: 4)���� ��ǻ�Ͱ� �ΰ������� �־ �̱�� ���� �� ���� �����Ѵ�.
	 E) 3�� ����� ���� Over. ���ڸ� ������.
	*/

	// ���� �õ� �ʱ�ȭ �ϴ� �κ�
	srand(time(NULL));
	// ���� �����
	int player_board[5][5] = { 0, };
	int computer_board[5][5] = { 0, };

	// �÷��̾�� ��ǻ���� ���带 �ʱ�ȭ �Ѵ�.
	int cnt = 1;
	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k < 5; k++)
		{
			player_board[i][k] = cnt;
			computer_board[i][k] = cnt;
			cnt++;
		}
	}

	// �÷��̾�� ��ǻ���� ���带 ���´�.
	for (int i = 0; i < 30; i++)
	{
		// player board suffle�� ���� ����
		int p_dest[2] = { rand() % 5, rand() % 5 };
		int p_sour[2] = { rand() % 5, rand() % 5 };
		// coputer board sufffle�� ���� ����
		int c_dest[2] = { rand() % 5, rand() % 5 };
		int c_sour[2] = { rand() % 5, rand() % 5 };
		int temp;
		

		// player board suffle �ϴ� �κ�
		temp = player_board[p_dest[0]][p_dest[1]];
		player_board[p_dest[0]][p_dest[1]] =
			player_board[p_sour[0]][p_sour[1]];
		player_board[p_sour[0]][p_sour[1]] = temp;

		// computer board suffle �ϴ� �κ�
		temp = computer_board[c_dest[0]][c_dest[1]];
		computer_board[c_dest[0]][c_dest[1]] =
			computer_board[c_sour[0]][c_sour[1]];
		computer_board[c_sour[0]][c_sour[1]] = temp;
	}

	// game_over �� true �Ǳ� ������ ������ ����Ѵ�.
	bool game_over = false;
	while (game_over != true)
	{
		// ������ ��Ȱ�� �����ϱ� ���ؼ� �������� �켱 �����ش�.
		cout << "*** �÷��̾� ������ ***" << endl << endl;
		show_board(player_board);
		cout << endl;
		cout << "*** ��ǻ�� ������ ***" << endl << endl;
		show_board(computer_board);
		cout << endl;

		// �� ���� ���� �����Ѵ�. ���� ���ڸ� ���� �Է��Ѵ�.
		int my_num;
		cout << "[My turn] ���ڸ� �Է��Ͻÿ�: ";
		cin >> my_num;

		// ���� �Է��� ���� �켱�� �� �����ǿ��� *�� �ٲ۴�.
		int cnt = 0;
		for (int i = 0; i < 5; i++)
		{
			for (int k = 0; k < 5; k++)
			{
				if (player_board[i][k] == my_num)
				{
					player_board[i][k] = (int)'*';
				}
				else
				{
					// cnt�� 25�� ������ ã�Ƶ� ���ڸ� ��ã�� ��. 
					// ���ڸ� �߸� �Է��� ���̴�.
					cnt++;
				}
			}
		}

		// ��ǻ�� ���ʶ� Ȱ���ϱ� ���ؼ� ���������� ���� �ڸ��� �����ϴ�
		// ������.
		int computer_last_i = 0;
		int computer_last_k = 0;

		// ��ǻ���� �����ǿ��� ���� my_num ���� *�� �ٲ۴�.
		for (int i = 0; i < 5; i++)
		{
			for (int k = 0; k < 5; k++)
			{
				if (computer_board[i][k] == my_num)
				{
					computer_board[i][k] = (int)'*';
					// ��ǻ���� ������ �ڸ� ��ǥ�� �����Ѵ�.
					computer_last_i = i;
					computer_last_k = k;
				}
			}
		}

		
		// �� ���� ������ ��ǻ���� ����
		// ���⼭ ��ǻ�Ͱ� ���� �ڸ��� *�� ���� ����
		bool computer_turn_end = false;
		int computer_num = 0;
		while (computer_turn_end == false)
		{
			// ��ǻ�Ͱ� *�� ���� �ڸ��� rand() �� ������ش�.
			int computer_turn_i = rand() % 5;
			int computer_turn_k = rand() % 5;

			// Ż�������� �����. �����ǿ� *�� ������ *�� ��� Ż��
			if (computer_board[computer_turn_i][computer_turn_k] != (int)'*')
			{
				// computer_num �� ���� �ִ� ���� �����Ѵ�.
				computer_num = computer_board[computer_turn_i][computer_turn_k];
				// �� ������ *�� ��´�
				computer_board[computer_turn_i][computer_turn_k] = (int)'*';
				// Ż���ϴ� �κ��̴�.
				computer_turn_end = true;
			}
			else
			{
				// �����ǿ� *�� ������ Ż������ �ʰ� �ٽ� ��ǥ ��ġ
				continue;
			}
		// end of while ��ǻ�Ͱ� ���� �ڸ��� *�� ��� �ݺ��� Ż��
		}
		cout << "Computer�� ���� �� :" << computer_num << endl;
		// ���� ��ǻ�Ͱ� ���� ������ �� �����ǿ� *�� ��´�.
		for (int i = 0; i < 5; i++)
		{
			for (int k = 0; k < 5; k++)
			{
				if (player_board[i][k] == computer_num)
				{
					player_board[i][k] = (int)'*';
				}
			}
		}

		// ���� üũ�ؼ� 3�� ����� ���� ������ ���� �̱��.
		int player_bingo_cnt = 0;
		// �밢���� ������ �ѹ��� �� ���ƾ� ã�� �� �־ for�� �ۿ� �ִ�.
		int player_left_cross_cnt = 0;
		int player_right_cross_cnt = 0;

		int computer_bingo_cnt = 0;
		// �밢���� ������ �ѹ��� �� ���ƾ� ã�� �� �־ for�� �ۿ� �ִ�.
		int computer_left_cross_cnt = 0;
		int computer_right_cross_cnt = 0;
		// Bingo check column
		for (int i = 0; i < 5; i++)
		{
			// �÷��̾��� * �� ���� ����
			int player_col_cnt = 0;
			int player_row_cnt = 0;
			
			// ��ǻ���� * �� ���� ����
			int computer_col_cnt = 0;
			int computer_row_cnt = 0;
			
			for (int k = 0; k < 5; k++)
			{
				// �÷��̾� ���� �밢�� Ȯ��
				if (i == k)
				{
					// �÷��̾� ������ Ȯ��
					if (player_board[i][k] == (int)'*')
					{
						player_col_cnt++;
						player_left_cross_cnt++;
						/*cout << "Left Cross: " 
							<< player_left_cross_cnt << endl;*/
					}
				}
				else
				{
					// �÷��̾� ������ Ȯ��
					if (player_board[i][k] == (int)'*')
					{
						player_col_cnt++;
					}
				}
				// �÷��̾� ������ �밢�� Ȯ��
				if (k + i + 1 == 5)
				{
					// �÷��̾� ������ Ȯ��
					if (player_board[k][i] == (int)'*')
					{
						player_row_cnt++;
						player_right_cross_cnt++;
					}
				}
				else
				{
					// �÷��̾� ������ Ȯ��
					if (player_board[k][i] == (int)'*')
					{
						player_row_cnt++;
					}
				}

				// ��ǻ�� ���� �밢�� Ȯ��
				if (i == k)
				{
					// ��ǻ�� ������ Ȯ��
					if (computer_board[i][k] == (int)'*')
					{
						computer_col_cnt++;
						computer_left_cross_cnt++;
					}
				}
				else
				{
					// ��ǻ�� ������ Ȯ��
					if (computer_board[i][k] == (int)'*')
					{
						computer_col_cnt++;
					}
				}
				// ��ǻ�� ������ �밢�� Ȯ��
				if (k + i + 1 == 5)
				{
					// ��ǻ�� ������ Ȯ��
					if (computer_board[k][i] == (int)'*')
					{
						computer_row_cnt++;
						computer_right_cross_cnt++;
					}
				}
				else
				{
					// ��ǻ�� ������ Ȯ��
					if (computer_board[k][i] == (int)'*')
					{
						computer_row_cnt++;
					}
				}
			// 1�� Ȯ�� ��
			}
			// �÷��̾��� �����ǿ��� ���� �� �ٿ� 5���� * �̶�� ���� 1�� �ø���.
			if (player_col_cnt == 5)
			{
				player_bingo_cnt++;
			}
			if (player_row_cnt == 5)
			{
				player_bingo_cnt++;
			}
			if (player_left_cross_cnt == 5)
			{
				player_bingo_cnt++;
			}
			if (player_right_cross_cnt == 5)
			{
				player_bingo_cnt++;
			}
			// ��ǻ���� �����ǿ��� ���� �� �ٿ� 5���� * �̶�� ���� 1�� �ø���.
			if (computer_col_cnt == 5)
			{
				computer_bingo_cnt++;
			}
			if (computer_row_cnt == 5)
			{
				computer_bingo_cnt++;
			}
			if (computer_left_cross_cnt == 5)
			{
				computer_bingo_cnt++;
			}
			if (computer_right_cross_cnt == 5)
			{
				computer_bingo_cnt++;
			}
		// end of for
		}

		// ���� ����� ������?
		cout << "Player_bingo: " << player_bingo_cnt << endl;
		cout << "Computer_bingo: " << computer_bingo_cnt << endl;

		// �׽�Ʈ�� ���ؼ� Ż�⹮�� �־�д�.
		if (my_num == -1)
		{
			cout << "������ ������ �����մϴ�. " << endl;
			game_over = true;
		}

		// 3���� ����� ������ ������.
		if (player_bingo_cnt >= 3)
		{
			cout << endl;
			cout << "[Win] Player �¸� !!!" << endl;
			cout << endl;
			game_over = true;
		}
		if (computer_bingo_cnt >= 3)
		{
			cout << endl;
			cout << "[Lose] Player �й� ..." << endl;
			cout << endl;
			game_over = true;
		}


		// ���⼭ �߸� �Է����� ��� ������ش�.
		// ���� ������ ��쿡�� ��� ����� �ʿ䰡 ����.
		if (cnt == 25 && game_over != true)
		{
			cout << "[Warn]: �߸��� ���ڸ� �Է��߽��ϴ�. " << endl;
			cout << " �����ǿ� �ִ� ���ڸ� �Է��ϼ���." << endl;
			system("pause");
		}
	// end of while
	}
	
	system("pause");
	return 0;
}

void show_board(int (*my_board)[5])
{
	// �������� ����ϴ� �Լ�
	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k < 5; k++)
		{
			// 42�� *�� ����Ѵ�.
			if (my_board[i][k] == (int)'*')
			{
				cout << setw(3) << '*' << " ";
			}
			else
			{
				cout << setw(3) << my_board[i][k] << " ";
			}
		}
		cout << endl;
	// end of for
	}
}
