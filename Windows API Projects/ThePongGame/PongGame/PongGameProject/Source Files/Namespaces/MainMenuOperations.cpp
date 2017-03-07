#include "../../Header Files/Namespaces/MainMenuOperations.h"

void MainMenuOperations::WindowCreatedInitializer(HWND hWnd) {
	using namespace AppInitializers;
	using namespace AppConsts;

	GCurrentGamePhase = GAME_PHASES::INITIAL_MENU;
	//GActiveMenuItem = MENU_ITEMS::NONE;
	GActiveMenuItem = nullptr;
	GhSpriteDC = CreateCompatibleDC(NULL);
	GBackBuffer = new BackBuffer(hWnd, G_CLIENT_WIDTH, G_CLIENT_HEIGHT);

	// common bitmaps	
	GBlackBackground = new SpriteWithoutMask(GhAppInst, BLACK_BACKGROUND_BM, G_CLIENT_CENTER, Vec2(0.0f, 0.0f));
	GMenuCopyrights = new SpriteWithoutMask(GhAppInst, MENU_COPYRIGHTS_BM, Vec2(320, 417), Vec2(0.0f, 0.0f));
	GMenuFrame = new SpriteWithoutMask(GhAppInst, MENU_FRAME_BM, Vec2(320, 240), Vec2(0.0f, 0.0f));
	GMenuThePongGameLogo = new SpriteWithoutMask(GhAppInst, MENU_THE_PONG_GAME_LOGO_BM, Vec2(320, 86), Vec2(0.0f, 0.0f));
	GMenuItemBack = new MenuItemSpriteWithoutMask(GhAppInst, MENU_ITEM_BACK_BM, MENU_ITEM_BACK_ACTIVE_BM, Vec2(321, 191), GAME_PHASES::NONE); // this sprite's game_phases part will have to be changed dinamically
    GF1HowToPlayHint.reset(new SpriteWithoutMask(GhAppInst, F1_HOW_TO_PLAY_HINT, Vec2(321, 135), Vec2(0.0f, 0.0f)));

	// Gameplay view
	GHashLine.reset(new SpriteWithoutMask(GhAppInst, HASH_LINE_BM, Vec2(320, 240), Vec2(0.0f, 0.0f)));
	GPlayerOneRacket.reset(new SpriteWithoutMask(GhAppInst, RACKET_BM, Vec2(8, 240), Vec2(0.0f, 0.0f)));
	GPlayerTwoRacket.reset(new SpriteWithoutMask(GhAppInst, RACKET_BM, Vec2(633, 240), Vec2(0.0f, 0.0f)));
	GPlayerOneSpeedBoost.reset(new SpriteWithoutMask(GhAppInst, SPEED_BOOST_PLUS_SIGN_BM, Vec2(8, 240), Vec2(0.0f, 0.0f)));
	GPlayerTwoSpeedBoost.reset(new SpriteWithoutMask(GhAppInst, SPEED_BOOST_PLUS_SIGN_BM, Vec2(633, 240), Vec2(0.0f, 0.0f)));
	GBall.reset(new SpriteWithoutMask(GhAppInst, BALL_BM, Vec2(200, 200), Vec2(0.0f, 0.0f)));

	// Main Menu View
	GMenuItemNewGame = new MenuItemSpriteWithoutMask(GhAppInst, MENU_ITEM_NEW_GAME_BM, MENU_ITEM_NEW_GAME_ACTIVE_BM, Vec2(321, 191), GAME_PHASES::NEW_GAME_MENU);
	GMenuItemOptions = new MenuItemSpriteWithoutMask(GhAppInst, MENU_ITEM_OPTIONS_BM, MENU_ITEM_OPTIONS_ACTIVE_BM, Vec2(321, 235), GAME_PHASES::OPTIONS_MENU);
	GMenuItemCredits = new MenuItemSpriteWithoutMask(GhAppInst, MENU_ITEM_CREDITS_BM, MENU_ITEM_CREDITS_ACTIVE_BM, Vec2(321, 279), GAME_PHASES::CREDITS_MENU);
	GMenuItemExitGame = new MenuItemSpriteWithoutMask(GhAppInst, MENU_ITEM_EXIT_GAME_BM, MENU_ITEM_EXIT_GAME_ACTIVE_BM, Vec2(321, 322), GAME_PHASES::EXIT_GAME);

	// New Game View
	GMenuItemAIvsAI = new MenuItemSpriteWithoutMask(GhAppInst, MENU_ITEM_AI_VS_AI_BM, MENU_ITEM_AI_VS_AI_ACTIVE_BM, Vec2(321, 322), GAME_PHASES::AI_VS_AI_GAME);
	GMenuItemP1vsAI = new MenuItemSpriteWithoutMask(GhAppInst, MENU_ITEM_P1_VS_AI_BM, MENU_ITEM_P1_VS_AI_ACTIVE_BM, Vec2(321, 235), GAME_PHASES::CHOOSE_AI_DIFFICULTY_MENU);
	GMenuItemP1vsP2 = new MenuItemSpriteWithoutMask(GhAppInst, MENU_ITEM_P1_VS_P2_BM, MENU_ITEM_P1_VS_P2_ACTIVE_BM, Vec2(321, 279), GAME_PHASES::HUMAN_P1_VS_HUMAN_P2_GAME);

	// AI Difficulty View
	GMenuDifficulty = new SpriteWithoutMask(GhAppInst, MENU_DIFFICULTY_BM, Vec2(321, 235), Vec2(0.0f, 0.0f));
	GMenuItemEasy = new MenuItemSpriteWithoutMask(GhAppInst, MENU_ITEM_EASY_BM, MENU_ITEM_EASY_ACTIVE_BM, Vec2(321, 279), GAME_PHASES::CHOOSE_SIDE_MENU, GAME_SETTINGS::DIFFICULTY_EASY);
	GMenuItemMedium = new MenuItemSpriteWithoutMask(GhAppInst, MENU_ITEM_MEDIUM_BM, MENU_ITEM_MEDIUM_ACTIVE_BM, Vec2(321, 322), GAME_PHASES::CHOOSE_SIDE_MENU, GAME_SETTINGS::DIFFICULTY_MEDIUM);
	GMenuItemHard = new MenuItemSpriteWithoutMask(GhAppInst, MENU_ITEM_HARD_BM, MENU_ITEM_HARD_ACTIVE_BM, Vec2(321, 365), GAME_PHASES::CHOOSE_SIDE_MENU, GAME_SETTINGS::DIFFICULTY_HARD);

	// Choose Side View
	GMenuChooseSide = new SpriteWithoutMask(GhAppInst, MENU_CHOOSE_SIDE_BM, Vec2(321, 235), Vec2(0.0f, 0.0f));
	GMenuItemLeft = new MenuItemSpriteWithoutMask(GhAppInst, MENU_ITEM_LEFT_BM, MENU_ITEM_LEFT_ACTIVE_BM, Vec2(321, 279), GAME_PHASES::HUMAN_P1_VS_AI_GAME, GAME_SETTINGS::SIDE_LEFT);
	GMenuItemRight = new MenuItemSpriteWithoutMask(GhAppInst, MENU_ITEM_RIGHT_BM, MENU_ITEM_RIGHT_ACTIVE_BM, Vec2(321, 322), GAME_PHASES::HUMAN_P1_VS_AI_GAME, GAME_SETTINGS::SIDE_RIGHT);

	// Options View
	GMenuGameSpeed = new SpriteWithoutMask(GhAppInst, MENU_GAME_SPEED_BM, Vec2(321, 235), Vec2(0.0f, 0.0f));
	GMenuItemSlow = new MenuItemSpriteWithoutMask(GhAppInst, MENU_ITEM_SLOW_BM, MENU_ITEM_SLOW_ACTIVE_BM, Vec2(321, 279), GAME_PHASES::NONE, GAME_SETTINGS::SPEED_SLOW);
	GMenuItemNormal = new MenuItemSpriteWithoutMask(GhAppInst, MENU_ITEM_NORMAL_BM, MENU_ITEM_NORMAL_ACTIVE_BM, Vec2(321, 322), GAME_PHASES::NONE, GAME_SETTINGS::SPEED_NORMAL);
	GMenuItemFast = new MenuItemSpriteWithoutMask(GhAppInst, MENU_ITEM_FAST_BM, MENU_ITEM_FAST_ACTIVE_BM, Vec2(321, 365), GAME_PHASES::NONE, GAME_SETTINGS::SPEED_FAST);

	// Credits View
	GMenuCreditsText = new SpriteWithoutMask(GhAppInst, MENU_CREDITS_TEXT_BM, Vec2(328, 269), Vec2(0.0f, 0.0f));
	GMenuItemCreditsBack = new MenuItemSpriteWithoutMask(GhAppInst, MENU_ITEM_BACK_BM, MENU_ITEM_BACK_ACTIVE_BM, Vec2(321, 175), GAME_PHASES::INITIAL_MENU);

	// HowToPLay View
	GMenuHowToPlay.reset(new SpriteWithoutMask(GhAppInst, MENU_HOW_TO_PLAY_BM, Vec2(320, 240), Vec2(0.0f, 0.0f)));
}

