#include "ChessBoard.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "GamePieces.h"
#include "GamePieces/Bishop.h"
#include "GamePieces/Knight.h"
#include "GamePieces/Pawn.h"
#include "GamePieces/Rook.h"
#include "GamePieces/Queen.h"
#include "GamePieces/King.h"
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>

ChessBoard::ChessBoard() : bPromotion(false), bCheck(false) {
    promotionDest[0] = -1;
    promotionDest[1] = -1;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            board[i][j].setSize(sf::Vector2f(100, 100));
            board[i][j].setPosition(sf::Vector2f(400 + 100 * j, 50 + 100 * i));
            sf::FloatRect boardRect = board[i][j].getLocalBounds();
            board[i][j].setFillColor(((i + j) % 2 == 1) ? sf::Color(112, 162, 163) : sf::Color(177, 228, 185));
        }
    }
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            boardPiece[i][j] = nullptr;
        }
    }

    for (int i = 0; i < 8; ++i) {
        boardPiece[1][i] = new Pawn("./Textures/Black-Pawn.png", 1, i, Player::Black, this);
        boardPiece[6][i] = new Pawn("./Textures/White-Pawn.png", 6, i, Player::White, this);
    }

    boardPiece[0][0] = new Rook("./Textures/Black-Rook.png", 0, 0, Player::Black, this);
    boardPiece[0][7] = new Rook("./Textures/Black-Rook.png", 0, 7, Player::Black, this);
    boardPiece[7][0] = new Rook("./Textures/White-Rook.png", 7, 0, Player::White, this);
    boardPiece[7][7] = new Rook("./Textures/White-Rook.png", 7, 7, Player::White, this);

    boardPiece[0][1] = new Knight("./Textures/Black-Knight.png", 0, 1, Player::Black, this);
    boardPiece[0][6] = new Knight("./Textures/Black-Knight.png", 0, 6, Player::Black, this);
    boardPiece[7][1] = new Knight("./Textures/White-Knight.png", 7, 1, Player::White, this);
    boardPiece[7][6] = new Knight("./Textures/White-Knight.png", 7, 6, Player::White, this);

    boardPiece[0][2] = new Bishop("./Textures/Black-Bishop.png", 0, 2, Player::Black, this);
    boardPiece[0][5] = new Bishop("./Textures/Black-Bishop.png", 0, 5, Player::Black, this);
    boardPiece[7][2] = new Bishop("./Textures/White-Bishop.png", 7, 2, Player::White, this);
    boardPiece[7][5] = new Bishop("./Textures/White-Bishop.png", 7, 5, Player::White, this);

    boardPiece[0][3] = new Queen("./Textures/Black-Queen.png", 0, 3, Player::Black, this);
    boardPiece[7][3] = new Queen("./Textures/White-Queen.png", 7, 3, Player::White, this);

    boardPiece[0][4] = new King("./Textures/Black-King.png", 0, 4, Player::Black, this);
    boardPiece[7][4] = new King("./Textures/White-King.png", 7, 4, Player::White, this);

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

    guideBox[0].setSize(sf::Vector2f(20, 820));
    guideBox[0].setFillColor(sf::Color(27, 153, 139));
    guideBox[0].setPosition(380, 50);

    guideBox[1].setSize(sf::Vector2f(20, 820));
    guideBox[1].setFillColor(sf::Color(27, 153, 139));
    guideBox[1].setPosition(1200, 50);

    guideBox[2].setSize(sf::Vector2f(800, 20));
    guideBox[2].setFillColor(sf::Color(27, 153, 139));
    guideBox[2].setPosition(400, 850);

    if (!possibleMoveTexture.loadFromFile("./Textures/Black-Dot.png")) {
        std::cout << "Texture not load" << std::endl;
    }

    if (!moveBuffer.loadFromFile("./Sounds/piece-move.wav")) {
        std::cout << "Cannot load sound" << std::endl;
    }
    if (!captureBuffer.loadFromFile("./Sounds/piece-capture.wav")) {
        std::cout << "Cannot load sound" << std::endl;
    }

    moveSound.setBuffer(moveBuffer);
    captureSound.setBuffer(captureBuffer);

}

