#pragma once
#include "../GamePieces.h"
#include "../General.h"

class ChessBoard;

class Rook : public GamePieces {

private:

    bool bMove;



public:

    Rook();

    Rook(Rook*, ChessBoard*);

    Rook(sf::String, int, int, Player, ChessBoard*);

    ~Rook();

    void setMove();

    bool getMove();

    void render(sf::RenderWindow*);

    bool moveValidate(int, int, int, int);

    bool checkOccupy(int, int, int, int);

};