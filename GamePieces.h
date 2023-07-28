#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/String.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace sf {
    class RenderWindow;
}

class GamePieces {

private:

    sf::Texture texture;

    sf::Sprite sprite;



public:

    GamePieces();

    GamePieces(sf::String, int, int);

    ~GamePieces();

    virtual void render(sf::RenderWindow*);

};