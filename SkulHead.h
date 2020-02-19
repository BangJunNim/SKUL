#pragma once
#include "gameNode.h"

class Skul;

class SkulHead
{
	image* headImage;
	Skul* body;
	int directionTemp;

public:
	SkulHead(Skul* body);
	virtual ~SkulHead();

	virtual void Excute();
	virtual void Enter();
	virtual void Exit();

	virtual void Idle();
	virtual void Move();
	virtual void Dash();
	virtual void Jump();
	virtual void Fall();
	virtual void Attack();
	virtual void Skill1();
	virtual void Skill2();
	virtual void SkillSwap();

	virtual void LerpMoving(); // 대쉬 러프 사용 

private:

};

class LittleBone : public SkulHead
{
public:
	LittleBone(Skul* body);

	virtual void Enter();
	virtual void Exit();

	virtual void Idle();
	virtual void Move();
	virtual void Dash();
	virtual void Jump();
	virtual void Attack();
	virtual void Skill1();
	virtual void Skill2();
	virtual void SkillSwap();
};