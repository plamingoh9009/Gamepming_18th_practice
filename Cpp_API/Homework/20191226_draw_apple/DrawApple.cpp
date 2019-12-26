#include "DrawApple.h"



void DrawApple::draw_leaf(HDC hdc, int x, int y)
{
	int xLeaf = x + 97;
	int yLeaf = y + 57;
	_xLeaf = xLeaf;
	_yLeaf = yLeaf;

	int i = 0;

	// 1번째 싸이클
	{
		for (i = 0; i < 15; i++)
		{
			SetPixel(hdc, xLeaf, yLeaf - i, RGB(98, 187, 71));
		}
		for (i = 0; i < 20; i++)
		{
			SetPixel(hdc, xLeaf + 1, yLeaf - i, RGB(98, 187, 71));
		}
		for (i = 0; i < 23; i++)
		{
			SetPixel(hdc, xLeaf + 2, yLeaf - i, RGB(98, 187, 71));
		}
		for (i = 0; i < 26; i++)
		{
			SetPixel(hdc, xLeaf + 3, yLeaf - i, RGB(98, 187, 71));
		}
		for (i = 0; i < 29; i++)
		{
			SetPixel(hdc, xLeaf + 4, yLeaf - i, RGB(98, 187, 71));
		}
	}

	// 2번째 싸이클
	xLeaf = xLeaf + 5;
	yLeaf = yLeaf - 1;

	{
		for (i = 0; i < 28; i++)
		{
			SetPixel(hdc, xLeaf, yLeaf - i, RGB(98, 187, 71));
		}
		for (i = 0; i < 30; i++)
		{
			SetPixel(hdc, xLeaf + 1, yLeaf - i, RGB(98, 187, 71));
		}
		for (i = 0; i < 32; i++)
		{
			SetPixel(hdc, xLeaf + 2, yLeaf - i, RGB(98, 187, 71));
		}
		for (i = 0; i < 34; i++)
		{
			SetPixel(hdc, xLeaf + 3, yLeaf - i, RGB(98, 187, 71));
		}
		for (i = 0; i < 36; i++)
		{
			SetPixel(hdc, xLeaf + 4, yLeaf - i, RGB(98, 187, 71));
		}
	}

	// 3 번째 싸이클 35개 픽셀 4줄
	xLeaf = xLeaf + 5;
	yLeaf = yLeaf - 1;

	{
		for (i = 0; i < 35; i++)
		{
			SetPixel(hdc, xLeaf, yLeaf - i, RGB(98, 187, 71));
		}
		for (i = 0; i < 36; i++)
		{
			SetPixel(hdc, xLeaf + 1, yLeaf - i, RGB(98, 187, 71));
		}
		for (i = 0; i < 37; i++)
		{
			SetPixel(hdc, xLeaf + 2, yLeaf - i, RGB(98, 187, 71));
		}
		for (i = 0; i < 38; i++)
		{
			SetPixel(hdc, xLeaf + 3, yLeaf - i, RGB(98, 187, 71));
		}
	}

	// 4번째 싸이클 39개 픽셀 3줄
	xLeaf = xLeaf + 4;
	yLeaf = yLeaf - 1;

	{
		for (i = 0; i < 39; i++)
		{
			SetPixel(hdc, xLeaf, yLeaf - i, RGB(98, 187, 71));
		}
		for (i = 0; i < 40; i++)
		{
			SetPixel(hdc, xLeaf + 1, yLeaf - i, RGB(98, 187, 71));
		}
		for (i = 0; i < 41; i++)
		{
			SetPixel(hdc, xLeaf + 2, yLeaf - i, RGB(98, 187, 71));
		}
	}

	// 5번째 싸이클 
	xLeaf = xLeaf + 3;
	yLeaf = yLeaf - 1;

	{
		for (i = 0; i < 39; i++)
		{
			SetPixel(hdc, xLeaf, yLeaf - i, RGB(98, 187, 71));
		}
		for (i = 0; i < 39; i++)
		{
			SetPixel(hdc, xLeaf + 1, yLeaf - i, RGB(98, 187, 71));
		}
	}

	// 6번째 싸이클
	xLeaf = xLeaf + 2;
	yLeaf = yLeaf - 1;

	{
		for (i = 0; i < 40; i++)
		{
			SetPixel(hdc, xLeaf, yLeaf - i, RGB(98, 187, 71));
		}
		for (i = 0; i < 40; i++)
		{
			SetPixel(hdc, xLeaf + 1, yLeaf - i, RGB(98, 187, 71));
		}
	}

	// 7번째 싸이클
	xLeaf = xLeaf + 2;
	yLeaf = yLeaf - 1;

	{
		for (i = 0; i < 40; i++)
		{
			SetPixel(hdc, xLeaf, yLeaf - i, RGB(98, 187, 71));
		}
		for (i = 0; i < 40; i++)
		{
			SetPixel(hdc, xLeaf + 1, yLeaf - i, RGB(98, 187, 71));
		}
	}

	// 8번째 싸이클
	xLeaf = xLeaf + 2;
	yLeaf = yLeaf - 1;

	{
		for (i = 0; i < 40; i++)
		{
			SetPixel(hdc, xLeaf, yLeaf - i, RGB(98, 187, 71));
		}
		for (i = 0; i < 41; i++)
		{
			SetPixel(hdc, xLeaf + 1, yLeaf - i, RGB(98, 187, 71));
		}
	}

	// 9번째 싸이클
	xLeaf = xLeaf + 2;
	yLeaf = yLeaf - 1;

	{
		for (i = 0; i < 40; i++)
		{
			SetPixel(hdc, xLeaf, yLeaf - i, RGB(98, 187, 71));
		}
	}

	// 10번째 싸이클 
	xLeaf = xLeaf + 1;
	yLeaf = yLeaf - 1;

	{
		for (i = 0; i < 41; i++)
		{
			SetPixel(hdc, xLeaf, yLeaf - i, RGB(98, 187, 71));
		}
		for (i = 0; i < 42; i++)
		{
			SetPixel(hdc, xLeaf + 1, yLeaf - i, RGB(98, 187, 71));
		}
	}

	// 11번째 싸이클
	xLeaf = xLeaf + 2;
	yLeaf = yLeaf - 1;

	{
		for (i = 0; i < 41; i++)
		{
			SetPixel(hdc, xLeaf, yLeaf - i, RGB(98, 187, 71));
		}
	}

	// 12번째 싸이클
	xLeaf = xLeaf + 1;
	yLeaf = yLeaf - 1;

	{
		for (i = 0; i < 40; i++)
		{
			SetPixel(hdc, xLeaf, yLeaf - i, RGB(98, 187, 71));
		}
	}

	// 13번째 싸이클
	xLeaf = xLeaf + 1;
	yLeaf = yLeaf - 1;

	{
		for (i = 0; i < 39; i++)
		{
			SetPixel(hdc, xLeaf, yLeaf - i, RGB(98, 187, 71));
		}
	}

	// 14번째 싸이클
	xLeaf = xLeaf + 1;
	yLeaf = yLeaf - 1;

	{
		for (i = 0; i < 38; i++)
		{
			SetPixel(hdc, xLeaf, yLeaf - i, RGB(98, 187, 71));
		}
		for (i = 0; i < 39; i++)
		{
			SetPixel(hdc, xLeaf + 1, yLeaf - i, RGB(98, 187, 71));
		}
	}

	// 15번째 싸이클
	xLeaf = xLeaf + 2;
	yLeaf = yLeaf - 1;

	{
		for (i = 0; i < 38; i++)
		{
			SetPixel(hdc, xLeaf, yLeaf - i, RGB(98, 187, 71));
		}
	}

	// 16번째 싸이클
	xLeaf = xLeaf + 1;
	yLeaf = yLeaf - 1;

	{
		for (i = 0; i < 38; i++)
		{
			SetPixel(hdc, xLeaf, yLeaf - i, RGB(98, 187, 71));
		}
	}

	// 17번째 싸이클
	xLeaf = xLeaf + 1;
	yLeaf = yLeaf - 1;

	{
		for (i = 0; i < 37; i++)
		{
			SetPixel(hdc, xLeaf, yLeaf - i, RGB(98, 187, 71));
		}
	}

	// 18번째 싸이클
	xLeaf = xLeaf + 1;
	yLeaf = yLeaf - 1;

	{
		for (i = 0; i < 37; i++)
		{
			SetPixel(hdc, xLeaf, yLeaf - i, RGB(98, 187, 71));
		}
	}

	// 19번째 싸이클
	xLeaf = xLeaf + 1;
	yLeaf = yLeaf - 2;

	{
		for (i = 0; i < 34; i++)
		{
			SetPixel(hdc, xLeaf, yLeaf - i, RGB(98, 187, 71));
		}
	}

	// 20번째 싸이클
	xLeaf = xLeaf + 1;
	yLeaf = yLeaf - 1;

	{
		for (i = 0; i < 35; i++)
		{
			SetPixel(hdc, xLeaf, yLeaf - i, RGB(98, 187, 71));
		}
	}

	// 21번째 싸이클
	xLeaf = xLeaf + 1;
	yLeaf = yLeaf - 1;

	{
		for (i = 0; i < 34; i++)
		{
			SetPixel(hdc, xLeaf, yLeaf - i, RGB(98, 187, 71));
		}
	}

	// 22번째 싸이클
	xLeaf = xLeaf + 1;
	yLeaf = yLeaf - 2;

	{
		for (i = 0; i < 33; i++)
		{
			SetPixel(hdc, xLeaf, yLeaf - i, RGB(98, 187, 71));
		}
	}

	// 23번째 싸이클
	xLeaf = xLeaf + 1;
	yLeaf = yLeaf - 1;

	{
		for (i = 0; i < 32; i++)
		{
			SetPixel(hdc, xLeaf, yLeaf - i, RGB(98, 187, 71));
		}
	}

	// 24번째 싸이클
	xLeaf = xLeaf + 1;
	yLeaf = yLeaf - 2;

	{
		for (i = 0; i < 30; i++)
		{
			SetPixel(hdc, xLeaf, yLeaf - i, RGB(98, 187, 71));
		}
	}

	// 25번째 싸이클
	xLeaf = xLeaf + 1;
	yLeaf = yLeaf - 2;

	{
		for (i = 0; i < 28; i++)
		{
			SetPixel(hdc, xLeaf, yLeaf - i, RGB(98, 187, 71));
		}
	}
	// 26번째 싸이클
	xLeaf = xLeaf + 1;
	yLeaf = yLeaf - 2;

	{
		for (i = 0; i < 29; i++)
		{
			SetPixel(hdc, xLeaf, yLeaf - i, RGB(98, 187, 71));
		}
	}

	// 27번째 싸이클
	xLeaf = xLeaf + 1;
	yLeaf = yLeaf - 2;

	{
		for (i = 0; i < 27; i++)
		{
			SetPixel(hdc, xLeaf, yLeaf - i, RGB(98, 187, 71));
		}
	}

	// 28번째 싸이클
	xLeaf = xLeaf + 1;
	yLeaf = yLeaf - 3;

	{
		for (i = 0; i < 24; i++)
		{
			SetPixel(hdc, xLeaf, yLeaf - i, RGB(98, 187, 71));
		}
	}

	// 29번째 싸이클
	xLeaf = xLeaf + 1;
	yLeaf = yLeaf - 3;

	{
		for (i = 0; i < 21; i++)
		{
			SetPixel(hdc, xLeaf, yLeaf - i, RGB(98, 187, 71));
		}
	}
}

