#include "stdafx.h"
#include "MusicControl.h"
//============================================
//##				노래 이동					##
//============================================
void MusicControl::prev_song()
{
	pause_currentSong();
	_currentSong--;
	if (_currentSong < 1)
	{
		_currentSong = _vSongs.size();
	}
	_fChangeSong = true;
	play_currentSong();
}
void MusicControl::next_song()
{
	pause_currentSong();
	_currentSong++;
	if (_vSongs.size() < _currentSong)
	{
		_currentSong = 1;
	}
	_fChangeSong = true;
	play_currentSong();
}
//============================================
//##		현재 노래 재생	, 정지				##
//============================================
void MusicControl::play_currentSong()
{
	SOUNDMANAGER->play(_vSongs[_currentSong - 1], _volume);
}
void MusicControl::pause_currentSong()
{
	SOUNDMANAGER->pause(_vSongs[_currentSong - 1]);
}
MusicControl::MusicControl()
{
}
MusicControl::~MusicControl()
{
}
HRESULT MusicControl::init()
{
	_fDebug = false;
	_volume = 1;
	_fChangeSong = false;
	return S_OK;
}
void MusicControl::release()
{
}
void MusicControl::update()
{
	if (_fClickPlay == true)
	{
		play_currentSong();
		_fClickPlay = false;
	}
	else if (_fClickPrev == true)
	{
		prev_song();
		_fClickPrev = false;
	}
	else if (_fClickNext == true)
	{
		next_song();
		_fClickNext = false;
	}
}
void MusicControl::render()
{
}
