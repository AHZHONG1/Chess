#pragma once

#include <SFML/Window/Event.hpp>

namespace sf {
    class RectangleShape;
    class RenderWindow;
}

class GamePieces;

class ChessBoard {

private:


    sf::RectangleShape* board[8][8];

    GamePieces* boardPiece[8][8];



public:


    ChessBoard();

    ~ChessBoard();

    bool overlap(const sf::Event& event, GamePieces*&) const;

    void drag(const sf::Event&, GamePieces*);

    void render(sf::RenderWindow*);

};