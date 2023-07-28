#include <SFML/Graphics.hpp>
#include <iostream>
#include "State.h"
#include "MainMenu.h"
#include "InGame.h"
#include "PauseMenu.h"

using namespace std;

int main() {

    int width = 1600, height = 900;
    sf::RenderWindow window(sf::VideoMode(width, height), "Chess", sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    State state = State::MainMenuState;
    MainMenu mainMenu(width, height);
    InGame inGame(width, height);
    PauseMenu pauseMenu(width, height);

    while (window.isOpen()) {
        switch (state) {
        case State::MainMenuState:
            mainMenu.update(&window, state);
            mainMenu.render(&window);
            break;
        case State::InGameState:
            inGame.update(&window, state);
            inGame.render(&window);
            break;
        case State::PauseState:
            pauseMenu.update(&window, state);
            pauseMenu.render(&window);
            break;
        }
    }

    return 0;
}