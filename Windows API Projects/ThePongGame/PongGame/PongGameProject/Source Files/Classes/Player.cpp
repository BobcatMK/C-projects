#include "../../Header Files/Classes/Player.h"

Player::Player(AppConsts::GAME_SETTINGS sidePlayingOn, bool speedBoostAvailable, std::shared_ptr<SpriteWithoutMask>& racketBm, std::shared_ptr<SpriteWithoutMask>& speedBoostBm) {
	// sprite paletki + speedBoostReady + sidePlayingOn
	mSidePlayingOn = sidePlayingOn;
	mSpeedBoostAvailable = speedBoostAvailable;
	mRacketBm = racketBm;
	mSpeedBoostBm = speedBoostBm;
}

AppConsts::GAME_SETTINGS Player::getSidePlayingOn() {
	return mSidePlayingOn;
};

bool Player::getSpeedBoostAvailable() {
	return mSpeedBoostAvailable;
};

std::shared_ptr<SpriteWithoutMask>& Player::getRacketBm() {
	return mRacketBm;
};

std::shared_ptr<SpriteWithoutMask>& Player::getSpeedBoostBm() {
	return mSpeedBoostBm;
}