void MainMenuOperations::DrawInitialMenu() {
	using namespace AppInitializers;

	MainMenuOperations::DrawCommonMenuParts(true);
	GCurrentMenuItems.clear();
	GCurrentMenuItems.push_back(GMenuItemNewGame->drawMenuItem());
	GCurrentMenuItems.push_back(GMenuItemOptions->drawMenuItem());
	GCurrentMenuItems.push_back(GMenuItemCredits->drawMenuItem());
	GCurrentMenuItems.push_back(GMenuItemExitGame->drawMenuItem());

	GBackBuffer->present();
}

void MainMenuOperations::DrawNewGameMenu() {
    using namespace AppInitializers;
    using namespace AppConsts;

    MainMenuOperations::DrawCommonMenuParts(true);
    GCurrentMenuItems.clear();
    GMenuItemBack->mMainMenuOrGameTypeToActivateOnClick = GAME_PHASES::INITIAL_MENU;
    GCurrentMenuItems.push_back(GMenuItemBack->drawMenuItem());
    GCurrentMenuItems.push_back(GMenuItemAIvsAI->drawMenuItem());
    GCurrentMenuItems.push_back(GMenuItemP1vsAI->drawMenuItem());
    GCurrentMenuItems.push_back(GMenuItemP1vsP2->drawMenuItem());
}

