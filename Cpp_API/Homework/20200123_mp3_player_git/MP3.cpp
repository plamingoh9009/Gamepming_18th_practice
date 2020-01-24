#include "stdafx.h"
#include "MP3.h"
//============================================
//##			뮤직 컨트롤					##
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
//##			디버그 모드					##
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
//##			뮤직오픈 컨트롤				##
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
//##			백 이미지 초기화				##
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
	// 디버그 모드인지 아닌지 넘긴다.
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
		}//if: 노래를 추가하면
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
//##		뮤직컨트롤로 값 넘김				##
//============================================
	if (_open->get_songs().empty() == false)
	{
		// 컨트롤에서 재생하기 위한 정보를 넘긴다.
		_control->set_currentSong(_open->get_currentSong());
		_control->set_vSongs(_open->get_songs());
		_control->set_vSongsIter(_open->get_songsIter());
	}
//============================================
//##		뮤직오픈으로 값 넘김				##
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