void DrawApple::draw_green(HDC hdc, int startX, int startY)
{
	int x = 14 + startX;
	int y = 82 + startY;
	_xGreen = x;
	_yGreen = y;
	int lineLength = 170;

	int i;

	// 82 ~ 78
	{
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(98, 187, 71));
		}

		x += 1;
		y -= 1;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(98, 187, 71));
		}

		x += 1;
		y -= 1;
		lineLength = 171;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(98, 187, 71));
		}

		//x += 1;
		y -= 1;
		lineLength = 173;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(98, 187, 71));
		}

		x += 1;
		y -= 1;
		lineLength = 174;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(98, 187, 71));
		}
	}

	// 77 ~ 73
	{
		x += 1;
		y -= 1;
		lineLength = 171;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(98, 187, 71));
		}

		//x += 1;
		y -= 1;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(98, 187, 71));
		}

		x += 1;
		y -= 1;
		lineLength = 169;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(98, 187, 71));
		}

		x += 1;
		y -= 1;
		lineLength = 167;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(98, 187, 71));
		}

		x += 1;
		y -= 1;
		lineLength = 165;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(98, 187, 71));
		}
	}

	// 72 ~ 68
	{
		//x += 1;
		y -= 1;
		lineLength = 165;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(98, 187, 71));
		}

		x += 1;
		y -= 1;
		lineLength = 163;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(98, 187, 71));
		}

		x += 1;
		y -= 1;
		lineLength = 161;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(98, 187, 71));
		}

		x += 1;
		y -= 1;
		lineLength = 159;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(98, 187, 71));
		}

		x += 1;
		y -= 1;
		lineLength = 157;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(98, 187, 71));
		}
	}

	// 67 ~ 63
	{
		x += 1;
		y -= 1;
		lineLength = 156;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(98, 187, 71));
		}

		x += 1;
		y -= 1;
		lineLength = 153;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(98, 187, 71));
		}

		x += 1;
		y -= 1;
		lineLength = 150;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(98, 187, 71));
		}

		// 64
		x += 2;
		y -= 1;
		lineLength = 68;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(98, 187, 71));
		}
		lineLength = 66;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i + 81, y, RGB(98, 187, 71));
		}
		// 63
		x += 1;
		y -= 1;
		lineLength = 63;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(98, 187, 71));
		}
		lineLength = 60;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i + 84, y, RGB(98, 187, 71));
		}
	}

	// 62 ~ 58
	{
		// 62 지점
		x += 2;
		y -= 1;
		lineLength = 66;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(98, 187, 71));
		}
		lineLength = 63;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i + 80, y, RGB(98, 187, 71));
		}
		// 61 지점
		x += 1;
		y -= 1;
		lineLength = 59;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(98, 187, 71));
		}
		lineLength = 56;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i + 84, y, RGB(98, 187, 71));
		}

		x += 2;
		y -= 1;
		lineLength = 51;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(98, 187, 71));
		}
		lineLength = 49;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i + 85, y, RGB(98, 187, 71));
		}

		x += 1;
		y -= 1;
		lineLength = 47;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(98, 187, 71));
		}
		lineLength = 44;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i + 87, y, RGB(98, 187, 71));
		}

		x += 3;
		y -= 1;
		lineLength = 40;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(98, 187, 71));
		}
		lineLength = 39;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i + 86, y, RGB(98, 187, 71));
		}
	}

	// 57 ~ 
	{
		x += 3;
		y -= 1;
		lineLength = 33;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(98, 187, 71));
		}
		//lineLength = 63;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i + 86, y, RGB(98, 187, 71));
		}

		x += 4;
		y -= 1;
		lineLength = 24;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(98, 187, 71));
		}
		lineLength = 26;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i + 86, y, RGB(98, 187, 71));
		}
	}
}

