#include "stdafx.h"
#include "SeedBank.h"

map<string, SeedCard*> SeedBank::get_seedCards()
{
	return map<string, SeedCard*>(_seedCards);
}
map<string, SeedCard*>::iterator SeedBank::get_itSeedCards()
{
	return map<string, SeedCard*>::iterator(_itSeedCards);
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
	for (;_itSeedCards != _seedCards.end(); _itSeedCards++)
	{
		_itSeedCards->second->render();
	}
}
void SeedBank::init_seedCards()
{
	SeedCard * seedCard;
	int size = _plantName.size();
	for (int i = 0;i < size;i++)
	{
		seedCard = new SeedCard;
		seedCard->init();
		seedCard->set_seedCard(_plantName[i], 
			_space[i].left, _space[i].top);
		// 여기서 맵에 insert
		_seedCards.insert(
			make_pair(_plantName[i], seedCard)
		);
		seedCard = nullptr;
	}
}
void SeedBank::delete_seedCards()
{
	_itSeedCards = _seedCards.begin();
	for (;_itSeedCards != _seedCards.end();)
	{
		_itSeedCards->second->release();
		_seedCards.erase(_itSeedCards++);
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
	// 시드뱅크 이미지를 초기화
	_rect = RectMake(20, 0, 446, 87);
	_img = IMAGEMANAGER->addImage("SeedBank", "images/SeedBank.bmp",
		_rect.right - _rect.left, _rect.bottom - _rect.top,
		false, COLOR_MAGENTA);
	// 시드뱅크 렉트를 초기화
	init_space();
	// 식물 이름 벡터를 초기화
	init_plantName();
	// 시드카드 벡터를 초기화
	init_seedCards();
	return S_OK;
}
void SeedBank::release()
{
	IMAGEMANAGER->deleteImage("SeedBank");
	// 식물이름 벡터를 삭제
	delete_plantName();
	delete_plantImage();
	// 시드카드 벡터를 릴리즈
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
	}//else: tab 키를 누르지 않았을 때, 시드뱅크를 렌더
}
