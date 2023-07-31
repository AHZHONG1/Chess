#pragma once
#include "../GamePieces.h"
#include "../General.h"

class ChessBoard;

class Knight : public GamePieces {

private:





public:

    Knight();

    Knight(Knight*, ChessBoard*);

    Knight(sf::String, int, int, Player, ChessBoard*);

    ~Knight();

    void render(sf::RenderWindow*);

    bool moveValidate(int, int, int, int);

    bool checkOccupy(int, int, int, int);

};