#include "DrawApple.h"
#include "DrawName.h"

HINSTANCE m_hInstance;
HWND m_hWnd;
LPTSTR m_lpszClass = TEXT("경일 프로그래밍 18기");

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdParam, int nCmdShow)
{
	m_hInstance = hInstance;

	WNDCLASS wndClass;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = hInstance;
	wndClass.lpfnWndProc = (WNDPROC)WndProc;
	wndClass.lpszClassName = m_lpszClass;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndClass);

	m_hWnd = CreateWindow(
		m_lpszClass, m_lpszClass,	// 클래스 이름, 윈도우타이틀 이름
		WS_OVERLAPPEDWINDOW,	// 윈도우 스타일
		30, 30, 1024, 512,	// 윈도우 화면 x,y | 윈도우 크기 x,y
		NULL, (HMENU)NULL,	// 부모 윈도우, 메뉴핸들
		hInstance, NULL		// 인스턴스 지정
	);

	ShowWindow(m_hWnd, nCmdShow);

	MSG message;

	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	DrawApple apple;
	DrawName myName;
	int startX, startY;
	switch (iMessage)
	{
	case WM_CREATE:
		// 윈도우가 시작될 때 단 한번만 실행된다.
		break;
	case WM_PAINT:
		// 윈도우의 작업영역이 손실되었을 때 실행된다. 그리는 곳
		hdc = BeginPaint(hWnd, &ps);

		// 애플을 그릴 200 X 231 영역을 표시한다.
		startX = 30;
		startY = 30;
		/*MoveToEx(hdc, startX, startY, NULL);
		LineTo(hdc, 200+ startX, startY);
		LineTo(hdc, 200+ startX, 231+ startY);

		MoveToEx(hdc, startX, startY, NULL);
		LineTo(hdc, startX, 231+ startY);
		LineTo(hdc, 200+ startX, 231+ startY);*/

		// 애플의 이파리를 그린다.
		apple.draw_leaf(hdc, startX, startY);
		apple.draw_green(hdc, startX, startY);
		apple.draw_yello(hdc, startX, startY);
		apple.draw_orenge(hdc, startX, startY);
		apple.draw_red(hdc, startX, startY);
		apple.draw_purple(hdc, startX, startY);
		apple.draw_blue(hdc, startX, startY);

		// 내 이름을 그린다.
		// 위치는 스타트 위치 * 2 + 200
		startX = startX * 2 + 200;
		startY += 231;
		myName.draw_name(hdc, startX, startY);

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		// 윈도우가 종료될 때 단 한번만 실행된다.
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}
