#pragma once
#include "General.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <thread>

class ChessBoard;
class GamePieces;
class Timer;
class Button;
class PromotionBox;
class EndGameScreen;
class Stockfish;

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

    sf::Font font;
    sf::Text text;

    std::string eval;

    bool isFinishCalculateEval;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    Stockfish* fish;

    Player turn;

    bool bjustMove;

    bool bjustPick;

    bool bEnd;

    PromotionBox* promotionbox;

    EndGameScreen* endGameScreen;

    std::thread* t1;
    

public:

    InGame();

    InGame(int, int, int, int, int);

    ~InGame();

    void start();

    bool checkEndGameCondition(Player);

    void update(sf::RenderWindow*, State&);

    void render(sf::RenderWindow*);


};