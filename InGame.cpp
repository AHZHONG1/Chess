#include "InGame.h"
#include "Button.h"
#include <iostream>
#include "ChessBoard.h"

InGame::InGame() {

}

InGame::InGame(int width, int height) : dragedPiece(nullptr) {
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
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Left) {
                if (board->overlap(event, dragedPiece)) {
                    std::cout << "Clicked" << std::endl;
                }
            }
            break;
        case sf::Event::MouseButtonReleased:
            if (event.mouseButton.button == sf::Mouse::Left) {
                dragedPiece = nullptr;
                std::cout << "Released" << std::endl;
            }
            break;
        case sf::Event::MouseMoved:
            if (dragedPiece != nullptr) {
                std::cout << event.mouseMove.x << " : " << event.mouseMove.y << std::endl;
                board->drag(event, dragedPiece);
            }
            break;
        }
    }
}

void InGame::render(sf::RenderWindow* window) {
    window->clear(sf::Color::Black);
    board->render(window);
    window->display();
}
