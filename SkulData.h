#pragma once
//#include "SkulHead.h"
#include "singletonBase.h"


//������ ���� ������ �ʴ� �� 
#define SKULLSPEED 8		// �̵��ӵ�
#define JUMPPOWER 10.0f		// ����
#define JUMPCOUNT 2			// ����Ƚ�� 
#define GRAVITY	  0.05f		// �߷�
#define SaveJump  0         // ���� ����� 
#define FALLMAXSPEED -30.0f	// �ִ� �߶� �ӵ� 
#define HEADTHROWSPEED 10	// �Ӹ� ������ �ӵ� 
#define DASHLIMIT 2			// �뽬 Ƚ�� ����
#define DASHDISTANCE 180.f  // �뽬 �Ÿ�
#define BASEHP	100			// �⺻ ü��
#define DashCoolTime  50	// �뽬 ��Ž 


enum Direction
{
	DirectionLeft,
	DirectionRight
};

struct BoolSet
{
	// ���� Ȯ�� 
	bool isJump;		// ���� üũ 
	bool isFall;		// �������� ���� üũ 
	bool Headhave;		// �Ӹ� ������ �ִ��� . 
	bool Moving;		// ����	

	// �ִ� �̹��� 
	bool AniCheck;		// �޸��� �̹��� �־����� üũ��. 
	bool AniDash;		// �뽬 �̹��� �������� üũ 
	bool AniJump;		// ���� �ϴ� �̹��� 
	bool AniFall;		// �������� �̹��� 
};

//
struct SkulDash
{
	short Dash;				
	short MaxDash;			// �ִ� �뽬 Ƚ�� 

	SkulDash()
		:Dash(DashCoolTime), MaxDash(DASHLIMIT) {}

};

struct SkulJump
{
	short MaxJump;			// �ִ� ���� Ƚ��
	short SaveCount;		// ���� ���Ҵ��� ����� 
	float JumpPower;		// ���� �Ŀ� 
	float Gravity;			// �߷°�

	SkulJump()
		: MaxJump(1), JumpPower(JUMPPOWER), Gravity(GRAVITY), SaveCount() {}
};

// ������ �⺻ ������ �Ǿ� �� Ŭ���� 
class SkulInfo : public singletonBase<SkulInfo>
{
	
public:
	RECT Rc;				// ��Ʈ ��Ʈ��Ʈ 
	image*	Image;			// �̹��� ���
	animation*	Ani;		// ������ �̹��� �ִϸ��̼�
	string imageKey;		// Ű������ �̹��� �ҷ��� 
	string aniKey;			// Ű������ �̹��� �ҷ��� 
	SkulDash DashData;		// �뽬 ����ü  ���� 
	BoolSet bSet;			// bool ��  ���մ� ����ü 
	Direction dir;			// ����
	SkulJump JumpData;		// ���� ���� ������ 

	int Power;				// ���ݷ�
	int X, Y;				// �÷��̾� ��ġ
	int Count;				// �ð� ī��Ʈ 
	int Hp;					// ü��

	float Time;				// ���� �� ��  
	float Distance; 		// �����ϴ� �Ÿ�  
	float WorldTimeCount;	// ���� ��� �ϰ� �ʹ�. 

	void ReSet()
	{
		// �̹��� ���� �ʱ�ȭ
		imageKey = "";
		aniKey = "";
		//bool ���� �ʱ�ȭ 
		bSet.Headhave = 0;
		bSet.isJump = 0;
		bSet.Moving = 0;
		bSet.AniCheck = 0;
		bSet.AniDash = 0;
		bSet.AniJump = 0;
		
		// �⺻ �÷��� ���� 
		Power = 0;
		Count = 0;
		Hp = BASEHP;
		Time = 0.1f;  //  �̵� �ð� ���� �̵��ϴ� �ð�! 
		Distance = 0;
		WorldTimeCount = 0.0f;
	}
	int getDashCoolTime()
	{
		return DashCoolTime;
	}
};



