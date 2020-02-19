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
	player = new Skul(WINSIZEX / 2.f, WINSIZEY / 2.f);
	player->init();
	return S_OK;
}

void InGameScene::release()
{
}

void InGameScene::update()
{
	player->update();
}

void InGameScene::render()
{
	DATAMANAGER->map_Render_Datamanager(getMemDC());
	player->render();
}
