#include "King.h"
#include "../ChessBoard.h"

King::King() {

}

King::King(King* piece, ChessBoard* boardState) : GamePieces(piece, boardState), bMove(piece->bMove) {

}

King::King(sf::String texturePath, int i, int j, Player color, ChessBoard* board) : GamePieces(texturePath, i, j, color, board), bMove(false) {

}

King::~King() {

}

void King::render(sf::RenderWindow* window) {
    GamePieces::render(window);
}

void King::setMove() {
    bMove = true;
}

bool King::moveValidate(int start1, int start2, int end1, int end2) {
    if ((absolute(start1, end1) <= 1 && absolute(start2, end2) <= 1) || (!bMove && (end2 == 1 || end2 == 6) && start1 == end1)) {
        return true;
    }
    return false;
}

bool King::checkOccupy(int start1, int start2, int end1, int end2) {
    if (absolute(start2, end2) <= 1) {
        if (getBoardState()->getSpecificColor(end1, end2) == getColor()) {
            return true;
        }
        return false;
    }
    if (end2 == 1 && getBoardState()->checkRook(end1, 0)) {
        for (int i = start2 - 1; i >= end2; --i) {
            if (getBoardState()->checkOccupy(end1, i)) {
                return true;
            }
        }
        return false;
    }
    if (end2 == 6 && getBoardState()->checkRook(end1, 7)) {
        for (int i = start2 + 1; i <= end2; ++i) {
            if (getBoardState()->checkOccupy(end1, i)) {
                return true;
            }
        }
        return false;
    }
    return true;
}