#pragma once
#include "Base/GameNode.h"
class Scene : public GameNode
{
protected:
	string _imgPath = "Images/";
	// ����� ��带 ���� ����
	bool _fDebug = false;
protected:
	void update_checkDebugMode();
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	Scene();
	~Scene();
public:
	// append: "Images/[append]"
	void set_imgPath(string append = "");
};

