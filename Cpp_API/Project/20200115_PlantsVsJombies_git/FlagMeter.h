#pragma once
#include "gameNode.h"
class FlagMeter : public gameNode
{
private:
	image * _imgFull;
	image * _imgEmpty;
	image * _imgFlag;
	image * _imgHead;
	RECT _rect;
	int _width, _height;
	// �÷��׹��Ͱ� �����̱� ���� ����
	float _currentWidth;
	float _maxGauge;
	float _currentGauge;
	RECT _headRect;
	int _headWidth;
	int _flagmeterCount;
	int _flagmeterDelay;
protected:
	// �÷��׹��� ��Ʈ��
	void run_flagmeter();
	void move_flagmeter();
	// �÷��׹��� �ʱ�ȭ
	void init_flagmeter();
public:
	// ���� ������ ������ �ѱ��.
	float get_currentGauge() { return _currentGauge; }
	//����׸� ���� �Լ�
	void show_rect();
public:
	FlagMeter();
	~FlagMeter();
	HRESULT init();
	void release();
	void update();
	void render();
};

