#include "../../Header Files/Namespaces/AppConsts.h"

const int AppConsts::G_CLIENT_WIDTH = 640;
const int AppConsts::G_CLIENT_HEIGHT = 480;
const int AppConsts::G_WINDOW_WIDTH = AppConsts::G_CLIENT_WIDTH + 16;
const int AppConsts::G_WINDOW_HEIGHT = AppConsts::G_CLIENT_HEIGHT + 58;
const std::wstring AppConsts::G_WINDOW_CAPTION = L"Pong Game";
const short int AppConsts::SLEEP_TIME_IN_MS = 10;
const Vec2 AppConsts::G_CLIENT_CENTER{AppConsts::G_CLIENT_WIDTH / 2, AppConsts::G_CLIENT_HEIGHT /2};