void DrawApple::draw_yello(HDC hdc, int startX, int startY)
{
	int x = 14 + startX;
	int y = 83 + startY;
	int lineLength = 169;

	int i;

	// 83 ~ 87
	{
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(252, 184, 39));
		}

		x -= 1;
		y += 1;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(252, 184, 39));
		}

		//x -= 1;
		y += 1;
		lineLength = 168;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(252, 184, 39));
		}

		x -= 1;
		y += 1;
		//lineLength = 168;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(252, 184, 39));
		}

		//x -= 1;
		y += 1;
		lineLength = 167;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(252, 184, 39));
		}
	}

	// 88 ~ 92
	{
		x -= 1;
		y += 1;
		lineLength = 167;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(252, 184, 39));
		}

		//x -= 1;
		y += 1;
		lineLength--;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(252, 184, 39));
		}

		x -= 1;
		y += 1;
		//lineLength = 168;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(252, 184, 39));
		}

		//x -= 1;
		y += 1;
		lineLength--;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(252, 184, 39));
		}

		x -= 1;
		y += 1;
		lineLength = 165;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(252, 184, 39));
		}
	}

	// 93 ~ 98
	{
		//x -= 1;
		y += 1;
		lineLength = 164;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(252, 184, 39));
		}

		//x -= 1;
		y += 1;
		//lineLength--;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(252, 184, 39));
		}

		x -= 1;
		y += 1;
		lineLength = 164;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(252, 184, 39));
		}

		//x -= 1;
		y += 1;
		//lineLength--;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(252, 184, 39));
		}

		x -= 1;
		y += 1;
		//lineLength = 165;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(252, 184, 39));
		}

		//x -= 1;
		y += 1;
		//lineLength = 165;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(252, 184, 39));
		}
	}

	// 99 ~ 105
	{
		//x -= 1;
		y += 1;
		lineLength = 163;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(252, 184, 39));
		}

		x -= 1;
		y += 1;
		lineLength--;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(252, 184, 39));
		}

		//x -= 1;
		y += 1;
		//lineLength = 164;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(252, 184, 39));
		}

		// 102
		//x -= 1;
		y += 1;
		//lineLength--;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(252, 184, 39));
		}

		// 103
		x -= 1;
		y += 1;
		lineLength = 164;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(252, 184, 39));
		}

		//x -= 1;
		y += 1;
		lineLength--;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(252, 184, 39));
		}

		//x -= 1;
		y += 1;
		//lineLength--;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(252, 184, 39));
		}
	}

	// 106 ~ 111
	{
		//x -= 1;
		y += 1;
		lineLength = 163;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(252, 184, 39));
		}

		x -= 1;
		y += 1;
		//lineLength--;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(252, 184, 39));
		}

		//x -= 1;
		y += 1;
		//lineLength = 164;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(252, 184, 39));
		}

		//x -= 1;
		y += 1;
		//lineLength--;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(252, 184, 39));
		}

		// 110
		x -= 1;
		y += 1;
		lineLength = 163;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(252, 184, 39));
		}

		//x -= 1;
		y += 1;
		//lineLength--;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(252, 184, 39));
		}
	}
}

