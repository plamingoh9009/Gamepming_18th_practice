#pragma once
/*
 1.BMP :  ������ ������ ���ս� �������̹Ƿ� �ӵ��� ���� ������.
 2.JPG : �սǾ����̹Ƿ� ���� ���� �̹����� �ս��� �Ͼ�� ���
 �����̵Ǿ� �뷮�� �۴�.
 3.PNG: 1,2�� �޸� alphaä���� ����.
*/
class image
{
public:
	enum IMAGE_LOAD_KIND
	{
		LOAD_RESOURCE = 0,	//���ҽ��ε�
		LOAD_FILE,			//���Ϸε�
		LOAD_EMPTY,			//�� ��Ʈ�� ����
		LOAD_END
	};

	typedef struct tagImage
	{
		DWORD		resID;				//���ҽ� ID
		HDC			hMemDC;				//�޸� DC
		HBITMAP		hBit;				//��Ʈ��(���ο� ��Ʈ�� �ڵ�)
		HBITMAP		hOBit;				//�õ� ��Ʈ��(���� ��Ʈ�� �ڵ�)
		int			width;				//�̹��� ����ũ��
		float		x;					//�̹��� X��ǥ
		float		y;					//�̹��� Y��ǥ
		int			height;				//�̹��� ����ũ��
		BYTE		loadType;			//�ε�Ÿ��
		int			currentFrameX;		//���� ������ X
		int			currentFrameY;		//���� ������ Y
		int			maxFrameX;			//�ִ� X������ ����
		int			maxFrameY;			//�ִ� Y������ ����
		int			frameWidth;			//1������ ���α���
		int			frameHeight;		//1������ ���α���


		tagImage()
		{
			resID =				0;
			hMemDC =			NULL;
			hBit =				NULL;
			hOBit =				NULL;
			x =					0;
			y =					0;
			currentFrameX =		0;
			currentFrameY=		0;
			maxFrameX =			0;
			maxFrameY=			0;
			frameWidth=			0;
			frameHeight=		0;
			width =				0;
			height =			0;
			loadType =			LOAD_RESOURCE;
		}
	}IMAGE_INFO, *LPIMAGE_INFO;
	image();
	~image();

private:
	LPIMAGE_INFO	_imageInfo;			//�̹��� ����
	char*			_fileName;			//�̹��� �̸�
	bool			_isTrans;			//���� ��������?
	COLORREF		_transColor;		//���� ���� RGB

	//���Ŀ�
	BLENDFUNCTION   _blendFunc;			//���ĺ��带 ���� ����
	LPIMAGE_INFO	_blendImage;		//���ĺ��带 ����ϱ� ���� �̹��� ����

public:

	//��Ʈ�� �ʱ�ȭ
	HRESULT init(int width, int height);
	HRESULT init(const char* fileName, int width, int height, bool isTrans = false, COLORREF transColor = RGB(255, 0, 255));

	//������ �̹��� ���Ϸ� �ʱ�ȭ
	HRESULT init(const char* fileName, int width, int height, int frameX, int frameY, bool isTrans = false, COLORREF transColor = RGB(255, 0, 255));
	HRESULT init(const char* fileName,int x, int y, int width, int height, int frameX, int frameY, bool isTrans = false, COLORREF transColor = RGB(255, 0, 255));

	//��������
	void setTransColor(bool isTrans, COLORREF transColor);

	void release();

	//����(���� ������ ��ġ�� �̹��� ���)
	void render(HDC hdc);
	void render(HDC hdc, int destX, int destY);
	void render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

	//������ ����
	void frameRender(HDC hdc, int destX, int destY);
	void frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

	//��������
								   //������ų����
	void loopRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY);
	void loopAlphaRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY, BYTE alpha);

	//���ķ���
	void alphaRender(HDC hdc, BYTE alpha);
	void alphaRender(HDC hdc, int destX, int destY, BYTE alpha);
	void alphaRender(HDC hdc,int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);

	//DC�� �����Ͷ�.
	inline HDC getMemDC() { return _imageInfo->hMemDC; }


	//======�̹��� ������ ���� �ϱ� ����======//
	//�̹��� X��ǥ ���
	inline float getX() { return _imageInfo->x; }
	inline void setX(float x) {_imageInfo->x = x;}

	//�̹��� Y��ǥ ���
	inline float getY() { return _imageInfo->y; }
	inline void setY(float y) { _imageInfo->y = y; }


	//�̹��� ���� ��ǥ ����

	inline void setCenter(float x, float y)
	{
		_imageInfo->x = x - (_imageInfo->width / 2);
		_imageInfo->y = y - (_imageInfo->height / 2);
	}
	//���μ��� ũ�� ���
	inline int getWidth() { return _imageInfo->width; }
	inline int getHeight() { return _imageInfo->height; }

	//�ٿ�� �ڽ�(�浹��)
	inline RECT getBoundingBox() 
	{
		RECT rc = RectMakeCenter(_imageInfo->x, _imageInfo->y, _imageInfo->width, _imageInfo->height);

		return rc;
	}
	//������ X����
	inline int getFrameX() { return _imageInfo->currentFrameX; }
	inline void setFrameX(int frameX)
	{
		_imageInfo->currentFrameX = frameX;

		if (frameX > _imageInfo->maxFrameX)
		{
			_imageInfo->currentFrameX = _imageInfo->maxFrameX;
		}
	}
	//������ Y����
	inline int getFrameY() { return _imageInfo->currentFrameY; }
	inline void setFrameY(int frameY)
	{
		_imageInfo->currentFrameY = frameY;

		if (frameY > _imageInfo->maxFrameY)
		{
			_imageInfo->currentFrameY = _imageInfo->maxFrameY;
		}
	}

	//1������ ���μ��� ũ�� ���
	inline int getFrameWidth() { return _imageInfo->frameWidth; }
	inline int getFrameHeight() { return _imageInfo->frameHeight;}

	//�ƽ� ������ X,y
	inline int getMaxFrameX() { return _imageInfo->maxFrameX; }
	inline int getMaxFrameY() { return _imageInfo->maxFrameY; }

};

