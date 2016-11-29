#pragma once
#ifndef GDI_SPRITE_COLLISION_H
#define GDI_SPRITE_COLLISION_H

#include "AppInitializers.h"
#include "AppConsts.h"
#include "cmath"

namespace GDISpriteCollision {
	extern void runDetection(float dt);
	extern AppConsts::collisionSides _probableCollisionSides();
	extern void _reverseVelVec(float& colOneT, float& colTwoT);
	extern void _calculateCollision(AppConsts::collisionSides& collision, float& dt);
}
#endif
