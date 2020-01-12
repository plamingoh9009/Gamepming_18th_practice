#pragma once

// 메모리 누수 체크 헤더파일
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#define	_Memory		_CrtMemState

static _Memory	_startM, _endM, _resultM;

// 메모리 누수 관련 함수
inline void set_DbgFlag()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}

inline void show_LeakBlock(int index)
{
	_CrtSetBreakAlloc(index);
}

inline void set_MemoryPoint(_Memory* point)
{
	_CrtMemCheckpoint(point);
}

inline void show_MemoryLeak(_Memory* start, _Memory* end, _Memory* result)
{
	if (_CrtMemDifference(result, start, end))
	{
		_CrtMemDumpStatistics(result);
	}
}
