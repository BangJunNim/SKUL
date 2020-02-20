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
	
	// 방향 
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
		SKULDATA->bSet.AniDash = false;

		if (SKULDATA->DashData.Dash < SKULDATA->DashData.MaxDash)
		{
			SKULDATA->bSet.Moving = true; // 러프 
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
	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		Attack();
	}

	//jump ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
	if (KEYMANAGER->isOnceKeyDown('C')) 
	{
		SKULDATA->bSet.AniJump = false;
		SKULDATA->bSet.isJump = true;
	
	

		/*else
		{
			SKULDATA->bSet.isJump = false;
			SKULDATA->bSet.isFall = true;
			Fall();
		}*/
		
	}
	// 점프 중이니까 true값 
	if (SKULDATA->bSet.isJump)
	{
		/*	SKULDATA->Y -= JUMPPOWER;

			if (SKULDATA->Y > 0)
			{
				SKULDATA->Y -= SKULDATA->JumpData.JumpPower;
			}

			if (SKULDATA->Y > FALLMAXSPEED)
			{
				SKULDATA->Y += SKULDATA->JumpData.Gravity;
			}*/
		Jump();
	}

	//skill1 ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
	if (KEYMANAGER->isOnceKeyDown('A')) 
	{
		Skill1();
	}

	//skill2 ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
	if (KEYMANAGER->isOnceKeyDown('S'))
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
	/*if (KEYMANAGER->isOnceKeyUp('C'))  
	{
		Fall();
	}*/

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
	if (KEYMANAGER->isOnceKeyDown('C')) // Jump
	{
		Jump();
	}
}

void SkulHead::Dash()
{

	if (SKULDATA->dir == DirectionLeft)
	{
		if (!SKULDATA->bSet.AniDash)
		{
			SKULDATA->Image = IMAGEMANAGER->findImage("LittIebornDash");
			SKULDATA->Ani = KEYANIMANAGER->findAnimation("LittlebornDashL");
			SKULDATA->imageKey = "LittIebornDash";
			SKULDATA->aniKey = "LittlebornDashL";
			SKULDATA->Ani->start();
			SKULDATA->bSet.AniDash = true;
		}
	}

	if (SKULDATA->dir == DirectionRight)
	{
		if (!SKULDATA->bSet.AniDash)
		{
			SKULDATA->Image = IMAGEMANAGER->findImage("LittIebornDash");
			SKULDATA->Ani = KEYANIMANAGER->findAnimation("LittlebornDashR");
			SKULDATA->imageKey = "LittIebornDash";
			SKULDATA->aniKey = "LittlebornDashR";
			SKULDATA->Ani->start();
			SKULDATA->bSet.AniDash = true;
		}
	}
}

void SkulHead::Jump()
{
	if (SKULDATA->dir == DirectionLeft)
	{
		if (!SKULDATA->bSet.AniJump)
		{
			SKULDATA->Image = IMAGEMANAGER->findImage("LittIebornJump");
			SKULDATA->Ani = KEYANIMANAGER->findAnimation("LittlebornJumpL");
			SKULDATA->imageKey = "LittIebornJump";
			SKULDATA->aniKey = "LittlebornJumpL";
			SKULDATA->Ani->start();
			SKULDATA->bSet.AniJump = true;
		}
		SKULDATA->Y -= SKULDATA->JumpData.JumpPower;
		SKULDATA->JumpData.JumpPower -= SKULDATA->JumpData.Gravity;
	}

	if (SKULDATA->dir == DirectionRight)
	{
		if (!SKULDATA->bSet.AniJump)
		{
			SKULDATA->Image = IMAGEMANAGER->findImage("LittIebornJump");
			SKULDATA->Ani = KEYANIMANAGER->findAnimation("LittlebornJumpR");
			SKULDATA->imageKey = "LittIebornJump";
			SKULDATA->aniKey = "LittlebornJumpR";
			SKULDATA->Ani->start();
			SKULDATA->bSet.AniJump = true;
		}
		SKULDATA->Y -= SKULDATA->JumpData.JumpPower;
		SKULDATA->JumpData.JumpPower -= SKULDATA->JumpData.Gravity;
	}
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

		// 대쉬 끝났을 때 이미지들  다시 재생 
		SKULDATA->bSet.Moving = false;
		SKULDATA->bSet.AniCheck = false;
		SKULDATA->bSet.AniDash = false;
		Idle();
	}
}




