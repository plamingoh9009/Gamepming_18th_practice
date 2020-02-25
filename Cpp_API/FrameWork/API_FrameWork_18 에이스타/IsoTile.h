#pragma once
//ũ��
#define CELL_WIDTH 100
#define CELL_HEIGHT 50

#define RADIUS_WIDTH (CELL_WIDTH / 2)
#define RADIUS_HEIGHT (CELL_HEIGHT / 2)
//�ʱ���ǥ
#define INIT_X 400
#define INIT_Y 20
//Ÿ�� ����
#define TILE_COUNT_X 20
#define TILE_COUNT_Y 20

//Ÿ�� �̹���
#define TILE_SIZE_X 8
#define TILE_SIZE_Y 10


#define TILE_MAX 10
enum TILEKIND
{
	TILEKIND_OBJECT,
	TILEKIND_TERRAIN,
	TILEKIND_NONE
};

struct TagTile
{
	int left, top;

	int index;

	int tileNum[TILE_MAX];
	TILEKIND tileKind[TILE_MAX];
	POINT tilePos[TILE_MAX];


	int height;
};