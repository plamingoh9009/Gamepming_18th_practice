﻿// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 특정 포함 파일이 들어 있는
// 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <time.h>

// STL
#include <vector>
#include <map>
#include <string>

// 여기서 프로그램에 필요한 추가 헤더를 참조합니다.
// 내가 만든 헤더파일은 이곳에 추가 ㅇㅇ
#include "commonMacroFunction.h"
#include "KeyManager.h"
#include "randomFunction.h"

#include "missleControl.h"
#include "playerControl.h"
// ========================
// ###		매니저들		###
// ========================
#define KEYMANAGER	KeyManager::getSingleton()
#define RND			RandomFunction::getSingletom()

// ========================
// ###		디파인문		###
// ========================
#define WINNAME		(LPTSTR)(TEXT("경일프로그래밍 18기"))
#define WINSTARTX	100
#define WINSTARTY	100
#define WINSIZEX	1024
#define WINSIZEY	512
#define WINSTYLE	WS_CAPTION | WS_SYSMENU

// ============================================
// ###		메인게임 릴리즈에서 사용할 것		###
// ============================================
#define SAFE_DELETE(p)	{if(p){delete(p); (p) = nullptr;}}

// ========================================================
// ###		전역변수(인스턴스, 윈도우 핸들, 마우스 좌표)		###
// ========================================================

extern HINSTANCE m_hInstance;
extern HWND m_hWnd;
extern POINT m_ptMouse;