ChessBoard::ChessBoard(ChessBoard* board) : en_passant(board->en_passant), bPromotion(board->bPromotion), possibleMoveTexture(board->possibleMoveTexture), bCheck(false), moveBuffer(board->moveBuffer), captureBuffer(board->captureBuffer), moveSound(board->moveSound), captureSound(board->captureSound) {
    promotionDest[0] = board->promotionDest[0];
    promotionDest[1] = board->promotionDest[1];
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board->boardPiece[i][j] == nullptr) {
                this->boardPiece[i][j] = nullptr;
                continue;
            }
            if (typeid(*board->boardPiece[i][j]) == typeid(Pawn)) {
                this->boardPiece[i][j] = new Pawn(dynamic_cast<Pawn*>(board->boardPiece[i][j]), this);
            }
            if (typeid(*board->boardPiece[i][j]) == typeid(Rook)) {
                this->boardPiece[i][j] = new Rook(dynamic_cast<Rook*>(board->boardPiece[i][j]), this);
            }
            if (typeid(*board->boardPiece[i][j]) == typeid(Knight)) {
                this->boardPiece[i][j] = new Knight(dynamic_cast<Knight*>(board->boardPiece[i][j]), this);
            }
            if (typeid(*board->boardPiece[i][j]) == typeid(Bishop)) {
                this->boardPiece[i][j] = new Bishop(dynamic_cast<Bishop*>(board->boardPiece[i][j]), this);
            }
            if (typeid(*board->boardPiece[i][j]) == typeid(Queen)) {
                this->boardPiece[i][j] = new Queen(dynamic_cast<Queen*>(board->boardPiece[i][j]), this);
            }
            if (typeid(*board->boardPiece[i][j]) == typeid(King)) {
                this->boardPiece[i][j] = new King(dynamic_cast<King*>(board->boardPiece[i][j]), this);
            }
        }
    }
}

ChessBoard::~ChessBoard() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (boardPiece[i][j]) {
                delete boardPiece[i][j];
            }
        }
    }
    while (!possibleMoveSprites.empty()) {
        delete possibleMoveSprites.back();
        possibleMoveSprites.pop_back();
    }  
}

bool ChessBoard::overlapPiece(const sf::Event &event, GamePieces*& piece, int& x, int& y, Player turn) const {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (boardPiece[i][j]) {
                if (boardPiece[i][j]->overlap(event) && boardPiece[i][j]->getColor() == turn) {
                    piece = boardPiece[i][j];
                    y = i;
                    x = j;
                    return true;
                }
            }
        }
    }
    return false;
}

bool ChessBoard::overlapBoard(const sf::Event& event, int& outI, int& outJ) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                outI = i;
                outJ = j;
                return true;
            }
        }
    }
    outI = -1;
    outJ = -1;
    return false;
}

void ChessBoard::drag(const sf::Event& event, GamePieces* piece) {
    piece->drag(event);
}

void ChessBoard::release(const sf::Event& event, GamePieces* piece, int i, int j) {
    // if (overlapBoard(event, piece, i, j)) {
        
    // }
}

void ChessBoard::showPossibleMove(int x, int y, Player turn) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (boardPiece[y][x]->moveValidate(y, x, i, j) && !(boardPiece[y][x]->checkOccupy(y, x, i, j))) {
                if (!checkCheckAfterMove(y, x, i, j, turn)) {
                    possibleMoveSprites.push_back(new sf::Sprite(possibleMoveTexture));
                    possibleMoveSprites.back()->setPosition(450 + 100 * j, 100 + 100 * i);
                    possibleMoveSprites.back()->setColor(sf::Color(0, 0, 0, 150));
                    possibleMoveSprites.back()->setOrigin(50, 50);
                }
            }
        }
    }
}

void ChessBoard::removePossibleMove() {
    while (!possibleMoveSprites.empty()) {
        delete possibleMoveSprites.back();
        possibleMoveSprites.pop_back();
    }   
}