void DrawApple::draw_orenge(HDC hdc, int startX, int startY)
{
	int x = 3 + startX;
	int y = 112 + startY;
	int lineLength = 164;

	int i;

	// 112 ~ 116
	{
		//x -= 1;
		y += 1;
		lineLength = 164;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 130, 31));
		}

		//x -= 1;
		y += 1;
		//lineLength--;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 130, 31));
		}

		//x -= 1;
		y += 1;
		//lineLength = 164;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 130, 31));
		}

		//x -= 1;
		y += 1;
		//lineLength--;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 130, 31));
		}

		//x -= 1;
		y += 1;
		//lineLength = 163;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 130, 31));
		}
	}

	// 117 ~ 122
	{
		x -= 1;
		y += 1;
		lineLength = 164;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 130, 31));
		}

		//x -= 1;
		y += 1;
		//lineLength--;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 130, 31));
		}

		//x -= 1;
		y += 1;
		//lineLength = 164;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 130, 31));
		}

		//x -= 1;
		y += 1;
		//lineLength--;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 130, 31));
		}

		//x -= 1;
		y += 1;
		//lineLength = 163;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 130, 31));
		}

		//x -= 1;
		y += 1;
		//lineLength--;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 130, 31));
		}
	}

	// 123 ~ 128
	{
		//x -= 1;
		y += 1;
		lineLength = 164;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 130, 31));
		}

		//x -= 1;
		y += 1;
		//lineLength--;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 130, 31));
		}

		//x -= 1;
		y += 1;
		//lineLength = 164;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 130, 31));
		}

		//x -= 1;
		y += 1;
		//lineLength--;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 130, 31));
		}

		//x -= 1;
		y += 1;
		//lineLength = 163;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 130, 31));
		}

		//x -= 1;
		y += 1;
		//lineLength--;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 130, 31));
		}

	}

	// 129 ~ 134
	{
		x += 1;
		y += 1;
		lineLength = 164;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 130, 31));
		}

		//x -= 1;
		y += 1;
		//lineLength--;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 130, 31));
		}

		//x -= 1;
		y += 1;
		lineLength++;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 130, 31));
		}

		//x -= 1;
		y += 1;
		//lineLength--;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 130, 31));
		}

		//x -= 1;
		y += 1;
		//lineLength = 163;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 130, 31));
		}

		//x -= 1;
		y += 1;
		//lineLength--;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 130, 31));
		}
	}

	// 135 ~ 140
	{
		x += 1;
		y += 1;
		lineLength = 165;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 130, 31));
		}

		//x -= 1;
		y += 1;
		//lineLength--;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 130, 31));
		}

		//x -= 1;
		y += 1;
		lineLength++;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 130, 31));
		}

		//x -= 1;
		y += 1;
		//lineLength--;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 130, 31));
		}

		//x -= 1;
		y += 1;
		//lineLength = 163;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 130, 31));
		}

		//x -= 1;
		y += 1;
		lineLength++;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 130, 31));
		}
	}
}

