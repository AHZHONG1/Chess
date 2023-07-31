#include "Pawn.h"
#include "../ChessBoard.h"

Pawn::Pawn() {

}

Pawn::Pawn(Pawn* piece, ChessBoard* boardState) : GamePieces(piece, boardState), bMove(piece->bMove) {

}

Pawn::Pawn(sf::String texturePath, int i, int j, Player color, ChessBoard* board) : GamePieces(texturePath, i, j, color, board), bMove(false) {

}

Pawn::~Pawn() {

}

void Pawn::render(sf::RenderWindow* window) {
    GamePieces::render(window);
}

void Pawn::setMove() {
    bMove = true;
}

bool Pawn::moveValidate(int start1, int start2, int end1, int end2) {
    if (getColor() == Player::White) {
        if (end1 == start1 - 1 && absolute(start2, end2) <= 1) {
            return true;
        }
        if (!bMove && end1 == start1 - 2 && start2 == end2) {
            return true;
        }
        return false;
    } else {
        if (end1 == start1 + 1 && absolute(start2, end2) <= 1) {
            return true;
        }
        if (!bMove && end1 == start1 + 2 && start2 == end2) {
            return true;
        }
        return false;
    }
}

bool Pawn::checkOccupy(int start1, int start2, int end1, int end2) {
    if (start2 == end2) {
        if (getBoardState()->checkOccupy(end1, end2)) {
            return true;
        }
        return false;
    }
    if (getColor() == Player::White) {
        if (getBoardState()->getSpecificColor(end1, end2) == Player::None && start1 == 3 && getBoardState()->getEn_passant() == end2) {
            return false;
        }
    } else {
        if (getBoardState()->getSpecificColor(end1, end2) == Player::None && start1 == 4 && getBoardState()->getEn_passant() == end2) {
            return false;
        }
    }
    if (getBoardState()->getSpecificColor(end1, end2) == getColor() || getBoardState()->getSpecificColor(end1, end2) == Player::None) {
        return true;
    }
    return false;
}