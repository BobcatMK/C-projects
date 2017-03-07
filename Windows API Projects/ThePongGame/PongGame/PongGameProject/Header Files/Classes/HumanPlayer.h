#pragma once
#include "Player.h"

class HumanPlayer : public Player {
public:
	HumanPlayer(AppConsts::GAME_SETTINGS sidePlayingOn, bool speedBoostAvailable, std::shared_ptr<SpriteWithoutMask>& racketBm, std::shared_ptr<SpriteWithoutMask>& speedBoostBm);
private:
	HumanPlayer() {};
};
