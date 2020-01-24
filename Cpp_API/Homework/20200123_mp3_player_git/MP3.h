#pragma once
#include "gameNode.h"
#include "MusicOpen.h"
#include "MusicControl.h"
class MP3: public gameNode
{
private:
	image * _backImg;
	// 음악을 컨트롤하는 클래스다.
	MusicControl * _control;
	RECT _playRect;
	RECT _nextRect;
	RECT _prevRect;
	// 음악을 가져와서 보여주는 클래스다.
	MusicOpen * _open;
	RECT _openRect;
	// 디버그 모드
	bool _fDebug;
	// 마우스 위치를 정의한다.
	RECT _mouseRect;
protected:
	// 뮤직 컨트롤을 초기화
	void init_control();
	void delete_control();
	// 마우스 위치
	void make_mouseRect();
	// 뮤직오픈을 초기화
	void init_open();
	void delete_open();
	// 디버그 모드
	void show_Rects();
	void show_mouseRect();
	// 이미지를 초기화
	void init_backImg();
	void delete_backImg();
public:
	MP3();
	~MP3();
	HRESULT init();
	void release();
	void update();
	void render();
};

