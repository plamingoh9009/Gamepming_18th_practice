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
	// ���⼭ Ÿ�� ���͸� �����.
	typedef vector<Tile*> vTiles;
private:
	// �� Ÿ�� ����
	vTiles _sampleTiles;
	vTiles _tiles;
	// ���� ���� Ÿ���� ������� �¾� �Ҷ� ����.
	string _currentTileType;
	// ���̺�, �ε��Ҷ� ���� ����
	TileInfo * _tileInfos;
	DWORD _saveBuffer;
	int _saveTileCount;
	// ���̺�, �ε��ư �����Ҷ� ���� ����
	RECT _saveRect;
	RECT _loadRect;
	// ���带 �׸���.
	RECT _boardRect;
protected:
	// Ÿ�� ������ ����� �Լ�
	void setup_tileInfos();
	void load_tilesFromTileInfo();
	void init_board();
	void draw_board();
	// ���̺�, �ε� �ʱ�ȭ
	void init_buttons();
	void draw_buttons();
	// ���Ⱑ �������� �ƴ��� �Ǵ��ϴ� �Լ�
	bool is_board();
	bool is_sampleTiles();
	void init_sampleTiles();
	void delete_sampleTiles();
	void draw_sampleTiles();
	// Ÿ�� 1�� ����
	void make_tile(string type, int x, int y, bool isCenter);
	void delete_tilesAll();
	void draw_tiles();
	// ���� Ÿ�� ����
	void setup_tile();
public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(/*HDC hdc*/);//�׸��°�

	void save();
	void load();
};

