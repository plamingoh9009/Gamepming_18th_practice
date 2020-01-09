#include "stdafx.h"
#include "mainGame.h"

HRESULT mainGame::init()
{
	gameNode::init();

	// ���⼭ ���� �޸𸮿� �ø���.
	_map = new Map;
	_map->init();

	// ���⼭ �ڵ����� �޸𸮿� �ø���.
	_player = new Car;
	_player->init();

	// �޾ƿ� �÷��̾��� �ӵ��� �ʱ�ȭ�Ѵ�.
	_speed_player = 0;
	_maxSpeed = static_cast<int> (_player->get_SPEED_FOR_CALC() * 
		_player->get_MAX_SPEED() );

	// ���� ������ �ӵ��� �ʱ�ȭ�Ѵ�.
	_mapMove = 0;

	// ���⼭ �ٸ� �ڵ����� �޸𸮿� �ø���.
	_other = new OtherCar;
	_other->init();
	return S_OK;
}

void mainGame::release()
{
	gameNode::release();

	// �޸� �����Ѵ�.
	SAFE_DELETE(_map);
	SAFE_DELETE(_player);
	SAFE_DELETE(_other);
}

void mainGame::update()
{
	gameNode::update();

	// �ڵ����� ���¸� ������Ʈ�Ѵ�.
	_player->update();

	// �ٸ� �ڵ����� ���¸� ������Ʈ �Ѵ�.
	_speed_player = _player->get_speed();
	_other->update(_speed_player, _maxSpeed);

	// ������Ʈ �� �� �ڵ����� �浹�ϴ��� üũ�Ѵ�.
	check_crush();

	// ���� �����̰� �ϴ� ���� speed_mapMove = 0;
	// �ڵ����� �ӵ��� �����ͼ� speed_mapMove�� ����Ѵ�.
	set_mapMove();
}

void mainGame::render(HDC hdc)
{
	//����ۿ� �Ѹ���.
	HDC memDC = this->getBackBuffer()->getMemDC();
	//��� ��Ʈ��
	PatBlt(memDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//===================================================

	_map->render(memDC, _mapMove);
	_player->render(memDC);

	// �ٸ� �ڵ����� ���⼭ �����Ѵ�.
	_other->render(memDC);

	// ���� �׽�Ʈ �ڵ�
	//renderTest(memDC);
	//===================================================
	//������� ������ HDC�� �׸���.(�ǵ帮������.)
	this->getBackBuffer()->render(hdc, 0, 0);
}

void mainGame::check_crush()
{
	// �� �ڵ����� ��ǥ�� RECT ���·� �����ͼ� ���Ѵ�.
	RECT player, target, temp;
	POINT pt;
	int magenta_band;
	int width, height;

	// �÷��̾��� ��ǥ�� ���´�.
	pt = _player->get_posPlayer();

	magenta_band = _player->get_MAGENTA_BAND();
	width = _player->get_CAR_W();
	height = _player->get_CAR_H();

	player.left = pt.x + magenta_band;
	player.top = pt.y;
	player.right = pt.x + width - magenta_band;
	player.bottom = pt.y + height;

	// target�� ��ǥ�� ���´�.
	pt = _other->get_posCar();
	
	target.left = pt.x + magenta_band;
	target.top = pt.y;
	target.right = pt.x + width - magenta_band;
	target.bottom = pt.y + height;

	// ���⼭ �浹 üũ �� ������ �����ϴ� �ڵ�
	if (IntersectRect(&temp, &player, &target))
	{
		// esc �̺�Ʈ �߻�
		//keybd_event(VK_ESCAPE, 0, 0, 0);
	}
}

void mainGame::set_mapMove()
{
	int carSpeed = _player->get_speed();
	int forCalc = static_cast<int> (_player->get_SPEED_FOR_CALC() * 0.2);

	//_mapMove -= carSpeed;
	//_speed_mapMove = forCalc;
	_mapMove -= static_cast<int> (carSpeed / forCalc);

	// MAP�� ���̸�ŭ �������ٸ� ���ڸ� �ʱ�ȭ ���ش�.
	if ((_mapMove * -1) >= WINSIZEY)
	{
		_mapMove += WINSIZEY;
	}

}

void mainGame::renderTest(HDC hdc)
{
	char strTest[128];

	wsprintf(strTest, "�� �����̴� ����, �Ÿ�: %d", _mapMove);
	TextOut(hdc, 20, 20, strTest, strlen(strTest));
}

mainGame::mainGame()
{
}
mainGame::~mainGame()
{
}