#include "Rook.h"
#include "../ChessBoard.h"

Rook::Rook() {

}

Rook::Rook(Rook* piece, ChessBoard* boardState) : GamePieces(piece, boardState), bMove(piece->bMove) {

}

Rook::Rook(sf::String texturePath, int i, int j, Player color, ChessBoard* board, bool value) : GamePieces(texturePath, i, j, color, board), bMove(value) {

}

Rook::~Rook() {

}

void Rook::setMove() {
    bMove = true;
}

bool Rook::getMove() {
    return bMove;
}

void Rook::render(sf::RenderWindow* window) {
    GamePieces::render(window);
}

bool Rook::moveValidate(int start1, int start2, int end1, int end2) {
    if (start1 == end1 || start2 == end2) {
        return true;
    }
    return false;
}

bool Rook::checkOccupy(int start1, int start2, int end1, int end2) {
    if (start1 == end1) {
        if (start2 > end2) {
            for (int i = end2 + 1; i < start2; ++i) {
                if (getBoardState()->checkOccupy(start1, i) == true) {
                    return true;
                }
            }
        }
        if (end2 > start2) {
            for (int i = start2 + 1; i < end2; ++i) {
                if (getBoardState()->checkOccupy(start1, i) == true) {
                    return true;
                }
            }
        }
    }
    if (start2 == end2) {
        if (start1 > end1) {
            for (int i = end1 + 1; i < start1; ++i) {
                if (getBoardState()->checkOccupy(i, start2) == true) {
                    return true;
                }
            }
        }
        if (end1 > start1) {
            for (int i = start1 + 1; i < end1; ++i) {
                if (getBoardState()->checkOccupy(i, start2) == true) {
                    return true;
                }
            }
        }
    }
    if (getBoardState()->getSpecificColor(end1, end2) == getColor()) {
        return true;
    }
    return false;
}