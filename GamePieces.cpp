#include "GamePieces.h"
#include <SFML/Graphics.hpp>
#include <iostream>

GamePieces::GamePieces() {
    
}

GamePieces::GamePieces(sf::String texturePath, int i, int j) {
    if (!texture.loadFromFile(texturePath)) {
        std::cout << "Texture not load" << std::endl;
    }

    sprite.setTexture(texture);
    sprite.setPosition(400 + 100 * j, 50 + 100 * i);

}

GamePieces::~GamePieces() {

}

void GamePieces::render(sf::RenderWindow* window) {
    window->draw(sprite);
}
