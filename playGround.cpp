#include "stdafx.h"
#include "playGround.h"

playGround::playGround()
{
}

playGround::~playGround()
{
}

HRESULT playGround::init()
{
	
	gameNode::init(true);
	ShowCursor(false);
	_addImage.addImage_Func();			// 이미지를 추가한다. (나중에 로딩씬에서 처리 해야한다.)

	_sceneChanger = new sceneChanger;	// 동적할당	
	_sceneChanger->init();				// 기본 셋팅 초기화


	return S_OK;
}


void playGround::release()
{
	gameNode::release();
	_sceneChanger->release();	

}


void playGround::update()
{
	gameNode::update();

	RECT MousePoint;
	MousePointer.left = _ptMouse.x;
	MousePointer.top = _ptMouse.y;
	MousePointer.right = 42;
	MousePointer.bottom = 42;
	RectMake(MousePointer.left, MousePointer.top, MousePointer.right, MousePointer.bottom);



	_sceneChanger->update();	// 씬 체인저 업데이트
	KEYANIMANAGER->update();
}

void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, CAMERAMANAGER->Use_Func()->get_World_Size().x, CAMERAMANAGER->Use_Func()->get_World_Size().y, WHITENESS);
	//==========================================================	

	_sceneChanger->render();

	//cout << TIMEMANAGER->getWorldTime() << endl;

	IMAGEMANAGER->findImage("MousePointer")->render(getMemDC(), MousePointer.left, MousePointer.top);

	//===========================================================
	_backBuffer->render(getHDC(), 0, 0);
}