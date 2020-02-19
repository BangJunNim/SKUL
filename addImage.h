#pragma once
#include "stdafx.h"

struct tagAddImage
{
	
	// �̹����� Ű������ �߰��ϴ� �Լ�
	void addImage_Func()
	{
		// back Ground <�ӽ�>
		IMAGEMANAGER->addImage("base_MapTool_BG", "./image/mapTool/backGround/base_MapTool_BG.bmp", 1600, 960, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("tutorial_BG_0", "./image/mapTool/backGround/tutorial/tutorial_BG_0.bmp", 2304, 1920, false, RGB(0, 0, 0));
		IMAGEMANAGER->addImage("tutorial_BG_1", "./image/mapTool/backGround/tutorial/tutorial_BG_1.bmp", 2304, 1920, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("tutorial_BG_2", "./image/mapTool/backGround/tutorial/tutorial_BG_2.bmp", 2304, 1920, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("stage1_BG_0", "./image/mapTool/backGround/stage_1/stage1_BG_0.bmp", 2304, 1920, false, RGB(0, 0, 0));
		IMAGEMANAGER->addImage("stage1_BG_1", "./image/mapTool/backGround/stage_1/stage1_BG_1.bmp", 2304, 1920, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("stage1_BG_2", "./image/mapTool/backGround/stage_1/stage1_BG_2.bmp", 2304, 1920, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("intro_BG_0", "./image/mapTool/backGround/intro/intro_BG_0.bmp", 3392, 960, false, RGB(0, 0, 0));
		IMAGEMANAGER->addImage("intro_BG_1", "./image/mapTool/backGround/intro/intro_BG_1.bmp", 3392, 960, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("intro_BG_2", "./image/mapTool/backGround/intro/intro_BG_2.bmp", 3392, 960, true, RGB(255, 0, 255));
	
		// tile Rect Image
		IMAGEMANAGER->addImage("tile_Rect", "./image/Tile_Rect.bmp", 64, 64, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("tile_Rect_200", "./image/Tile_Rect_200.bmp", 200, 200, true, RGB(255, 0, 255));

		// mapTool Icon
		IMAGEMANAGER->addImage("save_Icon", "./image/mapTool/icon/BT_Save.bmp", 52, 52, true, RGB(255, 0, 255));									// ���̺� ������
		IMAGEMANAGER->addImage("load_Icon", "./image/mapTool/icon/BT_Load.bmp", 52, 52, true, RGB(255, 0, 255));									// �ε� ������
		IMAGEMANAGER->addImage("eraser_Icon", "./image/mapTool/icon/BT_Eraser.bmp", 52, 52, true, RGB(255, 0, 255));								// ���찳 ������
		IMAGEMANAGER->addImage("ground_Icon", "./image/mapTool/icon/BT_Tile.bmp", 52, 52, true, RGB(255, 0, 255));									// ���� ������
		IMAGEMANAGER->addImage("ground_E_Icon", "./image/mapTool/icon/BT_Tile_E.bmp", 52, 52, true, RGB(255, 0, 255));								// ���� ���찳 ������
		IMAGEMANAGER->addImage("decoration_Icon", "./image/mapTool/icon/BT_Decoration.bmp", 52, 52, true, RGB(255, 0, 255));						// ���ڷ��̼� ������
		IMAGEMANAGER->addImage("decoration_E_Icon", "./image/mapTool/icon/BT_Decoration_E.bmp", 52, 52, true, RGB(255, 0, 255));					// ���ڷ��̼� ���찳 ������
		IMAGEMANAGER->addImage("hit_Object_Icon", "./image/mapTool/icon/BT_Hit_Object.bmp", 52, 52, true, RGB(255, 0, 255));						// �ı� ������Ʈ ������
		IMAGEMANAGER->addImage("hit_Object_E_Icon", "./image/mapTool/icon/BT_Hit_Object_E.bmp", 52, 52, true, RGB(255, 0, 255));					// �ı� ������Ʈ ���찳 ������
		IMAGEMANAGER->addImage("door_Icon", "./image/mapTool/icon/BT_Door.bmp", 52, 52, true, RGB(255, 0, 255));									// �� ������
		IMAGEMANAGER->addImage("door_E_Icon", "./image/mapTool/icon/BT_Door_E.bmp", 52, 52, true, RGB(255, 0, 255));								// �� ���찳 ������
		IMAGEMANAGER->addImage("character_Icon", "./image/mapTool/icon/BT_Character.bmp", 52, 52, true, RGB(255, 0, 255));							// ĳ���� ������
		IMAGEMANAGER->addImage("character_E_Icon", "./image/mapTool/icon/BT_Character_E.bmp", 52, 52, true, RGB(255, 0, 255));						// ĳ���� ���찳 ������
		IMAGEMANAGER->addImage("item_Icon", "./image/mapTool/icon/BT_Item.bmp", 52, 52, true, RGB(255, 0, 255));									// ������ ������
		IMAGEMANAGER->addImage("item_E_Icon", "./image/mapTool/icon/BT_Item_E.bmp", 52, 52, true, RGB(255, 0, 255));								// ������ ���찳 ������
		IMAGEMANAGER->addImage("trap_Icon", "./image/mapTool/icon/BT_Trap.bmp", 52, 52, true, RGB(255, 0, 255));									// ���� ������
		IMAGEMANAGER->addImage("trap_E_Icon", "./image/mapTool/icon/BT_Trap_E.bmp", 52, 52, true, RGB(255, 0, 255));								// ���� ���찳 ������
		IMAGEMANAGER->addImage("back_Ground_Icon", "./image/mapTool/icon/BT_BackGround.bmp", 52, 52, true, RGB(255, 0, 255));						// �� �׶��� ������
		IMAGEMANAGER->addImage("back_Ground_E_Icon", "./image/mapTool/icon/BT_BackGround_E.bmp", 52, 52, true, RGB(255, 0, 255));					// �� �׶��� ������
		IMAGEMANAGER->addImage("prev_Icon", "./image/mapTool/icon/leftArrow.bmp", 32, 30, true, RGB(255, 0, 255));									// ���� ������
		IMAGEMANAGER->addImage("next_Icon", "./image/mapTool/icon/rightArrow.bmp", 32, 30, true, RGB(255, 0, 255));									// ���� ������
		IMAGEMANAGER->addImage("up_Icon", "./image/mapTool/icon/UpArrow.bmp", 32, 30, true, RGB(255, 0, 255));										// �� ������
		IMAGEMANAGER->addImage("down_Icon", "./image/mapTool/icon/DownArrow.bmp", 32, 30, true, RGB(255, 0, 255));									// �ٿ� ������
		IMAGEMANAGER->addImage("back_Ground_Select", "./image/mapTool/icon/backGround_Select.bmp", 32, 32, true, RGB(255, 0, 255));					// �� �׶��� ���� ��ġ
		IMAGEMANAGER->addImage("back_Ground_Select_Pointer", "./image/mapTool/icon/backGround_Select_Pointer.bmp", 32, 32, true, RGB(255, 0, 255));	// �� �׶��� ���� ������
		IMAGEMANAGER->addImage("minus_Icon", "./image/mapTool/icon/Minus.bmp", 32, 30, true, RGB(255, 0, 255));										// ���̾� ���� ��ư
		IMAGEMANAGER->addImage("rect_Plus_Icon", "./image/mapTool/icon/BT_Rect_Plus.bmp", 52, 52, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("footHoldType_Check", "./image/mapTool/icon/FootHoldType_Check.bmp", 64, 64, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("wallType_Check", "./image/mapTool/icon/WallType_Check.bmp", 64, 64, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("trapType_Check", "./image/mapTool/icon/TrapType_Check.bmp", 64, 64, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("footHoldType_Check_Button", "./image/mapTool/icon/FootHoldType_Check_Button.bmp", 32, 30, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("wallType_Check_Button", "./image/mapTool/icon/WallType_Check_Button.bmp", 32, 30, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("trapType_Check_Button", "./image/mapTool/icon/TrapType_Check_Button.bmp", 32, 30, true, RGB(255, 0, 255));

		// mapTool <tile Pallet>
		IMAGEMANAGER->addFrameImage("tutorial_Tile", "./image/mapTool/tile/terrain_Tile/Tutorial_Tile.bmp", 576, 256, 9, 4, true, RGB(255, 0, 255));
		IMAGEMANAGER->addFrameImage("stage1_Tile", "./image/mapTool/tile/terrain_Tile/Stage1_Tile.bmp", 576, 256, 9, 4, true, RGB(255, 0, 255));
		IMAGEMANAGER->addFrameImage("stage2_Tile", "./image/mapTool/tile/terrain_Tile/Stage2_Tile.bmp", 576, 256, 9, 4, true, RGB(255, 0, 255));
		IMAGEMANAGER->addFrameImage("stage3_Tile", "./image/mapTool/tile/terrain_Tile/Stage3_Tile.bmp", 512, 320, 8, 5, true, RGB(255, 0, 255));
		IMAGEMANAGER->addFrameImage("startPoint_Tile", "./image/mapTool/tile/terrain_Tile/StartPoint_Tile.bmp", 512, 128, 8, 2, true, RGB(255, 0, 255));

		// mapTool <backGround Pallet>
		IMAGEMANAGER->addFrameImage("backGround_Pallet_0", "./image/mapTool/backGround/backGround_Img_0.bmp", 600, 600, 3, 3, true, RGB(255, 0, 255));

		// Mouse Pointer
		IMAGEMANAGER->addImage("MousePointer", "./image/MouseCursor.bmp", 42, 42, true, RGB(255, 0, 255));

		// Effact Image
		IMAGEMANAGER->addFrameImage("Smork", "./image/Effact/Smork.bmp", 2964, 58, 26, 1, true, RGB(255, 0, 255));		// �뽬 ����Ʈ 

		// skul Image adddddddddd  Ʃ�丮�� �̹��� 0 ~ 3 , �Ӹ� �ִ� ���� �̹��� 4 ~ 9 , �Ӹ� ���� ���� �̹��� 
		IMAGEMANAGER->addFrameImage("Littleborn", "./image/Skul/Idle/skul_Idle_NoWeapon.bmp", 640, 238, 4, 2, true, RGB(255, 0, 255));
		IMAGEMANAGER->addFrameImage("LittlebornWalk", "./image/skul/Walk/skul_Walk_NoWeapon.bmp", 1280, 238, 8, 2, true, RGB(255, 0, 255));
		IMAGEMANAGER->addFrameImage("LittIebornJump", "./image/skul/Jump/skul_Jump.bmp", 320, 238, 2, 2, true, RGB(255, 0, 255));
		IMAGEMANAGER->addFrameImage("LittIebornDash", "./image/skul/Dash/skul_Dash.bmp", 320, 238, 2, 2, true, RGB(255, 0, 255));
		IMAGEMANAGER->addFrameImage("SkulAttack", "./image/Skul/Attack/skul_Attack.bmp", 1440, 238, 9, 2, true, RGB(255, 0, 255));
		IMAGEMANAGER->addFrameImage("SkulFall", "./image/Skul/Fall/skul_Fall.bmp", 800, 238, 5, 2, true, RGB(255, 0, 255));
		IMAGEMANAGER->addFrameImage("SkulWeaponIdle", "./image/Skul/Idle/skul_Idle_HaveWeapon.bmp", 640, 238, 4, 2, true, RGB(255, 0, 255));
		IMAGEMANAGER->addFrameImage("SkulJumpAttack", "./image/Skul/Jump/skul_Jump_Attack.bmp", 640, 238, 4, 2, true, RGB(255, 0, 255));
		IMAGEMANAGER->addFrameImage("SkulSkill", "./image/Skul/Skill/skill.bmp", 640, 238, 4, 2, true, RGB(255, 0, 255));
		IMAGEMANAGER->addFrameImage("SkillWalk", "./image/skul/Walk/skul_Walk_Weapon.bmp", 1280, 238, 8, 2, true, RGB(255, 0, 255));


		// skul Ani addddddd  Right
		KEYANIMANAGER->addCoordinateFrameAnimation("LittlebornIdleR", "Littleborn", 0, 3, 5, false, true);  
		KEYANIMANAGER->addCoordinateFrameAnimation("LittlebornWalkR", "LittlebornWalk", 0, 7, 10, false, true);
		KEYANIMANAGER->addCoordinateFrameAnimation("LittlebornJumpR", "LittIebornJump", 0, 1, 5, false, true);
		KEYANIMANAGER->addCoordinateFrameAnimation("LittlebornDashR", "LittIebornDash", 0, 1, 5, false, true);
		KEYANIMANAGER->addCoordinateFrameAnimation("SkulAttackR1", "SkulAttack", 0, 4, 5, false, true);
		KEYANIMANAGER->addCoordinateFrameAnimation("SkulAttackR2", "SkulAttack", 5, 8, 5, false, true);
		KEYANIMANAGER->addCoordinateFrameAnimation("SkulFallR", "SkulFall", 0, 4, 5, false, true);
		KEYANIMANAGER->addCoordinateFrameAnimation("SkulWeaponIdleR", "SkulWeaponIdle", 0, 3, 5, false, true);
		KEYANIMANAGER->addCoordinateFrameAnimation("SkulJumpAttackR", "SkulJumpAttack", 0, 3, 5, false, true);
		KEYANIMANAGER->addCoordinateFrameAnimation("SkulSkillR", "SkulSkill", 0, 3, 5, false, true);
		KEYANIMANAGER->addCoordinateFrameAnimation("SkillWalkR", "SkillWalk", 0, 7, 10, false, true);


		// skul Ani add left
		KEYANIMANAGER->addCoordinateFrameAnimation("LittlebornIdleL", "Littleborn", 4, 7, 5, false, true);   
		KEYANIMANAGER->addCoordinateFrameAnimation("LittlebornWalkL", "LittlebornWalk", 8,15, 10, false, true);
		KEYANIMANAGER->addCoordinateFrameAnimation("LittlebornJumpL", "LittIebornJump", 2, 3, 5, false, true);
		KEYANIMANAGER->addCoordinateFrameAnimation("LittlebornDashL", "LittIebornDash", 2, 3, 5, false, true);
		KEYANIMANAGER->addCoordinateFrameAnimation("SkulAttackL1", "SkulAttack", 9, 13, 5, false, true);
		KEYANIMANAGER->addCoordinateFrameAnimation("SkulAttackL2", "SkulAttack", 14, 17, 5, false, true);
		KEYANIMANAGER->addCoordinateFrameAnimation("SkulFallL", "SkulFall", 5, 9, 5, false, true);
		KEYANIMANAGER->addCoordinateFrameAnimation("SkulWeaponIdleL", "SkulWeaponIdle", 4, 7, 5, false, true);
		KEYANIMANAGER->addCoordinateFrameAnimation("SkulJumpAttackL", "SkulJumpAttack", 4, 7, 5, false, true);
		KEYANIMANAGER->addCoordinateFrameAnimation("SkulSkillL", "SkulSkill", 4, 7, 5, false, true);
		KEYANIMANAGER->addCoordinateFrameAnimation("SkillWalkL", "SkillWalk", 8, 15, 10, false, true);

		//Effact Ani R
		KEYANIMANAGER->addCoordinateFrameAnimation("SmorkR", "Smork", 0, 12, 10, false, true);

		//Effact Ani L
		KEYANIMANAGER->addCoordinateFrameAnimation("SmorkL", "Smork", 13, 25, 10, false, true);

		
	}
};
