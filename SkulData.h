#pragma once
//#include "SkulHead.h"
#include "singletonBase.h"


//������ ���� ������ �ʴ� �� 
#define SKULLSPEED 8		// �̵��ӵ�
#define JUMPPOWER 10		// ����
#define GRAVITY	  0.9f		// �߷�
#define HEADTHROWSPEED 10	// �Ӹ� ������ �ӵ� 
#define DASHLIMIT 2			// �뽬 Ƚ�� ����
#define DASHDISTANCE 180.f  // �뽬 �Ÿ�
#define BaseHp	100			// �⺻ ü��
#define DashCoolTime  50	// �뽬 ��Ž 


enum Direction
{
	DirectionLeft,
	DirectionRight
};

struct BoolSet
{
	bool isJump;			// ���� üũ 
	bool Headhave;			// �Ӹ� ������ �ִ��� . 
	bool AniCheck;		// �޸��� �̹��� �־����� üũ��. 
	bool isDash;		// �뽬 �̹��� �������� üũ 
	bool Moving;		// ���� 
};

//
struct SkulDash
{
	short Dash;				
	short MaxDash;			// �ִ� �뽬 Ƚ�� 

	SkulDash()
		:Dash(DashCoolTime), MaxDash(DASHLIMIT) {}

};

// ������ �⺻ ������ �Ǿ� �� Ŭ���� 
class SkulInfo : public singletonBase<SkulInfo>
{
	
public:
	RECT Rc;				// ��Ʈ ��Ʈ��Ʈ 
	image*	Image;			// �̹��� ���
	animation*	Ani;		// ������ �̹��� �ִϸ��̼�
	string imageKey;
	string aniKey;
	SkulDash DashData;			// �뽬 ����ü  ���� 
	BoolSet bSet;			// bool ��  ���մ� ����ü 
	Direction dir;

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
		bSet.AniCheck = 0;
		bSet.isDash = 0;
		bSet.Moving = 0;
		
		// �⺻ �÷��� ���� 
		Power = 0;
		Count = 0;
		Hp = BaseHp;
		Time = 0.1f;  //  �̵� �ð� ���� �̵��ϴ� �ð�! 
		Distance = 0;
		WorldTimeCount = 0.0f;
	}
	int getDashCoolTime()
	{
		return DashCoolTime;
	}
};



