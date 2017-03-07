#pragma once

#include <windows.h>
#include <string>
#include "Vec2.h"
#include "../Namespaces/AppInitializers.h"

class SpriteWithoutMask {
	public:
		SpriteWithoutMask(HINSTANCE hAppInst, int imageID, const Vec2& p0, const Vec2& v0);
		~SpriteWithoutMask();

		int width();
		int height();

		void update(float dt);
		SpriteWithoutMask* draw(HDC hBackBufferDC, HDC hSpriteDC, DWORD drawMethod);
		SpriteWithoutMask* draw();
	public:
		Vec2 mPosition;
		Vec2 mVelocity;
		Vec2 mLowerRightCorner;
		Vec2 mUpperLeftCorner;
	private:
		SpriteWithoutMask(const SpriteWithoutMask& rhs);
		SpriteWithoutMask& operator=(const SpriteWithoutMask& rhs);

	protected:
		HINSTANCE mhAppInst;
		HBITMAP mhImage;
		BITMAP mImageBM;
};
