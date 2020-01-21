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
	// 플래그미터가 움직이기 위한 변수
	float _currentWidth;
	float _maxGauge;
	float _currentGauge;
	RECT _headRect;
	int _headWidth;
	int _flagmeterCount;
	int _flagmeterDelay;
protected:
	// 플래그미터 컨트롤
	void run_flagmeter();
	void move_flagmeter();
	// 플래그미터 초기화
	void init_flagmeter();
public:
	// 현재 게이지 정보를 넘긴다.
	float get_currentGauge() { return _currentGauge; }
	//디버그를 위한 함수
	void show_rect();
public:
	FlagMeter();
	~FlagMeter();
	HRESULT init();
	void release();
	void update();
	void render();
};

