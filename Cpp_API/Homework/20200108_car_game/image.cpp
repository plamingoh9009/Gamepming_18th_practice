#include "stdafx.h"
#include "image.h"
//���ĺ��带 ����ϱ� ���ؼ�
#pragma comment(lib,"msimg32.lib")
//��� �̴ϼȶ����� �ʱ�ȭ
//��ü ������ ���ÿ� �ʱ�ȭ
image::image() : _imageInfo(NULL),
				_fileName(NULL),
				_isTrans(false),
				_transColor(RGB(0,0,0))
{
}

image::~image()
{
}

HRESULT image::init(int width, int height)
{
	//�̹��� ������ ����ִٸ� �����ض�
	if (_imageInfo != NULL)release();
	//DC��������(���� �����쿡 ���� ȭ�� DC�� �ӽ÷� �����´�.)
	//CreateCompatibleDC : ��Ʈ���� ����ϱ� ���� �޸� DC�� ������ش�.
	//CreateCompatibleBitmap : ����DC�� ȣȯ�Ǵ� ��Ʈ���� �������ش�.
	//SelectObject : �⺻�� ��Ʈ�� �ڵ��� ��ȯ�ϰ�, ���ο� ��Ʈ���� �޸� DC����
	//�����ϰ� �޸� DC�� ��Ʈ���� �׷�����. ȭ��DC�� �ƴϹǷ� ����Ϳ� ���X
	HDC hdc = GetDC(m_hWnd);

	//�̹��� ���� ����
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_EMPTY;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	//�����̸�
	_fileName = NULL;

	//���� ���� �ɼ�
	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;
	_blendFunc.BlendOp = AC_SRC_OVER;//���� ������

	//���� ���带 ����ϱ����� �̹��� �ʱ�ȭ

	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = LOAD_EMPTY;
	_blendImage->resID = 0;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, _imageInfo->width, _imageInfo->height);
	_blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZEX;
	_blendImage->height = WINSIZEY;

	//����Ű ����
	_isTrans = false;
	_transColor = RGB(0, 0, 0);

	//���ҽ��� �����µ� �����ϸ�
	if (_imageInfo->hBit == NULL)
	{
		release();
		return E_FAIL;
	}
	//DC����
	ReleaseDC(m_hWnd, hdc);

	return S_OK;
}

