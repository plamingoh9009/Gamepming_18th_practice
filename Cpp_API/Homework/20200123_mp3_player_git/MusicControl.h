#pragma once
#include "gameNode.h"
class MusicControl: public gameNode
{
private:
	typedef vector<string> vStrings;
private:
	RECT _playRect;
	bool _fDebug;
	// 무슨 버튼을 눌렀는지
	bool _fClickPlay;
	bool _fClickPrev;
	bool _fClickNext;
	// 현재 재생할 노래
	vStrings _vSongs;
	vStrings::iterator _vSongsIter;
	int _currentSong;
	float _volume;
	// 재생할 노래가 바뀌었는지
	bool _fChangeSong;
protected:
	void prev_song();
	void next_song();
	void play_currentSong();
	void pause_currentSong();
public:
	// 노래가 바뀌면 정보를 넘겨준다
	int get_currentSong() { return _currentSong; }
	bool get_fChangeSong() { return _fChangeSong; }
	void set_fChangeSong(bool fResult) { _fChangeSong = fResult; }
	// 노래를 새로 열면 정보를 받아온다.
	void set_vSongs(vStrings vSongs) { _vSongs = vSongs; }
	void set_vSongsIter(vStrings::iterator vSongsIter) { _vSongsIter = vSongsIter; }
	void set_currentSong(int idx) { _currentSong = idx; }
	// 어느 버튼을 눌렀는지 받아온다.
	void set_fClickPlay(bool fResult) { _fClickPlay = fResult; }
	void set_fClickPrev(bool fResult) { _fClickPrev = fResult; }
	void set_fClickNext(bool fResult) { _fClickNext = fResult; }
	void set_fDebug(bool fResult) { _fDebug = fResult; }
public:
	MusicControl();
	~MusicControl();
	HRESULT init();
	void release();
	void update();
	void render();
};