void MainMenuOperations::DrawChooseAIDifficultyMenu() {
    using namespace AppInitializers;
    using namespace AppConsts;

    MainMenuOperations::DrawCommonMenuParts(true);
    GMenuDifficulty->draw();

    GCurrentMenuItems.clear();
    GMenuItemBack->mMainMenuOrGameTypeToActivateOnClick = GAME_PHASES::NEW_GAME_MENU;
    GCurrentMenuItems.push_back(GMenuItemBack->drawMenuItem());
    GCurrentMenuItems.push_back(GMenuItemEasy->drawMenuItem());
    GCurrentMenuItems.push_back(GMenuItemMedium->drawMenuItem());
    GCurrentMenuItems.push_back(GMenuItemHard->drawMenuItem());
}

void MainMenuOperations::DrawChooseSideMenu() {
    using namespace AppInitializers;
    using namespace AppConsts;

    MainMenuOperations::DrawCommonMenuParts(true);
    GMenuChooseSide->draw();

    GCurrentMenuItems.clear();
    GMenuItemBack->mMainMenuOrGameTypeToActivateOnClick = GAME_PHASES::CHOOSE_AI_DIFFICULTY_MENU;
    GCurrentMenuItems.push_back(GMenuItemBack->drawMenuItem());
    GCurrentMenuItems.push_back(GMenuItemLeft->drawMenuItem());
    GCurrentMenuItems.push_back(GMenuItemRight->drawMenuItem());
}

