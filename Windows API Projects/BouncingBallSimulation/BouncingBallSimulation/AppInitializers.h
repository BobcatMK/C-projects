#ifndef APP_INITIALIZERS_H
#define APP_INITIALIZERS_H

#include "Windows.h"
#include "Sprite.h"
#include "BackBuffer.h"

namespace AppInitializers {
	extern HWND ghMainWnd;
	extern HINSTANCE ghAppInst;
	extern HMENU ghMainMenu;
	extern HDC ghSpriteDC;

	extern Sprite* gBall;
	extern Sprite* gBackground;
	extern BackBuffer* gBackBuffer;

	extern Vec2 initialVelVector;

	extern bool wasMenuOperationEvent;

    extern double timeScaleSeconds;
    extern __int64 timeCount;
    extern double lastTimeInSeconds;
    extern double currentTimeInSeconds;
    extern double deltaTimeInSeconds;

	//extern double lastTime;
	//extern double currentTime;
	//extern double deltaTime;

	extern int leftBorder;
	extern int rightBorder;
	extern int topBorder;
	extern int bottomBorder;
}
#endif
