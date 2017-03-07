#include "../../Header Files/Classes/AIPlayer.h"

AIPlayer::AIPlayer(AppConsts::GAME_SETTINGS sidePlayingOn, bool speedBoostAvailable, std::shared_ptr<SpriteWithoutMask>& racketBm, std::shared_ptr<SpriteWithoutMask>& speedBoostBm, AppConsts::GAME_SETTINGS difficultyLevel) : Player(sidePlayingOn, speedBoostAvailable, racketBm, speedBoostBm) {
	mDifficultyLevel = difficultyLevel;
}