void MainMenuOperations::DrawOptionsMenu() {
    using namespace AppInitializers;
    using namespace AppConsts;

    MainMenuOperations::DrawCommonMenuParts(true);
    GMenuGameSpeed->draw();

    GCurrentMenuItems.clear();
    GMenuItemBack->mMainMenuOrGameTypeToActivateOnClick = GAME_PHASES::INITIAL_MENU;
    GCurrentMenuItems.push_back(GMenuItemBack->drawMenuItem());
    GCurrentMenuItems.push_back(GMenuItemSlow->drawMenuItem());
    GCurrentMenuItems.push_back(GMenuItemNormal->drawMenuItem());
    GCurrentMenuItems.push_back(GMenuItemFast->drawMenuItem());

    MainMenuOperations::VisuallyActivateSpeedSetting();
}

void MainMenuOperations::DrawCreditsMenu() {
    using namespace AppInitializers;
    using namespace AppConsts;

    MainMenuOperations::DrawCommonMenuParts(false);
    GMenuCreditsText->draw();

    GCurrentMenuItems.clear();
    GCurrentMenuItems.push_back(GMenuItemCreditsBack->drawMenuItem());
}

void MainMenuOperations::DrawCommonMenuParts(bool drawMenuFrame) {
	using namespace AppInitializers;

	if (drawMenuFrame) {
		GMenuFrame->draw();
	}
	else {
		GBlackBackground->draw();
	}
	GMenuCopyrights->draw();
	GMenuThePongGameLogo->draw();
    GF1HowToPlayHint->draw();
}

bool MainMenuOperations::MouseCursorIsOverMenuItem(MenuItemSpriteWithoutMask* menuItem, short int mouseCoordinateX, short int mouseCoordinateY) {
	if (
		mouseCoordinateX >= menuItem->mUpperLeftCorner.x &&
		mouseCoordinateX <= menuItem->mLowerRightCorner.x &&
		mouseCoordinateY >= menuItem->mUpperLeftCorner.y &&
		mouseCoordinateY <= menuItem->mLowerRightCorner.y
		) {
		return true;
	}

	return false;
}

//OutputDebugStringW(L"aaaaaaaaaaaaa ");
//OutputDebugStringW(std::to_wstring(mouseCoordinateX).c_str());
//OutputDebugStringW(L"aaaaaaaaaaa ");
//OutputDebugStringW(std::to_wstring(mouseCoordinateY).c_str());

