#pragma once
#include "State.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class ChessBoard;
class GamePieces;
class Timer;
class Button;

namespace sf {
    class RenderWindow;
}

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

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    

public:

    InGame();

    InGame(int, int);

    ~InGame();

    void start();

    void update(sf::RenderWindow*, State&);

    void render(sf::RenderWindow*);


};