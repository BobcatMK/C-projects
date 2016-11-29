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

	float lastTime = 0.0f;
	float currentTime = 0.0f;
	float deltaTime = 0.0f;

	bool wasMenuOperationEvent = false;

	int leftBorder = NULL;
	int rightBorder = NULL;
	int topBorder = NULL;
	int bottomBorder = NULL;

	bool xVelIsPositive = 0;
	bool yVelIsPositive = 0;
}
