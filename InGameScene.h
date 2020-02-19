#pragma once
#include "gameNode.h"
#include "NormalSkul.h"

class Skul;

class InGameScene	: public gameNode
{
private:

	//NormalSkul* Skul;

	Skul* player;

public:
	InGameScene();
	~InGameScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

