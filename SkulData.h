#pragma once
//#include "SkulHead.h"
#include "singletonBase.h"


//스컬의 절대 변하지 않는 값 
#define SKULLSPEED 8		// 이동속도
#define JUMPPOWER 10		// 점프
#define GRAVITY	  0.9f		// 중력
#define HEADTHROWSPEED 10	// 머리 던지는 속도 
#define DASHLIMIT 2			// 대쉬 횟수 제한
#define DASHDISTANCE 180.f  // 대쉬 거리
#define BaseHp	100			// 기본 체력
#define DashCoolTime  50	// 대쉬 쿨탐 


enum Direction
{
	DirectionLeft,
	DirectionRight
};

struct BoolSet
{
	bool isJump;			// 점프 체크 
	bool Headhave;			// 머리 가지고 있는지 . 
	bool AniCheck;		// 달리는 이미지 넣었는지 체크함. 
	bool isDash;		// 대쉬 이미지 들어가졌는지 체크 
	bool Moving;		// 무빙 
};

//
struct SkulDash
{
	short Dash;				
	short MaxDash;			// 최대 대쉬 횟수 

	SkulDash()
		:Dash(DashCoolTime), MaxDash(DASHLIMIT) {}

};

// 스컬의 기본 정보가 되어 줄 클래스 
class SkulInfo : public singletonBase<SkulInfo>
{
	
public:
	RECT Rc;				// 렉트 렉트렉트 
	image*	Image;			// 이미지 등록
	animation*	Ani;		// 프레임 이미지 애니메이션
	string imageKey;
	string aniKey;
	SkulDash DashData;			// 대쉬 구조체  변수 
	BoolSet bSet;			// bool 값  모여잇는 구조체 
	Direction dir;

	int Power;				// 공격력
	int X, Y;				// 플레이어 위치
	int Count;				// 시간 카운트 
	int Hp;					// 체력
	float Time;				// 갱신 될 때  
	float Distance; 		// 가야하는 거리  
	float WorldTimeCount;	// 러프 사용 하고 싶다. 

	void ReSet()
	{
		// 이미지 관련 초기화
		imageKey = "";
		aniKey = "";
		//bool 관련 초기화 
		bSet.Headhave = 0;
		bSet.isJump = 0;
		bSet.AniCheck = 0;
		bSet.isDash = 0;
		bSet.Moving = 0;
		
		// 기본 플렝어 셋팅 
		Power = 0;
		Count = 0;
		Hp = BaseHp;
		Time = 0.1f;  //  이동 시간 무브 이동하는 시간! 
		Distance = 0;
		WorldTimeCount = 0.0f;
	}
	int getDashCoolTime()
	{
		return DashCoolTime;
	}
};



