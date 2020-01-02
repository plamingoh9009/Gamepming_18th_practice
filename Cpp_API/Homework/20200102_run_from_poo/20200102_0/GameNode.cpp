#include "stdafx.h"
#include "GameNode.h"


GameNode::GameNode()
{
}


GameNode::~GameNode()
{
}

HRESULT GameNode::init()
{
	// Ÿ�̸Ӷ� ������ �ֱ⸶�� �Լ��� �����Ѵ�.
	/* 
	1. ������ �ڵ�
	2. Ÿ�̸� ��ȣ
	3. Ÿ�̸� �ֱ� 1000 = 1��
	4. �ֱ⸶�� ������ �Լ� -> NULL�̸� WM_TIMER�� ����ȴ�.
	*/
	SetTimer(m_hWnd, 1, 10, NULL);
	// �Ŵ��� �ʱ�ȭ
	KEYMANAGER->init();

	return S_OK;
}

void GameNode::release()
{
	// Ÿ�̸� ����
	// ������ ���ϸ� ���Ḧ �ص� �޸� ���� �߻��Ѵ�.
	KillTimer(m_hWnd, 1);
	// �Ŵ��� ����
	KEYMANAGER->releaseSingleton();
}

void GameNode::update()
{
	// ������� ���� ������� �ʴ´�.
	InvalidateRect(m_hWnd, NULL, true);
}

void GameNode::render(HDC hdc)
{
}

LRESULT GameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	switch (iMessage)
	{
	case WM_TIMER:
		this->update();
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		this->render(hdc);
		EndPaint(hWnd, &ps);
		break;
	case WM_MOUSEMOVE:
		m_ptMouse.x = LOWORD(lParam);
		m_ptMouse.y = HIWORD(wParam);
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}//end of switch
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}
