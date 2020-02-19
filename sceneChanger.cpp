#include "stdafx.h"
#include "sceneChanger.h"

sceneChanger::sceneChanger()
{
}

sceneChanger::~sceneChanger()
{
}

HRESULT sceneChanger::init()
{
	_sceneFunc.addScene();	// ¾ÀÀ» Ãß°¡ ÇÑ´Ù.
	_sceneFunc.changeScene("Stage1");	// Ã³À½ ½ÃÀÛÇÒ ¾ÀÀ» °ñ¶óÁØ´Ù.

	return S_OK;
}

void sceneChanger::release()
{
}

void sceneChanger::update()
{
	_sceneFunc.TEST_SceneChange();
	SCENEMANAGER->update();
}

void sceneChanger::render()
{
	SCENEMANAGER->render();
}
