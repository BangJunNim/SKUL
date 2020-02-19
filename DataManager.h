#pragma once
#include "singletonBase.h"
#include "mapTool_Library.h"


class DataManager : public singletonBase<DataManager>
{
private:
	vector<tagTileInfo>			_tileList;								// Ÿ�ϸ� ������ ��´�.
	tagMapInfo					_mapInfo;								// ���� ������ ��´�.
	vector<tagSaveBackGround>	_vMapInfo[BACKGROUND_LAYER_COUNT];		// ���� ����� ��´�.



public:
	DataManager();		// ������
	~DataManager();		// �Ҹ���

	HRESULT init();
	void release();
	void update();

	// �������������������������������������������������������������������������������������������������� �� �Լ� ��������������������������������������������������������������������������������������������������������������������

	// �Ű������� �ִ� ���� ������ map ���Ϸ� ����ų�, map ������ �Ű������� �ִ´�.
	void map_Save(vector<tagTileInfo> tileList, tagMapInfo* mapInfo, vector<tagSaveBackGround>* vMapInfo);	// ���� �����Ѵ�. (�Ű����� : Ÿ�ϸ���Ʈ, �� ����)
	void map_Load(vector<tagTileInfo>* tileList, tagMapInfo* mapInfo, vector<tagSaveBackGround>* vMapInfo);	// ���� �ҷ��´�. (�Ű����� : Ÿ�ϸ���Ʈ �ּ�, �� ����) (Ÿ�ϸ���Ʈ�� �ּҰ� �ʿ��� ������ �� ������ ���� �־���� �ϱ� ������)

	// �Ű������� �ִ� ������ �׸���.
	void map_Render(HDC getMemDC, vector<tagTileInfo>* tileList, tagMapInfo mapInfo, vector<tagSaveBackGround>* vMapInfo);	// ���� �׷��ش�. (�Ű����� : ������ ����ִ� ������)
	void map_Render(HDC getMemDC, vector<tagTileInfo>* tileList, tagMapInfo mapInfo, vector<tagSaveBackGround>* vMapInfo,	// ���� �׷��ְ�, ���������ش�. (�Ű����� : �ӵ����� ����ִ� �迭5��)
		short loopSpd[]);

	// ������ �Ŵ����� �ִ� ������ ���� �����Ѵ�.
	void map_Load_Datamanager(string mapName, string mapInfoName);											// ���� �����͸Ŵ����� �����Ѵ�. (�Ű����� : ���̸�)

	// ������ �Ŵ����� �ִ� ������ ���� ����Ѵ�.
	void map_Render_Datamanager(HDC getMemDC);																// ���� �׷��ش�. (������ �Ŵ����� ����Ǿ� �ִ� ���� �׸���)
	void map_Render_Datamanager(HDC getMemDC, short loopSpd[]);												// ���� �׷��ְ�, ���������ش�. (�Ű����� : �ӵ����� ����ִ� �迭 5��)

	// ������ �Ŵ����� ���� �Ǿ� �ִ� ������ �̿��� ��Ʈ ���
	void Rect_Render_Datamanager(HDC getMemDC);

	// ������ �Ŵ��� ���� ����
	vector<tagTileInfo>* set_TileList() { return &_tileList; }												// Ÿ�ϸ� ���� �ּ�

	// ������ �Ŵ��� ���� ����
	vector<tagTileInfo> get_TileList() { return _tileList; }												// Ÿ�ϸ� ����


	// �������������������������������������������������������������������������������������������������� �浹üũ ���������������������������������������������������������������������������������������������������������������������
	
	bool Collision_Player_Ground();																			// �÷��̾� �Ʒ� Ÿ�Ͽ� ���� �ִ��� üũ
	bool Collision_Player_Wall();																			// �÷��̾ �ٶ󺸴� ���⿡ ���� �ִ��� üũ
	bool Collision_Player_Trab();																			// �÷��̾��� ��Ʈ�� ���� ��Ʈ�� �浹 �ߴ��� üũ

};

