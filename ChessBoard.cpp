#include "ChessBoard.h"
#include <SFML/Graphics.hpp>
#include "GamePieces.h"
#include "GamePieces/Bishop.h"
#include "GamePieces/Knight.h"
#include "GamePieces/Pawn.h"
#include "GamePieces/Rook.h"
#include "GamePieces/Queen.h"
#include "GamePieces/King.h"

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
}

void ChessBoard::render(sf::RenderWindow* window) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            window->draw(*board[i][j]);
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
