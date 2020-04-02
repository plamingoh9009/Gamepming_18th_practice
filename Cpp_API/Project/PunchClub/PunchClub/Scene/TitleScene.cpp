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
	// �ƹ� ��ư�� Ȱ��ȭ ���� ���� ���
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
void TitleScene::update_loopsRenders()
{
	if (_cloud_up_x > 1366)
	{
		_cloud_up_x -= 1366;
	}
	else
	{
		_cloud_up_x++;
	}
	if (_cloud_under_x > 1366)
	{
		_cloud_under_x -= 1366;
	}
	else
	{
		_cloud_under_x++;
	}
}
//==========================================
//##			�̹��� �ʱ�ȭ				  ##
//==========================================
void TitleScene::init_background()
{
	POINT center;
	string path;
	_sky_black = new Image;
	path = _imgPath + "sky_black.bmp";
	_sky_black->init(path.c_str(), (int)(682 * GAME_MULTIPLE), (int)(210 * GAME_MULTIPLE));
	_sky_color = new Image;
	path = _imgPath + "sky_color.bmp";
	_sky_color->init(path.c_str(), (int)(682 * GAME_MULTIPLE), (int)(108 * GAME_MULTIPLE));
	center.x = (int)(WIN_HALF_W);
	center.y = (int)(WIN_HALF_H - 65);
	_sky_color->set_center(center);
	// Cloud
	_cloud_up = new Image;
	path = _imgPath + "sky_up.bmp";
	_cloud_up->init(path.c_str(), (int)(682 * GAME_MULTIPLE), (int)(58 * GAME_MULTIPLE));
	center.x = (int)(WIN_HALF_W);
	center.y = (int)(WIN_HALF_H - 200);
	_cloud_up->set_center(center);
	_cloud_under = new Image;
	path = _imgPath + "sky_under.bmp";
	_cloud_under->init(path.c_str(), (int)(682 * GAME_MULTIPLE), (int)(69 * GAME_MULTIPLE));
	center.x = (int)(WIN_HALF_W);
	center.y = (int)(WIN_HALF_H - 170);
	_cloud_under->set_center(center);

	_cloud_up_x = RAND->get_int(1366);
	_cloud_under_x = RAND->get_int(1366);
}
void TitleScene::draw_background()
{
	_sky_black->render(get_memDC());
	_sky_color->loopRender(get_memDC(), &_sky_color->get_rect(), _cloud_up_x, 0);
	// cloud
	_cloud_up->loopRender(get_memDC(), &_cloud_up->get_rect(), _cloud_up_x, 0);
	_cloud_under->loopRender(get_memDC(), &_cloud_under->get_rect(), _cloud_under_x, 0);
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
	// ��ġ�� ��� ��
	POINT center;
	// ù ��ǥ�� �����츦 �������� ��´�.
	center.x = (LONG)(WIN_HALF_W);
	center.y = (LONG)(WINSIZEY * 0.22);
	_logo_center[0] = center;
	_logo_rc[0] = RectMakeCenter(center.x, center.y,
		_logo[0]->get_width(), _logo[0]->get_height());
	// �ι�° ��ǥ�� ��ġŬ�� �ΰ� �������� ��´�.
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
	// ���⼭ ��ġ�� ����ش�.
	POINT center = _logo_center[0];
	center.y = (LONG)(center.y + _logo[0]->get_width() * 1.2);
	_play_rc = RectMakeCenter(center.x, center.y,
		_play->get_frameWidth(), _play->get_frameHeight());
	// ���� ��ư
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
	// �ΰ� �̹���
	init_logos();
	init_texts();
	return S_OK;
}
void TitleScene::release()
{
	Release(_sky_black);
	Release(_sky_color);
	delete_logos();
	delete_texts();
}
void TitleScene::update()
{
	control_light_onButtons();
	update_loopsRenders();
	if (KEYMANAGER->is_onceKeyDown(VK_LBUTTON)) { run_buttons(); }
	// ���⼭ �� ü����
	if (_fPlayGame == true)
	{
		SCENEMANAGER->changeScene("Home");
	}
	//==========================================
	//##			����� ���				  ##
	//==========================================
	update_checkDebugMode();
}
void TitleScene::render()
{
	// ��� �̹��� ����
	draw_background();
	// �ΰ� �̹��� ����
	draw_logos();
	draw_texts();
}
TitleScene::TitleScene()
{
}
TitleScene::~TitleScene()
{
}
