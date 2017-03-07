#include "../../Header Files/Classes/SpriteWithoutMask.h"

SpriteWithoutMask::SpriteWithoutMask(HINSTANCE hAppInst, int imageID, const Vec2& p0, const Vec2& v0)
{
	mhAppInst = hAppInst;
	mhImage = LoadBitmap(hAppInst, MAKEINTRESOURCE(imageID));
	GetObject(mhImage, sizeof(BITMAP), &mImageBM);
	mPosition = p0;
	mVelocity = v0;
	mUpperLeftCorner = Vec2(p0.x - int(0.5 * mImageBM.bmWidth), p0.y - int(0.5 * mImageBM.bmHeight));
	mLowerRightCorner = Vec2(p0.x + int(0.5 * mImageBM.bmWidth), p0.y + int(0.5 * mImageBM.bmHeight));
}

SpriteWithoutMask::~SpriteWithoutMask()
{
	DeleteObject(mhImage);
}

int SpriteWithoutMask::width()
{
	return mImageBM.bmWidth;
}

int SpriteWithoutMask::height()
{
	return mImageBM.bmHeight;
}

void SpriteWithoutMask::update(float dt)
{
	mPosition += mVelocity * dt;
}

SpriteWithoutMask* SpriteWithoutMask::draw(HDC hBackBufferDC, HDC hSpriteDC, DWORD drawMethod)
{
	int spritesWidth = width();
	int spritesHeight = height();

	int leftUpperCornerPosX = (int)mPosition.x - (spritesWidth / 2);
	int leftUpperCornerPosY = (int)mPosition.y - (spritesHeight / 2);

	HGDIOBJ oldObj = SelectObject(hSpriteDC, mhImage);
	BitBlt(hBackBufferDC, leftUpperCornerPosX, leftUpperCornerPosY, spritesWidth, spritesHeight, hSpriteDC, 0, 0, drawMethod);

	SelectObject(hSpriteDC, oldObj);

	return this;
}

SpriteWithoutMask* SpriteWithoutMask::draw() {
	using namespace AppInitializers;
	return draw(GBackBuffer->getDC(), GhSpriteDC, SRCCOPY);
}