HRESULT image::init(const char * fileName, int width, int height, bool isTrans, COLORREF transColor)
{
	if (fileName == NULL) return E_FAIL;
	if (_imageInfo != NULL)release();

	HDC hdc = GetDC(m_hWnd);

	
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(m_hInstance,
										  fileName,
										  IMAGE_BITMAP,
										  width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;


	//���� ���� �ɼ�
	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;
	_blendFunc.BlendOp = AC_SRC_OVER;//���� ������

									 //���� ���带 ����ϱ����� �̹��� �ʱ�ȭ

	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = LOAD_EMPTY;
	_blendImage->resID = 0;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, _imageInfo->width, _imageInfo->height);
	_blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZEX;
	_blendImage->height = WINSIZEY;



	//�����̸�
	int len = strlen(fileName);
	_fileName = new char[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	_isTrans = isTrans;
	_transColor = transColor;

	//���Ҹ� �����µ� �����ߴٸ�
	if (_imageInfo->hBit == NULL)
	{
		release();
		return E_FAIL;
	}
	//����
	ReleaseDC(m_hWnd, hdc);

	return S_OK;
}

HRESULT image::init(const char * fileName, int width, int height, int frameX, int frameY, bool isTrans, COLORREF transColor)
{
	if (fileName == NULL) return E_FAIL;
	if (_imageInfo != NULL)release();

	HDC hdc = GetDC(m_hWnd);


	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(m_hInstance,
		fileName,
		IMAGE_BITMAP,
		width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->maxFrameX = frameX - 1;
	_imageInfo->maxFrameY = frameY - 1;
	_imageInfo->frameWidth = width / frameX;
	_imageInfo->frameHeight = height / frameY;


	//���� ���� �ɼ�
	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;
	_blendFunc.BlendOp = AC_SRC_OVER;//���� ������

									 //���� ���带 ����ϱ����� �̹��� �ʱ�ȭ

	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = LOAD_EMPTY;
	_blendImage->resID = 0;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, _imageInfo->width, _imageInfo->height);
	_blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZEX;
	_blendImage->height = WINSIZEY;


	//�����̸�
	int len = strlen(fileName);
	_fileName = new char[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	_isTrans = isTrans;
	_transColor = transColor;


	//���Ҹ� �����µ� �����ߴٸ�
	if (_imageInfo->hBit == NULL)
	{
		release();
		return E_FAIL;
	}
	//����
	ReleaseDC(m_hWnd, hdc);
	return S_OK;
}

HRESULT image::init(const char * fileName, int x, int y, int width, int height, int frameX, int frameY, bool isTrans, COLORREF transColor)
{
	if (fileName == NULL) return E_FAIL;
	if (_imageInfo != NULL)release();

	HDC hdc = GetDC(m_hWnd);


	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(m_hInstance,
		fileName,
		IMAGE_BITMAP,
		width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);

	_imageInfo->x = x;
	_imageInfo->y = y;
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->maxFrameX = frameX - 1;
	_imageInfo->maxFrameY = frameY - 1;
	_imageInfo->frameWidth = width / frameX;
	_imageInfo->frameHeight = height / frameY;


	//���� ���� �ɼ�
	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;
	_blendFunc.BlendOp = AC_SRC_OVER;//���� ������

									 //���� ���带 ����ϱ����� �̹��� �ʱ�ȭ

	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = LOAD_EMPTY;
	_blendImage->resID = 0;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, _imageInfo->width, _imageInfo->height);
	_blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZEX;
	_blendImage->height = WINSIZEY;

	//�����̸�
	int len = strlen(fileName);
	_fileName = new char[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	_isTrans = isTrans;
	_transColor = transColor;


	//���Ҹ� �����µ� �����ߴٸ�
	if (_imageInfo->hBit == NULL)
	{
		release();
		return E_FAIL;
	}
	//����
	ReleaseDC(m_hWnd, hdc);

	return S_OK;
}

void image::setTransColor(bool isTrans, COLORREF transColor)
{
	_isTrans = isTrans;
	_transColor = transColor;
}

void image::release()
{
	if (_imageInfo)
	{
		SelectObject(_imageInfo->hMemDC, _imageInfo->hOBit);
		DeleteObject(_imageInfo->hBit);
		DeleteDC(_imageInfo->hMemDC);

		SAFE_DELETE(_imageInfo);
		SAFE_DELETE(_fileName);

		_isTrans = false;
		_transColor = RGB(0, 0, 0);
	}
}

void image::render(HDC hdc)
{
	if (_isTrans)
	{
		//GdiTransparentBlt : ��Ʈ���� �ҷ��ö� Ư�������� �����ϰ� �������ִ� �Լ�
		GdiTransparentBlt(
			hdc,							//����� ����� DC
			0,								//����� ��ǥ�� ������ X
			0,								//����� ��ǥ�� ������ Y
			_imageInfo->width,				//����� �̹��� ����ũ��
			_imageInfo->height,				//����� �̹��� ����ũ��
			_imageInfo->hMemDC,				//����� ��� DC
			0,								//������� ���� X
			0,								//������� ���� Y
			_imageInfo->width,				//���翵�� ����ũ��
			_imageInfo->height,				//���翵�� ����ũ��
			_transColor);					//�����Ҷ� ������ ����
	}
	else
	{
		//SRCCOPY  : �������ִ� �Լ� ���� ���θ� �������ػ� ����
		//DC���� �������� ��Ӻ������ִ� �༮
		BitBlt(hdc, 0, 0, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, SRCCOPY);
	}
}

void image::render(HDC hdc, int destX, int destY)
{
	if (_isTrans)
	{
		//GdiTransparentBlt : ��Ʈ���� �ҷ��ö� Ư�������� �����ϰ� �������ִ� �Լ�
		GdiTransparentBlt(
			hdc,							//����� ����� DC
			destX,								//����� DC������ �ѷ��� X��ǥ
			destY,								//����� DC������ �ѷ��� Y��ǥ
			_imageInfo->width,				//����� �̹��� ����ũ��
			_imageInfo->height,				//����� �̹��� ����ũ��
			_imageInfo->hMemDC,				//����� ��� DC
			0,								//������� ���� X
			0,								//������� ���� Y
			_imageInfo->width,				//���翵�� ����ũ��
			_imageInfo->height,				//���翵�� ����ũ��
			_transColor);					//�����Ҷ� ������ ����
	}
	else
	{
		//SRCCOPY  : �������ִ� �Լ� ���� ���θ� �������ػ� ����
		//DC���� �������� ��Ӻ������ִ� �༮
		BitBlt(hdc, destX, destY, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, SRCCOPY);
	}
}
								//�Ѹ��� x,y			//�ѷ��ð� x,y
void image::render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight)
{
	if (_isTrans)
	{
		//GdiTransparentBlt : ��Ʈ���� �ҷ��ö� Ư�������� �����ϰ� �������ִ� �Լ�
		GdiTransparentBlt(
			hdc,							
			destX,							
			destY,							
			sourWidth,		
			sourHeight,		
			_imageInfo->hMemDC,				
			sourX,								
			sourY,								
			sourWidth,
			sourHeight,
			_transColor);					
	}
	else
	{
		//SRCCOPY  : �������ִ� �Լ� ���� ���θ� �������ػ� ����
		//DC���� �������� ��Ӻ������ִ� �༮
		BitBlt(hdc, destX, destY, sourWidth, sourHeight,
			_imageInfo->hMemDC, sourX, sourY, SRCCOPY);
	}
}

void image::frameRender(HDC hdc, int destX, int destY)
{
	if (_isTrans)
	{
		//GdiTransparentBlt : ��Ʈ���� �ҷ��ö� Ư�������� �����ϰ� �������ִ� �Լ�
		GdiTransparentBlt(
			hdc,							
			destX,							
			destY,							
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_transColor);					
	}
	else
	{
		//SRCCOPY  : �������ִ� �Լ� ���� ���θ� �������ػ� ����
		//DC���� �������� ��Ӻ������ִ� �༮
		BitBlt(hdc, destX, destY, _imageInfo->frameWidth, _imageInfo->frameHeight,
			_imageInfo->hMemDC, 
			_imageInfo->currentFrameX * _imageInfo->frameWidth, 
			_imageInfo->currentFrameY * _imageInfo->frameHeight, SRCCOPY);
	}
}

void image::frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY)
{
	_imageInfo->currentFrameX = currentFrameX;
	_imageInfo->currentFrameY = currentFrameY;


	if (_isTrans)
	{
		//GdiTransparentBlt : ��Ʈ���� �ҷ��ö� Ư�������� �����ϰ� �������ִ� �Լ�
		GdiTransparentBlt(
			hdc,
			destX,
			destY,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_transColor);
	}
	else
	{
		//SRCCOPY  : �������ִ� �Լ� ���� ���θ� �������ػ� ����
		//DC���� �������� ��Ӻ������ִ� �༮
		BitBlt(hdc, destX, destY, _imageInfo->frameWidth, _imageInfo->frameHeight,
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight, SRCCOPY);
	}

}

