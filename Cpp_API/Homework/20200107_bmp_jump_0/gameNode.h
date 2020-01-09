#pragma once
#include"image.h"
class gameNode
{
	/*
		������۸� :  ��������� ȭ���� ������
		���� hdc�� �Ѹ��� �����.
		�����̳� ��Ʈ���� Ŀ���� ���ϰ� Ŀ����.
		��, �̸��� ���ڰŸ��� ������ �߻��ȴ�.
		�޸� ������ ���(ȭ�鿡 ������ �ʴ� ���)�� �� �����ٴ� ���� �̿��Ͽ�
		�޸𸮿� ��� ����� ������ �Ѹ������� hdc�� �ű�� ����� ��������̴�.
	
	*/

private:

	image * _backBuffer;		//�����
	void setBackBuffer();		//����� ����

public:
	gameNode();
	~gameNode();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
	//����� ��������
	image* getBackBuffer() { return _backBuffer; }

	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

};

