#pragma once
#include "stdafx.h"
#include "mapTool.h"
#include "InGameScene.h"
class tagSceneFunc	// scene �Լ��� ��Ƶ� Ŭ����
{
public:
	// �� �߰��� ���ִ� �Լ�
	void addScene()
	{
		SCENEMANAGER->addScene("mapTool", new mapTool);
		SCENEMANAGER->addScene("Stage1", new InGameScene);
	}

	// �� ü������ ���ִ� �Լ�
	// �Ű����� : ��ü���� �ּ�, ���ϴ� �� ����
	void changeScene(string sceneName)
	{
		// �޾ƿ� �� ������ �̿��Ͽ� �� ü����
		SCENEMANAGER->changeScene(sceneName);
	}

	// [�׽�Ʈ] ���� �� ��ȯ �Լ�
	void TEST_SceneChange()
	{
		if (KEYMANAGER->isOnceKeyDown(VK_F1))
		{
			// ���� ������ �̵��Ѵ�.
			SCENEMANAGER->changeScene("mapTool");
		}
		if (KEYMANAGER->isOnceKeyDown(VK_F2))
		{
			// ���� ������ �̵��Ѵ�.
			SCENEMANAGER->changeScene("Stage1");
		}
	}
};
