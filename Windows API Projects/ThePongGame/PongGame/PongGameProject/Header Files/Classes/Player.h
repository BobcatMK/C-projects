#pragma once
#include "../Namespaces/AppConsts.h"
#include "../Namespaces/AppInitializers.h"

class Player {
public:
	AppConsts::GAME_SETTINGS getSidePlayingOn();
	bool getSpeedBoostAvailable();
	std::shared_ptr<SpriteWithoutMask>& getRacketBm();
	std::shared_ptr<SpriteWithoutMask>& getSpeedBoostBm();
protected:
	Player() {};
	Player(AppConsts::GAME_SETTINGS sidePlayingOn, bool speedBoostAvailable, std::shared_ptr<SpriteWithoutMask>& racketBm, std::shared_ptr<SpriteWithoutMask>& speedBoostBm);
	AppConsts::GAME_SETTINGS mSidePlayingOn;
	bool mSpeedBoostAvailable;
	std::shared_ptr<SpriteWithoutMask> mRacketBm;
	std::shared_ptr<SpriteWithoutMask> mSpeedBoostBm;
};
