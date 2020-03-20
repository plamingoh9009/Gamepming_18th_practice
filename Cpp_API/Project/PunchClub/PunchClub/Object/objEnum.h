#pragma once
namespace FACILITY
{
	enum TYPE
	{
		OBJ_EMPTY,
		OBJ_TREADMILL,
		OBJ_BARBELL,
		OBJ_YUNGCHUN,
		OBJ_TIRE,
		OBJ_BENCH_PRESS,
		OBJ_PUNCHBUG
	};
	enum RUN_TYPE
	{
		TRM_EMPTY,
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
		PB_PLAYER
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
	int money = 35;
};