void MainMenuOperations::ActivateAndDeactivateMenuItem(short int mouseCoordinateX, short int mouseCoordinateY) {
	using namespace AppInitializers;
	// przy pomocy najechania nie mozna dezaktywowac settinga, setting moze byc dezaktywowany tylko poprzez klika na innego settinga z tej samej rodziny.
	// najlepiej by bylo zrobic tak - dodac tutaj informacje o tym, ze ma ta funkcja ma nie robic zadnych dzia³an majacych na celu dezaktywacje aktywnego setting menu item'a.
	// reszte dzialan moze wykonywac, ale nie moze dezaktywowac aktywny setting menu item - koniec kropka.
	// Aby zrealizowac to zadanie, bedzie konieczne dodanie funkcji, ktora bedzie odpowiedzialna za zwracanie pointera na setting menu item , ktory jest aktywny bazujac na aktualnej
	// wartosci zmiennej globalnej GSettingSpeed.

	MenuItemSpriteWithoutMask* menuItemToActivate = nullptr;
	// Patrze czy caly czas myszka jest na tym samym menu itemie , jezeli tak to nic nie robie.
	if (GActiveMenuItem != nullptr && MainMenuOperations::MouseCursorIsOverMenuItem(GActiveMenuItem, mouseCoordinateX, mouseCoordinateY)) {
		return;
	}

	for (auto constIt = GCurrentMenuItems.cbegin(); constIt != GCurrentMenuItems.cend(); ++constIt) {
		if (MainMenuOperations::MouseCursorIsOverMenuItem(*constIt, mouseCoordinateX, mouseCoordinateY)) {
			menuItemToActivate = *constIt;
		}
	}

	// oznacza to, ze jezdze sobie myszka gdzies po bokach i nic nie aktywuje ani dezaktywuje
	if (menuItemToActivate == nullptr && GActiveMenuItem == nullptr) {
		return;
	}

	// oznacza to, ze trzeba ten GActiveMenuItem dezaktywowac
	// ale nie ma go dezaktywowac jezeli ten menu item jest settingiem i jest aktywny
	if (GActiveMenuItem != nullptr) {
		if (GActiveMenuItem != MainMenuOperations::GetPointerToCurrentSpeedSettingSprite()) {
			GActiveMenuItem->drawMenuItem();
		}
		GActiveMenuItem = nullptr;
	}

	// jest menu item do aktywacji, trzeba go aktywowac
	if (menuItemToActivate != nullptr) {
		GActiveMenuItem = menuItemToActivate;
		menuItemToActivate->drawMenuItemActive();
	}

	GBackBuffer->present();
}

void MainMenuOperations::GenerateMenuViewBasedOnGCurrentGamePhase() {
    using namespace AppInitializers;
    using namespace AppConsts;

    switch (GCurrentGamePhase) {
    case GAME_PHASES::INITIAL_MENU:
        MainMenuOperations::DrawInitialMenu();
        break;
    case GAME_PHASES::NEW_GAME_MENU:
        MainMenuOperations::DrawNewGameMenu();
        break;
    case GAME_PHASES::CHOOSE_AI_DIFFICULTY_MENU:
        MainMenuOperations::DrawChooseAIDifficultyMenu();
        break;
    case GAME_PHASES::CHOOSE_SIDE_MENU:
        MainMenuOperations::DrawChooseSideMenu();
        break;
    // this commented code below should not be needed. When game will start game screen will be regenerated based on game loop
    //case GAME_PHASES::HUMAN_P1_VS_AI_GAME:
    //case GAME_PHASES::HUMAN_P1_VS_HUMAN_P2_GAME:
    //case GAME_PHASES::AI_VS_AI_GAME:
    //    MainMenuOperations::DrawGame();
        break;
    case GAME_PHASES::OPTIONS_MENU:
        MainMenuOperations::DrawOptionsMenu();
        break;
    case GAME_PHASES::CREDITS_MENU:
        MainMenuOperations::DrawCreditsMenu();
        break;
    }

    GActiveMenuItem = nullptr; // TODO - check if this should be commented or not - I'm not sure at this point.
    GBackBuffer->present();
}

