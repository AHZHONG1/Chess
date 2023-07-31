#include "Rook.h"

Rook::Rook() {

}

Rook::Rook(sf::String texturePath, int i, int j, Player color) : GamePieces(texturePath, i, j, color) {

}

Rook::~Rook() {

}

void Rook::render(sf::RenderWindow* window) {
    GamePieces::render(window);
}
