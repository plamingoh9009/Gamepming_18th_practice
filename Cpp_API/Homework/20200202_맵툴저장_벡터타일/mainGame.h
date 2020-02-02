#pragma once
#include"gameNode.h"
#include "Tile.h"
struct TileInfo
{
	RECT rc;
	string type;
};
class mainGame :  public gameNode
{
private:
	// 여기서 타일 벡터를 만든다.
	typedef vector<Tile*> vTiles;
private:
	// 내 타일 벡터
	vTiles _sampleTiles;
	vTiles _tiles;
	// 현재 무슨 타일을 골랐는지 셋업 할때 쓴다.
	string _currentTileType;
	// 세이브, 로드할때 쓰는 변수
	TileInfo * _tileInfos;
	DWORD _saveBuffer;
	int _saveTileCount;
	// 세이브, 로드버튼 렌더할때 쓰는 변수
	RECT _saveRect;
	RECT _loadRect;
	// 보드를 그린다.
	RECT _boardRect;
protected:
	// 타일 정보를 만드는 함수
	void setup_tileInfos();
	void load_tilesFromTileInfo();
	void init_board();
	void draw_board();
	// 세이브, 로드 초기화
	void init_buttons();
	void draw_buttons();
	// 여기가 보드인지 아닌지 판단하는 함수
	bool is_board();
	bool is_sampleTiles();
	void init_sampleTiles();
	void delete_sampleTiles();
	void draw_sampleTiles();
	// 타일 1개 생성
	void make_tile(string type, int x, int y, bool isCenter);
	void delete_tilesAll();
	void draw_tiles();
	// 현재 타일 셋팅
	void setup_tile();
public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//초기화
	virtual void release();//해제
	virtual void update();//연산하는곳
	virtual void render(/*HDC hdc*/);//그리는곳

	void save();
	void load();
};

