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
		"500¿ø", strlen("500¿ø"));
}

ShopScene::ShopScene()
{
}
ShopScene::~ShopScene()
{
}
