#pragma once
#include"gameNode.h"
/*
	�־��� ��������� ��ǥ������ ���� �ִ� ��θ� ã�Ƴ��� �׷��� �˰��� �߿� �ϳ���.
	F=G+H
	F = ���(���������� ���� �� ��� ������� �̵��ϴ� �ɸ� ���� �������� ��ħ)
	G =�簢������ ���� ���ο� �簢�� ������ �̵����
	H = �簢�� ���κ��� ���������������� �����̵����
	(�밢�� �̵��� �ƴ� ���μ��� �̵��� ���� ������� ���, ��ֹ��� ���� ��Ҵ� ������� �ʴ´�.)

	���ۿ��� :  ���������� �̵��� �� �ִ� ������ ���¸���Ʈ�� �߰���.
	��ġ�� �ٽ� Ȯ���� �ʿ䰡 ���� ������ Ŭ���� ����Ʈ�� �߰�
	���� ����Ʈ���� ���� ����� ���� ��ġ�� ���� ��ġ�� ����(�� F�� ������)
	�� ������ �ݺ��Ѵ�.
	F���� �����ϴٸ� �ӵ����� �������� ���¸���Ʈ�� �� �ʰ� �߰� �Ȱ��� �����ϴ� ���� ������.
*/
#define TILE_X 20	//���� Ÿ�ϼ�
#define TILE_Y 20	//���� Ÿ�� ��
#define WIDTH 35		//Ÿ�� ���� ����
#define HEIGHT 35		//Ÿ�� ���α���
#define BIGNUM 5000		//�ʱⰪ(F)

//Ÿ�� �Ӽ�
enum TILE_TYPE
{
	TILE_TYPE_EMPTY,		//��Ÿ��(�������� �ִ� ��)
	TILE_TYPE_START,		//��������
	TILE_TYPE_END,			//������
	TILE_TYPE_WALL			//��
};
enum ASTAR_STATE
{
	ASTAR_STATE_SEARCHING,	//�˻���
	ASTAR_STATE_FOUND,		//�߰�!
	ASTAR_STATE_NOWAY,		//�����
	ASTAR_STATE_END
};

struct aStarTile
{
	RECT rc;
	COLORREF color;
	bool walkable;			//�������� �ִ��� ����
	bool listOn;			//openlist�� �߰� �Ǿ����� ����
	int i, j;
	int F, G, H;
	char str[128];
	aStarTile* parent;	//�θ� Ÿ�� �ּ�
	TILE_TYPE type;		//Ÿ�� �Ӽ�
};
class aStar :  public gameNode
{
private:

	aStarTile _tile[TILE_X][TILE_Y];
	vector<aStarTile*> _openList;
	vector<aStarTile*> _closeList;

	ASTAR_STATE _astarState;
	TILE_TYPE _selectType;				//Ÿ�� ��ġ�Ҷ� ����� �Ӽ�
	COLORREF _selectedTypeColor;

	int _startX, _startY;			//���������� i,j�ε���
	int _endX, _endY;			//���������� i,j�ε���
	int _lastIndex;				//���߿� �߰��� Ŭ���� ����Ʈ�� �ε���

	bool _startPointSet;			//���������� ��ġ �Ǿ���
	bool _endPointSet;				//���������� ��ġ �Ǿ���

	int Ci;
	int Cj;
	int Cg;

	RECT rc[6];
	HBRUSH newBrush, oldBrush;
	HFONT newFont, oldFont;


public:
	aStar();
	~aStar();

	HRESULT init();
	void release();
	void update();
	void render();


	void tileComposition();//��ġ
	void tileInitializing();	//��ġ�� �Ӽ��� �°� Ÿ�� �ʱ�ȭ
	void addOpenList();			//���� ����Ʈ �߰�
	void calculateH();			//���� ����Ʈ�� Ÿ�� H�����
	void calculateF();			//���� ����Ʈ�� Ÿ�� F�����
	void addCloseList();		//���� ���� F������ Ŭ���� ����Ʈ�� �߰�
	void checkArrive();			//�����ߴ��� ���� üũ
	void showWay(aStarTile* tile);//������ ���������� ���������� �մ� ��� ��������


};