void image::loopRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY)
{
	//�����ϱ�
	if (offsetX < 0)offsetX = _imageInfo->width + (offsetX % _imageInfo->width);
	if (offsetY < 0)offsetY = _imageInfo->height + (offsetY % _imageInfo->height);

	//�׷�����(����Ǿ���� �̹��� ����)
	RECT rcSour;

	int sourWidth;
	int sourHeight;
	//�׷����� DC����
	RECT rcDest;

	int drawAreaX = drawArea->left;
	int drawAreaY = drawArea->top;
	int drawAreaW = drawArea->right - drawArea->left;
	int drawAreaH = drawArea->bottom - drawArea->top;
	
	//���� ��������
	for (int y = 0; y < drawAreaH; y += sourHeight)
	{
		//������ ���� �������.
		rcSour.top = (y + offsetY) % _imageInfo->height;
		rcSour.bottom = _imageInfo->height;
		sourHeight = rcSour.bottom - rcSour.top;

		//������ �׸��� ȭ���� �Ѿ�ٸ�(ȭ�� ������ ��������)
		if (y + sourHeight > drawAreaH)
		{
			//�Ѿ �׸��� ����ŭ ������ ���� �÷��� 
			rcSour.bottom -= (y + sourHeight) - drawAreaH;
			sourHeight = rcSour.bottom - rcSour.top;
		}
		rcDest.top = y + drawAreaY;
		rcDest.bottom = rcDest.top + sourHeight;

		//���� ���� ����
		for (int x = 0; x< drawAreaW; x += sourWidth)
		{
			//�������
			rcSour.left = (x + offsetX) % _imageInfo->width;
			rcSour.right = _imageInfo->width;
			sourWidth = rcSour.right - rcSour.left;

			//ȭ������� �Ѿ� ���ٸ�
			if (x + sourWidth > drawAreaW)
			{
				//�Ѿ �縸ŭ ����Ʈ ���� ��������..
				rcSour.right -= (x + sourWidth) - drawAreaW;
				sourWidth = rcSour.right - rcSour.left;
			}
			rcDest.left = x + drawAreaX;
			rcDest.right = rcDest.left + sourWidth;
			//�׸���
			render(hdc, rcDest.left, rcDest.top,
				rcSour.left, rcSour.top,
				rcSour.right - rcSour.left,
				rcSour.bottom - rcSour.top);
		}
	}
}

