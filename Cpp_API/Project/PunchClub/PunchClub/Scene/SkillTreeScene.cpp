#include "stdafx.h"
#include "SkillTreeScene.h"


HRESULT SkillTreeScene::init()
{
	return S_OK;
}
void SkillTreeScene::release()
{
}
void SkillTreeScene::update()
{
}
void SkillTreeScene::render()
{
	TextOut(get_memDC(), WIN_HALF_W, WIN_HALF_H, "��ų ������", strlen("��ų ������"));
}
SkillTreeScene::SkillTreeScene()
{
}
SkillTreeScene::~SkillTreeScene()
{
}
