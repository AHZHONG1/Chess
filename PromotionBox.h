#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/String.hpp>
#include "General.h"
#include <SFML/Window/Event.hpp>

namespace sf {
    class RenderWindow;
}

class GamePieces;

class PromotionBox {

private:

    sf::Texture promotionBackgroundTexture;
    sf::Sprite promotionBackgroundSprite;

    sf::RectangleShape promotionBackground;
    sf::RectangleShape boxBackground;

    sf::RectangleShape borderLine[2][3];

    sf::Texture queenTexture;
    sf::Sprite queenSprite;

    sf::Texture knightTexture;
    sf::Sprite knightSprite;

    sf::Texture rookTexture;
    sf::Sprite rookSprite;

    sf::Texture bishopTexture;
    sf::Sprite bishopSprite;



public:

    PromotionBox();

    PromotionBox(int, int, Player);

    ~PromotionBox();

    bool overlapPiece(const sf::Event&, sf::String&) const;

    void update(sf::RenderWindow*);

    void render(sf::RenderWindow*);


};