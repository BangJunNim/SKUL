#include "stdafx.h"
#include "SkulHead.h"
#include "Skul.h"

SkulHead::SkulHead(Skul * body)
	:headImage(nullptr), body(nullptr), directionTemp(0)
{
	Enter();
}

SkulHead::~SkulHead()
{
}

// 설정
void SkulHead::Enter()
{
	SkillSwap();
	SKULDATA->dir = DirectionRight;
	SKULDATA->Image = IMAGEMANAGER->findImage("Littleborn");
	SKULDATA->Ani = KEYANIMANAGER->findAnimation("LittlebornIdleR");

	SKULDATA->imageKey = "Littleborn";
	SKULDATA->aniKey = "LittlebornIdleR";

	SKULDATA->Ani->start();

}
// 실행 
void SkulHead::Excute()
{
	// 렉트 이미지 크기에 맞게 그림. 
	SKULDATA->Rc = RectMake(SKULDATA->X, SKULDATA->Y, SKULDATA->Image->getWidth(), SKULDATA->Image->getHeight());
	

	if (SKULDATA->dir == DirectionRight)
	{
		directionTemp = +1;
	}
	else
	{
		directionTemp = -1;
	}
	// Dash ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
	if (KEYMANAGER->isOnceKeyDown('Z')) 
	{
		SKULDATA->bSet.isDash = false;

		if (SKULDATA->DashData.Dash < SKULDATA->DashData.MaxDash)
		{
			SKULDATA->bSet.Moving = true;
			SKULDATA->Count = 0;
			SKULDATA->DashData.Dash++;

			SKULDATA->WorldTimeCount = TIMEMANAGER->getWorldTime();//
			Dash();
			
		}
	}
	else
	{
		SKULDATA->Count++;
		if (SKULDATA->Count >= SKULDATA->getDashCoolTime())
		{
			if (SKULDATA->DashData.Dash > 0)
			{
				SKULDATA->DashData.Dash--;
			}
		}
	}

	//Attack ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
	if (KEYMANAGER->isOnceKeyDown('x'))
	{
		Attack();
	}

	//jump ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
	if (KEYMANAGER->isOnceKeyDown('c')) 
	{
		Jump();
	}

	//skill1 ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
	if (KEYMANAGER->isOnceKeyDown('a')) 
	{
		Skill1();
	}

	//skill2 ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
	if (KEYMANAGER->isOnceKeyDown('s'))
	{
		Skill2();
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		SKULDATA->dir = DirectionLeft;
		Move();
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{

		SKULDATA->dir = DirectionRight;
		Move();
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		SKULDATA->bSet.AniCheck = false;
		Idle();
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		SKULDATA->bSet.AniCheck = false;
		Idle();
	}
	

	LerpMoving();
	CAMERAMANAGER->Use_Func()->set_CameraXY(SKULDATA->X, SKULDATA->Y, true);
}


// 종료
void SkulHead::Exit()
{

}

void SkulHead::Idle()
{

	if (SKULDATA->dir == DirectionLeft)
	{
		SKULDATA->Image = IMAGEMANAGER->findImage("Littleborn");
		SKULDATA->Ani = KEYANIMANAGER->findAnimation("LittlebornIdleL");

		SKULDATA->imageKey = "Littleborn";
		SKULDATA->aniKey = "LittlebornIdleL";

		SKULDATA->Ani->start();

	}
	else if (SKULDATA->dir == DirectionRight)
	{
		SKULDATA->Image = IMAGEMANAGER->findImage("Littleborn");
		SKULDATA->Ani = KEYANIMANAGER->findAnimation("LittlebornIdleR");

		SKULDATA->imageKey = "Littleborn";
		SKULDATA->aniKey = "LittlebornIdleR";

		SKULDATA->Ani->start();
	}
}

void SkulHead::Move()
{
	if (SKULDATA->dir == DirectionLeft)
	{
		if (!SKULDATA->bSet.AniCheck)
		{
			SKULDATA->Image = IMAGEMANAGER->findImage("LittlebornWalk");
			SKULDATA->Ani = KEYANIMANAGER->findAnimation("LittlebornWalkL");
			SKULDATA->imageKey = "LittlebornWalk";
			SKULDATA->aniKey = "LittlebornWalkL";
			SKULDATA->Ani->start();
			SKULDATA->bSet.AniCheck = true;
		}
			SKULDATA->X -= SKULLSPEED;
	}

	else if (SKULDATA->dir == DirectionRight)
	{
		if (!SKULDATA->bSet.AniCheck)
		{
			SKULDATA->Image = IMAGEMANAGER->findImage("LittlebornWalk");
			SKULDATA->Ani = KEYANIMANAGER->findAnimation("LittlebornWalkR");
			SKULDATA->imageKey = "LittlebornWalk";
			SKULDATA->aniKey = "LittlebornWalkR";
			SKULDATA->Ani->start();
			SKULDATA->bSet.AniCheck = true;
		}
		SKULDATA->X += SKULLSPEED;
	}
	if (KEYMANAGER->isOnceKeyDown('Z')) // Dash
	{
		Dash();
	} 

}

void SkulHead::Dash()
{

	if (SKULDATA->dir == DirectionLeft)
	{
		if (!SKULDATA->bSet.isDash)
		{
			SKULDATA->Image = IMAGEMANAGER->findImage("LittIebornDash");
			SKULDATA->Ani = KEYANIMANAGER->findAnimation("LittlebornDashL");
			SKULDATA->imageKey = "LittIebornDash";
			SKULDATA->aniKey = "LittlebornDashL";
			SKULDATA->Ani->start();
			SKULDATA->bSet.isDash = true;
		}
	}

	if (SKULDATA->dir == DirectionRight)
	{
		if (!SKULDATA->bSet.isDash)
		{
			SKULDATA->Image = IMAGEMANAGER->findImage("LittIebornDash");
			SKULDATA->Ani = KEYANIMANAGER->findAnimation("LittlebornDashR");
			SKULDATA->imageKey = "LittIebornDash";
			SKULDATA->aniKey = "LittlebornDashR";
			SKULDATA->Ani->start();
			SKULDATA->bSet.isDash = true;
		}
	}
	
}

void SkulHead::Jump()
{
	// SKULDATA->Y = SKULDATA->Y - JUMPPOWER;
}

void SkulHead::Fall()
{
}

void SkulHead::Attack()
{
}

void SkulHead::Skill1()
{
}

void SkulHead::Skill2()
{
}

void SkulHead::SkillSwap()
{
}

//러프 사용한다 사용한다 사용한다!!!!!!
void SkulHead::LerpMoving()
{
	if (!SKULDATA->bSet.Moving) return;

	SKULDATA->Distance = (SKULDATA->X - CAMERAMANAGER->Use_Func()->get_CameraXY().x) + (DASHDISTANCE * directionTemp);

	float elapsedTime = TIMEMANAGER->getElapsedTime();
	// 거리 도달 
	float moveSpeed = (elapsedTime / SKULDATA->Time) * DASHDISTANCE;

	float angle = 0;
	if (SKULDATA->dir == DirectionRight)
	{
		angle = 0;
	}
	if (SKULDATA->dir == DirectionLeft)
	{
		angle = 3.14f;
	}
	
	SKULDATA->X += cosf(angle) * moveSpeed; // v

	if (SKULDATA->Time + SKULDATA->WorldTimeCount <= TIMEMANAGER->getWorldTime())
	{
		SKULDATA->WorldTimeCount = TIMEMANAGER->getWorldTime();

		SKULDATA->bSet.Moving = false;

		SKULDATA->bSet.isDash = false;
		Idle();

		
	}
}




