#pragma once
#include "gameNode.h"

#define TILESIZE 32

#define TILEX 20	//���� Ÿ�� ����
#define TILEY 20	//���� Ÿ�� ����

#define TILESIZEX TILESIZE * TILEX	//640 32 * 20
#define TILESIZEY TILESIZE * TILEY	//640 32 * 20

//Ÿ�ϼ� ����
#define SAMPLETILEX 20
#define SAMPLETILEY 9

//����
enum TERRAIN
{
	TR_CEMENT, TR_DESERT, TR_GRASS, TR_WATER, TR_END
};

//������Ʈ
enum OBJECT
{
	OBJ_BLOCK1, OBJ_BLOCK3, OBJ_BLOCKS,
	OBJ_FLAG1, OBJ_FLAG2,
	OBJ_TANK1, OBJ_TANK2,
	OBJ_NONE
};

//������
enum POS
{
	POS_FLAG1, POS_FLAG2, POS_TANK1, POS_TANK2
};

//Ÿ�� ���� ���� ����ü
struct tagTile
{
	TERRAIN		terrain;
	OBJECT		obj;
	RECT		rc;
	int			terrainFrameX;
	int			terrainFrameY;
	int			objFrameX;
	int			objFrameY;
};

//Ÿ�ϼ� ���� ���� ����ü
struct tagSampleTile
{
	RECT rcTile;
	int terrainFrameX;
	int terrainFrameY;
};

//���� Ÿ�� �޾ƿ� ����ü
struct tagCurrentTile
{
	int x;
	int y;
};

class playGround : public gameNode
{
private:
	HWND _btnSave;
	HWND _btnLoad;
	HWND _btnTerrainDraw;
	HWND _btnObjectDraw;
	HWND _btnEraser;

	tagCurrentTile _currentTile;
	tagSampleTile _sampleTile[SAMPLETILEX * SAMPLETILEY];
	tagTile _tiles[TILEX * TILEY];

	int _pos[2];

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void setup();
	virtual void setMap();

	virtual void save();
	virtual void load();

	TERRAIN terrainSelect(int frameX, int frameY);
	OBJECT objSelect(int frameX, int frameY);
	
};

