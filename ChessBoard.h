#pragma once

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

namespace sf {
    class RenderWindow;
}

class GamePieces;

class ChessBoard {

private:


    sf::RectangleShape board[8][8];

    GamePieces* boardPiece[8][8];

    sf::Font font;

    sf::RectangleShape guideBox[3];

    sf::Text text[3][8];



public:


    ChessBoard();

    ~ChessBoard();

    bool overlapPiece(const sf::Event& event, GamePieces*&) const;

    bool overlapBoard(const sf::Event& event, GamePieces*) const;

    void drag(const sf::Event&, GamePieces*);

    void release(const sf::Event&, GamePieces*);

    void render(sf::RenderWindow*);

};