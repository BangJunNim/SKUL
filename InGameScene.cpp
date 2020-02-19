#include "stdafx.h"
#include "InGameScene.h"
#include "Skul.h"


InGameScene::InGameScene()
{
}


InGameScene::~InGameScene()
{
}

HRESULT InGameScene::init()
{
	DATAMANAGER->map_Load_Datamanager("tutorial.map", "tutorial_Info.map");
	DATAMANAGER->Make_Skul();
	player = DATAMANAGER->skuladdless();
	return S_OK;
}

void InGameScene::release()
{
}

void InGameScene::update()
{
//	player->update();
	DATAMANAGER->update();
}
void InGameScene::render()
{
	DATAMANAGER->map_Render_Datamanager(getMemDC());
	player->render();
	
}
