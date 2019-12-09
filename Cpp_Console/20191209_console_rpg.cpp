#include <iostream>
#include <time.h>
#include <string>

using namespace std;

int main()
{
	// ���� �Լ��� �õ�� ���⼭ �ʱ�ȭ
	srand(time(NULL));

	// ���� �����
	int my_charactor = 0;
	int my_monster = 0;
	struct charactor_base
	{
		// ĳ������ ���̽� �����̴�.
		// ĳ���Ϳ� ���� ���̽��� Ư�� ���� ���Ѵ�.
		int hp = 30;
		int mp = 8;
		int attack = 3;
		// ���� ũ��Ƽ���� �ۼ�Ʈ�� �ǹ��Ѵ�.
		// 20% Ȯ���� �������� 1/4 ��ŭ�� �޴´�.
		int defence = 20;
		// attack�� 50% ���� ������ �������� �����Ѵ�.
		int critical = 50;
		string type = {};
	};
	bool game_over = false;

	// �ٸ��ֱ� ���ؼ� ���� ȭ�鿡�� ������ ���� ����Ѵ�. 
	cout << "     ******************************" << endl;
	cout << "     ***        Text RPG        ***" << endl;
	cout << "     ******************************" << endl;
	cout << endl << endl;

	// ĳ���� ����â�� �ٸ��ݴϴ�. 
	cout << "[Create] ĳ���͸� �����մϴ�." << endl;
	cout << "1. �� ���̳�" << endl;
	cout << "2. ������" << endl;
	cout << "3. ��� �ɸ���" << endl;
	cout << "4. �Ǵн�" << endl << endl;
	cout << "[1-4] ����: ";
	cin >> my_charactor;

	// ���� �� ĳ������ �������ͽ��� ���⼭ �����, ����ؼ� �����ش�.
	charactor_base player;
	switch (my_charactor)
	{
	case 1:
		// �� ���̳ʸ� ����� ���̴�.
		player.hp = player.hp * 8;
		player.mp = player.mp * 3;
		player.attack = player.attack * 9;
		player.type = "�� ���̳�";

		cout << "[Success] �� ���̳ʸ� �����߽��ϴ�." << endl << endl;
		cout << "HP: " << player.hp << endl;
		cout << "MP: " << player.mp << endl;
		cout << "Atk: " << player.attack << endl;
		cout << "----------" << endl;
		cout << "Def: " << player.defence << "%" << endl;
		cout << "Cri: " << player.critical << "%" << endl;
		break;

	case 2:
		// �������� ����� ���̴�.
		player.hp = player.hp * 10;
		player.mp = player.mp * 6;
		player.attack = player.attack * 8;
		player.type = "������";

		cout << "[Success] �������� �����߽��ϴ�." << endl << endl;
		cout << "HP: " << player.hp << endl;
		cout << "MP: " << player.mp << endl;
		cout << "Atk: " << player.attack << endl;
		cout << "----------" << endl;
		cout << "Def: " << player.defence << "%" << endl;
		cout << "Cri: " << player.critical << "%" << endl;
		break;

	case 3:
		// ��� �ɸ����� ����� ���̴�.
		player.hp = player.hp * 6;
		player.mp = player.mp * 4;
		player.attack = player.attack * 10;
		player.type = "��� �ɸ���";

		cout << "[Success] ��� �ɸ����� �����߽��ϴ�." << endl << endl;
		cout << "HP: " << player.hp << endl;
		cout << "MP: " << player.mp << endl;
		cout << "Atk: " << player.attack << endl;
		cout << "----------" << endl;
		cout << "Def: " << player.defence << "%" << endl;
		cout << "Cri: " << player.critical << "%" << endl;
		break;

	case 4:
		// �Ǵн��� ����� ���̴�.
		player.hp = player.hp * 12;
		player.mp = player.mp * 4;
		player.attack = player.attack * 9;
		player.type = "�Ǵн�";

		cout << "[Success] �Ǵн��� �����߽��ϴ�." << endl << endl;
		cout << "HP: " << player.hp << endl;
		cout << "MP: " << player.mp << endl;
		cout << "Atk: " << player.attack << endl;
		cout << "----------" << endl;
		cout << "Def: " << player.defence << "%" << endl;
		cout << "Cri: " << player.critical << "%" << endl;
		break;

	default:
		cout << "[Error] �ùٸ��� ���� ��ȣ�Դϴ�." << endl;
		game_over = true;
		break;
	}
	system("pause");

	// ĳ���� ���ÿ��� ������ ���� ���⼭ ���α׷��� ������.
	if (game_over == true)
	{
		return 0;
	}

	// ĳ���͸� �����ߴٸ� ������ �����ϴ� �κ��� �ٸ��ش�.
	system("cls");
	cout << "     *** ���� ���̺꿡 �����߽��ϴ�. ***" << endl << endl;
	
	// �������� ���͸� 3�� ������.
	for (int i=0; i<3; i++)
	{
		// ������ ������ ������ ���͸� 1���� �����. 
		// ���ʹ� 3����. ���۸�, �����, ��Ż
		my_monster = rand() % 3 + 1;
		charactor_base monster;

		switch (my_monster)
		{
		case 1:
			// ���۸��� �����.
			monster.hp = monster.hp * 2;
			monster.mp = monster.mp * 1;
			monster.attack = monster.attack * 2;
			monster.type = "���۸�";

			cout << "[!!!] " << i+1 << "��° ���� ���۸��� �������ϴ�." 
				<< endl << endl;
			cout << "HP: " << monster.hp << endl;
			cout << "MP: " << monster.mp << endl;
			cout << "Atk: " << monster.attack << endl;
			cout << "----------" << endl;
			break;
			
		case 2:
			// ����� �����.
			monster.hp = monster.hp * 3;
			monster.mp = monster.mp * 2;
			monster.attack = monster.attack * 4;
			monster.type = "�����";

			cout << "[!!!] " << i + 1 << "��° ���� ����� �������ϴ�." 
				<< endl << endl;
			cout << "HP: " << monster.hp << endl;
			cout << "MP: " << monster.mp << endl;
			cout << "Atk: " << monster.attack << endl;
			cout << "----------" << endl;
			break;

		case 3:
			// ��Ż�� �����.
			monster.hp = monster.hp * 4;
			monster.mp = monster.mp * 2;
			monster.attack = monster.attack * 3;
			monster.type = "��Ż";

			cout << "[!!!] " << i + 1 << "��° ���� ��Ż�� �������ϴ�." 
				<< endl << endl;
			cout << "HP: " << monster.hp << endl;
			cout << "MP: " << monster.mp << endl;
			cout << "Atk: " << monster.attack << endl;
			cout << "----------" << endl;
			break;
		}
		system("pause");

		// ������� ���Ϳ� �ο�� �׼��� �����.
		// �÷��̾��� hp�� ������ hp�� 0�� �Ǹ� �׼��� ������.
		while (player.hp > 0 && monster.hp > 0)
		{
			// ���Ϳ��� �׼��� �����ֱ� ���ؼ� ȭ���� �� �� �����.
			system("cls");

			// ������ ������ ���⼭ �����ش�.
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

			// �ο��� �������� �����Ѵ�.
			int my_action = 0;
			int critical_damage = 0;

			cout << endl;
			cout << "[Action] �׼��� �����ϼ��� " << endl;
			cout << "1. �Ϲݰ��� \t 2. ��ų����" << endl;
			cout << "0. ��������" << endl;
			cout << "[0-2] ����: ";
			cin >> my_action;

			// ��������� ����ٰ� ���� �����Ѵ�.
			if (my_action == 0)
			{
				system("cls");
				cout << "�����ƽ��ϴ�.. " << endl;
				break;
			}

			switch (my_action)
			{
			case 1:
				// �Ϲݰ����� �������� ��
				
				// ���� ���� ������, ���Ͱ� �� �� ������.
				// ������ ��� Ȯ�� ���� ���.
				cout << player.type << "�� ���� !!!" << endl;
				if ((rand() % 101) < monster.defence)
				{
					// ���Ͱ� ��� ���� ���
					cout << " " << monster.type << "�� ��� !!!" << endl;
					monster.hp = monster.hp - (int)(player.attack / (double)4);
					cout << "HP�� " << (int)(player.attack / (double)4)
						<< " ��ŭ �޾Ҵ�." << endl;
				}
				else
				{
					monster.hp = monster.hp - player.attack;
					cout << "HP�� " << player.attack << " ��ŭ �޾Ҵ�."
						<< endl;
				}
				// ���⼭ ���Ͱ� �׾����� üũ
				if (monster.hp <= 0)
				{
					cout << endl;
					cout << monster.type << "��(��) �׾���." << endl << endl;
					cout << "     *** " << player.type << "�� �¸� !!!  *** " << endl;
					cout << endl;
				}
				// ���Ͱ� ���� �ʾƾ� ���� ���� �� �ִ�.
				else
				{
					// ���� ���Ͱ� ���� ������.
					cout << monster.type << "�� ���� !!!" << endl;
					if ((rand() % 101) < player.defence)
					{
						// �÷��̾ ��� ���� ���
						cout << " " << player.type << "�� ��� !!!" << endl;
						player.hp = player.hp - (int)(monster.attack / (double)4);
						cout << "HP�� " << (int)(monster.attack / (double)4)
							<< " ��ŭ �޾Ҵ�." << endl;
					}
					else
					{
						// �÷��̾ ������� ������ ���
						player.hp = player.hp - monster.attack;
						cout << "HP�� " << monster.attack << " ��ŭ �޾Ҵ�."
							<< endl;
					}
				}

				// ���⼭ �÷��̾ �׾����� üũ
				if (player.hp <= 0)
				{
					cout << endl;
					cout << player.type << "��(��) �׾���." << endl << endl;
					cout << monster.type << "�� �¸� ��-�� " << endl;
					cout << endl;
				}
				system("pause");
				break;

			case 2:
				// ��ų������ �������� ��

				// ���⼭ ������ �ִ��� üũ�Ѵ�.
				if (player.mp < 10)
				{
					// ������ 10���� ������ ��ų�� �� �� ����.
					cout << "��ų�� ������ ���� 10�� �ʿ��մϴ�." << endl;
					system("pause");
					continue;
				}
				
				// ���� ���� ������, ���Ͱ� �� �� ������.
				// ������ �ִٸ� ��ų������ �� �� �ִ�.
				// ��ų������ �� �����Ѵ�.
				cout << player.type << "�� ��ų���� !!!" << endl;
				// ��ų���� ������ attack * critical(%)�� ���� ������
				// ���� ������ 
				critical_damage = (int)( player.attack * (player.critical / (double)100) );
				// �ڿ� player.attack�� �ѹ� ���ϴ� ������ % �������� ������ ������ ����. 
				// ũ��Ƽ���ε� attack���� �������� ������ ���� �ȵ�.
				critical_damage = rand() % critical_damage + player.attack;

				// ���� ������ ���Ͱ� �׾����� üũ
				monster.hp = monster.hp - critical_damage;
				cout << monster.type << "�� HP�� " << critical_damage <<
					" ��ŭ ��Ҵ� !!! " << endl;

				// ������ �ǰ� ������� �� ������ �⵵�� �����.
				player.mp -= 10;

				// ���⼭ ���Ͱ� �׾����� üũ
				if (monster.hp <= 0)
				{
					cout << endl;
					cout << monster.type << "��(��) �׾���." << endl << endl;
					cout << "     *** " << player.type << "�� �¸� !!!  *** " << endl;
					cout << endl;
				}
				else
				{
					// ���� ���Ͱ� ���� ������.
					cout << monster.type << "�� ���� !!!" << endl;
					if ((rand() % 101) < player.defence)
					{
						// �÷��̾ ��� ���� ���
						cout << " " << player.type << "�� ��� !!!" << endl;
						player.hp = player.hp - (int)(monster.attack / (double)4);
						cout << "�÷��̾��� HP�� " << (int)(monster.attack / (double)4)
							<< " ��ŭ �޾Ҵ�." << endl;
					}
					else
					{
						// �÷��̾ ������� ������ ���
						player.hp = player.hp - monster.attack;
						cout << "HP�� " << monster.attack << " ��ŭ �޾Ҵ�."
							<< endl;
					}
				}

				// ���⼭ �÷��̾ �׾����� üũ
				if (player.hp <= 0)
				{
					cout << endl;
					cout << player.type << "��(��) �׾���." << endl << endl;
					cout << monster.type << "�� �¸� ��-�� " << endl;
					cout << endl;
				}
				system("pause");
				break;

			default:
				// �߸��� ��ȣ�� �޾��� ��
				cout << "�ƹ��ϵ� �Ͼ�� �ʾҽ��ϴ�. " <<
					"�ùٸ� ��ȣ�� �Է��ϼ���. " << endl;

				system("pause");
				continue;
			}
		}

	}

	cout << "Game Over " << endl;
	system("pause");
	return 0;
}