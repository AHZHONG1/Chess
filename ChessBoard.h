#pragma once

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "General.h"

namespace sf {
    class RenderWindow;
}

class GamePieces;

class ChessBoard {

private:


    sf::RectangleShape board[8][8];

    GamePieces* boardPiece[8][8];

    int en_passant;

    sf::Font font;

    sf::RectangleShape guideBox[3];

    sf::Text text[3][8];



public:


    ChessBoard();

    ChessBoard(ChessBoard*);

    ~ChessBoard();

    bool overlapPiece(const sf::Event& event, GamePieces*&, int&, int&, Player) const;

    bool overlapBoard(const sf::Event& event, int&, int&);

    void drag(const sf::Event&, GamePieces*);

    void release(const sf::Event&, GamePieces*, int, int);

    void showPossibleMove();

    bool moveValid(const sf::Event&, GamePieces*, int, int, Player);

    void forceMove(int, int, int, int);

    bool checkOccupy(int, int);

    bool checkCheckAfterMove(int, int, int, int, Player);

    Player getSpecificColor(int, int);

    int getEn_passant();

    bool checkRook(int, int);

    bool checkKing(int, int, Player);

    bool isCheck(ChessBoard*, Player);

    void render(sf::RenderWindow*);

};