#include "GDISpriteCollision.h"

namespace GDISpriteCollision {
	void runDetection(double dt) {
		while (dt != 0.0f) {
			AppConsts::collisionSides collision = _probableCollisionSides();
			_calculateCollision(collision, dt);
		}
	}

	void _calculateCollision(AppConsts::collisionSides& collision, double& dt) {
		using namespace AppConsts;
		using namespace AppInitializers;

		double colOneT = 0.0f;
		double colTwoT = 0.0f;
		double timeToCollision = 0.0f;
		Vec2& ballPos = gBall->mPosition;
		Vec2& ballVel = gBall->mVelocity;

		switch (collision) {
		case collisionSides::BOTTOM_AND_RIGHT:
			// what if ballVel.x or y is equal to 0 ? In this case it can't be. If it was it would landed in different case scenario.
			colOneT = ((double)bottomBorder - ballPos.y) / ballVel.y; // bottom collision time
			colTwoT = ((double)rightBorder - ballPos.x) / ballVel.x; // right collision time
			timeToCollision = (colOneT < colTwoT ? colOneT : colTwoT);

			if (dt > timeToCollision) {
				// it means that there will be collision
				dt -= timeToCollision;
				ballPos.y = ballPos.y + (ballVel.y * timeToCollision);
				ballPos.x = ballPos.x + (ballVel.x * timeToCollision);
				_reverseVelVec(colOneT, colTwoT);
				break;
			}

			ballPos.y = ballPos.y + (ballVel.y * dt);
			ballPos.x = ballPos.x + (ballVel.x * dt);
			dt = 0.0f;
			break;
		case collisionSides::TOP_AND_RIGHT:
			colOneT = std::abs((ballPos.y - (double)topBorder) / ballVel.y); // top collision time
			colTwoT = ((double)rightBorder - ballPos.x) / ballVel.x; // right collision time
			timeToCollision = (colOneT < colTwoT ? colOneT : colTwoT);
			
			if (dt > timeToCollision) {
				dt -= timeToCollision;
				ballPos.y = ballPos.y - (std::abs(ballVel.y) * timeToCollision);
				ballPos.x = ballPos.x + (ballVel.x * timeToCollision);
				_reverseVelVec(colOneT, colTwoT);
				break;
			}
			
			ballPos.y = ballPos.y - (std::abs(ballVel.y) * dt);
			ballPos.x = ballPos.x + (ballVel.x * dt);
			dt = 0.0f;
			break;
		case collisionSides::RIGHT:
			colTwoT = ((double)rightBorder - ballPos.x) / ballVel.x; // right collision time
			
			if (dt > colTwoT) {
				dt -= colTwoT;
				ballPos.x = ballPos.x + (ballVel.x * colTwoT);
				ballVel.x = -ballVel.x;
				break;
			}
			
			ballPos.x = ballPos.x + (ballVel.x * dt);
			dt = 0.0f;
			break;
		case collisionSides::BOTTOM_AND_LEFT:
			colOneT = ((double)bottomBorder - ballPos.y) / ballVel.y; // bottom collision time
			colTwoT = (ballPos.x - (double)leftBorder) / std::abs(ballVel.x); // left collision time
			timeToCollision = (colOneT < colTwoT ? colOneT : colTwoT);

			if (dt > timeToCollision) {
				dt -= timeToCollision;
				ballPos.y = ballPos.y + (ballVel.y * timeToCollision);
				ballPos.x = ballPos.x - (std::abs(ballVel.x) * timeToCollision);
				_reverseVelVec(colOneT, colTwoT);
				break;
			}
			
			ballPos.y = ballPos.y + (ballVel.y * dt);
			ballPos.x = ballPos.x - (std::abs(ballVel.x) * dt);
			dt = 0.0f;
			break;
		case collisionSides::TOP_AND_LEFT:
			colOneT = std::abs((ballPos.y - (double)topBorder) / ballVel.y); // top collision time
			colTwoT = (ballPos.x - (double)leftBorder) / std::abs(ballVel.x); // left collision time
			timeToCollision = (colOneT < colTwoT ? colOneT : colTwoT);

			if (dt > timeToCollision) {
				dt -= timeToCollision;
				ballPos.y = ballPos.y - (std::abs(ballVel.y) * timeToCollision);
				ballPos.x = ballPos.x - (std::abs(ballVel.x) * timeToCollision);
				_reverseVelVec(colOneT, colTwoT);
				break;
			}

			ballPos.y = ballPos.y - (std::abs(ballVel.y) * dt);
			ballPos.x = ballPos.x - (std::abs(ballVel.x) * dt);
			dt = 0.0f;
			break;
		case collisionSides::LEFT:
			colTwoT = (ballPos.x - (double)leftBorder) / std::abs(ballVel.x); // left collision time

			if (dt > colTwoT) {
				dt -= colTwoT;
				ballPos.x = ballPos.x - (std::abs(ballVel.x) * colTwoT);
				ballVel.x = -ballVel.x;
				break;
			}

			ballPos.x = ballPos.x - (std::abs(ballVel.x) * dt);
			dt = 0.0f;
			break;
		case collisionSides::BOTTOM:
			colOneT = ((double)bottomBorder - ballPos.y) / ballVel.y; // bottom collision time

			if (dt > colOneT) {
				dt -= colOneT;
				ballPos.y = ballPos.y + (ballVel.y * colOneT);
				ballVel.y = -ballVel.y;
				break;
			}

			ballPos.y = ballPos.y + (ballVel.y * colOneT);
			dt = 0.0f;
			break;
		case collisionSides::TOP:
			colOneT = std::abs((ballPos.y - (double)topBorder) / ballVel.y); // top collision time

			if (dt > colOneT) {
				dt -= colOneT;
				ballPos.y = ballPos.y - (std::abs(ballVel.y) * colOneT);
				ballVel.y = -ballVel.y;
				break;
			}

			ballPos.y = ballPos.y - (std::abs(ballVel.y) * dt);
			dt = 0.0f;
			break;
		case collisionSides::NONE:
			// if predicted collisionSides is equal to NONE then it means that ball is not moving at all
			break;
		}
	}

	void _reverseVelVec(double& colOneT, double& colTwoT) {
		using namespace AppInitializers;
		if (colOneT < colTwoT) {
			gBall->mVelocity.y = -gBall->mVelocity.y;
			return;
		}
		else if (colOneT > colTwoT) {
			gBall->mVelocity.x = -gBall->mVelocity.x;
			return;
		}

		gBall->mVelocity.y = -gBall->mVelocity.y;
		gBall->mVelocity.x = -gBall->mVelocity.x;
		return;
	}

	AppConsts::collisionSides _probableCollisionSides() {
		using namespace AppInitializers;
		using namespace AppConsts;

		Vec2& ballVel = gBall->mVelocity;

		if (ballVel.x > 0) {
			if (ballVel.y > 0) {
				return collisionSides::BOTTOM_AND_RIGHT;
			}
			else if (ballVel.y < 0) {
				return collisionSides::TOP_AND_RIGHT;
			}

			return collisionSides::RIGHT;
		}
		else if (ballVel.x < 0) {
			if (ballVel.y > 0) {
				return collisionSides::BOTTOM_AND_LEFT;
			}
			else if (ballVel.y < 0) {
				return collisionSides::TOP_AND_LEFT;
			}

			return collisionSides::LEFT;
		}

		if (ballVel.y > 0) {
			return collisionSides::BOTTOM;
		}
		else if (ballVel.y < 0) {
			return collisionSides::TOP;
		}

		return collisionSides::NONE;
	}
}
