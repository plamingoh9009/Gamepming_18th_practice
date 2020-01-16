#include "stdafx.h"
#include "SeedBank.h"

vector<SeedCard*> SeedBank::get_seedCards()
{
	return vector<SeedCard*>(_seedCards);
}
vector<SeedCard*>::iterator SeedBank::get_itSeedCards()
{
	return vector<SeedCard*>::iterator(_itSeedCards);
}

void SeedBank::delete_plantImage()
{
	IMAGEMANAGER->deleteImage("SunFlower_Disable");
	IMAGEMANAGER->deleteImage("SunFlower_Enable");
	IMAGEMANAGER->deleteImage("Wallnut_Disable");
	IMAGEMANAGER->deleteImage("Wallnut_Enable");
	IMAGEMANAGER->deleteImage("PeaShooter_Disable");
	IMAGEMANAGER->deleteImage("PeaShooter_Enable");
}
void SeedBank::init_plantName()
{
	_plantName.push_back("SunFlower");
	_plantName.push_back("PeaShooter");
	_plantName.push_back("Wallnut");
}
void SeedBank::delete_plantName()
{
	_itPlantName = _plantName.begin();
	for (;_itPlantName != _plantName.end();)
	{
		_itPlantName = _plantName.erase(_itPlantName);
	}
	_plantName.clear();
}

void SeedBank::draw_seedCards()
{
	_itSeedCards = _seedCards.begin();
	for (;_itSeedCards != _seedCards.end();_itSeedCards++)
	{
		(*_itSeedCards)->render();
	}
}
void SeedBank::init_seedCards()
{
	for (int i = 0; i < _plantName.size(); i++)
	{
		_seedCards.push_back(new SeedCard);
	}

	for (int i = 0;i < _plantName.size(); i++)
	{
		_seedCards[i]->init();
		_seedCards[i]->set_seedCard(_plantName[i],
			_space[i].left, _space[i].top);
	}
}
void SeedBank::delete_seedCards()
{
	_itSeedCards = _seedCards.begin();
	for (; _itSeedCards != _seedCards.end();)
	{
		(*_itSeedCards)->release();
		_itSeedCards = _seedCards.erase(_itSeedCards);
	}
	_seedCards.clear();
}
void SeedBank::show_space()
{
	for (int i = 0; i < 6; i++)
	{
		Rectangle(getMemDC(), _space[i].left, _space[i].top,
			_space[i].right, _space[i].bottom);
	}
}
void SeedBank::init_space()
{
	int seedCardWidth = 50;
	int seedCardHeight = 70;
	int blankWidth = (int)(seedCardWidth * 0.192);
	int initX = 78 + _rect.left + (int)(blankWidth * 0.5);
	int initY = 8 + _rect.top;
	int currentX, currentY;

	currentY = initY;
	currentX = initX;
	for (int i = 0; i < 6; i++)
	{
		_space[i] = RectMake(currentX, currentY,
			seedCardWidth, seedCardHeight);
		currentX = currentX + seedCardWidth + blankWidth;
	}
}

SeedBank::SeedBank()
{
}
SeedBank::~SeedBank()
{
}

HRESULT SeedBank::init()
{
	// �õ��ũ �̹����� �ʱ�ȭ
	_rect = RectMake(20, 0, 446, 87);
	_img = IMAGEMANAGER->addImage("SeedBank", "images/SeedBank.bmp",
		_rect.right - _rect.left, _rect.bottom - _rect.top,
		false, COLOR_MAGENTA);
	// �õ��ũ ��Ʈ�� �ʱ�ȭ
	init_space();
	// �Ĺ� �̸� ���͸� �ʱ�ȭ
	init_plantName();
	// �õ�ī�� ���͸� �ʱ�ȭ
	init_seedCards();
	return S_OK;
}
void SeedBank::release()
{
	IMAGEMANAGER->deleteImage("SeedBank");
	// �Ĺ��̸� ���͸� ����
	delete_plantName();
	delete_plantImage();
	// �õ�ī�� ���͸� ������
	IMAGEMANAGER->deleteImage("SeedCard");
	delete_seedCards();
}
void SeedBank::update()
{
}
void SeedBank::render()
{
	if (KEYMANAGER->isToggleKey(VK_TAB)) {}
	else
	{
		IMAGEMANAGER->render("SeedBank", getMemDC(), _rect.left, _rect.top);
		draw_seedCards();
	}//else: tab Ű�� ������ �ʾ��� ��, �õ��ũ�� ����
}
