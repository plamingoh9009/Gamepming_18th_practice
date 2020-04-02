#pragma once
#include "Scene.h"
enum BUTTON_TYPE
{
	BUTTON_DISABLED,
	BUTTON_PLAY,
	BUTTON_EXIT
};
class TitleScene : public Scene
{
private:
	Image * _sky_black;
	Image * _sky_color;
	Image * _cloud_up;
	Image * _cloud_under;
	int _cloud_up_x = 0;
	int _cloud_under_x = 0;
	// 로고
	Image * _logo[2];
	RECT _logo_rc[2];
	POINT _logo_center[2];
	Image * _star;
	// 버튼
	Image * _play;
	RECT _play_rc;
	Image * _exit;
	RECT _exit_rc;
	BUTTON_TYPE _buttonType = BUTTON_DISABLED;
	// 씬 체인지
	bool _fPlayGame = false;
protected:
	void control_light_onButtons();
	void run_buttons();
	void update_loopsRenders();
protected:
	void init_background();
	void draw_background();
	void init_logos();
	void draw_logos();
	void delete_logos();
	void init_texts();
	void draw_texts();
	void delete_texts();
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	TitleScene();
	~TitleScene();
};

