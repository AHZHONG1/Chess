#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/String.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>

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

    bool overlap(const sf::Event&) const;

    void drag(const sf::Event&);

    virtual void render(sf::RenderWindow*);

};