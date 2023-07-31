#include "King.h"

King::King() {

}

King::King(sf::String texturePath, int i, int j, Player color) : GamePieces(texturePath, i, j, color) {

}

King::~King() {

}

void King::render(sf::RenderWindow* window) {
    GamePieces::render(window);
}
