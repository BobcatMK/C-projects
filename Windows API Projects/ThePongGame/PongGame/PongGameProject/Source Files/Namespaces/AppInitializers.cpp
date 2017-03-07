#include "../../Header Files/Namespaces/AppInitializers.h"

HWND AppInitializers::GhMainWnd = nullptr;
HINSTANCE AppInitializers::GhAppInst = nullptr;
HDC AppInitializers::GhSpriteDC = nullptr;
HMENU AppInitializers::GhMainMenu = nullptr;

short int AppInitializers::GMouseCoordinateX = 0;
short int AppInitializers::GMouseCoordinateY = 0;

BackBuffer* AppInitializers::GBackBuffer = nullptr;

// VIEW BITMAPS BEGIN
// Common bitmaps
SpriteWithoutMask* AppInitializers::GBlackBackground = nullptr;
SpriteWithoutMask* AppInitializers::GMenuCopyrights = nullptr;
SpriteWithoutMask* AppInitializers::GMenuFrame = nullptr;
SpriteWithoutMask* AppInitializers::GMenuThePongGameLogo = nullptr;
MenuItemSpriteWithoutMask* AppInitializers::GMenuItemBack = nullptr;
std::shared_ptr<SpriteWithoutMask> AppInitializers::GF1HowToPlayHint(nullptr);

// Main Menu View
MenuItemSpriteWithoutMask* AppInitializers::GMenuItemNewGame = nullptr;
MenuItemSpriteWithoutMask* AppInitializers::GMenuItemOptions = nullptr;
MenuItemSpriteWithoutMask* AppInitializers::GMenuItemCredits = nullptr;
MenuItemSpriteWithoutMask* AppInitializers::GMenuItemExitGame = nullptr;

// New Game View
MenuItemSpriteWithoutMask* AppInitializers::GMenuItemAIvsAI = nullptr;
MenuItemSpriteWithoutMask* AppInitializers::GMenuItemP1vsAI = nullptr;
MenuItemSpriteWithoutMask* AppInitializers::GMenuItemP1vsP2 = nullptr;

// AI Difficulty View
SpriteWithoutMask* AppInitializers::GMenuDifficulty = nullptr;
MenuItemSpriteWithoutMask* AppInitializers::GMenuItemEasy = nullptr;
MenuItemSpriteWithoutMask* AppInitializers::GMenuItemMedium = nullptr;
MenuItemSpriteWithoutMask* AppInitializers::GMenuItemHard = nullptr;

// Choose Side View
SpriteWithoutMask* AppInitializers::GMenuChooseSide = nullptr;
MenuItemSpriteWithoutMask* AppInitializers::GMenuItemLeft = nullptr;
MenuItemSpriteWithoutMask* AppInitializers::GMenuItemRight = nullptr;

// Options View
SpriteWithoutMask* AppInitializers::GMenuGameSpeed = nullptr;
MenuItemSpriteWithoutMask* AppInitializers::GMenuItemFast = nullptr;
MenuItemSpriteWithoutMask* AppInitializers::GMenuItemNormal = nullptr;
MenuItemSpriteWithoutMask* AppInitializers::GMenuItemSlow = nullptr;

// Credits View
SpriteWithoutMask* AppInitializers::GMenuCreditsText = nullptr;
MenuItemSpriteWithoutMask* AppInitializers::GMenuItemCreditsBack = nullptr;

std::shared_ptr<SpriteWithoutMask> AppInitializers::GPlayerOneRacket(nullptr);
std::shared_ptr<SpriteWithoutMask> AppInitializers::GPlayerTwoRacket(nullptr);

std::shared_ptr<SpriteWithoutMask> AppInitializers::GPlayerOneSpeedBoost(nullptr);
std::shared_ptr<SpriteWithoutMask> AppInitializers::GPlayerTwoSpeedBoost(nullptr);

std::shared_ptr<SpriteWithoutMask> AppInitializers::GHashLine(nullptr);
std::shared_ptr<SpriteWithoutMask> AppInitializers::GBall(nullptr);

std::shared_ptr<SpriteWithoutMask> AppInitializers::GMenuHowToPlay(nullptr);
// VIEW BITMAPS END

std::shared_ptr<Player> AppInitializers::GPlayerOne(nullptr);
std::shared_ptr<Player> AppInitializers::GPlayerTwo(nullptr);

float AppInitializers::CurrentTime = 0.0f;
float AppInitializers::LastTime = 0.0f;
float AppInitializers::DeltaTime = 0.0f;
bool AppInitializers::WasMenuOperationEvent = false;

AppConsts::GAME_PHASES AppInitializers::GCurrentGamePhase = AppConsts::GAME_PHASES::INITIAL_MENU;
AppConsts::GAME_SETTINGS AppInitializers::GSettingDifficulty = AppConsts::GAME_SETTINGS::NONE;
AppConsts::GAME_SETTINGS AppInitializers::GSettingSide = AppConsts::GAME_SETTINGS::NONE;
AppConsts::GAME_SETTINGS AppInitializers::GSettingSpeed = AppConsts::GAME_SETTINGS::SPEED_NORMAL;
//AppConsts::MENU_ITEMS AppInitializers::GActiveMenuItem = AppConsts::MENU_ITEMS::NONE;
bool AppInitializers::GMenuHowToPlayIsVisible = false;

MenuItemSpriteWithoutMask* AppInitializers::GActiveMenuItem = nullptr;
MenuItemSpriteWithoutMask* AppInitializers::GActiveSettingMenuItem = nullptr;
std::vector<MenuItemSpriteWithoutMask*> AppInitializers::GCurrentMenuItems;
