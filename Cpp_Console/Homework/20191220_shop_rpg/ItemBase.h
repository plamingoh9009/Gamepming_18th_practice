#pragma once
#include <map>

#include "GameBase.h"
#include "Item.h"

// 아이템 목록의 데이터 타입을 쉽게 재정의 한다.
typedef map<string, Item> itemList_t;

/*
ItemBase Class:
아이템 베이스 클래스는 게임 베이스를 상속 받는다.
아이템 클래스를 include 해서, 아이템 이름을 키 값으로 받는 map itemList_t 
타입을 제공한다.
method
virtual void show_itemList(itemList_t):
	이 함수는 아이템 리스트를 받아서 무기, 방어구, 장신구 형태로 출력하는 함수다.
	아이템 리스트가 비어있는지는 확인하지 않기 때문에 매개변수를 넘기기 전에
	비었는지 확인하고 넘기는 것이 올바른 사용법이다.
virtual itemList_t download_itemList():
	ItemBase가 제공하는 _mItem_temp에 있는 값을 내려받는 함수다.
virtual upload itemList(iteList_t):
	ItemBase가 제공하는 _mItem_temp에 값을 업로드하는 함수다.
*/
class ItemBase : public GameBase
{
protected:
	virtual void show_itemList(itemList_t, PAGE_CHOICE);
public:
	ItemBase();
	~ItemBase();
};

