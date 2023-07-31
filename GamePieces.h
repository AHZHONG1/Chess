#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/String.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include "General.h"

namespace sf {
    class RenderWindow;
}

class ChessBoard;

class GamePieces {

private:

    sf::Texture texture;

    sf::Sprite sprite;

    Player color;

    ChessBoard* boardState;

public:

    GamePieces();

    GamePieces(GamePieces*, ChessBoard*);

    GamePieces(sf::String, int, int, Player, ChessBoard*);

    virtual ~GamePieces();

    bool overlap(const sf::Event&) const;

    void drag(const sf::Event&);

    void place(int, int);

    Player getColor();

    ChessBoard* getBoardState();

    virtual void render(sf::RenderWindow*);

    virtual bool moveValidate(int, int, int, int) = 0;

    virtual bool checkOccupy(int, int, int, int) = 0;

};