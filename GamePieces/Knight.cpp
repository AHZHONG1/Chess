#include "Knight.h"
#include "../ChessBoard.h"

Knight::Knight() {

}

Knight::Knight(Knight* piece, ChessBoard* boardState) : GamePieces(piece, boardState) {

}

Knight::Knight(sf::String texturePath, int i, int j, Player color, ChessBoard* board) : GamePieces(texturePath, i, j, color, board) {

}

Knight::~Knight() {

}

void Knight::render(sf::RenderWindow* window) {
    GamePieces::render(window);
}

bool Knight::moveValidate(int start1, int start2, int end1, int end2) {
    if ((absolute(start1, end1) == 1 && absolute(start2, end2) == 2) || (absolute(start1, end1) == 2 && absolute(start2, end2) == 1)) {
        return true;
    }
    return false;
}

bool Knight::checkOccupy(int start1, int start2, int end1, int end2) {
    if (getBoardState()->getSpecificColor(end1, end2) == getColor()) {
        return true;
    }
    return false;
}