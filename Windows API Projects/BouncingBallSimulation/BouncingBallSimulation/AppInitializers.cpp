#include "AppInitializers.h"

namespace AppInitializers {
	HWND ghMainWnd = nullptr;
	HINSTANCE ghAppInst = nullptr;
	HMENU ghMainMenu = nullptr;
	HDC ghSpriteDC = nullptr;

	Sprite* gBall = nullptr;
	Sprite* gBackground = nullptr;
	BackBuffer* gBackBuffer = nullptr;

	Vec2 initialVelVector{};

    
    
    //__int64 lastTimeCount = 0;
    //__int64 currentTimeCount = 0;
    double timeScaleSeconds = 0.0;
    __int64 timeCount = 0;
    double lastTimeInSeconds = 0;
    double currentTimeInSeconds = 0;
    double deltaTimeInSeconds = 0;
	//double lastTime = 0.0f;
	//double currentTime = 0.0f;
	//double deltaTime = 0.0f;

	bool wasMenuOperationEvent = false;

	int leftBorder = NULL;
	int rightBorder = NULL;
	int topBorder = NULL;
	int bottomBorder = NULL;

	bool xVelIsPositive = 0;
	bool yVelIsPositive = 0;
}
