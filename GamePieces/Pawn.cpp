#include "Pawn.h"

Pawn::Pawn() {

}

Pawn::Pawn(sf::String texturePath, int i, int j) : GamePieces(texturePath, i, j) {

}

Pawn::~Pawn() {

}

void Pawn::render(sf::RenderWindow* window) {
    GamePieces::render(window);
}