void DrawApple::draw_red(HDC hdc, int startX, int startY)
{
	int x = 4 + startX;
	int y = 141 + startY;

	int lineLength = 167;

	int i;

	// 141 ~ 146
	{
		//x += 1;
		//y += 1;
		//lineLength = 165;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 58, 62));
		}

		//x -= 1;
		y += 1;
		lineLength++;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 58, 62));
		}

		//x -= 1;
		y += 1;
		//lineLength++;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 58, 62));
		}

		x += 1;
		y += 1;
		//lineLength--;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 58, 62));
		}

		//x -= 1;
		y += 1;
		//lineLength = 163;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 58, 62));
		}

		//x -= 1;
		y += 1;
		//lineLength++;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 58, 62));
		}
	}

	// 147 ~ 152
	{
		x += 1;
		y += 1;
		lineLength = 168;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 58, 62));
		}

		//x -= 1;
		y += 1;
		lineLength++;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 58, 62));
		}

		//x -= 1;
		y += 1;
		lineLength = 170;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 58, 62));
		}

		//x += 1;
		y += 1;
		//lineLength--;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 58, 62));
		}

		//x -= 1;
		y += 1;
		lineLength++;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 58, 62));
		}

		//x -= 1;
		y += 1;
		lineLength++;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 58, 62));
		}
	}

	// 153 ~ 158
	{
		x += 1;
		y += 1;
		lineLength = 172;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 58, 62));
		}

		//x -= 1;
		y += 1;
		//lineLength++;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 58, 62));
		}

		//x -= 1;
		y += 1;
		lineLength++;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 58, 62));
		}

		x += 1;
		y += 1;
		lineLength = 173;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 58, 62));
		}

		//x -= 1;
		y += 1;
		lineLength++;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 58, 62));
		}

		//x -= 1;
		y += 1;
		lineLength++;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 58, 62));
		}
	}

	// 159 ~ 164
	{
		//x += 1;
		y += 1;
		lineLength = 176;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 58, 62));
		}

		x += 1;
		y += 1;
		lineLength = 176;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 58, 62));
		}

		//x -= 1;
		y += 1;
		lineLength++;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 58, 62));
		}

		//x += 1;
		y += 1;
		lineLength += 2;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 58, 62));
		}

		x += 1;
		y += 1;
		lineLength = 179;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 58, 62));
		}

		//x -= 1;
		y += 1;
		lineLength += 2;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 58, 62));
		}
	}

	// 165 ~ 169
	{
		//x += 1;
		y += 1;
		lineLength = 183;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 58, 62));
		}

		x += 1;
		y += 1;
		lineLength = 184;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 58, 62));
		}

		//x -= 1;
		y += 1;
		lineLength += 3;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 58, 62));
		}

		//x += 1;
		y += 1;
		//lineLength += 2;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 58, 62));
		}

		x += 1;
		y += 1;
		lineLength = 185;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(244, 58, 62));
		}
	}
}

