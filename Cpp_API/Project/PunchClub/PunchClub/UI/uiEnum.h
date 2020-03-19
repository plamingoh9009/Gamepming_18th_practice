#pragma once
namespace GAUGE
{
	enum TYPE
	{
		GG_EMPTY,
		GG_WORK
	};
}
namespace SLOT
{
	enum TYPE
	{
		SLT_EMPTY,
		SLT_ACTIVE_SKILL,
		SLT_ITEM
	};
	enum SKILL
	{
		SKL_EMPTY,
		SKL_BLOCK,
		SKL_DODGE,
		SKL_PUNCH
	};
	enum ITEM
	{
		ITM_EMPTY,
		ITM_MEAT,
		ITM_PIZZA_BOX,
		ITM_SODA
	};
}
namespace ICON
{
	enum TYPE
	{
		ICN_EMPTY,
		ICN_HUD_MAP,
		ICN_LEAGUE,
		ICN_SKILLTREE,
		// 아이템 아이콘
		ICN_ENERGY,
		ICN_FEEL,
		ICN_FOOD,
		ICN_HEALTH
	};
}
namespace MAPICON
{
	enum TYPE
	{
		ICN_EMPTY,
		ICN_HOME,
		ICN_SHOP,
		ICN_GYM,
		ICN_BUILD,
		ICN_PLAYER
	};
}
namespace WINDOW
{
	enum TYPE
	{
		WND_NONE,
		WND_FRIGER,
		WND_SHOP,
		WND_LEAGUE,
		WND_BUS,
		WND_BUILD
	};
}
namespace MYTEXT
{
	enum TYPE
	{
		TXT_NONE,
		TXT_TITLE,
		TXT_DESCR
	};
}
namespace BUTTON
{
	enum TYPE
	{
		BTN_NONE,
		BTN_RED,
		BTN_RED_LONG,
		BTN_DELETE_RED,
		BTN_BLUE_LONG,
		BTN_GREEN,
		BTN_GREEN_LONG,
		BTN_GREEN_INVEN,
		BTN_BUS_GREEN
	};
	enum ICON
	{
		ICN_DOLLAR,
		ICN_TIME_DAYS,
		ICN_DELETE
	};
}
