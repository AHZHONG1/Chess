#pragma once

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/String.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "General.h"
#include <vector>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <thread>

namespace sf {
    class RenderWindow;
    class Sprite;
}

class GamePieces;
class Stockfish;

class ChessBoard {

private:


    sf::RectangleShape board[8][8];

    GamePieces* boardPiece[8][8];

    int en_passant;

    sf::Font font;

    sf::RectangleShape guideBox[3];

    sf::Text text[3][8];

    bool bPromotion;

    int promotionDest[2];

    sf::Texture possibleMoveTexture;

    std::vector<sf::Sprite*> possibleMoveSprites;

    bool bCheck;

    sf::SoundBuffer moveBuffer;

    sf::SoundBuffer captureBuffer;

    sf::Sound moveSound;

    sf::Sound captureSound;

public:


    ChessBoard();

    ChessBoard(ChessBoard*);

    ~ChessBoard();

    bool overlapPiece(const sf::Event& event, GamePieces*&, int&, int&, Player) const;

    bool overlapBoard(const sf::Event& event, int&, int&);

    void drag(const sf::Event&, GamePieces*);

    void release(const sf::Event&, GamePieces*, int, int);

    void showPossibleMove(int, int, Player);

    void removePossibleMove();

    bool isPossibleMove(Player);

    bool moveValid(const sf::Event&, GamePieces*, int, int, Player, Stockfish*, std::thread*);

    void forceMove(int, int, int, int, bool, Stockfish*, std::thread*);

    bool checkOccupy(int, int);

    bool checkCheckAfterMove(int, int, int, int, Player);

    Player getSpecificColor(int, int);

    int getEn_passant();

    bool checkRook(int, int);

    bool checkKing(int, int, Player);

    bool isCheck(ChessBoard*, Player);

    void setbCheck(bool);

    bool getbCheck();

    bool isCheckmate(Player);

    bool isStalemate(Player);

    bool isPromotion();

    void setPromotion(bool);

    void promotion(sf::String, Player, Stockfish*, std::thread*);

    void render(sf::RenderWindow*);

};