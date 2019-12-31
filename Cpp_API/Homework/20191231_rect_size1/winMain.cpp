#include "stdafx.h"
#include "myFunc.h"

//인스턴스: 메모리상에 할당되어 실행중인 프로그램이다.
//OS를 확인하기 위한 값.
HINSTANCE m_hInstance;
HWND m_hWnd;
POINT m_ptMouse = { 0, 0 };

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

	// MSG: 운영체제에서 발생하는 메세지 정보를 저장하기 위한 구조체
	MSG message;

	// TranslateMessage: 키보드 입력메세지 처리 담당
	// DispatchMessage: 윈도우 프로시저에 전달된 메세지를 실제 윈도우에 전달
	// GetMessage: 대기상태
	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	/*
	InvaildateRect:
	윈도우의 일부분을 무효화. 사용자가 InvaildateRect 통해서 윈도우의
	일부분을 무효화 시켰다면 윈도우에 발생되는 WM_PAINT 메시지를 통해 무효화된
	부분을 다시그려준다.
	*/

	HDC hdc;
	PAINTSTRUCT ps;

	static POINT  pt;
	static bool click_sizeF = false;
	static bool click_dragF = false;
	static WPARAM resizeF = NULL;

	static char  str[128];
	static char	 strPt[128];
	
	//RECT rcTemp;
	RECT rangeWindow = { 0, 0, WINSIZEX, WINSIZEY };

	SYSTEMTIME myTime;
	char strTime[128];
	GetLocalTime(&myTime);

	switch (iMessage)
	{
	case WM_CREATE:
		// 윈도우가 시작될 때 단 한번만 실행된다.
		RECT static rc = RectMakeCenter(
			WINSIZEX / 2, WINSIZEY / 2, 100, 100);
		//RECT static rc_in = setRectCenter(rc);

		wsprintf(strPt, "");

		// 전자시계 만들 타이머
		SetTimer(hWnd, 1, 1000, NULL);

		break;
	case WM_PAINT:
		// 윈도우의 작업영역이 손실되었을 때 실행된다. 그리는 곳
		hdc = BeginPaint(hWnd, &ps);

		// 컨트롤 가능한 사각형 출력 하는 부분
		RectangleMake(hdc, rc);
		//RectangleMake(hdc, rc_in);
		wsprintf(str, "컨트롤 가능");
		TextOut(hdc, rc.left + 5, rc.top + 5, str, strlen(str));

		// 전자시계 출력부분
		//GetTimeFormat()
		wsprintf(strTime, "%d:%d:%d", myTime.wHour, myTime.wMinute, 
			myTime.wSecond);
		TextOut(hdc, 20, 30, strTime, strlen(strTime));

		EndPaint(hWnd, &ps);
		break;
	case WM_MOUSEMOVE:
		pt.x = LOWORD(lParam);
		pt.y = HIWORD(lParam);

		if (click_sizeF == true)
		{
			rc = controlRectSize(rc, pt, resizeF);
			//rc_in = setRectCenter(rc);

			//wsprintf(strPt, "%d, %d", pt.x, pt.y);
		}//end of if: 사각형을 늘리려고 잡았을 때

		if (click_dragF == true)
		{
			moveRect(&rc, pt);
			//rc_in = setRectCenter(rc);
		}
		InvalidateRect(hWnd, NULL, true);
		break;
	case WM_TIMER:
		InvalidateRect(hWnd, NULL, true);
		break;
	case WM_LBUTTONDOWN:

		if (isInWindow(pt, rc) == true)
		{
			resizeF = isInRectEdge(rc, pt);
			if (resizeF != NULL)
			{
				click_sizeF = true;
				//wsprintf(strPt, "%d, %d", pt.x, pt.y);
			}
			else
			{
				click_dragF = true;
			}
			//wsprintf(strPt, "%d, %d", pt.x, pt.y);
		}

		InvalidateRect(hWnd, NULL, true);
		break;
	case WM_LBUTTONUP:
		click_sizeF = false;
		click_dragF = false;
		wsprintf(strPt, "");
		//InvalidateRect(hWnd, NULL, true);
		break;
	case WM_KEYDOWN:
		break;
	case WM_DESTROY:
		// 윈도우가 종료될 때 단 한번만 실행된다.
		KillTimer(hWnd, 1);
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
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
