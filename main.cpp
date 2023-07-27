#include <SFML/Graphics.hpp>
#include <iostream>
#include "MainMenu.h"

using namespace std;

int main() {

    enum State { MainMenuState, InGameState };

    int width = 1600, height = 900;
    sf::RenderWindow window(sf::VideoMode(width, height), "Chess", sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    State state = State::MainMenuState;
    MainMenu mainMenu(width, height);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        switch (state) {
        case State::MainMenuState:
            mainMenu.render(&window);
            break;
        case State::InGameState:
            break;
        }
    }

    return 0;
}