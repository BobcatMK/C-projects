#include "../../Header Files/Namespaces/GameController.h"

void GameController::RunGameLoop() {
	using namespace AppInitializers;
	using namespace AppConsts;

	CurrentTime = (float)timeGetTime();
	DeltaTime = (CurrentTime - LastTime) * 0.001f;

	if (WasMenuOperationEvent) {
		DeltaTime = 0.0f;
		WasMenuOperationEvent = false;
	}

	GameController::DrawAndPresentGameplay();
	GameController::DrawFPSAsWindowCaption();
	LastTime = CurrentTime;

	Sleep(SLEEP_TIME_IN_MS);
}


void GameController::DrawAndPresentGameplay() {
	using namespace AppInitializers;
	using namespace AppConsts;

	switch (GCurrentGamePhase) {
	case GAME_PHASES::HUMAN_P1_VS_AI_GAME:
		// run game loop
		break;
	case GAME_PHASES::HUMAN_P1_VS_HUMAN_P2_GAME:
		// run game loop
		break;
	case GAME_PHASES::AI_VS_AI_GAME:
		// run game loop
		break;
	}

	// TODO pamiêtaj aby w ka¿dym z case'ów dodaæ GBackBuffer->present();
	// TODO - wywolaj message WM_MOUSE_MOVE, aby sczytaæ informacje o pozycji myszy w momencie wygenerowania nowego menu. BARDZO WAZNE.
}

void GameController::DrawFPSAsWindowCaption() {
	static int frameCnt = 0;
	static float timeElapsed = 0;
	static wchar_t buffer[256];

	++frameCnt;
	timeElapsed += AppInitializers::DeltaTime;

	if (timeElapsed < 1.0f) return;

	wsprintf(buffer, L" | %d FPS", frameCnt);

	SetWindowText(AppInitializers::GhMainWnd, (AppConsts::G_WINDOW_CAPTION + buffer).c_str());

	frameCnt = 0;
	timeElapsed = 0.0f;
}

bool GameController::InitMainWnd(int showCmd) {
	using namespace AppConsts;
	using namespace AppInitializers;

	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = GhAppInst;
	wc.hIcon = ::LoadIcon(0, IDI_APPLICATION);
	wc.hCursor = ::LoadCursor(0, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)::GetStockObject(NULL_BRUSH);
	wc.lpszMenuName = 0;
	wc.lpszClassName = L"PongGameWnd";

	RegisterClass(&wc);

	GhMainMenu = LoadMenu(GhAppInst, MAKEINTRESOURCE(IDR_PONG_MENU));
	GhMainWnd = ::CreateWindow(
		L"PongGameWnd",
		G_WINDOW_CAPTION.c_str(),
		WS_OVERLAPPED | WS_SYSMENU,
		200,
		200,
		G_WINDOW_WIDTH,
		G_WINDOW_HEIGHT,
		0,
		GhMainMenu,
		GhAppInst,
		0
	);

	if (GhMainWnd == NULL) {
		::MessageBox(NULL, L"Window creation failed!", L"CreateWindow error", MB_OK);
		return false;
	}

	ShowWindow(GhMainWnd, showCmd);
	UpdateWindow(GhMainWnd);
	return true;
}

LRESULT CALLBACK GameController::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	using namespace AppInitializers;
	using namespace AppConsts;

	switch (msg) {
	case WM_KEYDOWN:
		switch (wParam) {
		case VK_F1:
            GMenuHowToPlayIsVisible = true;
            MainMenuOperations::DrawHowToPlayMenuAndPresent();
            break;
		}
		return NULL;
	case WM_KEYUP:
		switch (wParam) {
		case VK_F1:
            GMenuHowToPlayIsVisible = false;
            // if player is currently in game mode, then redraw will be done by game loop and not by keyup message
            if (MainMenuOperations::IsCurrentPhaseGamePhase()) break;
            MainMenuOperations::GenerateMenuViewBasedOnGCurrentGamePhase();
            SendMessage(GhMainWnd, WM_MOUSEMOVE, wParam, lParam);
            break;
		}
		return NULL;
	case WM_CREATE:
		MainMenuOperations::WindowCreatedInitializer(hWnd);
		break;
	case WM_PAINT:
		MainMenuOperations::DrawInitialMenu();
		SendMessage(GhMainWnd, WM_MOUSEMOVE, wParam, lParam);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case ID_FILE_EXIT:
			DestroyWindow(GhMainWnd);
			break;
		}

		return NULL;
	case WM_LBUTTONUP:
		// We don't want to do anything if void will be clicked or when game phases is not menu
		if (GActiveMenuItem == nullptr || MainMenuOperations::IsCurrentPhaseGamePhase() || GMenuHowToPlayIsVisible) return NULL;
		MainMenuOperations::ChangeMenuOrRunGameBasedOnGActiveMenuItem();
		SendMessage(GhMainWnd, WM_MOUSEMOVE, wParam, lParam);
		return NULL;
	case WM_MOUSEMOVE:
		// We don't want to do anything if GCurrentGamePhase is game type phase
		if (MainMenuOperations::IsCurrentPhaseGamePhase() || GMenuHowToPlayIsVisible) return NULL;
		// tutaj ma odbywaæ siê aktywowanie poszczegolnych menu item'ów po najechaniu na nie myszka.
        {
            POINT mouseCoordinates{};
            GetCursorPos(&mouseCoordinates);
            ScreenToClient(GhMainWnd, &mouseCoordinates);
            MainMenuOperations::ActivateAndDeactivateMenuItem(mouseCoordinates.x, mouseCoordinates.y);
        }
        // TODO - zmiana settingow musi byc obslugiwana w tym samym miejscu co obs³uga zwyk³ych menu itemow, ktore nie sa settingsami. Wynika to z tego
		// ze na jednym widoku mog¹ byæ jednoczesnie menu itemy zwykle i menu itemy settingsy.
		return NULL;
	case WM_DESTROY:
		srand(1); // unseed random number generator
		PostQuitMessage(NULL);
		return NULL;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
