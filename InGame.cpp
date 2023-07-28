#include "InGame.h"
#include "Button.h"
#include <iostream>
#include "ChessBoard.h"

InGame::InGame() {

}

InGame::InGame(int width, int height) {
    board = new ChessBoard();

}

InGame::~InGame() {
    delete board;
}

void InGame::update(sf::RenderWindow* window, State& state) {
    sf::Event event;

    while (window->pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.scancode == sf::Keyboard::Scan::Escape) {
                state = State::PauseState;
            }
            break;
        case sf::Event::LostFocus:
            //state = State::PauseState;
            break;
        }
    }
}

void InGame::render(sf::RenderWindow* window) {
    window->clear(sf::Color::Black);
    board->render(window);
    window->display();
}
