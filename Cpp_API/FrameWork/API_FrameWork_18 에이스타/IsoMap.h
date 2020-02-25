#pragma once
#include"gameNode.h"
#include"IsoTile.h"
class IsoMap : public gameNode
{
private:

	TagTile _tileMap[TILE_COUNT_X][TILE_COUNT_Y];

	int _isoX, _isoY;
	int _center;
	char str[128];


	int _startX;
	int _startY;

	POINT imageFrame;
	CTRL _currentCTRL;


	bool _isDebug;
public:
	IsoMap();
	~IsoMap();

	HRESULT init();
	void release();
	void update();
	void render();

	//Ÿ�ϸ� �׸���.
	void DrawTileMap();

	//������ �׸���
	void DrawRhombus(int left, int top);
	//�ڳʰ���(1~4�и�)
	int GetCornerIndex(int isoX, int isoY);

	//������ �ȿ� ����?
	bool IsInRhombus(int corner, int isoX, int isoY);

	void MapToolSetup();
	void setMap(int isoX, int isoY, bool isAdd);
	TILEKIND kindSelect(int frameX, int frameY);


	void TlieInit();
	void Load();
	void Save();

};

