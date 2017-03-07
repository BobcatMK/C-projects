#pragma once

#include "AppConsts.h"
#include "../Classes/BackBuffer.h"
#include <vector>
#include <memory>

class MenuItemSpriteWithoutMask; //forward declare
class SpriteWithoutMask;  //forward declare
class Player; //forward declare
// since I'm forward declaring I can't use unique_ptr, I have to use shared_ptr instead
// explanation is available here http://stackoverflow.com/questions/6012157/is-stdunique-ptrt-required-to-know-the-full-definition-of-t

namespace AppInitializers {
	extern HWND GhMainWnd;
	extern HINSTANCE GhAppInst;
	extern HDC GhSpriteDC;
	extern HMENU GhMainMenu;

	extern short int GMouseCoordinateX;
	extern short int GMouseCoordinateY;

	extern BackBuffer* GBackBuffer;

	// VIEW BITMAPS BEGIN
	// Common bitmaps
	extern SpriteWithoutMask* GBlackBackground;
	extern SpriteWithoutMask* GMenuCopyrights;
	extern SpriteWithoutMask* GMenuFrame;
	extern SpriteWithoutMask* GMenuThePongGameLogo;
	extern MenuItemSpriteWithoutMask* GMenuItemBack;
    extern std::shared_ptr<SpriteWithoutMask> GF1HowToPlayHint;

	// Main Menu View
	extern MenuItemSpriteWithoutMask* GMenuItemNewGame;
	extern MenuItemSpriteWithoutMask* GMenuItemOptions;
	extern MenuItemSpriteWithoutMask* GMenuItemCredits;
	extern MenuItemSpriteWithoutMask* GMenuItemExitGame;

	// New Game View
	extern MenuItemSpriteWithoutMask* GMenuItemAIvsAI;
	extern MenuItemSpriteWithoutMask* GMenuItemP1vsAI;
	extern MenuItemSpriteWithoutMask* GMenuItemP1vsP2;

	// AI Difficulty View
	extern MenuItemSpriteWithoutMask* GMenuItemEasy;
	extern MenuItemSpriteWithoutMask* GMenuItemMedium;
	extern MenuItemSpriteWithoutMask* GMenuItemHard;
	extern SpriteWithoutMask* GMenuDifficulty;

	// Choose Side View
	extern MenuItemSpriteWithoutMask* GMenuItemLeft;
	extern MenuItemSpriteWithoutMask* GMenuItemRight;
	extern SpriteWithoutMask* GMenuChooseSide;

	// Options View
	extern MenuItemSpriteWithoutMask* GMenuItemFast;
	extern MenuItemSpriteWithoutMask* GMenuItemNormal;
	extern MenuItemSpriteWithoutMask* GMenuItemSlow;
	extern SpriteWithoutMask* GMenuGameSpeed;

	// Credits View
	extern MenuItemSpriteWithoutMask* GMenuItemCreditsBack;
	extern SpriteWithoutMask* GMenuCreditsText;

	extern std::shared_ptr<SpriteWithoutMask> GPlayerOneRacket;
	extern std::shared_ptr<SpriteWithoutMask> GPlayerTwoRacket;

	extern std::shared_ptr<SpriteWithoutMask> GPlayerOneSpeedBoost;
	extern std::shared_ptr<SpriteWithoutMask> GPlayerTwoSpeedBoost;

	extern std::shared_ptr<SpriteWithoutMask> GHashLine;
	extern std::shared_ptr<SpriteWithoutMask> GBall;

	extern std::shared_ptr<SpriteWithoutMask> GMenuHowToPlay;
	// VIEW BITMAPS END

	extern std::shared_ptr<Player> GPlayerOne;
	extern std::shared_ptr<Player> GPlayerTwo;

	extern float CurrentTime;
	extern float LastTime;
	extern float DeltaTime;
	extern bool WasMenuOperationEvent;

	extern AppConsts::GAME_PHASES GCurrentGamePhase;
	extern AppConsts::GAME_SETTINGS GSettingDifficulty;
	extern AppConsts::GAME_SETTINGS GSettingSide;
	extern AppConsts::GAME_SETTINGS GSettingSpeed;
	//extern AppConsts::MENU_ITEMS GActiveMenuItem;
    extern bool GMenuHowToPlayIsVisible;

	extern MenuItemSpriteWithoutMask* GActiveMenuItem;
	extern MenuItemSpriteWithoutMask* GActiveSettingMenuItem;
	extern std::vector<MenuItemSpriteWithoutMask*> GCurrentMenuItems;
}
