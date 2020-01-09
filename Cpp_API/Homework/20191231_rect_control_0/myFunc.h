#pragma once
#include "Windows.h"


WPARAM isInRectEdge(RECT me, POINT pt);
RECT controlRectSize(RECT me, POINT pt, WPARAM lo);
RECT setRectCenter(RECT me);

bool isCrushWall(RECT me, RECT wall);
bool isInWindow(RECT me, RECT window);
bool isInWindow(POINT pt, RECT window);
bool isInRange(LONG target, LONG start, LONG end);

void swapRect(RECT* me, RECT* other);
void moveRect(RECT* me, WPARAM wParam, int distance);
void moveRect(RECT* me, POINT pt);
RECT makeLittleRect(const RECT me);
void runCrush(RECT me, RECT* other);
void moveBackInWindow(RECT* me, RECT window);