void MainMenuOperations::ChangeMenuOrRunGameBasedOnGActiveMenuItem() {
	using namespace AppInitializers;
	using namespace AppConsts;

	switch (GActiveMenuItem->mMainMenuOrGameTypeToActivateOnClick) {
	case GAME_PHASES::INITIAL_MENU:
        GCurrentGamePhase = GAME_PHASES::INITIAL_MENU;
		MainMenuOperations::DrawInitialMenu();
		break;
	case GAME_PHASES::NEW_GAME_MENU:
        GCurrentGamePhase = GAME_PHASES::NEW_GAME_MENU;
        MainMenuOperations::DrawNewGameMenu();
		break;
	case GAME_PHASES::CHOOSE_AI_DIFFICULTY_MENU:
        GCurrentGamePhase = GAME_PHASES::CHOOSE_AI_DIFFICULTY_MENU;
        MainMenuOperations::DrawChooseAIDifficultyMenu();
		break;
	case GAME_PHASES::CHOOSE_SIDE_MENU:
        GCurrentGamePhase = GAME_PHASES::CHOOSE_SIDE_MENU;
        MainMenuOperations::ChangeDifficultySetting();
        MainMenuOperations::DrawChooseSideMenu();
		break;
	case GAME_PHASES::HUMAN_P1_VS_AI_GAME:
        GCurrentGamePhase = GAME_PHASES::HUMAN_P1_VS_AI_GAME;
        MainMenuOperations::ChangeSideSetting();

		if (GSettingSide == GAME_SETTINGS::SIDE_LEFT) {
			GPlayerOne.reset(new HumanPlayer(GSettingSide, true, GPlayerOneRacket, GPlayerOneSpeedBoost));
			GPlayerTwo.reset(new AIPlayer(GAME_SETTINGS::SIDE_RIGHT, true, GPlayerTwoRacket, GPlayerTwoSpeedBoost, GSettingDifficulty));
		}
		else if (GSettingSide == GAME_SETTINGS::SIDE_RIGHT) {
			GPlayerOne.reset(new AIPlayer(GAME_SETTINGS::SIDE_LEFT, true, GPlayerOneRacket, GPlayerOneSpeedBoost, GSettingDifficulty));
			GPlayerTwo.reset(new HumanPlayer(GSettingSide, true, GPlayerTwoRacket, GPlayerTwoSpeedBoost));
		}
		MainMenuOperations::DrawGame();
		break;
	case GAME_PHASES::HUMAN_P1_VS_HUMAN_P2_GAME:
		GCurrentGamePhase = GAME_PHASES::HUMAN_P1_VS_HUMAN_P2_GAME;
		GPlayerOne.reset(new HumanPlayer(GSettingSide, true, GPlayerOneRacket, GPlayerOneSpeedBoost));
		GPlayerTwo.reset(new HumanPlayer(GSettingSide, true, GPlayerTwoRacket, GPlayerTwoSpeedBoost));
		MainMenuOperations::DrawGame();
		break;
	case GAME_PHASES::AI_VS_AI_GAME:
        GCurrentGamePhase = GAME_PHASES::AI_VS_AI_GAME;
		GPlayerOne.reset(new AIPlayer(GAME_SETTINGS::SIDE_LEFT, true, GPlayerOneRacket, GPlayerOneSpeedBoost, GAME_SETTINGS::DIFFICULTY_HARD)); // AI should play with each other always on hard difficulty
		GPlayerTwo.reset(new AIPlayer(GAME_SETTINGS::SIDE_RIGHT, true, GPlayerTwoRacket, GPlayerTwoSpeedBoost, GAME_SETTINGS::DIFFICULTY_HARD)); // AI should play with each other always on hard difficulty
		MainMenuOperations::DrawGame();
		break;
	case GAME_PHASES::OPTIONS_MENU:
        GCurrentGamePhase = GAME_PHASES::OPTIONS_MENU;
        MainMenuOperations::DrawOptionsMenu();
		break;
	case GAME_PHASES::CREDITS_MENU:
        GCurrentGamePhase = GAME_PHASES::CREDITS_MENU;
        MainMenuOperations::DrawCreditsMenu();
		break;
	case GAME_PHASES::EXIT_GAME:
		DestroyWindow(GhMainWnd);
		break;
	case GAME_PHASES::NONE:
		MainMenuOperations::ChangeAndVisuallyDeactivateOldSpeedSetting();
		MainMenuOperations::VisuallyActivateSpeedSetting();
		break;
	}

	GActiveMenuItem = nullptr;
	GBackBuffer->present();
}

