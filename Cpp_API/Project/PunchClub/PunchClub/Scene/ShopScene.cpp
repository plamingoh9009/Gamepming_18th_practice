#include "stdafx.h"
#include "ShopScene.h"

HRESULT ShopScene::init()
{
	return S_OK;
}

void ShopScene::release()
{
}

void ShopScene::update()
{
}

void ShopScene::render()
{
	TextOut(get_memDC(), WINSIZEX * 0.5, WINSIZEY * 0.5,
		"500��", strlen("500��"));
}

ShopScene::ShopScene()
{
}
ShopScene::~ShopScene()
{
}
