#pragma once
#include "General.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class ChessBoard;
class GamePieces;
class Timer;
class Button;
class PromotionBox;

namespace sf {
    class RenderWindow;
}

class InGame {

private:

    ChessBoard* board;

    GamePieces* dragedPiece;

    int originalPieceX, originalPieceY;

    Timer* timerWhite;
    Timer* timerBlack;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    Player turn;

    bool bjustMove;

    bool bjustPick;

    PromotionBox* promotionbox;
    

public:

    InGame();

    InGame(int, int);

    ~InGame();

    void start();

    bool checkEndGameCondition(Player);

    void update(sf::RenderWindow*, State&);

    void render(sf::RenderWindow*);


};