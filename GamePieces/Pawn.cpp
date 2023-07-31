#include "Pawn.h"

Pawn::Pawn() {

}

Pawn::Pawn(sf::String texturePath, int i, int j, Player color) : GamePieces(texturePath, i, j, color) {

}

Pawn::~Pawn() {

}

void Pawn::render(sf::RenderWindow* window) {
    GamePieces::render(window);
}
