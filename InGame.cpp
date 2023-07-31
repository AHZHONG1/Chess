#include "InGame.h"
#include "Button.h"
#include <iostream>
#include "ChessBoard.h"
#include "Timer.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

InGame::InGame() : dragedPiece(nullptr), timerWhite(new Timer(1, 0, 30, sf::Vector2f(40, 50))), originalPieceX(-1), originalPieceY(-1), turn(Player::White) {

}

InGame::InGame(int width, int height) : board(new ChessBoard()), dragedPiece(nullptr), timerWhite(new Timer(1, 0, 30, sf::Vector2f(40, 50))), timerBlack(new Timer(1, 0, 30, sf::Vector2f(1260, 50))), originalPieceX(-1), originalPieceY(-1), turn(Player::White) {
    if (!backgroundTexture.loadFromFile("./Textures/backgroundImage.jpg")) {
        std::cout << "Cannot load image" << std::endl;
    }

    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0, 0);
    
    
    btn1 = new Button(sf::Vector2f(100, 20), sf::Vector2f(140, 200), "Start", sf::Color::White, sf::Color::Red);
    btn2 = new Button(sf::Vector2f(100, 20), sf::Vector2f(140, 300), "Pause", sf::Color::White, sf::Color::Red);
    btn3 = new Button(sf::Vector2f(100, 20), sf::Vector2f(1340, 200), "Start", sf::Color::White, sf::Color::Red);
    btn4 = new Button(sf::Vector2f(100, 20), sf::Vector2f(1340, 300), "Pause", sf::Color::White, sf::Color::Red);

    start();
}

InGame::~InGame() {
    delete btn1;
    delete btn2;
    delete btn3;
    delete btn4;
    delete board;
    delete timerWhite;
    delete timerBlack;
}

void InGame::start() {
    timerWhite->start();
    timerBlack->start();
}

void InGame::update(sf::RenderWindow* window, State& state) {

    switch (turn) {
    case Player::White:
        timerWhite->start();
        timerBlack->pause();
        break;
    case Player::Black:
        timerWhite->pause();
        timerBlack->start();
        break;
    } 

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
                if (board->overlapPiece(event, dragedPiece, originalPieceX, originalPieceY, turn)) {

                }
                if (btn1->click(event)) {
                    timerWhite->start();
                }
                if (btn2->click(event)) {
                    timerWhite->pause();
                }
                if (btn3->click(event)) {
                    timerBlack->start();
                }
                if (btn4->click(event)) {
                    timerBlack->pause();
                }
            }
            break;
        case sf::Event::MouseButtonReleased:
            if (event.mouseButton.button == sf::Mouse::Left) {
                if (dragedPiece) {
                    if (board->moveValid()) {
                        board->release(event, dragedPiece, originalPieceX, originalPieceY);
                    }
                    
                }
                dragedPiece = nullptr;
            }
            break;
        case sf::Event::MouseMoved:
            if (dragedPiece != nullptr) {
                board->drag(event, dragedPiece);
                board->showPossibleMove();
            }
            break;
        }
    } 
    timerWhite->update();
    timerBlack->update();
    
}

void InGame::render(sf::RenderWindow* window) {
    window->clear(sf::Color::Black);
    window->draw(backgroundSprite);
    timerWhite->render(window);
    timerBlack->render(window);
    btn1->render(window);
    btn2->render(window);
    btn3->render(window);
    btn4->render(window);
    board->render(window);
    window->display();
}
