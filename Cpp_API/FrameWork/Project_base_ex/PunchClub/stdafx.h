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

// STL
#include<vector>
#include<map>
#include<string>
// 여기서 프로그램에 필요한 추가 헤더를 참조합니다.
//==========================================
//##			베이스 프레임워크			  ##
//==========================================
#include "commonMacroFunction.h"
#include "Base/Image.h"
#include "Base/SingletonBase.h"
#include "Base/Util.h"
#include "Base/Random.h"

using namespace UTIL;
using namespace std;
//==========================================
//##			매니저 프레임워크			  ##
//==========================================
#include "Manager/TimeManager.h"

// 여기서 초기화
#define TIMEMANAGER	TimeManager::get_singleton()
//======================================
//##			디파인문				  ##
//======================================
#define WINNAME		(LPTSTR)(TEXT("경일 프로그래밍 18기"))
#define WINSTARTX   50
#define WINSTARTY   50
#define WINSIZEX	1024
#define	WINSIZEY	600
#define WINSTYLE	WS_CAPTION | WS_SYSMENU
#define SAFE_DELETE(p) {if(p) {delete(p); (p) = nullptr;}}

//========================================
//##				전역변수				##
//========================================
extern HINSTANCE m_hInstance;
extern HWND m_hWnd;
extern POINT m_ptMouse;