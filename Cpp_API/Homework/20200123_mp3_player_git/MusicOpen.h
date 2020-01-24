#pragma once
#include "gameNode.h"
class MusicOpen: public gameNode
{
private:
	typedef vector<string> vStrings;
private:
	// �޴�â�� ����������� ���Ѵ�.
	bool _fClickMenu;
	// �뷡��� ����
	vStrings _songs;
	vStrings::iterator _songsIter;
	int _currentSong;
	RECT _songNameRect;
	// ����� ���
	bool _fDebug;
protected:
	// �뷡��� ���Ϳ� �߰��Ѵ�.
	void show_currentSong();
	void show_songNameRect();
	void delete_songsAll();
	// �޴�â�� �ʱ�ȭ�Ѵ�.
	void init_menu();
public:
	// �뷡��� ����, ���� �뷡�̸��� �ѱ��.
	int get_currentSong() { return _currentSong; }
	vector<string> get_songs() { return _songs; }
	vector<string>::iterator get_songsIter() { return _songsIter; }
	// ����� ��带 �޴´�.
	void set_fDebug(bool fResult) { _fDebug = fResult; }
	void set_fClickMenu(bool fResult) { _fClickMenu = fResult; }
	// �ٲ� �뷡 �ε����� �޴´�.
	void set_currentSong(int idx) { _currentSong = idx; }
public:
	MusicOpen();
	~MusicOpen();
	HRESULT init();
	void release();
	void update();
	void render();
};

