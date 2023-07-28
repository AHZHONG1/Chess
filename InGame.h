#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"

class ChessBoard;
class GamePieces;

class InGame {

private:

    ChessBoard* board;

    GamePieces* dragedPiece;


    

public:

    InGame();

    InGame(int, int);

    ~InGame();

    void update(sf::RenderWindow*, State&);

    void render(sf::RenderWindow*);


};