void MainMenuOperations::ChangeDifficultySetting() {
	using namespace AppInitializers;
	using namespace AppConsts;

	AppConsts::GAME_SETTINGS newDifficultySetting = GActiveMenuItem->mSettingToActiveOnClick;

	switch (newDifficultySetting) {
	case GAME_SETTINGS::DIFFICULTY_EASY:
	case GAME_SETTINGS::DIFFICULTY_MEDIUM:
	case GAME_SETTINGS::DIFFICULTY_HARD:
		GSettingDifficulty = newDifficultySetting;
		return;
	}
}

void MainMenuOperations::ChangeSideSetting() {
	using namespace AppInitializers;
	using namespace AppConsts;

	AppConsts::GAME_SETTINGS newSideSetting = GActiveMenuItem->mSettingToActiveOnClick;

	switch (newSideSetting) {
	case GAME_SETTINGS::SIDE_LEFT:
	case GAME_SETTINGS::SIDE_RIGHT:
		GSettingSide = newSideSetting;
		return;
	}
}

void MainMenuOperations::ChangeAndVisuallyDeactivateOldSpeedSetting() {
	using namespace AppInitializers;
	using namespace AppConsts;

	GAME_SETTINGS speedSettingToChange = GActiveMenuItem->mSettingToActiveOnClick;
	// visually deactivating old speed setting
	MainMenuOperations::GetPointerToCurrentSpeedSettingSprite()->drawMenuItem();

	// change speed setting
	GSettingSpeed = speedSettingToChange;
}

void MainMenuOperations::VisuallyActivateSpeedSetting() {
	using namespace AppInitializers;
	using namespace AppConsts;

	MainMenuOperations::GetPointerToCurrentSpeedSettingSprite()->drawMenuItemActive();
}

MenuItemSpriteWithoutMask* MainMenuOperations::GetPointerToCurrentSpeedSettingSprite() {
	using namespace AppInitializers;
	using namespace AppConsts;

	switch (GSettingSpeed) {
	case GAME_SETTINGS::SPEED_SLOW:
		return GMenuItemSlow;
	case GAME_SETTINGS::SPEED_NORMAL:
		return GMenuItemNormal;
	case GAME_SETTINGS::SPEED_FAST:
		return GMenuItemFast;
	}

	// add service of case which is not included inside switch statement. If it will happen then it means that
	// there is an error inside program. I can add noexcept to this function as it will never throw error.
	// I can return some default option to get rid of warning, leave it as it is or create popup windows menu with
	// message "Dude... come on...".
}

bool MainMenuOperations::IsCurrentPhaseGamePhase() {
	using namespace AppInitializers;
	using namespace AppConsts;

	switch (GCurrentGamePhase) {
	case GAME_PHASES::HUMAN_P1_VS_AI_GAME:
	case GAME_PHASES::HUMAN_P1_VS_HUMAN_P2_GAME:
	case GAME_PHASES::AI_VS_AI_GAME:
		return true;
	}

	return false;
}

void MainMenuOperations::DrawGame() {
	using namespace AppInitializers;

	GBlackBackground->draw();
	GHashLine->draw();
	GBall->draw();
	// TODO - mozliwe ze trzeba bedzie sprawdzic czy speed boost jest dostepny zanim sie go tutaj narysuje, dlatego, ze chyba
	// ta funkcja bedzie wywolywana jak ktos wylaczy menu w trakcie rozgrywki albo wylaczy F1 How To Play menu.
	GPlayerOne->getRacketBm()->draw();
	GPlayerOne->getSpeedBoostBm()->draw();
	GPlayerTwo->getRacketBm()->draw();
	GPlayerTwo->getSpeedBoostBm()->draw();
}

void MainMenuOperations::DrawHowToPlayMenuAndPresent() {
    using namespace AppInitializers;

    GMenuHowToPlay->draw();
    GBackBuffer->present();
}
