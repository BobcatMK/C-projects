#include "Logic.h"

void Logic::RunSimulation() {
	using namespace AppInitializers;
	using namespace AppConsts;

    QueryPerformanceCounter((LARGE_INTEGER*)&timeCount);
    currentTimeInSeconds = (double)timeCount * timeScaleSeconds;
    deltaTimeInSeconds = currentTimeInSeconds - lastTimeInSeconds;

	if (wasMenuOperationEvent) {
        deltaTimeInSeconds = 0.0;
		wasMenuOperationEvent = false;
	}
	// this function below does all the calculation magic
    GDISpriteCollision::runDetection(deltaTimeInSeconds);

	// draw object onto BackBuffer
	gBackground->draw(gBackBuffer->getDC(), ghSpriteDC);
	gBall->draw(gBackBuffer->getDC(), ghSpriteDC);

	// draw fps
	Logic::DrawFPS();

	// present the BackBuffer
	gBackBuffer->present();

	// update time
	//lastTime = currentTime;
    lastTimeInSeconds = currentTimeInSeconds;

	// give windows time to do his own operations between game loop iterations
	Sleep(AppConsts::SleepTimeInMs);
}

void Logic::DrawFPS() {
	static int frameCnt = 0;
	static double timeElapsed = 0;
	static wchar_t buffer[256];

	++frameCnt;
	//timeElapsed += AppInitializers::deltaTime;
    timeElapsed += AppInitializers::deltaTimeInSeconds;

	if (timeElapsed < 1.0f) return;

	wsprintf(buffer, L"-- FPS = %d", frameCnt);

	// send message to main window to change caption
	SetWindowText(AppInitializers::ghMainWnd, (AppConsts::gWndCaption + buffer).c_str());

	// reset data for new fps calculation
	frameCnt = 0;
	timeElapsed = 0.0f;
}

Vec2 Logic::GetRandVec2(int startX, int rangeX, int startY, int rangeY, bool shouldRandSign) {
	POINT p{ rand() % rangeX + startX,  rand() % rangeY + startY };

	if (shouldRandSign) {
		p.x = rand() % 2 ? p.x : -p.x;
		p.y = rand() % 2 ? p.y : -p.y;
	}

	return Vec2(p);
}

Vec2 Logic::CountPositionVec2() {
	int startX, rangeX, startY, rangeY;
	startX = rangeX = startY = rangeY = 0;

	startX += (int)ceil(0.5 * AppInitializers::gBall->width());
	rangeX = AppConsts::gClientWidth - AppInitializers::gBall->width();

	startY += (int)ceil(0.5 * AppInitializers::gBall->height());
	rangeY = AppConsts::gClientHeight - AppInitializers::gBall->height();

	return Logic::GetRandVec2(startX, rangeX, startY, rangeY, false);
}

LRESULT CALLBACK Logic::MainWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	using namespace AppInitializers;
	using namespace Logic;
	using namespace AppConsts;
	Circle bc;
	static Vec2* ballVel;

	switch (msg) {
	case WM_CREATE:
		gBall = new Sprite(ghAppInst, IDB_BITMAP_BALL, IDB_BITMAP_BALL_MASK, bc, Vec2(0.0f, 0.0f), Vec2(0.0f, 0.0f));
		gBackground = new Sprite(ghAppInst, IDB_BITMAP_BACKGROUND, IDB_BITMAP_BACKGROUND_MASK, bc, gClientCenter, Vec2(0.0f, 0.0f));
		gBall->mPosition = CountPositionVec2();
		gBall->mVelocity = GetRandVec2(vMinX, vRangeX, vMinY, vRangeY, true);
		initialVelVector.x = gBall->mVelocity.x;
		initialVelVector.y = gBall->mVelocity.y;
		ballVel = &(gBall->mVelocity);
		ghSpriteDC = CreateCompatibleDC(NULL);
		gBackBuffer = new BackBuffer(hWnd, gClientWidth, gClientHeight);
		leftBorder = (int)ceil(0.5 * gBall->width());
		rightBorder = gClientWidth - leftBorder;
		topBorder = (int)ceil(0.5 * gBall->height());
		bottomBorder = gClientHeight - topBorder;
		return NULL;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case ID_FILE_EXIT:
			DestroyWindow(ghMainWnd);
			return NULL;
		case ID_SPEED_VERYSLOW:
			SetInitialVec2(gVerySlowRatio);
			break;
		case ID_SPEED_SLOW:
			SetInitialVec2(gSlowRatio);
			break;
		case ID_SPEED_NORMAL:
			SetInitialVec2(gNormalRatio);
			break;
		case ID_SPEED_FAST:
			SetInitialVec2(gFastRatio);
			break;
		case ID_SPEED_VERYFAST:
			SetInitialVec2(gVeryFastRatio);
			break;
		case ID_POSITIONVECTOR_GENERATERANDOM:
			gBall->mPosition = CountPositionVec2();
			break;
		}

		return NULL;
	case WM_EXITMENULOOP:
	case WM_MOVE:
		wasMenuOperationEvent = true;
		break;
	case WM_DESTROY:
		delete gBall;
		gBall = nullptr;
		delete gBackground;
		gBackground = nullptr;
		delete gBackBuffer;
		gBackBuffer = nullptr;
		DeleteDC(ghSpriteDC);
		ghSpriteDC = nullptr;
		srand(1);
		PostQuitMessage(NULL);
		return NULL;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
};

void Logic::SetInitialVec2(double ratio) {
	using namespace AppInitializers;

	double& xVel = gBall->mVelocity.x;
	double& yVel = gBall->mVelocity.y;

	xVel = (xVel > 0.0f ? std::abs(initialVelVector.x) : -std::abs(initialVelVector.x));
	yVel = (yVel > 0.0f ? std::abs(initialVelVector.y) : -std::abs(initialVelVector.y));

	xVel *= ratio;
	yVel *= ratio;
}

bool Logic::InitMainWnd() {
	using namespace AppInitializers;
	using namespace AppConsts;

	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = MainWndProc;
	wc.cbClsExtra = NULL;
	wc.cbWndExtra = NULL;
	wc.hInstance = ghAppInst;
	wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)::GetStockObject(NULL_BRUSH);
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = L"BouncingBallMainWnd";

	RegisterClass(&wc);

	ghMainMenu = LoadMenu(ghAppInst, MAKEINTRESOURCE(IDR_MAIN_MENU));
	ghMainWnd = ::CreateWindowW(
		L"BouncingBallMainWnd",
		gWndCaption.c_str(),
		WS_OVERLAPPED | WS_SYSMENU,
		200,
		200,
		gWindowWidth,
		gWindowHeight,
		0,
		ghMainMenu,
		ghAppInst,
		0
	);

	if (ghMainWnd == NULL) {
		::MessageBoxW(nullptr, L"CreateWindow failed.", 0, 0);
		return false;
	}

	ShowWindow(ghMainWnd, SW_NORMAL);
	UpdateWindow(ghMainWnd);

	return true;
};
