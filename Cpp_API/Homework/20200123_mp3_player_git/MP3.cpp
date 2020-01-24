#include "stdafx.h"
#include "MP3.h"
//============================================
//##			���� ��Ʈ��					##
//============================================
void MP3::init_control()
{
	_control = new MusicControl;
	_control->init();
	_playRect = RectMake(151, 519, 35, 35);
	_prevRect = RectMake(104, 526, 25, 20);
	_nextRect = RectMake(208, 526, 25, 20);
}
void MP3::delete_control()
{
	_control->release();
}
void MP3::make_mouseRect()
{
	_mouseRect = RectMakeCenter(m_ptMouse.x, m_ptMouse.y, 8, 8);
}
//============================================
//##			����� ���					##
//============================================
void MP3::show_Rects()
{
	FrameRect(getMemDC(), &_openRect,
		CreateSolidBrush(RGB(255, 255, 255)));
	FrameRect(getMemDC(), &_playRect,
		CreateSolidBrush(RGB(255, 255, 255)));
	FrameRect(getMemDC(), &_prevRect,
		CreateSolidBrush(RGB(255, 255, 255)));
	FrameRect(getMemDC(), &_nextRect,
		CreateSolidBrush(RGB(255, 255, 255)));
}
void MP3::show_mouseRect()
{
	FrameRect(getMemDC(), &_mouseRect,
		CreateSolidBrush(RGB(255, 255, 255)));
}
//============================================
//##			�������� ��Ʈ��				##
//============================================
void MP3::init_open()
{
	_open = new MusicOpen;
	_open->init();
	_openRect = RectMake(299, 27, 25, 25);
}
void MP3::delete_open()
{
	_open->release();
	_open = nullptr;
}
//============================================
//##			�� �̹��� �ʱ�ȭ				##
//============================================
void MP3::init_backImg()
{
	_backImg = IMAGEMANAGER->addImage("MP3_BackImg",
		"images/MP3_Background.bmp", 338, 600, false, COLOR_MAGENTA);
}
void MP3::delete_backImg()
{
	_backImg = nullptr;
	IMAGEMANAGER->deleteImage("MP3_BackImg");
}

MP3::MP3()
{
}
MP3::~MP3()
{
}
HRESULT MP3::init()
{
	init_backImg();
	init_open();
	init_control();
	return S_OK;
}
void MP3::release()
{
	delete_backImg();
	delete_open();
	delete_control();
}
void MP3::update()
{
	// ����� ������� �ƴ��� �ѱ��.
	_open->set_fDebug(_fDebug);
	_open->update();
	_control->set_fDebug(_fDebug);
	_control->update();

	if (KEYMANAGER->isToggleKey(0x31)) { _fDebug = true; }
	else { _fDebug = false; }

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if (IntersectRect(&RECT(), &_mouseRect, &_openRect))
		{
			_open->set_fClickMenu(true);
		}//if: �뷡�� �߰��ϸ�
		else if (IntersectRect(&RECT(), &_mouseRect, &_playRect))
		{
			_control->set_fClickPlay(true);
		}
		else if (IntersectRect(&RECT(), &_mouseRect, &_prevRect))
		{
			_control->set_fClickPrev(true);
		}
		else if (IntersectRect(&RECT(), &_mouseRect, &_nextRect))
		{
			_control->set_fClickNext(true);
		}
	}
//============================================
//##		������Ʈ�ѷ� �� �ѱ�				##
//============================================
	if (_open->get_songs().empty() == false)
	{
		// ��Ʈ�ѿ��� ����ϱ� ���� ������ �ѱ��.
		_control->set_currentSong(_open->get_currentSong());
		_control->set_vSongs(_open->get_songs());
		_control->set_vSongsIter(_open->get_songsIter());
	}
//============================================
//##		������������ �� �ѱ�				##
//============================================
	if (_control->get_fChangeSong() == true)
	{
		_open->set_currentSong(_control->get_currentSong());
		_control->set_fChangeSong(false);
	}
	make_mouseRect();
}
void MP3::render()
{
	_backImg->render(getMemDC(), 0, 0);
	_open->render();
	_control->render();
	if (_fDebug == true)
	{
		show_Rects();
		show_mouseRect();
	}
}
