#include "stdafx.h"
#include "Skul.h"
#include "SkulHead.h"


Skul::Skul(int X, int Y)
{
	SKULDATA->ReSet(); //  스컬 처음 초기화 

	SKULDATA->X = X;
	SKULDATA->Y = Y;
}


Skul::~Skul()
{
}

HRESULT Skul::init()
{
	// 스컬 헤드 대쉬 구현했으니깐 테스트 해봐야댐;
	currentHead = new SkulHead(this);

	return S_OK;
}

void Skul::release()
{
}

void Skul::update()
{
	currentHead->Excute();
}

void Skul::render()
{
	string SkulIdle;
	SkulIdle = SKULDATA->aniKey;
	IMAGEMANAGER->findImage(SKULDATA->imageKey)->aniRender(getMemDC(), SKULDATA->X - CAMERAMANAGER->Use_Func()->get_CameraXY().x,
	SKULDATA->Y - CAMERAMANAGER->Use_Func()->get_CameraXY().y, KEYANIMANAGER->findAnimation(SKULDATA->aniKey));
}
