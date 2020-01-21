#include "stdafx.h"
#include "Stage.h"
void Stage::update_clickedUi()
{
	if (_ui->get_fClickCard() == true &&
		_ui->get_fBuyCard() == true)
	{
		_objControl->set_fClickCard(true);
		_objControl->set_cardType(_ui->get_cardType());
		_ui->set_fClickCard(false);
		_ui->set_fBuyCard(false);
	}
	else if (_ui->get_fClickStage() == true)
	{
		_objControl->set_fClickStage(true);
		_ui->set_fClickStage(false);
	}
}
void Stage::update_uiToObjControl()
{
	//�õ�ī���� ��Ʈ ���� �ѱ��.
	_objControl->set_cardRects(_ui->get_cardRects());
	_objControl->set_itCardRects(_ui->get_itCardRects());
	// ���� ���� ��Ʈ ���͸� �ѱ��.
	_objControl->set_mapSpaces(_ui->get_mapSpaces());
	_objControl->set_itMapSpaces(_ui->get_itMapSpaces());
	// ���� ���� ��Ʈ ���͸� �ѱ��.
	_objControl->set_mapLines(_ui->get_mapLines());
	_objControl->set_itMapLines(_ui->get_itMapLines());
	// ���� ������ ������ �ѱ��.
	if (_ui->is_passOverGauge() == true)
	{
		_objControl->set_currentGauge(_ui->get_currentGauge());
		_ui->set_fPassOverGauge(false);
	}
}
void Stage::update_objControlToUi()
{
	// �عٶ�� ������ �Ѱ��ش�.
	_ui->update_sunflowerInfo(
		_objControl->get_sunflowerCount(),
		_objControl->get_newSunflowerCount());
	_objControl->set_newSunflowerCount(0);
}
Stage::Stage()
{
}
Stage::~Stage()
{
}
HRESULT Stage::init()
{
	_objControl = new ObjectControl;
	_objControl->init();
	_ui = new UI;
	_ui->init();
	return S_OK;
}
void Stage::release()
{
	_ui->release();
	_objControl->release();
}
void Stage::update()
{
	_ui->update();
	update_clickedUi();
	update_uiToObjControl();
	_objControl->update();
	update_objControlToUi();
}
void Stage::render()
{
	_ui->render();
	_objControl->render();
}
