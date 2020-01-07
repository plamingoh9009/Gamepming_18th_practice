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

	//�����̸�
	int len = strlen(fileName);
	_fileName = new char[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	_isTrans = isTrans;
	_transColor = transColor;

	//���ҽ��� �����µ� �����ߴٸ�
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

void image::frameRender(HDC hdc, LONG destX, LONG destY)
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

void image::frameRender(HDC hdc, LONG destX, LONG destY, LONG currentFrameX, LONG currentFrameY)
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
