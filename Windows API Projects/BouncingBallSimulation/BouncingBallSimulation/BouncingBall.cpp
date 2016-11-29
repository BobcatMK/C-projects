#include <Windows.h>
#include <string>
#include <mmsystem.h>

#include "Logic.h"

using namespace std;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR cmdLine, int showCmd) {
	AppInitializers::ghAppInst = hInstance;

	if (Logic::InitMainWnd()) {
		MSG msg;
		SecureZeroMemory(&msg, sizeof(MSG));

		AppInitializers::lastTime = (float)timeGetTime();
		srand((unsigned int)time(NULL));
		while (msg.message != WM_QUIT) {
			if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else {
				Logic::RunSimulation();
			}
		}
		return (int)msg.wParam;
	}

	::MessageBoxW(nullptr, L"Window creation failed.", L"Error", MB_OK);
	return NULL;
}