void DrawApple::draw_purple(HDC hdc, int startX, int startY)
{
	int x = 12 + startX;
	int y = 170 + startY;

	int lineLength;

	int i;

	// 170 ~ 175
	{
		//x += 1;
		//y += 1;
		lineLength = 185;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(150, 61, 151));
		}

		//x += 1;
		y += 1;
		lineLength--;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(150, 61, 151));
		}

		x += 1;
		y += 1;
		lineLength = 183;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(150, 61, 151));
		}

		//x += 1;
		y += 1;
		lineLength--;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(150, 61, 151));
		}

		x += 1;
		y += 1;
		lineLength = 181;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(150, 61, 151));
		}

		//x -= 1;
		y += 1;
		//lineLength += 2;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(150, 61, 151));
		}
	}

	// 176 ~ 181
	{
		x += 1;
		y += 1;
		lineLength = 179;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(150, 61, 151));
		}

		//x += 1;
		y += 1;
		//lineLength--;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(150, 61, 151));
		}

		x += 1;
		y += 1;
		lineLength = 177;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(150, 61, 151));
		}

		//x += 1;
		y += 1;
		//lineLength--;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(150, 61, 151));
		}

		x += 1;
		y += 1;
		lineLength = 175;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(150, 61, 151));
		}

		//x -= 1;
		y += 1;
		//lineLength += 2;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(150, 61, 151));
		}
	}

	// 182 ~ 188
	{
		//x += 1;
		y += 1;
		lineLength = 175;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(150, 61, 151));
		}

		x += 1;
		y += 1;
		lineLength = 173;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(150, 61, 151));
		}

		//x += 1;
		y += 1;
		//lineLength = 177;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(150, 61, 151));
		}

		x += 1;
		y += 1;
		lineLength = 171;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(150, 61, 151));
		}

		//x += 1;
		y += 1;
		//lineLength = 175;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(150, 61, 151));
		}

		x += 1;
		y += 1;
		lineLength = 169;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(150, 61, 151));
		}

		//x -= 1;
		y += 1;
		//lineLength += 2;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(150, 61, 151));
		}
	}

	// 189 ~ 196
	{
		x += 1;
		y += 1;
		lineLength = 167;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(150, 61, 151));
		}

		x += 1;
		y += 1;
		lineLength = 165;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(150, 61, 151));
		}

		//x += 1;
		y += 1;
		//lineLength = 177;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(150, 61, 151));
		}

		x += 1;
		y += 1;
		lineLength = 163;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(150, 61, 151));
		}

		//x += 1;
		y += 1;
		//lineLength = 175;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(150, 61, 151));
		}

		x += 1;
		y += 1;
		lineLength = 161;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(150, 61, 151));
		}

		x += 1;
		y += 1;
		lineLength = 159;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(150, 61, 151));
		}

		//x += 1;
		y += 1;
		//lineLength += 2;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(150, 61, 151));
		}
	}
}

