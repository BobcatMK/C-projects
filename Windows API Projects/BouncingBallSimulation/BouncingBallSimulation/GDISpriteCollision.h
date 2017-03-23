#pragma once
#ifndef GDI_SPRITE_COLLISION_H
#define GDI_SPRITE_COLLISION_H

#include "AppInitializers.h"
#include "AppConsts.h"
#include "cmath"

namespace GDISpriteCollision {
	extern void runDetection(double dt);
	extern AppConsts::collisionSides _probableCollisionSides();
	extern void _reverseVelVec(double& colOneT, double& colTwoT);
	extern void _calculateCollision(AppConsts::collisionSides& collision, double& dt);
}
#endif
