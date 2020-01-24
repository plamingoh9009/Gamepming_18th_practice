#pragma once
#include "gameNode.h"
#include "MusicOpen.h"
#include "MusicControl.h"
class MP3: public gameNode
{
private:
	image * _backImg;
	// ������ ��Ʈ���ϴ� Ŭ������.
	MusicControl * _control;
	RECT _playRect;
	RECT _nextRect;
	RECT _prevRect;
	// ������ �����ͼ� �����ִ� Ŭ������.
	MusicOpen * _open;
	RECT _openRect;
	// ����� ���
	bool _fDebug;
	// ���콺 ��ġ�� �����Ѵ�.
	RECT _mouseRect;
protected:
	// ���� ��Ʈ���� �ʱ�ȭ
	void init_control();
	void delete_control();
	// ���콺 ��ġ
	void make_mouseRect();
	// ���������� �ʱ�ȭ
	void init_open();
	void delete_open();
	// ����� ���
	void show_Rects();
	void show_mouseRect();
	// �̹����� �ʱ�ȭ
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

