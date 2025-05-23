#include "Queen.h"
#include "../ChessBoard.h"

Queen::Queen() {

}

Queen::Queen(Queen* piece, ChessBoard* boardState) : GamePieces(piece, boardState) {

}

Queen::Queen(sf::String texturePath, int i, int j, Player color, ChessBoard* board) : GamePieces(texturePath, i, j, color, board) {

}

Queen::~Queen() {

}

void Queen::render(sf::RenderWindow* window) {
    GamePieces::render(window);
}

bool Queen::moveValidate(int start1, int start2, int end1, int end2) {
    if (start1 == end1 || start2 == end2) {
        return true;
    }
    if (absolute(start1, end1) == absolute(start2, end2)) {
        return true;
    }
    return false;
}

bool Queen::checkOccupy(int start1, int start2, int end1, int end2) {
    if (start1 == end1 || start2 == end2) {
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

    if (start1 > end1) {
        if (start2 > end2) {
            for (int i = 1; i < (absolute(start1, end1)); ++i) {
                if (getBoardState()->checkOccupy(start1 - i, start2 - i) == true) {
                    return true;
                }
            }
        }
        if (end2 > start2) {
            for (int i = 1; i < (absolute(start1, end1)); ++i) {
                if (getBoardState()->checkOccupy(start1 - i, start2 + i) == true) {
                    return true;
                }
            }
        }
    }
    if (end1 > start1) {
        if (start2 > end2) {
            for (int i = 1; i < (absolute(start1, end1)); ++i) {
                if (getBoardState()->checkOccupy(start1 + i, start2 - i) == true) {
                    return true;
                }
            }
        }
        if (end2 > start2) {
            for (int i = 1; i < (absolute(start1, end1)); ++i) {
                if (getBoardState()->checkOccupy(start1 + i, start2 + i) == true) {
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