#include "AppConsts.h"

const std::wstring AppConsts::gWndCaption = L"Bouncing Ball Simulation";
const int AppConsts::gClientWidth = 1280;
const int AppConsts::gClientHeight = 720;
const Vec2 AppConsts::gClientCenter{ AppConsts::gClientWidth / 2, AppConsts::gClientHeight / 2 };
const int AppConsts::gWindowWidth = AppConsts::gClientWidth + 16;
const int AppConsts::gWindowHeight = AppConsts::gClientHeight + 58;

const int AppConsts::SleepTimeInMs = 0;

//velocity increment or decrement for options
const double AppConsts::gVerySlowRatio = 0.4f;
const double AppConsts::gSlowRatio = 0.7f;
const double AppConsts::gNormalRatio = 1.0f;
const double AppConsts::gFastRatio = 1.3f;
const double AppConsts::gVeryFastRatio = 1.6f;

const double AppConsts::gMovePerFrameRatio = 0.01f;

// velocity vector data for ball
// I'm not using vMaxX or vMaxY variables due to the way rand works
const int AppConsts::vMinX = 100;
const int AppConsts::vRangeX = 1;

const int AppConsts::vMinY = 300;
const int AppConsts::vRangeY = 1;
