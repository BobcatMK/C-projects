#ifndef LOGIC_H
#define LOGIC_H

#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Vec2.h"
#include "resource.h"
#include "AppConsts.h"
#include "AppInitializers.h"
#include "GDISpriteCollision.h"


namespace Logic {
	void RunSimulation();
	void DrawFPS();
	Vec2 GetRandVec2(int startX, int rangeX, int startY, int rangeY, bool shouldRandSign);
	Vec2 CountPositionVec2();
	bool InitMainWnd();
	void SetInitialVec2(float ratio);
	LRESULT CALLBACK MainWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
}
#endif
