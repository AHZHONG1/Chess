#pragma once
#include "../GamePieces.h"
#include "../General.h"

class ChessBoard;

class Queen : public GamePieces {

private:





public:

    Queen();

    Queen(Queen*, ChessBoard*);

    Queen(sf::String, int, int, Player, ChessBoard*);

    ~Queen();

    void render(sf::RenderWindow*);

    bool moveValidate(int, int, int, int);

    bool checkOccupy(int, int, int, int);

};