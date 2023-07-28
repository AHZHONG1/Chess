#pragma once

namespace sf {
    class RectangleShape;
    class RenderWindow;
}

class GamePieces;

class ChessBoard {

private:


    sf::RectangleShape* board[8][8];

    GamePieces* boardPiece[8][8];



public:


    ChessBoard();

    ~ChessBoard();

    void render(sf::RenderWindow*);

};