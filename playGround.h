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
	sceneChanger*	_sceneChanger;	// 씬 전환을 담당한다.

	tagAddImage		_addImage;	// 이미지를 추가 한다. (나중에 로딩씬으로 이동 해야한다)
	
	RECT MousePointer;


public:
	playGround();
	~playGround();

	virtual HRESULT init(); 
	virtual void release();
	virtual void update();
	virtual void render();

};
