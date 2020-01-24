#include "stdafx.h"
#include "MusicOpen.h"
//============================================
//##			노래제목 출력					##
//============================================
void MusicOpen::show_currentSong()
{
	if (_songs.empty() == false)
	{
		SetBkMode(getMemDC(), 1);
		TextOut(getMemDC(), _songNameRect.left, _songNameRect.top,
			_songs[_currentSong-1].c_str(), _songs[_currentSong-1].size());
	}//if: 노래가 존재한다면
}
void MusicOpen::show_songNameRect()
{
	FrameRect(getMemDC(), &_songNameRect,
		CreateSolidBrush(RGB(255, 255, 255)));
}
void MusicOpen::delete_songsAll()
{
	_songsIter = _songs.begin();
	for (;_songsIter != _songs.end();)
	{
		_songsIter = _songs.erase(_songsIter);
	}
	_songs.clear();
}
//============================================
//##			메뉴창 초기화				##
//============================================
void MusicOpen::init_menu()
{
	_currentSong = 0;
	// 노래 이름을 출력할 좌표를 지정
	_songNameRect = RectMake(18, 369, 300, 20);
}

MusicOpen::MusicOpen()
{
}
MusicOpen::~MusicOpen()
{
}
HRESULT MusicOpen::init()
{
	init_menu();
	return S_OK;
}
void MusicOpen::release()
{
}
void MusicOpen::update()
{
	if (_fClickMenu == true)
	{
		OPENFILENAME ofn;
		char filePathSize[1024] = "";
		ZeroMemory(&ofn, sizeof(OPENFILENAME));

		ofn.lStructSize = sizeof(OPENFILENAME);//구조체 사이즈 지정
		ofn.hwndOwner = NULL;//대화상자 소유자를 지정
		ofn.lpstrFile = filePathSize;//파일이름 에디트에 처음 나타낼 파일명을 지정. 충분한버퍼가 있어야 한다.
		ofn.nMaxFile = sizeof(filePathSize);
		ofn.nFilterIndex = true;//파일 형식 콤보박스에서 사용할 필터의 인덱스를 지정
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = NULL;
		ofn.lpstrInitialDir = NULL;
		ofn.lpstrFilter = ("음악파일");//이름(파일형식)

		//대화상자의 모양과 동작을 지정
		//OFN_PATHMUSTEXIST : 존재하는 경로와 파일만 입력
		//OFN_FILEMUSTEXIST :존재하는 파일만 입력
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

		if (GetOpenFileName(&ofn) == FALSE) return;

		char temp[1024];

		strncpy_s(temp, strlen(ofn.lpstrFile) + 1, ofn.lpstrFile, strlen(ofn.lpstrFile));
		char* context = NULL;
		char* token = strtok_s(temp, "\\", &context);

		while (strlen(context))
		{
			token = strtok_s(NULL, "\\", &context);
		}
		SOUNDMANAGER->addSound(token, ofn.lpstrFile, false, false);
		_songs.push_back(token);
		_currentSong++;
		_fClickMenu = false;
	}
}
void MusicOpen::render()
{
	show_currentSong();
	if (_fDebug == true)
	{
		show_songNameRect();
	}
}
