#pragma once
#include "../GamePieces.h"
#include "../General.h"

class ChessBoard;

class Pawn : public GamePieces {

private:

    bool bMove;



public:

    Pawn();

    Pawn(Pawn*, ChessBoard*);

    Pawn(sf::String, int, int, Player, ChessBoard*);

    ~Pawn();

    void render(sf::RenderWindow*);

    void setMove();

    bool moveValidate(int, int, int, int);

    bool checkOccupy(int, int, int, int);

};