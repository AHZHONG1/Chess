#include "ChessBoard.h"
#include <SFML/Graphics.hpp>
#include "GamePieces.h"
#include "GamePieces/Bishop.h"
#include "GamePieces/Knight.h"
#include "GamePieces/Pawn.h"
#include "GamePieces/Rook.h"
#include "GamePieces/Queen.h"
#include "GamePieces/King.h"
#include <iostream>

ChessBoard::ChessBoard() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            board[i][j] = new sf::RectangleShape(sf::Vector2f(100, 100));
            board[i][j]->setPosition(sf::Vector2f(400 + 100 * i, 50 + 100 * j));
            sf::FloatRect boardRect = board[i][j]->getLocalBounds();
            board[i][j]->setFillColor(((i + j) % 2 == 1) ? sf::Color(112, 162, 163) : sf::Color(177, 228, 185));
        }
    }
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            boardPiece[i][j] = nullptr;
        }
    }

    for (int i = 0; i < 8; ++i) {
        boardPiece[1][i] = new Pawn("./Textures/Black-Pawn.png", 1, i);
        boardPiece[6][i] = new Pawn("./Textures/White-Pawn.png", 6, i);
    }

    boardPiece[0][0] = new Rook("./Textures/Black-Rook.png", 0, 0);
    boardPiece[0][7] = new Rook("./Textures/Black-Rook.png", 0, 7);
    boardPiece[7][0] = new Rook("./Textures/White-Rook.png", 7, 0);
    boardPiece[7][7] = new Rook("./Textures/White-Rook.png", 7, 7);

    boardPiece[0][1] = new Knight("./Textures/Black-Knight.png", 0, 1);
    boardPiece[0][6] = new Knight("./Textures/Black-Knight.png", 0, 6);
    boardPiece[7][1] = new Knight("./Textures/White-Knight.png", 7, 1);
    boardPiece[7][6] = new Knight("./Textures/White-Knight.png", 7, 6);

    boardPiece[0][2] = new Bishop("./Textures/Black-Bishop.png", 0, 2);
    boardPiece[0][5] = new Bishop("./Textures/Black-Bishop.png", 0, 5);
    boardPiece[7][2] = new Bishop("./Textures/White-Bishop.png", 7, 2);
    boardPiece[7][5] = new Bishop("./Textures/White-Bishop.png", 7, 5);

    boardPiece[0][3] = new Queen("./Textures/Black-Queen.png", 0, 3);
    boardPiece[7][3] = new Queen("./Textures/White-Queen.png", 7, 3);

    boardPiece[0][4] = new King("./Textures/Black-King.png", 0, 4);
    boardPiece[7][4] = new King("./Textures/White-King.png", 7, 4);

    if (!font.loadFromFile("./Font/roboto/Roboto-Regular.ttf")) {
        std::cout << "Loading error" << std::endl;
    } 

    
    for (int i = 0; i < 8; ++i) {
        text[0][i].setFont(font);
        text[0][i].setString(std::to_string(8 - i));
        text[0][i].setCharacterSize(24);
        text[0][i].setPosition(390, 100 + 100 * i);
        sf::FloatRect textRect = text[0][i].getLocalBounds();
        text[0][i].setOrigin(textRect.left + textRect.width / 2.0, textRect.top + textRect.height / 2.0);
        text[0][i].setFillColor(sf::Color::Black);
    }

    for (int i = 0; i < 8; ++i) {
        text[1][i].setFont(font);
        text[1][i].setString(std::to_string(8 - i));
        text[1][i].setCharacterSize(24);
        text[1][i].setPosition(1210, 100 + 100 * i);
        sf::FloatRect textRect = text[1][i].getLocalBounds();
        text[1][i].setOrigin(textRect.left + textRect.width / 2.0, textRect.top + textRect.height / 2.0);
        text[1][i].setFillColor(sf::Color::Black);
    }

    for (int i = 0; i < 8; ++i) {
        text[2][i].setFont(font);
        text[2][i].setString(static_cast<char>('A' + i));
        text[2][i].setCharacterSize(24);
        text[2][i].setPosition(450 + 100 * i, 860);
        sf::FloatRect textRect = text[2][i].getLocalBounds();
        text[2][i].setOrigin(textRect.left + textRect.width / 2.0, textRect.top + textRect.height / 2.0);
        text[2][i].setFillColor(sf::Color::Black);
    }

    guideBox[0] = new sf::RectangleShape(sf::Vector2f(20, 820));
    guideBox[0]->setFillColor(sf::Color(27, 153, 139));
    guideBox[0]->setPosition(380, 50);

    guideBox[1] = new sf::RectangleShape(sf::Vector2f(20, 820));
    guideBox[1]->setFillColor(sf::Color(27, 153, 139));
    guideBox[1]->setPosition(1200, 50);

    guideBox[2] = new sf::RectangleShape(sf::Vector2f(800, 20));
    guideBox[2]->setFillColor(sf::Color(27, 153, 139));
    guideBox[2]->setPosition(400, 850);

    


}

ChessBoard::~ChessBoard() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            delete board[i][j];
        }
    }
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (boardPiece[i][j]) {
                delete boardPiece[i][j];
            }
        }
    }
    for (int i = 0; i < 3; ++i) {
        delete guideBox[i];
    }
}

bool ChessBoard::overlapPiece(const sf::Event &event, GamePieces*& piece) const {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (boardPiece[i][j]) {
                if (boardPiece[i][j]->overlap(event)) {
                    piece = boardPiece[i][j];
                    return true;
                }
            }
        }
    }
    return false;
}

bool ChessBoard::overlapBoard(const sf::Event& event, GamePieces* piece) const {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j]) {
                if (board[i][j]->getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    piece->place(i, j);
                    return true;
                }
            }
        }
    }
    return false;
}

void ChessBoard::drag(const sf::Event& event, GamePieces* piece) {
    piece->drag(event);
}

void ChessBoard::release(const sf::Event& event, GamePieces* piece) {
    if (overlapBoard(event, piece)) {
        
    }
}

void ChessBoard::render(sf::RenderWindow* window) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            window->draw(*board[i][j]);
        } 
    }
    for (int i = 0; i < 3; ++i) {
        window->draw(*guideBox[i]);
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 8; ++j) {
            window->draw(text[i][j]);
        }
    }

    

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (boardPiece[i][j]) {
                boardPiece[i][j]->render(window);
            }
        } 
    }

}
