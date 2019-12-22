#pragma once
#include <map>

#include "GameBase.h"
#include "Item.h"

// ������ ����� ������ Ÿ���� ���� ������ �Ѵ�.
typedef map<string, Item> itemList_t;

/*
ItemBase Class:
������ ���̽� Ŭ������ ���� ���̽��� ��� �޴´�.
������ Ŭ������ include �ؼ�, ������ �̸��� Ű ������ �޴� map itemList_t 
Ÿ���� �����Ѵ�.
method
virtual void show_itemList(itemList_t):
	�� �Լ��� ������ ����Ʈ�� �޾Ƽ� ����, ��, ��ű� ���·� ����ϴ� �Լ���.
	������ ����Ʈ�� ����ִ����� Ȯ������ �ʱ� ������ �Ű������� �ѱ�� ����
	������� Ȯ���ϰ� �ѱ�� ���� �ùٸ� �����̴�.
virtual itemList_t download_itemList():
	ItemBase�� �����ϴ� _mItem_temp�� �ִ� ���� �����޴� �Լ���.
virtual upload itemList(iteList_t):
	ItemBase�� �����ϴ� _mItem_temp�� ���� ���ε��ϴ� �Լ���.
*/
class ItemBase : public GameBase
{
protected:
	virtual void show_itemList(itemList_t, PAGE_CHOICE);
public:
	ItemBase();
	~ItemBase();
};

