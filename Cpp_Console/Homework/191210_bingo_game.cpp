#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// 빙고판을 출력해서 보여주는 함수
void show_board(int (*my_board)[5]);

int main()
{
	/*
	빙고게임 만들기
	 1) 5X5 빙고판에서 player, computer가 각각 진행하는 턴제 게임
	 2) 각 빙고판은 1~25의 숫자가 랜덤하게 생성됨.
	 3) 내 턴: 내가 숫자를 입력하면 마킹 한다는 의미로 특수문자 같은거 넣어줌.
	 4) 컴퓨터 턴: 컴이 숫자를 제시함. (랜덤)

	 * 특수조건: 4)에서 컴퓨터가 인공지능이 있어서 이기기 위한 한 수를 제시한다.
	 E) 3줄 빙고면 게임 Over. 승자를 가린다.
	*/

	// 랜덤 시드 초기화 하는 부분
	srand(time(NULL));
	// 변수 선언부
	int player_board[5][5] = { 0, };
	int computer_board[5][5] = { 0, };

	// 플레이어와 컴퓨터의 보드를 초기화 한다.
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

	// 플레이어와 컴퓨터의 보드를 섞는다.
	for (int i = 0; i < 30; i++)
	{
		// player board suffle을 위한 변수
		int p_dest[2] = { rand() % 5, rand() % 5 };
		int p_sour[2] = { rand() % 5, rand() % 5 };
		// coputer board sufffle을 위한 변수
		int c_dest[2] = { rand() % 5, rand() % 5 };
		int c_sour[2] = { rand() % 5, rand() % 5 };
		int temp;
		

		// player board suffle 하는 부분
		temp = player_board[p_dest[0]][p_dest[1]];
		player_board[p_dest[0]][p_dest[1]] =
			player_board[p_sour[0]][p_sour[1]];
		player_board[p_sour[0]][p_sour[1]] = temp;

		// computer board suffle 하는 부분
		temp = computer_board[c_dest[0]][c_dest[1]];
		computer_board[c_dest[0]][c_dest[1]] =
			computer_board[c_sour[0]][c_sour[1]];
		computer_board[c_sour[0]][c_sour[1]] = temp;
	}

	// game_over 가 true 되기 전까지 게임을 계속한다.
	bool game_over = false;
	while (game_over != true)
	{
		// 게임을 원활히 진행하기 위해서 빙고판을 우선 보여준다.
		cout << "*** 플레이어 빙고판 ***" << endl << endl;
		show_board(player_board);
		cout << endl;
		cout << "*** 컴퓨터 빙고판 ***" << endl << endl;
		show_board(computer_board);
		cout << endl;

		// 내 턴을 먼저 시작한다. 내가 숫자를 먼저 입력한다.
		int my_num;
		cout << "[My turn] 숫자를 입력하시오: ";
		cin >> my_num;

		// 내가 입력한 값을 우선은 내 빙고판에서 *로 바꾼다.
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
					// cnt가 25면 끝까지 찾아도 숫자를 못찾은 것. 
					// 숫자를 잘못 입력한 것이다.
					cnt++;
				}
			}
		}

		// 컴퓨터 차례때 활용하기 위해서 마지막으로 놓은 자리를 저장하는
		// 변수다.
		int computer_last_i = 0;
		int computer_last_k = 0;

		// 컴퓨터의 빙고판에서 같은 my_num 값을 *로 바꾼다.
		for (int i = 0; i < 5; i++)
		{
			for (int k = 0; k < 5; k++)
			{
				if (computer_board[i][k] == my_num)
				{
					computer_board[i][k] = (int)'*';
					// 컴퓨터의 마지막 자리 좌표를 저장한다.
					computer_last_i = i;
					computer_last_k = k;
				}
			}
		}

		
		// 내 차례 다음은 컴퓨터의 차례
		// 여기서 컴퓨터가 랜덤 자리에 *을 찍을 예정
		bool computer_turn_end = false;
		int computer_num = 0;
		while (computer_turn_end == false)
		{
			// 컴퓨터가 *을 찍을 자리를 rand() 로 만들어준다.
			int computer_turn_i = rand() % 5;
			int computer_turn_k = rand() % 5;

			// 탈출조건을 만든다. 빙고판에 *이 없으면 *을 찍고 탈출
			if (computer_board[computer_turn_i][computer_turn_k] != (int)'*')
			{
				// computer_num 에 원래 있던 값을 저장한다.
				computer_num = computer_board[computer_turn_i][computer_turn_k];
				// 그 다음에 *을 찍는다
				computer_board[computer_turn_i][computer_turn_k] = (int)'*';
				// 탈출하는 부분이다.
				computer_turn_end = true;
			}
			else
			{
				// 빙고판에 *이 있으면 탈출하지 않고 다시 좌표 서치
				continue;
			}
		// end of while 컴퓨터가 랜덤 자리에 *을 찍고 반복문 탈출
		}
		cout << "Computer가 찍은 값 :" << computer_num << endl;
		// 이제 컴퓨터가 찍은 값으로 내 빙고판에 *을 찍는다.
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

		// 빙고를 체크해서 3줄 빙고면 먼저 빙고인 쪽이 이긴다.
		int player_bingo_cnt = 0;
		// 대각선은 포문을 한바퀴 다 돌아야 찾을 수 있어서 for문 밖에 있다.
		int player_left_cross_cnt = 0;
		int player_right_cross_cnt = 0;

		int computer_bingo_cnt = 0;
		// 대각선은 포문을 한바퀴 다 돌아야 찾을 수 있어서 for문 밖에 있다.
		int computer_left_cross_cnt = 0;
		int computer_right_cross_cnt = 0;
		// Bingo check column
		for (int i = 0; i < 5; i++)
		{
			// 플레이어의 * 을 세는 변수
			int player_col_cnt = 0;
			int player_row_cnt = 0;
			
			// 컴퓨터의 * 을 세는 변수
			int computer_col_cnt = 0;
			int computer_row_cnt = 0;
			
			for (int k = 0; k < 5; k++)
			{
				// 플레이어 왼쪽 대각선 확인
				if (i == k)
				{
					// 플레이어 가로줄 확인
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
					// 플레이어 가로줄 확인
					if (player_board[i][k] == (int)'*')
					{
						player_col_cnt++;
					}
				}
				// 플레이어 오른쪽 대각선 확인
				if (k + i + 1 == 5)
				{
					// 플레이어 세로줄 확인
					if (player_board[k][i] == (int)'*')
					{
						player_row_cnt++;
						player_right_cross_cnt++;
					}
				}
				else
				{
					// 플레이어 세로줄 확인
					if (player_board[k][i] == (int)'*')
					{
						player_row_cnt++;
					}
				}

				// 컴퓨터 왼쪽 대각선 확인
				if (i == k)
				{
					// 컴퓨터 가로줄 확인
					if (computer_board[i][k] == (int)'*')
					{
						computer_col_cnt++;
						computer_left_cross_cnt++;
					}
				}
				else
				{
					// 컴퓨터 가로줄 확인
					if (computer_board[i][k] == (int)'*')
					{
						computer_col_cnt++;
					}
				}
				// 컴퓨터 오른쪽 대각선 확인
				if (k + i + 1 == 5)
				{
					// 컴퓨터 세로줄 확인
					if (computer_board[k][i] == (int)'*')
					{
						computer_row_cnt++;
						computer_right_cross_cnt++;
					}
				}
				else
				{
					// 컴퓨터 세로줄 확인
					if (computer_board[k][i] == (int)'*')
					{
						computer_row_cnt++;
					}
				}
			// 1줄 확인 끝
			}
			// 플레이어의 빙고판에서 만약 한 줄에 5개가 * 이라면 빙고를 1개 올린다.
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
			// 컴퓨터의 빙고판에서 만약 한 줄에 5개가 * 이라면 빙고를 1개 올린다.
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

		// 빙고가 제대로 나오나?
		cout << "Player_bingo: " << player_bingo_cnt << endl;
		cout << "Computer_bingo: " << computer_bingo_cnt << endl;

		// 테스트를 위해서 탈출문을 넣어둔다.
		if (my_num == -1)
		{
			cout << "게임을 강제로 종료합니다. " << endl;
			game_over = true;
		}

		// 3줄이 빙고면 게임은 끝난다.
		if (player_bingo_cnt >= 3)
		{
			cout << endl;
			cout << "[Win] Player 승리 !!!" << endl;
			cout << endl;
			game_over = true;
		}
		if (computer_bingo_cnt >= 3)
		{
			cout << endl;
			cout << "[Lose] Player 패배 ..." << endl;
			cout << endl;
			game_over = true;
		}


		// 여기서 잘못 입력했을 경우 경고해준다.
		// 게임 오버인 경우에는 경고를 출력할 필요가 없다.
		if (cnt == 25 && game_over != true)
		{
			cout << "[Warn]: 잘못된 숫자를 입력했습니다. " << endl;
			cout << " 빙고판에 있는 숫자를 입력하세요." << endl;
			system("pause");
		}
	// end of while
	}
	
	system("pause");
	return 0;
}

void show_board(int (*my_board)[5])
{
	// 빙고판을 출력하는 함수
	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k < 5; k++)
		{
			// 42면 *로 출력한다.
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
