#include "stdafx.h"
#include "utils.h"

namespace UTIL
{
	float getDistance(float startX, float startY, float endX, float endY)
	{
		float x = endX - startX;
		float y = endY -  startY;

		return sqrtf(x * x + y * y);
	}

	double getAngle(float x1, float y1, float x2, float y2)
	{
		float x = x2 - x1;
		float y = y2 - y1;
	
		float distance = sqrtf(x * x + y * y);
		
		double angle = static_cast<double>(acosf(x / distance));

		if (y2 > y1)
		{
			angle = -angle;

			if (angle >= 2 * PI) angle -= 2 * PI;
		}

		return angle;
	}
}
