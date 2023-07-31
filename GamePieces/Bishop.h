#pragma once
#include "../GamePieces.h"
#include "../General.h"

class ChessBoard;

class Bishop : public GamePieces {

private:





public:

    Bishop();

    Bishop(Bishop*, ChessBoard*);

    Bishop(sf::String, int, int, Player, ChessBoard*);

    ~Bishop();

    void render(sf::RenderWindow*);

    bool moveValidate(int, int, int, int);

    bool checkOccupy(int, int, int, int);

};