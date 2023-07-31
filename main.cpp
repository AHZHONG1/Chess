#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include "General.h"
#include "MainMenu.h"
#include "InGame.h"
#include "PauseMenu.h"
#include "GameSetting.h"

int main() {

    int width = 1600, height = 900;
    sf::RenderWindow window(sf::VideoMode(width, height), "Chess", sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    State state = State::MainMenuState;
    MainMenu* mainMenu = nullptr;
    InGame* inGame = nullptr;
    PauseMenu* pauseMenu = nullptr;
    GameSetting* gameSetting = nullptr;


    while (window.isOpen()) {
        switch (state) {
        case State::MainMenuState:
            if (mainMenu == nullptr) {
                mainMenu = new MainMenu(width, height);
            }
            if (inGame) {
                delete inGame;
                inGame = nullptr;
            }
            mainMenu->update(&window, state);
            mainMenu->render(&window);
            break;
        case State::InGameState:
            if (inGame == nullptr) {
                inGame = new InGame(width, height);
            }
            inGame->update(&window, state);
            inGame->render(&window);
            break;
        case State::PauseState:
            if (pauseMenu == nullptr) {
                pauseMenu = new PauseMenu(width, height);
            }
            pauseMenu->update(&window, state);
            pauseMenu->render(&window);
            break;
        case State::GameSettingState:
            if (gameSetting == nullptr) {
                gameSetting = new GameSetting(width, height);
            }
            gameSetting->update(&window, state);
            gameSetting->render(&window);
            break;
        }
    }

    if (mainMenu) {
        delete mainMenu;
    }
    if (inGame) {
        delete inGame;
    }
    if (pauseMenu) {
        delete pauseMenu;
    }
    if (gameSetting) {
        delete gameSetting;
    }

    return 0;
}