#pragma once

#include <Windows.h>
#include "AppConsts.h"
#include "AppInitializers.h"
#include "../Classes/BackBuffer.h"
#include "../Classes/SpriteWithoutMask.h"
#include "../Classes/MenuItemSpriteWithoutMask.h"
#include "../Classes/Player.h"
#include "../Classes/AIPlayer.h"
#include "../Classes/HumanPlayer.h"
#include "../resource2.h"

namespace MainMenuOperations {
	extern void WindowCreatedInitializer(HWND hWnd);
	extern void DrawInitialMenu();
	extern void DrawCommonMenuParts(bool drawMenuFrame);
	extern void ActivateAndDeactivateMenuItem(short int mouseCoordinateX, short int mouseCoordinateY);
	extern bool MouseCursorIsOverMenuItem(MenuItemSpriteWithoutMask* menuItem, short int mouseCoordinateX, short int mouseCoordinateY);
    extern void GenerateMenuViewBasedOnGCurrentGamePhase();
	extern void ChangeMenuOrRunGameBasedOnGActiveMenuItem();
	extern void ChangeDifficultySetting();
	extern void ChangeSideSetting();
	extern void ChangeAndVisuallyDeactivateOldSpeedSetting();
	extern void VisuallyActivateSpeedSetting();
	extern MenuItemSpriteWithoutMask* GetPointerToCurrentSpeedSettingSprite();
	extern bool IsCurrentPhaseGamePhase();
	extern void DrawGame();
    extern void DrawHowToPlayMenuAndPresent();
    extern void DrawNewGameMenu();
    extern void DrawChooseAIDifficultyMenu();
    extern void DrawChooseSideMenu();
    extern void DrawOptionsMenu();
    extern void DrawCreditsMenu();
}
