#pragma once
namespace MYOBJECT
{
	enum TYPE
	{
		OBJ_EMPTY,
		// Facility
		OBJ_TREADMILL,
		OBJ_BARBELL,
		OBJ_YUNGCHUN,
		OBJ_TIRE,
		OBJ_BENCH_PRESS,
		OBJ_PUNCHBUG,
		// Furniture
		OBJ_FRIGER,
		OBJ_SOFA,
		OBJ_TV,
		OBJ_AQUARIUM,
		OBJ_FAN,
		OBJ_CLOCK,
		OBJ_KITCHEN_TABLE,
		OBJ_STAND,
		OBJ_TABLE,
		OBJ_BOOKSHELF,
		OBJ_PHONE
	};
	enum RUN_TYPE
	{
		TRM_EMPTY,
		// Facility
		TRM_NORMAL,
		TRM_ORANGE_GIRL,
		TRM_YELLOW_GIRL,
		TRM_PLAYER,
		BBL_EMPTY,
		BBL_PLAYER,
		YCN_EMPTY,
		YCN_PLAYER,
		TIR_PLAYER,
		BP_PLAYER,
		PB_PLAYER,
		// Furniture
		SOFA_PLAYER,
		TV_PLAYER
	};
}
namespace NPC
{
	enum TYPE
	{
		NPC_EMPTY,
		NPC_SHOP
	};
}
struct PlayerStat
{
	double health = 800;
	double food = 600;
	double energy = 600;
	double mood = 600;
	// Stat for fight
	double str = 1250;
	double agl = 1250;
	double stm = 1250;
	// SP & Money
	int skillPoint = 3;
	int money = 73;
	// Work Gauge
	double workGauge = 250;
};
namespace PLAYER_SET
{
	enum ACTION
	{
		ACTION_EMPTY,
		ACTION_WORK,
		ACTION_SLEEP_SOFA,
		ACTION_WATCH_TV,
		// EXERSIZE
		ACTION_TREADMILL,
		ACTION_BARBELL,
		ACTION_HIT_TIRE,
		ACTION_BENCH_PRESS,
		ACTION_PUNCHBUG,
		ACTION_YUNGCHUN
	};
	enum STAT
	{
		STR = 0b0001,
		AGL = 0b0010,
		STM = 0b0100
	};
}
