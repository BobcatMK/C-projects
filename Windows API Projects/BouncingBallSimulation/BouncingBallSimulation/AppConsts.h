#ifndef APP_CONSTS_H
#define APP_CONSTS_H

#include <string>
#include "Vec2.h"
namespace AppConsts {
	extern const std::wstring gWndCaption;
	extern const int gClientWidth;
	extern const int gClientHeight;
	extern const Vec2 gClientCenter;

	extern const int gWindowWidth;
	extern const int gWindowHeight;
	extern const int SleepTimeInMs;	

	extern const double gVerySlowRatio;
	extern const double gSlowRatio;
	extern const double gNormalRatio;
	extern const double gFastRatio;
	extern const double gVeryFastRatio;

	extern const double gMovePerFrameRatio;

	// velocity vector data for ball
	// I'm not using vMaxX or vMaxY variables due to the way rand works
	extern const int vMinX;
	extern const int vRangeX;

	extern const int vMinY;
	extern const int vRangeY;

	enum class collisionSides {
		NONE = 0,
		TOP = 1,
		RIGHT = 2,
		TOP_AND_RIGHT = 3,
		BOTTOM = 4,
		BOTTOM_AND_RIGHT = 6,
		LEFT = 7,
		TOP_AND_LEFT = 8,
		BOTTOM_AND_LEFT = 11
	};
};

#endif
