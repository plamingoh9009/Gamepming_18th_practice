#pragma once
/*
 1.BMP :  제약이 많지만 무손실 무압축이므로 속도가 가장 빠르다.
 2.JPG : 손실압축이므로 원래 가진 이미지의 손실이 일어나는 대신
 압축이되어 용량이 작다.
 3.PNG: 1,2과 달리 alpha채널이 없다.
*/
class image
{
public:
	enum IMAGE_LOAD_KIND
	{
		LOAD_RESOURCE = 0,	//리소스로딩
		LOAD_FILE,			//파일로딩
		LOAD_EMPTY,			//빈 비트맵 파일
		LOAD_END
	};

	typedef struct tagImage
	{
		DWORD		resID;				//리소스 ID
		HDC			hMemDC;				//메모리 DC
		HBITMAP		hBit;				//비트맵(새로운 비트맵 핸들)
		HBITMAP		hOBit;				//올드 비트맵(기존 비트맵 핸들)
		int			width;				//이미지 가로크기
		LONG		x;					//이미지 X좌표
		LONG		y;					//이미지 Y좌표
		int			height;				//이미지 세로크기
		BYTE		loadType;			//로드타입
		int			currentFrameX;		//현재 프레임 X
		int			currentFrameY;		//현재 프레임 Y
		int			maxFrameX;			//최대 X프레임 갯수
		int			maxFrameY;			//최대 Y프레임 갯수
		int			frameWidth;			//1프레임 가로길이
		int			frameHeight;		//1프레임 세로길이


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
	LPIMAGE_INFO	_imageInfo;			//이미지 정보
	char*			_fileName;			//이미지 이름
	bool			_isTrans;			//배경색 날릴꺼냐?
	COLORREF		_transColor;		//배경색 날릴 RGB


public:

	//비트맵 초기화
	HRESULT init(int width, int height);
	HRESULT init(const char* fileName, int width, int height, 
		bool isTrans = false, COLORREF transColor = RGB(255, 0, 255));

	//프레임 이미지 파일로 초기화
	HRESULT init(const char* fileName, int width, int height, 
		int frameX, int frameY, bool isTrans = false, COLORREF transColor = RGB(255, 0, 255));
	HRESULT init(const char* fileName,int x, int y, 
		int width, int height, int frameX, int frameY, bool isTrans = false, COLORREF transColor = RGB(255, 0, 255));

	//투명값셋팅
	void setTransColor(bool isTrans, COLORREF transColor);

	void release();

	//렌더(내가 지정한 위치에 이미지 출력)
	void render(HDC hdc);
	void render(HDC hdc, int destX, int destY);
	void render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

	//프레임 렌더

	void frameRender(HDC hdc, LONG destX, LONG destY);
	void frameRender(HDC hdc, LONG destX, LONG destY, LONG currentFrameX, LONG currentFrameY);


	//DC를 가져와라.
	inline HDC getMemDC() { return _imageInfo->hMemDC; }


	//======이미지 조작을 쉽게 하기 위해======//
	//이미지 X좌표 얻기
	inline LONG getX() { return _imageInfo->x; }
	inline void setX(LONG x) {_imageInfo->x = x;}

	//이미지 Y좌표 얻기
	inline LONG getY() { return _imageInfo->y; }
	inline void setY(LONG y) { _imageInfo->y = y; }


	//이미지 센터 좌표 셋팅

	inline void setCenter(LONG x, LONG y)
	{
		_imageInfo->x = x - (_imageInfo->width / 2);
		_imageInfo->y = y - (_imageInfo->height / 2);
	}
	//가로세로 크기 얻기
	inline int getWidth() { return _imageInfo->width; }
	inline int getHeight() { return _imageInfo->height; }

	//바운딩 박스(충돌용)
	inline RECT getBoundingBox() 
	{
		RECT rc = RectMakeCenter(_imageInfo->x, _imageInfo->y, _imageInfo->width, _imageInfo->height);

		return rc;
	}
	//프레임 X셋팅
	inline int getFrameX() { return _imageInfo->currentFrameX; }
	inline void setFrameX(int frameX)
	{
		_imageInfo->currentFrameX = frameX;

		if (frameX > _imageInfo->maxFrameX)
		{
			_imageInfo->currentFrameX = _imageInfo->maxFrameX;
		}
	}
	//프레임 Y셋팅
	inline int getFrameY() { return _imageInfo->currentFrameY; }
	inline void setFrameY(int frameY)
	{
		_imageInfo->currentFrameY = frameY;

		if (frameY > _imageInfo->maxFrameY)
		{
			_imageInfo->currentFrameY = _imageInfo->maxFrameY;
		}
	}

	//1프레임 가로세로 크기 얻기
	inline int getFrameWidth() { return _imageInfo->frameWidth; }
	inline int getFrameHeight() { return _imageInfo->frameHeight;}

	//맥스 프레임 X,y
	inline int getMaxFrameX() { return _imageInfo->maxFrameX; }
	inline int getMaxFrameY() { return _imageInfo->maxFrameY; }

};

