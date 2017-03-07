#include "../../Header Files/Classes/MenuItemSpriteWithoutMask.h"
#include <string>

MenuItemSpriteWithoutMask::MenuItemSpriteWithoutMask(
	HINSTANCE hAppInst, int menuItemID, int menuItemActiveID, const Vec2& p0, const AppConsts::GAME_PHASES mainMenuOrGameTypeToActivateOnClick
) : MenuItemSpriteWithoutMask(hAppInst, menuItemID, menuItemActiveID, p0, mainMenuOrGameTypeToActivateOnClick, AppConsts::GAME_SETTINGS::NONE) {}

MenuItemSpriteWithoutMask::MenuItemSpriteWithoutMask(
	HINSTANCE hAppInst, int menuItemID, int menuItemActiveID, const Vec2& p0, const AppConsts::GAME_PHASES mainMenuOrGameTypeToActivateOnClick, const AppConsts::GAME_SETTINGS settingToActiveOnClick
) {
	mhAppInst = hAppInst;
	mhMenuItem = LoadBitmap(hAppInst, MAKEINTRESOURCE(menuItemID));
	mhMenuItemActive = LoadBitmap(hAppInst, MAKEINTRESOURCE(menuItemActiveID));
	GetObject(mhMenuItem, sizeof(BITMAP), &mMenuItemBM);
	GetObject(mhMenuItemActive, sizeof(BITMAP), &mMenuItemActiveBM);
	mPosition = p0;
	mUpperLeftCorner = Vec2(p0.x - int(0.5 * mMenuItemBM.bmWidth), p0.y - int(0.5 * mMenuItemBM.bmHeight));
	mLowerRightCorner = Vec2(p0.x + int(0.5 * mMenuItemBM.bmWidth), p0.y + int(0.5 * mMenuItemBM.bmHeight));
	mMainMenuOrGameTypeToActivateOnClick = mainMenuOrGameTypeToActivateOnClick;
	mSettingToActiveOnClick = settingToActiveOnClick;
}

MenuItemSpriteWithoutMask::~MenuItemSpriteWithoutMask()
{
	DeleteObject(mhMenuItem);
	DeleteObject(mhMenuItemActive);
}

int MenuItemSpriteWithoutMask::width()
{
	return mMenuItemBM.bmWidth;
}

int MenuItemSpriteWithoutMask::height()
{
	return mMenuItemBM.bmHeight;
}

MenuItemSpriteWithoutMask* MenuItemSpriteWithoutMask::draw(HDC hBackBufferDC, HDC hSpriteDC, DWORD drawMethod, HBITMAP bitmapHandler) {
	int spritesWidth = width();
	int spritesHeight = height();

	int leftUpperCornerPosX = (int)mPosition.x - (spritesWidth / 2);
	int leftUpperCornerPosY = (int)mPosition.y - (spritesHeight / 2);

	HGDIOBJ oldObj = SelectObject(hSpriteDC, bitmapHandler);
	BitBlt(hBackBufferDC, leftUpperCornerPosX, leftUpperCornerPosY, spritesWidth, spritesHeight, hSpriteDC, 0, 0, drawMethod);

	SelectObject(hSpriteDC, oldObj);

	return this;
}

MenuItemSpriteWithoutMask* MenuItemSpriteWithoutMask::drawMenuItem(HDC hBackBufferDC, HDC hSpriteDC, DWORD drawMethod) {
	return draw(hBackBufferDC, hSpriteDC, drawMethod, mhMenuItem);
}

MenuItemSpriteWithoutMask* MenuItemSpriteWithoutMask::drawMenuItem() {
	using namespace AppInitializers;
	return draw(GBackBuffer->getDC(), GhSpriteDC, SRCCOPY, mhMenuItem);
}

MenuItemSpriteWithoutMask* MenuItemSpriteWithoutMask::drawMenuItemActive(HDC hBackBufferDC, HDC hSpriteDC, DWORD drawMethod) {
	return draw(hBackBufferDC, hSpriteDC, drawMethod, mhMenuItemActive);
}

MenuItemSpriteWithoutMask* MenuItemSpriteWithoutMask::drawMenuItemActive() {
	using namespace AppInitializers;
	return draw(GBackBuffer->getDC(), GhSpriteDC, SRCCOPY, mhMenuItemActive);
}
