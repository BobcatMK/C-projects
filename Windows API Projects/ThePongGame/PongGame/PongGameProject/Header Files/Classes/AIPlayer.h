#pragma once
#include "Player.h"

class AIPlayer : public Player {
public:
	AIPlayer(AppConsts::GAME_SETTINGS sidePlayingOn, bool speedBoostAvailable, std::shared_ptr<SpriteWithoutMask>& racketBm, std::shared_ptr<SpriteWithoutMask>& speedBoostBm, AppConsts::GAME_SETTINGS difficultyLevel);
private:
	AIPlayer() {};
	AppConsts::GAME_SETTINGS mDifficultyLevel;
};
