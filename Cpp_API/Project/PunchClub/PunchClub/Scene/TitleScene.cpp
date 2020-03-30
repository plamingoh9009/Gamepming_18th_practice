#include "stdafx.h"
#include "TitleScene.h"

void TitleScene::control_light_onButtons()
{
	int enabledCounter = 0;
	if (PtInRect(&_play_rc, m_ptMouse))
	{
		_play->set_frameX(1);
		_buttonType = BUTTON_PLAY;
		enabledCounter++;
	}
	else { _play->set_frameX(0); }
	if (PtInRect(&_exit_rc, m_ptMouse))
	{
		_exit->set_frameX(1);
		_buttonType = BUTTON_EXIT;
		enabledCounter++;
	}
	else { _exit->set_frameX(0); }
	// 아무 버튼도 활성화 되지 않은 경우
	if (enabledCounter < 1)
	{
		_buttonType = BUTTON_DISABLED;
	}
}
void TitleScene::run_buttons()
{
	if (_buttonType == BUTTON_PLAY) { _fPlayGame = true; }
	else if (_buttonType == BUTTON_EXIT) { PostQuitMessage(0); }
}
//==========================================
//##			이미지 초기화				  ##
//==========================================
void TitleScene::init_background()
{
	double bg_multiple = 1.7042;
	_bg = new Image;
	string path = _imgPath + "Sky_map.bmp";
	_bg->init(path.c_str(), (int)(256 * GAME_MULTIPLE * bg_multiple),
		(int)(255 * GAME_MULTIPLE * bg_multiple));
}
void TitleScene::draw_background()
{
	_bg->render(get_memDC());
	_bg->render(get_memDC(), (int)(WINSIZEX * 0.5), 0);
}

void TitleScene::init_logos()
{
	string path;
	_logo[0] = new Image;
	path = _imgPath + "Logo.bmp";
	_logo[0]->init(path.c_str(), 191, 167);
	_logo[1] = new Image;
	path = _imgPath + "Logo_darkFist.bmp";
	_logo[1]->init(path.c_str(), 254, 152);
	// 위치를 잡는 중
	POINT center;
	// 첫 좌표는 윈도우를 기준으로 잡는다.
	center.x = (LONG)(WIN_HALF_W);
	center.y = (LONG)(WINSIZEY * 0.22);
	_logo_center[0] = center;
	_logo_rc[0] = RectMakeCenter(center.x, center.y,
		_logo[0]->get_width(), _logo[0]->get_height());
	// 두번째 좌표는 펀치클럽 로고를 기준으로 잡는다.
	center.x = center.x - 20;
	center.y = (LONG)(center.y + (_logo[0]->get_height() * 0.45));
	_logo_center[1] = center;
	_logo_rc[1] = RectMakeCenter(center.x, center.y,
		_logo[1]->get_width(), _logo[1]->get_height());
}
void TitleScene::draw_logos()
{
	_logo[0]->render(get_memDC(), _logo_rc[0].left, _logo_rc[0].top);
	_logo[1]->render(get_memDC(), _logo_rc[1].left, _logo_rc[1].top);
}
void TitleScene::delete_logos()
{
	_logo[0]->release();
	_logo[1]->release();
	_logo[0] = nullptr;
	_logo[1] = nullptr;
}

void TitleScene::init_texts()
{
	string path;
	_play = new Image;
	path = _imgPath + "Font_Play.bmp";
	_play->init(path.c_str(), 164, 40, 2, 1);
	_play->set_frameX(0);
	_play->set_frameY(0);
	_exit = new Image;
	path = _imgPath + "Font_Exit.bmp";
	_exit->init(path.c_str(), 100, 40, 2, 1);
	_exit->set_frameX(0);
	_exit->set_frameY(0);
	// 여기서 위치를 잡아준다.
	POINT center = _logo_center[0];
	center.y = (LONG)(center.y + _logo[0]->get_width() * 1.2);
	_play_rc = RectMakeCenter(center.x, center.y,
		_play->get_frameWidth(), _play->get_frameHeight());
	// 종료 버튼
	center.y = (LONG)(center.y + _play->get_frameHeight() * 1.5);
	_exit_rc = RectMakeCenter(center.x, center.y, 
		_exit->get_frameWidth(), _exit->get_frameHeight());
}
void TitleScene::draw_texts()
{
	_play->frameRender(get_memDC(), _play_rc.left, _play_rc.top, 
		_play->get_frameX(), _play->get_frameY());
	_exit->frameRender(get_memDC(), _exit_rc.left, _exit_rc.top, 
		_exit->get_frameX(), _exit->get_frameY());
}
void TitleScene::delete_texts()
{
	_play->release();
	_play = nullptr;
	_exit->release();
	_exit = nullptr;
}

HRESULT TitleScene::init()
{
	add_currentScene_toList(SCENE_TITLE);
	set_imgPath("Title/");
	init_background();
	// 로고 이미지
	init_logos();
	init_texts();
	return S_OK;
}
void TitleScene::release()
{
	_bg->release();
	_bg = nullptr;
	delete_logos();
	delete_texts();
}
void TitleScene::update()
{
	control_light_onButtons();
	if (KEYMANAGER->is_onceKeyDown(VK_LBUTTON)) { run_buttons(); }
	// 여기서 씬 체인지
	if (_fPlayGame == true)
	{
		SCENEMANAGER->changeScene("Home");
	}
//==========================================
//##			디버그 모드				  ##
//==========================================
	update_checkDebugMode();
}
void TitleScene::render()
{
	// 배경 이미지 렌더
	draw_background();
	// 로고 이미지 렌더
	draw_logos();
	draw_texts();
}
TitleScene::TitleScene()
{
}
TitleScene::~TitleScene()
{
}
