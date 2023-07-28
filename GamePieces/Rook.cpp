#include "Rook.h"

Rook::Rook() {

}

Rook::Rook(sf::String texturePath, int i, int j) : GamePieces(texturePath, i, j) {

}

Rook::~Rook() {

}

void Rook::render(sf::RenderWindow* window) {
    GamePieces::render(window);
}
