#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"

class ChessBoard;
class GamePieces;
class Timer;
class Button;

class InGame {

private:

    ChessBoard* board;

    GamePieces* dragedPiece;

    Timer* timerWhite;
    Timer* timerBlack;

    Button* btn1;
    Button* btn2;
    Button* btn3;
    Button* btn4;
    

public:

    InGame();

    InGame(int, int);

    ~InGame();

    void start();

    void update(sf::RenderWindow*, State&);

    void render(sf::RenderWindow*);


};