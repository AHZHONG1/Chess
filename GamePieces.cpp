#include "GamePieces.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

GamePieces::GamePieces() {
    
}

GamePieces::GamePieces(sf::String texturePath, int i, int j, Player color) : color(color) {
    if (!texture.loadFromFile(texturePath)) {
        std::cout << "Texture not load" << std::endl;
    }

    sprite.setTexture(texture);
    sprite.setPosition(450 + 100 * j, 100 + 100 * i);
    sprite.setOrigin(50, 50);

}

GamePieces::~GamePieces() {

}

bool GamePieces::overlap(const sf::Event &event) const {
    return sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y);
}

void GamePieces::drag(const sf::Event &event) {
    sprite.setPosition(event.mouseMove.x, event.mouseMove.y);
}

void GamePieces::place(int x, int y) {
    sprite.setPosition(450 + 100 * x, 100 + 100 * y);
}

Player GamePieces::getColor() {
    return color;
}

void GamePieces::render(sf::RenderWindow* window) {
    window->draw(sprite);
}
