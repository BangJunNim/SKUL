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
	_addImage.addImage_Func();			// �̹����� �߰��Ѵ�. (���߿� �ε������� ó�� �ؾ��Ѵ�.)

	_sceneChanger = new sceneChanger;	// �����Ҵ�	
	_sceneChanger->init();				// �⺻ ���� �ʱ�ȭ


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



	_sceneChanger->update();	// �� ü���� ������Ʈ
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