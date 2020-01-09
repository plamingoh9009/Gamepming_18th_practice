#include "stdafx.h"
#include "mainGame.h"

HRESULT mainGame::init()
{
	gameNode::init();

	// 여기서 맵을 메모리에 올린다.
	_map = new Map;
	_map->init();

	// 여기서 자동차를 메모리에 올린다.
	_player = new Car;
	_player->init();

	// 받아올 플레이어의 속도를 초기화한다.
	_speed_player = 0;
	_maxSpeed = static_cast<int> (_player->get_SPEED_FOR_CALC() * 
		_player->get_MAX_SPEED() );

	// 맵이 움직일 속도를 초기화한다.
	_mapMove = 0;

	// 여기서 다른 자동차를 메모리에 올린다.
	_other = new OtherCar;
	_other->init();
	return S_OK;
}

void mainGame::release()
{
	gameNode::release();

	// 메모리 해제한다.
	SAFE_DELETE(_map);
	SAFE_DELETE(_player);
	SAFE_DELETE(_other);
}

void mainGame::update()
{
	gameNode::update();

	// 자동차의 상태를 업데이트한다.
	_player->update();

	// 다른 자동차의 상태를 업데이트 한다.
	_speed_player = _player->get_speed();
	_other->update(_speed_player, _maxSpeed);

	// 업데이트 된 두 자동차가 충돌하는지 체크한다.
	check_crush();

	// 맵을 움직이게 하는 변수 speed_mapMove = 0;
	// 자동차의 속도를 가져와서 speed_mapMove를 계산한다.
	set_mapMove();
}

void mainGame::render(HDC hdc)
{
	//백버퍼에 뿌리자.
	HDC memDC = this->getBackBuffer()->getMemDC();
	//흰색 비트맵
	PatBlt(memDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//===================================================

	_map->render(memDC, _mapMove);
	_player->render(memDC);

	// 다른 자동차는 여기서 렌더한다.
	_other->render(memDC);

	// 렌더 테스트 코드
	//renderTest(memDC);
	//===================================================
	//백버퍼의 내용을 HDC에 그린다.(건드리지말것.)
	this->getBackBuffer()->render(hdc, 0, 0);
}

void mainGame::check_crush()
{
	// 두 자동차의 좌표를 RECT 형태로 가져와서 비교한다.
	RECT player, target, temp;
	POINT pt;
	int magenta_band;
	int width, height;

	// 플레이어의 좌표를 얻어온다.
	pt = _player->get_posPlayer();

	magenta_band = _player->get_MAGENTA_BAND();
	width = _player->get_CAR_W();
	height = _player->get_CAR_H();

	player.left = pt.x + magenta_band;
	player.top = pt.y;
	player.right = pt.x + width - magenta_band;
	player.bottom = pt.y + height;

	// target의 좌표를 얻어온다.
	pt = _other->get_posCar();
	
	target.left = pt.x + magenta_band;
	target.top = pt.y;
	target.right = pt.x + width - magenta_band;
	target.bottom = pt.y + height;

	// 여기서 충돌 체크 후 게임을 종료하는 코드
	if (IntersectRect(&temp, &player, &target))
	{
		// esc 이벤트 발생
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

	// MAP의 길이만큼 지나갔다면 숫자를 초기화 해준다.
	if ((_mapMove * -1) >= WINSIZEY)
	{
		_mapMove += WINSIZEY;
	}

}

void mainGame::renderTest(HDC hdc)
{
	char strTest[128];

	wsprintf(strTest, "맵 움직이는 방향, 거리: %d", _mapMove);
	TextOut(hdc, 20, 20, strTest, strlen(strTest));
}

mainGame::mainGame()
{
}
mainGame::~mainGame()
{
}