void image::loopAlphaRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY, BYTE alpha)
{
	//�����ϱ�
	if (offsetX < 0)offsetX = _imageInfo->width + (offsetX % _imageInfo->width);
	if (offsetY < 0)offsetY = _imageInfo->height + (offsetY % _imageInfo->height);

	//�׷�����(����Ǿ���� �̹��� ����)
	RECT rcSour;

	int sourWidth;
	int sourHeight;
	//�׷����� DC����
	RECT rcDest;

	int drawAreaX = drawArea->left;
	int drawAreaY = drawArea->top;
	int drawAreaW = drawArea->right - drawArea->left;
	int drawAreaH = drawArea->bottom - drawArea->top;

	//���� ��������
	for (int y = 0; y < drawAreaH; y += sourHeight)
	{
		//������ ���� �������.
		rcSour.top = (y + offsetY) % _imageInfo->height;
		rcSour.bottom = _imageInfo->height;
		sourHeight = rcSour.bottom - rcSour.top;

		//������ �׸��� ȭ���� �Ѿ�ٸ�(ȭ�� ������ ��������)
		if (y + sourHeight > drawAreaH)
		{
			//�Ѿ �׸��� ����ŭ ������ ���� �÷��� 
			rcSour.bottom -= (y + sourHeight) - drawAreaH;
			sourHeight = rcSour.bottom - rcSour.top;
		}
		rcDest.top = y + drawAreaY;
		rcDest.bottom = rcDest.top + sourHeight;

		//���� ���� ����
		for (int x = 0; x< drawAreaW; x += sourWidth)
		{
			//�������
			rcSour.left = (x + offsetX) % _imageInfo->width;
			rcSour.right = _imageInfo->width;
			sourWidth = rcSour.right - rcSour.left;

			//ȭ������� �Ѿ� ���ٸ�
			if (x + sourWidth > drawAreaW)
			{
				//�Ѿ �縸ŭ ����Ʈ ���� ��������..
				rcSour.right -= (x + sourWidth) - drawAreaW;
				sourWidth = rcSour.right - rcSour.left;
			}
			rcDest.left = x + drawAreaX;
			rcDest.right = rcDest.left + sourWidth;
			//�׸���
			alphaRender(hdc, rcDest.left, rcDest.top,
				rcSour.left, rcSour.top,
				rcSour.right - rcSour.left,
				rcSour.bottom - rcSour.top,alpha);
		}
	}
}

void image::alphaRender(HDC hdc, BYTE alpha)
{
	//���İ� �ʱ�ȭ
	_blendFunc.SourceConstantAlpha = alpha;

	//���İ� �ʱ�ȭ
	_blendFunc.SourceConstantAlpha = alpha;

	if (_isTrans)
	{
		
		BitBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			hdc, _imageInfo->x, _imageInfo->y, SRCCOPY);

		GdiTransparentBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _transColor);

		AlphaBlend(hdc, _imageInfo->x, _imageInfo->y, _imageInfo->width, _imageInfo->height,
			_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			_blendFunc);
	}
	else
	{
		AlphaBlend(hdc, _imageInfo->x, _imageInfo->y, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}

}

void image::alphaRender(HDC hdc, int destX, int destY, BYTE alpha)
{
	//���İ� �ʱ�ȭ
	_blendFunc.SourceConstantAlpha = alpha;

	if (_isTrans)
	{
		BitBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			hdc, destX, destY, SRCCOPY);

		GdiTransparentBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _transColor);

		AlphaBlend(hdc, destX, destY, _imageInfo->width, _imageInfo->height,
			_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			_blendFunc);
	}
	else
	{
		AlphaBlend(hdc,destX, destY, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			_blendFunc);
	}
}

void image::alphaRender(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha)
{
	//���İ� �ʱ�ȭ
	_blendFunc.SourceConstantAlpha = alpha;

	if (_isTrans)
	{
		BitBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			hdc, destX, destY, SRCCOPY);

		GdiTransparentBlt(_blendImage->hMemDC, 0, 0, sourWidth, sourHeight,
			_imageInfo->hMemDC, sourX, sourY, sourWidth, sourHeight, _transColor);

		AlphaBlend(hdc, destX, destY, sourWidth, sourHeight,_blendImage->hMemDC, 0, 0, sourWidth, sourHeight,_blendFunc);
	}
	else
	{
		AlphaBlend(hdc, destX, destY, sourWidth, sourHeight, _imageInfo->hMemDC, sourX,sourY, sourWidth, sourHeight, _blendFunc);
	}
}
