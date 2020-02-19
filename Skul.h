#pragma once
#include "gameNode.h"
#include "SkulData.h"

class SkulHead;

class Skul : public gameNode
{
private:
	SkulHead* currentHead;
public:
	Skul(int X, int Y);
	~Skul();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

private:

};
