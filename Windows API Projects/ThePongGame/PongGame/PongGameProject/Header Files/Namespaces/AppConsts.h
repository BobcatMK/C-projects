#pragma once

#include <string>
#include "../Classes/Vec2.h"

namespace AppConsts {
	extern const int G_CLIENT_WIDTH;
	extern const int G_CLIENT_HEIGHT;
	extern const Vec2 G_CLIENT_CENTER;

	extern const int G_WINDOW_WIDTH;
	extern const int G_WINDOW_HEIGHT;
	
	extern const std::wstring G_WINDOW_CAPTION;

	extern const short int SLEEP_TIME_IN_MS;

	enum class GAME_PHASES {
		INITIAL_MENU = 0,
			NEW_GAME_MENU = 1,
				CHOOSE_AI_DIFFICULTY_MENU = 2,
				CHOOSE_SIDE_MENU = 3,
					HUMAN_P1_VS_AI_GAME = 4,
				HUMAN_P1_VS_HUMAN_P2_GAME = 5,
				AI_VS_AI_GAME = 6,
			OPTIONS_MENU = 7,
			CREDITS_MENU = 8,
		EXIT_GAME = 9,
		NONE = 10
	};

	enum class GAME_SETTINGS {
		NONE = 0,
		DIFFICULTY_EASY = 1,
		DIFFICULTY_MEDIUM = 2,
		DIFFICULTY_HARD = 3,
		SIDE_LEFT = 4,
		SIDE_RIGHT = 5,
		SPEED_SLOW = 6,
		SPEED_NORMAL = 7,
		SPEED_FAST = 8
	};
	//enum class MENU_ITEMS {
	//	NONE = 0,
	//	BACK = 1,
	//	NEW_GAME = 2,
	//		HUMAN_P1_VS_AI = 3,
	//			EASY = 4,
	//			MEDIUM = 5,
	//			HARD = 6,
	//				LEFT = 7,
	//				RIGHT = 8,
	//		HUMAN_P1_VS_HUMAN_P2 = 9,
	//		AI_VS_AI = 10,
	//	OPTIONS = 11,
	//		SLOW = 12,
	//		NORMAL = 13,
	//		FAST = 14,
	//	CREDITS = 15,
	//	EXIT_GAME = 16
	//};
}
