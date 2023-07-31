#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/String.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include "General.h"

namespace sf {
    class RenderWindow;
}

class GamePieces {

private:

    sf::Texture texture;

    sf::Sprite sprite;

    Player color;

public:

    GamePieces();

    GamePieces(sf::String, int, int, Player);

    ~GamePieces();

    bool overlap(const sf::Event&) const;

    void drag(const sf::Event&);

    void place(int, int);

    Player getColor();

    virtual void render(sf::RenderWindow*);

};