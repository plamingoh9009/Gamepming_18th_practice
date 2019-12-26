#include "DrawApple.h"
#include "DrawName.h"

HINSTANCE m_hInstance;
HWND m_hWnd;
LPTSTR m_lpszClass = TEXT("���� ���α׷��� 18��");

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
		m_lpszClass, m_lpszClass,	// Ŭ���� �̸�, ������Ÿ��Ʋ �̸�
		WS_OVERLAPPEDWINDOW,	// ������ ��Ÿ��
		30, 30, 1024, 512,	// ������ ȭ�� x,y | ������ ũ�� x,y
		NULL, (HMENU)NULL,	// �θ� ������, �޴��ڵ�
		hInstance, NULL		// �ν��Ͻ� ����
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
		// �����찡 ���۵� �� �� �ѹ��� ����ȴ�.
		break;
	case WM_PAINT:
		// �������� �۾������� �սǵǾ��� �� ����ȴ�. �׸��� ��
		hdc = BeginPaint(hWnd, &ps);

		// ������ �׸� 200 X 231 ������ ǥ���Ѵ�.
		startX = 30;
		startY = 30;
		/*MoveToEx(hdc, startX, startY, NULL);
		LineTo(hdc, 200+ startX, startY);
		LineTo(hdc, 200+ startX, 231+ startY);

		MoveToEx(hdc, startX, startY, NULL);
		LineTo(hdc, startX, 231+ startY);
		LineTo(hdc, 200+ startX, 231+ startY);*/

		// ������ ���ĸ��� �׸���.
		apple.draw_leaf(hdc, startX, startY);
		apple.draw_green(hdc, startX, startY);
		apple.draw_yello(hdc, startX, startY);
		apple.draw_orenge(hdc, startX, startY);
		apple.draw_red(hdc, startX, startY);
		apple.draw_purple(hdc, startX, startY);
		apple.draw_blue(hdc, startX, startY);

		// �� �̸��� �׸���.
		// ��ġ�� ��ŸƮ ��ġ * 2 + 200
		startX = startX * 2 + 200;
		startY += 231;
		myName.draw_name(hdc, startX, startY);

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		// �����찡 ����� �� �� �ѹ��� ����ȴ�.
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}
