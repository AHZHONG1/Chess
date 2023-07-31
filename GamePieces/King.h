#pragma once
#include "../GamePieces.h"
#include "../General.h"

class ChessBoard;

class King : public GamePieces {

private:

    bool bMove;



public:

    King();

    King(King*, ChessBoard*);

    King(sf::String, int, int, Player, ChessBoard*);

    ~King();

    void render(sf::RenderWindow*);

    void setMove();

    bool moveValidate(int, int, int, int);

    bool checkOccupy(int, int, int, int);

};