bool ChessBoard::isPossibleMove(Player turn) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (boardPiece[i][j] != nullptr && boardPiece[i][j]->getColor() == turn) {
                for (int x = 0; x < 8; ++x) {
                    for (int y = 0; y < 8; ++y) {
                        if (boardPiece[i][j]->moveValidate(i, j, x, y) && !(boardPiece[i][j]->checkOccupy(i, j, x, y))) {
                            if (!checkCheckAfterMove(i, j, x, y, turn)) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool ChessBoard::moveValid(const sf::Event& event, GamePieces* piece, int i, int j, Player turn) {
    int destI, destJ;
    if (!overlapBoard(event, destI, destJ)) {
        std::cout << "not place on board" << std::endl;
        return false;
    }

    std::cout << i << " : " << j << " to " << destI << " : " << destJ << std::endl;
    
    if (!piece->moveValidate(i, j, destI, destJ)) {
        std::cout << "Ignore move rule" << std::endl;
        return false;
    }
    if (piece->checkOccupy(i, j, destI, destJ)) {
        std::cout << "place is occupy" << std::endl;
        return false;
    }

    if (checkCheckAfterMove(i, j, destI, destJ, turn)) {
        std::cout << "Being checked after move" << std::endl;
        return false;
    }

    if (typeid(*piece) == typeid(Rook)) {
        dynamic_cast<Rook*>(piece)->setMove();
    }

    if (typeid(*piece) == typeid(Pawn)) {
        dynamic_cast<Pawn*>(piece)->setMove();
    }

    if (typeid(*piece) == typeid(King)) {
        dynamic_cast<King*>(piece)->setMove();
    }

    forceMove(i, j, destI, destJ, true);

    if (typeid(*piece) == typeid(Pawn) && absolute(i, destI) == 2) {
        en_passant = j;
    } else {
        en_passant = -1;
    }

    if (typeid(*piece) == typeid(Pawn) && (destI == 0 || destI == 7)) {
        std::cout << "Promotion" << std::endl;
        promotionDest[0] = destI;
        promotionDest[1] = destJ;
        bPromotion = true;
    }

    std::cout << "move success" << std::endl;

    return true;
}

void ChessBoard::forceMove(int start1, int start2, int end1, int end2, bool bPlaySound) {
    std::cout << start1 << "|" << start2 << "|" << end1 << "|" << end2 << std::endl;
    boardPiece[start1][start2]->place(end2, end1);
    if (boardPiece[end1][end2] == nullptr && boardPiece[start1][start2] != nullptr && typeid(*boardPiece[start1][start2]) == typeid(Pawn) && start2 != end2) {
        boardPiece[end1][end2] = boardPiece[start1][start2];
        boardPiece[start1][start2] = nullptr;
        delete boardPiece[start1][end2];
        boardPiece[start1][end2] = nullptr;
        if (bPlaySound) {
            captureSound.play();
        }
    } else if (boardPiece[start1][start2] != nullptr && typeid(*boardPiece[start1][start2]) == typeid(King) && absolute(start2, end2) > 1) {
        boardPiece[end1][end2] = boardPiece[start1][start2];
        boardPiece[start1][start2] = nullptr;
        if (end2 == 1) {
            boardPiece[end1][0]->place(2, end1);
            boardPiece[end1][2] = boardPiece[end1][0];
            boardPiece[end1][0] = nullptr;
        }
        if (end2 == 6) {
            boardPiece[end1][7]->place(5, end1);
            boardPiece[end1][5] = boardPiece[end1][7];
            boardPiece[end1][7] = nullptr;
        }
        if (bPlaySound) {
            moveSound.play();
        }
    } else if (boardPiece[end1][end2] == nullptr) {
        boardPiece[end1][end2] = boardPiece[start1][start2];
        boardPiece[start1][start2] = nullptr;
        if (bPlaySound) {
            moveSound.play();
        }
    } else {
        delete boardPiece[end1][end2];
        boardPiece[end1][end2] = boardPiece[start1][start2];
        boardPiece[start1][start2] = nullptr;
        if (bPlaySound) {
            captureSound.play();
        }
    }
}

bool ChessBoard::checkOccupy(int i, int j) {
    if (boardPiece[i][j] == nullptr) {
        return false;
    }
    return true;
}

bool ChessBoard::checkCheckAfterMove(int start1, int start2, int end1, int end2, Player turn) {
    ChessBoard* newBoard = new ChessBoard(this);
    newBoard->forceMove(start1, start2 , end1, end2, false);
    //newBoard->printBoard();
    if (isCheck(newBoard, turn)) {
        delete newBoard;
        return true;
    }
    delete newBoard;
    return false;
}

Player ChessBoard::getSpecificColor(int i, int j) {
    if (boardPiece[i][j] == nullptr) {
        return Player::None;
    }
    return boardPiece[i][j]->getColor();
}

int ChessBoard::getEn_passant() {
    return en_passant;
}

bool ChessBoard::checkRook(int i, int j) {
    if (boardPiece[i][j] == nullptr) return false;
    return (typeid(*boardPiece[i][j]) == typeid(Rook) && dynamic_cast<Rook*>(boardPiece[i][j])->getMove() == false);
}

bool ChessBoard::checkKing(int i, int j, Player turn) {
    if (boardPiece[i][j] == nullptr) return false;
    return (typeid(*boardPiece[i][j]) == typeid(King) && boardPiece[i][j]->getColor() == turn);
}

bool ChessBoard::isCheck(ChessBoard* newBoard, Player turn) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (newBoard->boardPiece[i][j] != nullptr && newBoard->boardPiece[i][j]->getColor() != turn) {
                for (int x = 0; x < 8; ++x) {
                    for (int y = 0; y < 8; ++y) {
                        if (newBoard->boardPiece[i][j]->moveValidate(i, j, x, y) && !(newBoard->boardPiece[i][j]->checkOccupy(i, j, x, y)) && newBoard->checkKing(x, y, turn)) {
                            bCheck = true;
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

void ChessBoard::setbCheck(bool value) {
    bCheck = value;
}

bool ChessBoard::getbCheck() {
    return bCheck;
}

bool ChessBoard::isCheckmate(Player turn) {
    if (isCheck(this, turn)) {
        if (!isPossibleMove(turn)) {
            return true;
        }
    }
    return false;
}

bool ChessBoard::isStalemate(Player turn) {
    if (!isPossibleMove(turn)) {
        return true;
    }
    return false;
}

bool ChessBoard::isPromotion() {
    return bPromotion;
}

void ChessBoard::setPromotion(bool value) {
    bPromotion = value;
}

void ChessBoard::promotion(sf::String pieceString, Player color) {
    delete boardPiece[promotionDest[0]][promotionDest[1]];
    if (pieceString == "Queen") {
        boardPiece[promotionDest[0]][promotionDest[1]] = new Queen((color == Player::White) ? "./Textures/White-Queen.png" : "./Textures/Black-Queen.png", promotionDest[0], promotionDest[1], color, this);
    }
    if (pieceString == "Knight") {
        boardPiece[promotionDest[0]][promotionDest[1]] = new Knight((color == Player::White) ? "./Textures/White-Knight.png" : "./Textures/Black-Knight.png", promotionDest[0], promotionDest[1], color, this);
    }
    if (pieceString == "Rook") {
        boardPiece[promotionDest[0]][promotionDest[1]] = new Rook((color == Player::White) ? "./Textures/White-Rook.png" : "./Textures/Black-Rook.png", promotionDest[0], promotionDest[1], color, this, true);
    }
    if (pieceString == "Bishop") {
        boardPiece[promotionDest[0]][promotionDest[1]] = new Bishop((color == Player::White) ? "./Textures/White-Bishop.png" : "./Textures/Black-Bishop.png", promotionDest[0], promotionDest[1], color, this);
    }
}

void ChessBoard::render(sf::RenderWindow *window)
{
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            window->draw(board[i][j]);
        } 
    }
    for (int i = 0; i < 3; ++i) {
        window->draw(guideBox[i]);
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 8; ++j) {
            window->draw(text[i][j]);
        }
    }

    for (sf::Sprite* possibleMoveSprite : possibleMoveSprites) {
        window->draw(*possibleMoveSprite);
    }   

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (boardPiece[i][j]) {
                boardPiece[i][j]->render(window);
            }
        } 
    }
}
