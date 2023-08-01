#include "InGame.h"
#include "Button.h"
#include <iostream>
#include "ChessBoard.h"
#include "Timer.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "GamePieces.h"
#include "PromotionBox.h"
#include <SFML/System/String.hpp>

InGame::InGame() : dragedPiece(nullptr), timerWhite(new Timer(1, 0, 30, sf::Vector2f(40, 50))), originalPieceX(-1), originalPieceY(-1), turn(Player::White), bjustMove(false), promotionbox(nullptr) {

}

InGame::InGame(int width, int height) : board(new ChessBoard()), dragedPiece(nullptr), timerWhite(new Timer(0, 0, 30, sf::Vector2f(40, 50))), timerBlack(new Timer(1, 0, 30, sf::Vector2f(1260, 50))), originalPieceX(-1), originalPieceY(-1), turn(Player::White), bjustMove(false), promotionbox(nullptr) {
    if (!backgroundTexture.loadFromFile("./Textures/backgroundImage.jpg")) {
        std::cout << "Cannot load image" << std::endl;
    }

    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0, 0);

    start();
}

InGame::~InGame() {
    delete board;
    delete timerWhite;
    delete timerBlack;
}

void InGame::start() {
    timerWhite->start();
    timerBlack->start();
}

bool InGame::checkEndGameCondition(Player turn) {
    if (board->isCheckmate(turn)) {
        return true;
    }
    
    if (board->isStalemate(turn)) {
        return true;
    }
    return false;
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

    if (timerWhite->isEnd() || timerBlack->isEnd()) {
        timerWhite->pause();
        timerBlack->pause();
        std::cout << "End Game" << std::endl;
        state = State::MainMenuState;
    }

    if (bjustMove) {
        if (checkEndGameCondition(turn)) {
            timerWhite->pause();
            timerBlack->pause();
            std::cout << "End Game" << std::endl;
            state = State::MainMenuState;
        }
        bjustMove = false;
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
                if (!board->isPromotion() && board->overlapPiece(event, dragedPiece, originalPieceX, originalPieceY, turn)) {

                }
                sf::String piece = "";
                if (board->isPromotion() && promotionbox->overlapPiece(event, piece)) {
                    board->setPromotion(false);
                    board->promotion(piece, turn);
                    delete promotionbox;
                    bjustMove = true;
                    turn = (turn == Player::White) ? Player::Black : Player::White;
                }
            }
            break;
        case sf::Event::MouseButtonReleased:
            if (event.mouseButton.button == sf::Mouse::Left) {
                if (dragedPiece) {
                    if (!board->moveValid(event, dragedPiece, originalPieceY, originalPieceX, turn)) {
                        dragedPiece->place(originalPieceX, originalPieceY);
                    } else {
                        if (board->isPromotion()) {
                            promotionbox = new PromotionBox(1600, 900, turn);
                        } else {
                            bjustMove = true;
                            turn = (turn == Player::White) ? Player::Black : Player::White;
                        }          
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
    window->clear();
    window->draw(backgroundSprite);
    timerWhite->render(window);
    timerBlack->render(window);
    board->render(window);
    if (board->isPromotion()) {
        promotionbox->render(window);
    }
    window->display();
}
