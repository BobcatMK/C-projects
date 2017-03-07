#pragma once

#include <windows.h>
#include "Vec2.h"
#include "../Namespaces/AppConsts.h"
#include "../Namespaces/AppInitializers.h"

class MenuItemSpriteWithoutMask {
public:
	MenuItemSpriteWithoutMask(HINSTANCE hAppInst, int menuItemID, int menuItemActiveID, const Vec2& p0, const AppConsts::GAME_PHASES mainMenuOrGameTypeToActivateOnClick);
	MenuItemSpriteWithoutMask(HINSTANCE hAppInst, int menuItemID, int menuItemActiveID, const Vec2& p0, const AppConsts::GAME_PHASES mainMenuOrGameTypeToActivateOnClick, AppConsts::GAME_SETTINGS settingToActiveOnClick);
	~MenuItemSpriteWithoutMask();

	int width();
	int height();

	MenuItemSpriteWithoutMask* drawMenuItem(HDC hBackBufferDC, HDC hSpriteDC, DWORD drawMethod);
	MenuItemSpriteWithoutMask* drawMenuItem();
	MenuItemSpriteWithoutMask* drawMenuItemActive(HDC hBackBufferDC, HDC hSpriteDC, DWORD drawMethod);
	MenuItemSpriteWithoutMask* drawMenuItemActive();
public:
	Vec2 mPosition;
	Vec2 mLowerRightCorner;
	Vec2 mUpperLeftCorner;
	AppConsts::GAME_PHASES mMainMenuOrGameTypeToActivateOnClick;
	AppConsts::GAME_SETTINGS mSettingToActiveOnClick;
private:
	MenuItemSpriteWithoutMask(const MenuItemSpriteWithoutMask& rhs);
	MenuItemSpriteWithoutMask& operator=(const MenuItemSpriteWithoutMask& rhs);
	MenuItemSpriteWithoutMask(const MenuItemSpriteWithoutMask&& rhs);
	MenuItemSpriteWithoutMask&& operator=(const MenuItemSpriteWithoutMask&& rhs);
	MenuItemSpriteWithoutMask* draw(HDC hBackBufferDC, HDC hSpriteDC, DWORD drawMethod, HBITMAP bitmapHandler);
protected:
	HINSTANCE mhAppInst;
	HBITMAP mhMenuItem;
	HBITMAP mhMenuItemActive;
	BITMAP mMenuItemBM;
	BITMAP mMenuItemActiveBM;
};
