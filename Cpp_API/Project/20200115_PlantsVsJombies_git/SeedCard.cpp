#include "stdafx.h"
#include "SeedCard.h"

RECT SeedCard::get_oneFrameRect()
{
	return _oneFrameRect;
}
RECT SeedCard::make_oneFrameRect()
{
	int x = _rect.left;
	int y = _rect.top;
	int width = _img->getFrameWidth();
	int height = _img->getFrameHeight();
	RECT oneFrameRect = RectMake(x, y, width, height);
	return oneFrameRect;
}
void SeedCard::show_oneFrameRect()
{
	Rectangle(getMemDC(), _oneFrameRect.left, _oneFrameRect.top,
		_oneFrameRect.right, _oneFrameRect.bottom);
}

void SeedCard::init_plantImage()
{
	//SunFlower
	IMAGEMANAGER->addImage("SunFlower_Disable",
		"images/ui/SunFlower_Disable.bmp", 27, 27, false, COLOR_MAGENTA);
	IMAGEMANAGER->addImage("SunFlower_Enable",
		"images/ui/SunFlower_Enable.bmp", 27, 27, false, COLOR_MAGENTA);
	//Wallnut
	IMAGEMANAGER->addImage("Wallnut_Disable",
		"images/ui/Wallnut_Disable.bmp", 26, 25, false, COLOR_MAGENTA);
	IMAGEMANAGER->addImage("Wallnut_Enable",
		"images/ui/Wallnut_Enable.bmp", 26, 25, false, COLOR_MAGENTA);
	//PeaShooter
	IMAGEMANAGER->addImage("PeaShooter_Disable",
		"images/ui/PeaShooter_Disable.bmp", 26, 27, false, COLOR_MAGENTA);
	IMAGEMANAGER->addImage("PeaShooter_Enable",
		"images/ui/PeaShooter_Enable.bmp", 26, 27, false, COLOR_MAGENTA);
}
void SeedCard::set_seedCard(string strKey, int x, int y)
{
	// ī�� 1���� �����Ѵ�.
	_type = strKey;
	_rect = RectMake(x, y, _width, _height);
	int initPlantImgX, initPlantImgY;
	// ī�� �̹��� ����
	if (strKey.compare("SunFlower") == 0)
	{
		_kindOfPlant = strKey.append("_Enable");
		initPlantImgX = 8;
		initPlantImgY = 12;
		_kindOfCardBack = "Rare";
		_plantImage = IMAGEMANAGER->findImage(_kindOfPlant);
	}
	else if (strKey.compare("Wallnut") == 0)
	{
		_kindOfPlant = strKey.append("_Enable");
		initPlantImgX = 8;
		initPlantImgY = 12;
		_kindOfCardBack = "Normal";
		_plantImage = IMAGEMANAGER->findImage(_kindOfPlant);
	}
	else if (strKey.compare("PeaShooter") == 0)
	{
		_kindOfPlant = strKey.append("_Enable");
		initPlantImgX = 8;
		initPlantImgY = 12;
		_kindOfCardBack = "Normal";
		_plantImage = IMAGEMANAGER->findImage(_kindOfPlant);
	}
	// ī�� �̹��� ��ġ ����
	_plantImage->setX((float)(_rect.left + initPlantImgX));
	_plantImage->setY((float)(_rect.top + initPlantImgY));

	// ī�� ��� �̹��� ����
	if (_kindOfCardBack.compare("Rare") == 0)
	{
		_currentFrameX = 1;
		_currentFrameY = 0;
	}
	//if: ����ī��� 2��° �̹���
	else if (_kindOfCardBack.compare("Normal") == 0)
	{
		_currentFrameX = 2;
		_currentFrameY = 0;
	}
	//if: �븻ī��� 3��° �̹���

	// ī�� �� ���� �簢���� �ʱ�ȭ
	_oneFrameRect = make_oneFrameRect();
}

SeedCard::SeedCard()
{
}
SeedCard::~SeedCard()
{
}

HRESULT SeedCard::init()
{
	_width = 450;
	_height = 70;
	_maxFrameX = 9;
	_maxFrameY = 1;
	_img = IMAGEMANAGER->addFrameImage("SeedCard", "images/SeedCard.bmp",
		_width, _height, _maxFrameX, _maxFrameY, false, COLOR_MAGENTA);
	// ī����� �Ĺ� �̹����� �ε��Ѵ�.
	init_plantImage();
	return S_OK;
}
void SeedCard::release()
{
	//delete_plantImage�� SeedBank Ŭ������ �ϰ� �ִ�.
	_img->release();
	_plantImage->release();
}
void SeedCard::update()
{
}
void SeedCard::render()
{
	// ī���� ����� ����
	IMAGEMANAGER->frameRender("SeedCard", getMemDC(),
		_rect.left, _rect.top, _currentFrameX, _currentFrameY);
	// ī���� �Ĺ��׸��� ����
	_plantImage->render(getMemDC(),
		(int)(_plantImage->getX()), (int)(_plantImage->getY()));
}
