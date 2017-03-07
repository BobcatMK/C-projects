#include "../../Header Files/Classes/HumanPlayer.h"

HumanPlayer::HumanPlayer(AppConsts::GAME_SETTINGS sidePlayingOn, bool speedBoostAvailable, std::shared_ptr<SpriteWithoutMask>& racketBm, std::shared_ptr<SpriteWithoutMask>& speedBoostBm) : Player(sidePlayingOn, speedBoostAvailable, racketBm, speedBoostBm) {}
