#pragma once
#include "Windows.h"

bool isCrushWall(RECT me, RECT wall);
bool isInWindow(RECT me, RECT window);
void swapRect(RECT* me, RECT* other);
void moveRect(RECT* me, WPARAM wParam);
RECT makeLittleRect(const RECT me);