void DrawApple::draw_blue(HDC hdc, int startX, int startY)
{
	int x = 26 + startX;
	int y = 197 + startY;

	int lineLength = 167;

	int i;

	// 197 ~ 204
	{
		x += 1;
		y += 1;
		lineLength = 157;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(0, 157, 220));
		}

		x += 1;
		y += 1;
		lineLength = 155;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(0, 157, 220));
		}

		//x += 1;
		y += 1;
		//lineLength = 177;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(0, 157, 220));
		}

		x += 1;
		y += 1;
		lineLength = 153;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(0, 157, 220));
		}

		x += 1;
		y += 1;
		lineLength = 151;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(0, 157, 220));
		}

		//x += 1;
		y += 1;
		//lineLength = 161;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(0, 157, 220));
		}

		x += 1;
		y += 1;
		lineLength = 149;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(0, 157, 220));
		}

		x += 1;
		y += 1;
		lineLength = 147;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(0, 157, 220));
		}
	}

	// 205 ~ 212
	{
		x += 1;
		y += 1;
		lineLength = 145;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(0, 157, 220));
		}

		//x += 1;
		y += 1;
		//lineLength = 155;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(0, 157, 220));
		}

		x += 1;
		y += 1;
		lineLength = 143;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(0, 157, 220));
		}

		x += 1;
		y += 1;
		lineLength = 141;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(0, 157, 220));
		}

		x += 1;
		y += 1;
		lineLength = 139;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(0, 157, 220));
		}

		x += 1;
		y += 1;
		lineLength = 137;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(0, 157, 220));
		}

		x += 1;
		y += 1;
		lineLength -= 2;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(0, 157, 220));
		}

		x += 1;
		y += 1;
		lineLength -= 2;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(0, 157, 220));
		}
	}

	// 213 ~ 217
	{
		x += 1;
		y += 1;
		lineLength = 132;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(0, 157, 220));
		}

		x += 1;
		y += 1;
		lineLength -= 2;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(0, 157, 220));
		}

		x += 1;
		y += 1;
		lineLength -= 2;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(0, 157, 220));
		}

		x += 1;
		y += 1;
		lineLength -= 2;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(0, 157, 220));
		}

		x += 1;
		y += 1;
		lineLength -= 2;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(0, 157, 220));
		}
	}

	// 218 ~ 223
	{
		x += 1;
		y += 1;
		lineLength = 52;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(0, 157, 220));
		}
		lineLength = 53;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i + 68, y, RGB(0, 157, 220));
		}

		x += 1;
		y += 1;
		lineLength = 48;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(0, 157, 220));
		}
		lineLength = 49;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i + 70, y, RGB(0, 157, 220));
		}

		x += 2;
		y += 1;
		lineLength = 43;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(0, 157, 220));
		}
		lineLength = 45;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i + 71, y, RGB(0, 157, 220));
		}

		x += 1;
		y += 1;
		lineLength = 39;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(0, 157, 220));
		}
		lineLength = 40;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i + 73, y, RGB(0, 157, 220));
		}

		x += 2;
		y += 1;
		lineLength = 35;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(0, 157, 220));
		}
		lineLength = 37;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i + 73, y, RGB(0, 157, 220));
		}

		x += 1;
		y += 1;
		lineLength = 31;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(0, 157, 220));
		}
		lineLength = 32;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i + 75, y, RGB(0, 157, 220));
		}
	}

	// 218 ~ 223
	{
		x += 2;
		y += 1;
		lineLength = 27;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(0, 157, 220));
		}
		lineLength = 28;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i + 75, y, RGB(0, 157, 220));
		}

		x += 2;
		y += 1;
		lineLength = 22;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(0, 157, 220));
		}
		lineLength = 23;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i + 76, y, RGB(0, 157, 220));
		}

		x += 3;
		y += 1;
		lineLength = 17;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(0, 157, 220));
		}
		lineLength = 17;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i + 76, y, RGB(0, 157, 220));
		}

		x += 3;
		y += 1;
		lineLength = 10;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i, y, RGB(0, 157, 220));
		}
		lineLength = 9;
		for (i = 0; i < lineLength; i++)
		{
			SetPixel(hdc, x + i + 77, y, RGB(0, 157, 220));
		}
	}
}

DrawApple::DrawApple()
{
}


DrawApple::~DrawApple()
{
}
