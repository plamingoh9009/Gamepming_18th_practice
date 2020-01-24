#pragma once
#include "gameNode.h"
class MusicOpen: public gameNode
{
private:
	typedef vector<string> vStrings;
private:
	// 메뉴창을 출력할지말지 정한다.
	bool _fClickMenu;
	// 노래목록 벡터
	vStrings _songs;
	vStrings::iterator _songsIter;
	int _currentSong;
	RECT _songNameRect;
	// 디버그 모드
	bool _fDebug;
protected:
	// 노래목록 벡터에 추가한다.
	void show_currentSong();
	void show_songNameRect();
	void delete_songsAll();
	// 메뉴창을 초기화한다.
	void init_menu();
public:
	// 노래목록 벡터, 현재 노래이름을 넘긴다.
	int get_currentSong() { return _currentSong; }
	vector<string> get_songs() { return _songs; }
	vector<string>::iterator get_songsIter() { return _songsIter; }
	// 디버그 모드를 받는다.
	void set_fDebug(bool fResult) { _fDebug = fResult; }
	void set_fClickMenu(bool fResult) { _fClickMenu = fResult; }
	// 바뀐 노래 인덱스를 받는다.
	void set_currentSong(int idx) { _currentSong = idx; }
public:
	MusicOpen();
	~MusicOpen();
	HRESULT init();
	void release();
	void update();
	void render();
};

