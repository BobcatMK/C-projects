#pragma once

//#include "Vec2.h"
//#include "Circle.h"
#include "../Classes/SpriteWithoutMask.h"
#include "../Classes/BackBuffer.h"
#include "../resource2.h"
#include "AppConsts.h"
#include "AppInitializers.h"
#include "MainMenuOperations.h"

namespace GameController {
	extern void RunGameLoop();
	extern bool InitMainWnd(int showCmd);
	extern LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	extern void DrawFPSAsWindowCaption();
	extern void DrawAndPresentGameplay();
}
