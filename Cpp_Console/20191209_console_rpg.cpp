#include <iostream>
#include <time.h>
#include <string>

using namespace std;

int main()
{
	// 랜덤 함수의 시드는 여기서 초기화
	srand(time(NULL));

	// 변수 선언부
	int my_charactor = 0;
	int my_monster = 0;
	struct charactor_base
	{
		// 캐릭터의 베이스 스탯이다.
		// 캐릭터에 따라서 베이스에 특정 값을 곱한다.
		int hp = 30;
		int mp = 8;
		int attack = 3;
		// 방어와 크리티컬은 퍼센트를 의미한다.
		// 20% 확률로 데미지를 1/4 만큼만 받는다.
		int defence = 20;
		// attack의 50% 범위 내에서 데미지를 결정한다.
		int critical = 50;
		string type = {};
	};
	bool game_over = false;

	// 꾸며주기 위해서 메인 화면에서 제목을 먼저 출력한다. 
	cout << "     ******************************" << endl;
	cout << "     ***        Text RPG        ***" << endl;
	cout << "     ******************************" << endl;
	cout << endl << endl;

	// 캐릭터 선택창을 꾸며줍니다. 
	cout << "[Create] 캐릭터를 생성합니다." << endl;
	cout << "1. 짐 레이너" << endl;
	cout << "2. 제라툴" << endl;
	cout << "3. 사라 케리건" << endl;
	cout << "4. 피닉스" << endl << endl;
	cout << "[1-4] 선택: ";
	cin >> my_charactor;

	// 내가 고른 캐릭터의 스테이터스를 여기서 만들고, 출력해서 보여준다.
	charactor_base player;
	switch (my_charactor)
	{
	case 1:
		// 짐 레이너를 만드는 곳이다.
		player.hp = player.hp * 8;
		player.mp = player.mp * 3;
		player.attack = player.attack * 9;
		player.type = "짐 레이너";

		cout << "[Success] 짐 레이너를 생성했습니다." << endl << endl;
		cout << "HP: " << player.hp << endl;
		cout << "MP: " << player.mp << endl;
		cout << "Atk: " << player.attack << endl;
		cout << "----------" << endl;
		cout << "Def: " << player.defence << "%" << endl;
		cout << "Cri: " << player.critical << "%" << endl;
		break;

	case 2:
		// 제라툴을 만드는 곳이다.
		player.hp = player.hp * 10;
		player.mp = player.mp * 6;
		player.attack = player.attack * 8;
		player.type = "제라툴";

		cout << "[Success] 제라툴을 생성했습니다." << endl << endl;
		cout << "HP: " << player.hp << endl;
		cout << "MP: " << player.mp << endl;
		cout << "Atk: " << player.attack << endl;
		cout << "----------" << endl;
		cout << "Def: " << player.defence << "%" << endl;
		cout << "Cri: " << player.critical << "%" << endl;
		break;

	case 3:
		// 사라 케리건을 만드는 곳이다.
		player.hp = player.hp * 6;
		player.mp = player.mp * 4;
		player.attack = player.attack * 10;
		player.type = "사라 케리건";

		cout << "[Success] 사라 케리건을 생성했습니다." << endl << endl;
		cout << "HP: " << player.hp << endl;
		cout << "MP: " << player.mp << endl;
		cout << "Atk: " << player.attack << endl;
		cout << "----------" << endl;
		cout << "Def: " << player.defence << "%" << endl;
		cout << "Cri: " << player.critical << "%" << endl;
		break;

	case 4:
		// 피닉스를 만드는 곳이다.
		player.hp = player.hp * 12;
		player.mp = player.mp * 4;
		player.attack = player.attack * 9;
		player.type = "피닉스";

		cout << "[Success] 피닉스를 생성했습니다." << endl << endl;
		cout << "HP: " << player.hp << endl;
		cout << "MP: " << player.mp << endl;
		cout << "Atk: " << player.attack << endl;
		cout << "----------" << endl;
		cout << "Def: " << player.defence << "%" << endl;
		cout << "Cri: " << player.critical << "%" << endl;
		break;

	default:
		cout << "[Error] 올바르지 않은 번호입니다." << endl;
		game_over = true;
		break;
	}
	system("pause");

	// 캐릭터 선택에서 에러가 나면 여기서 프로그램을 끝낸다.
	if (game_over == true)
	{
		return 0;
	}

	// 캐릭터를 선택했다면 던전에 입장하는 부분을 꾸며준다.
	system("cls");
	cout << "     *** 저그 하이브에 입장했습니다. ***" << endl << endl;
	
	// 던전에서 몬스터를 3번 만난다.
	for (int i=0; i<3; i++)
	{
		// 던전에 입장을 했으니 몬스터를 1마리 만든다. 
		// 몬스터는 3종류. 저글링, 히드라, 뮤탈
		my_monster = rand() % 3 + 1;
		charactor_base monster;

		switch (my_monster)
		{
		case 1:
			// 저글링을 만든다.
			monster.hp = monster.hp * 2;
			monster.mp = monster.mp * 1;
			monster.attack = monster.attack * 2;
			monster.type = "저글링";

			cout << "[!!!] " << i+1 << "번째 몬스터 저글링을 만났습니다." 
				<< endl << endl;
			cout << "HP: " << monster.hp << endl;
			cout << "MP: " << monster.mp << endl;
			cout << "Atk: " << monster.attack << endl;
			cout << "----------" << endl;
			break;
			
		case 2:
			// 히드라를 만든다.
			monster.hp = monster.hp * 3;
			monster.mp = monster.mp * 2;
			monster.attack = monster.attack * 4;
			monster.type = "히드라";

			cout << "[!!!] " << i + 1 << "번째 몬스터 히드라를 만났습니다." 
				<< endl << endl;
			cout << "HP: " << monster.hp << endl;
			cout << "MP: " << monster.mp << endl;
			cout << "Atk: " << monster.attack << endl;
			cout << "----------" << endl;
			break;

		case 3:
			// 뮤탈을 만든다.
			monster.hp = monster.hp * 4;
			monster.mp = monster.mp * 2;
			monster.attack = monster.attack * 3;
			monster.type = "뮤탈";

			cout << "[!!!] " << i + 1 << "번째 몬스터 뮤탈을 만났습니다." 
				<< endl << endl;
			cout << "HP: " << monster.hp << endl;
			cout << "MP: " << monster.mp << endl;
			cout << "Atk: " << monster.attack << endl;
			cout << "----------" << endl;
			break;
		}
		system("pause");

		// 만들어진 몬스터와 싸우는 액션을 만든다.
		// 플레이어의 hp나 몬스터의 hp가 0이 되면 액션이 끝난다.
		while (player.hp > 0 && monster.hp > 0)
		{
			// 몬스터와의 액션을 보여주기 위해서 화면을 한 번 지운다.
			system("cls");

			// 몬스터의 스탯을 여기서 보여준다.
			cout << "     *** [" << monster.type << "] *** \t";
			cout << "     *** [" << player.type << "] ***"
				<< endl << endl;
			cout << "HP: " << monster.hp << "\t\t\t";
			cout << "HP: " << player.hp << endl;
			cout << "MP: " << monster.mp << "\t\t\t";
			cout << "MP: " << player.mp << endl;
			cout << "Atk: " << monster.attack << "\t\t\t";
			cout << "Atk: " << player.attack << endl;
			cout << "----------" << endl;

			// 싸울지 도망갈지 선택한다.
			int my_action = 0;
			int critical_damage = 0;

			cout << endl;
			cout << "[Action] 액션을 선택하세요 " << endl;
			cout << "1. 일반공격 \t 2. 스킬공격" << endl;
			cout << "0. 도망가기" << endl;
			cout << "[0-2] 선택: ";
			cin >> my_action;

			// 도망가기는 여기다가 따로 구현한다.
			if (my_action == 0)
			{
				system("cls");
				cout << "도망쳤습니다.. " << endl;
				break;
			}

			switch (my_action)
			{
			case 1:
				// 일반공격을 선택했을 때
				
				// 내가 먼저 때리고, 몬스터가 한 방 때린다.
				// 몬스터의 방어 확률 먼저 계산.
				cout << player.type << "의 공격 !!!" << endl;
				if ((rand() % 101) < monster.defence)
				{
					// 몬스터가 방어 했을 경우
					cout << " " << monster.type << "의 방어 !!!" << endl;
					monster.hp = monster.hp - (int)(player.attack / (double)4);
					cout << "HP가 " << (int)(player.attack / (double)4)
						<< " 만큼 달았다." << endl;
				}
				else
				{
					monster.hp = monster.hp - player.attack;
					cout << "HP가 " << player.attack << " 만큼 달았다."
						<< endl;
				}
				// 여기서 몬스터가 죽었는지 체크
				if (monster.hp <= 0)
				{
					cout << endl;
					cout << monster.type << "이(가) 죽었다." << endl << endl;
					cout << "     *** " << player.type << "의 승리 !!!  *** " << endl;
					cout << endl;
				}
				// 몬스터가 죽지 않아야 나를 때릴 수 있다.
				else
				{
					// 이제 몬스터가 나를 때린다.
					cout << monster.type << "의 공격 !!!" << endl;
					if ((rand() % 101) < player.defence)
					{
						// 플레이어가 방어 했을 경우
						cout << " " << player.type << "의 방어 !!!" << endl;
						player.hp = player.hp - (int)(monster.attack / (double)4);
						cout << "HP가 " << (int)(monster.attack / (double)4)
							<< " 만큼 달았다." << endl;
					}
					else
					{
						// 플레이어가 방어하지 못했을 경우
						player.hp = player.hp - monster.attack;
						cout << "HP가 " << monster.attack << " 만큼 달았다."
							<< endl;
					}
				}

				// 여기서 플레이어가 죽었는지 체크
				if (player.hp <= 0)
				{
					cout << endl;
					cout << player.type << "이(가) 죽었다." << endl << endl;
					cout << monster.type << "의 승리 ㅜ-ㅜ " << endl;
					cout << endl;
				}
				system("pause");
				break;

			case 2:
				// 스킬공격을 선택했을 때

				// 여기서 마나가 있는지 체크한다.
				if (player.mp < 10)
				{
					// 마나가 10보다 작으면 스킬을 쓸 수 없다.
					cout << "스킬을 쓰려면 마나 10이 필요합니다." << endl;
					system("pause");
					continue;
				}
				
				// 내가 먼저 때리고, 몬스터가 한 방 때린다.
				// 마나가 있다면 스킬공격을 할 수 있다.
				// 스킬공격은 방어를 무시한다.
				cout << player.type << "의 스킬공격 !!!" << endl;
				// 스킬공격 계산식은 attack * critical(%)의 범위 내에서
				// 랜덤 데미지 
				critical_damage = (int)( player.attack * (player.critical / (double)100) );
				// 뒤에 player.attack을 한번 더하는 이유는 % 연산으로 랜덤을 돌리기 때문. 
				// 크리티컬인데 attack보다 데미지가 작으면 말이 안됨.
				critical_damage = rand() % critical_damage + player.attack;

				// 먼저 때리고 몬스터가 죽었는지 체크
				monster.hp = monster.hp - critical_damage;
				cout << monster.type << "의 HP가 " << critical_damage <<
					" 만큼 닳았다 !!! " << endl;

				// 몬스터의 피가 닳았으면 내 마나도 닳도록 만든다.
				player.mp -= 10;

				// 여기서 몬스터가 죽었는지 체크
				if (monster.hp <= 0)
				{
					cout << endl;
					cout << monster.type << "이(가) 죽었다." << endl << endl;
					cout << "     *** " << player.type << "의 승리 !!!  *** " << endl;
					cout << endl;
				}
				else
				{
					// 이제 몬스터가 나를 때린다.
					cout << monster.type << "의 공격 !!!" << endl;
					if ((rand() % 101) < player.defence)
					{
						// 플레이어가 방어 했을 경우
						cout << " " << player.type << "의 방어 !!!" << endl;
						player.hp = player.hp - (int)(monster.attack / (double)4);
						cout << "플레이어의 HP가 " << (int)(monster.attack / (double)4)
							<< " 만큼 달았다." << endl;
					}
					else
					{
						// 플레이어가 방어하지 못했을 경우
						player.hp = player.hp - monster.attack;
						cout << "HP가 " << monster.attack << " 만큼 달았다."
							<< endl;
					}
				}

				// 여기서 플레이어가 죽었는지 체크
				if (player.hp <= 0)
				{
					cout << endl;
					cout << player.type << "이(가) 죽었다." << endl << endl;
					cout << monster.type << "의 승리 ㅜ-ㅜ " << endl;
					cout << endl;
				}
				system("pause");
				break;

			default:
				// 잘못된 번호를 받았을 때
				cout << "아무일도 일어나지 않았습니다. " <<
					"올바른 번호를 입력하세요. " << endl;

				system("pause");
				continue;
			}
		}

	}

	cout << "Game Over " << endl;
	system("pause");
	return 0;
}