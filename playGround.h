#pragma once
#include "gameNode.h"
#include "sceneChanger.h"
#include "addImage.h"



#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

class playGround : public gameNode
{
private:
	sceneChanger*	_sceneChanger;	// �� ��ȯ�� ����Ѵ�.

	tagAddImage		_addImage;	// �̹����� �߰� �Ѵ�. (���߿� �ε������� �̵� �ؾ��Ѵ�)
	
	RECT MousePointer;


public:
	playGround();
	~playGround();

	virtual HRESULT init(); 
	virtual void release();
	virtual void update();
	virtual void render();

};
