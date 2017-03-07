#include <Windows.h>
#include <mmsystem.h>
#include <time.h>
#include "../Header Files/Namespaces/GameController.h"

using namespace std;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR cmdLine, int showCmd) {
	AppInitializers::GhAppInst = hInstance;

	if (GameController::InitMainWnd(showCmd)) {
		MSG msg;
		SecureZeroMemory(&msg, sizeof(MSG));

		AppInitializers::LastTime = (float)timeGetTime();
		srand((unsigned int)time(NULL));

		while (msg.message != WM_QUIT) {
			if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else {
				GameController::RunGameLoop();
			}
		}
		return (int)msg.wParam;
	}

	::MessageBox(nullptr, L"Window creation failed", L"Error", MB_OK);
	return NULL;
}
