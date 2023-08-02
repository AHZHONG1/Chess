#pragma once

enum class State { MainMenuState, InGameState, PauseState, GameSettingState };

enum class Player { White, Black, None };

enum class GameMode { PVPOffline, AIOffline, PVPOnline, None };

int absolute(int, int);