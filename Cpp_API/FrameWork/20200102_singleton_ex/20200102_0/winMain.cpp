﻿#include "stdafx.h"
#include "MainGame.h"

HINSTANCE m_hInstance;
HWND m_hWnd;
POINT m_ptMouse = { 0, 0 };

MainGame mg;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

void setWindowSize(int x, int y, int width, int height);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdParam, int nCmdShow)
{
	/*
	윈도우 API는 크게 winMain, wndProc 두 개의 함수로 이루어져 있다.
	윈도우 프로시저는 윈도우에서 이루어지는 동작을 이야기한다. 즉 메세지를
	처리한다.
	 */

	m_hInstance = hInstance;

	// WNDCLASS: 윈도우 창의 정보를 저장하기 위한 구조체
	// 윈도우창 구조체 선언 후 초기화
	WNDCLASS wndClass;

	// 윈도우 클래스에서 사용화고자 하는 여분의 메모리양을 바이트 단위로 지정
	wndClass.cbClsExtra = 0;
	// cbClsExtra이랑 유사하나 개별 윈도우에서 사용하고자 하는 여분의 메모리양을 지정.
	wndClass.cbWndExtra = 0;
	// 윈도우 작업영역에 칠할 배경 브러시
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);

	// 커서 지정
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	// 타이틀바의 좌상단에 보여줄 아이콘과 윈도우가 최소화 되었을때 보여줄 아이콘을 지정.
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	// 윈도우 클래스를 등록한 응용프로그램의 인스턴스 핸들
	wndClass.hInstance = hInstance;
	// 메세지를 처리하는 함수를 지정(윈도우 프로시저)
	wndClass.lpfnWndProc = (WNDPROC)WndProc;
	// 등록하고자 하는 윈도우 클래스 이름
	wndClass.lpszClassName = WINNAME;
	// 클래스로부터 만들어진 윈도우가 사용할 메뉴를 지정
	wndClass.lpszMenuName = NULL;
	// 윈도우 클래스의 스타일을 지정
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	// 윈도우 클래스 등록
	// 등록할 윈도우 클래스의 특성을 지정하는 WNDCLASS 구조체를 전달한다.
	RegisterClass(&wndClass);

	m_hWnd = CreateWindow(
		WINNAME, WINNAME,		// 클래스 이름, 윈도우타이틀 이름
		WS_OVERLAPPEDWINDOW,	// 윈도우 스타일
		WINSTARTX, WINSTARTY,	// 윈도우 화면 x,y
		WINSIZEX, WINSIZEY,		// 윈도우 크기 x,y
		NULL, (HMENU)NULL,		// 부모 윈도우, 메뉴핸들
		hInstance, NULL			// 인스턴스 지정
	);

	setWindowSize(WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY);
	// 화면에 윈도우 보여주자
	ShowWindow(m_hWnd, nCmdShow);

	// 메인게임 초기화에 실패하면 종료
	if (FAILED(mg.init()))
	{
		return 0;
	}
	
	// MSG: 운영체제에서 발생하는 메세지 정보를 저장하기 위한 구조체
	MSG message;

	/* 
	// 게임용 루프(PeekMessage)
	while (true)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			if (message.message == WM_QUIT) break;

			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		else {}
	}
	*/

	// TranslateMessage: 키보드 입력메세지 처리 담당
	// DispatchMessage: 윈도우 프로시저에 전달된 메세지를 실제 윈도우에 전달
	// GetMessage: 대기상태
	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	//메시지 루프를 다돌면 해제한다.
	mg.release();

	return message.wParam;
}

enum DIRECTION
{
	DIRECTION_NULL,
	DIRECTION_LT,
	DIRECTION_RT,
	DIRECTION_LB,
	DIRECTION_RB
};

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	return mg.MainProc(hWnd, iMessage, wParam, lParam);
}

// ==============================================================
// ### 윈도우 크기조정(클라이언트 영역의 사이즈를 정확히 잡아준다.) ###
// ==============================================================
void setWindowSize(int x, int y, int width, int height)
{
	RECT rc;
	rc.left = 0;
	rc.top = 0;
	rc.right = width;
	rc.bottom = height;

	AdjustWindowRect(&rc, WINSTYLE, false);

	// 위 정보로 윈도우 사이즈를 셋팅하자.
	SetWindowPos(m_hWnd, NULL, x, y,
		(rc.right - rc.left), (rc.bottom - rc.top),
		SWP_NOZORDER);
}
