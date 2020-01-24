#include "stdafx.h"
#include "MusicOpen.h"
//============================================
//##			�뷡���� ���					##
//============================================
void MusicOpen::show_currentSong()
{
	if (_songs.empty() == false)
	{
		SetBkMode(getMemDC(), 1);
		TextOut(getMemDC(), _songNameRect.left, _songNameRect.top,
			_songs[_currentSong-1].c_str(), _songs[_currentSong-1].size());
	}//if: �뷡�� �����Ѵٸ�
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
//##			�޴�â �ʱ�ȭ				##
//============================================
void MusicOpen::init_menu()
{
	_currentSong = 0;
	// �뷡 �̸��� ����� ��ǥ�� ����
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

		ofn.lStructSize = sizeof(OPENFILENAME);//����ü ������ ����
		ofn.hwndOwner = NULL;//��ȭ���� �����ڸ� ����
		ofn.lpstrFile = filePathSize;//�����̸� ����Ʈ�� ó�� ��Ÿ�� ���ϸ��� ����. ����ѹ��۰� �־�� �Ѵ�.
		ofn.nMaxFile = sizeof(filePathSize);
		ofn.nFilterIndex = true;//���� ���� �޺��ڽ����� ����� ������ �ε����� ����
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = NULL;
		ofn.lpstrInitialDir = NULL;
		ofn.lpstrFilter = ("��������");//�̸�(��������)

		//��ȭ������ ���� ������ ����
		//OFN_PATHMUSTEXIST : �����ϴ� ��ο� ���ϸ� �Է�
		//OFN_FILEMUSTEXIST :�����ϴ� ���ϸ� �Է�
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
